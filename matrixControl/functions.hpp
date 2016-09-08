#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED



#endif // FUNCTIONS_HPP_INCLUDED

#define COL1    0
#define COL2    1
#define COL3    4
#define COL4    17
#define COL5    27
#define COL6    22
#define COL7    10
#define COL8    9
#define COL9    11
#define COL10   5

#define ROW1    18
#define ROW2    23
#define ROW3    24
#define ROW4    25
#define ROW5    8
#define ROW6    7
#define ROW7    12
#define ROW8    16
#define ROW9    20
#define ROW10   21

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

void braillePointOnAlt(int point);
void braillePointOffAlt(int point);
void braillePointOnTimeAlt(int point, int time);
void brailleCell(char points[5], int time);


void configPins(){
        gpioSetMode(0, PI_OUTPUT);
        gpioSetMode(1, PI_OUTPUT);
        gpioSetMode(4, PI_OUTPUT);
        gpioSetMode(17, PI_OUTPUT);
        gpioSetMode(27, PI_OUTPUT);
        gpioSetMode(22, PI_OUTPUT);
        gpioSetMode(10, PI_OUTPUT);
        gpioSetMode(9, PI_OUTPUT);
        gpioSetMode(11, PI_OUTPUT);
        gpioSetMode(5, PI_OUTPUT);
        turnOffCol();
        gpioSetMode(18, PI_OUTPUT);
        gpioSetMode(23, PI_OUTPUT);
        gpioSetMode(24, PI_OUTPUT);
        gpioSetMode(25, PI_OUTPUT);
        gpioSetMode(8, PI_OUTPUT);
        gpioSetMode(7, PI_OUTPUT);
        gpioSetMode(12, PI_OUTPUT);
        gpioSetMode(16, PI_OUTPUT);
        gpioSetMode(20, PI_OUTPUT);
        gpioSetMode(21, PI_OUTPUT);
        turnOffRow();
        gpioSetPullUpDown(0, PI_PUD_DOWN);
        gpioSetPullUpDown(1, PI_PUD_DOWN);
        gpioSetPullUpDown(4, PI_PUD_DOWN);
        gpioSetPullUpDown(17, PI_PUD_DOWN);
        gpioSetPullUpDown(27, PI_PUD_DOWN);
        gpioSetPullUpDown(22, PI_PUD_DOWN);
        gpioSetPullUpDown(10, PI_PUD_DOWN);
        gpioSetPullUpDown(9, PI_PUD_DOWN);
        gpioSetPullUpDown(11, PI_PUD_DOWN);
        gpioSetPullUpDown(5, PI_PUD_DOWN);
        gpioSetPullUpDown(18, PI_PUD_DOWN);
        gpioSetPullUpDown(23, PI_PUD_DOWN);
        gpioSetPullUpDown(24, PI_PUD_DOWN);
        gpioSetPullUpDown(25, PI_PUD_DOWN);
        gpioSetPullUpDown(8, PI_PUD_DOWN);
        gpioSetPullUpDown(7, PI_PUD_DOWN);
        gpioSetPullUpDown(12, PI_PUD_DOWN);
        gpioSetPullUpDown(16, PI_PUD_DOWN);
        gpioSetPullUpDown(20, PI_PUD_DOWN);
        gpioSetPullUpDown(21, PI_PUD_DOWN);
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
int o=0;
switch(row){
    case 1:
    	gpioWrite(18, o);
    break;
    case 2:
        gpioWrite(23, o);
    break;
    case 3:
    	gpioWrite(24, o);
    break;
    case 4:
        gpioWrite(25, o);
    break;
    case 5:
    	gpioWrite(8, o);
    break;
    case 6:
        gpioWrite(7, o);
    break;
    case 7:
    	gpioWrite(12, o);
    break;
    case 8:
        gpioWrite(16, o);
    break;
    case 9:
    	gpioWrite(20, o);
    break;
    case 10:
        gpioWrite(21, o);
    break;
}
	printf("TURNED ON ROW%d", row);
	//o=1;
switch(col){
    case 1:
    	gpioWrite(0, o);
    break;
    case 2:
        gpioWrite(1, o);
    break;
    case 3:
    	gpioWrite(4, o);
    break;
    case 4:
        gpioWrite(17, o);
    break;
    case 5:
    	gpioWrite(27, o);
    break;
    case 6:
    gpioWrite(22, o);
    break;
    case 7:
    	gpioWrite(10, o);
    break;
    case 8:
        gpioWrite(9, o);
    break;
    case 9:
    	gpioWrite(11, o);
    break;
    case 10:
        gpioWrite(5, o);
    break;
}
    printf("TURNED ON COL%d\n", col);
    }

void turnOff(int row, int col){
int o=1;
switch(row){
    case 1:
    	gpioWrite(18, o);
    break;
    case 2:
        gpioWrite(23, o);
    break;
    case 3:
    	gpioWrite(24, o);
    break;
    case 4:
        gpioWrite(25, o);
    break;
    case 5:
    	gpioWrite(8, o);
    break;
    case 6:
        gpioWrite(7, o);
    break;
    case 7:
    	gpioWrite(12, o);
    break;
    case 8:
        gpioWrite(16, o);
    break;
    case 9:
    	gpioWrite(20, o);
    break;
    case 10:
        gpioWrite(21, o);
    break;
}
//o=0;
switch(col){
    case 1:
    	gpioWrite(0, o);
    break;
    case 2:
        gpioWrite(1, o);
    break;
    case 3:
    	gpioWrite(4, o);
    break;
    case 4:
        gpioWrite(17, o);
    break;
    case 5:
    	gpioWrite(27, o);
    break;
    case 6:
    gpioWrite(22, o);
    break;
    case 7:
    	gpioWrite(10, o);
    break;
    case 8:
        gpioWrite(9, o);
    break;
    case 9:
    	gpioWrite(11, o);
    break;
    case 10:
        gpioWrite(5, o);

    break;
}

}
void turnOffRow(){
int o=1;
    	gpioWrite(18, o);
        gpioWrite(23, o);
    	gpioWrite(24, o);
        gpioWrite(25, o);
    	gpioWrite(8, o);
        gpioWrite(7, o);
    	gpioWrite(12, o);
        gpioWrite(16, o);
    	gpioWrite(20, o);
        gpioWrite(21, o);
}
void turnOffCol(){
int o=1;
    	gpioWrite(0, o);
        gpioWrite(1, o);
    	gpioWrite(4, o);
        gpioWrite(17, o);
    	gpioWrite(27, o);
        gpioWrite(22, o);
    	gpioWrite(10, o);
        gpioWrite(9, o);
    	gpioWrite(11, o);
        gpioWrite(5, o);

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
			motorOn2(13, 14);
			break;
		case 5:
			motorOn2(53, 54);
			break;
		case 6:
			motorOn2(93, 94);
			break;
		case 1:
			motorOn2(17, 18);
			break;
		case 2:
			motorOn2(57, 58);
		break;
		case 3:
			motorOn2(97, 98);
		break;
		default:
			break;
	}
}

void braillePointOffAlt(int point){
	switch(point){
		case 4:
			motorOff2(13, 14);
			break;
		case 5:
			motorOff2(53, 54);
			break;
		case 6:
			motorOff2(93, 94);
			break;
		case 1:
			motorOff2(17, 18);
			break;
		case 2:
			motorOff2(57, 58);
		break;
		case 3:
			motorOff2(97, 98);
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
