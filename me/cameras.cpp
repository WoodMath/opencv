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
	Cameras::setFileList("list.txt");
	Cameras::setDirectory("./");
	Cameras::bActive = false;
};

void Cameras::start(){

	Cameras::bActive = true;
	Cameras::disp.start();
	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->start();
	}
	
	std::string sFull = Cameras::sDirectory;
	sFull.append(Cameras::sFileList);
	Cameras::sFullPathFileList = sFull;
	Cameras::fFileList.open((Cameras::sFullPathFileList).c_str());

	DEBUG_FN(" Cameras::sFullPathFileList = " << Cameras::sFullPathFileList)

};

void Cameras::wait(){

	if(!Cameras::bActive)
		return;

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

	if(!Cameras::bActive)
		return;

	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->display();
	}

};

void Cameras::save(){

	if(!Cameras::bActive)
		return;

	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->save();
		Cameras::fFileList << ((Cameras::camCameras[iInc])->getFileName()) << std::endl;

	}

};

void Cameras::stop(){

	if(!Cameras::bActive)
		return;

	Cameras::disp.stop();
	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->stop();
	}
	Cameras::fFileList.close();

	Cameras::bActive = false;
};

void Cameras::setDirectory(std::string sDirectory){

	int iStatus;

	int iLen;
	std::string sLast;
	std::string sSlash = "/";

	// Check main directory 
	iLen = sDirectory.length();
	sLast = &(sDirectory.at(iLen - 1));

	if(sLast != sSlash)
		sDirectory.append(sSlash);

	
	Cameras::sDirectory = sDirectory;

	DEBUG_FN(" sDirectory = " << Cameras::sDirectory)

	std::string sDescription, sDescriptionDir;
	std::string sFull;

	for(int iInc=0; iInc < Cameras::iCameraCount; iInc++){
		sDescription = (Cameras::camCameras[iInc])->getDescription();
		sDescriptionDir = sDescription;

		sFull = "./";
		sFull.append(sDirectory);
		sFull.append(sDescriptionDir);
		sFull.append("/");
		mkpath(sFull,0755);
	
//		DEBUG_FN(" sFull = " << sFull << " getenv(\"PWD\") = " << getenv("PWD"));
//		DEBUG_FN(" iInc = " << iInc)
		(Cameras::camCameras[iInc])->setDirectory(sFull);
	}
	
};

void Cameras::setFileList(std::string sFileList){

	Cameras::sFileList = sFileList;
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





