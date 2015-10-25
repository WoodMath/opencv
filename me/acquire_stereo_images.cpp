#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <time.h>

using namespace cv;

#define WINDOW_MODE WINDOW_NORMAL


int main(int argc, char* argv[]){

	//	FileStorage fs(filename, FileStorage::READ);
	//	fs.open(filename, FileStorage::READ);



	string sFileName = "config.yml";
	string sImageList;
	FileStorage fsr(sFileName, FileStorage::READ);



	int iDelay, iMaxFrames;
	unsigned int iWidth, iHeight;
	unsigned long ulCount = 0;
	unsigned long ulMaxFrames;
	int iGrabFrequency;
	int iZeroPadding;
	int iAutoGrab;

	fsr["delay"] >> iDelay;
	fsr["max_frames"] >> iMaxFrames;
	fsr["image_list"] >> sImageList;
	fsr["auto_grab"] >> iAutoGrab;
	fsr["zero_padding"] >> iZeroPadding;
	fsr["grab_frequency"] >> iGrabFrequency;


	ulMaxFrames = (unsigned long)(iMaxFrames);

	fsr.release();

  	FileStorage fsw(sImageList, FileStorage::WRITE);
	fsw << "imagelist" << "[";

	int iKey;


	VideoCapture camLeft(0); // open the default camera
	VideoCapture camRight(1); // open the default camera





	if(!camLeft.isOpened() || !camRight.isOpened())  // check if we succeeded
		return -1;


/*
	camLeft.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	camLeft.set(CV_CAP_PROP_FRAME_HEIGHT, 960);
	camRight.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	camRight.set(CV_CAP_PROP_FRAME_HEIGHT, 960);
*/
	Mat matLeft;
	Mat matRight;

	vector<int> compression_params;
//	compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
//	compression_params.push_back(9);

	namedWindow("Left",  WINDOW_MODE);
	namedWindow("Right",  WINDOW_MODE);

	char cLeft[256];
	char cRight[256];

	clock_t iClockStart = clock(), iClockDiff;
	unsigned int iSec;


	while(1){
		camLeft.grab();
		camRight.grab();

		camLeft.retrieve(matLeft,0);
		camRight.retrieve(matRight,0);
		imshow("Left", matLeft);
		imshow("Right", matRight);



		iKey = waitKey(iDelay);

		iClockDiff = clock() - iClockStart;
		iSec = iClockDiff / CLOCKS_PER_SEC;



		if(iKey > -1) 
			printf(" iKey = %d \n", iKey);


		if(iKey == 32 || (iAutoGrab && iSec >= iGrabFrequency)){
			// save images using space bar
			sprintf(cLeft,"./calib_images/left_%0*lu.png", iZeroPadding, ulCount);
			sprintf(cRight,"./calib_images/right_%0*lu.png", iZeroPadding, ulCount);

			fsw << string(cLeft);
			fsw << string(cRight);

			printf("\t Saving frames %s and %s (%0*lu of %0*lu) .\n", cLeft, cRight, iZeroPadding, ulCount+1, iZeroPadding, ulMaxFrames);

			imwrite(cLeft,matLeft,compression_params);
			imwrite(cRight,matRight,compression_params);
			ulCount++;

			iClockStart = clock();


		}


		if(iKey == 27 || iKey == 113)		// ESC or Q is hit
			break;
		if(ulCount >= ulMaxFrames)
			break;


	}

	fsw << "]";
	fsw.release();

	return 0;
}
