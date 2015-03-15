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
    _video = new VideoCapture;//(0); //this works
    _video->open(filePath.toStdString());
}


Mat VideoManager::getFrame(int frameNum) {
    //FIXME make sure frame num is in the right range
    //double count = _video.get(CV_CAP_PROP_FRAME_COUNT); //get the frame count
    _video->set(CV_CAP_PROP_POS_FRAMES,frameNum);
    Mat frame;
    _video->read(frame);
    return frame;
}


void VideoManager::closeConnection() {
    if (_video->isOpened()) {
        _video->release();
    }
}


