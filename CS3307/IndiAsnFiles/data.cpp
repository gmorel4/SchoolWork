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

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

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
    manager->post(request, url.toEncoded());
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


