#include <iostream>
#include <pigpio.h>
#include <stdio.h>

using namespace std;

void motorOnTime(int motorNumber, int time);
void motorOn(int motorNumber);
void motorOff(int motorNumber);
void turnOff(int row, int col);
void turnOn(int row, int col);

#define ROW1 4
#define ROW2 27
#define COL1 22
#define COL2 17

int main()
{

    if (gpioInitialise() >= 0){
        gpioSetMode(ROW1, PI_OUTPUT);//COL1
        gpioSetMode(ROW2, PI_OUTPUT);//COL2
        gpioSetMode(COL1, PI_OUTPUT);//COL3
        gpioSetMode(COL2, PI_OUTPUT);//COL4
    }
    cout << "Hello world!" << endl;

    /*for(int i = 1; i<=10; i++){
    for(int m = 1; m<=4; m++)
    motorOnTime(m, 50);

    motorOn(1);
    motorOn(2);
    gpioDelay(50000);
    motorOff(1);
    motorOff(2);
    gpioDelay(50000);
    motorOn(3);
    motorOn(4);
    gpioDelay(50000);
    motorOff(3);
    motorOff(4);
    gpioDelay(50000);
    motorOn(1);
    motorOn(4);
    gpioDelay(50000);
    motorOff(1);
    motorOff(4);
    gpioDelay(50000);
    }*/
    for(int i=0;  i<99; i++)
    {
    gpioWrite(17, 1);
    gpioDelay(1000000);
    gpioWrite(17, 0);
    gpioDelay(1000000);
    }

    gpioTerminate();
    return 0;
}


void motorOnTime(int motorNumber, int time){
	if (motorNumber <= 2){
		turnOn(1, motorNumber);
		gpioDelay(time*1000);
		turnOff(1, motorNumber);
	}
	else{
		turnOn(2, motorNumber-2);
		gpioDelay(time*1000);
		turnOff(2, motorNumber-2);
	}
}

void motorOn(int motorNumber){
	if (motorNumber <= 2){
		turnOn(1, motorNumber);
	}
	else{
		turnOn(2, motorNumber-2);
	}
}

void motorOff(int motorNumber){
	if (motorNumber <= 2){
		turnOff(1, motorNumber);
	}
	else{
		turnOff(2, motorNumber-2);
	}
}

void turnOn(int row, int col){
int o=1;
switch(row){
    case 1:
    	gpioWrite(ROW1, o);
    break;
    case 2:
        gpioWrite(ROW2, o);
    break;
}
	printf("TURNED ON ROW%d", row);
	o=0;
switch(col){
    case 1:
    	gpioWrite(COL1, o);
    break;
    case 2:
        gpioWrite(COL2, o);
    break;
}
    printf("TURNED ON COL%d\n", col);
    }

void turnOff(int row, int col){
int o=0;
switch(row){
    case 1:
    	gpioWrite(ROW1, o);
    break;
    case 2:
        gpioWrite(ROW2, o);
    break;
}
	printf("TURNED OFF ROW%d", row);
	o=1;
switch(col){
    case 1:
    	gpioWrite(COL1, o);
    break;
    case 2:
        gpioWrite(COL2, o);
    break;
}
    printf("TURNED OFF COL%d\n", col);
}
