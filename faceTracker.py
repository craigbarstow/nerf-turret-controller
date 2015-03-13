import cv2

debug = True
pos_relative_origin_x = 0
pos_relative_origin_y = 0

faceCascade = cv2.CascadeClassifier('./haarcascade_frontalface_alt.xml')
video_capture = cv2.VideoCapture(0)

while True:
    ret, frame = video_capture.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30),
        flags=cv2.cv.CV_HAAR_FIND_BIGGEST_OBJECT
    )

    #place circle over center of face
    print faces
    for (x, y, w, h) in faces:
        cv2.circle(frame, (int(x+w*.5), int(y+h*.5)), 10, (0, 0, 255), 17)

    # Debug stuff
    if debug:
        cv2.imshow('Video', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

video_capture.release()

if debug:
    cv2.destroyAllWindows()
