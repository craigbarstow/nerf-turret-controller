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
LIBS += -L/usr/local/lib \
     -lopencv_core \
     -lopencv_imgproc \
     -lopencv_features2d\
     -lopencv_highgui
