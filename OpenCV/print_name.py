import cv2
import numpy as np

img = cv2.imread('img/blank_500.jpg')

#cv2.rectangle(img, (300, 300), (100, 200), (255,0,0), 5 )
#cv2.putText(img, "enrhd24", (140, 260), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0,0)) 

#cv2.imshow('rectangle', img)
#cv2.waitKey(0)
#cv2.destroyAllWindows()


#cv2.imshow('draw text', img)

cv2.imshow("img", img)
cv2.waitKey(0)
