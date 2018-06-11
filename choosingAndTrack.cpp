#include "choosingAndTrack.h"
#include "ui_choosingAndTrack.h"

using namespace cv;
using namespace std;

choosingAndTrack::choosingAndTrack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choosingAndTrack)
{
    ui->setupUi(this);
}

choosingAndTrack::~choosingAndTrack()
{
    delete ui;

}

int xLast, yLast = -1; // Change this to improve optimization (?)

extern int typeofMarker;
extern bool captureViolinMarker;

Vec3b BowColorToTrack;
Vec3b ViolinColorToTrack;

Mat3b hsvcolorBow;
Mat3b hsvcolorViolin;

void choosingAndTrack::TrackColor(Vec3b color){ //Rebem el color que ha detectat el kmeans

    if(typeofMarker == 0 ){

        BowColorToTrack = color;
        typeofMarker = 1;

    }else{

        ViolinColorToTrack = color;

        cout << "Bow color to track: "  << BowColorToTrack << endl;
        cout << "Violin color to track: "  << ViolinColorToTrack << endl;

    }
}

Vec3b choosingAndTrack::getViolinColor(){
    return ViolinColorToTrack;
}


Vec3b choosingAndTrack::getBowColor(){
    return BowColorToTrack;
}


void choosingAndTrack::Tracking(){ //Obertura de la camara i tracking

    if ((BowColorToTrack==Vec3b {0,0,0}) || (ViolinColorToTrack==Vec3b {0,0,0})){
        QMessageBox msgBox;
        msgBox.setText("No colors detected, please press Detect Markers first");
        msgBox.exec();

    }else{

        Mat3b rgbcolorBow(BowColorToTrack);
        Mat3b rgbcolorViolin(ViolinColorToTrack);

        cvtColor(rgbcolorBow,hsvcolorBow,CV_RGB2HSV);
        cvtColor(rgbcolorViolin,hsvcolorViolin,CV_RGB2HSV);

        extern int webcamNum;

        VideoCapture capture(webcamNum);

        if (!capture.isOpened()) { //check if video device has been initialised
            QMessageBox msgBox;
            msgBox.setText("No webcam detected");
            msgBox.exec();
        }else{
            namedWindow("Webcam", 0); //create a window called "Control"

            if (!capture.isOpened()) { //check if video device has been initialised
                cout << "cannot open camera"<<endl;
            }
            namedWindow("MASK");
            namedWindow("HSV");

            moveWindow("MASK", 650,0);
            moveWindow("HSV",650,0);

            int threshBow = 50;
            //        int threshViolin = 50;  one threshold (thresholdBow) for the two markers, slow if 2.

            while(true){

                Mat cameraFrame, hsvCameraFrame;
                capture.set(CV_CAP_PROP_FRAME_WIDTH,640);
                capture.set(CV_CAP_PROP_FRAME_HEIGHT,480);
                capture.read(cameraFrame);
                createTrackbar("sensTracking Bow","Webcam",&threshBow,255); //Max sense 255!!
                //            createTrackbar("sensTracking Violin","Webcam",&threshViolin,255); //Max sense 255!! one threshold (thresholdBow) for the two markers, slow if 2.

                cvtColor(cameraFrame,hsvCameraFrame, CV_BGR2HSV); //BGR OR RGB??

//                utilsGestureRecognition ugR;
//                ugR.getFrameRate(capture);

                Vec3b hsvVectorBow = *hsvcolorBow[0];
                Vec3b hsvVectorViolin = *hsvcolorViolin[0];

                // one threshold (thresholdBow) for the two markers, slow if 2.
                Scalar minHSVViolin = Scalar(hsvVectorViolin.val[0] - threshBow, hsvVectorViolin.val[1] - threshBow , hsvVectorViolin.val[2] - threshBow);
                Scalar maxHSVViolin = Scalar(hsvVectorViolin.val[0] + threshBow, hsvVectorViolin.val[1] + threshBow, hsvVectorViolin.val[2] + threshBow);

                Scalar minHSVBow = Scalar(hsvVectorBow.val[0] - threshBow, hsvVectorBow.val[1] - threshBow , hsvVectorBow.val[2] - threshBow);
                Scalar maxHSVBow = Scalar(hsvVectorBow.val[0] + threshBow, hsvVectorBow.val[1] + threshBow, hsvVectorBow.val[2] + threshBow);


                if((minHSVViolin[0]) < 0){
                    minHSVViolin[0] = 0;
                }
                if((minHSVViolin[1]) < 0){
                    minHSVViolin[1] = 0;
                }
                if((minHSVViolin[2]) < 0){
                    minHSVViolin[2] = 0;
                }

                if((maxHSVViolin[0]) > 179){
                    maxHSVViolin[0] = 179;
                }
                if((maxHSVViolin[1]) > 255){
                    maxHSVViolin[1] = 255;
                }
                if((maxHSVViolin[2]) > 255){
                    maxHSVViolin[2] = 255;
                }

                if((minHSVBow[0]) < 0){
                    minHSVBow[0] = 0;
                }
                if((minHSVBow[1]) < 0){
                    minHSVBow[1] = 0;
                }
                if((minHSVBow[2]) < 0){
                    minHSVBow[2] = 0;
                }

                if((maxHSVBow[0]) > 179){
                    maxHSVBow[0] = 179;
                }
                if((maxHSVBow[1]) > 255){
                    maxHSVBow[1] = 255;
                }
                if((maxHSVBow[2]) > 255){
                    maxHSVBow[2] = 255;
                }

                Mat maskHSVBow, maskHSVViolin, resultHSV, finalmask;
                inRange(hsvCameraFrame, minHSVBow, maxHSVBow, maskHSVBow);
                inRange(hsvCameraFrame,minHSVViolin, maxHSVViolin, maskHSVViolin);
                morphObject(maskHSVViolin);
                morphObject(maskHSVBow);
                trackBow(x1Bow, y1Bow, x2Bow, y2Bow, maskHSVBow, cameraFrame);
                trackViolin(x1Violin, y1Violin, x2Violin, y2Violin,x3Violin, y3Violin, maskHSVViolin, cameraFrame);

                bitwise_or(maskHSVBow,maskHSVViolin,finalmask);
                bitwise_and(cameraFrame, cameraFrame, resultHSV, finalmask);

                imshow("HSV", resultHSV);
                imshow("MASK",finalmask);
                imshow("Webcam", cameraFrame);

                if (waitKey(1) == 27 ){
                    break;
                }
            }
            capture.release();
            destroyAllWindows();
        }
    }
}

