#include "display.hpp"

Display::Display(){


	Display::iWindowWidth = 480;
	Display::iWindowHeight = 360;
	
//	Display::setWindowSize(320, 240);
//	Display::iWindowWidth = 320;
//	Display::iWindowHeight = 240;
//	Display::sDescription = "Test";

	DEBUG_FN(" iWindowHeight = " << Display::iWindowHeight)
	DEBUG_FN(" iWindowWidth = " << Display::iWindowWidth)

	Display::setDescription("Test");


};

Display::Display(std::string sDescription){

	Display::setWindowSize(320,240);

	Display::Display();

	DEBUG_FN(" iWindowHeight = " << Display::iWindowHeight)
	DEBUG_FN(" iWindowWidth = " << Display::iWindowWidth)


	Display::setDescription(sDescription);

};

Display::~Display(){

};

void Display::setDescription(std::string sDescription){

	Display::sDescription = sDescription;

	DEBUG_FN(" iWindowHeight = " << Display::iWindowHeight)
	DEBUG_FN(" iWindowWidth = " << Display::iWindowWidth)


};

void Display::start(){

	DEBUG_FN(" iWindowHeight = " << Display::iWindowHeight)
	DEBUG_FN(" iWindowWidth = " << Display::iWindowWidth)


	Display::bActive = true;
	cv::namedWindow(Display::sDescription, WINDOW_MODE);

	cv::moveWindow(Display::sDescription, Display::iWindowX, Display::iWindowY);


};

void Display::display(std::string sDisplay){

	if(!(Display::bActive))
		return;

	DEBUG_FN(" iWindowHeight = " << Display::iWindowHeight)
	DEBUG_FN(" iWindowWidth = " << Display::iWindowWidth)

	Display::matDisplay = cv::Mat::zeros(Display::iWindowHeight, Display::iWindowWidth, CV_8UC3);
	cv::imshow(Display::sDescription, Display::matDisplay);
	cv::waitKey(0);
//	cv::moveWindow(Display::sDescription, Display::iWindowX, Display::iWindowY);



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

	Display::iWindowWidth = iWidth;
	Display::iWindowHeight = iHeight;

	
	Display::matDisplay = cv::Mat::zeros(iHeight, iWidth, CV_8UC3);

	DEBUG_FN(" iWindowHeight = " << Display::iWindowHeight)
	DEBUG_FN(" iWindowWidth = " << Display::iWindowWidth)



};

void Display::setWindowPosition(int iX, int iY){

	Display::iWindowX = iX;
	Display::iWindowY = iY;


};


/*
	cv::namedWindow("Test");

	std::string text = "Funny text inside the box";
	int fontFace = cv::FONT_HERSHEY_SIMPLEX;
	double fontScale = 2;
	int thickness = 3;

//	cv::Mat matText(600, 800, CV_8UC3, cv::Scalar::all(0));

	int baseline=0;
	cv::Size textSize = cv::getTextSize(text, fontFace,
                            fontScale, thickness, &baseline);
	baseline += thickness;

	// center the text
	cv::Point textOrg((matText.cols - textSize.width)/2, (matText.rows + textSize.height)/2);

	// draw the box
//	cv::rectangle(matText, textOrg + cv::Point(0, baseline), textOrg + cv::Point(textSize.width, -textSize.height), cv::Scalar(0,0,255));

	// ... and the baseline first
//	cv::line(matText, textOrg + cv::Point(0, thickness), textOrg + cv::Point(textSize.width, thickness), cv::Scalar(0, 0, 255));

	// then put the text itself
	cv::putText(matText, text, textOrg, fontFace, fontScale, cv::Scalar::all(255), thickness, 8);

	cv::imshow("Test",matText);

	cv::waitKey(0);

	cv::destroyWindow("Test");

*/
