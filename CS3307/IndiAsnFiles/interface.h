#ifndef INTERFACE_H
#define INTERFACE_H

#include "controller.h"

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();

public slots:
    void getWeather();

private:
    QPushButton *_weather;
    Controller *_controller;
    Ui::MainWindow *_ui;


};

#endif // INTERFACE_H
