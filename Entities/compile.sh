#! /bin/sh

g++ main.cpp -o main -I include/ src/*.cpp -std=c++11
./main
rm main
