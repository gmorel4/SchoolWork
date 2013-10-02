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
    QLabel *label;
    QPushButton *getWeather;
    QComboBox *locationBox;
    QComboBox *unitBox;
    QLabel *label_2;
    QLabel *conditionLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tempLabel = new QLabel(centralWidget);
        tempLabel->setObjectName(QStringLiteral("tempLabel"));
        tempLabel->setGeometry(QRect(40, 170, 321, 71));
        tempLabel->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 141, 21));
        label->setAlignment(Qt::AlignCenter);
        getWeather = new QPushButton(centralWidget);
        getWeather->setObjectName(QStringLiteral("getWeather"));
        getWeather->setGeometry(QRect(140, 250, 114, 32));
        locationBox = new QComboBox(centralWidget);
        locationBox->setObjectName(QStringLiteral("locationBox"));
        locationBox->setGeometry(QRect(130, 30, 111, 26));
        unitBox = new QComboBox(centralWidget);
        unitBox->setObjectName(QStringLiteral("unitBox"));
        unitBox->setGeometry(QRect(130, 70, 111, 26));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 111, 21));
        conditionLabel = new QLabel(centralWidget);
        conditionLabel->setObjectName(QStringLiteral("conditionLabel"));
        conditionLabel->setGeometry(QRect(40, 100, 321, 71));
        conditionLabel->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        tempLabel->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Choose Location:", 0));
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
        label_2->setText(QApplication::translate("MainWindow", "Choose Units:", 0));
        conditionLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
