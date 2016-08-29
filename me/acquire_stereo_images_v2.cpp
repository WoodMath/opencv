#define DEBUG
#define CAMERA
#ifdef DEBUG
	#define DEBUG_FN(X)	{std::cout << X << std::endl ;}
#else
	#define DEBUG_FN(X)
#endif



#include "opencv2/opencv.hpp"
#include "callbacks.hpp"

#include <stdio.h>
#include <iostream>
#include <time.h>


#define TRUE 	(1)
#define FALSE	(0)


using namespace cv;



#define WINDOW_MODE WINDOW_AUTOSIZE

char bTriggerEnabled = FALSE;


string sFileName = "config.yml";
string sImageList;
string sImageName;

int iFrameRate, iMaxFrames, iFrameStart;
int iGrabRate;
int iZeroPadding;
int iSaveWidth = 640, iSaveHeight = 480;
int iPreviewWidth = 320, iPreviewHeight = 240;
int iMouseTrigger = 0, iKeyboardTrigger = 0, iTimerTrigger = 0;

unsigned long ulCount = (unsigned long)(iFrameStart);
unsigned long ulFrameStart = (unsigned long)(iFrameStart);
unsigned long ulMaxFrames = (unsigned long)(iMaxFrames);



int getParameters(int argc, char* argv[]){

	sFileName = "config.yml";

	iSaveWidth = 640;
	iSaveHeight = 480;
	iPreviewWidth = 320;
	iPreviewHeight = 240;
	iMouseTrigger = 0;
	iKeyboardTrigger = 0;
	iTimerTrigger = 0;


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

	fsr["frame_start"] >> iFrameStart;		//	Number of first frame to write
	fsr["frame_rate"] >> iFrameRate;		//	Number of Milliseconds between frames
	fsr["grab_rate"] >> iGrabRate;			//	Number of Milliseconds between grabs
	fsr["max_frames"] >> iMaxFrames;
	fsr["image_list"] >> sImageList;
	fsr["image_name"] >> sImageName;
	fsr["zero_padding"] >> iZeroPadding;
	fsr["save_width"] >> iSaveWidth;
	fsr["save_height"] >> iSaveHeight;
	fsr["preview_width"] >> iPreviewWidth;
	fsr["preview_height"] >> iPreviewHeight;
	fsr["mouse_trigger"] >> iMouseTrigger;
	fsr["keyboard_trigger"] >> iKeyboardTrigger;
	fsr["timer_trigger"] >> iTimerTrigger;

	DEBUG_FN("frame_start = " << iFrameStart)
	DEBUG_FN("frame_rate = " << iFrameRate)
	DEBUG_FN("grab_rate = " << iGrabRate)		//	Number of Milliseconds between grabs
	DEBUG_FN("max_frames = " << iMaxFrames)
	DEBUG_FN("image_list = " << sImageList)
	DEBUG_FN("image_name = " << sImageName)
	DEBUG_FN("zero_padding = " << iZeroPadding)
	DEBUG_FN("save_width = " << iSaveWidth)
	DEBUG_FN("save_height = " << iSaveHeight)
	DEBUG_FN("preview_width = " << iPreviewWidth)
	DEBUG_FN("preview_height = " << iPreviewHeight)
	DEBUG_FN("mouse_trigger = " << iMouseTrigger)
	DEBUG_FN("keyboard_trigger = " << iKeyboardTrigger)
	DEBUG_FN("timer_trigger = " << iTimerTrigger)



	ulCount = (unsigned long)(iFrameStart);
	ulFrameStart = (unsigned long)(iFrameStart);
	ulMaxFrames = (unsigned long)(iMaxFrames);

	fsr.release();


	return 0;
}

int main(int argc, char* argv[]){

	//	FileStorage fs(filename, FileStorage::READ);
	//	fs.open(filename, FileStorage::READ);


	getParameters(argc, argv);
  

	FileStorage fsw(sImageList, FileStorage::WRITE);
	fsw << "imagelist" << "[";

	int iKey;
/*
#ifndef NO_CAMERA



#endif

	Mat matPreviewLeft;
	Mat matPreviewRight;

	Mat matSaveLeft;
	Mat matSaveRight;

	Mat matStatus;

	vector<int> compression_params;
//	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
//	compression_params.push_back(9);


#ifdef NO_CAMERA


	printf(" Setting up dummy matrices");
	matPreviewLeft = Mat::zeros(iPreviewHeight, iPreviewWidth, CV_8U);
	matPreviewRight = Mat::zeros(iPreviewHeight, iPreviewWidth, CV_8U);

	matSaveLeft = Mat::zeros(iSaveHeight, iSaveWidth, CV_8U);
	matSaveRight = Mat::zeros(iSaveHeight, iSaveWidth, CV_8U);


	matStatus = Mat::zeros(iSaveHeight, iSaveWidth, CV_8U);

#endif

	while(1){

#ifndef NO_CAMERA 
		camPreviewLeft.grab();
		camPreviewRight.grab();

		camPreviewLeft.retrieve(matPreviewLeft,0);
		camPreviewRight.retrieve(matPreviewRight,0);
#endif


		imshow("Left", matPreviewLeft);
		imshow("Right", matPreviewRight);
		imshow("Status", matStatus);


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

#ifndef NO_CAMERA
			imwrite(cLeft,matPreviewLeft,compression_params);
			imwrite(cRight,matPreviewRight,compression_params);
#endif
			ulCount++;

			iClockStart = clock();

			bTriggerEnabled = FALSE;
	

		}


		if(iKey == 27 || iKey == 113)		// ESC or Q is hit
			break;


	}


	waitKey(0);
*/
	fsw << "]";
	fsw.release();
//	destroyWindow("Left");
//	destroyWindow("Right");
//	destroyWindow("Status");
//	destroyAllWindows();

	return 0;
}