void choosingAndTrack::morphObject(Mat &thresh){

    //create structuring element that will be used to "dilate" and "erode" image.
    //the element chosen here is a 3px by 3px rectangle
    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(3, 3));
    //dilate with larger element so make sure object is nicely visible
    Mat dilateElement = getStructuringElement(MORPH_RECT, Size(8, 8));

    erode(thresh, thresh, erodeElement);
    erode(thresh, thresh, erodeElement);
    dilate(thresh, thresh, dilateElement);
    dilate(thresh, thresh, dilateElement);
}

string choosingAndTrack::numberToString(int number){

    std::stringstream ss;
    ss << number;
    return ss.str();
}

void choosingAndTrack::drawBow(int x1, int y1, int x2, int y2, Mat cameraframe, bool object2Found){


    rectangle(cameraframe,Point(x1-(sideLength1Bow/2),y1-(sideLength1Bow/2)), Point(x1+(sideLength1Bow/2),y1+(sideLength1Bow/2)),Scalar(BowColorToTrack[2],BowColorToTrack[1],BowColorToTrack[0]),2); //RGB -> GRB
    putText(cameraframe, " x = " + numberToString(x1) + " y = " + numberToString(y1), Point(x1, y1 + 30), 1, 1, Scalar(0,0, 0), 1);

    if (object2Found == true){
        rectangle(cameraframe,Point(x2-(sideLength2Bow/2),y2-(sideLength2Bow/2)), Point(x2+(sideLength2Bow/2),y2+(sideLength2Bow/2)),Scalar(BowColorToTrack[2],BowColorToTrack[1],BowColorToTrack[0]),2);
        putText(cameraframe, " x = " + numberToString(x2) + "y = " + numberToString(y2), Point(x2, y2 + 30), 1, 1, Scalar(0,0, 0), 1);

        line(cameraframe, Point(x1, y1), Point(x2, y2), Scalar(255,0,0), 2);
//        double midPointX = ((x1+x2)/2.0);
//        double midPointY = ((y1+y2)/2.0);

//        circle(cameraframe,Point(midPointX,midPointY),5,Scalar(0,100,100),7);
    }
}
double DistanceTwoPoints2(double x1, double y1, double x2, double y2)
{
    double x, y, distance;
    x = x2 - x1;
    y = y2 - y1;
    distance = pow(x,2) + pow(y,2);
    distance = sqrt(distance);
    return distance;
}
double cross(Point v1,Point v2){
    return v1.x*v2.y - v1.y*v2.x;
}

