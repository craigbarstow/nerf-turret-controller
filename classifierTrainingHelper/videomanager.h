#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H

#include <qstring.h>

class VideoManager
{
public:
    VideoManager();
    ~VideoManager();
    void openConnection();
    void openConnection(QString filePath);
};

#endif // VIDEOMANAGER_H
