#include <ctime>
#include <iostream>
#include <raspicam/raspicam_cv.h>
#include <cctype>
#include <iterator>
#include <stdio.h>

/** OpenCV */
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/ml/ml.hpp>

/** Stasm */
#include <stasm_lib.h>
#include <stasm.h>

using namespace std;
using namespace cv;
using namespace stasm;

/** Global variables */
double res;
int n=0, p=0;
float baseline=0;
float features[9];
int feature_counter=0;

Mat image, img;
FILE *fp=NULL;
float landmarks[2 * stasm_NLANDMARKS]; // x,y coords (note the 2)


/** Function Headers */
void extractFeatures();
double extractFeature(float x1, float y1, float x2, float y2);

int main ( int argc,char **argv ) {

    // Create SVM
    CvSVM SVM;
    CvSVM SVM2;
    // Load SVM data
    SVM.load("binary.xml");// 2-Class neutral/non-neutral
    SVM2.load("multiclass.xml");// 6-Class anger/disgust/fear/happiness/sadness/surprise

    // Set up Camera
    raspicam::RaspiCam_Cv Camera;
    Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );
    Camera.set( CV_CAP_PROP_FRAME_WIDTH, 640);
    Camera.set( CV_CAP_PROP_FRAME_HEIGHT, 480);

    //Open camera
    cout<<"Opening Camera..."<<endl;
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return -1;}

    //Start capture
    cout<<"Capturing...."<<endl;
    for ( int i = 10; i < 20; i ) {
        Camera.grab();
        Camera.retrieve (img);
        flip(img, img, 0);

        if(img.empty()){
           printf(" --(!) No captured frame -- Break!"); break;
        }

        int foundface;
        if (!stasm_search_single(&foundface, landmarks, (const char*)img.data, img.cols, img.rows, "", "/home/pi/haptikos/data/stasm")){
            printf("Error in stasm_search_single: %s\n", stasm_lasterr());
        }

        if (foundface){
          for (int i = 0; i < stasm_NLANDMARKS; i++){
            line(img, cvPoint(landmarks[i*2], landmarks[i*2+1]), cvPoint(landmarks[i*2], landmarks[i*2+1]), CV_RGB(255,255,255));
          }

          extractFeatures();
          Mat sampleMat(1,10, CV_32FC1, features);
          float response = SVM.predict(sampleMat);

          if (response == 1){
            printf("Neutral\n");
            putText(img, "Neutra", cvPoint(30,30), FONT_HERSHEY_SIMPLEX, 1, CV_RGB(255,255,255));
          }else{
            response = SVM2.predict(sampleMat);
            if (response == 1){
                printf("anger\n");
                putText(img, "raiva", cvPoint(30,30), FONT_HERSHEY_SIMPLEX, 1, CV_RGB(255,255,255));
            }else if(response == 2){
                printf("disgust\n");
                putText(img, "desgosto", cvPoint(30,30), FONT_HERSHEY_SIMPLEX, 1, CV_RGB(255,255,255));
            }else if(response == 3){
                printf("fear\n");
                putText(img, "medo", cvPoint(30,30), FONT_HERSHEY_SIMPLEX, 1, CV_RGB(255,255,255));
            }else if(response == 4){
                printf("happiness\n");
                putText(img, "felicidade", cvPoint(30,30), FONT_HERSHEY_SIMPLEX, 1, CV_RGB(255,255,255));
            }else if(response == 5){
                printf("sadness\n");
                putText(img, "tristeza", cvPoint(30,30), FONT_HERSHEY_SIMPLEX, 1, CV_RGB(255,255,255));
            }else if(response == 6){
                printf("surprise\n");
                putText(img, "surpresa", cvPoint(30,30), FONT_HERSHEY_SIMPLEX, 1, CV_RGB(255,255,255));
            }
        }
        }
    char key = (char)waitKey(10); //delay N millis, usually long enough to display and capture input
    switch (key){
      case 'a':
        imwrite("image.jpg", img);
        break;
        case 'q':
        case 'Q':
        case 27: //escape key
          i = 40;
          break;
        default:
          break;
    }
        imshow("Image", img);
        img = Mat::zeros(Size(640,480), CV_8UC1);
    }
    fclose(fp);
    cout<<"Stop camera..."<<endl;
    Camera.release();
    waitKey(0);
}

double extractFeature(float x1, float y1, float x2, float y2){
    double result;
    line(img, cvPoint(x1, y1), cvPoint(x2, y2), CV_RGB(255,255,255));
    // Euclidean distance
    result = (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))/baseline;
    if(feature_counter<9){
        //fprintf(fp, "%.2f, ", result);
        features[feature_counter]=result;
        feature_counter++;
    }else{
        //fprintf(fp, "%.2f}, \n", result);
        features[feature_counter]=result;
        feature_counter=0;
    }
    return result;
}

void extractFeatures(){
    //fprintf(fp, "{");
    baseline=(sqrt(pow((landmarks[30*2+1] - landmarks[30*2]), 2) + pow((landmarks[40*2+1] - landmarks[40*2]), 2)));
    //printf("RCO - LCO: ");
    extractFeature(landmarks[65*2], landmarks[65*2+1], landmarks[59*2], landmarks[59*2+1]);
    //printf("RC - LCO: ");
    extractFeature(landmarks[30*2], landmarks[30*2+1], landmarks[59*2], landmarks[59*2+1]);
    //printf("LC - LCO: ");
    extractFeature(landmarks[65*2], landmarks[65*2+1], landmarks[40*2], landmarks[40*2+1]);
    //printf("ULip - LLip: ");
    extractFeature(landmarks[62*2], landmarks[62*2+1], landmarks[74*2], landmarks[74*2+1]);
    //printf("Sn - ULip: ");
    extractFeature(landmarks[56*2], landmarks[56*2+1], landmarks[62*2], landmarks[62*2+1]);
    //printf("Sn - LLip: ");
    extractFeature(landmarks[56*2], landmarks[56*2+1], landmarks[74*2], landmarks[74*2+1]);
    //printf("mULip - mLLip: ");
    extractFeature(landmarks[67*2], landmarks[67*2+1], landmarks[70*2], landmarks[70*2+1]);
    //printf("EBR - EBL: ");
    extractFeature(landmarks[21*2], landmarks[21*2+1], landmarks[22*2], landmarks[22*2+1]);
    //printf("EBR - RC: ");
    extractFeature(landmarks[21*2], landmarks[21*2+1], landmarks[30*2], landmarks[30*2+1]);
    //printf("EBL - LC: ");
    extractFeature(landmarks[22*2], landmarks[22*2+1], landmarks[40*2], landmarks[40*2+1]);
    for(int k=0; k<=9; k++)
    printf("%.2f, ", features[k]);
    printf("\n");
}
