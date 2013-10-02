#ifndef INTERFACE_H
#define INTERFACE_H

#include "controller.h"

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QPushButton>
#include <QString>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    void updateDisplay(double temp);
    void networkError();
    ~Interface();

public slots:
    void getWeather();
    void changeLocation(QString);
    void changeUnits(QString);

private:
    QPushButton *_weather;
    Controller *_controller;
    Ui::MainWindow *_ui;
    QComboBox *_location;
    QComboBox *_units;


};

#endif // INTERFACE_H
