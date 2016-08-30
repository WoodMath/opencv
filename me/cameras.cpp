#include "cameras.hpp"

Cameras::Cameras(){

	Cameras::init();
};

Cameras::~Cameras(){



};

void Cameras::init(){
	Cameras::iCameraCount = 0;
	Cameras::iFrameRate = 600;
	Cameras::disp.setWindowPosition(640,0);

};

void Cameras::start(){

	Cameras::disp.start();
	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->start();
	}

};

void Cameras::wait(){


	for(int iInc = 0; iInc < Cameras::iCameraCount; iInc++)
		if(!(Cameras::camCameras[iInc]->isActive()))
			return;

	char cDisplay[32];
	char cKey;
	int iKey=0;




	clock_t iPreviewClockStart = clock(), iPreviewClockDiff;
	unsigned int iPreviewMSec;

	clock_t iSaveClockStart = clock(), iSaveClockDiff;
	unsigned int iSaveSec;

	unsigned int iFile = 0;

//	iKey = cv::waitKey(0);
	int iCountdown = 5;
	int iCurrent = iCountdown+1;

	DEBUG_FN(" Cameras::iFrameRate = " << Cameras::iFrameRate)
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

		if(iPreviewMSec >= Cameras::iFrameRate){

//			DEBUG_FN(" iPreviewMSec " << iPreviewMSec)
			Cameras::display();
			iKey = cv::waitKey(1);
			if(iKey != -1)
				std::cout << " iKey = " << iKey << std::endl;
			if(iKey == 27 || iKey == 113)
				break;
			iPreviewClockStart = clock();
		}

		if(iSaveSec >= 1){
			iCurrent--;

			sprintf(cDisplay," 0:%0*d ", 2, iCurrent);
			Cameras::disp.display(cDisplay);

			std::cout << " iCurrent = " << iCurrent << std::endl;
			if(iCurrent<=0){
				
				Cameras::save();
				iCurrent = iCountdown + 1;
			}
			iSaveClockStart = clock();
		}

	}


};

void Cameras::display(){

	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->display();
	}

};

void Cameras::save(){

	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->save();
	}

};

void Cameras::stop(){
	Cameras::disp.stop();
	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->stop();
	}

};


void Cameras::setDirectory(std::string sDirectory){

	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->setDirectory(sDirectory);
	}
	
};

void Cameras::setFrameRate(unsigned int iFrameRate){

	Cameras::iFrameRate = iFrameRate;
};

void Cameras::addCamera(Camera &camAdd){

	Camera* camAddress = &camAdd;
	Camera **camResized;
	Camera **camOld = Cameras::camCameras;
	camResized = new Camera*[Cameras::iCameraCount+1];

//	DEBUG_FN(" Cameras::iCameraCount = " << Cameras::iCameraCount)

	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		camResized[iInc] = camOld[iInc];
	}

	camResized[Cameras::iCameraCount] = camAddress;
	
	Cameras::camCameras = camResized;
#ifdef DEBUG
//	camAddress->printDebug();
#endif
	if(Cameras::iCameraCount > 0)
		delete[] camOld;

	(Cameras::iCameraCount)++;

};


void Cameras::printDebug(){

#ifdef DEBUG

//	for(int iInc = 0; iInc < Cameras::iCameraCount; iInc++)
//		((Cameras::camCameras)[iInc])->printDebug();
	
#endif

};





