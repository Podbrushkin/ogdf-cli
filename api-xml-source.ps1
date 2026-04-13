# Creating doxygen goes smthing among these lines:
function Create-DoxygenXml {
  cp doc/ogdf-doxygen.cfg doc/ogdf-doxygen-xml.cfg

  # Enable XML, disable HTML (skips heavy doc generation)
  sed -i 's/GENERATE_XML.*/GENERATE_XML           = YES/' doc/ogdf-doxygen-xml.cfg
  sed -i 's/GENERATE_HTML.*/GENERATE_HTML          = NO/' doc/ogdf-doxygen-xml.cfg

  # Extract everything, even functions without full Doxygen blocks
  sed -i 's/EXTRACT_ALL.*/EXTRACT_ALL            = YES/' doc/ogdf-doxygen-xml.cfg

  # Point input ONLY to the generators directory (drastically faster)
  sed -i 's|^INPUT\s*=.*|INPUT                  = include/ogdf/basic/graph_generators|' doc/ogdf-doxygen-xml.cfg

  doxygen doc/ogdf-doxygen-xml.cfg

  # No these:
  rm doc/ogdf-doxygen-xml.cfg
  doxygen -g Doxyfile  # Creates a new Doxyfile in the current directory
  # Enable XML, disable HTML (skips header/footer errors)
  sed -i 's/GENERATE_XML           = NO/GENERATE_XML           = YES/' Doxyfile
  sed -i 's/GENERATE_HTML          = YES/GENERATE_HTML          = NO/' Doxyfile

  # Extract everything, even if comments are missing
  sed -i 's/EXTRACT_ALL            = NO/EXTRACT_ALL            = YES/' Doxyfile

  # Point input ONLY to generators
  sed -i 's|^INPUT\s*=.*|INPUT                  = include/ogdf/basic/graph_generators|' Doxyfile
  sed -i 's/RECURSIVE              = NO/RECURSIVE              = YES/' Doxyfile

  # Ignore C++ macros like OGDF_EXPORT to prevent parsing errors
  sed -i 's/^PREDEFINED            = /PREDEFINED            = OGDF_EXPORT= /' Doxyfile
  doxygen Doxyfile
  sls -Path ./xml/deterministic_8h.xml -Pattern 'cubegraph'
}


function Get-FunctionGeneratorObjects {

$xmlPath = "./ogdf-src/xml/group__graph-generators.xml"
[xml]$doc = Get-Content $xmlPath -Raw

# Later we will look up for category of each func
$sectionMap = @{}
$doc.SelectNodes("//sectiondef") | ForEach-Object {
    $sec = if ($_.header) { $_.header.trim() }
    $_.memberdef | % {
        $funcId = $_.definition+$_.argsString
        $sectionMap[$funcId] = $sec
    }
}

$functions = $doc.SelectNodes("//memberdef[@kind='function']")

$fObjs = @()
$functions | % {
  $func = $_
  $name = $func.name
  $briefDescription = $func.briefdescription.para # | % {$_.InnerText}
  $detailedDescription = $func.detailedDescription.para | ? {!$_.parameterlist} | % {$_.InnerText}
  $params = $func.param | % {
    $ordered = [ordered]@{type=$_.type; declName=$_.declName;}
    if ($_.defval) {$ordered.defVal = $_.defval}
    [pscustomobject]$ordered
  }
  $func.detailedDescription.para.parameterList.parameterItem | % {
    $pName = $_.parameterNamelist.parametername
    $pDesc = $_.parameterdescription.InnerText.trim()
    $params | ? declName -eq $pName | % {Add-Member -inp $_ -NotePropertyName description -NotePropertyValue $pDesc}
  }
  $allowedParamTypes = 'Graph &,int,double,bool' -split ','
  $unknownTypes = $params.type | ? {$_ -notin $allowedParamTypes}
  if ($unknownTypes.count -gt 0) {return}

  $fObj = [ordered]@{name = $name; argsString = $func.argsString; definition = $func.definition }
  if ($section = $sectionMap.$name) {$fObj.section = $section}
  if ($briefDescription) { $fObj.'briefDescription' = $briefDescription }
  if ($detailedDescription) { $fObj.'detailedDescription' = $detailedDescription }
  #if ($unknownTypes.count -eq 0) {$fObj.allowed = $true}
  $fObj.params = $params

  $fObj = [pscustomobject]$fObj
  $fObjs += $fObj
}
return $fObjs;
}

return

$fObjs.params.type | group {$_} -NoElement | Sort-Object Count -desc | select -f 10
<#
Count Name
----- ----
   78 int
   58 Graph &
   20 const Graph &
   19 double
   13 bool
    8 NodeMap &
    5 ClusterGraph &
    2 NodeArray< node > &
    2 List< std::pair< int, in…
    2 EdgeArray< uint8_t > &
#>

