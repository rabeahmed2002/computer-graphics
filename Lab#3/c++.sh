#!/bin/zsh

gcc "Device.cpp" -lGL -lGLU -lglut -lm  -std=c++11 -lstdc++ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lopenal;
./a.out;
gcc $1 -lGL -lGLU -lglut -lm  -std=c++11 -lstdc++ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lopenal; 
./a.out;