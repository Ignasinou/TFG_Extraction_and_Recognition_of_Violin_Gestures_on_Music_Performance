#include "utilsgesturerecognition.h"
#include "ui_utilsgesturerecognition.h"
#include <time.h>

utilsGestureRecognition::utilsGestureRecognition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::utilsGestureRecognition)
{
    ui->setupUi(this);
}

utilsGestureRecognition::~utilsGestureRecognition()
{
    delete ui;
}


double DistanceTwoPoints(double x1, double y1, double x2, double y2)
{
    double x, y, distance;
    x = x2 - x1;
    y = y2 - y1;
    distance = pow(x,2) + pow(y,2);
    distance = sqrt(distance);
    return distance;
}

//Function to find angle with Sine rule
double otherAngleFind(double biggerAngle, double largestDistance, double smallDistance)
{
    double otherAngle;
    otherAngle = smallDistance *sin(biggerAngle*3.14159265/180);
    otherAngle = otherAngle/largestDistance;
    otherAngle = asin(otherAngle)*180.0 / M_PI;
    return otherAngle;
}

//Function to find angle opposite to largest side of triangle
double BiggerAngleFind(double largestDistance, double smallDistanceOne, double smallDistanceTwo)
{
    double biggerAngle;
    biggerAngle =  pow(smallDistanceOne,2) + pow(smallDistanceTwo, 2) - pow(largestDistance,2);
    biggerAngle = fabs(biggerAngle/(2*smallDistanceOne*smallDistanceTwo));
    biggerAngle = acos(biggerAngle)* 180.0 / M_PI;
    return biggerAngle;
}

//Calculate angle of triangle given three coordinates
void TriangleAngleCalculation(double x1, double y1, double x2, double y2, double x3, double y3, double angleArray[], double distanceArray[], double pointArray[])
{

    double dist1, dist2, dist3;
    double angle1, angle2, angle3;
    double total;




//    int largestLength = 0;
    dist1 = DistanceTwoPoints(x1, y1, x2, y2);
    dist2 = DistanceTwoPoints(x2, y2, x3, y3);
    dist3 = DistanceTwoPoints(x1, y1, x3, y3);


   cout<<"Distance"<<dist1<<"  "<<dist2<<"  "<<dist3;

   distanceArray[0] = 0;
   distanceArray[1] = 0;
   distanceArray[2] = 0;

    if(dist1>dist2 && dist1 > dist3)
    {
//        cout<<"dist1 is greater";

        if(dist2 < dist3){
            cout<<"dist2 small" << endl;

            distanceArray[0] = 0;
            distanceArray[1] = dist2;
            distanceArray[2] = 0;
            pointArray[0] = x2;
            pointArray[1] = y2;
            pointArray[2] = x3;
            pointArray[3] = y3;

        }if(dist3<dist2){
            cout<<"dist3 small" << endl;

            distanceArray[0] = 0;
            distanceArray[1] = 0;
            distanceArray[2] = dist3;

            pointArray[0] = x1;
            pointArray[1] = y1;
            pointArray[2] = x3;
            pointArray[3] = y3;
        }

        angle1 = BiggerAngleFind(dist1, dist2, dist3);
        angle2 = otherAngleFind(angle1, dist1, dist2);
        angle3 = otherAngleFind(angle1, dist1, dist3);

        //angle2 = OtherAngleFind(angle1, dist1, dist2);

        total=angle1+angle2+angle3;

        if(total <180)
        {
            angle1 = 180 - angle1;
        }
    }
    else if(dist2 > dist3 && dist2 > dist1)
    {
//        cout<<"dist2 is greater";

        if(dist1 < dist3){
            cout<<"dist1 small" << endl;

            distanceArray[0] = dist1;
            distanceArray[1] = 0;
            distanceArray[2] = 0;
            pointArray[0] = x1;
            pointArray[1] = y1;
            pointArray[2] = x2;
            pointArray[3] = y2;

        }if(dist3<dist1){
            cout<<"dist3 small" << endl;

            distanceArray[0] = 0;
            distanceArray[1] = 0;
            distanceArray[2] = dist3;

            pointArray[0] = x1;
            pointArray[1] = y1;
            pointArray[2] = x3;
            pointArray[3] = y3;
        }



        angle2 = BiggerAngleFind(dist2, dist1, dist3);
        angle1 = otherAngleFind(angle2, dist2, dist1);
        angle3 = otherAngleFind(angle2, dist2, dist3);

        total=angle1+angle2+angle3;

        if(dist3>dist1){

        }

        if(total <180)
        {
            angle2 = 180 - angle2;
        }
    }
    else
    {
//       cout<<"dist3 is greater";

        if(dist2 < dist1){
            cout<<"dist2 small" << endl;

            distanceArray[0] = 0;
            distanceArray[1] = dist2;
            distanceArray[2] = 0;
            pointArray[0] = x2;
            pointArray[1] = y2;
            pointArray[2] = x3;
            pointArray[3] = y3;

        }if(dist1<dist2){
            cout<<"dist1 small" << endl;

            distanceArray[0] = dist1;
            distanceArray[1] = 0;
            distanceArray[2] = 0;

            pointArray[0] = x1;
            pointArray[1] = y1;
            pointArray[2] = x2;
            pointArray[3] = y2;
        }

        angle3 = BiggerAngleFind(dist3, dist1, dist2);
        angle1 = otherAngleFind(angle3, dist3, dist1);
        angle2 = otherAngleFind(angle3, dist3, dist2);

        total=angle1+angle2+angle3;

        if(total <180)
        {
            angle3 = 180 - angle3;
        }
    }

//    cout<<endl<<"Angle Between First Point and Second Point = "<<angle3<<endl;
//    cout<<"Angle Between First Point and Third Point = "<<angle2<<endl;
//    cout<<"Angle Between Second Point and Third Point = "<<angle1<<endl;

    angleArray[0] = angle1;
    angleArray[1] = angle2;
    angleArray[2] = angle3;

}

