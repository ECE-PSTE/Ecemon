#! /bin/sh

g++ client.cpp -o client -I ../entities/include/ ../entities/src/*.cpp -I ../models/include/ ../models/src/*.cpp -I ../graphics/include/ ../graphics/src/*.cpp -I include/ src/*.cpp -I ../Socket/lib ../Socket/lib/*.cpp -std=c++11 -lpthread -lsfml-graphics -lsfml-window -lsfml-system
g++ server.cpp -o server -I ../Socket/lib ../Socket/lib/*.cpp -std=c++11 -lpthread
