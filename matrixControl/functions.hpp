#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED



#endif // FUNCTIONS_HPP_INCLUDED
//


#define COL12   23
#define COL11   24
#define COL10   27
#define COL9    10
#define COL8    25
#define COL7    7
#define COL6    11
#define COL5    12
#define COL4    13
#define COL3    20
#define COL2    5
#define COL1    26


#define ROW10   4
#define ROW9    22
#define ROW8    9
#define ROW7    8
#define ROW6    0
#define ROW5    1
#define ROW4    6
#define ROW3    16
#define ROW2    21
#define ROW1    19


void configPins(){
    gpioSetMode(COL1, PI_OUTPUT);
    gpioSetMode(COL2, PI_OUTPUT);
    gpioSetMode(COL3, PI_OUTPUT);
    gpioSetMode(COL4, PI_OUTPUT);
    gpioSetMode(COL5, PI_OUTPUT);
    gpioSetMode(COL6, PI_OUTPUT);
    gpioSetMode(COL7, PI_OUTPUT);
    gpioSetMode(COL8, PI_OUTPUT);
    gpioSetMode(COL9, PI_OUTPUT);
    gpioSetMode(COL10, PI_OUTPUT);
    gpioSetMode(COL11, PI_OUTPUT);
    gpioSetMode(COL12, PI_OUTPUT);

    gpioSetMode(ROW1, PI_OUTPUT);
    gpioSetMode(ROW2, PI_OUTPUT);
    gpioSetMode(ROW3, PI_OUTPUT);
    gpioSetMode(ROW4, PI_OUTPUT);
    gpioSetMode(ROW5, PI_OUTPUT);
    gpioSetMode(ROW6, PI_OUTPUT);
    gpioSetMode(ROW7, PI_OUTPUT);
    gpioSetMode(ROW8, PI_OUTPUT);
    gpioSetMode(ROW9, PI_OUTPUT);
    gpioSetMode(ROW10, PI_OUTPUT);

    gpioSetPullUpDown(COL1, PI_PUD_DOWN);
    gpioSetPullUpDown(COL2, PI_PUD_DOWN);
    gpioSetPullUpDown(COL3, PI_PUD_DOWN);
    gpioSetPullUpDown(COL4, PI_PUD_DOWN);
    gpioSetPullUpDown(COL5, PI_PUD_DOWN);
    gpioSetPullUpDown(COL6, PI_PUD_DOWN);
    gpioSetPullUpDown(COL7, PI_PUD_DOWN);
    gpioSetPullUpDown(COL8, PI_PUD_DOWN);
    gpioSetPullUpDown(COL9, PI_PUD_DOWN);
    gpioSetPullUpDown(COL10, PI_PUD_DOWN);
    gpioSetPullUpDown(COL11, PI_PUD_DOWN);
    gpioSetPullUpDown(COL12, PI_PUD_DOWN);

    gpioSetPullUpDown(ROW1, PI_PUD_DOWN);
    gpioSetPullUpDown(ROW2, PI_PUD_DOWN);
    gpioSetPullUpDown(ROW3, PI_PUD_DOWN);
    gpioSetPullUpDown(ROW4, PI_PUD_DOWN);
    gpioSetPullUpDown(ROW5, PI_PUD_DOWN);
    gpioSetPullUpDown(ROW6, PI_PUD_DOWN);
    gpioSetPullUpDown(ROW7, PI_PUD_DOWN);
    gpioSetPullUpDown(ROW8, PI_PUD_DOWN);
    gpioSetPullUpDown(ROW9, PI_PUD_DOWN);
    gpioSetPullUpDown(ROW10, PI_PUD_DOWN);
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
        case 3:
        	gpioWrite(ROW3, o);
        break;
        case 4:
            gpioWrite(ROW4, o);
        break;
        case 5:
        	gpioWrite(ROW5, o);
        break;
        case 6:
            gpioWrite(ROW6, o);
        break;
        case 7:
        	gpioWrite(ROW7, o);
        break;
        case 8:
            gpioWrite(ROW8, o);
        break;
        case 9:
        	gpioWrite(ROW9, o);
        break;
        case 10:
            gpioWrite(ROW10, o);
        break;
        default:
        break;
    }

	o=0;

    switch(col){
        case 1:
        	gpioWrite(COL1, o);
        break;
        case 2:
            gpioWrite(COL2, o);
        break;
        case 3:
        	gpioWrite(COL3, o);
        break;
        case 4:
            gpioWrite(COL4, o);
        break;
        case 5:
        	gpioWrite(COL5, o);
        break;
        case 6:
            gpioWrite(COL6, o);
        break;
        case 7:
        	gpioWrite(COL7, o);
        break;
        case 8:
            gpioWrite(COL8, o);
        break;
        case 9:
        	gpioWrite(COL9, o);
        break;
        case 10:
            gpioWrite(COL10, o);
        break;
            case 11:
            gpioWrite(COL11, o);
        break;
            case 12:
            gpioWrite(COL12, o);
        break;
        default:
        break;
    }
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
        case 3:
        	gpioWrite(ROW3, o);
        break;
        case 4:
            gpioWrite(ROW4, o);
        break;
        case 5:
        	gpioWrite(ROW5, o);
        break;
        case 6:
            gpioWrite(ROW6, o);
        break;
        case 7:
        	gpioWrite(ROW7, o);
        break;
        case 8:
            gpioWrite(ROW8, o);
        break;
        case 9:
        	gpioWrite(ROW9, o);
        break;
        case 10:
            gpioWrite(ROW10, o);
        break;
        default:
        break;
    }

    o=1;

    switch(col){
        case 1:
        	gpioWrite(COL1, o);
        break;
        case 2:
            gpioWrite(COL2, o);
        break;
        case 3:
        	gpioWrite(COL3, o);
        break;
        case 4:
            gpioWrite(COL4, o);
        break;
        case 5:
        	gpioWrite(COL5, o);
        break;
        case 6:
            gpioWrite(COL6, o);
        break;
        case 7:
        	gpioWrite(COL7, o);
        break;
        case 8:
            gpioWrite(COL8, o);
        break;
        case 9:
        	gpioWrite(COL9, o);
        break;
        case 10:
            gpioWrite(COL10, o);
        break;
            case 11:
            gpioWrite(COL11, o);
        break;
            case 12:
            gpioWrite(COL12, o);
        break;
        default:
        break;
    }
}

