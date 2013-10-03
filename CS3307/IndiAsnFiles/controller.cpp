#include "controller.h"
#include "data.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QDateTime>
#include <QPixmap>

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

    //creating a pixmap to have a starting image
    QPixmap pix (":/images/images/weather.png");

    //align the label holding the start-up image to the centre
    _ui->weatherImage->setAlignment(Qt::AlignCenter);

    //set the start-up image
    _ui->weatherImage->setPixmap(pix);

    //set the push button
    _weather = _ui->getWeather;

    //set the selection boxes
    _location = _ui->locationBox;
    _units = _ui->unitBox;

    //connect the widget signals to the specified slots
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

//called when the user presses the 'Get Weather' button (invoked by Interface class)
void Controller::getWeather()
{
    //tell the Data class to send the URL query
    _data->sendQuery();

    //clear all of the weather labels and start-up image (only there on first call)
    _ui->weatherImage->clear();
    _ui->conditionsLabel->clear();
    _ui->degreeLabel->clear();
    _ui->degreeLabel_2->clear();
    _ui->hiloLabel->clear();
    _ui->humidityLabel->clear();
    _ui->locationLabel->clear();
    _ui->pressureLabel->clear();
    _ui->smUnitLabel->clear();
    _ui->sunriseLabel->clear();
    _ui->sunsetLabel->clear();
    _ui->tempLabel->clear();
    _ui->unitLabel->clear();
    _ui->windLabel->clear();

    //display message to user
    _ui->locationLabel->setText("Getting weather.....");
}

//tell the interface to update the UI when the Data class receives new weather information
void Controller::updateMain(QString& location, double& temp, QString& units)
{
    //create a new QString to be displayed from the double that was received as a parameter
    QString display(QString::number(temp, 'f', 1));

    //display the location, temperature in the current units
    _ui->locationLabel->setText(location);
    _ui->tempLabel->setText(display);
    _ui->degreeLabel->setText("o");

    //set the units label to be the correct letter abbreviation for the desired units
    if (units == "Imperial")
        _ui->unitLabel->setText("F");
    else if (units == "Metric")
        _ui->unitLabel->setText("C");
    else
        _ui->unitLabel->setText("K");
}

//updates the current conditions description
void Controller::updateConditions(QString &conditions)
{
    //allign the label holding the conditions description to be in the centre
    _ui->conditionsLabel->setAlignment(Qt::AlignCenter);

    //display the conditions
    _ui->conditionsLabel->setText(conditions);
}

//update other weather conditions (min and max temps, humidity, pressure, sunrise, sunset, windspeed and direction)
void Controller::updateDescription(double &min, double &max, double &humidity, double &pressure, uint &sunrise, uint &sunset, double &windspeed, double &winddirection)
{
    //convert the unix time of the sunrise and sunset to a QDateTime object
    QDateTime sunrDT = QDateTime::fromTime_t(sunrise);
    QDateTime sunsDT = QDateTime::fromTime_t(sunset);

    //make a QString to display the sunrise and sunset times with the desired format
    QString sunr ("Sunrise: " + sunrDT.toString("hh:mm:ss ap"));
    QString suns ("Sunset: " + sunsDT.toString("hh:mm:ss ap"));

    //get the current requested units
    QString units = _data->units();

    //make a QString the for Hi/Lo temperature
    QString HiLo ("Hi/Lo: " + QString::number(max,'f',1) + "/" + QString::number(min,'f',1));

    QString tempUnits;

    //make a QString for the humidity
    QString humid ("Humidity: " + QString::number(humidity,'f',1) + "%");

    //make a QString for the pressure (not sure what units were used, assumed Pascals?)
    QString press ("Pressure: " + QString::number(pressure, 'f',1) + " Pa");


    QString direction;

    //a really long if/else if chain to determine the direction of the wind, based on the given degrees
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

    //get the correct abbreviation for windspeed and temperature based on the desired units
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

    //create a QString for the wind
    QString wind ("Wind: " + QString::number(windspeed, 'f', 1) + " " + windUnits + " " + direction);

    //display all of the created QStrings for the detailed weather information
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
    //display to the user that there was an error when a reply was received
    QString display("Network Error!");
    _ui->tempLabel->setText(display);
}

Controller::~Controller()
{
    delete _data;
    delete _ui;
}
