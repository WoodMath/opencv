#!/bin/bash

#for CODE in $@
#do
#g++ $CODE.cpp -o $CODE -lm -lGL -lGLU -lglut
#done

echo
echo
echo
echo
echo
echo

#g++ DisplayImage.cpp -o DisplayImage.out `pkg-config --cflags --libs opencv`

CODE="camera_calibration"
g++ -g $(pkg-config  --cflags opencv) $CODE.cpp \
     $(pkg-config --libs opencv) -o $CODE.out

#done
