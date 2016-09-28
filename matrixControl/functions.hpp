#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED



#endif // FUNCTIONS_HPP_INCLUDED
//

#define COL10    4
#define COL9    17
#define COL8    27
#define COL7    22
#define COL6    10
#define COL5    9
#define COL4    11
#define COL3    0
#define COL2    5
#define COL1   6

#define ROW10    18
#define ROW9    23
#define ROW8    24
#define ROW7    25
#define ROW6    8
#define ROW5    7
#define ROW4    12
#define ROW3    16
#define ROW2    20
#define ROW1   21

void configPins();
void motorOnTime(int motorNumber, int time);
void motorOn(int motorNumber);
void motorOff(int motorNumber);
void motorOnTime4(int m1, int m2, int m3, int m4, int time);
void motorOn4(int m1, int m2, int m3, int m4);
void motorOff4(int m1, int m2, int m3, int m4);
void motorOnTime2(int m1, int m2, int time);
void motorOn2(int m1, int m2);
void motorOff2(int m1, int m2);
void turnOff(int row, int col);
void turnOn(int row, int col);
void turnOffRow();
void turnOffCol();

void anger();
void happiness();
void sadness();
void sadnessNew();
void surprise();
void surpriseNew();

void braillePointOn();
void braillePointOff();
void braillePointOnTime();

void brailleCell(char points[5], int time);


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

        turnOffRow();
        turnOffCol();
}

void motorOnTime(int motorNumber, int time){
    if (motorNumber == 1 || motorNumber == 2 || motorNumber == 41 || motorNumber == 42 || motorNumber == 81 || motorNumber == 82)
        motorNumber=motorNumber+10;
    else if(motorNumber == 11 || motorNumber == 12 || motorNumber == 51 || motorNumber == 52 || motorNumber == 91 || motorNumber == 92)
        motorNumber=motorNumber-10;

	if (motorNumber <= 10){
		turnOn(1, motorNumber);
		gpioDelay(time*1000);
		turnOff(1, motorNumber);
	}else if(motorNumber%10 == 0){
		turnOn((motorNumber/10), (motorNumber/(motorNumber/10)));
		gpioDelay(time*1000);
		turnOff((motorNumber/10) , (motorNumber/(motorNumber/10)));
	}else{//Ex: 88 = (((88/10)+1), (88modulo10)
		turnOn((motorNumber/10)+1, motorNumber%10);
		gpioDelay(time*1000);
		turnOff((motorNumber/10)+1, motorNumber%10);
	}
}

void motorOn(int motorNumber){
    if (motorNumber == 1 || motorNumber == 2 || motorNumber == 41 || motorNumber == 42 || motorNumber == 81 || motorNumber == 82)
        motorNumber=motorNumber+10;
    else if(motorNumber == 11 || motorNumber == 12 || motorNumber == 51 || motorNumber == 52 || motorNumber == 91 || motorNumber == 92)
        motorNumber=motorNumber-10;

    if (motorNumber <= 10){
        turnOn(1, motorNumber);
    }else if(motorNumber%10 == 0){
        turnOn((motorNumber/10), (motorNumber/(motorNumber/10)));
    }else{//Ex: 88 = (((88/10)+1), (88modulo10)
        turnOn((motorNumber/10)+1, motorNumber%10);
    }
}

