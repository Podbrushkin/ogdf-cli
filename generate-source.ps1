function Get-CommentAboveLine ($lines, [int]$EndExclude) {
	$i = $EndExclude - 2
	$comment = @()
	while ($i -ge 0) {
	 $line = $lines[($i--)];
	  $commentRegex = '^\s*/+|\s*\*'
	  if ( $line -match $commentRegex) {
		$comment += $line
	  } else {break}
	}
	$comment = $comment -replace '^[\s/\*!]*' | ? {$_}
	if (!$comment) {return $null}
	$comment = ([array]$comment)[($comment.Length-1)..0] -join "`n"	
	return $comment.trim()
}

function Get-LayoutMethodDefinition ($cppHeaderFile) {
	$allowedTypes = 'int,double,bool' -split ','
	
	
	$methods = Get-Methods $cppHeaderFile
	
	# This one will be filled in Get-MethodCalls
	$script:referenceTypes = @()
	
	$ifElses = Get-MethodCalls $methods
	$ifElses = $ifElses | Join-String -sep "`nelse "
	
	Write-Host referenceTypes: $script:referenceTypes
	
	# Get layout comment
	$layoutComment = $null;
	$endExclude = sls -Path $cppHeaderFile -Pattern ': public LayoutModule' | % LineNumber
	if ($EndExclude.count -ne 1) {
		Write-Host -foreg yellow $cppHeaderFile "is it: public LayoutModule? Will be no comment"
		#return
	} else {
		$layoutComment = Get-CommentAboveLine -lines (cat $cppHeaderFile) -EndExclude $endExclude
	}

	# Get methods comments
	$methodsComments = $methods | ? {$_.params.type -in ($allowedTypes+$script:referenceTypes)} | % {
	$_.name+' ('+$_.params.type+")`n"+$_.comment+"`n"
	} | Join-String -sep "`n"

	# Combine and escape comments
	$helpStrEscaped = ($layoutComment,$methodsComments -join "`n").trim().Replace('\', '\\').Replace('"', '\"') -replace '\r?\n', '\n'

	# Build include stmt
	$path = $cppHeaderFile.FullName -replace '.*include.' -replace '\\','/'
	$include = "#include <$path>"

	# Create main method call
	$layoutName = $cppHeaderFile.BaseName
	$src = @"
$include
void apply${layoutName}(GraphAttributes& GA, const std::map<std::string, std::string>& localParams) {
${layoutName} layout;

static const char* helpText = "$helpStrEscaped";
if (localParams.find("help") != localParams.end()) {
std::cout << helpText << std::endl;
exit(0);
}
try {
for (const auto& [key, value] : localParams) {
$ifElses
else {
std::cout << "Bad key: " << key << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
layout.call(GA);
} catch (const std::exception& e) {
std::cout << e.what() << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
}
"@
	return $src
	
}

# --- Create method objects
# Get info which setters this layout has
function Get-Methods ($cppHeaderFile) {
	$lines = cat $cppHeaderFile
	$methods = & $ctags --output-format=json --extras=* --fields=* --c++-kinds=+p -f - $cppHeaderFile | fromJson -de 9 | ? access -eq public | ? extras -ne qualified | ? kind -in function,prototype | ? signature -NotLike '()*' | % {
		$method = $_
		$paramType = $method.signature -replace '^\(([a-z:]+).*','$1'
		Add-Member -inp $method -NotePropertyName params -NotePropertyValue @{type=$paramType}

		# Add comments
		$i = $method.line
		$comment = Get-CommentAboveLine $lines $i
		if ($comment) {
			Add-Member -inp $method -NotePropertyName comment -NotePropertyValue $comment
		}
		$_
	}
	return $methods
}


# Create code which calls those setters (primitives and enums supported)
function Get-MethodCalls ($methods) {
	# --- Create method calls, first for primitives
	$primitiveTypes = 'int,double,bool' -split ','
	$typeToCast = @{int='std::stoi'; double='std::stod'; bool='strToBool'}
	$ifElses = $methods | ? {$_.params.type -in $primitiveTypes} | % {
		$m = $_
		$withoutSetPrefixCondition = ""
		if ($m.name -match '^set') { 
			$reformattedKey = $m.name -replace "^set" | % { $_.Substring(0,1).ToLower() + $_.Substring(1) }
		  $withoutSetPrefixCondition  = " || key == """+$reformattedKey +'"'
		}
		@"
		if (key == "$($m.name)"$withoutSetPrefixCondition) {
			layout.$($m.name)($($typeToCast[$m.params.type])(value));
		}
"@
	}
	# Second, for enums
	$script:referenceTypes = @()
	$ifElses += $methods | ? {$_.params.type -notin $primitiveTypes} | % {
		$method = $_
		#write-host 0 
		# It's either enum name or qualified class name where enums are
		$methodParamType = $method.params.type 
		Write-host methodParamType: $methodParamType
		
		$enumLocation = $null
		$enumName = $null
		$enumValues = @()
		
		# This one finds enum which is declared in layout class itself
		$global:enumTag = & $ctags --output-format=json --extras=* --fields=* --c++-kinds=+p -f - $cppHeaderFile | 
			fromJson -de 9 | 
			? kind -eq enum | 
			? extras -ne qualified | 
			? name -eq $methodParamType
		# Handle internal enums
		if ($enumTag) {
			write-host 1 $enumObj
			$enumObj = Get-EnumObj $enumTag
			$enumValues = $enumObj.values
			
			$method.comment += "`nPossible values: `n"+($enumObj.comment)
			$enumName = $enumObj.name
			$script:referenceTypes += $enumName
			$enumLocation = $enumObj.location -replace 'ogdf::'
		}
		# Handle external enums
		else {
			$classWithEnums,$enumName = ($methodParamType -split '::')[0,1]
			# Find class where enums can be declared
			$headerWithEnums = gci -Recurse (gi $method.path).Directory "$classWithEnums*" | select -f 1
			#$enumName = $method.signature -replace '.*::(\w+) .*','$1'
			if (!$headerWithEnums) { return }
			$enumObj = Get-EnumsFromHeader $headerWithEnums | ? {$_.name.endsWith($enumName)}
			#write-host 2 $enumObj
			if (!$enumObj) { return }
			$enumName = $enumObj.name
			$enumValues = $enumObj.values
			$enumLocation = $enumObj.location -replace 'ogdf::'
			#write-host enumvaluescount: $foundEnum.values.value.count
			#if ($foundEnum.values.value.count -eq 1) {
			#	write-host ($foundEnum | toJson -de 9)
			#}
			
			$method.comment += "`nPossible values: `n" + $enumObj.comment
			$script:referenceTypes += $enumLocation+'::'+$enumName
		} 
		
		
		$enumIfElses = $enumValues | % {
			@"
			if (value == "$_") {
			  layout.$($method.name)($enumLocation::$enumName::$_);
			}
"@
		} | Join-String -sep "`nelse "
		$enumIfElses += @"
`n else { 
std::cout << "Bad enum value: " << value << std::endl;
std::cout << helpText << std::endl;
exit(1);
}
"@
		$enumBlock = @"
if (key == "$($method.name)") {
$enumIfElses
}
"@
		$enumBlock
	}
return $ifElses
}

function Get-EnumsFromHeader ($headerWithEnums) {
	$cppCode = cat -Raw $headerWithEnums
	& $ctags --output-format=json --extras=* --fields=* --c++-kinds=+p -f - $headerWithEnums | fromJson -de 9 | ? kind -eq enum | ? extras -ne qualified | % {
		$enumTag = $_
		Get-EnumObj $enumTag
	}
}
function Get-EnumObj ($enumTag) {
	$regex = $enumTag.pattern -replace '/|\$|\^'
	$regex = '(?smi)'+[regex]::Escape($regex)+'.*?\}'
	$from = $enumTag.line-1; $lines = $enumTag.end-$from
	$enumDef = cat $enumTag.path | select -Skip $from -First $lines | Join-String -sep "`n"
	$enumValues = $enumDef -replace '^.*\{\s*|\}.*' -split '\r?\n' -replace '\s*//.*' -replace '^\s*|,' -split '\s+' | ? {$_}
	$enumComment = $enumDef -split '\r?\n' -notmatch '{|}' -replace '^\s*' -join "`n"
	return [pscustomobject]@{
		definition=$enumDef; values=$enumValues; 
		comment=$enumComment; name=$enumTag.name; 
		location=$enumTag.scope;
	}
}





return 

$ctags = gi "C:\Users\user\AppData\Local\Programs\ctags\ctags.exe"

# Find layouts
sls -Path .\ogdf-src\include\ogdf\*\*.h -Pattern ': public LayoutModule'

# Pick one
$cppHeaderFile = gi .\ogdf-src\include\ogdf\energybased\FMMMLayout.h
