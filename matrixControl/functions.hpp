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
    if (motorNumber <= 10){
        turnOn(1, motorNumber);
    }else if(motorNumber%10 == 0){
        turnOn((motorNumber/10), (motorNumber/(motorNumber/10)));
    }else{//Ex: 88 = (((88/10)+1), (88modulo10)
        turnOn((motorNumber/10)+1, motorNumber%10);
    }
}

void motorOff(int motorNumber){
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
//
//void letraA(){
//
//    motorOnTime(99, 125);
//    motorOnTime2(88, 89, 125);
//    motorOnTime(78, 125);
//    motorOnTime2(67, 68, 125);
//    motorOnTime2(57, 58, 125);
//    motorOnTime(47, 125);
//    motorOnTime2(36, 37, 125);
//    motorOnTime2(26, 27, 125);
//    motorOnTime2(15, 16, 125);
//    motorOnTime2(24, 25, 125);
//    motorOnTime2(34, 35, 125);
//    motorOnTime(44, 125);
//    motorOnTime2(53, 54, 125);
//    motorOnTime2(63, 64, 125);
//    motorOnTime(73, 125);
//    motorOnTime2(82, 83, 125);
//    motorOnTime(92, 125);
//
//    motorOnTime(68, 100);
//    motorOnTime2(68, 67, 50);
//    motorOnTime(67, 100);
//    motorOnTime2(67, 66, 50);
//    motorOnTime(66, 100);
//    motorOnTime2(66, 65, 50);
//    motorOnTime(65, 100);
//    motorOnTime2(65, 64, 50);
//    motorOnTime(64, 100);
//    motorOnTime2(64, 63, 50);
//    motorOnTime(63, 100);
//
//}
//
//void letraB(){
//
//    motorOnTime(18, 100);
//    motorOnTime(28, 100);
//    motorOnTime(38, 100);
//    motorOnTime(48, 100);
//    motorOnTime(58, 100);
//    motorOnTime(68, 100);
//    motorOnTime(78, 100);
//    motorOnTime(88, 100);
//    motorOnTime(98, 100);
//
//    motorOnTime(17, 100);
//    motorOnTime(16, 100);
//    motorOnTime2(15, 25, 125);
//    motorOnTime2(24, 25, 125);
//    motorOnTime(34, 100);
//    motorOnTime2(44, 45, 125);
//    motorOnTime(56, 100);
//    motorOnTime(57, 100);
//    motorOnTime(58, 100);
//    motorOnTime(57, 100);
//    motorOnTime(56, 100);
//    motorOnTime(55, 100);
//    motorOnTime(64, 100);
//    motorOnTime(74, 100);
//    motorOnTime(85, 100);
//    motorOnTime(96, 100);
//    motorOnTime(97, 100);
//    motorOnTime(98, 100);
//
//}
//
//void letraC(){
//    motorOnTime(33, 125);
//    motorOnTime2(23, 24, 125);
//    motorOnTime(14, 125);
//    motorOnTime(15, 125);
//    motorOnTime(16, 125);
//    motorOnTime(17, 125);
//    motorOnTime2(27, 28, 125);
//    motorOnTime2(38, 39, 125);
//    motorOnTime(49, 125);
//    motorOnTime(59, 125);
//    motorOnTime(69, 125);
//    motorOnTime2(79, 78, 125);
//    motorOnTime2(88, 87, 125);
//    motorOnTime(97, 125);
//    motorOnTime(96, 125);
//    motorOnTime(95, 125);
//    motorOnTime(94, 125);
//    motorOnTime2(84, 83, 125);
//    motorOnTime(73, 125);
//
//}


void surpriseNew(){
    motorOnTime(55, 200);
    motorOnTime4(45, 54, 56, 65, 200);
    motorOnTime4(44, 46, 64, 66, 200);
    motorOnTime4(35, 53, 75, 57, 200);
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
    motorOnTime3(46, 45, 55, 150);
    motorOnTime3(36, 34, 54, 150);
    motorOnTime3(26, 23, 53, 150);
    motorOnTime3(16, 12, 52, 150);
    motorOnTime3(6, 1, 51, 150);
    gpioDelay(50000);
//    motorOnTime4(45, 46, 55, 56, 150);
}

void fear(){
//    motorOnTime3(17, 23, 53, 200);
    motorOnTime3(16, 22, 52, 200);
//    motorOnTime3(17, 23, 53, 200);
    motorOnTime3(16, 22, 52, 200);
//    motorOnTime3(17, 23, 53, 200);
    motorOnTime3(16, 22, 52, 200);
//    motorOnTime3(17, 23, 53, 200);
    motorOnTime3(16, 22, 52, 200);
}

void happiness(){
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
}

void sadnessNew(){
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
