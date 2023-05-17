import cv2
import numpy as np

img = cv2.imread('../img/pig.jpg', cv2.IMREAD_COLOR)
resize_img = cv2.resize(img, dsize=(200,200), interpolation=cv2.INTER_LINEAR)


cv2.imshow("resize_img", resize_img)
cv2.waitKey(0)
cv2.destroyAllWindows()