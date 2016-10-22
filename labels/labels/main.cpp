#include <ctime>
#include <iostream>
#include <cctype>
#include <iterator>
#include <stdio.h>
#include <dirent.h>

using namespace std;

FILE *fp=NULL;

int main()
{
    fp = fopen("/home/pi/haptikos/labels/labelsTrain.txt", "w");
    for(int i=0; i<10; i++)
    fprintf(fp, "1.0, ");
    for(int i=0; i<60; i++)
    fprintf(fp, "-1.0, ");
    fprintf(fp, "};");
    fclose(fp);

    fp = fopen("/home/pi/haptikos/labels/labelsMultiTrain.txt", "w");
    for(int i=0; i<10; i++)
    fprintf(fp, "1.0, ");
    for(int i=0; i<10; i++)
    fprintf(fp, "2.0, ");
    for(int i=0; i<10; i++)
    fprintf(fp, "3.0, ");
    for(int i=0; i<10; i++)
    fprintf(fp, "4.0, ");
    for(int i=0; i<10; i++)
    fprintf(fp, "5.0, ");
    for(int i=0; i<10; i++)
    fprintf(fp, "6.0, ");
    fprintf(fp, "};");
    fclose(fp);


    return 0;
}
