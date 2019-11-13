#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer (new QTimer),
    timer2 (new QTimer),
    httpManager(new HTTPManager)
{
    ui->setupUi(this);

    connect(timer, SIGNAL(timeout()),
            this, SLOT(setCurrentTime()));

    setCurrentTime();
    timer->start(1000);

    connect(timer2, SIGNAL(timeout()),
            this, SLOT(changeImage()));

    loadImages();
    timer2->start(10000);

    connect(httpManager, SIGNAL(ImageReady(QPixmap *)),
            this, SLOT(processImage(QPixmap *)));

    connect(httpManager, SIGNAL(WeatherJsonReady(QJsonObject *)),
            this, SLOT(processWeatherJson(QJsonObject *)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCurrentTime()
{
    QTime time = QTime::currentTime();
    QString hour = time.toString("hh");
    QString minute = time.toString("mm");
    QString second = time.toString("ss");

    ui->hourLCD->display(hour);
    ui->minLCD->display(minute);
    ui->secLCD->display(second);

    int intHour = hour.toInt();
    if(intHour < 12){
        ui->Greeting->setText("Good Morning!");
    }
    if(intHour >= 12){
        if(intHour < 17)
        ui->Greeting->setText("Good Afternoon!");
        if(intHour > 17)
        ui->Greeting->setText("Good Evening!");
        if(intHour > 20)
        ui->Greeting->setText("Good Night!");
    }
}

void MainWindow::processImage(QPixmap *image)
{
    ui->imageLabel->setPixmap(*image);
}

void MainWindow::processWeatherJson(QJsonObject *json)
{
    qDebug() << json->value("weather");
    QString weather = json->value("weather").toArray()[0].toObject()["main"].toString();
    QString weatherDesc= json->value("weather").toArray()[0].toObject()["description"].toString();

    double temp = json->value("main").toObject()["temp"].toDouble();
    double temp_min = json->value("main").toObject()["temp_min"].toDouble();
    double temp_max = json->value("main").toObject()["temp_max"].toDouble();
    double humidity = json->value("main").toObject()["humidity"].toDouble();

    qDebug() << weather;
    qDebug() << weatherDesc;
    qDebug() << temp;
    qDebug() << temp_min;
    qDebug() << temp_max;
    qDebug() << humidity;

    ui->weatherLabel->setText("Weather: " +weather +"\nTemp: " + QString::number(temp)
                              + "\nMin Temp: " + QString::number(temp_min) + "\nMax Temp: " + QString::number(temp_max)
                              + "\nHumidity: " + QString::number(humidity));

    if(weather == "Clear"){
        ui->weatherIcon->setPixmap(clearImage);
    }
    if(weather == "Clouds"){
        qDebug() << "here " + weather;
        ui->weatherIcon->setPixmap(cloudsImage);
    }
    if(weather == "Scatteredclouds"){
        ui->weatherIcon->setPixmap(cloudsImage);
    }
    if(weather == "Haze"){
        ui->weatherIcon->setPixmap(hazeImage);
    }
    if(weather == "Rain"){
        ui->weatherIcon->setPixmap(rainImage);
    }
    if(weather == "Drizzle"){
        ui->weatherIcon->setPixmap(rainImage);
    }
    if(weather == "Snow"){
        ui->weatherIcon->setPixmap(snowImage);
    }
    if(weather == "thunderstorm"){
        ui->weatherIcon->setPixmap(thunderstormImage);
    }

}

void MainWindow::loadImages()
{
    QString beachFileName = "Beach.jpg";
    QString gameFileName = "Game.jpg";
    QString nightSkyFileName = "NightSky.jpg";
    QString parkFileName = "Park.jpg";
    QString waterMountFileName = "WaterMount.jpg";

    if  (image1.load(beachFileName)){
        qDebug() << "image1 load successful";
        image1 = image1.scaled(ui->DigitalPhotoFrame->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }
    if  (image2.load(gameFileName)){
        qDebug() << "image1 load successful";
        image2 = image2.scaled(ui->DigitalPhotoFrame->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }
    if  (image3.load(nightSkyFileName)){
        qDebug() << "image1 load successful";
        image3 = image3.scaled(ui->DigitalPhotoFrame->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }
    if  (image4.load(parkFileName)){
        qDebug() << "image1 load successful";
        image4 = image4.scaled(ui->DigitalPhotoFrame->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }
    if  (image5.load(waterMountFileName)){
        qDebug() << "image1 load successful";
        image5 = image5.scaled(ui->DigitalPhotoFrame->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }

    //load weather icons
    QString clearFileName = "clear.png";
    QString cloudsFileName = "clouds.png";
    QString hazeFileName = "haze.png";
    QString rainFileName = "rain.png";
    QString snowFileName = "snow.png";
    QString drizzleFileName = "rain.png";
    QString thunderstormFileName = "thunderstorm.png";
    if  (clearImage.load(clearFileName)){
        clearImage = clearImage.scaled(ui->weatherIcon->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }
    if  (cloudsImage.load(cloudsFileName)){
        cloudsImage = cloudsImage.scaled(ui->weatherIcon->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }
    if  (hazeImage.load(hazeFileName)){
        hazeImage = hazeImage.scaled(ui->weatherIcon->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }
    if  (rainImage.load(rainFileName)){
        rainImage = rainImage.scaled(ui->weatherIcon->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }
    if  (snowImage.load(clearFileName)){
        snowImage = snowImage.scaled(ui->weatherIcon->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }
    if  (thunderstormImage.load(clearFileName)){
        thunderstormImage = thunderstormImage.scaled(ui->weatherIcon->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    }

}

void MainWindow::changeImage()
{
    if(photo == 1){
         ui->DigitalPhotoFrame->setPixmap(image1);
    }
    if(photo == 2){
         ui->DigitalPhotoFrame->setPixmap(image2);
    }
    if(photo == 3){
         ui->DigitalPhotoFrame->setPixmap(image3);
    }
    if(photo == 4){
         ui->DigitalPhotoFrame->setPixmap(image4);
    }
    if(photo == 5){
         ui->DigitalPhotoFrame->setPixmap(image5);
         photo =0;
    }
    photo++;
}

void MainWindow::on_imageDownloadButton_clicked()
{
    QString zip = ui->zipCodeEdit->text();
    qDebug() << "zip";
    httpManager->sendImageRequest(zip);

}

void MainWindow::on_weatherDownloadButton_clicked()
{
    QString zip = ui->zipCodeEdit->text();
    qDebug() << "zip";
    httpManager->sendWeatherRequest(zip);


}
