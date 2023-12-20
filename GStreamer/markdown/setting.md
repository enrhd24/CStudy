# 개발 환경

- Ubuntu LTS 20.04
- VirtualBox 7.0
- sudo apt-get update
- sudo apt-get upgrade

# 개발 settings
- su root
- sudo apt-get install {G-Streamer}
- dpkg -l | grep gstreamer
- sudo apt-get install git
- gcc 01.c -o 01 `pkg-config --cfloags --libs gstreamer-1.0`
