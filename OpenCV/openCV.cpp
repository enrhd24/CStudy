#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int ac, char** av) {

	Mat img = imread("rain.png",0); //gray scale
	Mat color_img = imread("rain.png",1); // color scale

	// 이미지 밝기 조절 [덧셈, 뺄셈]
	Mat img_2 = img + 100;
	Mat img_3 = img - 100;
	Mat img_4 = img * 100;
	Mat img_5 = img / 100;

	imshow("img", img);
	imshow("img_2", img_2);
	imshow("img_3", img_3);
	imshow("img_4", img_4);
	imshow("img_5", img_5);
	
	waitKey(0);

	return 0;
}