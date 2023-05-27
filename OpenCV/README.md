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
