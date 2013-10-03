#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QtNetwork/QNetworkReply>

class Controller;
class Data : public QObject
{
    Q_OBJECT

public:
    Data(QString location, QString units, Controller *control);
    double& temperature();
    void changeUnits(QString units);
    QString& location();
    void changeLocation(QString location);
    QString& currentConditions();
    QString& units();
    bool netError();
    void sendQuery();
    ~Data();

public slots:
    void replyFinished(QNetworkReply * reply);

private:
    Controller *_controller;
    QString _location;
    QString _units;
    QNetworkAccessManager *_manager;
    bool _networkError;

};

#endif // DATA_H
