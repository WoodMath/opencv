#ifndef _CAMERA_

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "opencv2/opencv.hpp"
#include "mkpath.hpp"

#define DEBUG

#ifdef DEBUG
	#define DEBUG_FN(X)	{std::cout << X << std::endl ;}
#else
	#define DEBUG_FN(X)
#endif



#define FRAME_RATE (10)
#define SAVE_RATE (10)
#ifndef WINDOW_MODE
#define WINDOW_MODE (cv::WINDOW_AUTOSIZE)
//#define WINDOW_MODE (0)
#endif

#define _CAMERA_
//#define SINGLE_VC

class Camera{

public:
	Camera();
	Camera(int iSource);
	~Camera();
	void setSource(int iSource);	
	void setPreviewSize(int iWidth, int iHeight);
	void setSaveSize(int iWidth, int iHeight);
	void setDescription(std::string sDescription);
	void setDirectory(std::string sDirectory);
	void setWindowPosition(int iX, int iY);
	void start();
	void wait();
	void display();
	void save();
	void stop();
	void setFrameRate(unsigned int iFrameRate);
	char* getFileName();
	std::string getDescription();

	void printDebug();
	bool isActive();
private:
	void init();

	int iSource;
	int iPreviewWidth;
	int iPreviewHeight;
	int iSaveWidth;
	int iSaveHeight;
	int iWindowX;
	int iWindowY;
	unsigned int iSaveCount;

	std::string sDescription;
	std::string sDirectory;

	char cFileName[256];
	unsigned int iFrameRate;

#ifndef SINGLE_VC
	cv::VideoCapture camPreview;
#endif
	cv::VideoCapture camSave;
#ifndef SINGLE_VC
	cv::Mat matPreview;
#endif
	cv::Mat matSave;

	std::vector<int> compression_params;

	bool bActive;
};

#endif
