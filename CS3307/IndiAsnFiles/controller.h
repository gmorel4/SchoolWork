#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "data.h"
#include "interface.h"

#include <QString>

class Controller
{
public:
    Controller(Interface* inter);
    void changeUnits(QString units);
    void changeCity(QString location);
    double& temperature();
    QString& city();
    QString& units();
    QString& currentConditions();
    void getWeather();
    void updateDisplay (double temp);
    void networkError();
    ~Controller();


private:
    Data *_data;
    Interface *_interface;


};

#endif // CONTROLLER_H
