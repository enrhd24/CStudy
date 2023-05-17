#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
us namespace cv;

int main(){

    Mat src = imread("opencv.png", IMREAD_COLOR);
    if(false == src.empty()){
        imshow("opencv",src);
        waitKey();

        destroyAllWindows();
    }
    return 0;
}