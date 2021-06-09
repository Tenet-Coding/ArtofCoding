import cv2 
import time 
import numpy as np 
import handModule as hm 

################################################
wCam , hCam = 640, 480 
#################################################

cap = cv2.VideoCapture(0)
cap.set(3,wCam)
cap.set(4,hCam)
pTime = 0 


dectector  = hm.handDetector(detectionCon = 0.7)


while True:
    success, img = cap.read()
    img = dectector.findHands(img)



    cTime = time.time()
    fps = 1/(cTime- pTime)
    pTime = cTime 
    #putText(image, fps int , where to place, font , scale(how big you want), color, thickness)
    cv2.putText(img, f'FPS: {int(fps)}', (40,50) , cv2.FONT_HERSHEY_COMPLEX_SMALL, 1 , (255, 0 , 0 ), 2)  
      
    cv2.imshow("Img",img)
    cv2.waitKey(1)