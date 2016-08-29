#include <stdio.h>
#include "display.hpp"


int main(int arc, char* argv[]){

	Display disp;
	disp.start();

	const char* cTest = "Test\0";
	disp.display(cTest);
//	cv::waitKey(0);
	disp.stop();

}
