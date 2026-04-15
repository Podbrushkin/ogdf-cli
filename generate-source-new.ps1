function Get-GeneratorFunctionSrc ($fObj) {
$generatorMethodTemplate = @'
void %FUNC_WRAPPER_NAME%(Graph& G, const std::map<std::string, std::string>& localParams) {
  static const char* helpText = "%HELP_TEXT%";
  try {
%VARIABLE_DEFINITIONS%
    %GEN_NAME%(%VAR_NAMES%);
  } catch (const std::exception& e) {
    std::cout << helpText << std::endl;
    exit(1);
  }
}
'@
#$funcWrapperName = $fObj.name,$fObj.params.declName,'Generator' | Join-String
$funcWrapperName = $fObj.name+$fObj.nameSuffix+'Generator'
$primitiveTypes = 'int,double,bool' -split ','
$typeToCast = @{int='std::stoi'; double='std::stod'; bool='strToBool'}

$variableDefinitions = $fObj.params | ? type -in $primitiveTypes | % {
if ($_.defVal) {
@"
    $($_.type) $($_.declName) = $($_.defVal);
    if (localParams.find("$($_.declName)") != localParams.end()) {
      $($_.declName) = $($typeToCast[$_.type])(localParams.at(`"$($_.declName)`"));
    }
"@
} else {
"    $($_.type) $($_.declName) = $($typeToCast[$_.type])(localParams.at(`"$($_.declName)`"));"
}
}

$helpText = "=== "+$fObj.name+$fObj.nameSuffix+" ===`n"
$helpText += $fObj | Select-Object -excl name,params,nameSuffix | Format-List | Out-String
$helpText += $fObj.params | Format-Table | Out-String
$helpTextEscaped = $helpText.Replace('\','\\').Replace("`n",'\n').replace('"','\"').trim()
#$helpTextEscaped = 'no help'

$generatorMethodTemplate.replace('%GEN_NAME%',$fObj.name).
Replace('%VARIABLE_DEFINITIONS%',$variableDefinitions -join "`n").
Replace('%VAR_NAMES%',$fObj.params.declName -join ', ').
replace('%HELP_TEXT%',$helpTextEscaped).
replace('%FUNC_WRAPPER_NAME%',$funcWrapperName)
}

function Replace-LinesBetweenAnchors($inputStr,$anchorStr,$replacementStr) {
  $anchorStrEscaped = [regex]::Escape($anchorStr)
  $mGroup = $inputStr | Select-String "(?smi)$anchorStrEscaped.*?\n(.*?)(?=\r?\n[^\r\n]*?$anchorStrEscaped)" | ForEach-Object Matches | ForEach-Object {$_.Groups[1]}
  $outStr = $inputStr.Remove($mGroup.Index,$mGroup.Length).Insert($mGroup.Index,$replacementStr)
  return $outStr
}
return
$fObjs = Get-FunctionGeneratorObjects

$fObjs | group name | ? Count -gt 1 | % {
  $_.Group | % {$i=1}{ Add-Member -inp $_ -NotePropertyName nameSuffix -NotePropertyValue ($i++) -Force }
}

$genDefinitions = $fObjs | % { Get-GeneratorFunctionSrc $_ } | join-string -sep "`n"
$anchorStr = '%GENERATORS_DEFINITIONS%'
$inputStr = gc -Raw ./MyGenerators.cpp
$outStr = Replace-LinesBetweenAnchors $inputStr $anchorStr $genDefinitions
$outStr | Set-Content ./MyGenerators.cpp -NoNewline

$genTable = $fObjs | % {
'  {"%%", %%Generator}'.Replace('%%',$_.name+$_.nameSuffix)
} | Join-String -sep ",`n"
$anchorStr = '%GENERATORS_TABLE%'
$inputStr = gc -Raw ./MyGenerators.cpp
$outStr = Replace-LinesBetweenAnchors $inputStr $anchorStr $genTable
$outStr | Set-Content ./MyGenerators.cpp -NoNewline


$helpText = $fObjs | % {[pscustomobject]@{a= $_.name+$_.nameSuffix; b=$_.argsString.Replace('(Graph &G, ','').Replace(')','')}} | Format-Table -HideTableHeaders | Out-String
$helpTextEscaped = $helpText.Replace('\','\\').Replace("`n",'\n').replace('"','\"').trim()
$helpLine = 'static const char* helpText = "{0}";' -f $helpTextEscaped
$anchorStr = '%GENERATORS_HELPLINE%'
$inputStr = gc -Raw ./MyGenerators.cpp
$outStr = Replace-LinesBetweenAnchors $inputStr $anchorStr $helpLine
$outStr | Set-Content ./MyGenerators.cpp -NoNewline

# Now you can compile.

return

# bad:
#$funcDefForImport = ($fObj.definition+$fObj.argsString).Replace('OGDF_EXPORT ','').Replace('ogdf::','')
$fObjs | % {
"void $($_.name)Generator(Graph& G, const std::map<std::string, std::string>& localParams);"
}

# bad:
$fObjs | % {
@"
if (generatorName == "$($_.name)") {
  $($_.name)Generator(G, localParams);
}
"@
} | Join-String -sep " else "

# good:


# ########### USAGE EXAMPLE

@'
complement --n 32 --directed false --allowSelfLoops false
regularLatticeGraph --n 32 --k 4
regularTree --n 32 --children 2
completeGraph --n 32
completeBipartiteGraph --n 16 --m 16
wheelGraph --n 32
cubeGraph --n 5
globeGraph --meridians 8 --latitudes 4
suspension --s 32
gridGraph --n 8 --m 4 --loopN false --loopM false
petersenGraph --n 16 --m 2
emptyGraph --nodes 32
randomRegularGraph --n 32 --d 4
randomGraph --n 32 --m 100
randomSimpleGraph --n 32 --m 100
randomSimpleGraphByProbability --n 32 --pEdge 0.2
randomSimpleConnectedGraph --n 32 --m 50
randomBiconnectedGraph --n 32 --m 60
randomPlanarConnectedGraph --n 32 --m 60
randomPlanarBiconnectedGraph --n 32 --m 60 --multiEdges false
randomPlanarBiconnectedDigraph --n 32 --m 60 --p 0.0 --multiEdges false
randomUpwardPlanarBiconnectedDigraph --n 32 --m 60
randomPlanarCNBGraph --n 32 --m 60 --b 5
randomTriconnectedGraph --n 32 --p1 0.5 --p2 0.5
randomPlanarTriconnectedGraph --n 32 --m 80
randomPlanarTriconnectedGraph --n 32 --p1 0.3 --p2 0.3
randomTree --n 32
randomTree --n 32 --maxDeg 4 --maxWidth 10
randomDigraph --n 32 --p 0.1
randomSeriesParallelDAG --edges 60 --p 0.5 --flt 0.0
randomGeometricCubeGraph --nodes 32 --threshold 0.3 --dimension 2
randomWaxmanGraph --nodes 32 --alpha 0.5 --beta 0.2 --width 1.0 --height 1.0
preferentialAttachmentGraph --nodes 32 --minDegree 2
randomWattsStrogatzGraph --n 32 --k 4 --probability 0.3
randomHierarchy --n 32 --m 3 --planar true --singleSource true --longEdges false
pruneEdges --max_edges 60 --min_deg 2
'@

@'
complement --n 512 --directed false --allowSelfLoops false
regularLatticeGraph --n 512 --k 4
regularTree --n 512 --children 2
completeGraph --n 512
completeBipartiteGraph --n 256 --m 256
wheelGraph --n 512
cubeGraph --n 9
globeGraph --meridians 32 --latitudes 16
suspension --s 512
gridGraph --n 32 --m 16 --loopN false --loopM false
petersenGraph --n 256 --m 2
emptyGraph --nodes 512
randomRegularGraph --n 512 --d 4
randomGraph --n 512 --m 2000
randomSimpleGraph --n 512 --m 2000
randomSimpleGraphByProbability --n 512 --pEdge 0.015
randomSimpleConnectedGraph --n 512 --m 1000
randomBiconnectedGraph --n 512 --m 1000
randomPlanarConnectedGraph --n 512 --m 1500
randomPlanarBiconnectedGraph --n 512 --m 1500 --multiEdges false
randomPlanarBiconnectedDigraph --n 512 --m 1500 --p 0.0 --multiEdges false
randomUpwardPlanarBiconnectedDigraph --n 512 --m 1500
randomPlanarCNBGraph --n 512 --m 1500 --b 10
randomTriconnectedGraph --n 512 --p1 0.5 --p2 0.5
randomPlanarTriconnectedGraph --n 512 --m 1500
randomPlanarTriconnectedGraph --n 512 --p1 0.3 --p2 0.3
randomTree --n 512
randomTree --n 512 --maxDeg 4 --maxWidth 20
randomDigraph --n 512 --p 0.01
randomSeriesParallelDAG --edges 1000 --p 0.5 --flt 0.0
randomGeometricCubeGraph --nodes 512 --threshold 0.1 --dimension 2
randomWaxmanGraph --nodes 512 --alpha 0.5 --beta 0.2 --width 1.0 --height 1.0
preferentialAttachmentGraph --nodes 512 --minDegree 2
randomWattsStrogatzGraph --n 512 --k 4 --probability 0.1
randomHierarchy --n 512 --m 5 --planar true --singleSource true --longEdges false
pruneEdges --max_edges 1500 --min_deg 2
'@


$genLines | ogvf -PassThru | % {
$genCode = $_ -replace '\s+'
$outFile = Join-Path (gi ./img/) "$genCode$(Get-Date -Format FileDateTime).png"
$generatorArgs = $_ -split ' '
$expr = /bin/echo `& $ogdfCli --generate @generatorArgs --layout FMMM --out-file delme.dot
Invoke-Expression $expr
@(
  @{op='import'; file='delme.dot' }
  @{op='preview'; 'background-color'='#171717'; 'nodeLabelShow'=$true; }
  @{op='colorNodesBy';column='degree'; mode='ranking'}
  @{op='labelNodesBy';column='degree'; }
  @{op='layouts'; values=@(
    @{name='Expansion'; 'Density'=5000; steps=1;  }
  )}
  @{op='export';file=$outFile; timestamp=$false; resolution=@(512,512); }
) | ConvertTo-Json -d 9 | java -jar $gephiCommander -
$cmdEscaped = $generatorArgs -join ' '
magick $outFile -gravity SouthWest -undercolor "rgba(0,0,0,0.5)" -fill white -pointsize "%[fx:int(h*0.04)]" -annotate +10+10 $cmdEscaped $outFile
}

magick montage $files -tile "${cols}x${rows}" -geometry "400x400+2+2" -background "black" img/grid_output.png
