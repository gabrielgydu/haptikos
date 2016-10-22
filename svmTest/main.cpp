#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

#include "/home/pi/haptikos/svmTraining/bin12.hpp"
#include "/home/pi/haptikos/svmTraining/bin13.hpp"
#include "/home/pi/haptikos/svmTraining/bin23.hpp"
#include "/home/pi/haptikos/svmTraining/multi12.hpp"
#include "/home/pi/haptikos/svmTraining/multi13.hpp"
#include "/home/pi/haptikos/svmTraining/multi23.hpp"
#include "testData1.hpp"
#include "testData2.hpp"
#include "testData3.hpp"
#include "testDataBin1.hpp"
#include "testDataBin2.hpp"
#include "testDataBin3.hpp"

using namespace cv;

char steps[4][3] = {"", "12", "13", "23"};
int result[7][7] = {
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0}};
int sampleNumber = 16;
char binClassifier[200];
char multiClassifier[200];
char multiNeutralClassifier[200];
char resultFilename[200];
FILE *fp = NULL;
int cor=0, inc=0, tot=0;

int main()
{
    for(int step=1; step<=3; step++){

        CvSVM SVMBin;
        CvSVM SVM;
        CvSVM SVMMulti;
        Mat sampleMat;

        sprintf(binClassifier, "/home/pi/haptikos/svmTraining/bin%s.xml", steps[step]);
        sprintf(multiClassifier, "/home/pi/haptikos/svmTraining/multi%s.xml", steps[step]);
        sprintf(multiNeutralClassifier, "/home/pi/haptikos/svmTraining/multiNeutral%s.xml", steps[step]);
        SVMBin.load(binClassifier);
        SVM.load(multiClassifier);
        SVMMulti.load(multiNeutralClassifier);

        //Evaluate binary classification
        for(int k=0; k<70; k++){
            if(step==1)
                sampleMat = Mat(1, sampleNumber, CV_32FC1, dataBin3[k]);
            else if(step==2)
                sampleMat = Mat(1,sampleNumber, CV_32FC1, dataBin2[k]);
            else if(step==3)
                sampleMat = Mat(1,sampleNumber, CV_32FC1, dataBin1[k]);

            float response = SVMBin.predict(sampleMat);

            int row = (int) response;
            int col = (int)labelsBin[k];
            result[row][col]++;
        }
        std::ofstream resultFile;
        resultFile.open("resultBinary.csv", std::ios::app);
        resultFile << ";;;;;\n";
        resultFile << ";Neutra;Nao-neutra;\n";
        resultFile << "Neutra;" << result[1][1] << ";" << result[1][2] << "\n";
        resultFile << "Nao-neutra;" << result[2][1] << ";" << result[2][2] << "\n";
        resultFile << ";;;;;\n;;;;;\n";
        resultFile.close();

        for(int h=0; h<=8; h++)
        for(int l=0; l<=8; l++)
        result[h][l] = 0;

        //Evaluate multiclass without neutral classification
        for(int k=0; k<60; k++){
            if(step==1)
                sampleMat = Mat(1,sampleNumber, CV_32FC1, data3[k]);
            else if(step==2)
                sampleMat = Mat(1,sampleNumber, CV_32FC1, data2[k]);
            else if(step==3)
                sampleMat = Mat(1,sampleNumber, CV_32FC1, data1[k]);

            float response = SVM.predict(sampleMat);
            std::cout << response << "//" << labels[k] << std::endl;
            if(response == labels[k])
                cor++;
            else
                inc++;

            int row = (int) response;
            int col = (int)labels[k];
            result[row][col]++;


        }

        resultFile.open("resultMulticlass.csv", std::ios::app);
        /*resultFile << ";;;;;;;;;;;;;\n";
        resultFile << ";Raiva;Desgosto;Medo;Felicidade;Tristeza;Surpresa;\n";
        resultFile << "Raiva;" << result[1][1] << ";" << result[1][2] << ";"<< result[1][3] << ";"<< result[1][4] << ";" << result[1][5] << ";"<< result[1][6] << ";"<<"\n";
        resultFile << "Desgosto;" << result[2][1] << ";" << result[2][2] << ";"<< result[2][3] << ";"<< result[2][4] << ";" << result[2][5] << ";"<< result[2][6] << ";"<<"\n";
        resultFile << "Medo;" << result[3][1] << ";" << result[3][2] << ";"<< result[3][3] << ";"<< result[3][4] << ";" << result[3][5] << ";"<< result[3][6] << ";"<<"\n";
        resultFile << "Felicidade;" << result[4][1] << ";" << result[4][2] << ";"<< result[4][3] << ";"<< result[4][4] << ";" << result[4][5] << ";"<< result[4][6] <<";"<<"\n";
        resultFile << "Tristeza;" << result[5][1] << ";" << result[5][2] << ";"<< result[5][3] << ";"<< result[5][4] << ";" << result[5][5] << ";"<< result[5][6] << ";"<<"\n";
        resultFile << "Surpresa;" << result[6][1] << ";" << result[6][2] << ";"<< result[6][3] << ";"<< result[6][4] << ";" << result[6][5] << ";"<< result[6][6] << ";"<<"\n";
        resultFile << ";;;;;;;;;;;;;\n;;;;;;;;;;;;;\n";*/
        resultFile << ";;;;;;;;;;;;;\n";
        resultFile << ";Neutral;Raiva;Desgosto;Medo;Felicidade;Tristeza;Surpresa;\n";
        resultFile << "Neutral;" << result[1][1] << ";" << result[1][2] << ";"<< result[1][3] << ";"<< result[1][4] << ";" << result[1][5] << ";"<< result[1][6] << ";"<<result[1][7] <<"\n";
        resultFile << "Raiva;" << result[2][1] << ";" << result[2][2] << ";"<< result[2][3] << ";"<< result[2][4] << ";" << result[2][5] << ";"<< result[2][6] << ";"<<result[2][7] <<"\n";
        resultFile << "Desgosto;" << result[3][1] << ";" << result[3][2] << ";"<< result[3][3] << ";"<< result[3][4] << ";" << result[3][5] << ";"<< result[3][6] << ";"<<result[3][7] <<"\n";
        resultFile << "Medo;" << result[4][1] << ";" << result[4][2] << ";"<< result[4][3] << ";"<< result[4][4] << ";" << result[4][5] << ";"<< result[4][6] << ";"<<result[4][6] <<"\n";
        resultFile << "Felicidade;" << result[5][1] << ";" << result[5][2] << ";"<< result[5][3] << ";"<< result[5][4] << ";" << result[5][5] << ";"<< result[5][6] <<";"<<result[5][7] <<"\n";
        resultFile << "Tristeza;" << result[6][1] << ";" << result[6][2] << ";"<< result[6][3] << ";"<< result[6][4] << ";" << result[6][5] << ";"<< result[6][6] << ";"<<result[6][7] <<"\n";
        resultFile << "Surpresa;" << result[7][1] << ";" << result[7][2] << ";"<< result[7][3] << ";"<< result[7][4] << ";" << result[7][5] << ";"<< result[7][6] << ";"<<result[7][7] <<"\n";
        resultFile << ";;;;;;;;;;;;;\n;;;;;;;;;;;;;\n";
        resultFile.close();

        for(int h=0; h<=8; h++)
        for(int l=0; l<=8; l++)
        result[h][l] = 0;

        //Evaluate multiclass with neutral classification
        for(int k=0; k<70; k++){
            if(step==1)
                sampleMat = Mat(1,sampleNumber, CV_32FC1, dataBin3[k]);
            else if(step==2)
                sampleMat = Mat(1,sampleNumber, CV_32FC1, dataBin2[k]);
            else if(step==3)
                sampleMat = Mat(1,sampleNumber, CV_32FC1, dataBin1[k]);

            float response = SVMMulti.predict(sampleMat);

            int row = (int) response;
            int col = (int)labelsMulti[k];
            result[row][col]++;
        }

        resultFile.open("resultMulticlass.csv", std::ios::app);
        resultFile << ";;;;;;;;;;;;;\n";
        resultFile << ";Neutral;Raiva;Desgosto;Medo;Felicidade;Tristeza;Surpresa;\n";
        resultFile << "Neutral;" << result[1][1] << ";" << result[1][2] << ";"<< result[1][3] << ";"<< result[1][4] << ";" << result[1][5] << ";"<< result[1][6] << ";"<<result[1][7] <<"\n";
        resultFile << "Raiva;" << result[2][1] << ";" << result[2][2] << ";"<< result[2][3] << ";"<< result[2][4] << ";" << result[2][5] << ";"<< result[2][6] << ";"<<result[2][7] <<"\n";
        resultFile << "Desgosto;" << result[3][1] << ";" << result[3][2] << ";"<< result[3][3] << ";"<< result[3][4] << ";" << result[3][5] << ";"<< result[3][6] << ";"<<result[3][7] <<"\n";
        resultFile << "Medo;" << result[4][1] << ";" << result[4][2] << ";"<< result[4][3] << ";"<< result[4][4] << ";" << result[4][5] << ";"<< result[4][6] << ";"<<result[4][6] <<"\n";
        resultFile << "Felicidade;" << result[5][1] << ";" << result[5][2] << ";"<< result[5][3] << ";"<< result[5][4] << ";" << result[5][5] << ";"<< result[5][6] <<";"<<result[5][7] <<"\n";
        resultFile << "Tristeza;" << result[6][1] << ";" << result[6][2] << ";"<< result[6][3] << ";"<< result[6][4] << ";" << result[6][5] << ";"<< result[6][6] << ";"<<result[6][7] <<"\n";
        resultFile << "Surpresa;" << result[7][1] << ";" << result[7][2] << ";"<< result[7][3] << ";"<< result[7][4] << ";" << result[7][5] << ";"<< result[7][6] << ";"<<result[7][7] <<"\n";
        resultFile << ";;;;;;;;;;;;;\n;;;;;;;;;;;;;\n";
        resultFile.close();

        for(int h=0; h<=8; h++)
        for(int l=0; l<=8; l++)
        result[h][l] = 0;
    }
    tot=cor+inc;
    std::cout << "Result: " << cor << "//" << inc << "// total "<<tot << std::endl;
    waitKey(0);

}
