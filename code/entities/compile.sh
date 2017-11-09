#! /bin/sh

g++ test.cpp -o test -I include/ src/*.cpp
./test
rm test
