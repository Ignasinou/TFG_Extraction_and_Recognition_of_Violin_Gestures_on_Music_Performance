/********************************************************************************
** Form generated from reading UI file 'utilsgesturerecognition.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTILSGESTURERECOGNITION_H
#define UI_UTILSGESTURERECOGNITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_utilsGestureRecognition
{
public:

    void setupUi(QWidget *utilsGestureRecognition)
    {
        if (utilsGestureRecognition->objectName().isEmpty())
            utilsGestureRecognition->setObjectName(QStringLiteral("utilsGestureRecognition"));
        utilsGestureRecognition->resize(400, 300);

        retranslateUi(utilsGestureRecognition);

        QMetaObject::connectSlotsByName(utilsGestureRecognition);
    } // setupUi

    void retranslateUi(QWidget *utilsGestureRecognition)
    {
        utilsGestureRecognition->setWindowTitle(QApplication::translate("utilsGestureRecognition", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class utilsGestureRecognition: public Ui_utilsGestureRecognition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTILSGESTURERECOGNITION_H
