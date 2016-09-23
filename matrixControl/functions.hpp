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

//void letraA();
//void letraB();
//void letraC();

void braillePointOn();
void braillePointOff();
void braillePointOnTime();

void braillePointOnAlt(int point);
void braillePointOffAlt(int point);
void braillePointOnTimeAlt(int point, int time);
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


void surpriseNew(){
93, 95, 96, 98

93, 95, 96, 98, 83, 85, 86, 88

83, 85, 86, 88

83, 85, 86, 88, 73, 75, 76, 78

73, 75, 76, 78

73, 75, 76, 78, 63, 65, 66, 68

63, 65, 66, 68

63, 65, 66, 68, 53, 55, 56, 58

53, 55, 56, 58

53, 55, 56, 58, 43, 45, 46, 48

43, 45, 46, 48

43, 45, 46, 48, 33, 34, 37, 38 

33, 34, 37, 38 

33, 34, 37, 38, 22, 23, 28, 29

22, 23, 28, 29

22, 23, 28, 29, 11, 12, 19, 20 

11, 12, 19, 20 

1, 11, 19, 10

1, 10

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
    motorOnTime(45, 150);
    motorOnTime2(44, 34, 150);
    motorOnTime2(43, 23, 150);
    motorOnTime2(42, 12, 150);
    motorOnTime2(41, 1, 150);
    gpioDelay(100000);
    motorOn4(44, 45, 46, 47);
    motorOn4(54, 55, 56, 57);
    gpioDelay(100000);
    motorOff4(44, 45, 46, 47);
    motorOff4(54, 55, 56, 57);
}

void fear(){
    for(int j=0; i<4; i++){
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
            motorOn4(3 , 4 , 13, 14);
            break;
        case 5:
            motorOn4(43, 44, 53, 54);
            break;
        case 6:
            motorOn4(83, 84, 93, 94);
            break;
        case 1:
            motorOn4(7 , 8 , 17, 18);
            break;
        case 2:
            motorOn4(47, 48, 57, 58);
        break;
        case 3:
            motorOn4(87, 88, 97, 98);
        break;
        default:
            break;
    }
}

void braillePointOff(int point){
    switch(point){
        case 4:
            motorOff4(3 , 4 , 13, 14);
            break;
        case 5:
            motorOff4(43, 44, 53, 54);
            break;
        case 6:
            motorOff4(83, 84, 93, 94);
            break;
        case 1:
            motorOff4(7 , 8 , 17, 18);
            break;
        case 2:
            motorOff4(47, 48, 57, 58);
        break;
        case 3:
            motorOff4(87, 88, 97, 98);
        break;
        default:
            break;
    }
}

void braillePointOnTime(int point, int time){
    switch(point){
        case 4:
            motorOnTime4(3 , 4 , 13, 14, time);
            break;
        case 5:
            motorOnTime4(43, 44, 53, 54, time);
            break;
        case 6:
            motorOnTime4(83, 84, 93, 94, time);
            break;
        case 1:
            motorOnTime4(7 , 8 , 17, 18, time);
            break;
        case 2:
            motorOnTime4(47, 48, 57, 58, time);
        break;
        case 3:
            motorOnTime4(87, 88, 97, 98, time);
        break;
        default:
            break;
    }
}

void braillePointOnAlt(int point){
	switch(point){
		case 4:
			motorOn(11);
			break;
		case 5:
			motorOn(51);
			break;
		case 6:
			motorOn(91);
			break;
		case 1:
			motorOn( 20);
			break;
		case 2:
			motorOn(60);
		break;
		case 3:
			motorOn( 100);
		break;
		default:
			break;
	}
}

void braillePointOffAlt(int point){
	switch(point){
		case 4:
			motorOff(11);
			break;
		case 5:
			motorOff(51);
			break;
		case 6:
			motorOff(91);
			break;
		case 1:
			motorOff( 20);
			break;
		case 2:
			motorOff( 60);
		break;
		case 3:
			motorOff( 100);
		break;
		default:
			break;
	}
}
void braillePointOnTimeAlt(int point, int time){
			braillePointOnAlt(point);
			gpioDelay(time*1000);
			braillePointOffAlt(point);
}

void brailleCell(char points[5], int time){
	for(int k =0; k<=5; k++){
		if(points[k] == '1')
			braillePointOnAlt(k+1);
	}
	gpioDelay(time*1000);
		for(int l =0; l<=5; l++){
		if(points[l] == '1')
			braillePointOffAlt(l+1);
	}

}
