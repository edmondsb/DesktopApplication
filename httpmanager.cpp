#include "httpmanager.h"
#include <QJsonDocument>
#include <QJsonObject>

HTTPManager::HTTPManager(QObject *parent) :
    QObject(parent),
    imageDownloadManager(new QNetworkAccessManager),
    weatherAPIManager(new QNetworkAccessManager)
{
    connect(imageDownloadManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(ImageDownloadedHandler(QNetworkReply *)));

    connect(weatherAPIManager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(WeatherDownloaderHandler(QNetworkReply*)));
}

HTTPManager::~HTTPManager()
{
    delete imageDownloadManager;
    delete weatherAPIManager;
}

void HTTPManager::sendImageRequest(QString zip)
{
    QNetworkRequest request;

    QString address = "https://dev.virtualearth.net/REST/V1/Imagery/Map/AerialWithLabels/"
            + zip
            + "/3?mapSize=400,200&mapLayer=TrafficFlow&format=png&key=AjzUpKn0pXProHbf37wyToUmQrFh8dwyz-37bMXeT_ilYOQwVaLBEXOiEI554vGj";
    request.setUrl(QUrl(address));
    imageDownloadManager->get(request);
    qDebug() << "image request sent to address" << request.url();
}

void HTTPManager::sendWeatherRequest(QString zip)
{
    QNetworkRequest request;

    QString address = "https://api.openweathermap.org/data/2.5/weather?zip="
            + zip
            +",us&units=imperial&appid=e7dc7ca4fe3c5adfbe0423d07c3bffb4";
    request.setUrl(QUrl(address));
    weatherAPIManager->get(request);
    qDebug() << "weather request sent to address" << request.url();
}

void HTTPManager::ImageDownloadedHandler(QNetworkReply *reply)
{
    qDebug() << "Image reply has arrived";
    if(reply->error()){
        qDebug() << reply->errorString();
        return;
    }
    qDebug() << "download successful";
    QPixmap *image = new QPixmap();
    image->loadFromData(reply->readAll());
    reply->deleteLater();

    emit ImageReady(image);
}

void HTTPManager::WeatherDownloaderHandler(QNetworkReply *reply)
{
    qDebug() << "weather reply has arrived";
    if(reply->error()){
        qDebug() << reply->errorString();
        return;
    }

    qDebug() << "download successful";

    QString answer = reply->readAll();
    reply->deleteLater();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject *jsonObj = new QJsonObject(jsonResponse.object());

    emit WeatherJsonReady(jsonObj);

}





