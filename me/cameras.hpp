#ifndef _CAMERAS_

#define _CAMERAS_

#include <fstream>
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
	void setFileList(std::string sFileList);

	void setFrameRate(unsigned int iFrameRate);

	void addCamera(Camera &camAdd);
	void printDebug();

private:
	int iCameraCount;
	Camera **camCameras;
	unsigned int iFrameRate;
	std::string sDirectory;
	std::string sFileList;
	std::string sFullPathFileList;
	std::ofstream fFileList;

	Display disp;

	bool bActive;
	cv::Mat matCountdown;
	void init();


};

#endif
