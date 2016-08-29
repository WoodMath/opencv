#include "camera.hpp"




Camera::Camera(){

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
	
//	Camera::compression_params.push_back(cv::CV_IMWRITE_PNG_COMPRESSION);
//	Camera::compression_params.push_back(9);
	Camera::sDirectory = "./";

};

Camera::Camera(int iSource){

	DEBUG_FN(" Debug worked ")
	Camera::setSource(iSource);
	Camera::Camera();

};

Camera::~Camera(){

};

void Camera::setSource(int iSource){

	std::cout << " *** " << "Setting Camera to " << iSource << " *** " << std::endl;
	Camera::iSource = iSource;

	Camera::camPreview.open(iSource);
	Camera::camSave.open(iSource);
 
};

void Camera::setPreviewSize(int iWidth, int iHeight){

	Camera::iPreviewWidth = iWidth;
	Camera::iPreviewHeight = iHeight;

	Camera::camPreview.set(CV_CAP_PROP_FRAME_WIDTH, iWidth);
	Camera::camPreview.set(CV_CAP_PROP_FRAME_HEIGHT, iHeight);

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
	// Still need to add code to make directory if does not exist
	
};

void Camera::setWindowPosition(int iX, int iY){

	if(Camera::sDescription == "None")
		return;

	Camera::iWindowX = iX;
	Camera::iWindowY = iY;
};


void Camera::start(){

	if(!camPreview.isOpened() || !camSave.isOpened())  // check if we succeeded
		return;

	Camera::bActive = true;
	cv::namedWindow(Camera::sDescription, WINDOW_MODE);
	cv::moveWindow(Camera::sDescription, Camera::iWindowX, Camera::iWindowY);

}

void Camera::wait(){



	if(!camPreview.isOpened() || !camSave.isOpened())  // check if we succeeded
		return;

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

		if(iPreviewMSec >= FRAME_RATE){
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
	
	Camera::camPreview.grab();
	Camera::camPreview.retrieve(Camera::matPreview,0);

	if(!(Camera::bActive))
		return;

	cv::imshow(Camera::sDescription, Camera::matPreview);


};

void Camera::stop(){

	cv::destroyWindow(Camera::sDescription);
	Camera::bActive = false;
};
