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
    _url = QUrl ("http://openweathermap.org/data/2.5/weather");

    //creating a QUrlQuery
    _query = QUrlQuery (_url);

    //adding items to the QUrlQuery with our CS3307 APPID
    _query.addQueryItem("APPID","291cc02999b830ce1d7bf176d3d49172");

    //creating a new QNetworkAccessManager to manage network requests and replies
    _manager = new QNetworkAccessManager(this);
}

//returns the temperture
double& Data::temperature()
{
    return _temp;
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

//return the current weather conditions
QString& Data::currentConditions()
{
    return _conditions;
}

//return the units being used
QString& Data::units()
{
    return _units;
}

//envoked by the controller when the user wants to update the weather
void Data::sendQuery()
{
    //create a network request from the url
    QNetworkRequest request(_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    //add items to the url query for the location and the desired units
    _query.addQueryItem("q", _location);
    _query.addQueryItem("units", _units);

    //set the query to the url
    _url.setQuery(_query);

    //set the url to the request
    request.setUrl(_url);

    //tell the network manager to post the url request
    _manager->post(request, _url.toEncoded());
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
    QJsonObject weather = obj["weather"].toObject();

    //parse out the temperature from the 'main' Json object
    _temp = main["temp"].toDouble();

    //parse out the current conditions from the 'weather' Json object
    _conditions = weather["description"].toString();

    //tell the controller to update the UI with the new weather information
    _controller->updateDisplay(_temp);
}

Data::~Data()
{
    delete _manager;
    delete _controller;
}


