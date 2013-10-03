#include "controller.h"
#include "data.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QDateTime>

Controller::Controller(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{

    _ui->setupUi(this);
    //set the default location to London, Canada
    QString location = "London, ON, CAN";

    //set the default units to metric
    QString units = "Metric";

    //create a Data object using this Controller, and the default values for location and units
    _data = new Data (location, units, this);

    _weather = _ui->getWeather;

    _location = _ui->locationBox;
    _units = _ui->unitBox;

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
    _ui->locationLabel->setText("Getting weather.....");
}

//tell the interface to update the UI when the Data class receives new weather information
void Controller::updateMain(QString& location, double& temp, QString& units)
{
    //create a new QString to be displayed from the double that was received as a parameter
    QString display(QString::number(temp, 'f', 1));

    //display the QString on the UI in the associated text box
    _ui->locationLabel->setText(location);
    _ui->tempLabel->setText(display);
    _ui->degreeLabel->setText("o");

    if (units == "Imperial")
        _ui->unitLabel->setText("F");
    else if (units == "Metric")
        _ui->unitLabel->setText("C");
    else
        _ui->unitLabel->setText("K");
}

void Controller::updateConditions(QString &conditions)
{
    _ui->conditionsLabel->setAlignment(Qt::AlignCenter);
    _ui->conditionsLabel->setText(conditions);
}

void Controller::updateDescription(double &min, double &max, double &humidity, double &pressure, uint &sunrise, uint &sunset, double &windspeed, double &winddirection)
{
    QDateTime sunrDT = QDateTime::fromTime_t(sunrise);
    QDateTime sunsDT = QDateTime::fromTime_t(sunset);
    QString sunr ("Sunrise: " + sunrDT.toString("hh:mm:ss ap"));
    QString suns ("Sunset: " + sunsDT.toString("hh:mm:ss ap"));
    QString units = _data->units();
    QString HiLo ("Hi/Lo: " + QString::number(max,'f',1) + "/" + QString::number(min,'f',1));
    QString tempUnits;
    QString humid ("Humidity: " + QString::number(humidity,'f',1) + "%");
    QString press ("Pressure: " + QString::number(pressure, 'f',1) + " Pa");
    QString direction;

    if ((winddirection >= 0 && winddirection <= 11.25) || (winddirection > 348.75 && winddirection <= 360))
        direction = "N";
    else if (winddirection > 11.25 && winddirection <= 33.75)
        direction = "NNE";
    else if (winddirection > 33.75 && winddirection <= 56.25)
        direction = "NE";
    else if (winddirection > 56.25 && winddirection <= 78.75)
        direction = "ENE";
    else if (winddirection > 78.75 && winddirection <= 101.25)
        direction = "E";
    else if (winddirection > 101.25 && winddirection <= 123.75)
        direction = "ESE";
    else if (winddirection > 123.75 && winddirection <= 146.25)
        direction = "SE";
    else if (winddirection > 146.25 && winddirection <= 168.75)
        direction = "SSE";
    else if (winddirection > 168.75 && winddirection <= 191.25)
        direction = "S";
    else if (winddirection > 191.25 && winddirection <= 213.75)
        direction = "SSW";
    else if (winddirection > 213.75 && winddirection <= 236.25)
        direction = "SW";
    else if (winddirection > 236.25 && winddirection <= 258.75)
        direction = "WSW";
    else if (winddirection > 258.75 && winddirection <= 281.25)
        direction = "W";
    else if (winddirection > 281.25 && winddirection <= 303.75)
        direction = "WNW";
    else if (winddirection > 303.75 && winddirection <= 326.25)
        direction = "NW";
    else if (winddirection > 326.25 && winddirection <= 348.75)
        direction = "NNW";

    QString windUnits;
    if (units == "Imperial")
    {
        windUnits = "Mph";
        tempUnits = "F";
    }
    else if (units == "Metric")
    {
        windUnits = "Km/h";
        tempUnits = "C";
    }
    else
    {
        windUnits = "Km/h";
        tempUnits = "K";
    }

    QString wind ("Wind: " + QString::number(windspeed, 'f', 1) + " " + windUnits + " " + direction);

    _ui->hiloLabel->setText(HiLo);
    _ui->degreeLabel_2->setText("o");
    _ui->smUnitLabel->setText(tempUnits);
    _ui->sunriseLabel->setText(sunr);
    _ui->sunsetLabel->setText(suns);
    _ui->humidityLabel->setText(humid);
    _ui->pressureLabel->setText(press);
    _ui->windLabel->setText(wind);
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
