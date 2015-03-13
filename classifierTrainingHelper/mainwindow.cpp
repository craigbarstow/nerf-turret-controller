#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditFilename->setReadOnly(true);
    _videoMan = new VideoManager;
    _frameCount = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOpenVideo_clicked()
{
    //FIXME: only accept movie extensions
    _filePath = QFileDialog::getOpenFileName(this, "Select a movie file.", "/Users/Craig");
    if(this->_filePath.isEmpty()) {
        return;
    } else {
     ui->lineEditFilename->setText(_filePath);
     _videoMan->openConnection(_filePath);
    }
}

void MainWindow::on_btnNextFrame_clicked()
{
   _frameCount++;
   updateFrameCountLabel();
   displayFrame();
}

void MainWindow::on_btnPreviousFrame_clicked()
{
    if (_frameCount > 0) {
        _frameCount--;
        updateFrameCountLabel();
        displayFrame();
    }
}

void MainWindow::updateFrameCountLabel()
{
    ui->frameCountLabel->setText("Frame Number: "+QString::number(_frameCount));
}

void MainWindow::on_btnCloseVideo_clicked()
{
    ui->lineEditFilename->setText("");
    _videoMan->closeConnection();
}

void MainWindow::displayFrame()
{
    Mat frame_Mat = _videoMan->getFrame(_frameCount);
    //QImage frame = Mat2QImage(frame_Mat);
}










