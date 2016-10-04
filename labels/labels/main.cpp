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
    fp = fopen("/home/pi/haptikos/labels/labels.txt", "w");
    for(int i=0; i<51; i++)
    fprintf(fp, "1.0, ");
    for(int i=0; i<838; i++)
    fprintf(fp, "-1.0, ");
    fprintf(fp, "};");
    fclose(fp);

    fp = fopen("/home/pi/haptikos/labels/labels_multi.txt", "w");
    for(int i=0; i<153; i++)
    fprintf(fp, "1.0, ");
    for(int i=0; i<138; i++)
    fprintf(fp, "2.0, ");
    for(int i=0; i<115; i++)
    fprintf(fp, "3.0, ");
    for(int i=0; i<154; i++)
    fprintf(fp, "4.0, ");
    for(int i=0; i<118; i++)
    fprintf(fp, "5.0, ");
    for(int i=0; i<155; i++)
    fprintf(fp, "6.0, ");
    fprintf(fp, "};");
    fclose(fp);


    return 0;
}
