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
    bool openConnection(QString filePath);
    void closeConnection();
    Mat getFrame(int frameNum);

private:
    VideoCapture *_video;
};

#endif // VIDEOMANAGER_H
