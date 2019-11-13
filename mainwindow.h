#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

#include "httpmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
        void setCurrentTime();
        void processImage(QPixmap *);
        void processWeatherJson(QJsonObject *json);

        void loadImages();
        void changeImage();

        void on_imageDownloadButton_clicked();

        void on_weatherDownloadButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer2;
    HTTPManager *httpManager;

    QPixmap image1;
    QPixmap image2;
    QPixmap image3;
    QPixmap image4;
    QPixmap image5;

    QPixmap clearImage;
    QPixmap cloudsImage;
    QPixmap rainImage;
    QPixmap thunderstormImage;
    QPixmap hazeImage;
    QPixmap snowImage;



    int photo =1;


};

#endif // MAINWINDOW_H
