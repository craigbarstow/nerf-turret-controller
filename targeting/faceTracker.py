import io
import cv2, sys
import serial
import picamera
import picamera.array
import numpy as np

DEBUG = 1
TARGETING_SENSITIVITY = 25
RETURN_ORIGIN_FRAME_COUNT = 20
HOLD_FIRE_CHARACTER = "="
FIRE_CHARACTER = "!"

pos_relative_origin_x = 0
pos_relative_origin_y = 0
no_target_frame_count = 0

#saving the picture to an in-program stream rather than a file
stream = io.BytesIO()

#to speed things up, lower the resolution of the camera
CAMERA_WIDTH = 320
CAMERA_HEIGHT = 240

#faceCascade = cv2.CascadeClassifier('./haarcascade_frontalface_alt.xml')
faceCascade = cv2.CascadeClassifier('lbpcascade_frontalface.xml')
#video_capture = cv2.VideoCapture(0)

if not DEBUG:
    ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=0)

while True:
    with picamera.PiCamera() as camera:
        #camera.resolution = (CAMERA_WIDTH, CAMERA_HEIGHT)
        #camera.capture(stream, format='jpeg')
	with picamera.array.PiRGBArray(camera) as stream:
	    camera.capture(stream, format='bgr')
	    frame = stream.array
    #data = np.fromstring(stream.getvalue(), dtype=np.uint8)
    #frame = cv2.imdecode(data, 1)
    #ret, frame = video_capture.read()
    #get image size in px
    #img_height, img_width, img_depth = frame.shape

    grayscale_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        grayscale_frame,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30),
        flags=cv2.cv.CV_HAAR_FIND_BIGGEST_OBJECT
    )
    
    #faces = faceCascade.detectMultiScale(grayscale_frame, 1.3, 5)
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

            if DEBUG:
                sys.stdout.write(start_char + str(face_x_center - center_coord_x) + "|" + str(center_coord_y - face_y_center) + "\n")
                #cv2.circle(frame, (face_x_center, face_y_center), 10, (0, 0, 255), 17)
            else:
                ser.write(start_char + str(face_x_center - center_coord_x) + "|" + str(center_coord_y - face_y_center) + "\n")
    else:
        no_target_frame_count += 1
        if no_target_frame_count > RETURN_ORIGIN_FRAME_COUNT:
            #issue command for turret to return to default position
            if DEBUG:
                sys.stdout.write(HOLD_FIRE_CHARACTER + "r\n")
            else:
                ser.write(HOLD_FIRE_CHARACTER + "r\n")
            no_target_frame_count = 0
        else:
            #dont move turret
            if DEBUG:
                sys.stdout.write(HOLD_FIRE_CHARACTER + "0|0\n")
            else:
                ser.write(HOLD_FIRE_CHARACTER + "0|0\n")

    # Debug stuff
    if DEBUG:
        #cv2.imshow("Face Tracker", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

video_capture.release()
if not DEBUG:
    ser.close()

if DEBUG:
    cv2.destroyAllWindows()