void otherAngles(int i, int &indexAngle1, int &indexAngle2 ){
    if( i ==  0 ){
        indexAngle1 = 1;
        indexAngle2 = 2;
    }
    if ( i == 1 ){
        indexAngle1 = 0;
        indexAngle2 = 2;
    }
    if ( i == 2 ){
        indexAngle1 = 0;
        indexAngle2 = 1;
    }
}

void utilsGestureRecognition::visualFeedbackViolinPosition(double &a1,double &a2, double &a3,bool &isCorrectPos){

    isCorrectPos = 0;
    int width = 250;
    int height = 250;

    Mat visualFeedback( height, width, CV_8UC3, Scalar(169,169,169) ); // Background Windows

    double centerX = height/2 ;
    double centerY = width/2 ;

    circle(visualFeedback,Point(centerX,centerY),centerX,Scalar(200,200,200),-1,8,0);

    for (int r = 0; r <  150; r=r+25){
        circle(visualFeedback,Point(centerX,centerY),r,Scalar(255,255,255),1,8,0);
    }

    double threshold = 5.0; //Angle threshold
    double refAngle = 18.5; //Angle ref

    double thresholdGoodPos = 35.0;
    double refAngleAuxGoodPos = 75.0;

    double angleArray[3] = {a1,a2,a3};

    double auxAngle1, auxAngle2;
    int index1 = 0, index2 = 0;

//    cout << angleArray[0] << endl;
//   cout << angleArray[1]  << endl;
//    cout << angleArray[2]  << endl;

    for (int i = 0; i <= 2; i++){

        if ( (angleArray[i] <= refAngle + threshold) && (angleArray[i] >= refAngle - threshold) ){

            //cout << i << endl;
            otherAngles(i, index1, index2);

            auxAngle1 = angleArray[index1];
            auxAngle2 = angleArray[index2];

//            cout << auxAngle1 << endl;
//            cout << auxAngle2 << endl;

            if ( ((auxAngle1 <=  refAngleAuxGoodPos + thresholdGoodPos) && (auxAngle1 >= refAngleAuxGoodPos - thresholdGoodPos)) && ((auxAngle2 <=  refAngleAuxGoodPos + thresholdGoodPos) && (auxAngle2 >= refAngleAuxGoodPos - thresholdGoodPos)) ){
               cout << "GOOD POSITION" << endl;
               isCorrectPos = 1;
               //cout << " Number angle =  " << angleArray[i] << endl;

                   // NORMALIZATION

               double min = refAngle - threshold;
               double max = refAngle + threshold;

               double normAngle = (angleArray[i] - min) / (max - min);
               double rangeNorm = normAngle + 0.5;

               if (rangeNorm > 1){
                   rangeNorm = 1 - (rangeNorm - 1);
               }

               int circleRadius = rangeNorm * (height / 2);

               //cout << circleRadius << endl;

               circle(visualFeedback,Point(centerX,centerY),circleRadius,Scalar(200,213,48),-1,8,0);

            }
        }
        imshow("VisualFeedback",visualFeedback);
        moveWindow("VisualFeedback", 800, 500);
    }
}


