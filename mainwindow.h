#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>

#include <iostream>
#include<vector>
#include <map>
#include <algorithm>
#include <QMessageBox>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/photo.hpp"
#include "opencv2/opencv.hpp"

#include "markers.h"
#include "colordetection.h"
#include "choosingAndTrack.h"
#include "utilsgesturerecognition.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_detectMarkers_clicked();

    void on_intWebCam_toggled(bool checked);

    void on_extWebCam_toggled(bool checked);

    void on_load_clicked();

    void on_tracking_clicked();

    void on_ViewColors_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
