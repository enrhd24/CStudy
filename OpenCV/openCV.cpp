#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int ac, char** av) {

	Mat img = imread("rain.png",0); //gray scale
	Mat color_img = imread("rain.png",1); // color scale
	Mat hist_img;

	// Histogram을 이용한 이미지 밝기 조절
	equalizeHist(img, hist_img);

	imshow("img", img);
	imshow("color_img", hist_img);
	
	waitKey(0);

	return 0;
}