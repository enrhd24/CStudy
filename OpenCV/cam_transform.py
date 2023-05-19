import cv2

cap = cv2.VideoCapture(0)

if cap.isOpened():
    w = cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
    h = cap.get(cv2.CAP_PROP_FRAME_WIDTH)
    fps = cap.get(cv2.CAP_PROP_FPS)
    dt = int(1000/fps)
    center = (int(w/2),int(h/2))

    while True:
        ret, frame = cap.read()

        if not ret:
            break
        
        frame_rotate = cv2.rotate(frame, cv2.ROTATE_90_CLOCKWISE)
        cv2.imshow("frame", frame)
        cv2.imshow("frame_rotate", frame_rotate)

        if cv2.waitKey(dt) != -1:
            break 