void motorOff(int motorNumber){
    if (motorNumber == 1 || motorNumber == 2 || motorNumber == 41 || motorNumber == 42 || motorNumber == 81 || motorNumber == 82)
        motorNumber=motorNumber+10;
    else if(motorNumber == 11 || motorNumber == 12 || motorNumber == 51 || motorNumber == 52 || motorNumber == 91 || motorNumber == 92)
        motorNumber=motorNumber-10;

    if (motorNumber <= 10){
        turnOff(1, motorNumber);
    }else if(motorNumber%10 == 0){
        turnOff((motorNumber/10), (motorNumber/(motorNumber/10)));
    }else{//Ex: 88 = (((88/10)+1), (88modulo10)
        turnOff((motorNumber/10)+1, motorNumber%10);
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
}
	//printf("TURNED ON ROW%d", row);
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
}
    //printf("TURNED ON COL%d\n", col);
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
}

}
void turnOffRow(){
int o=0;
    	gpioWrite(COL1, o);
    	gpioWrite(COL2, o);
    	gpioWrite(COL3, o);
    	gpioWrite(COL4, o);
    	gpioWrite(COL5, o);
    	gpioWrite(COL6, o);
    	gpioWrite(COL7, o);
    	gpioWrite(COL8, o);
    	gpioWrite(COL9, o);
    	gpioWrite(COL10, o);
}
void turnOffCol(){
int o=1;
    	gpioWrite(ROW1, o);
    	gpioWrite(ROW2, o);
    	gpioWrite(ROW3, o);
    	gpioWrite(ROW4, o);
    	gpioWrite(ROW5, o);
    	gpioWrite(ROW6, o);
    	gpioWrite(ROW7, o);
    	gpioWrite(ROW8, o);
    	gpioWrite(ROW9, o);
    	gpioWrite(ROW10, o);

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
    motorOn(m1);
    motorOn(m2);
    motorOn(m3);
    motorOn(m4);
    gpioDelay(time*1000);
    motorOff(m1);
    motorOff(m2);
    motorOff(m3);
    motorOff(m4);
}

void motorOnTime8(int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int time){
    motorOn4(m1, m2, m3, m4);
    motorOn4(m5, m6, m7, m8);
    gpioDelay(time*1000);
    motorOff4(m1, m2, m3, m4);
    motorOff4(m5, m6, m7, m8);
}

void motorOn3(int m1, int m2, int m3){
    motorOn(m1);
    motorOn(m2);
    motorOn(m3);
}

void motorOff3(int m1, int m2, int m3){
    motorOff(m1);
    motorOff(m2);
    motorOff(m3);
}

void motorOnTime3(int m1, int m2, int m3, int time){
    motorOn3(m1, m2, m3);
    gpioDelay(time*1000);
    motorOff3(m1, m2, m3);
}

void motorMultiplex(int m1, int m2, int m3, int time){
    for(int j=0; j<333; j++){
        motorOnTime(m1, time/1000);
        motorOnTime(m2, time/1000);
        motorOnTime(m3, time/1000);
    }
}

void motorOnTime2(int m1, int m2, int time){
    motorOn(m1);
    motorOn(m2);
    gpioDelay(time*1000);
    motorOff(m1);
    motorOff(m2);
}

void motorOn2(int m1, int m2){
    motorOn(m1);
    motorOn(m2);
}

void motorOff2(int m1, int m2){
    motorOff(m1);
    motorOff(m2);
}

void angerNew(){
    for(int k=0; k<5; k++){
        motorOnTime8(44, 47, 53, 54, 57, 58, 64, 67, 100);
        gpioDelay(100000);
    }
}

