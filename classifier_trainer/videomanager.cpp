#include "videomanager.h"
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <QDebug>
#include <QMessageBox>

VideoManager::VideoManager()
{

}

VideoManager::~VideoManager()
{

}

bool VideoManager::openConnection(QString filePath) {
    _video = new VideoCapture;
    if (_video->open(filePath.toStdString())) {
        QString s = "video successfully opened";
        qDebug() << s;
        return true;
    } else {
        QMessageBox* videoOpenErrorBox = new QMessageBox;
        videoOpenErrorBox->setWindowTitle("Video Load Error");
        videoOpenErrorBox->setText("The video failed to load. Please select a different video and try again.");
        videoOpenErrorBox->exec();
        return false;
    }
}

Mat VideoManager::getFrame(int frameNum) {
    //double count = _video.get(CV_CAP_PROP_FRAME_COUNT); //get the frame count
    _video->set(CV_CAP_PROP_POS_FRAMES,frameNum);
    Mat frame;
    _video->read(frame);

    //debug stuff
    qDebug() << "Frame #: "+ QString::number(frameNum);
    qDebug() << _video->read(frame);
    if (frame.empty()) {
        qDebug() << "Frame is empty!";
    } else {
        namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
        imshow( "Display window", frame );
        qDebug() << "it worked!";
    }
    return frame;
}


void VideoManager::closeConnection() {
    if (_video->isOpened()) {
        _video->release();
    }
}


