#include "colordetection.h"
#include "ui_colordetection.h"

colorDetection::colorDetection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::colorDetection)
{
    ui->setupUi(this);
}

colorDetection::~colorDetection()
{
    delete ui;
}

using namespace cv;
using namespace std;

extern int typeofMarker;

Vec3b maxcolor0;
Vec3b maxcolor1;
Vec3b maxcolor2;

Vec3b maxcolor0BOW;
Vec3b maxcolor1BOW;
Vec3b maxcolor2BOW;

Vec3b maxcolor0VIOLIN;
Vec3b maxcolor1VIOLIN;
Vec3b maxcolor2VIOLIN;

struct lessVec3b
{
    bool operator()( const Vec3b& lhs,  const Vec3b& rhs) const {
        return (lhs[0] != rhs[0]) ? (lhs[0] < rhs[0]) : ((lhs[1] != rhs[1]) ? (lhs[1] < rhs[1]) : (lhs[2] < rhs[2]));
        }
    };

    map<Vec3b, int, lessVec3b> getPalette(const Mat3b& src)
    {
        map<Vec3b, int, lessVec3b> palette;
        for (int r = 0; r < src.rows; ++r)
        {
            for (int c = 0; c < src.cols; ++c)
            {
                Vec3b color = src(r, c);
                if (palette.count(color) == 0)
                {
                    palette[color] = 1;
                }
                else
                {
                    palette[color] = palette[color] + 1;
                }
            }
        }
        return palette;
    }

    void reduceColor_Quantization(const Mat3b& src, Mat3b& dst)
    {
        uchar N = 64;
        dst = src / N;
        dst *= N;
    }

    void reduceColor_kmeans(const Mat3b& src, Mat3b& dst)
    {
        int K = 8;
        int n = src.rows * src.cols;
        Mat data = src.reshape(1, n);
        data.convertTo(data, CV_32F);

        vector<int> labels;
        Mat1f colors;
        kmeans(data, K, labels, cv::TermCriteria(), 1, cv::KMEANS_PP_CENTERS, colors);

        for (int i = 0; i < n; ++i)
        {
            data.at<float>(i, 0) = colors(labels[i], 0);
            data.at<float>(i, 1) = colors(labels[i], 1);
            data.at<float>(i, 2) = colors(labels[i], 2);
        }

        Mat reduced = data.reshape(3, src.rows);
        reduced.convertTo(dst, CV_8U);
    }

    void reduceColor_Stylization(const Mat3b& src, Mat3b& dst)
    {
        stylization(src, dst);
    }

    void reduceColor_EdgePreserving(const Mat3b& src, Mat3b& dst)
    {
        edgePreservingFilter(src, dst);
    }

    void colorDetection::on_pushButton_clicked()
    {
        DetectionOfColors();
    }

    void colorDetection::on_color0Button_clicked()
    {
        if(typeofMarker == 0 ){
            PassTheColorDetectedOnButtonClicked(maxcolor0BOW);
        }else{
            PassTheColorDetectedOnButtonClicked(maxcolor0VIOLIN);
        }
    }

    void colorDetection::on_color1Button_clicked()
    {
        if(typeofMarker == 0 ){
            PassTheColorDetectedOnButtonClicked(maxcolor1BOW);
        }else{
            PassTheColorDetectedOnButtonClicked(maxcolor1VIOLIN);
        }
    }

    void colorDetection::on_color2Button_clicked()
    {
        if(typeofMarker == 0 ){
            PassTheColorDetectedOnButtonClicked(maxcolor2BOW);
        }else{
            PassTheColorDetectedOnButtonClicked(maxcolor2VIOLIN);
        }
    }

    void colorDetection::DetectionOfColors(){

        Mat3b img;

        if(typeofMarker == 0 ){
            img = imread("captureshotBOW.jpeg");
        }else{
            img = imread("captureshotVIOLIN.jpeg");
        }

        if ( img.data == NULL ){

            QMessageBox msgBox;
            msgBox.setText("No color detected!");
            msgBox.exec();

        } else {

            // Reduce color
            Mat3b reduced;

            //reduceColor_Quantization(img, reduced);
            reduceColor_kmeans(img, reduced);
            //reduceColor_Stylization(img, reduced);
            //reduceColor_EdgePreserving(img, reduced);
            imshow( "Original", img );                   // Show our image inside it.
            imshow( "Reduced", reduced );                   // Show our image inside it.

            // Get palette
            map<Vec3b, int, lessVec3b> palette = getPalette(reduced);

            // Print palette
            int area = img.rows * img.cols;
            int sizePalette = palette.size();
            Vec3b colorsOfPalette[sizePalette];
            float percentOfColor[sizePalette];

            Vec3b auxcolorsOfPalette[sizePalette];
            float auxpercentOfColor[sizePalette];

            int n=0;
            for (auto color : palette)
            {
                colorsOfPalette[n]=color.first;
                percentOfColor[n] = 100.f * float(color.second) / float(area);
                auxcolorsOfPalette[n]=color.first;
                auxpercentOfColor[n] = 100.f * float(color.second) / float(area);
                n++;
            }

            sort(percentOfColor,percentOfColor+sizePalette,greater<float>());

            //first detected color

            float* x0 = std::find(auxpercentOfColor, auxpercentOfColor + sizePalette, percentOfColor[0]);

            int y0 = distance (auxpercentOfColor,x0);

            maxcolor0=colorsOfPalette[y0];

            //Second color detected

            float* x1 = std::find(auxpercentOfColor, auxpercentOfColor + sizePalette, percentOfColor[1]);

            int y1 = distance (auxpercentOfColor,x1);

            maxcolor1=colorsOfPalette[y1];

            //Third color detected

            float* x2 = std::find(auxpercentOfColor, auxpercentOfColor + sizePalette, percentOfColor[2]);

            int y2 = distance (auxpercentOfColor,x2);

            maxcolor2=colorsOfPalette[y2];

            //First frame and label %

            QPalette palette0 = ui->frame->palette();
            QString percentStr0 = QString::number(percentOfColor[0], 'f', 2);
            ui->label->setText(percentStr0);

            Vec3b auxmaxcolor0 = maxcolor0[0];
            maxcolor0[0] = maxcolor0[2];
            maxcolor0[2] = auxmaxcolor0[0];// Turned from BGR to RGB

            palette0.setColor( backgroundRole(), QColor( maxcolor0[0], maxcolor0[1], maxcolor0[2] ) );

            ui->frame->setPalette(palette0);
            ui->frame->setAutoFillBackground(true);

            //Second frame and label %

            QPalette palette1 = ui->frame_2->palette();
            QString percentStr1 = QString::number(percentOfColor[1], 'f', 2);
            ui->label_2->setText(percentStr1);

            Vec3b auxmaxcolor1 = maxcolor1[0];
            maxcolor1[0] = maxcolor1[2];
            maxcolor1[2] = auxmaxcolor1[0];// Turned from BGR to RGB

            palette1.setColor( backgroundRole(), QColor( maxcolor1[0], maxcolor1[1], maxcolor1[2] ) );
            ui->frame_2->setPalette(palette1);
            ui->frame_2->setAutoFillBackground(true);

            //Third frame and label %

            QPalette palette2 = ui->frame_3->palette();
            QString percentStr2 = QString::number(percentOfColor[2], 'f', 2);
            ui->label_3->setText(percentStr2);

            Vec3b auxmaxcolor2 = maxcolor2[0];
            maxcolor2[0] = maxcolor2[2];
            maxcolor2[2] = auxmaxcolor2[0]; // Turned from BGR to RGB

            if(typeofMarker == false ){

                maxcolor0BOW = maxcolor0;
                maxcolor1BOW = maxcolor1;
                maxcolor2BOW = maxcolor2;

            }else{
                maxcolor0VIOLIN = maxcolor0;
                maxcolor1VIOLIN = maxcolor1;
                maxcolor2VIOLIN = maxcolor2;
            }

            palette2.setColor( backgroundRole(), QColor( maxcolor2[0], maxcolor2[1], maxcolor2[2]  ) );
            ui->frame_3->setPalette(palette2);
            ui->frame_3->setAutoFillBackground(true);
        }
    }
    void colorDetection::PassTheColorDetectedOnButtonClicked(Vec3b colorPassed){

        if (colorPassed==Vec3b {0,0,0}){
            QMessageBox msgBox;
            msgBox.setText("No color detected: please press Detect Colors BUTTON or detect colors on Detect Markers' button on Main Menu");
            msgBox.exec();
        }else{
            choosingAndTrack choosingAndTrack;
            choosingAndTrack.TrackColor(colorPassed);
            maxcolor0 = Vec3b {0,0,0}; //Restart variables!!
            maxcolor1 = Vec3b {0,0,0};
            maxcolor2 = Vec3b {0,0,0};
            this->close();
        }
    }
