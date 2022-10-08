import cv2
import numpy as np
url =input("Your IP Address/video:")
cp = cv2.VideoCapture(url)
while(True):
    camera, frame = cp.read()
    if frame is not None:
        cv2.imshow("Frame", frame)
    q = cv2.waitKey()
    if q==ord("q"):
        break
cv2.destroyAllWindows()
