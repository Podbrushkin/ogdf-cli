# You're in empty dir

# Download source code
$url = 'https://ogdf.uos.de/wp-content/uploads/2023/09/ogdf.v2023.09.zip'
Invoke-RestMethod $url -OutFile "$HOME/downloads/$($url -replace '.*/')"

# Extract src and rename it
7z x "$HOME/downloads/$($url -replace '.*/')"
ren .\OGDF\ ogdf-src

# Now need to build OGDF
# Prepare path to downloaded src
$ogdfSrc = gi .\ogdf-src\ | % FullName
$ogdfSrcUnix = '/'+$ogdfSrc.Substring(0,1).ToLower() + ($ogdfSrc -replace '.*:' -replace '\\','/')
# $ogdfSrcUnix = '/c/JAVA2023/ogdf-cli/ogdf-src/'

# Will be putting here everything which needs to be executed in MINGW64
$bashFile = "$HOME\AppData\Local\Programs\msys64\home\user\delme.sh"

mkdir .\ogdf-build

# Build OGDF
@'
cd /c/JAVA2023/ogdf-cli/
cmake -S ogdf-src -B ogdf-build
'@ > $bashFile
# Now, launch MSYS2 MINGW64 and execute `. ~/delme.sh` (above script)

# Now add '#include <cstdint>' line to these files(2):
gci -Recurse  ogdf-src\src\coin\* *.cpp | sls 'CoinInt64' | % Path | select -Unique

# Compile OGDF
@'
cd /c/JAVA2023/ogdf-cli/
cmake --build ogdf-build --parallel 4
'@ | Out-File $bashFile
# Execute  `. ~/delme.sh` in MSYS2 MINGW64

# Done! You've got these big bois:
# .\ogdf-build\libCOIN.a
# .\ogdf-build\libOGDF.a

# Compile your own client code (put cpp files into /ogdf-cli/):
@'
cd /c/JAVA2023/ogdf-cli/
g++ -std=c++17 -o ogdf-cli.exe *.cpp \
	 -I./ogdf-src/include \
     -I./ogdf-build/include \
     -L./ogdf-build -lOGDF -lCOIN \
     -lstdc++fs -pthread
'@ | Out-File $bashFile

# Put mingw64 to PATH in order to be able to run your app:
$env:Path = "C:\Users\user\AppData\Local\Programs\msys64\mingw64\bin\;"+$env:Path

# Run your app:
$ogdfCli = gi 'C:\JAVA2023\ogdf-cli\ogdf-cli.exe'
& $ogdfCli --generate randomTree1 --n 100 --layout FMMM --out-file delme.svg
