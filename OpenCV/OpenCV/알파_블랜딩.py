import cv2

foreground = cv2.imread("puppets.png")
background = cv2.imread("ocean.png")
alpha = cv2.imread("puppets_alpha.png")

foreground = foreground.astype(float)
background = background.astype(float)

alpha = alpha.astype(float)/255

foreground = cv2.multiply(alpha, foreground)
background = cv2.multiply(1.0 - alpha, background)

outImage = cv2.add(foreground, background)

cv2.imshow("outImg", outImage/255)

cv2.waitKey(0)