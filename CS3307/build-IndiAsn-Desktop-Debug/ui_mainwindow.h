/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *tempLabel;
    QLabel *chooseLocation;
    QPushButton *getWeather;
    QComboBox *locationBox;
    QComboBox *unitBox;
    QLabel *chooseUnits;
    QLabel *Title;
    QLabel *locationLabel;
    QLabel *degreeLabel;
    QLabel *unitLabel;
    QLabel *sunriseLabel;
    QLabel *sunsetLabel;
    QLabel *conditionsLabel;
    QLabel *pressureLabel;
    QLabel *hiloLabel;
    QLabel *humidityLabel;
    QLabel *windLabel;
    QLabel *degreeLabel_2;
    QLabel *smUnitLabel;
    QLabel *courtesyLabel;
    QLabel *sunImage;
    QLabel *weatherImage;
    QLabel *rainImage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(463, 417);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(53, 53, 53);"));
        tempLabel = new QLabel(centralWidget);
        tempLabel->setObjectName(QStringLiteral("tempLabel"));
        tempLabel->setGeometry(QRect(330, 160, 81, 51));
        tempLabel->setStyleSheet(QLatin1String("\n"
"font: 75 20pt \"Cantarell\";\n"
"color: rgb(255, 70, 70);"));
        tempLabel->setAlignment(Qt::AlignCenter);
        chooseLocation = new QLabel(centralWidget);
        chooseLocation->setObjectName(QStringLiteral("chooseLocation"));
        chooseLocation->setGeometry(QRect(-10, 70, 151, 21));
        chooseLocation->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        chooseLocation->setAlignment(Qt::AlignCenter);
        getWeather = new QPushButton(centralWidget);
        getWeather->setObjectName(QStringLiteral("getWeather"));
        getWeather->setGeometry(QRect(180, 340, 114, 32));
        getWeather->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(172, 172, 172);"));
        locationBox = new QComboBox(centralWidget);
        locationBox->setObjectName(QStringLiteral("locationBox"));
        locationBox->setGeometry(QRect(130, 70, 221, 26));
        locationBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(179, 179, 179);"));
        unitBox = new QComboBox(centralWidget);
        unitBox->setObjectName(QStringLiteral("unitBox"));
        unitBox->setGeometry(QRect(120, 120, 141, 26));
        unitBox->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(179, 179, 179);"));
        chooseUnits = new QLabel(centralWidget);
        chooseUnits->setObjectName(QStringLiteral("chooseUnits"));
        chooseUnits->setGeometry(QRect(10, 120, 101, 21));
        chooseUnits->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        Title = new QLabel(centralWidget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(120, 20, 231, 41));
        Title->setMaximumSize(QSize(471, 51));
        Title->setStyleSheet(QLatin1String("color: rgb(93, 228, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"font: 75 italic 28pt \"Century Schoolbook L\";"));
        locationLabel = new QLabel(centralWidget);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));
        locationLabel->setGeometry(QRect(30, 160, 281, 51));
        locationLabel->setStyleSheet(QLatin1String("font: 75 18pt \"Cantarell\";\n"
"color: rgb(170, 170, 170);"));
        degreeLabel = new QLabel(centralWidget);
        degreeLabel->setObjectName(QStringLiteral("degreeLabel"));
        degreeLabel->setGeometry(QRect(400, 160, 21, 20));
        degreeLabel->setStyleSheet(QStringLiteral("color: rgb(255, 70, 70);"));
        unitLabel = new QLabel(centralWidget);
        unitLabel->setObjectName(QStringLiteral("unitLabel"));
        unitLabel->setGeometry(QRect(410, 170, 31, 31));
        unitLabel->setStyleSheet(QLatin1String("font: 75 20pt \"Cantarell\";\n"
"color: rgb(255, 70, 70);"));
        sunriseLabel = new QLabel(centralWidget);
        sunriseLabel->setObjectName(QStringLiteral("sunriseLabel"));
        sunriseLabel->setGeometry(QRect(40, 250, 171, 21));
        sunriseLabel->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        sunsetLabel = new QLabel(centralWidget);
        sunsetLabel->setObjectName(QStringLiteral("sunsetLabel"));
        sunsetLabel->setGeometry(QRect(40, 280, 161, 21));
        sunsetLabel->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        conditionsLabel = new QLabel(centralWidget);
        conditionsLabel->setObjectName(QStringLiteral("conditionsLabel"));
        conditionsLabel->setGeometry(QRect(20, 210, 411, 31));
        conditionsLabel->setStyleSheet(QLatin1String("font: 75 14pt \"Cantarell\";\n"
"color: rgb(170, 170, 170);"));
        pressureLabel = new QLabel(centralWidget);
        pressureLabel->setObjectName(QStringLiteral("pressureLabel"));
        pressureLabel->setGeometry(QRect(40, 310, 131, 21));
        pressureLabel->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        hiloLabel = new QLabel(centralWidget);
        hiloLabel->setObjectName(QStringLiteral("hiloLabel"));
        hiloLabel->setGeometry(QRect(280, 250, 131, 21));
        hiloLabel->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        humidityLabel = new QLabel(centralWidget);
        humidityLabel->setObjectName(QStringLiteral("humidityLabel"));
        humidityLabel->setGeometry(QRect(280, 280, 131, 21));
        humidityLabel->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        windLabel = new QLabel(centralWidget);
        windLabel->setObjectName(QStringLiteral("windLabel"));
        windLabel->setGeometry(QRect(280, 310, 191, 21));
        windLabel->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        degreeLabel_2 = new QLabel(centralWidget);
        degreeLabel_2->setObjectName(QStringLiteral("degreeLabel_2"));
        degreeLabel_2->setGeometry(QRect(400, 240, 21, 20));
        degreeLabel_2->setStyleSheet(QLatin1String("color: rgb(170, 170, 170);\n"
"font: 75 9pt \"Cantarell\";"));
        smUnitLabel = new QLabel(centralWidget);
        smUnitLabel->setObjectName(QStringLiteral("smUnitLabel"));
        smUnitLabel->setGeometry(QRect(410, 250, 21, 21));
        smUnitLabel->setStyleSheet(QStringLiteral("color: rgb(170, 170, 170);"));
        courtesyLabel = new QLabel(centralWidget);
        courtesyLabel->setObjectName(QStringLiteral("courtesyLabel"));
        courtesyLabel->setGeometry(QRect(100, 400, 281, 21));
        courtesyLabel->setStyleSheet(QLatin1String("color: rgb(170, 170, 170);\n"
"font: 8pt \"Asana Math\";"));
        sunImage = new QLabel(centralWidget);
        sunImage->setObjectName(QStringLiteral("sunImage"));
        sunImage->setGeometry(QRect(370, 0, 91, 71));
        sunImage->setStyleSheet(QStringLiteral("image: url(:/images/images/bright_sun_T.png);"));
        weatherImage = new QLabel(centralWidget);
        weatherImage->setObjectName(QStringLiteral("weatherImage"));
        weatherImage->setGeometry(QRect(10, 160, 441, 161));
        weatherImage->setStyleSheet(QLatin1String("\n"
"background-color: rgba(255, 255, 255, 0);"));
        rainImage = new QLabel(centralWidget);
        rainImage->setObjectName(QStringLiteral("rainImage"));
        rainImage->setGeometry(QRect(0, 0, 111, 61));
        rainImage->setStyleSheet(QStringLiteral("image: url(:/images/images/rain.png);"));
        MainWindow->setCentralWidget(centralWidget);
        sunImage->raise();
        tempLabel->raise();
        chooseLocation->raise();
        getWeather->raise();
        locationBox->raise();
        unitBox->raise();
        chooseUnits->raise();
        Title->raise();
        locationLabel->raise();
        degreeLabel->raise();
        unitLabel->raise();
        sunriseLabel->raise();
        sunsetLabel->raise();
        conditionsLabel->raise();
        pressureLabel->raise();
        hiloLabel->raise();
        humidityLabel->raise();
        windLabel->raise();
        degreeLabel_2->raise();
        smUnitLabel->raise();
        courtesyLabel->raise();
        weatherImage->raise();
        rainImage->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        tempLabel->setText(QString());
        chooseLocation->setText(QApplication::translate("MainWindow", "Choose Location:", 0));
        getWeather->setText(QApplication::translate("MainWindow", "Get Weather", 0));
        locationBox->clear();
        locationBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "London, ON, Canada", 0)
         << QApplication::translate("MainWindow", "Boston, MA, USA", 0)
         << QApplication::translate("MainWindow", "Toronto, ON, Canada", 0)
         << QApplication::translate("MainWindow", "Seattle, WA, USA", 0)
         << QApplication::translate("MainWindow", "Parry Sound, ON, Canada", 0)
        );
        unitBox->clear();
        unitBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Metric", 0)
         << QApplication::translate("MainWindow", "Imperial", 0)
         << QApplication::translate("MainWindow", "Internal", 0)
        );
        chooseUnits->setText(QApplication::translate("MainWindow", "Choose Units:", 0));
        Title->setText(QApplication::translate("MainWindow", "Weather Now", 0));
        locationLabel->setText(QString());
        degreeLabel->setText(QString());
        unitLabel->setText(QString());
        sunriseLabel->setText(QString());
        sunsetLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        conditionsLabel->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        conditionsLabel->setText(QString());
        pressureLabel->setText(QString());
        hiloLabel->setText(QString());
        humidityLabel->setText(QString());
        windLabel->setText(QString());
        degreeLabel_2->setText(QString());
        smUnitLabel->setText(QString());
        courtesyLabel->setText(QApplication::translate("MainWindow", "Weather information courtesy of openweathermaps.org", 0));
        sunImage->setText(QString());
        weatherImage->setText(QString());
        rainImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
