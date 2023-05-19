import cv2
import numpy as np

img = cv2.imread('img/pig.jpg')
resize_img = cv2.resize(img, dsize=(200,200), interpolation=cv2.INTER_LINEAR)
rows,cols = resize_img.shape[0:2]

# 1. 라디안 각도 계산
d45 = 45.0 * np.pi / 180    # 45도
d90 = 90.0 * np.pi / 180    # 90도

# 2. 좌표를 바꿀 행렬값 초기화 작업
m45 = np.float32( [[ np.cos(d45), -1* np.sin(d45), rows//2],
                    [np.sin(d45), np.cos(d45), -1*cols//4]])
m90 = np.float32( [[ np.cos(d90), -1* np.sin(d90), rows],
                    [np.sin(d90), np.cos(d90), 0]])

# 3. 변환 행렬[변화된 행렬] 적용
r45 = cv2.warpAffine(resize_img,m45,(cols,rows))
r90 = cv2.warpAffine(resize_img,m90,(rows,cols))

# 4. 결과 출력
cv2.imshow("origin", resize_img)
cv2.imshow("45", r45)
cv2.imshow("90", r90)
cv2.waitKey(0)
cv2.destroyAllWindows()