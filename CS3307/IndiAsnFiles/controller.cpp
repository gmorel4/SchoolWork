#include "controller.h"
#include "data.h"
#include "interface.h"
#include <iostream>

#include <QString>

Controller::Controller(Interface *inte)
{
    //set the default location to London, Canada
    QString location = "London,can";

    //set the default units to metric
    QString units = "metric";

    //create a Data object using this Controller, and the default values for location and units
    _data = new Data (location, units, this);
    _interface = inte;

}

//called when the user wants to change the units of the display (involed by Interface class)
void Controller::changeUnits(QString units)
{
    //tell the Data class to change the desired units
    _data->changeUnits(units);
}

//called when the user wants to change the location (invoked by Interface class)
void Controller::changeCity(QString location)
{
    //tells the Data class to change the location
    _data->changeLocation(location);
}

//returns the current temperature
double& Controller::temperature ()
{
    return (_data->temperature());
}

//returns the current location
QString& Controller::city()
{
    return (_data->location());
}

//returns the current units
QString& Controller::units()
{
    return (_data->units());
}

//returns the current weather conditions
QString& Controller::currentConditions()
{
    return (_data->currentConditions());
}

//called when the user presses the 'Get Weather' button (invoked by Interface class)
void Controller::getWeather()
{
    //tell the Data class to send the URL query
    _data->sendQuery();
}

//tell the interface to update the UI when the Data class receives new weather information
void Controller::updateDisplay(double temp)
{
    _interface->updateDisplay(temp);
}

//called when there is a network error
void Controller::networkError()
{
    _interface->networkError();
}

Controller::~Controller()
{
    delete _data;
    delete _interface;
}
