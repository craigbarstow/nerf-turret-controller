import cv2, sys

DEBUG = False
TARGETING_SENSITIVITY = 15
RETURN_ORIGIN_FRAME_COUNT = 20
HOLD_FIRE_CHARACTER = "="
FIRE_CHARACTER = "!"

pos_relative_origin_x = 0
pos_relative_origin_y = 0
no_target_frame_count = 0

faceCascade = cv2.CascadeClassifier('./haarcascade_frontalface_alt.xml')
video_capture = cv2.VideoCapture(0)

while True:
    ret, frame = video_capture.read()
    #get image size in px
    img_height, img_width, img_depth = frame.shape

    grayscale_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        grayscale_frame,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30),
        flags=cv2.cv.CV_HAAR_FIND_BIGGEST_OBJECT
    )

    #get dimensions of largest face
    if len(faces) > 0:
        for (x, y, w, h) in faces:
            #FIXME, only assign these once
            center_coord_x = int(img_width * .5)
            center_coord_y = int(img_height * .5)

            face_x_center = int(x+w*.5)
            face_y_center = int(y+h*.5)

            #output coordinates of face center, using image center as origin
            dist_x = face_x_center - center_coord_x
            dist_y = center_coord_y - face_y_center

            #FIXME: experiment with these values
            #Set hold fire character as default
            start_char = HOLD_FIRE_CHARACTER
            if abs(dist_x) < TARGETING_SENSITIVITY and abs(dist_y) < TARGETING_SENSITIVITY:
                #Set endline character to fire character
                start_char = FIRE_CHARACTER

            sys.stdout.write(start_char + str(face_x_center - center_coord_x) + "|" + str(center_coord_y - face_y_center) + "\n")

            if DEBUG:
                #place circle over center of face
                cv2.circle(frame, (face_x_center, face_y_center), 10, (0, 0, 255), 17)
    else:
        no_target_frame_count += 1
        if no_target_frame_count > RETURN_ORIGIN_FRAME_COUNT:
            #issue command for turret to return to default position
            sys.stdout.write(HOLD_FIRE_CHARACTER + "r\n")
            no_target_frame_count = 0
        else:
            #dont move turret
            sys.stdout.write(HOLD_FIRE_CHARACTER + "0|0\n")


    # Debug stuff
    if DEBUG:
        cv2.imshow("Face Tracker", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

video_capture.release()

if DEBUG:
    cv2.destroyAllWindows()
