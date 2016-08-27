#!/bin/sh
#gcc -c countdown.c -lcurses
gcc -L/usr/lib/libncurses.dylib -c countdown.c
gcc countdown.o test.c -o test -lcurses
#gcc -L/usr/lib/libncurses.dylib test.c countdown.o -o test
