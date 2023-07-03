1. python3 -m pip install --user -U virtualenv
2. virtualenv env
> Linux : source /env/bin/activate<br>
> Windows : ./env/Scripts/activate

#### ubuntu 20.04 LTS OpenCV 4.7.0 install

> sudo apt-get update && sudo apt-get upgrade<br>
> sudo apt-get install build-essential cmake python3-numpy python3-dev python3-tk libavcodec-dev libavformat-dev libavutil-dev libswscale-dev libavresample-dev libdc1394-dev libeigen3-dev libgtk-3-dev libvtk7-qt-dev<br>
> wget https://github.com/opencv/opencv/archive/4.7.0.tar.gz<br>
> tar -xvzf 4.7.0.tar.gz<br>
> rm 4.7.0.tar.gz<br>
> cd opencv-4.7.0<br>
> mkdir build;cd build<br>
> cmake -DBUILD_EXAMPLES=ON ..<br>
> make -j4<br>
> sudo make install<br>
> echo '/usr/local/lib' | sudo tee --append /etc/ld.so.conf.d/opencv.conf<br>
> sudo ldconfig<br>
> echo 'PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig' | sudo tee --append ~/.bashrc<br>
> echo 'export PKG_CONFIG_PATH' | sudo tee --append ~/.bashrc<br>
> source ~/.bashrc<br>
> python3<br>
> import cv2<br>
> cv2.__version__<br>

#### ubuntu ~/.bashrc setting
1. en = 'gedit ~/.bashrc'
2. sen = 'source ~/.bashrc'

---

#### Opencv

1. 3rdparty
- 라이브러링와 헤더가 포함되어 있다.
- Win32, Win64버전을 빌드하는 것이 바람직
2. apps
- app(Application)
- 이것은 볼 필요는 없습니다.
3. cmake
- 빌드 시스템
4. data
- 라이브러리 or 응용 프로그램
- 다양한 데이터가 포함되어 있습니다.
5. doc - 문서 형식인거 가타여
6. include - header파일을 모아 두는 것
7. modules - 각각의 모델의 코드를 모아 두는 것
8. platforms - 교차 컴파일에 필요한 도구 체인 및 추가 파일이 포함
9. samples - 샘플코드가 있는 것
10. perf - 퍼포먼스 테스트

### modules - core
- core / doc / intro.markdown

### modules - src
- martix.cpp [matAllocator]
- arithm.cpp [cv::add]_addTab()
    - 행렬의 사이즈가 같은 경우 더하기 하기
    - hal_각 os 마다 가지고 있는 최적화가 있다

- getAddTab -> array -> hal -> add8u[하드웨어]
  - 아리스메트릭 -> 스위치 0, 1[행렬의 크기가 같아야 가능]
  - src - dst

### opencv-hal-proposal - README.md

