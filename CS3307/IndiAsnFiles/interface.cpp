#include "interface.h"
#include "ui_mainwindow.h"

#include <QPushButton>

Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    //setting up the UI window with this Interface class
    _ui->setupUi(this);

    //creating a new Controller object with this Interface class
    _controller = new Controller(this);

    //linking the _weather button to be the Get Weather button from the UI
    _weather = _ui->getWeather;

    _location = _ui->locationBox;
    _units - _ui->unitBox;

    //connectiong the _weather push button to a slot to call getWeather() function when the button is released
    connect (_weather, SIGNAL(released()), this, SLOT(getWeather()));

    connect(_location, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeLocation(QString)));
    connect(_units, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeUnits(QString)));
}

void Interface::getWeather()
{
    //tells the controller to get a weather update
    _controller->getWeather();
}

void Interface::changeLocation(QString)
{
    _controller->changeCity(_location->currentText());
}

void Interface::changeUnits(QString)
{
    _controller->changeUnits(_units->currentText());
}

//function called by the controller when new information is received
//and the display needs to be updated
void Interface::updateDisplay (double temp)
{
    //create a new QString to be displayed from the double that was received as a parameter
    QString display(QString::number(temp, 'f', 1) + "degrees");

    //display the QString on the UI in the associated text box
    _ui->tempLabel->setText(display);
}

//called by the controller if there was an error with
//connecting to weather server
void Interface::networkError()
{
    QString display("Network Error!");
    _ui->tempLabel->setText(display);
}

Interface::~Interface()
{
    delete _controller;
    delete _weather;
    delete _ui;
}
