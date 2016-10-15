#ifndef BRAILLE_HPP_INCLUDED
#define BRAILLE_HPP_INCLUDED

#endif // BRAILLE_HPP_INCLUDED

void braillePointOn(int point){
	switch(point){
		case 4:
			motorOn2(1, 11);
			break;
		case 5:
			motorOn(41);
			break;
		case 6:
			motorOn2(81, 91);
			break;
		case 1:
			motorOn2(10, 20);
			break;
		case 2:
			motorOn(50);
		break;
		case 3:
			motorOn2(90, 100);
		break;
		default:
			break;
	}
}

void braillePointOff(int point){
    switch(point){
        case 4:
            motorOff2(1, 1);
            break;
        case 5:
            motorOff(41);
            break;
        case 6:
            motorOff2(81, 91);
            break;
        case 1:
            motorOff2(10, 20);
            break;
        case 2:
            motorOff(50);
        break;
        case 3:
            motorOff2(90, 100);
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
    motorOnTime4(31, 41, 51, 61, time/20);
    motorOnTime4(32, 42, 52, 62, time/20);
    motorOnTime4(33, 43, 53, 63, time/20);
    motorOnTime4(34, 44, 54, 64, time/20);
    motorOnTime4(35, 45, 55, 65, time/20);
    motorOnTime4(36, 46, 56, 66, time/20);
    motorOnTime4(37, 47, 57, 67, time/20);
    motorOnTime4(38, 48, 58, 68, time/20);
    motorOnTime4(39, 49, 59, 69, time/20);
    motorOnTime4(40, 50, 60, 70, time/20);

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
        spaceBraille(time);
        gpioDelay(50000);
    break;
    }
}