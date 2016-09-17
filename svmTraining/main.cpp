#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "svm_data_bin.hpp"

using namespace cv;

int main()
{
    Mat labelsMat(1727, 1, CV_32FC1, labelsBin);
    Mat trainingDataMat(1727, 10, CV_32FC1, trainingDataBin);
    // Set up SVM's parameters
    CvSVMParams params;
    params.svm_type    = CvSVM::C_SVC;
    //params.kernel_type = CvSVM::LINEAR;
    params.kernel_type = CvSVM::RBF;
    params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);

    // Train the SVM
    CvSVM SVM;
    SVM.train_auto(trainingDataMat, labelsMat, Mat(), Mat(), params);
    SVM.save("binary.xml");
    waitKey(0);

}
