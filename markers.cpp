#include "markers.h"
#include "ui_markers.h"
#include "mainwindow.h"

using namespace cv;
using namespace std;

markers::markers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::markers)
{
    ui->setupUi(this);
}

markers::~markers()
{
    delete ui;
}

extern int typeofMarker=0;
extern int webcamNum;
extern bool messageflag = false;


void markers::on_bowMarkers_clicked()
{
    typeofMarker=0;
    cameraOnCapture(typeofMarker,webcamNum);
}

void markers::on_violinMarkers_clicked()
{
    typeofMarker=1;
    cameraOnCapture(typeofMarker,webcamNum);
}

void markers::cameraOnCapture(int typeofMarker, int webcamNum){

    VideoCapture capture(webcamNum);

    namedWindow("Webcam", 0); //create a window called "Control"

    if (!capture.isOpened()) { //check if video device has been initialised
        QMessageBox msgBox;
        msgBox.setText("No webcam detected");
        msgBox.exec();
    }else{

        int xRoi = 640;
        int yRoi = 0;
        int maxRect = 64;
        int indexRect = 24;

        while (true) {

            Mat cameraFrame, auxcameraFrame;
            capture.set(CV_CAP_PROP_FRAME_WIDTH,640);
            capture.set(CV_CAP_PROP_FRAME_HEIGHT,480);
            capture.read(cameraFrame);
            auxcameraFrame = cameraFrame.clone(); //Para que en la captura no salga el rectangulo verde!

            int hRoi = 75*(indexRect/16.0);
            int wRoi = 640-hRoi;

            createTrackbar("Rectangle Size","Webcam",&indexRect,maxRect); // maxRect = max and "steps"
            rectangle( cameraFrame, Point( xRoi, yRoi ), Point( wRoi, hRoi), Scalar( 0, 255, 0 ), +2,4);

            imshow("Webcam", cameraFrame);

            if (waitKey(1) == 27 ){
                break;
            }

            if(typeofMarker==0 && messageflag==false){ //BowMarkerscaption
                QMessageBox msgBox;
                msgBox.setText("Press SPACE to capture BOW's markers color inside the green square");
                msgBox.exec();
                messageflag=true;
            }

            if(typeofMarker==1 && messageflag==false){
                QMessageBox msgBox; //ViolinMarkerscaption
                msgBox.setText("Press SPACE to capture VIOLIN's markers color inside the green square");
                msgBox.exec();
                messageflag=true;

            }
            if (waitKey(1) == 32){

                Mat image = auxcameraFrame.clone();
                Rect rectRoi = Rect(wRoi, yRoi, xRoi - wRoi, hRoi); //rectangle i Rect no van igual!
                Mat imageRoi = image(rectRoi);

                if(typeofMarker==0){
                    imwrite("captureshotBOW.jpeg", imageRoi);
                    imwrite("originalCaptureBOW.jpeg",imageRoi);

                }else{
                    imwrite("captureshotVIOLIN.jpeg", imageRoi);
                    imwrite("originalCaptureVIOLIN.jpeg",imageRoi);
                }
                break;
            }

        }
        messageflag=false;
        capture.release();
        destroyAllWindows();

        colorDetection colordetection;
        colordetection.exec();

    }
}
