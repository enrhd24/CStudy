#### [ROS_Study](https://neosla.tistory.com/m/39)

#### 05.04.2023
![05.04.2023](ROS%EC%A0%81%EC%9A%A9%20%EC%8B%9C%EC%8A%A4%ED%85%9C.png)
1. Install Ubuntu 20.04
2. Install ROS_Noetic Ninjemys
3. After cloning -> cd folder -> git remote set-url origin 레퍼지토리주소
4. ROS의 용어 정리 및 통신 방식 and ROS node Test 하는 방법 숙지
5. Robot을 알기 위한 사전지식은 무엇인가?? ROS적용 시스템 added

#### 05.05 ~ 05.06.2023
1. ROS 를 이해하기 위한 웹사이트 및 정리하기
2. ROS설치에 앞서 날짜 및 지원 버전에 따라 설치방법이 달라
   해당 ROS.org 페이지를 확인하여 설치하는 것이 안전하다.
3. ROS의 용어 정리
4. ROS의 Node란?
5. ROS의 Message란?
6. ROS의 FileSystem이란?

### 05.09.2023
[공부](https://keep-steady.tistory.com/45)
1. 로봇공학 = 기계공학 ^ 전자공학 ^ 컴공
- 기계공학 -> 로봇의 외관 디자인
- 전자공학 -> 모터제어, 센싱
- 컴공학 -> AI로 지능구현

2. 로봇의 종류
- 산업용 & 협동 로봇[용접 및 반도체 자동자 공장라인에서 사람을 대체]
- 서비스 로봇 [산업용 로봇을 제외한 모든 로봇]
   - HRI(Human Robot Interaction)기술
- 자율주행자동차 [이미지/라이다 장애물 인식]
- 착용형 로봇, 드론/무인기, 국방 로봇
- 로봇 구동기[모터로 제어 (DC모터, 서보모터)] 

3. 로봇 구성 요소
- 바디부 [로봇 팔, 다리]
- 말단부 [손, 발]
- 구동기 [관절]
- 제어기 [근육]
- 센서 [눈, 코, 입, 귀, 촉감]
- 소프트웨어 [머리]
- 동력장치 [소화기관]

4. 로봇 개발 단계
- 기구 설계 [로봇 라드웨어 디자인]
- 시뮬레이션 [행동 생성 및 개발기술 확인]
- 전자부 설계 [모데, 센서 제어를 위한 회로 디자인]
- 시제품 제작 [프로토타입 만들기]
- 상품화 개발 [대량생산을 통한 원가 절감, 디자인 수정]

4. AI * Robotics
   1. 로봇제어(강화학습) [행동 컨트롤]
   2. 환경인식(센서처리) [이미지, 라이다, 초음파 센서]
   3. SLAM [위치추정 및 주변 환경 지도 작성]
   4. 자율주행 [경로 생성, 충돌 회피]
- 1.. 작업능력 2. 감각능력 3. 인지 능력
- [자료1](https://robetchoi.gitbook.io/ros/1)
- [자료2](https://github.com/robotpilot/ros-seminar)


### 05.10.2023
1. ROS 환경 구성
2. turtlesim, ROS2, rqt
- ros2 run turtlesim turtlesim_node
- ros2 run turtlesim turtle_teleop_key
   1. ros2 node list
   2. ros topic list
   3. ros service list
   4. ros acton list
- sudo apt install -nros-foxy-rqt*
   - rqt
3. sudo apt update
