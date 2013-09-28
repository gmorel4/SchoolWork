#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QUrl>
#include <QUrlQuery>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QDebug>

void MainWindow::replyFinished(QNetworkReply * reply){
    if ( reply->error() != QNetworkReply::NoError ){
        // A communication error has occurred
        ui->tempLabel->setText("Network Error");
        return;
    }

    //We read the JSON response into a QJsonObject
    QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();

    //We find the "main" object from the full response (see the format in the assingment description)
    QJsonObject main = obj["main"].toObject();
    //and get out the temp element
    double temp = main["temp"].toDouble();

    //Generate a display string and display it to the UI
    QString display(QString::number(temp, 'f', 1) + " degrees");
    ui->tempLabel->setText(display);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //the network manager will post and recieve our HTTP requests
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    //connect the "finished" signal from the manager to our response handling method
    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

    //the host of the webservice
    QUrl url("http://openweathermap.org/data/2.5/weather");

    //set up the request to post
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    //the additional query data to enter
    QUrlQuery query(url);
    query.addQueryItem("APPID","291cc02999b830ce1d7bf176d3d49172"); //our CS3307 APPID
    query.addQueryItem("q", "London,can");
    query.addQueryItem("units", "metric");
    url.setQuery(query);

    //update the request with the new query information.
    request.setUrl(url);

    // DEBUG TIP:
    //   The following line will allow you print the full HTTP request that will be made
    //   You can enter it directly into a browser, and the JSON object returned will be shown
    //   This is why iostream is included in this file
    //std::cout<< url.toString().toStdString()<<std::endl;

    //post the request
    manager->post(request, url.toEncoded());
}

MainWindow::~MainWindow()
{
    delete ui;
}