bool getIntersectionPoint(Point a1, Point a2, Point b1, Point b2, Point & intPnt){
    Point p = a1;
    Point q = b1;
    Point r(a2-a1);
    Point s(b2-b1);

    if(cross(r,s) == 0) {return false;}

    double t = cross(q-p,s)/cross(r,s);

    intPnt = p + t*r;
    return true;
}





void choosingAndTrack::drawViolin(int x1, int y1,int x2, int y2, int x3, int y3, cv::Mat cameraframe, bool object2Found, bool object3Found){

    rectangle(cameraframe,Point(x1-(sideLength1Violin/2),y1-(sideLength1Violin/2)), Point(x1+(sideLength1Violin/2),y1+(sideLength1Violin/2)),Scalar(ViolinColorToTrack[2], ViolinColorToTrack[1], ViolinColorToTrack[0]),2);
    putText(cameraframe, " x = " + numberToString(x1) + " y = " + numberToString(y1), Point(x1, y1 + 30), 1, 1, Scalar(255, 0, 0), 1);

    if (object2Found == true){
        rectangle(cameraframe,Point(x2-(sideLength1Violin/2),y2-(sideLength1Violin/2)), Point(x2+(sideLength1Violin/2),y2+(sideLength1Violin/2)),Scalar(ViolinColorToTrack[2], ViolinColorToTrack[1], ViolinColorToTrack[0]),2);
        putText(cameraframe, " x = " + numberToString(x2) + "y = " + numberToString(y2), Point(x2, y2 + 30), 1, 1, Scalar(0,255, 0), 1);
    }

    if (object3Found == true){
        rectangle(cameraframe,Point(x3-(sideLength1Violin/2),y3-(sideLength1Violin/2)), Point(x3+(sideLength1Violin/2),y3+(sideLength1Violin/2)),Scalar(ViolinColorToTrack[2], ViolinColorToTrack[1], ViolinColorToTrack[0]),2);
        putText(cameraframe, " x = " + numberToString(x3) + "y = " + numberToString(y3), Point(x3, y3 + 30), 1, 1, Scalar(0, 0,255), 1);

        Point trainglePoints[1][3];
        trainglePoints[0][0] = Point (x1,y1);
        trainglePoints[0][1] = Point (x2,y2);
        trainglePoints[0][2] = Point (x3,y3);

        const Point* ppt[1] = { trainglePoints[0] };
        int npt[] = { 3 };

        fillPoly(cameraframe,ppt,npt,1,Scalar(255,255,255),8);
        int isCorrect;
        utilsGestureRecognition ug;
        ug.angleDetection(x1Violin,x2Violin,x3Violin,y1Violin,y2Violin,y3Violin,isCorrect);
        cout << "isCorrect"<<isCorrect << endl;

if(isCorrect == 1){
        double distance12 = DistanceTwoPoints2(x1Violin,y1Violin,x2Violin,y2Violin);
        double distance23 = DistanceTwoPoints2(x2Violin,y2Violin,y3Violin,y3Violin);
        double distance13 = DistanceTwoPoints2(x1Violin,y1Violin,x3Violin,y3Violin);

        if((distance12 < distance23) && (distance12 < distance13)){
//            line(cameraframe, Point(x1Violin, y1Violin), Point(x2Violin, y2Violin), Scalar(255,0,0), 2);

            double midPointXViolin = ((x1Violin+x2Violin)/2.0);
            double midPointYViolin = ((y1Violin+y2Violin)/2.0);

            line(cameraframe, Point(x3Violin, y3Violin), Point(midPointXViolin, midPointYViolin), Scalar(255,0,0), 2);

            Point violin1 = Point(x3Violin,y3Violin);
            Point violin2 = Point(midPointXViolin,midPointYViolin);

            Point bow1 = Point(x1Bow,y1Bow);
            Point bow2 = Point(x2Bow,y2Bow);
            Point intPoint;

            bool intersect = getIntersectionPoint(violin1,violin2,bow1,bow2,intPoint);
            circle(cameraframe,intPoint,5,Scalar(0,100,100),7);
            cout << "is this an intersection? "<< intersect << endl;

            utilsGestureRecognition utilsg;
            double angle = utilsg.calcAngle(violin1,violin2,bow1,bow2);
            cout << "Is this an angle? " << angle << endl;

        }
        if((distance23 < distance12) && (distance23 < distance13)){

//            line(cameraframe, Point(x2Violin, y2Violin), Point(x3Violin, y3Violin), Scalar(255,0,0), 2);

            double midPointXViolin = ((x2Violin+x3Violin)/2.0);
            double midPointYViolin = ((y2Violin+y3Violin)/2.0);

            line(cameraframe, Point(x1Violin, y1Violin), Point(midPointXViolin, midPointYViolin), Scalar(255,0,0), 2);

            Point violin1 = Point(x1Violin,y1Violin);
            Point violin2 = Point(midPointXViolin,midPointYViolin);

            Point bow1 = Point(x1Bow,y1Bow);
            Point bow2 = Point(x2Bow,y2Bow);
            Point intPoint;

            bool intersect = getIntersectionPoint(violin1,violin2,bow1,bow2,intPoint);
            circle(cameraframe,intPoint,5,Scalar(0,100,100),7);
            cout << "is this an intersection? "<< intersect << endl;

            utilsGestureRecognition utilsg;
            double angle = utilsg.calcAngle(violin1,violin2,bow1,bow2);
            cout << "Is this an angle? " << angle << endl;


        }
        if((distance13 < distance23) && (distance13 < distance12)){
            line(cameraframe, Point(x1Violin, y1Violin), Point(x3Violin, y3Violin), Scalar(255,0,0), 2);

            double midPointXViolin = ((x1Violin+x3Violin)/2.0);
            double midPointYViolin = ((y1Violin+y3Violin)/2.0);

            line(cameraframe, Point(x2Violin, y2Violin), Point(midPointXViolin, midPointYViolin), Scalar(255,0,0), 2);

            Point violin1 = Point(x2Violin,y2Violin);
            Point violin2 = Point(midPointXViolin,midPointYViolin);

            Point bow1 = Point(x1Bow,y1Bow);
            Point bow2 = Point(x2Bow,y2Bow);
            Point intPoint;

            bool intersect = getIntersectionPoint(violin1,violin2,bow1,bow2,intPoint);
            circle(cameraframe,intPoint,5,Scalar(0,100,100),7);
            cout << "is this an intersection? "<< intersect << endl;

            utilsGestureRecognition utilsg;
            double angle = utilsg.calcAngle(violin1,violin2,bow1,bow2);
            cout << "Is this an angle? " << angle << endl;

          }
       }
    }
}




