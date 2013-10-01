#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

class Data : public QObject
{
    Q_OBJECT

public:
    Data(QString location, QString units);
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
    void replyFinished(QNetworkReply *reply);

private:
    QString _location;
    QString _units;
    double _temp;
    QString _conditions;
    QUrl _url;
    QUrlQuery _query;
    QNetworkAccessManager *_manager;
    bool _networkError;

};

#endif // DATA_H
