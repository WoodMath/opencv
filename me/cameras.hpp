#ifndef _CAMERAS_

#define _CAMERAS_

#include "camera.hpp"
#include "display.hpp"

class Cameras{
public:
	Cameras();
	~Cameras();
	
	void start();
	void wait();
	void display();
	void save();
	void stop();

	void setDirectory(std::string sDirectory);
	void setFrameRate(unsigned int iFrameRate);

	void addCamera(Camera &camAdd);
	void printDebug();

private:
	int iCameraCount;
	Camera **camCameras;
	unsigned int iFrameRate;
	Display disp;

	cv::Mat matCountdown;
	void init();


};

#endif
