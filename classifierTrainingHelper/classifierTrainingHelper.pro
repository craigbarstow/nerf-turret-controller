#-------------------------------------------------
#
# Project created by QtCreator 2015-03-13T10:59:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = classifierTrainingHelper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    videomanager.cpp

HEADERS  += mainwindow.h \
    videomanager.h

FORMS    += mainwindow.ui


INCLUDEPATH += /usr/local/include\

LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_videostab
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

