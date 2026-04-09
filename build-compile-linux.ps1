# ogdf-src dir doesn't exist yet
git clone --depth 1 --branch foxglove-202510 https://github.com/ogdf/ogdf.git ogdf-src
# now it does

# if you don't have cmake, get it:
# sudo apt install cmake build-essential

cmake -S ogdf-src -B ogdf-build
# now we have ogdf-build dir

# this one will take ~5 min
cmake --build ogdf-build --parallel 4

# I am ignoring this manual: https://github.com/ogdf/ogdf/blob/master/doc/build.md

# Now we have these:
ls ./ogdf-build/*.a
# ogdf-build/libCOIN.a  ogdf-build/libOGDF.a

g++ -std=c++17 -o ogdf-cli *.cpp `
    -I./ogdf-src/include `
    -I./ogdf-build/include/ogdf-release `
    -L./ogdf-build -lOGDF -lCOIN `
    -pthread

# Now we got:
file ./ogdf-cli
# ./ogdf-cli: ELF 64-bit LSB pie executable, x86-64, version 1 (GNU/Linux), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=cde4d40e88467a95e8d828ce2b1bdb63d209a1d5, for GNU/Linux 3.2.0, not stripped

# Done! Usage:
$ogdfCli = gi ./ogdf-cli
& $ogdfCli --generate randomTree1 --n 100 --layout FMMM --out-file delme.svg
open delme.svg
