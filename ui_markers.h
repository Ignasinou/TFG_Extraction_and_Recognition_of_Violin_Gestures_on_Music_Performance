/********************************************************************************
** Form generated from reading UI file 'markers.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKERS_H
#define UI_MARKERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_markers
{
public:
    QPushButton *bowMarkers;
    QPushButton *violinMarkers;
    QLabel *label;

    void setupUi(QWidget *markers)
    {
        if (markers->objectName().isEmpty())
            markers->setObjectName(QStringLiteral("markers"));
        markers->resize(441, 115);
        bowMarkers = new QPushButton(markers);
        bowMarkers->setObjectName(QStringLiteral("bowMarkers"));
        bowMarkers->setEnabled(true);
        bowMarkers->setGeometry(QRect(60, 60, 113, 32));
        bowMarkers->setCheckable(false);
        bowMarkers->setChecked(false);
        bowMarkers->setAutoDefault(false);
        violinMarkers = new QPushButton(markers);
        violinMarkers->setObjectName(QStringLiteral("violinMarkers"));
        violinMarkers->setGeometry(QRect(270, 60, 113, 32));
        violinMarkers->setAutoDefault(false);
        label = new QLabel(markers);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 30, 301, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(markers);

        QMetaObject::connectSlotsByName(markers);
    } // setupUi

    void retranslateUi(QWidget *markers)
    {
        markers->setWindowTitle(QApplication::translate("markers", "Form", nullptr));
        bowMarkers->setText(QApplication::translate("markers", "Bow markers", nullptr));
        violinMarkers->setText(QApplication::translate("markers", "Violin markers", nullptr));
        label->setText(QApplication::translate("markers", "Which marker do you want to detect?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class markers: public Ui_markers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKERS_H
