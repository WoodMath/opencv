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

CODE="acquire_stereo_images_v2"
CALLBACKS="callbacks"
CAMERA="camera"
#g++ -g $(pkg-config --cflags opencv) -c $CALLBACKS.cpp $(pkg-config --libs opencv)
g++ -c $CAMERA.cpp
g++ -c $CALLBACKS.cpp
g++ -g $(pkg-config --cflags opencv) $CALLBACKS.o $CODE.cpp \
     $(pkg-config --libs opencv) -o $CODE.out

#done

#./imagelist_creator.out image_list.xml ./calib640x480/*.png
#./calibration.out -w 8 -h 7 -pt chessboard -s 2.25 -o camera_left.yml -op -oe imagelist_left.xml -su
#./calibration.out -w 8 -h 7 -pt chessboard -s 2.25 -o camera_right.yml -op -oe imagelist_right.xml

#./stereo_calib.out -w 9 -h 6 stereo_calib.xml
#./stereo_calib.out -w 7 -h 7 imagelist.yml

#./acquire_stereo_images_v2.out config_v2.yml
