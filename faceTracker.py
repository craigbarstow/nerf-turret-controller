#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import cv2, sys

debug = True
pos_relative_origin_x = 0
pos_relative_origin_y = 0

faceCascade = cv2.CascadeClassifier('./haarcascade_frontalface_alt.xml')
video_capture = cv2.VideoCapture(0)

while True:
    ret, frame = video_capture.read()
    #get image size in px
    img_height, img_width, img_depth = frame.shape

    grayscale = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        grayscale,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30),
        flags=cv2.cv.CV_HAAR_FIND_BIGGEST_OBJECT
    )

    #get dimensions of largest face
    for (x, y, w, h) in faces:
        #FIXME, only assign these once
        center_coord_x = int(img_width * .5)
        center_coord_y = int(img_height * .5)

        face_x_center = int(x+w*.5)
        face_y_center = int(y+h*.5)

        #output coordinates of face center, using image center as origin
        sys.stdout.write(str(face_x_center - center_coord_x) + "|" + str(center_coord_y - face_y_center) + "\r\n")

        if debug:
            #place circle over center of face
            cv2.circle(frame, (face_x_center, face_y_center), 10, (0, 0, 255), 17)

    # Debug stuff
    if debug:
        cv2.imshow("Face Tracker", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

video_capture.release()

if debug:
    cv2.destroyAllWindows()
