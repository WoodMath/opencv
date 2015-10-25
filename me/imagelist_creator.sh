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

CODE="imagelist_creator"
g++ -g $(pkg-config  --cflags opencv) $CODE.cpp \
     $(pkg-config --libs opencv) -o $CODE.out

#done

./imagelist_creator.out imagelist_left.xml ./left*.jpg
./imagelist_creator.out imagelist_right.xml ./right*.jpg

#./calibration.out -w 7 -h 7 -pt chessboard -s 2.25 -o camera.yml -op -oe image_list.xml -su

