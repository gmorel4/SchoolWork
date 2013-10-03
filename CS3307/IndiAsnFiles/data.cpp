#include "data.h"
#include "controller.h"
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



Data::Data(QString location, QString units, Controller *control)
{

    _location = location;
    _units = units;
    _controller = control;

    //creating a QUrl object from the string, specifies the weather server


    //creating a new QNetworkAccessManager to manage network requests and replies
    _manager = new QNetworkAccessManager (this);
    connect (_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

//changes the location for the weather to be retrieved
void Data::changeLocation(QString location)
{
    _location = location;
}

//change the units to measure the temperature
void Data::changeUnits(QString units)
{
    _units = units;
}

//return the location of the weather information
QString& Data::location()
{
    return _location;
}

//return the units being used
QString& Data::units()
{
    return _units;
}

//envoked by the controller when the user wants to update the weather
void Data::sendQuery()
{

    QUrl url = QUrl ("http://openweathermap.org/data/2.5/weather");

    //add items to the url query for the location and the desired units
    QUrlQuery query (url);
    query.addQueryItem("APPID","291cc02999b830ce1d7bf176d3d49172");
    query.addQueryItem("q", _location);
    query.addQueryItem("units", _units);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    //set the query to the url
    url.setQuery(query);

    //set the url to the request
    request.setUrl(url);

    std::cout<<url.toString().toStdString()<<std::endl;

    //tell the network manager to post the url request
    _manager->post(request, url.toEncoded());
}

//called when a network reply has been received
void Data::replyFinished(QNetworkReply *reply)
{
   //if there was an error received, tell the controller to display that there was an error
    if (reply->error() != QNetworkReply::NoError){
        _controller->networkError();
        return;
    }

    //get the Json object from the reply
    QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();

    //parse out various objects from the Json
    QJsonObject main = obj["main"].toObject();
    QJsonObject sys = obj["sys"].toObject();
    QJsonObject wind = obj["wind"].toObject();
    QJsonObject weather = sys["weather"].toObject();

    //parse out the temperature from the 'main' Json object
    double temp;
    double min;
    double max;
    double humidity;
    double pressure;
    temp = main["temp"].toDouble();
    min = main["temp_min"].toDouble();
    max = main["temp_max"].toDouble();
    humidity = main["humidity"].toDouble();
    pressure = main["pressure"].toDouble();

    //parse out the current conditions from the 'weather' Json object
    QString conditions;
    conditions = obj["description"].toString();

    uint sunrise = (uint) sys["sunrise"].toDouble();
    uint sunset = (uint) sys["sunset"].toDouble();

    double windspeed = wind["speed"].toDouble();
    double winddirection = wind["deg"].toDouble();

    //tell the controller to update the UI with the new weather information
    _controller->updateMain(_location, temp, _units);
    _controller->updateConditions(conditions);
    _controller->updateDescription (min,max,humidity,pressure,sunrise,sunset,windspeed,winddirection);
}

Data::~Data()
{
    delete _manager;
}

