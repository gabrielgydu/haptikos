#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "svm_data_mug.hpp"

using namespace cv;

int main()
{
    Mat labelsMat(224, 1, CV_32FC1, labels2);
    Mat trainingDataMat(224, 11, CV_32FC1, trainingData);
    // Set up SVM's parameters
    CvSVMParams params;
    params.svm_type    = CvSVM::C_SVC;
    //params.kernel_type = CvSVM::LINEAR;
    params.kernel_type = CvSVM::RBF;
    params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);

    // Train the SVM
    CvSVM SVM;
    SVM.train_auto(trainingDataMat, labelsMat, Mat(), Mat(), params);
    SVM.save("unilayer_mug.xml");
    //Mat sampleMat = (Mat_<float>(1,2) << i,j);
    //float sample[1][11] = {43.05, 71.03, 64.76, 64.33, 19.00, 12.04, 31.02};//last non-neutral from training
    //float sample[1][11] = {29.15, 45.04, 60.02, 58.22, 15.03, 14.04, 29.07, 4.12, 22.09, 13.00, 13.15};//neutral
   // float sample[1][11] = {69.07, 68.01, 127.02, 131.00, 32.02, 27.02, 59.03, 7.00, 49.16, 26.40, 26.57};
    //Mat sampleMat(1,11, CV_32FC1, sample);
    //float response = SVM.predict(sampleMat);
   /* if (response == -1)
        printf("Neutral\n");
    else if (response == 1)
        printf("Angry\n");//happy
    else if (response == 2)
        printf("Happy\n");//angry
    else if (response == 3)
        printf("Sad\n");//angry
    else if (response == 4)
        printf("Surprised\n");//angry*/
        /*if (response == 1)
        printf("Neutral\n");
    else if (response == -1)
        printf("Non-Neutral\n");*/
    waitKey(0);

}
