#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

extern int webcamNum=1;


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_detectMarkers_clicked()
{
    markers detectMarkers;
    detectMarkers.exec();
}

void MainWindow::on_intWebCam_toggled(bool checked)
{
    if (checked == true){
        webcamNum=0;

    }
}

void MainWindow::on_extWebCam_toggled(bool checked)
{
    if (checked == true){
        webcamNum=1;
    }
}

void MainWindow::on_load_clicked()
{
    Mat imageBow = imread("captureshotBOW.jpeg");
    Mat imageViolin = imread("captureshotViolin.jpeg");

    if ((imageBow.data == NULL) && (imageViolin.data == NULL)){

        QMessageBox msgBox;
        msgBox.setText("Bow and Violin markers' color not captured yet");
        msgBox.exec();
    }else {
        if (imageBow.data == NULL){
            QMessageBox msgBox;
            msgBox.setText("Bow markers' color not captured yet");
            msgBox.exec();
        }else{
            if(imageViolin.data == NULL){
                QMessageBox msgBox;
                msgBox.setText("Violin markers' color not captured yet");
                msgBox.exec();
            }
        }
    }
    if ((imageViolin.data != NULL) && (imageBow.data != NULL)){
        colorDetection colordetection;
        colordetection.exec();
    }

}

void MainWindow::on_tracking_clicked()
{
    choosingAndTrack choosingandtrack;
    choosingandtrack.Tracking();

}

void MainWindow::on_ViewColors_clicked()
{
    choosingAndTrack cat;

    Vec3b colorViolin = cat.getViolinColor();
    Vec3b colorBow = cat.getBowColor();

    if (colorBow != Vec3b {0,0,0}){

        QPalette paletteBow = ui->BowColor->palette();
        paletteBow.setColor(backgroundRole(), QColor (colorBow[0],colorBow[1],colorBow[2]));
        ui->BowColor->setPalette(paletteBow);
        ui->BowColor->setAutoFillBackground(true);

    }
    if (colorViolin != Vec3b {0,0,0}){

        QPalette paletteViolin = ui->ViolinColor->palette();
        paletteViolin.setColor(backgroundRole(), QColor (colorViolin[0],colorViolin[1],colorViolin[2]));
        ui->ViolinColor->setPalette(paletteViolin);
        ui->ViolinColor->setAutoFillBackground(true);

    }
    if ((colorBow == Vec3b {0,0,0}) || (colorViolin == Vec3b {0,0,0})){
        QMessageBox msgBox;
        msgBox.setText("No colors detected!");
        msgBox.exec();
    }
}
