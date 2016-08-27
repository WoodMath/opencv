#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "char.h"	
#include <sys/ioctl.h>
#include <unistd.h>
#include <curses.h>
#define PIXEL_ROWS (8)
#define PIXEL_COLS (8)
#define SPAN_ROWS (3)
#define SPAN_COLS (3)

unsigned int iRows;
unsigned int iCols;
unsigned int r, c;
unsigned int nrows, ncols;

char numPos[]={48,49,50,51,52,53,54,55,56,57};

void updateSize(){
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//	ioctl(0, TIOCGWINSZ, &w);
	iRows = w.ws_row;
	iCols = w.ws_col;
}

void init(){
	WINDOW *wnd;
	wnd = initscr();
	clear();
	getmaxyx(wnd,nrows,ncols);
	refresh();
}

void printChar(unsigned int iChar){

	init();
	
	uint64_t uChar = font[numPos[iChar]];
	unsigned char cChar;
	unsigned char bChar;
	int iInc = 0;	// Row incrementor
	int jInc = 0;	// Col incrementor
	int uInc = 0;	// Row incrementor
	int vInc = 0;	// Col incrementor

	r=0;
	for(iInc = 0; iInc < PIXEL_ROWS; iInc++){
		for(uInc = 0; uInc < SPAN_ROWS; uInc++){

			c=0;

			cChar = (unsigned char) ((uChar >> (PIXEL_COLS * (PIXEL_ROWS - iInc))) & 255);


			for(jInc = 0; jInc < PIXEL_COLS; jInc++){

//				printf("iInc = %d, jInc = %d, %u\n", iInc, jInc, (unsigned int)cChar);
				bChar = ((cChar >> (PIXEL_COLS - jInc - 1)) & 1);
				for(vInc = 0; vInc < SPAN_COLS; vInc++){

					move(r,c);
					if(bChar)
						insch(iChar + '0');
//						printf("%d", iChar);
//					else
//						printf(" ");

					c++;
				}
			}
//			printf("\n");
			r++;

		}
	}

	while(1){
		char d;
		d=getch();
		if(d=='q'){
			endwin();
			exit(0);
		}
	}
	updateSize();
	printf(" iRows = %d ; iCols = %d ; \n", iRows, iCols);
	return;

}
