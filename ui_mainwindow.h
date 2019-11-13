/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QLCDNumber *hourLCD;
    QLCDNumber *minLCD;
    QLCDNumber *secLCD;
    QPushButton *imageDownloadButton;
    QLabel *imageLabel;
    QLineEdit *zipCodeEdit;
    QPushButton *weatherDownloadButton;
    QLabel *weatherLabel;
    QLabel *Greeting;
    QLabel *DigitalPhotoFrame;
    QLabel *weatherIcon;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1034, 628);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 174, 163);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        hourLCD = new QLCDNumber(centralWidget);
        hourLCD->setObjectName(QString::fromUtf8("hourLCD"));
        hourLCD->setGeometry(QRect(10, 60, 141, 121));
        hourLCD->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);\n"
"background-color: rgb(23, 63, 95);"));
        hourLCD->setDigitCount(2);
        hourLCD->setProperty("intValue", QVariant(22));
        minLCD = new QLCDNumber(centralWidget);
        minLCD->setObjectName(QString::fromUtf8("minLCD"));
        minLCD->setGeometry(QRect(160, 60, 141, 121));
        minLCD->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);\n"
"background-color: rgb(23, 63, 95);"));
        minLCD->setDigitCount(2);
        minLCD->setProperty("intValue", QVariant(22));
        secLCD = new QLCDNumber(centralWidget);
        secLCD->setObjectName(QString::fromUtf8("secLCD"));
        secLCD->setGeometry(QRect(310, 60, 141, 121));
        secLCD->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);\n"
"background-color: rgb(23, 63, 95);"));
        secLCD->setDigitCount(2);
        secLCD->setProperty("intValue", QVariant(22));
        imageDownloadButton = new QPushButton(centralWidget);
        imageDownloadButton->setObjectName(QString::fromUtf8("imageDownloadButton"));
        imageDownloadButton->setGeometry(QRect(10, 190, 141, 51));
        QFont font;
        font.setPointSize(10);
        imageDownloadButton->setFont(font);
        imageDownloadButton->setAutoFillBackground(false);
        imageDownloadButton->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 63, 95);\n"
"color: rgb(225, 225, 225);"));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(10, 250, 291, 191));
        imageLabel->setStyleSheet(QString::fromUtf8(""));
        zipCodeEdit = new QLineEdit(centralWidget);
        zipCodeEdit->setObjectName(QString::fromUtf8("zipCodeEdit"));
        zipCodeEdit->setGeometry(QRect(160, 190, 141, 51));
        zipCodeEdit->setFont(font);
        zipCodeEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 63, 95);\n"
"color: rgb(225, 225, 225);"));
        zipCodeEdit->setAlignment(Qt::AlignCenter);
        weatherDownloadButton = new QPushButton(centralWidget);
        weatherDownloadButton->setObjectName(QString::fromUtf8("weatherDownloadButton"));
        weatherDownloadButton->setGeometry(QRect(310, 190, 141, 51));
        weatherDownloadButton->setFont(font);
        weatherDownloadButton->setAutoFillBackground(false);
        weatherDownloadButton->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 63, 95);\n"
"color: rgb(225, 225, 225);"));
        weatherLabel = new QLabel(centralWidget);
        weatherLabel->setObjectName(QString::fromUtf8("weatherLabel"));
        weatherLabel->setGeometry(QRect(310, 250, 141, 191));
        QFont font1;
        font1.setPointSize(11);
        weatherLabel->setFont(font1);
        weatherLabel->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);\n"
"background-color: rgb(23, 63, 95);"));
        weatherLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        Greeting = new QLabel(centralWidget);
        Greeting->setObjectName(QString::fromUtf8("Greeting"));
        Greeting->setGeometry(QRect(10, 10, 441, 41));
        QFont font2;
        font2.setPointSize(12);
        Greeting->setFont(font2);
        Greeting->setStyleSheet(QString::fromUtf8("color: rgb(225, 225, 225);\n"
"background-color: rgb(23, 63, 95);"));
        Greeting->setAlignment(Qt::AlignCenter);
        DigitalPhotoFrame = new QLabel(centralWidget);
        DigitalPhotoFrame->setObjectName(QString::fromUtf8("DigitalPhotoFrame"));
        DigitalPhotoFrame->setGeometry(QRect(460, 10, 521, 431));
        DigitalPhotoFrame->setFont(font1);
        weatherIcon = new QLabel(centralWidget);
        weatherIcon->setObjectName(QString::fromUtf8("weatherIcon"));
        weatherIcon->setGeometry(QRect(310, 360, 141, 81));
        weatherIcon->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 63, 95);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1034, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        imageDownloadButton->setText(QApplication::translate("MainWindow", "Image Download", nullptr));
        imageLabel->setText(QString());
        zipCodeEdit->setText(QApplication::translate("MainWindow", "98119", nullptr));
        weatherDownloadButton->setText(QApplication::translate("MainWindow", "Weather Download", nullptr));
        weatherLabel->setText(QString());
        Greeting->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        DigitalPhotoFrame->setText(QString());
        weatherIcon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
