#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "opencv2/highgui/highgui.hpp"
#include "videomanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btnOpenVideo_clicked();

private:
    Ui::MainWindow *ui;
    VideoManager *_videoMan;
    bool _processing;
    QString _fileName;

    void processVideo();
};

#endif // MAINWINDOW_H
