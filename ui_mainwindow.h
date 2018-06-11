/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *detectMarkers;
    QPushButton *tracking;
    QPushButton *settings;
    QGroupBox *groupBox;
    QRadioButton *intWebCam;
    QRadioButton *extWebCam;
    QPushButton *load;
    QFrame *ViolinColor;
    QLabel *label;
    QLabel *label_2;
    QFrame *BowColor;
    QPushButton *ViewColors;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(684, 253);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        detectMarkers = new QPushButton(centralWidget);
        detectMarkers->setObjectName(QStringLiteral("detectMarkers"));
        detectMarkers->setGeometry(QRect(30, 20, 141, 32));
        tracking = new QPushButton(centralWidget);
        tracking->setObjectName(QStringLiteral("tracking"));
        tracking->setGeometry(QRect(30, 60, 141, 32));
        settings = new QPushButton(centralWidget);
        settings->setObjectName(QStringLiteral("settings"));
        settings->setGeometry(QRect(30, 100, 141, 32));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(200, 10, 191, 121));
        intWebCam = new QRadioButton(groupBox);
        intWebCam->setObjectName(QStringLiteral("intWebCam"));
        intWebCam->setEnabled(true);
        intWebCam->setGeometry(QRect(20, 30, 151, 20));
        intWebCam->setCheckable(true);
        intWebCam->setChecked(false);
        extWebCam = new QRadioButton(groupBox);
        extWebCam->setObjectName(QStringLiteral("extWebCam"));
        extWebCam->setGeometry(QRect(20, 70, 151, 20));
        extWebCam->setChecked(true);
        load = new QPushButton(centralWidget);
        load->setObjectName(QStringLiteral("load"));
        load->setGeometry(QRect(30, 140, 141, 32));
        ViolinColor = new QFrame(centralWidget);
        ViolinColor->setObjectName(QStringLiteral("ViolinColor"));
        ViolinColor->setGeometry(QRect(550, 45, 110, 80));
        ViolinColor->setFrameShape(QFrame::WinPanel);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(540, 15, 131, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 15, 131, 16));
        BowColor = new QFrame(centralWidget);
        BowColor->setObjectName(QStringLiteral("BowColor"));
        BowColor->setGeometry(QRect(420, 45, 110, 80));
        BowColor->setFrameShape(QFrame::WinPanel);
        ViewColors = new QPushButton(centralWidget);
        ViewColors->setObjectName(QStringLiteral("ViewColors"));
        ViewColors->setEnabled(true);
        ViewColors->setGeometry(QRect(460, 140, 161, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 684, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        detectMarkers->setText(QApplication::translate("MainWindow", "Detect Markers", nullptr));
        tracking->setText(QApplication::translate("MainWindow", "Tracking", nullptr));
        settings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Camera to work with?", nullptr));
        intWebCam->setText(QApplication::translate("MainWindow", "Integrated Webcam", nullptr));
        extWebCam->setText(QApplication::translate("MainWindow", "External Webcam", nullptr));
        load->setText(QApplication::translate("MainWindow", "Load", nullptr));
        label->setText(QApplication::translate("MainWindow", "Color of violin marker", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Color of bow marker", nullptr));
        ViewColors->setText(QApplication::translate("MainWindow", "View/Refresh Colors", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
