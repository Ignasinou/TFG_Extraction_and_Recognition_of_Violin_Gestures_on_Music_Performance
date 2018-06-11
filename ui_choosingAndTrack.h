/********************************************************************************
** Form generated from reading UI file 'choosingAndTrack.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSINGANDTRACK_H
#define UI_CHOOSINGANDTRACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_choosingAndTrack
{
public:

    void setupUi(QWidget *choosingAndTrack)
    {
        if (choosingAndTrack->objectName().isEmpty())
            choosingAndTrack->setObjectName(QStringLiteral("choosingAndTrack"));
        choosingAndTrack->resize(400, 300);

        retranslateUi(choosingAndTrack);

        QMetaObject::connectSlotsByName(choosingAndTrack);
    } // setupUi

    void retranslateUi(QWidget *choosingAndTrack)
    {
        choosingAndTrack->setWindowTitle(QApplication::translate("choosingAndTrack", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class choosingAndTrack: public Ui_choosingAndTrack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSINGANDTRACK_H
