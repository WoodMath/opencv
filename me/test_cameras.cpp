#include <stdio.h>
#include "cameras.hpp"
#include "display.hpp"

int main(int arc, char* argv[]){

	Camera camLeft(0);
//	Camera camRight(1);

	camLeft.setPreviewSize(320,240);
	camLeft.setWindowPosition(0,0);
	camLeft.setSaveSize(640,480);
	camLeft.setDescription("Left");

//	camRight.setPreviewSize(320,240);
//	camRight.setWindowPosition(320,0);
//	camRight.setSaveSize(640,480);
//	camRight.setDescription("Right");

//	camLeft.start();
//	camLeft.wait();
//	camLeft.stop();
//	camLeft.setSource(0);

	Cameras cams;
	cams.addCamera(camLeft);
//	cams.addCamera(camRight);
	cams.start();
//	cv::waitKey(0);
	cams.wait();
	cams.stop();

//	cams.printDebug();

}
