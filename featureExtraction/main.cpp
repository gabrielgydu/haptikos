#include <ctime>
#include <iostream>
#include <cctype>
#include <iterator>
#include <stdio.h>

#include <string.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include </home/pi/stasm/stasm/stasm_lib.h>
#include </home/pi/stasm/stasm/stasm.h>

using namespace cv;
using namespace stasm;
using namespace std;

char expressions[7][20] = {"anger", "disgust", "fear", "happiness", "neutral", "sadness", "surprise"};
int e=0;
int feature_counter=0;
char orig_filename[200];
char stasm_filename[200];
char txt_filename[200];
Mat img;
float baseline=0;
float features[9];
FILE *fp=NULL;
float landmarks[2 * stasm_NLANDMARKS]; // x,y coords (note the 2)


double extractFeature(float x1, float y1, float x2, float y2){
    double result;
    line(img, cvPoint(x1, y1), cvPoint(x2, y2), CV_RGB(255,255,255));
    // Euclidean distance
    result = (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))/baseline;
    if(feature_counter<9){
        fprintf(fp, "%.2f, ", result);
        features[feature_counter]=result;
        feature_counter++;
    }else{
        fprintf(fp, "%.2f}, \n", result);
        features[feature_counter]=result;
        feature_counter=0;
    }
    return result;
}

void extractFeatures(){
    fprintf(fp, "{");
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


int main(int argc, char *argv[])
{

    for(e = 0; e <= 6; e++){

    sprintf(txt_filename, "/home/pi/haptikos/data/features/%s_2.txt", expressions[e]);
    fp = fopen(txt_filename, "w");
                if(!fp)
                printf("ERROR opening %s\n", txt_filename);

        for(int s = 1; s<=52; s++){
            for(int take = 0; take<10; take++){
                sprintf(orig_filename, "/home/pi/haptikos/data/dataset/%s/%d_%03d.jpg", expressions[e], s, take);
                img = imread(orig_filename, CV_LOAD_IMAGE_GRAYSCALE);
                if(!img.empty()){
                    //printf("image found: %s \n", orig_filename);
                    int foundface;

                    if (!stasm_search_single(&foundface, landmarks, (const char*)img.data, img.cols, img.rows, "", "/home/pi/haptikos/data/stasm")){
                        printf("Error in stasm_search_single: %s\n", stasm_lasterr());
                    }

                    if (!foundface)
                        printf("No face found in %s\n", orig_filename);
                    else{
                        //stasm_force_points_into_image(landmarks, img.cols, img.rows);
                        //for (int i = 0; i < stasm_NLANDMARKS; i++)
                        //    line(img, cvPoint(landmarks[i*2], landmarks[i*2+1]), cvPoint(landmarks[i*2], landmarks[i*2+1]), CV_RGB(255,255,255));
                        extractFeatures();
                        }
                        sprintf(stasm_filename, "/home/pi/haptikos/data/dataset_stasm_2/%s/%d_%03d.jpg", expressions[e], s, take);
                        imwrite(stasm_filename, img);

                    }
            }
        }
        fclose(fp);
    }
    printf("\n DONE");
    waitKey(0);
    return 0;
}



