#include opencv2/opencv.hpp

using namespace cv;
using namespace std;

int main(int argc, char** argv){
    Mat foreground = imread("puppets.png");
    Mat alpha = imread("pippets_alpha.png");

    // 행렬의 타입 변환
    foreground.convertTo(foreground, CV_32FC3);
    background.convertTo(background, CV_32FC3);
    alpha.convertTo(alpha, CV_32FC3, 1.0/255);
    
    // OpenCV의 Mat클래스 사용으로 이미지의 형렬의 형태를 지정한다.
    Mat ouImage = Mat::zeros(foreground.size(), foreground.type());
    
    multiply(alpha, foreground, foreground);
    // scalar라는 템플릿 변수하구 한다.
    multiply(Scalar::all(1.0)-alpha, background, background);

    //foreground 와 background의 값을 ouImage에 저장한다.
    add(foreground, background, ouImage);
    //imshow를 통해 창에 띄워준다.
    imshow("alpha blended image", ouImage/255);
    // 이 값에 값들이 들어가는데, 마치 delay되는 시간을 작성한 거 같다.
    waitKey(0);

    return 0;
}

