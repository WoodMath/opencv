#include <stdio.h>
#include "camera.hpp"


int main(int arc, char* argv[]){

	Camera camLeft(1);

	camLeft.setPreviewSize(640,480);
	camLeft.setSaveSize(640,480);
	camLeft.setDescription("Left");
	camLeft.start();
	camLeft.wait();
	camLeft.stop();
//	camLeft.setSource(0);
}
