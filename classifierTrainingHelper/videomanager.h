#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H

#include <QString>
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/opencv.hpp> //is this necessary?
//#include <opencv2/core/core.hpp>

using namespace cv;

class VideoManager
{
public:
    VideoManager();
    ~VideoManager();
    void openConnection(QString filePath);
    void closeConnection();

private:
    VideoCapture *_video;
};

#endif // VIDEOMANAGER_H
