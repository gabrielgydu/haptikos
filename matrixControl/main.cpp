#include <iostream>
#include <pigpio.h>
#include <stdio.h>
#include "functions.hpp"

using namespace std;

int main()
{

    if (gpioInitialise() >= 0){
        configPins();
    }
    cout << "Controle da matriz" << endl;

    //for(int i = 1; i<=100; i++)
    //motorOnTime(i, 500000);
    for(int j = 1; j<=100; j++)
            motorOnTime(j, 1);

    while(1){
        int key = getchar();
        if(key=='1'){
            anger();
        }else if(key=='2'){
            happiness();
        }else if(key=='3'){
            sadness();
        }else if(key=='4'){
            surprise();
        }else if(key=='5'){
                brailleCell("100000", 1000);
                gpioDelay(3000000);
                brailleCell("110000", 1000);
                gpioDelay(3000000);
                brailleCell("100100", 1000);
                gpioDelay(3000000);
                brailleCell("100110", 1000);
                gpioDelay(3000000);
                brailleCell("100010", 1000);
                gpioDelay(3000000);
                brailleCell("110100", 1000);
                gpioDelay(3000000);
                brailleCell("110110", 1000);
                gpioDelay(3000000);
                brailleCell("110010", 1000);
                gpioDelay(3000000);
                brailleCell("010100", 1000);
                gpioDelay(3000000);
        }else if(key=='6'){
            for(int j = 1; j<=100; j++)
            motorOnTime(j, 10);
            for(int i = 1; i<=20; i++)
            motorOnTime(i, 500);
        }else if(key=='7'){
            sadnessNew();
        }else if(key=='8'){
            surpriseNew();
        }else if(key=='9'){
            fear();
        }else if(key=='0'){
            disgust();
        }
        else if(key=='A'){
            letraA();
        }else if(key=='B'){
            letraB();
        }else if(key=='C'){
            letraC();
        }
        else if(key=='*'){
            gpioTerminate();
            return 0;
        }
    }


    gpioTerminate();
    return 0;
}

