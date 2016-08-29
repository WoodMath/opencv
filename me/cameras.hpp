#ifndef _CAMERAS_

#define _CAMERAS_

#include "camera.hpp"

class Cameras{
public:
	Cameras();
	~Cameras();
	
	void start();
	void wait();
	void display();
	void save();
	void stop();

	void addCamera(Camera* camAdd);

private:
	int iCameraCount;

	cv::Mat matCountdown;
};

#endif