void utilsGestureRecognition::angleDetection(int x1,int x2, int x3, int y1,int y2, int y3, int &isCorrect){

  double angle1 = 0.0, angle2 = 0.0, angle3 = 0.0;
  double angleArray[3] = { angle1, angle2, angle3 };
  double distanceArray[3] = { 0.0, 0.0, 0.0 };
  double pointsArray[4] = { 0.0, 0.0, 0.0, 0.0 };
  bool isCorrectPos;


  TriangleAngleCalculation(x1, y1, x2, y2, x3, y3, angleArray,distanceArray,pointsArray);
    // SOLAMENT FER LO DE SOTA SI REALMENT POT TROBARSE EL VIOLÍ EN UNA BONA POSICIÓ fer un return del trangle angle clac o ferho dins!


//  cout << "Angle 1  is " << angleArray[0] << endl;
//  cout << "Angle 2  is " << angleArray[1] << endl;
//  cout << "Angle 3  is " << angleArray[2] << endl;
  visualFeedbackViolinPosition(angleArray[0],angleArray[1],angleArray[2], isCorrectPos);
  int returnShortest = 0;
  isCorrect = isCorrectPos;





//  if(isCorrectPos == 1){

//      if(distanceArray[0] != 0){
//          returnShortest = 1;
//      }

//      if(distanceArray[1] != 0){
//          returnShortest = 2;
//      }

//      if(distanceArray[2] != 0){
//          returnShortest = 3;
//      }

//      if((distanceArray[0] == 0) && (distanceArray[1] == 0) && (distanceArray[2] == 0)){
//          returnShortest = 0;
//      }

      angle1 = angleArray[0];
      angle2 = angleArray[1];
      angle3 = angleArray[2];
  }
//}


void utilsGestureRecognition::visualFeedbackSkewness(double &angle){

    int width = 250;
        int height = 250;

        Mat visualFeedback2( height, width, CV_8UC3, Scalar(169,169,169) ); // Background Windows

        double centerX = height/2 ;
        double centerY = width/2 ;

        circle(visualFeedback2,Point(centerX,centerY),centerX,Scalar(200,200,200),-1,8,0);

        for (int r = 0; r <  150; r=r+25){
            circle(visualFeedback2,Point(centerX,centerY),r,Scalar(255,255,255),1,8,0);
        }

        double thSkewness = 35;
        double refSkewness = 90;

        if((angle <= (refSkewness+thSkewness)) && (angle >= (refSkewness - thSkewness))){

            double min = refSkewness - thSkewness;
            double max = refSkewness + thSkewness;

            double normAngle = (angle - min) / (max - min);
            double rangeNorm = normAngle + 0.5;

            if (rangeNorm > 1){
                rangeNorm = 1 - (rangeNorm - 1);
            }

            int circleRadius = rangeNorm * (height / 2);

            //cout << circleRadius << endl;

            circle(visualFeedback2,Point(centerX,centerY),circleRadius,Scalar(48,38,172),-1,8,0);

        }

        imshow("VisualFeedback2",visualFeedback2);
        moveWindow("VisualFeedback2", 500, 500);

}



double utilsGestureRecognition::calcAngle(Point p1, Point p2, Point p3, Point p4){

    double a = (float)p1.x - p2.x;
    double b = (float)p1.y - p2.y;
    double c = (float)p3.x - p4.x;
    double d = (float)p3.y - p4.y;

    double cos_angle , angle;
    double mag_v1 = sqrt(a*a + b*b);
    double mag_v2 = sqrt(c*c + d*d);

    cos_angle = (a*c + b*d) / (mag_v1 * mag_v2);
    angle = acos(cos_angle);
    angle = angle * 180.0 / 3.14159;	// convert to degrees ???
    //
    visualFeedbackSkewness(angle);
    return angle;


}




void utilsGestureRecognition::getFrameRate(VideoCapture video){

    double fps = video.get(CV_CAP_PROP_FPS);
        // If you do not care about backward compatibility
        // You can use the following instead for OpenCV 3
        // double fps = video.get(CAP_PROP_FPS);
        cout << "Frames per second using video.get(CV_CAP_PROP_FPS) : " << fps << endl;


        // Number of frames to capture
        int num_frames = 120;

        // Start and end times
        time_t start, end;

        // Variable for storing video frames
        Mat frame;

        cout << "Capturing " << num_frames << " frames" << endl ;

        // Start time
        time(&start);

        // Grab a few frames
        for(int i = 0; i < num_frames; i++)
        {
            video >> frame;
        }

        // End Time
        time(&end);

        // Time elapsed
        double seconds = difftime (end, start);
        cout << "Time taken : " << seconds << " seconds" << endl;

        // Calculate frames per second
        fps  = num_frames / seconds;
        cout << "Estimated frames per second : " << fps << endl;

}

