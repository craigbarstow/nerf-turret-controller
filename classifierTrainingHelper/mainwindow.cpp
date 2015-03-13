#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _videoMan = new VideoManager;
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPlayPause_clicked()
{
    if (!_processing) {
        ui->btnPlayPause->setText("Pause");
        _processing = true;
        processVideo();
    } else {
        ui->btnPlayPause->setText("Play");
        _processing = false;
    }
}

void MainWindow::processVideo()
{
    int frameCount = 0;

    while (_processing) {
        qDebug() << "frame count = "+ QString::number(frameCount);
        frameCount++;
    }

}



