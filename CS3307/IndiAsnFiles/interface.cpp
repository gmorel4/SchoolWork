#include "interface.h"
#include "ui_mainwindow.h"

#include <QPushButton>

Interface::Interface(QWidget *parent = 0) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _controller = new Controller();
    _weather = new QPushButton (this);
    weather = _ui->getWeather;
    connect (weather, SIGNAL(released()), this, slot(getWeather()));
}

void Interface::getWeather()
{
    _controller->getWeather();
    QString display(QString::number(_contoller->temperature, 'f', 1) + "degrees");
    _ui->tempLabel->setText(display);
}
