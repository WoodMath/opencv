#include "camera.hpp"

Camera::Camera(){
	Camera::init();
};

Camera::Camera(int iSource){

	DEBUG_FN(" Debug worked ")
	Camera::setSource(iSource);
	Camera::init();
//	Camera::Camera();

};

Camera::~Camera(){

};

void Camera::init(){

	Camera::iPreviewWidth = 0;
	Camera::iPreviewHeight = 0;
	Camera::iSaveWidth = 0;
	Camera::iSaveHeight = 0;
	Camera::sDescription = "None";
	Camera::sDirectory = "./";
	Camera::iWindowX = 0;
	Camera::iWindowY = 0;
	Camera::iSaveCount = 0;
	Camera::bActive = false;
	Camera::iFrameRate = 900;	
//	Camera::compression_params.push_back(cv::CV_IMWRITE_PNG_COMPRESSION);
//	Camera::compression_params.push_back(9);
	Camera::sDirectory = "./";


};

void Camera::setSource(int iSource){

	std::cout << " *** " << "Setting Camera to " << iSource << " *** " << std::endl;
	Camera::iSource = iSource;

#ifndef SINGLE_VC
	Camera::camPreview.open(iSource);
#endif
	Camera::camSave.open(iSource);
#ifndef SINGLE_VC
	Camera::camPreview.set(CV_CAP_PROP_FPS, 1); 
#endif
};

void Camera::setPreviewSize(int iWidth, int iHeight){

	Camera::iPreviewWidth = iWidth;
	Camera::iPreviewHeight = iHeight;
#ifndef SINGLE_VC
	Camera::camPreview.set(CV_CAP_PROP_FRAME_WIDTH, iWidth);
	Camera::camPreview.set(CV_CAP_PROP_FRAME_HEIGHT, iHeight);
#endif
};

void Camera::setSaveSize(int iWidth, int iHeight){

	Camera::iSaveWidth = iWidth;
	Camera::iSaveHeight = iHeight;

	Camera::camSave.set(CV_CAP_PROP_FRAME_WIDTH, iWidth);
	Camera::camSave.set(CV_CAP_PROP_FRAME_HEIGHT, iHeight);

};

void Camera::setDescription(std::string sDescription){

	Camera::sDescription = sDescription;

	sprintf(Camera::cFileName, "%simage_%s_%0*u.pnm", Camera::sDirectory.c_str(), Camera::sDescription.c_str(), 3, Camera::iSaveCount); 
};

void Camera::setDirectory(std::string sDirectory){

	int iLen = sDirectory.length();
	std::string sLast = &(sDirectory.at(iLen - 1));
	std::string sSlash = "/";
	if(sLast != sSlash)
		sDirectory.append(sSlash);

	Camera::sDirectory = sDirectory;

	mkpath(sDirectory, 0755);
	// Still need to add code to make directory if does not exist
	
};

void Camera::setWindowPosition(int iX, int iY){

//	if(Camera::sDescription == "None")
//		return;

	Camera::iWindowX = iX;
	Camera::iWindowY = iY;

	DEBUG_FN(" Camera::sDescription = " << Camera::sDescription << "; Camera::iWindowX = " << Camera::iWindowX << "; Camera::iWindowY = " << Camera::iWindowY)



	if(!Camera::bActive)
		return;

	cv::moveWindow(Camera::sDescription, Camera::iWindowX, Camera::iWindowY);



};


void Camera::start(){

#ifndef SINGLE_VC
	if(!camPreview.isOpened() || !camSave.isOpened())  // check if we succeeded
		return;
#else
	if(!camSave.isOpened())
		return;
#endif

	Camera::bActive = true;
	cv::Mat matZeros;
#ifndef SINGLE_VC
	matZeros = cv::Mat::zeros(Camera::iPreviewHeight, Camera::iPreviewWidth, CV_8UC3);
#else
	matZeros = cv::Mat::zeros(Camera::iSaveHeight, Camera::iSaveWidth, CV_8UC3);
#endif
	cv::namedWindow(Camera::sDescription, WINDOW_MODE);
	cv::imshow(Camera::sDescription, matZeros);
#ifdef SINGLE_VC
	cv::resizeWindow(Camera::sDescription, Camera::iPreviewWidth, Camera::iPreviewHeight);
#endif
	cv::moveWindow(Camera::sDescription, Camera::iWindowX, Camera::iWindowY);
	DEBUG_FN(" Camera::sDescription = " << Camera::sDescription << "; Camera::iWindowX = " << Camera::iWindowX << "; Camera::iWindowY = " << Camera::iWindowY)
}

