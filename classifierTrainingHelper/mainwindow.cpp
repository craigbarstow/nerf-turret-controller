#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    if (!_recording) {
        ui->btnPlayPause->setText("Pause");
        processing = true;
        processVideo();
    } else {
        ui->btnPlayPause->setText("Play");
        processing = false;
    }
}





