#ifndef _CAMERA_

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


#define _CAMERA_


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

private:
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


	cv::VideoCapture camPreview;
	cv::VideoCapture camSave;

	cv::Mat matPreview;
	cv::Mat matSave;

	std::vector<int> compression_params;

	bool bActive;
};

#endif
