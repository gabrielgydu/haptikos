#include <ctime>
#include <iostream>
#include <cctype>
#include <iterator>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <opencv2/core/core.hpp>
#include <opencv2//imgproc/imgproc.hpp>
#include <opencv2//highgui/highgui.hpp>

#include <stasm_lib.h>
#include <stasm.h>

using namespace cv;
using namespace stasm;
using namespace std;

char expressions[7][20] = {"neutral", "anger", "disgust", "fear", "happiness", "sadness", "surprise"};
int e=0;
int feature_counter=0;
char orig_filename[200];
char stasm_filename[200];
char txt_filename[200];
Mat img;
float baseline=0;
float features[15];
FILE *fp=NULL;
float landmarks[2 * stasm_NLANDMARKS]; // x,y coords (note the 2)

double extractFeature(float x1, float y1, float x2, float y2);
void extractFeatures();
void setFiles();
void setFinalFiles();

int main(int argc, char *argv[]){
    setFiles();
    for(e = 0; e <= 6; e++){
        for(int conj = 1; conj<=3; conj++){
            sprintf(txt_filename, "/home/pi/haptikos/data/features/%s_%d.txt", expressions[e], conj);
            fp = fopen(txt_filename, "w");
            if(!fp)
                printf("ERROR opening %s\n", txt_filename);
            for(int s = 1; s<=52; s++){
                sprintf(orig_filename, "/home/pi/haptikos/data/MUGdataset/%s/%d/%d.jpg", expressions[e], conj, s);
                img = imread(orig_filename, CV_LOAD_IMAGE_GRAYSCALE);
                if(!img.empty()){
                cout << "Image: " << orig_filename << endl;
                    int foundface;
                    if (!stasm_search_single(&foundface, landmarks, (const char*)img.data, img.cols, img.rows, "", "/home/pi/haptikos/data/stasm"))
                        printf("Error in stasm_search_single: %s\n", stasm_lasterr());
                    if (!foundface)
                        printf("No face found in %s\n", orig_filename);
                    else{
                        //stasm_force_points_into_image(landmarks, img.cols, img.rows);
                        //for (int i = 0; i < stasm_NLANDMARKS; i++)
                        //    line(img, cvPoint(landmarks[i*2], landmarks[i*2+1]), cvPoint(landmarks[i*2], landmarks[i*2+1]), CV_RGB(255,255,255));
                        extractFeatures();
                    }
                sprintf(stasm_filename, "/home/pi/haptikos/data/MUGdataset_stasm/%s/%d/%d.jpg", expressions[e], conj, s);
                imwrite(stasm_filename, img);

                std::ofstream resultFile;
                resultFile.precision(4);
                if(conj == 1){
                    resultFile.open("bin12.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    resultFile.open("bin13.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    resultFile.open("multi12.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    resultFile.open("multi13.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    if(e>0){
                        resultFile.open("testData1.hpp", std::ios::app);
                        resultFile << "{";
                        for(int n=0; n<14; n++)
                        resultFile << features[n] << ", ";
                        resultFile << features[15] << "}, \n";
                        resultFile.close();resultFile.clear();
                    }

                    resultFile.open("testDataBin1.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();
                }
                else if(conj == 2){
                    resultFile.open("bin12.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    resultFile.open("bin23.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    resultFile.open("multi12.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    resultFile.open("multi23.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    if(e>0){
                        resultFile.open("testData2.hpp", std::ios::app);
                        resultFile << "{";
                        for(int n=0; n<14; n++)
                        resultFile << features[n] << ", ";
                        resultFile << features[15] << "}, \n";
                        resultFile.close();resultFile.clear();
                    }

                    resultFile.open("testDataBin2.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();
                }
                else if(conj == 3){
                    resultFile.open("bin13.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    resultFile.open("bin23.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    resultFile.open("multi13.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    resultFile.open("multi23.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();

                    if(e>0){
                        resultFile.open("testData3.hpp", std::ios::app);
                        resultFile << "{";
                        for(int n=0; n<14; n++)
                        resultFile << features[n] << ", ";
                        resultFile << features[15] << "}, \n";
                        resultFile.close();resultFile.clear();
                    }

                    resultFile.open("testDataBin3.hpp", std::ios::app);
                    resultFile << "{";
                    for(int n=0; n<14; n++)
                    resultFile << features[n] << ", ";
                    resultFile << features[15] << "}, \n";
                    resultFile.close();resultFile.clear();
                }
            }
        }
        fclose(fp);
    }
    }
    setFinalFiles();
    printf("\n DONE");
    waitKey(0);
    return 0;
}

double extractFeature(float x1, float y1, float x2, float y2){
    double result;
    line(img, cvPoint(x1, y1), cvPoint(x2, y2), CV_RGB(255,255,255));
    // Euclidean distance
    result = (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)))/baseline;
    result=result*10;
    if(feature_counter<15){
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
    //Nose to mouth corner left
    extractFeature(landmarks[58*2], landmarks[58*2+1], landmarks[59*2], landmarks[59*2+1]);
    //Nose to mouth corner right
    extractFeature(landmarks[54*2], landmarks[54*2+1], landmarks[65*2], landmarks[65*2+1]);
    //Eye opening left
    extractFeature(landmarks[32*2], landmarks[32*2+1], landmarks[36*2], landmarks[36*2+1]);
    //Eye opening right
    extractFeature(landmarks[42*2], landmarks[42*2+1], landmarks[46*2], landmarks[46*2+1]);
    //Mid eyebrow to pupil left
    extractFeature(landmarks[19*2], landmarks[19*2+1], landmarks[38*2], landmarks[38*2+1]);
    //Mid eyebrow to pupil right
    extractFeature(landmarks[26*2], landmarks[26*2+1], landmarks[39*2], landmarks[39*2+1]);

    /*for(int k=0; k<=15; k++)
    printf("%.2f, ", features[k]);
    printf("\n");*/
}

void setFiles(){
    std::ofstream resultFile;
resultFile.open("bin12.hpp");
resultFile << "float dataBin12[140][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("bin13.hpp");
resultFile << "float dataBin13[140][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("bin23.hpp");
resultFile << "float dataBin23[140][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("multi12.hpp");
resultFile << "float data12[120][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("multi13.hpp");
resultFile << "float data13[120][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("multi23.hpp");
resultFile << "float data23[120][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("testData1.hpp");
resultFile << "float labels[60] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0};\nfloat labelsBin[70] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0};\nfloat labelsMulti[70] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0};\nfloat data1[60][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("testData2.hpp");
resultFile << "float data2[60][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("testData3.hpp");
resultFile << "float data3[60][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("testDataBin1.hpp");
resultFile << "float dataBin1[70][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("testDataBin2.hpp");
resultFile << "float dataBin2[70][16] = {\n";
resultFile.close();resultFile.clear();

resultFile.open("testDataBin3.hpp");
resultFile << "float dataBin3[70][16] = {\n";
resultFile.close();resultFile.clear();
}

void setFinalFiles(){
    std::ofstream resultFile;
resultFile.open("bin12.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("bin13.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("bin23.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("multi12.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("multi13.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("multi23.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("testData1.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("testData2.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("testData3.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("testDataBin1.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("testDataBin2.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();

resultFile.open("testDataBin3.hpp", std::ios::app);
resultFile << "};";
resultFile.close();resultFile.clear();
}

