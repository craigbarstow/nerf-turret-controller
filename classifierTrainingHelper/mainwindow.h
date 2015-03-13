#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
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
    void on_btnPlayPause_clicked();

private:
    Ui::MainWindow *ui;
    VideoManager *videoMan;
    bool processing;
    void processVideo();
};

#endif // MAINWINDOW_H
