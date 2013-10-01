#include "interface.h"
#include "ui_mainwindow.h"

#include <QPushButton>

Interface::Interface(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _controller = new Controller();
    _weather = _ui->getWeather;
    connect (_weather, SIGNAL(released()), this, SLOT(getWeather()));
}

void Interface::getWeather()
{
    _controller->getWeather();
    double temp = _controller->temperature();
    QString display(QString::number(temp, 'f', 1) + "degrees");
    _ui->tempLabel->setText(display);
}

Interface::~Interface()
{
    delete _controller;
    delete _weather;
    delete _ui;
}
