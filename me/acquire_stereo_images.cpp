#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>
#include <time.h>
#define TRUE 	(1)
#define FALSE	(0)
using namespace cv;
#define DEBUGd

#ifdef DEBUG
	#define DEBUG_FN(X)	{std::cout << X ;}
#else
	#define DEBUG_FN(X)
#endif

#define WINDOW_MODE WINDOW_AUTOSIZE

char bTriggerEnabled = FALSE;

void onMouse(int event, int x, int y, int flags, void* userdata){
	if ( event == EVENT_LBUTTONDOWN ){
		bTriggerEnabled = TRUE;

		DEBUG_FN("Mouse Button Pressed");
		DEBUG_FN(std::endl);

		return;
	}else if  ( event == EVENT_RBUTTONDOWN ) {
		bTriggerEnabled = TRUE;

		DEBUG_FN("Mouse Button Pressed");
		DEBUG_FN(std::endl);

		return;
	}else if  ( event == EVENT_MBUTTONDOWN ) {
		bTriggerEnabled = TRUE;

		DEBUG_FN("Mouse Button Pressed");
		DEBUG_FN(std::endl);

		return;
	}else if ( event == EVENT_MOUSEMOVE ){

	}
}

int main(int argc, char* argv[]){

	//	FileStorage fs(filename, FileStorage::READ);
	//	fs.open(filename, FileStorage::READ);



	string sFileName = "config.yml";
	string sImageList;
	string sImageName;
	if(argc <= 1){
		std::cout << "Usage is: " << std::endl;
		std::cout << "\t " << argv[0] << " configfile.yml " << std::endl;
		exit(0);

	}
	FileStorage fsr(argv[1], FileStorage::READ);
	if(!fsr.isOpened()){
		std::cout << "Could not find file " << argv[1] << std::endl;
		exit(0);
	}


	int iFrameRate, iMaxFrames, iFrameStart;
	int iGrabRate;
	int iZeroPadding;
	int iWidth = 640, iHeight = 480;
	int iMouseTrigger = 0, iKeyboardTrigger = 0, iTimerTrigger = 0;

	fsr["frame_start"] >> iFrameStart;		//	Number of first frame to write
	fsr["frame_rate"] >> iFrameRate;		//	Number of Milliseconds between frames
	fsr["grab_rate"] >> iGrabRate;			//	Number of Milliseconds between grabs
	fsr["max_frames"] >> iMaxFrames;
	fsr["image_list"] >> sImageList;
	fsr["image_name"] >> sImageName;
	fsr["zero_padding"] >> iZeroPadding;
	fsr["width"] >> iWidth;
	fsr["height"] >> iHeight;
	fsr["mouse_trigger"] >> iMouseTrigger;
	fsr["keyboard_trigger"] >> iKeyboardTrigger;
	fsr["timer_trigger"] >> iTimerTrigger;

	unsigned long ulCount = (unsigned long)(iFrameStart);
	unsigned long ulFrameStart = (unsigned long)(iFrameStart);
	unsigned long ulMaxFrames = (unsigned long)(iMaxFrames);
	


	fsr.release();

  	FileStorage fsw(sImageList, FileStorage::WRITE);
	fsw << "imagelist" << "[";

	int iKey;


	VideoCapture camLeft(0); // open the default camera
	VideoCapture camRight(1); // open the default camera





	if(!camLeft.isOpened() || !camRight.isOpened())  // check if we succeeded
		return -1;


///*
	camLeft.set(CV_CAP_PROP_FRAME_WIDTH, iWidth);
	camLeft.set(CV_CAP_PROP_FRAME_HEIGHT, iHeight);
	camRight.set(CV_CAP_PROP_FRAME_WIDTH, iWidth);
	camRight.set(CV_CAP_PROP_FRAME_HEIGHT, iHeight);
//*/
	Mat matLeft;
	Mat matRight;


	vector<int> compression_params;
//	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
//	compression_params.push_back(9);

	namedWindow("Left",  WINDOW_MODE);
	namedWindow("Right",  WINDOW_MODE);

	if(iMouseTrigger){
		DEBUG_FN("Mouse Trigger Enabled");
		DEBUG_FN(std::endl);
		setMouseCallback("Left", onMouse, NULL);
		setMouseCallback("Right", onMouse, NULL);
	}
	if(iKeyboardTrigger){
		DEBUG_FN("Keyboard Trigger Enabled");
		DEBUG_FN(std::endl);
	}
	if(iTimerTrigger){
		DEBUG_FN("Timer Trigger Enabled");
		DEBUG_FN(std::endl);
	}

	char cLeft[256];
	char cRight[256];

	clock_t iClockStart = clock(), iClockDiff;
	unsigned int iMSec;


	while(1){
		camLeft.grab();
		camRight.grab();

		camLeft.retrieve(matLeft,0);
		camRight.retrieve(matRight,0);
		imshow("Left", matLeft);
		imshow("Right", matRight);



		iKey = waitKey(iFrameRate);

		iClockDiff = clock() - iClockStart;
		iMSec = 1000 * iClockDiff / CLOCKS_PER_SEC;

		if(iKey > -1) 
			printf(" iKey = %d \n", iKey);
		if(iKeyboardTrigger && iKey == 32)	// Test for spacebar if keyboard enabled
			bTriggerEnabled = TRUE;
		if(iTimerTrigger && iMSec >= iGrabRate)
			bTriggerEnabled = TRUE;


		if((ulCount - ulFrameStart + 1) > ulMaxFrames)
			break;

		if(bTriggerEnabled){
			// save images using space bar
	
			sprintf(cLeft, sImageName.c_str(), "Left", iZeroPadding, ulCount);
			sprintf(cRight, sImageName.c_str(), "Right", iZeroPadding, ulCount);

			DEBUG_FN(" *(sImageName.c_str()) = ");
			DEBUG_FN(sImageName.c_str());
			DEBUG_FN(std::endl);

			DEBUG_FN(" Writing Left Image File ");
			DEBUG_FN(cLeft);
			DEBUG_FN(std::endl);
			DEBUG_FN(" Writing Right Image File ");
			DEBUG_FN(cRight);
			DEBUG_FN(std::endl);

			fsw << cLeft;
			fsw << cRight;

			printf("\t Saving frames %s and %s (%0*lu of %0*lu) .\n", 
				cLeft, cRight, iZeroPadding, 
				ulCount-ulFrameStart+1, iZeroPadding, ulMaxFrames);

			imwrite(cLeft,matLeft,compression_params);
			imwrite(cRight,matRight,compression_params);
			ulCount++;

			iClockStart = clock();

			bTriggerEnabled = FALSE;
	

		}


		if(iKey == 27 || iKey == 113)		// ESC or Q is hit
			break;


	}

	fsw << "]";
	fsw.release();
	destroyWindow("Left");
	destroyWindow("Right");
	destroyAllWindows();

	return 0;
}
