#!/bin/bash

#for CODE in $@
#do


#gcc -lGL -lglut $CODE.c -o $CODE
#g++ $CODE.cpp -o $CODE -lm -lGL -lGLU -lglut
echo 
echo 
echo 
echo 
echo 
echo 
echo 

#http://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c
#http://stackoverflow.com/questions/2831361/how-can-i-create-c-header-files
#http://stackoverflow.com/questions/15441877/how-do-i-link-object-files-in-c-problems-with-compilation
HOME_DIR="${HOME}"
SOIL_DIR="./soil"

gcc -c $SOIL_DIR/stb_image_aug.c -o $SOIL_DIR/stb_image_aug.o
gcc -c $SOIL_DIR/image_helper.c -o $SOIL_DIR/image_helper.o
gcc -c $SOIL_DIR/image_DXT.c -o $SOIL_DIR/image_DXT.o
gcc -c $SOIL_DIR/SOIL.c -o $SOIL_DIR/SOIL.o
#ar rcs libSOIL.a SOIL.o
gcc -c permutations.c
gcc -c bezier.c
gcc -c rubik.c
gcc -c shapes.c
gcc -c drawing.c
#gcc -c helper.c
#gcc permutations.o helper.o -o helper.out
#gcc image_DXT.o image_helper.o stb_image_aug.o SOIL.o permutations.o bezier.o shapes.o drawing.o rubik.o -o rubik.out -lm -lGL -lGLU -lglut
gcc $SOIL_DIR/image_DXT.o $SOIL_DIR/image_helper.o $SOIL_DIR/stb_image_aug.o $SOIL_DIR/SOIL.o permutations.o bezier.o shapes.o drawing.o rubik.o -o rubik.out -lm -lGL -lGLU -lglut

#gcc rubik.o shapes.o bezier.o -o rubik.out -lGL -lglut -lGLEW

#gcc rubik.o bezier.o -o rubik.out -I /usr/local/include/GL -L /usr/local/lib -lm -lGL -lGLU -lglut
#gcc rubik.o bezier.o -o rubik.out -I /usr/local/include/GL -L /usr/local/lib -lGL -lGLU -lglut
#g++ $CODE.cpp -o $CODE -I/opengl/downloads/OpenGL-tutorial_v0012_21 -lm -lGLEW -lGL -lGLU -lglut -lglfw 
#g++ $CODE.cpp -o $CODE -I../ -lm -lGLEW -lGL -lGLU -lglut -lglfw 

#./$CODE

#done
#ls -l -r -t