void surpriseNew1(){
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

void surpriseNew2(){//have to finish
motorOnTime4(94, 95, 96, 97, 100);
motorOnTime8(84, 85, 86, 87, 94, 95, 96, 97, 50);
motorOnTime4(84, 85, 86, 87, 100);
motorOnTime8(74, 75, 76, 77, 84, 85, 86, 87, 50);
motorOnTime4(74, 75, 76, 77, 100);
motorOnTime8(64, 65, 66, 67, 74, 75, 76, 77, 50);
motorOnTime4(64, 65, 66, 67, 100);
motorOnTime8(54, 55, 56, 57, 64, 65, 66, 67, 50);
motorOnTime4(54, 55, 56, 57, 100);
motorOnTime8(44, 45, 46, 47, 54, 55, 56, 57, 50);
motorOnTime4(44, 45, 46, 47, 100);
motorOnTime8(34, 35, 36, 37, 44, 45, 46, 47, 50);
motorOnTime4(34, 35, 36, 37, 100);

motorOnTime4(3, 13, 23, 33, 100);
motorOnTime4(2, 12, 22, 32, 100);
motorOnTime4(1, 11, 21, 31, 100);

}

void surpriseNew3(){

}

void surpriseNew4(){
motorOnTime4(97, 98, 99, 100, 100);
motorOnTime8(87, 88, 89, 90, 97, 98, 99, 100, 50);
motorOnTime4(87, 88, 89, 90, 100);
motorOnTime8(77, 78, 79, 80, 87, 88, 89, 90, 50);
motorOnTime4(77, 78, 79, 80, 100);
motorOnTime8(67, 68, 69, 70, 77, 78, 79, 80, 50);
motorOnTime4(67, 68, 69, 70, 100);
motorOnTime8(57, 58, 59, 60, 67, 68, 69, 70, 50);
motorOnTime4(57, 58, 59, 60, 100);
motorOnTime8(47, 48, 49, 50, 57, 58, 59, 60, 50);
motorOnTime4(47, 48, 49, 50, 100);
motorOnTime8(37, 38, 39, 40, 47, 48, 49, 50, 50);
motorOnTime4(37, 38, 39, 40, 100);
motorOnTime8(27, 28, 29, 30, 37, 38, 39, 40, 50);
motorOnTime4(27, 28, 29, 30, 100);
motorOnTime8(17, 18, 19, 20, 27, 28, 29, 30, 50);
motorOnTime4(17, 18, 19, 20, 100);
motorOnTime8(7, 8, 9, 10, 17, 18, 19, 20, 50);
motorOnTime4(7, 8, 9, 10, 100);

}

void surprise(){
    motorOnTime(96, 150);
    motorOnTime(95, 150);
    motorOnTime(94, 150);
    motorOnTime(93, 150);
    motorOnTime(92, 150);
    motorOnTime(91, 150);
    motorOnTime2(82, 83, 150);
    motorOnTime(74, 150);
    motorOnTime(73, 150);
    motorOnTime(72, 150);
    motorOnTime(71, 150);
    motorOnTime2(62, 63, 150);
    motorOnTime(52, 150);
    motorOnTime(43, 150);
}

void anger(){
    motorOnTime(80, 200);
    motorOnTime(69, 200);
    motorOnTime2(58, 48, 200);
    motorOnTime2(37, 47, 200);
    //motorOnTime(26, 200);
    motorOnTime2(26, 25, 200);
    //motorOnTime(25, 200);
    motorOnTime2(34, 44, 200);
    motorOnTime2(52, 53, 200);
    motorOnTime(62, 200);
    motorOnTime(71, 200);
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
    //motorOnTime8(44, 45, 46, 47, 54, 55, 56, 57, 150);
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

void sadnessNew(){
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

void sadness(){
    motorOnTime(7, 100);
    motorOnTime(17, 100);
    motorOnTime(27, 100);
    motorOnTime(37, 100);
    motorOnTime(47, 100);
    motorOnTime(57, 100);
    motorOnTime(67, 100);
    motorOnTime(77, 100);
    motorOnTime(87, 100);
    motorOnTime(97, 100);
    //2
    motorOnTime(4, 100);
    motorOnTime(14, 100);
    motorOnTime(24, 100);
    motorOnTime(34, 100);
    motorOnTime(44, 100);
    motorOnTime(54, 100);
    motorOnTime(64, 100);
    motorOnTime(74, 100);
    motorOnTime(84, 100);
    motorOnTime(94, 100);
}

void braillePointOn(int point){
	switch(point){
		case 4:
			motorOn2(1, 2);
			break;
		case 5:
			motorOn2(41, 42);
			break;
		case 6:
			motorOn2(91, 92);
			break;
		case 1:
			motorOn2(9, 10);
			break;
		case 2:
			motorOn2(49, 50);
		break;
		case 3:
			motorOn2(99, 100);
		break;
		default:
			break;
	}
}

void braillePointOff(int point){
    switch(point){
        case 4:
            motorOff2(1, 2);
            break;
        case 5:
            motorOff2(41, 42);
            break;
        case 6:
            motorOff2(91, 92);
            break;
        case 1:
            motorOff2(9, 10);
            break;
        case 2:
            motorOff2(49, 50);
        break;
        case 3:
            motorOff2(99, 100);
        break;
        default:
            break;
    }
}
void braillePointOnTime(int point, int time){
			braillePointOn(point);
			gpioDelay(time*1000);
			braillePointOff(point);
}

void brailleCell(char points[5], int time){
	for(int k =0; k<=5; k++){
		if(points[k] == '1'){
			braillePointOnTime(k+1, 500);
			}
	}

	for(int k =0; k<=5; k++){
		if(points[k] == '1'){
			braillePointOn(k+1);
			}
	}
	gpioDelay(time*1000);
		for(int l =0; l<=5; l++){
		if(points[l] == '1')
			braillePointOff(l+1);
	}

}

void spaceBraille(int time){
motorOnTime4(31, 41, 51, 61, time/2);
motorOnTime4(32, 42, 52, 62, time/2);
motorOnTime4(33, 43, 53, 63, time/2);
motorOnTime4(34, 44, 54, 64, time/2);
motorOnTime4(35, 45, 55, 65, time/2);
motorOnTime4(36, 46, 56, 66, time/2);
motorOnTime4(37, 47, 57, 67, time/2);
motorOnTime4(38, 48, 58, 68, time/2);
motorOnTime4(39, 49, 59, 69, time/2);
motorOnTime4(40, 50, 60, 70, time/2);

}

void braille(char l, int time){
    switch(l){
    case 'A':case 'a':
        brailleCell("100000", time);//A
        break;
    case 'B':case 'b':
        brailleCell("110000", time);//B
        break;
    case 'C':case 'c':
        brailleCell("100100", time);//C
        break;
    case 'D':case 'd':
        brailleCell("100110", time);//D
        break;
    case 'E':case 'e':
        brailleCell("100010", time);//E
        break;
    case 'F':case 'f':
        brailleCell("110100", time);//F
        break;
    case 'G':case 'g':
        brailleCell("110110", time);//G
        break;
    case 'H':case 'h':
        brailleCell("110010", time);//H
        break;
    case 'I':case 'i':
        brailleCell("010100", time);//I
        break;
    case 'J':case 'j':
        brailleCell("010110", time);//J
        break;
    case 'K':case 'k':
        brailleCell("101000", time);//K
        break;
    case 'L':case 'l':
        brailleCell("111000", time);//L
        break;
    case 'M':case 'm':
        brailleCell("101100", time);//M
        break;
    case 'N':case 'n':
        brailleCell("101110", time);//N
        break;
    case 'O':case 'o':
        brailleCell("101010", time);//O
        break;
    case 'P':case 'p':
        brailleCell("111100", time);//P
        break;
    case 'Q':case 'q':
        brailleCell("111110", time);//Q
        break;
    case 'R':case 'r':
        brailleCell("111010", time);//R
        break;
    case 'S':case 's':
        brailleCell("011100", time);//S
        break;
    case 'T':case 't':
        brailleCell("011110", time);//T
        break;
    case 'U':case 'u':
        brailleCell("101001", time);//U
        break;
    case 'V':case 'v':
        brailleCell("111001", time);//V
        break;
    case 'W':case 'w':
        brailleCell("010111", time);//W
        break;
    case 'X':case 'x':
        brailleCell("101101", time);//X
        break;
    case 'Y':case 'y':
        brailleCell("101111", time);//Y
        break;
    case 'Z':case 'z':
        brailleCell("101011", time);//Z
        break;
    case '*':
    break;
    default:
        gpioDelay(50000);
        spaceBraille(time*2);
        gpioDelay(50000);
    break;
    }
}