void motorOn(int motorNumber){
    if (motorNumber < 10){
        if(motorNumber == 1)
            turnOn(4, 11);
        else
            turnOn(1, motorNumber);
    }else if(motorNumber%10 == 0){
        if(motorNumber == 10 || motorNumber == 20 || motorNumber == 50 || motorNumber == 90 || motorNumber == 100)
            turnOn((motorNumber/10), 12);
        else
            turnOn((motorNumber/10), (motorNumber/(motorNumber/10)));
    }else{
        if(motorNumber == 11 || motorNumber == 41)
            turnOn((motorNumber/10)+2, 11);//ROW3 pro 11 e ROW6 pro 41
        else if(motorNumber == 81)
            turnOn(8, 11);
        else if(motorNumber == 91)
            turnOn(7, 11);
        else
            turnOn((motorNumber/10)+1, motorNumber%10);
    }
}


void motorOff(int motorNumber){
    if (motorNumber < 10){
        if(motorNumber == 1)
            turnOff(4, 11);
        else
            turnOff(1, motorNumber);
    }else if(motorNumber%10 == 0){
        if(motorNumber == 10 || motorNumber == 20 || motorNumber == 50 || motorNumber == 90 || motorNumber == 100)
            turnOff((motorNumber/10), 12);
        else
            turnOff((motorNumber/10), (motorNumber/(motorNumber/10)));
    }else{//Ex: 88 = (((88/10)+1), (88modulo10)
        if(motorNumber == 11 || motorNumber == 41)
            turnOff((motorNumber/10)+2, 11);//ROW3 pro 11 e ROW6 pro 41
        else if(motorNumber == 81)
            turnOff(8, 11);
        else if(motorNumber == 91)
            turnOff(7, 11);
        else
            turnOff((motorNumber/10)+1, motorNumber%10);
    }
}

void motorOnTime(int motorNumber, int time){
    motorOn(motorNumber);
    gpioDelay(time*1000);
    motorOff(motorNumber);
}

void turnOffCol(){
    gpioWrite(COL1, 1);
    gpioWrite(COL2, 1);
    gpioWrite(COL3, 1);
    gpioWrite(COL4, 1);
    gpioWrite(COL5, 1);
    gpioWrite(COL6, 1);
    gpioWrite(COL7, 1);
    gpioWrite(COL8, 1);
    gpioWrite(COL9, 1);
    gpioWrite(COL10, 1);
    gpioWrite(COL11, 1);
    gpioWrite(COL12, 1);
}
void turnOffRow(){
	gpioWrite(ROW1, 0);
	gpioWrite(ROW2, 0);
	gpioWrite(ROW3, 0);
	gpioWrite(ROW4, 0);
	gpioWrite(ROW5, 0);
	gpioWrite(ROW6, 0);
	gpioWrite(ROW7, 0);
	gpioWrite(ROW8, 0);
	gpioWrite(ROW9, 0);
	gpioWrite(ROW10, 0);
}

void motorOn4(int m1, int m2, int m3, int m4){
    motorOn(m1);
    motorOn(m2);
    motorOn(m3);
    motorOn(m4);
}

void motorOff4(int m1, int m2, int m3, int m4){
    motorOff(m1);
    motorOff(m2);
    motorOff(m3);
    motorOff(m4);
}

