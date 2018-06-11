#ifndef UTILSGESTURERECOGNITION_H
#define UTILSGESTURERECOGNITION_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class utilsGestureRecognition;
}

class utilsGestureRecognition : public QWidget
{
    Q_OBJECT

public:
    explicit utilsGestureRecognition(QWidget *parent = 0);
    ~utilsGestureRecognition();

    void angleDetection(int x1, int x2, int x3, int y1, int y2, int y3, int &isCorrect);
    void visualFeedbackViolinPosition(double &a1, double &a2, double &a3, bool &isCorrectPos);
    void getFrameRate(cv::VideoCapture video);
    double calcAngle(cv::Point p1, cv::Point p2, cv::Point p3, cv::Point p4);
    void visualFeedbackSkewness(double &angle);


private:
    Ui::utilsGestureRecognition *ui;

    double distancePoints(int x1, int y1, int x2, int y2);

};

#endif // UTILSGESTURERECOGNITION_H
