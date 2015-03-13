#include "videomanager.h"
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui.hpp>

VideoManager::VideoManager()
{

}

VideoManager::~VideoManager()
{

}

void VideoManager::openConnection(QString filePath) {
    //_video = new VideoCapture(filePath.toStdString());
    //VideoCapture myCapture(0);
    _video = new VideoCapture(0);
}

void VideoManager::closeConnection() {
    if (_video->isOpened()) {
        _video->release();
    }
}