void motorOnTime4(int m1, int m2, int m3, int m4, int time){
    motorOn4(m1, m2, m3, m4);
    gpioDelay(time*1000);
    motorOff4(m1, m2, m3, m4);
}

void motorOnTime8(int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int time){
    motorOn4(m1, m2, m3, m4);
    motorOn4(m5, m6, m7, m8);
    gpioDelay(time*1000);
    motorOff4(m1, m2, m3, m4);
    motorOff4(m5, m6, m7, m8);
}

void motorMultiplex(int m1, int m2, int m3, int time){
    for(int j=0; j<333; j++){
        motorOnTime(m1, time/1000);
        motorOnTime(m2, time/1000);
        motorOnTime(m3, time/1000);
    }
}

void motorOn2(int m1, int m2){
    motorOn(m1);
    motorOn(m2);
}

void motorOff2(int m1, int m2){
    motorOff(m1);
    motorOff(m2);
}

void motorOnTime2(int m1, int m2, int time){
    motorOn2(m1, m2);
    gpioDelay(time*1000);
    motorOff2(m1, m2);
}

void anger(){
    for(int k=0; k<5; k++){
        motorOnTime8(44, 47, 53, 54, 57, 58, 64, 67, 150);
        gpioDelay(100000);
    }
}
void disgust(){
    motorOnTime2(45, 55, 100);
    motorOnTime4(34, 44, 45, 55, 100);
    motorOnTime4(34, 44, 54, 64, 100);
    motorOnTime8(23, 43, 53, 73, 34, 44, 54, 64, 50);
    motorOnTime4(23, 43, 53, 73, 100);
    motorOnTime8(12, 42, 52, 82, 23, 43, 53, 73, 50);
    motorOnTime4(12, 42, 52, 82, 100);
    motorOnTime8(1, 41, 51, 91, 12, 42, 52, 82, 50);
    motorOnTime4(1, 41, 51, 91, 100);
    motorOnTime8(44, 47, 53, 54, 57, 58, 64, 67, 250);
}

void fear(){
    for(int j=0; j<5; j++){
        motorOnTime2(1, 5, 75);
        motorOn(41);
        motorOnTime2(1, 5, 75);
        motorOff(41);
        motorOnTime2(11, 6, 75);
        motorOn(41);
        motorOnTime2(11, 6, 75);
        motorOff(41);
    }
}

void happiness(){
    motorOnTime(50, 175);
    motorOnTime(60, 175);
    motorOnTime(70, 175);
    motorOnTime2(79, 80, 175);
    motorOnTime2(88, 89, 175);
    motorOnTime(97, 175);
    motorOnTime(96, 175);
    motorOnTime(95, 175);
    motorOnTime(94, 175);
    motorOnTime2(82, 83, 175);
    motorOnTime2(71, 72, 175);
    motorOnTime(61, 175);
    motorOnTime(51, 175);
    motorOnTime(41, 175);
}

void sadness(){
    motorOnTime(60, 175);
    motorOnTime(50, 175);
    motorOnTime(40, 175);
    motorOnTime2(29, 30, 175);
    motorOnTime2(18, 19, 175);
    motorOnTime(7, 175);
    motorOnTime(6, 175);
    motorOnTime(5, 175);
    motorOnTime(4, 175);
    motorOnTime2(12, 13, 175);
    motorOnTime2(21, 22, 175);
    motorOnTime(31, 175);
    motorOnTime(41, 175);
    motorOnTime(51, 175);
}

void surprise(){
    motorOnTime4(93, 95, 96, 98, 100);
    motorOnTime8(93, 95, 96, 98, 83, 85, 86, 88, 50);
    motorOnTime4(83, 85, 86, 88, 100);
    motorOnTime8(83, 85, 86, 88, 73, 75, 76, 78, 50);
    motorOnTime4(73, 75, 76, 78, 100);
    motorOnTime8(73, 75, 76, 78, 63, 65, 66, 68, 50);
    motorOnTime4(63, 65, 66, 68, 100);
    motorOnTime8(63, 65, 66, 68, 53, 55, 56, 58, 50);
    motorOnTime4(53, 55, 56, 58, 100);
    motorOnTime8(53, 55, 56, 58, 43, 45, 46, 48, 50);
    motorOnTime4(43, 45, 46, 48, 100);
    motorOnTime8(43, 45, 46, 48, 33, 34, 37, 38 , 50);
    motorOnTime4(33, 34, 37, 38 , 100);
    motorOnTime8(33, 34, 37, 38, 22, 23, 28, 29, 50);
    motorOnTime4(22, 23, 28, 29, 100);
    motorOnTime8(22, 23, 28, 29, 11, 12, 19, 20 , 50);
    motorOnTime4(11, 12, 19, 20 , 100);
    motorOnTime4(1, 11, 19, 10, 100);
    motorOnTime2(1, 10, 100);
}
