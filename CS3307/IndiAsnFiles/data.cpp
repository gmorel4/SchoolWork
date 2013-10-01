#include "data.h"
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

Data::Data(QString location, QString units)
{
    _location = location;
    _units = units;
    _networkError = false;
    _url = QUrl ("http://openweathermap.org/data/2.5/weather");
    _query = QUrlQuery (_url);
    _query.addQueryItem("APPID","291cc02999b830ce1d7bf176d3d49172");
    _manager = new QNetworkAccessManager(this);
}

double& Data::temperature()
{
    return _temp;
}

void Data::changeLocation(QString location)
{
    _location = location;
}

void Data::changeUnits(QString units)
{
    _units = units;
}

QString& Data::location()
{
    return _location;
}

QString& Data::currentConditions()
{
    return _conditions;
}

QString& Data::units()
{
    return _units;
}

bool Data::netError()
{
    return _networkError;
}

void Data::sendQuery()
{
    QNetworkRequest request(_url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    _query.addQueryItem("q", _location);
    _query.addQueryItem("units", _units);
    _url.setQuery(_query);
    _manager->post(request, _url.toEncoded());
}

void Data::replyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError){
        _networkError = true;
        return;
    }

    QJsonObject obj = QJsonDocument::fromJson(reply->readAll()).object();

    QJsonObject main = obj["main"].toObject();
    QJsonObject weather = obj["weather"].toObject();

    _temp = main["temp"].toDouble();
    _conditions = weather["description"].toString();
}

Data::~Data()
{
    delete _manager;
}


