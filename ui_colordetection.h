/********************************************************************************
** Form generated from reading UI file 'colordetection.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORDETECTION_H
#define UI_COLORDETECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_colorDetection
{
public:
    QPushButton *pushButton;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *color0Button;
    QPushButton *color1Button;
    QPushButton *color2Button;

    void setupUi(QDialog *colorDetection)
    {
        if (colorDetection->objectName().isEmpty())
            colorDetection->setObjectName(QStringLiteral("colorDetection"));
        colorDetection->resize(575, 237);
        pushButton = new QPushButton(colorDetection);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 10, 141, 32));
        frame = new QFrame(colorDetection);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 60, 120, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(colorDetection);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(230, 60, 120, 80));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(colorDetection);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(420, 60, 121, 81));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label = new QLabel(colorDetection);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 147, 60, 16));
        label_2 = new QLabel(colorDetection);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 150, 60, 10));
        label_3 = new QLabel(colorDetection);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 147, 60, 16));
        color0Button = new QPushButton(colorDetection);
        color0Button->setObjectName(QStringLiteral("color0Button"));
        color0Button->setGeometry(QRect(40, 170, 121, 32));
        color1Button = new QPushButton(colorDetection);
        color1Button->setObjectName(QStringLiteral("color1Button"));
        color1Button->setGeometry(QRect(230, 170, 121, 32));
        color2Button = new QPushButton(colorDetection);
        color2Button->setObjectName(QStringLiteral("color2Button"));
        color2Button->setGeometry(QRect(422, 170, 121, 32));

        retranslateUi(colorDetection);

        QMetaObject::connectSlotsByName(colorDetection);
    } // setupUi

    void retranslateUi(QDialog *colorDetection)
    {
        colorDetection->setWindowTitle(QApplication::translate("colorDetection", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("colorDetection", "Detect Colors", nullptr));
        label->setText(QApplication::translate("colorDetection", "1. ", nullptr));
        label_2->setText(QApplication::translate("colorDetection", "2. ", nullptr));
        label_3->setText(QApplication::translate("colorDetection", "3. ", nullptr));
        color0Button->setText(QApplication::translate("colorDetection", "Choose 1", nullptr));
        color1Button->setText(QApplication::translate("colorDetection", "Choose 2", nullptr));
        color2Button->setText(QApplication::translate("colorDetection", "Choose 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class colorDetection: public Ui_colorDetection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORDETECTION_H
