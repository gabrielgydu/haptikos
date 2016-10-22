#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bin12.hpp"
#include "bin13.hpp"
#include "bin23.hpp"
#include "multi12.hpp"
#include "multi13.hpp"
#include "multi23.hpp"
#include "labels.hpp"

using namespace cv;

CvSVMParams params;
char steps[4][3] = {"", "12", "13", "23"};
char svmFilename[200];
int sampleNumber = 16;

void svmParameters(bool isLinear);

int main()
{
    Mat labelsMat(120, 1, CV_32FC1, labels);
    Mat labelsBinMat(140, 1, CV_32FC1, labelsBin);
    Mat labelsMultiMat(140, 1, CV_32FC1, labelsMulti);
    Mat dataMat;
    Mat dataBinMat;

    for(int step=1; step<=3; step++){
        if(step==1){
            dataMat = Mat(120, sampleNumber, CV_32FC1, data12);
            dataBinMat = Mat(140, sampleNumber, CV_32FC1, dataBin12);
        }else if(step==2){
            dataMat = Mat(120, sampleNumber, CV_32FC1, data13);
            dataBinMat = Mat(140, sampleNumber, CV_32FC1, dataBin13);
        }else if(step==3){
            dataMat = Mat(120, sampleNumber, CV_32FC1, data23);
            dataBinMat = Mat(140, sampleNumber, CV_32FC1, dataBin23);
        }
        //Binary training
        CvSVM SVMBin;
        SVMBin.train_auto(dataBinMat, labelsBinMat, Mat(), Mat(), params, 20, CvSVM::get_default_grid(CvSVM::C), CvSVM::get_default_grid(CvSVM::GAMMA), CvSVM::get_default_grid(CvSVM::P), CvSVM::get_default_grid(CvSVM::NU), CvSVM::get_default_grid(CvSVM::COEF), CvSVM::get_default_grid(CvSVM::DEGREE), true);
        //SVMBin.train_auto(dataBinMat, labelsBinMat, Mat(), Mat(), params);
        sprintf(svmFilename, "bin%s.xml", steps[step]);
        SVMBin.save(svmFilename);

        //Multiclass training
        CvSVM SVM;
        SVM.train_auto(dataMat, labelsMat, Mat(), Mat(), params);
        //SVM.train_auto(dataMat, labelsMat, Mat(), Mat(), params, 20, CvSVM::get_default_grid(CvSVM::C), CvSVM::get_default_grid(CvSVM::GAMMA), CvSVM::get_default_grid(CvSVM::P), CvSVM::get_default_grid(CvSVM::NU), CvSVM::get_default_grid(CvSVM::COEF), CvSVM::get_default_grid(CvSVM::DEGREE), false);
        sprintf(svmFilename, "multi%s.xml", steps[step]);
        SVM.save(svmFilename);

        //Multiclass training
        CvSVM SVMMulti;
        SVMMulti.train_auto(dataBinMat, labelsMultiMat, Mat(), Mat(), params);
        //SVMMulti.train_auto(dataBinMat, labelsMultiMat, Mat(), Mat(), params, 20, CvSVM::get_default_grid(CvSVM::C), CvSVM::get_default_grid(CvSVM::GAMMA), CvSVM::get_default_grid(CvSVM::P), CvSVM::get_default_grid(CvSVM::NU), CvSVM::get_default_grid(CvSVM::COEF), CvSVM::get_default_grid(CvSVM::DEGREE), false);
        sprintf(svmFilename, "multiNeutral%s.xml", steps[step]);
        SVMMulti.save(svmFilename);
    }
    waitKey(0);

}

void svmParameters(bool isLinear){
    params.svm_type    = CvSVM::C_SVC;
    if(isLinear)
        params.kernel_type = CvSVM::LINEAR;
    else
        params.kernel_type = CvSVM::RBF;
        params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);
}