void Camera::wait(){


#ifndef SINGLE_VC
	if(!camPreview.isOpened() || !camSave.isOpened())  // check if we succeeded
		return;
#else
	if(!camSave.isOpened())
		return;
#endif
	if(!(Camera::bActive))
		return;

	char cKey;
	int iKey=0;




	clock_t iPreviewClockStart = clock(), iPreviewClockDiff;
	unsigned int iPreviewMSec;

	clock_t iSaveClockStart = clock(), iSaveClockDiff;
	unsigned int iSaveSec;

	DEBUG_FN(" iPreviewWidth = " << Camera::iPreviewWidth)
	DEBUG_FN(" iPreviewHeight = " << Camera::iPreviewHeight)

//	iKey = cv::waitKey(0);
	int iCountdown = 5;
	int iCurrent = iCountdown+1;

	DEBUG_FN(" Camera::iFrameRate = " << Camera::iFrameRate)
	while(1){
		iKey = -1;
//		cKey = getchar();
//		cKey = cv::waitKey(FRAME_RATE);
//		scanf("%c",&cKey);
//		std::cout << " cKey = " << cKey << std::endl ;
//		if(cKey == 'Q' || cKey == 'q' || cKey == 27)
//			break;
//		iKey = cv::waitKey(FRAME_RATE);
//		if(iKey == 27 || iKey == 113)
//			break;


		iPreviewClockDiff = clock() - iPreviewClockStart;
		iPreviewMSec = 1000 * iPreviewClockDiff / CLOCKS_PER_SEC;
		iSaveClockDiff = clock() - iSaveClockStart;
		iSaveSec = iSaveClockDiff / CLOCKS_PER_SEC;

	
		if(iPreviewMSec >= Camera::iFrameRate){

//			DEBUG_FN(" iPreviewMSec " << iPreviewMSec)
			Camera::display();
			iKey = cv::waitKey(1);
			if(iKey != -1)
				std::cout << " iKey = " << iKey << std::endl;
			if(iKey == 27 || iKey == 113)
				break;
			iPreviewClockStart = clock();
		}

		if(iSaveSec >= 1){
			iCurrent--;

			std::cout << " iCurrent = " << iCurrent << std::endl;
			if(iCurrent<=0){
				
				Camera::save();
				iCurrent = iCountdown + 1;
			}
			iSaveClockStart = clock();
		}

	}

};

void Camera::save(){


	sprintf(Camera::cFileName, "%simage_%s_%0*u.pnm", Camera::sDirectory.c_str(), Camera::sDescription.c_str(), 3, Camera::iSaveCount); 

	Camera::camSave.grab();
	Camera::camSave.retrieve(Camera::matSave,0);
	cv::imwrite(Camera::cFileName, Camera::matSave, Camera::compression_params);

	(Camera::iSaveCount)++;	
};

void Camera::display(){

#ifndef SINGLE_VC	
	Camera::camPreview.grab();
	Camera::camPreview.retrieve(Camera::matPreview,0);
#else
	Camera::camSave.grab();
	Camera::camSave.retrieve(Camera::matSave,0);
#endif
	if(!(Camera::bActive))
		return;

#ifndef SINGLE_VC
	cv::imshow(Camera::sDescription, Camera::matPreview);
#else
	cv::imshow(Camera::sDescription, Camera::matSave);
#endif

};

void Camera::stop(){

	cv::destroyWindow(Camera::sDescription);
	Camera::bActive = false;
};

void Camera::setFrameRate(unsigned int iFrameRate){

	Camera::iFrameRate = iFrameRate;
};

char* Camera::getFileName(){
	
	return Camera::cFileName;
};

std::string Camera::getDescription(){

	return Camera::sDescription;
};

void Camera::printDebug(){

	DEBUG_FN(" Camera::iSource = " << Camera::iSource)
	DEBUG_FN(" Camera::sDescription = " << Camera::sDescription)

};

bool Camera::isActive(){

	return Camera::bActive;
};
