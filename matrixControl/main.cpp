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
            //disgust();
            braillePointOn(1);
            gpioDelay(3000000);
            braillePointOff(1);
            gpioDelay(1000000);
            braillePointOn(1);
            braillePointOn(2);
            gpioDelay(3000000);
            braillePointOff(1);
            braillePointOff(1);
            gpioDelay(1000000);
            braillePointOn(1);
            braillePointOn(4);
            gpioDelay(3000000);
            braillePointOff(1);
            braillePointOff(4);
        }else if(key=='6'){
            //fear();
            //for(int i = 1; i<=100; i++)
            //motorOnTime(i, 500);
            brailleCell("111111", 1000);
        }else if(key=='7'){
            sadnessNew();

        }else if(key=='8'){
            surpriseNew();
        }
        else if(key=='*'){
            gpioTerminate();
            return 0;
        }
    }


    gpioTerminate();
    return 0;
}

