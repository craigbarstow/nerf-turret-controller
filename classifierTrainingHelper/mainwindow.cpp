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

void MainWindow::on_btnOpenVideo_clicked()
{
    this->_fileName = QFileDialog::getOpenFileName(this);
    if(this->_fileName.isEmpty()) {
        return;
    }
}

void MainWindow::processVideo()
{
    int frameCount = 0;
    _videoMan->openConnection("./test.avi");

    while (_processing) {

        qDebug() << "frame count = "+ QString::number(frameCount);
        frameCount++;
    }
    _videoMan->closeConnection();
}



