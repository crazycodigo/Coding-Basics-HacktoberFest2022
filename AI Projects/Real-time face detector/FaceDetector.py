import cv2
from random import randrange

#loading some pretrained data into our badass app!
trained_face_data = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

#Yeah thats how you import an image, think of image as a 2D array
#img = cv2.imread('abm3.jpeg')


"""
#converting image to grayscale
grayscaled_img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

#Detect the face by presenting it to your algorithm
face_coordinates = trained_face_data.detectMultiScale(grayscaled_img)
#detectMultiScale is the function that detects the image reguardless of if its scale ie size, this returns the coordinates of the rectangle that shows us the postion of the face

print(face_coordinates)

#draw rectangle around the face
for (x,y,w,h) in face_coordinates:
    cv2.rectangle(img,(x,y),(x+w,y+h),(randrange(256),randrange(256),randrange(256)),5)

#to show the image ("the name of the window showing it",file)
cv2.imshow('Face Detector',img)

#write this code otherwise the window will just open and close in a brink of a second
cv2.waitKey()
"""

#Now its time for face detection in videos

#Capture video in real time , 0 here tells you its the default webcam
webcam = cv2.VideoCapture(0)

#we want it to run until we close the webcam

while True:
    #Reading the current frame
    successful_frame_read, frame = webcam.read() #first variable is a boolean telling if capture was success or not and the second one actually has the image

    #convert to grayscale
    gframe = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    #Detect the face in frame
    detect_face = trained_face_data.detectMultiScale(gframe)

    for (x,y,w,h) in detect_face:
        cv2.rectangle(frame,(x,y),(w+x,h+y),(randrange(256),randrange(256),randrange(256)),5)
        cv2.imshow("Real Time Face", frame)
    
    #refreshing the frame every 1ms
    key= cv2.waitKey(1)
    #the app will stop when q or Q is pressed
    if key==81 or key ==113:
        break

webcam.release()
print("Code Completed KING!👑")