/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *btnOpenVideo;
    QLabel *frameCountLabel;
    QPushButton *btnPreviousFrame;
    QPushButton *btnNextFrame;
    QPushButton *btnCloseVideo;
    QLineEdit *lineEditFilename;
    QMenuBar *menuBar;
    QMenu *menuClassifier_Image_Selector;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(510, 520);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 491, 311));
        btnOpenVideo = new QPushButton(centralWidget);
        btnOpenVideo->setObjectName(QStringLiteral("btnOpenVideo"));
        btnOpenVideo->setGeometry(QRect(10, 390, 115, 32));
        frameCountLabel = new QLabel(centralWidget);
        frameCountLabel->setObjectName(QStringLiteral("frameCountLabel"));
        frameCountLabel->setGeometry(QRect(190, 360, 191, 20));
        btnPreviousFrame = new QPushButton(centralWidget);
        btnPreviousFrame->setObjectName(QStringLiteral("btnPreviousFrame"));
        btnPreviousFrame->setGeometry(QRect(10, 320, 241, 32));
        btnNextFrame = new QPushButton(centralWidget);
        btnNextFrame->setObjectName(QStringLiteral("btnNextFrame"));
        btnNextFrame->setGeometry(QRect(260, 320, 241, 32));
        btnCloseVideo = new QPushButton(centralWidget);
        btnCloseVideo->setObjectName(QStringLiteral("btnCloseVideo"));
        btnCloseVideo->setGeometry(QRect(10, 430, 115, 32));
        lineEditFilename = new QLineEdit(centralWidget);
        lineEditFilename->setObjectName(QStringLiteral("lineEditFilename"));
        lineEditFilename->setGeometry(QRect(130, 390, 351, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 510, 22));
        menuClassifier_Image_Selector = new QMenu(menuBar);
        menuClassifier_Image_Selector->setObjectName(QStringLiteral("menuClassifier_Image_Selector"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuClassifier_Image_Selector->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Image Selector", 0));
        btnOpenVideo->setText(QApplication::translate("MainWindow", "Select Video", 0));
        frameCountLabel->setText(QApplication::translate("MainWindow", "Frame Number: 0", 0));
        btnPreviousFrame->setText(QApplication::translate("MainWindow", "Previous Frame", 0));
        btnNextFrame->setText(QApplication::translate("MainWindow", "Next Frame", 0));
        btnCloseVideo->setText(QApplication::translate("MainWindow", "Close Video", 0));
        menuClassifier_Image_Selector->setTitle(QApplication::translate("MainWindow", "Classifier Image Selector", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
