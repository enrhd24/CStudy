import cv2

img = cv2.imread("img/pig.jpg")
resize_img = cv2.resize(img, dsize=(200,200), interpolation=cv2.INTER_LINEAR)

r90 = cv2.rotate(resize_img, cv2.ROTATE_90_CLOCKWISE)
r90ccw = cv2.rotate(resize_img, cv2.ROTATE_90_COUNTERCLOCKWISE)

cv2.imshow('orig', resize_img)
cv2.imshow('r90', r90)
cv2.imshow('r90ccw', r90ccw)

cv2.waitKey(0)
cv2.destroyAllWundows()





