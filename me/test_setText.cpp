
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "opencv2/opencv.hpp"


int main(int arc, char* argv[]){

	cv::Mat matText;

	matText = cv::Mat::zeros(240, 320, CV_8UC3);


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


}
