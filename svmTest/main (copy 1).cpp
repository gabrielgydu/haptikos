#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "svm_data_bin.hpp"
#include "svm_data.hpp"

using namespace cv;

int anger=0, disgust=0, fear=0, happiness=0, sadness=0, surprise = 0, neutral=0;
int correct=0, incorrect=0, resp=0, label=0;
int expressions[7] = {0,0,0,0,0,0,0};
int cMatrix[7][7] = {{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0}};

float response=0;


int main()
{
    Mat labelsMat(1727, 1, CV_32FC1, labelsBin);
    Mat trainingDataMat(1727, 10, CV_32FC1, trainingDataBin);
    // Set up SVM's parameters
    /*CvSVMParams params;
    params.svm_type    = CvSVM::C_SVC;
    //params.kernel_type = CvSVM::LINEAR;
    params.kernel_type = CvSVM::RBF;
    params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);

    // Train the SVM
    CvSVM SVM;
    SVM.train_auto(trainingDataMat, labelsMat, Mat(), Mat(), params);
    SVM.save("binary.xml");


    waitKey(0);*/

    // Create SVM
    CvSVM SVM;
    CvSVM SVM2;
    // Load SVM data
    SVM.load("/home/gabriel/Dropbox/01 TC/dev/svmTraining/binary.xml");// 2-Class neutral/non-neutral
    SVM2.load("/home/gabriel/Dropbox/01 TC/dev/svmTraining/multiclass.xml");// 6-Class anger/disgust/fear/happiness/sadness/surprise

    for(int k =0; k<=838; k++){

            Mat sampleMat(1,10, CV_32FC1, trainingData[k]);
            //response = SVM.predict(sampleMat);




          /*if (response == 1){
                    if(response == labelsBin[k])
                correct++;
            else{
                incorrect++;
                }
            //printf("Neutral\n");
            expressions[0]++;
            cMatrix[0][(int)labels[k+888]]++;
          }else{*/

            response = SVM2.predict(sampleMat);
            //printf("%d \ %d\n", (int) response, (int)labels[k-888]);
            if(response == labels[k])
                correct++;
            else{
                incorrect++;
                }
            if (response == 1){
            cMatrix[1][(int)labels[k]]++;
                expressions[1]++;
                //printf("anger\n");
            }else if(response == 2){
            cMatrix[2][(int)labels[k]]++;
                //printf("disgust\n");
                expressions[2]++;
            }else if(response == 3){
            cMatrix[3][(int)labels[k]]++;
                //printf("fear\n");
                expressions[3]++;
            }else if(response == 4){
            cMatrix[4][(int)labels[k]]++;
               // printf("happiness\n");
                expressions[4]++;
            }else if(response == 5){
            cMatrix[5][(int)labels[k]]++;
                //printf("sadness\n");
                expressions[5]++;
            }else if(response == 6){
            cMatrix[6][(int)labels[k]]++;
                //printf("surprise\n");
                expressions[6]++;
            }

    }

    //}

    printf("Correct: %d - Incorrect: %d\n Anger: %d\n Disgust: %d\n Fear: %d\n Happiness: %d\n Sadness: %d\n Surprise: %d\n Neutral: %d\n", correct, incorrect, expressions[1], expressions[2], expressions[3], expressions[4], expressions[5], expressions[6], expressions[0]);
    for(int y=0; y<7; y++)
    printf("%03d, %03d, %03d, %03d, %03d, %03d, %03d \n", cMatrix[0][y], cMatrix[1][y], cMatrix[2][y], cMatrix[3][y], cMatrix[4][y], cMatrix[5][y], cMatrix[6][y]);

    char ch=getchar();
    waitKey(0);

}
