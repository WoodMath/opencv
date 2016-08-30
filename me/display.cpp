#include "display.hpp"

Display::Display(){

	Display::init();
};

Display::Display(std::string sDescription){

	Display::init();


	Display::setDescription(sDescription);

};

Display::~Display(){

};

void Display::init(){

//	DEBUG_FN(" Display::init() called " << std::endl)

	Display::setWindowSize(320, 240);

	Display::iFontFace = cv::FONT_HERSHEY_SIMPLEX;
	Display::dFontScale = 2;
	Display::iThickness = 3;
	Display::iBaseline = 0;



	
	Display::setWindowSize(320, 240);
	Display::setWindowPosition(0, 0);
	Display::sDescription = "Display";




};

void Display::setDescription(std::string sDescription){

	Display::sDescription = sDescription;



};

void Display::start(){

//	DEBUG_FN(" iWindowHeight = " << Display::iWindowHeight)
//	DEBUG_FN(" iWindowWidth = " << Display::iWindowWidth)


	Display::bActive = true;
	cv::namedWindow(Display::sDescription, WINDOW_MODE);
	cv::Mat matZeros = cv::Mat::zeros(Display::iWindowHeight, Display::iWindowWidth, CV_8UC3);
	cv::imshow(Display::sDescription, matZeros);
	cv::moveWindow(Display::sDescription, Display::iWindowX, Display::iWindowY);


};

void Display::display(std::string sDisplay){

	if(!(Display::bActive))
		return;


	Display::matDisplay = cv::Mat::zeros(Display::iWindowHeight, Display::iWindowWidth, CV_8UC3);

	// OpenCV text goes here
	Display::szTextSize = cv::getTextSize(sDisplay, Display::iFontFace,
                            Display::dFontScale, Display::iThickness, &(Display::iBaseline));
	Display::iBaseline += Display::iThickness;

	// center the text
	Display::ptTextOrg = cv::Point((Display::matDisplay.cols - szTextSize.width)/2, (Display::matDisplay.rows + Display::szTextSize.height)/2);

	// then put the text itself
	cv::putText(Display::matDisplay, sDisplay, Display::ptTextOrg, Display::iFontFace, Display::dFontScale, cv::Scalar::all(255), Display::iThickness, 8);



	cv::imshow(Display::sDescription, Display::matDisplay);
//	cv::waitKey(0);
	cv::moveWindow(Display::sDescription, Display::iWindowX, Display::iWindowY);
//	cv::waitKey(0);


};

void Display::display(const char* cDisplay){

	if(!(Display::bActive))
		return;

	Display::display((std::string)cDisplay);
/*
	Display::matDisplay = cv::Mat::zeros(Display::iWindowHeight, Display::iWindowWidth, CV_8UC3);
	cv::imshow(Display::sDescription, Display::matDisplay);
	cv::moveWindow(Display::sDescription, Display::iWindowX, Display::iWindowY);
*/


};

void Display::stop(){

	Display::bActive = false;
	cv::destroyWindow(Display::sDescription);

};


void Display::setWindowSize(int iWidth, int iHeight){

	DEBUG_FN(" Display::setWindowSize called " << std::endl)

	Display::iWindowWidth = iWidth;
	Display::iWindowHeight = iHeight;

	
	Display::matDisplay = cv::Mat::zeros(iHeight, iWidth, CV_8UC3);




};

void Display::setWindowPosition(int iX, int iY){

	Display::iWindowX = iX;
	Display::iWindowY = iY;


};


/*

*/
