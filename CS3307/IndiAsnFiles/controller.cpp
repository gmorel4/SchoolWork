#include "controller.h"
#include "data.h"

#include <iostream>

#include <QString>

Controller::Controller()
{
    QString location = "London,can";
    QString units = "metric";
    _data = new Data (location, units);

}

void Controller::changeUnits(QString units)
{
    _data->changeUnits(units);
}

void Controller::changeCity(QString location)
{
    _data->changeLocation(location);
}

double& Controller::temperature ()
{
    return (_data->temperature());
}

QString& Controller::city()
{
    return (_data->location());
}

QString& Controller::units()
{
    return (_data->units());
}

QString& Controller::currentConditions()
{
    return (_data->currentConditions());
}

void Controller::getWeather()
{
    _data->sendQuery();
}

Controller::~Controller()
{
    delete _data;
}
