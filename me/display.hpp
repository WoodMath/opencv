#ifndef _DISPLAY_

#define _DISPLAY_



#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "opencv2/opencv.hpp"

#define DEBUG

#ifdef DEBUG
	#define DEBUG_FN(X)	{std::cout << X << std::endl ;}
#else
	#define DEBUG_FN(X)
#endif



#define FRAME_RATE (10)
#define SAVE_RATE (10)
#define WINDOW_MODE cv::WINDOW_AUTOSIZE




class Display{

public:
	Display();
	Display(std::string sDescription);
	~Display();
	void setDescription(std::string sDescription);
	void start();	
	void display(std::string sDisplay);
	void display(const char* cDisplay);
	void stop();

	void setWindowSize(int iWidth, int iHeight);
	void setWindowPosition(int iX, int iY);




private:
	std::string sDescription;
	cv::Mat matDisplay;

	int iWindowWidth;
	int iWindowHeight;
	int iWindowX;
	int iWindowY;
	
	bool bActive;
};

#endif
