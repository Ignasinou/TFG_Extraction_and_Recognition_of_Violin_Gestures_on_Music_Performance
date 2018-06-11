#ifndef COLORDETECTION_H
#define COLORDETECTION_H

#include <QDialog>
#include "mainwindow.h"



namespace Ui {
class colorDetection;
}

class colorDetection : public QDialog
{
    Q_OBJECT

public:
    explicit colorDetection(QWidget *parent = 0);
    ~colorDetection();
private slots:

    void DetectionOfColors();

    void PassTheColorDetectedOnButtonClicked(cv::Vec3b colorPassed);

    void on_pushButton_clicked();

    void on_color0Button_clicked();

    void on_color1Button_clicked();

    void on_color2Button_clicked();
private:
    Ui::colorDetection *ui;
};

#endif // COLORDETECTION_H
