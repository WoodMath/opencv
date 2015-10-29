#include <stdio.h>
#include <math.h>
#include <opencv2/opencv.hpp>

//#define WINDOW_MODE WINDOW_AUTOSIZE
#define WINDOW_MODE WINDOW_NORMAL
//#define TRACKBAR_MAX (4096)
#define TRACKBAR_MAX (255)
//#define WINDOW_CONTROL ("Canny")
#define WINDOW_CONTROL ("Original")

using namespace cv;

Mat image_color, image_gray, image_canny;
Mat image_input, image_output;
Mat image_circles;
Mat image_new;
Mat image_bw;
Mat image_mask, image_show;
int loThresh = 1100, hiThresh = 1200;
int minRadius = 0, maxRadius = 0;
int thicknessCircle = 5;
int dist = 0;
int thresh = 0;
int c = 5, blockSize = 5;
vector<Vec3f> circles;
int iPts = 0;
Point pts[4];
static void onMouse( int event, int x, int y, int, void* ){

	if( event != CV_EVENT_LBUTTONDOWN )
		return;

	printf(" x = %d ; y = %d ; \n", x, y);

	if(iPts == 0){
		image_mask = Mat::zeros(image_gray.rows, image_gray.cols, CV_8UC1);

		image_gray.copyTo(image_show);
	}
/*
	if(iPts >= 4){
		iPts = 0;
	}else{
		iPts++;
		pts[iPts-1] = Point(x, y);
	}
*/

	
	pts[iPts] = Point(x, y);
	iPts++;
	printf(" iPts = %d \n", iPts);
	if(iPts == 4){

		fillConvexPoly( image_mask,
			pts,4,
			Scalar( 1, 1, 1 ),
//			Scalar( 255, 255, 255 ),
			8 );

		image_show = image_gray.mul(image_mask);
//		image_show = image_mask;
		iPts = 0;
	}

	imshow(WINDOW_CONTROL, image_show);

//	Canny(image_gray, image_canny, loThresh, hiThresh, 5);
//	imshow("New Image", image_canny);

//	waitKey(0);

}

void onTrackBarOld( int, void* ){


	circles.clear();
	Canny(image_gray, image_canny, loThresh, hiThresh, 5);


	printf(" circles.size() = %d ; hiThresh = %d ; loThresh = %d; \n", circles.size(), hiThresh, loThresh);

	int loThreshUse = 100*loThresh+1;
	int hiThreshUse = 100*hiThresh+1;
	int distUse = 10*dist+1;
	HoughCircles( image_gray, circles, CV_HOUGH_GRADIENT, 1, distUse, hiThreshUse, loThreshUse, minRadius, maxRadius );

	image_gray.copyTo(image_circles);


	for( size_t i = 0; i < circles.size(); i++ ){
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// circle center
		circle( image_circles, center, 3, Scalar(0,255,0), -1, thicknessCircle, 0 );
		// circle outline
		circle( image_circles, center, radius, Scalar(0,0,255), 3, thicknessCircle, 0 );
	}
/*
	imshow("Canny", image_canny);

	imshow("Original", image_gray);

	imshow("Original", image_bw);
*/


//	waitKey(0);

}

void onTrackBar( int, void* ){



	int threshUse = thresh;
	int cUse = c;
	int blockSizeUse = 2*blockSize+1;
//	threshold(image_gray, image_bw, threshUse, 255, THRESH_BINARY);
	adaptiveThreshold(image_gray, image_bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, blockSizeUse, cUse);
//	imshow("Original", image_gray);
	imshow("Original", image_bw);


//	waitKey(0);

}

int main(int argc, char* argv[] ){
	if ( argc != 2 ){
		printf("usage: %s <Image_Path>\n", argv[0]);
		return -1;
	}

	int iRowInc, iColInc;


	image_color = imread( argv[1], CV_LOAD_IMAGE_COLOR );
	cvtColor( image_color, image_gray, CV_BGR2GRAY );
	image_mask = Mat::zeros(image_gray.rows, image_gray.cols, CV_8UC1);
	image_show = Mat::zeros(image_gray.rows, image_gray.cols, CV_8UC1);

//	image_color.copyTo(image_gray);
//	medianBlur(image_gray, image_gray, 3);

	if ( !image_color.data ){
		printf("No image data \n");
		return -1;
	}

	namedWindow("Original", WINDOW_MODE );
//	namedWindow("Canny", WINDOW_MODE );
/*
	createTrackbar( "loThresh", WINDOW_CONTROL, &loThresh, TRACKBAR_MAX, onTrackBar);
	createTrackbar( "hiThresh", WINDOW_CONTROL, &hiThresh, TRACKBAR_MAX, onTrackBar);

	createTrackbar( "minRaduis", WINDOW_CONTROL, &minRadius, TRACKBAR_MAX, onTrackBar);
	createTrackbar( "maxRadius", WINDOW_CONTROL, &maxRadius, TRACKBAR_MAX, onTrackBar);
	createTrackbar( "dist", WINDOW_CONTROL, &maxRadius, TRACKBAR_MAX, onTrackBar);

	createTrackbar("Threshold", WINDOW_CONTROL, &thresh, TRACKBAR_MAX, onTrackBar);
	createTrackbar("C", WINDOW_CONTROL, &c, TRACKBAR_MAX, onTrackBar);
	createTrackbar("BlockSize", WINDOW_CONTROL, &blockSize, TRACKBAR_MAX, onTrackBar);
*/

//	namedWindow("Circle", WINDOW_MODE );

	
	

	setMouseCallback(WINDOW_CONTROL, onMouse, 0 );

//	onTrackBar( 0, 0 );


//	onMouse( CV_EVENT_LBUTTONDOWN, 0, 0, 0, 0 );



	image_gray.copyTo(image_show);
	imshow(WINDOW_CONTROL, image_show);

	waitKey(0);

	return 0;
}
