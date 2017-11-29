#! /bin/sh

g++ game.cpp -o game -I ../entities/include/ ../entities/src/*.cpp -I ../models/include/ ../models/src/*.cpp -I ../graphics/include/ ../graphics/src/*.cpp -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system
./game
rm game
