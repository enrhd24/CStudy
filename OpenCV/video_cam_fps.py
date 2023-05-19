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

    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
    width = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
    height = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
    print(f"frame size: {width} * {height}, fps: {fps}")

    while True:
        ret, frame = cap.read()           
        if ret:
            cv2.imshow('camera', frame)   
            if cv2.waitKey(1) != -1:    
                break                   
        else:
            print('no frame')
            break
    








