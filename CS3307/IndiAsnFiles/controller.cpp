#include "controller.h"
#include "data.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{

    _ui->setupUi(this);
    //set the default location to London, Canada
    QString location = "London,can";

    //set the default units to metric
    QString units = "metric";

    //create a Data object using this Controller, and the default values for location and units
    _data = new Data (location, units, this);

    _weather = _ui->getWeather;

    //_location = _ui->locationBox;
    //_units = _ui->unitBox;

    connect (_weather, SIGNAL(released()), this, SLOT(getWeather()));
    connect (_location, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeLocation()));
    connect (_units, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeUnits()));

}

//called when the user wants to change the units of the display (involed by Interface class)
void Controller::changeUnits()
{
    //tell the Data class to change the desired units
    _data->changeUnits(_ui->unitBox->currentText());
}

//called when the user wants to change the location (invoked by Interface class)
void Controller::changeLocation()
{
    //tells the Data class to change the location
    _data->changeLocation(_ui->locationBox->currentText());
}

//returns the current temperature
//double& Controller::temperature ()
//{
//    return (_data->temperature());
//}

//returns the current location
//QString& Controller::city()
//{
//    return (_data->location());
//}

//returns the current units
//QString& Controller::units()
//{
//    return (_data->units());
//}

//returns the current weather conditions
//QString& Controller::currentConditions()
//{
//    return (_data->currentConditions());
//}

//called when the user presses the 'Get Weather' button (invoked by Interface class)
void Controller::getWeather()
{
    //tell the Data class to send the URL query
    _data->sendQuery();
}

//tell the interface to update the UI when the Data class receives new weather information
void Controller::updateDisplay(double temp)
{
    //create a new QString to be displayed from the double that was received as a parameter
    QString display(QString::number(temp, 'f', 1) + "degrees");

    //display the QString on the UI in the associated text box
    _ui->tempLabel->setText(display);
}

//called when there is a network error
void Controller::networkError()
{
    QString display("Network Error!");
    _ui->tempLabel->setText(display);
}

Controller::~Controller()
{
    delete _data;
    delete _ui;
}
