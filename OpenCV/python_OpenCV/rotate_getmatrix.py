import cv2

img = cv2.imread('img/pig.jpg')
resize_img = cv2.resize(img, dsize=(200,200), interpolation=cv2.INTER_LINEAR)
rows,cols = resize_img.shape[0:2]

# 1. 좌표를 바꿀 행렬값 초기화 작업
m45 = cv2.getRotationMatrix2D((cols/2,rows/2),45,0.5) # 회전축:중앙, 각도:45, 배율:0.5
m90 = cv2.getRotationMatrix2D((cols/2,rows/2),90,1.5) # 회전축:중앙, 각도:90, 배율:1.5

# 2. 변환 행렬[변화된 행렬] 적용
img45 = cv2.warpAffine(resize_img, m45,(cols, rows))
img90 = cv2.warpAffine(resize_img, m90,(cols, rows))

# 3. 결과 출력
cv2.imshow('origin',resize_img)
cv2.imshow("45", img45)
cv2.imshow("90", img90)
cv2.waitKey(0)
cv2.destroyAllWindows()