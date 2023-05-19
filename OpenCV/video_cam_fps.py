import cv2

# 0번 카메라 장치 연결
cap = cv2.VideoCapture(0)

# 캡쳐 객체 연결 확인
if not cap.isOpened():
    print("Camera open failed")
else:
    # CAP_PROP_FPS 상수 int
    fps = cap.get(cv2.CAP_PROP_FPS)
    width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
    height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
    print(f"frame size: {width} * {height}, fps: {fps}")

    # 이미지의 픽셀을 정하는 메서드(변수)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
    
    width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
    height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
    print(f"frame size: {width} * {height}, fps: {fps}")

    # int형으로 형변환하지 않으면, 실수가 된다.
    dt = int(1000 // fps)

    while True:
        ret, frame = cap.read()           
        if ret:
            frame_resize = cv2.resize(frame, (480,280))
            cv2.imshow('frame_resize', frame_resize)   
            cv2.imshow('frame', frame)   

            if cv2.waitKey(dt) != -1:    
                break                   
        else:
            print('no frame')
            break
    








