#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "data.h"


#include <QString>
#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>

namespace Ui{
class MainWindow;
}

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    explicit Controller(QWidget *parent = 0);
    //double& temperature();
/*  QString& city();
    QString& units();
    QString& currentConditions();*/
    void updateDisplay (double temp);
    void networkError();
    ~Controller();

public slots:
    void getWeather();
    void changeLocation ();
    void changeUnits ();


private:
    QPushButton *_weather;
    //QComboBox *_location;
    //QComboBox *_units;
    Ui::MainWindow *_ui;
    Data *_data;


};

#endif // CONTROLLER_H
