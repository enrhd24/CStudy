import cv2
import numpy as np

img = cv2.imread('img/pig.jpg', cv2.IMREAD_GRAYSCALE)
resize_img = cv2.resize(img, dsize=(300,300), interpolation=cv2.INTER_LINEAR)

ret, th1 = cv2.threshold(img,0,255,cv2.THRESH_OTSU)
resize_th1 = cv2.resize(th1, dsize=(300,300), interpolation=cv2.INTER_LINEAR)

add = resize_img + resize_th1
api_add = cv2.subtract(resize_img,resize_th1)

cv2.imshow("resize_img", resize_img)
cv2.imshow("th1",resize_th1)

cv2.imshow("add",add)
cv2.imshow("api_add",api_add)

cv2.waitKey(0)
cv2.destroyAllWindows()