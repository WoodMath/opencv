#http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=gcc
CCFLAGS=-lm -lGL -lGLU -lglut

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

all: stb_image_aug.c image_helper.c image_DXT.c SOIL.c permutations.c bezier.c shapes.c drawing.c rubik.c
	$(CC) -c stb_image_aug.c
	$(CC) -c image_helper.c
	$(CC) -c image_DXT.c
	$(CC) -c SOIL.c
	$(CC) -c permutations.c
	$(CC) -c bezier.c
	$(CC) -c shapes.c
	$(CC) -c drawing.c
	$(CC) -c rubik.c
	$(CC) stb_image_aug.c image_helper.c image_DXT.c SOIL.c permutations.c bezier.c shapes.c drawing.c rubik.c -o rubik.out $(CCFLAGS)
soil: stb_image_aug.c image_helper.c image_DXT.c SOIL.c
	$(CC) -c stb_image_aug.c
	$(CC) -c image_helper.c
	$(CC) -c image_DXT.c
	$(CC) -c SOIL.c
permutations: permutations.c
	$(CC) -c permutations.c
bezier: bezier.c
	$(CC) -c bezier.c
shapes: shapes.c
	$(CC) -c shapes.c
drawing: drawing.c
	$(CC) -c drawing.c
rubik: rubik.c
	$(CC) -c rubik.c

