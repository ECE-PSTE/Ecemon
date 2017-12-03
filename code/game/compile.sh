#! /bin/sh

g++ main.cpp -o main -I ../entities/include/ ../entities/src/*.cpp -I ../models/include/ ../models/src/*.cpp -I ../graphics/include/ ../graphics/src/*.cpp -I include/ src/*.cpp -I ../Socket/lib ../Socket/lib/*.cpp -std=c++11 -lpthread -lsfml-graphics -lsfml-window -lsfml-system
./main
rm main