void choosingAndTrack::trackBow(int &x1Bow, int &y1Bow, int &x2Bow, int &y2Bow, cv::Mat thresholdTrack, cv::Mat cameraFeed){

    Mat temp;
    thresholdTrack.copyTo(temp);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(temp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
    double refArea1 = 0, refArea2 = 0;
    bool findMark1 = false, findMark2 = false;

    if (hierarchy.size() > 0){
        int numObjects = hierarchy.size(); // Guardem el número d'objectes trobats

        if (numObjects < MAX_OBJECTS){ // Si tenim menos de max_objects vol dir que tenim una imatge neta i podem diferenciar bé els objectes
            //  EDIT: Poder hauria de ser com a molt 3 ja que sol busquem dos objectes!
            for (int index = 0; index >= 0; index = hierarchy[index][0]) {

                Moments moment1 = moments((Mat)contours[index]);
                area1Bow = moment1.m00;
                sideLength1Bow = sqrt(area1Bow);

                if (area1Bow > MIN_OBJECT_AREA && area1Bow <MAX_OBJECT_AREA){ // Filtro para objetos pequños o objetos muy grandes
                    x1Bow = moment1.m10 /area1Bow;
                    y1Bow = moment1.m01 /area1Bow;
                    findMark1 = true;
                    refArea1 = area1Bow;
                }else{
                    findMark2 = false;
                }
            }
            if (findMark1 == true && hierarchy[1][1] == 0){
                for (int index2 = 0; index2 >= 0; index2 = hierarchy[index2][1]){
                    Moments moment2 = moments ((Mat)contours[index2]);
                    area2Bow = moment2.m00;
                    sideLength2Bow = sqrt(area2Bow);
                    if ( area2Bow > MIN_OBJECT_AREA && area2Bow < MAX_OBJECT_AREA ){
                        x2Bow = moment2.m10 / area2Bow;
                        y2Bow = moment2.m01 / area2Bow;
                        findMark2 = true;
                        refArea2 = area2Bow;
                    }
                }
            }else{
                findMark2 = false;
            }
            drawBow(x1Bow,y1Bow, x2Bow,y2Bow,cameraFeed,findMark2);
        }
    }
}

void choosingAndTrack::trackViolin(int &x1Violin,int &y1Violin,int &x2Violin,int &y2Violin,int &x3Violin,int &y3Violin, Mat thresholdTrack, Mat cameraFeed){

    Mat temp;
    thresholdTrack.copyTo(temp);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(temp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
    double refArea1 = 0, refArea2 = 0, refArea3 = 0;
    bool findMark1 = false, findMark2 = false , findMark3 = false;

    if (hierarchy.size() > 0){
        int numObjects = hierarchy.size(); // Guardem el número d'objectes trobats
        if (numObjects < MAX_OBJECTS){ // Si tenim menos de max_objects vol dir que tenim una imatge neta i podem diferenciar bé els objectes
            //  EDIT: Poder hauria de ser com a molt 3 ja que sol busquem dos objectes!

            Moments moment1 = moments((Mat)contours[0]);
            area1Violin = moment1.m00;
            sideLength1Violin= sqrt(area1Violin);
            if (area1Violin > MIN_OBJECT_AREA && area1Violin <MAX_OBJECT_AREA){ // Filtro para objetos pequños o objetos muy grandes
                x1Violin = moment1.m10 /area1Violin;
                y1Violin = moment1.m01 /area1Violin;
                findMark1 = true;
                refArea1 = area1Violin;
            }else{
                findMark1 = false;
            }

            if ( (findMark1 == true) && (hierarchy.size() > 1) ){//(hierarchy[1][1] == 0)){
                Moments moment2 = moments ((Mat)contours[1]);
                area2Violin = moment2.m00;
                sideLength2Violin = sqrt(area2Violin);
                if ( area2Violin > MIN_OBJECT_AREA && area2Violin < MAX_OBJECT_AREA ){
                    x2Violin = moment2.m10 / area2Violin;
                    y2Violin = moment2.m01 / area2Violin;
                    findMark2 = true;
                    refArea2 = area2Violin;
                }else{
                    findMark2 = false;
                }

                if ( (findMark2 == true) && (hierarchy.size() > 2) ){

                    Moments moment3 = moments ((Mat)contours[2]);
                    area3Violin = moment3.m00;
                    sideLength3Violin = sqrt(area3Violin);
                    if( area3Violin > MIN_OBJECT_AREA && area3Violin < MAX_OBJECT_AREA ){
                        x3Violin = moment3.m10 / area3Violin;
                        y3Violin = moment3.m01 / area3Violin;
                        findMark3 = true;
                        refArea3 = area3Violin;
                    }else{
                        findMark3 = false;
                    }
                }
            }
            drawViolin(x1Violin,y1Violin, x2Violin,y2Violin, x3Violin,y3Violin,cameraFeed,findMark2, findMark3);
        }
    }
}
