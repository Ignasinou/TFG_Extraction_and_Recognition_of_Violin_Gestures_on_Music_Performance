#ifndef choosingAndTrack_H
#define choosingAndTrack_H

#include <QDialog>
#include "mainwindow.h"

using namespace cv;
using namespace std;

namespace Ui {
class choosingAndTrack;
}

class choosingAndTrack : public QDialog
{
    Q_OBJECT


public:
    explicit choosingAndTrack(QWidget *parent = 0);
    ~choosingAndTrack();

    void TrackColor(cv::Vec3b color);
    void Tracking();
    Vec3b getViolinColor();
    Vec3b getBowColor();

    //COSES PEL TRACKING
    double area1Bow, area2Bow;
    double area1Violin, area2Violin, area3Violin;
    double sideLength1Bow, sideLength2Bow;
    double sideLength1Violin, sideLength2Violin,sideLength3Violin;

    const int WIDTH = 640;
    const int HEIGHT = 480;
    static const int MAX_OBJECTS = 15;
    //minimum and maximum object area
    const int MIN_OBJECT_AREA = 15*15;
    const int MAX_OBJECT_AREA = HEIGHT*WIDTH / 2;
    int x1Bow = 0, y1Bow = 0, x2Bow = 0, y2Bow = 0;
    int x1Violin = 0, y1Violin = 0, x2Violin = 0, y2Violin = 0, x3Violin = 0, y3Violin = 0;

private slots:

    void morphObject(cv::Mat &thresh);
    void drawBow(int x1, int y1,int x2, int y2, cv::Mat cameraframe, bool object2Found);
    void trackBow(int &x1Bow, int &y1Bow, int &x2Bow, int &y2Bow, cv::Mat thresholdTrack, cv::Mat cameraFeed);
    void drawViolin(int x1, int y1,int x2, int y2, int x3, int y3, cv::Mat cameraframe, bool object2Found, bool object3Found);
    void trackViolin(int &x1Violin, int &y1Violin, int &x2Violin, int &y2Violin, int &x3Violin, int &y3Violin, cv::Mat thresholdTrack, cv::Mat cameraFeed);



    std::string numberToString(int number);

private:
    Ui::choosingAndTrack *ui;
};


#endif // choosingAndTrack_H
