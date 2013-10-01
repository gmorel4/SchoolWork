#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Data.cpp"

#include <QString>

class Controller
{
public:
    Controller();
    void changeUnits(QString units);
    void changeCity(QString location);
    double& temperature();
    QString& city();
    QString& units();
    QString& currentConditions();
    void getWeather();
    ~Controller();


private:
    Data *_data;


};

#endif // CONTROLLER_H
