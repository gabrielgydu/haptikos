#ifndef ALPHABET_HPP_INCLUDED
#define ALPHABET_HPP_INCLUDED

#endif // ALPHABET_HPP_INCLUDED

void letraA(int time){
    motorOnTime(100, time);
    motorMultiplex(89, 90, 100, time/2);
    motorOnTime2(89, 90, time);
    motorMultiplex(89, 90, 79, time/2);
    motorOnTime(79, time);
    motorMultiplex(68, 69, 79, time/2);
    motorOnTime2(68, 69, time);
    motorMultiplex(68, 69, 58, time/2);
    motorOnTime(58, time);
    motorMultiplex(47, 48, 58, time/2);
    motorOnTime2(47, 48, time);
    motorMultiplex(47, 48, 37, time/2);
    motorOnTime(37, time);
    motorMultiplex(26, 27, 37, time/2);
    motorOnTime2(26, 27, time);
    motorMultiplex(26, 27, 16, time/2);
    motorOnTime(16, time);
    motorOnTime2(16, 15, time/2);
    motorOnTime(15, time);
    motorMultiplex(15, 24, 25, time/2);
    motorOnTime2(24, 25, time);
    motorMultiplex(34, 24, 25, time/2);
    motorOnTime(34, time);
    motorMultiplex(34, 44, 43, time/2);
    motorOnTime2(43, 44, time);
    motorMultiplex(53, 44, 43, time/2);
    motorOnTime(53, time);
    motorMultiplex(62, 63, 53, time/2);
    motorOnTime2(62, 63, time);
    motorMultiplex(62, 63, 72, time/2);
    motorOnTime(72, time);
    motorMultiplex(72, 81, 82, time/2);
    motorOnTime2(81, 82, time);
    motorMultiplex(91, 81, 82, time/2);
    motorOnTime(91, time);
    gpioDelay(time*5000);
    motorOnTime(68, time);
    motorOnTime2(67, 68, time/2);
    motorOnTime(67, time);
    motorOnTime2(66, 67, time/2);
    motorOnTime(66, time);
    motorOnTime2(65, 66, time/2);
    motorOnTime(65, time);
    motorOnTime2(64, 65, time/2);
    motorOnTime(64, time);
    motorOnTime2(63, 64, time/2);
    motorOnTime(63, time);
}

void letraB(int time){
        motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorOnTime2(88, 78, time/2);
    motorOnTime(88, time);
    motorOnTime2(98, 88, time/2);
    motorOnTime(98, time);

    motorOnTime(8, time);
    motorOnTime2(7, 8, time/2);
    motorOnTime(7, time);
    motorMultiplex(6, 16, 7, time/2);
    motorOnTime2(6, 16, time);
    motorMultiplex(15, 6, 16, time/2);
    motorOnTime(15, time);
    motorOnTime2(25, 15, time/2);
    motorOnTime(25, time);
    motorOnTime2(35, 25, time/2);
    motorOnTime(35, time);
    motorOnTime2(46, 35, time/2);
    motorOnTime(46, time);
    motorOnTime2(47, 46, time/2);
    motorOnTime(47, time);
    motorOnTime2(57, 47, time/2);
    motorOnTime(57, time);
    motorOnTime2(56, 57, time/2);
    motorOnTime(56, time);
    motorOnTime2(55, 56, time/2);
    motorOnTime(55, time);
    motorOnTime2(64, 55, time/2);
    motorOnTime(64, time);
    motorMultiplex(73, 74, 64, time/2);
    motorOnTime2(73, 74, time);
    motorMultiplex(84, 73, 74, time/2);
    motorOnTime(84, time);
    motorOnTime2(95, 84, time/2);
    motorOnTime(95, time);
    motorOnTime2(96, 95, time/2);
    motorOnTime(96, time);
    motorOnTime2(97, 96, time/2);
    motorOnTime(97, time);
}

void letraC(int time){
    motorOnTime(22, time);
    motorMultiplex(12, 13, 22, time/2);
    motorOnTime2(12, 13, time);
    motorMultiplex(4, 12, 13, time/2);
    motorOnTime(4, time);
    motorOnTime2(5, 4, time/2);
    motorOnTime(5, time);
    motorOnTime2(6, 5, time/2);
    motorOnTime(6, time);
    motorMultiplex(7, 17, 6, time/2);
    motorOnTime2(7, 17, time);
    //motorOnTime2(18, 28, time);motorOnTime2(7, 17, time);
    motorOnTime2(18, 28, time);
    motorMultiplex(39, 18, 28, time/2);
    motorOnTime(39, time);
    motorOnTime2(49, 39, time/2);
    motorOnTime(49, time);
    motorOnTime2(59, 49, time/2);
    motorOnTime(59, time);
    motorOnTime2(69, 59, time/2);
    motorOnTime(69, time);
    motorMultiplex(78, 88, 69, time/2);
    motorOnTime2(78, 88, time);
    //motorOnTime2(87, 97, time);motorOnTime2(78, 88, time);
    motorOnTime2(87, 97, time);
    motorMultiplex(96, 87, 97, time/2);
    motorOnTime(96, time);
    motorOnTime2(95, 96, time/2);
    motorOnTime(95, time);
    motorOnTime2(94, 95, time/2);
    motorOnTime(94, time);
    motorMultiplex(82,83, 94, time/2);
    motorOnTime2(82,83, time);
    motorMultiplex(72, 82, 83, time/2);
    motorOnTime(72, time);

}

void letraD(int time){
    motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorOnTime2(88, 78, time/2);
    motorOnTime(88, time);
    motorOnTime2(98, 88, time/2);
    motorOnTime(98, time);

    motorOnTime(8, time);
    motorOnTime2(7, 8, time/2);
    motorOnTime(7, time);
    motorOnTime2(6, 7, time/2);
    motorOnTime(6, time);
    motorOnTime2(5, 6, time/2);
    motorOnTime(5, time);
    motorMultiplex( 4, 14, 5, time/2);
    motorOnTime2(4, 14, time);
    motorOnTime2(13, 23, time);
    motorMultiplex(32, 13, 23, time/2);
    motorOnTime(32, time);
    motorOnTime2(42, 32, time/2);
    motorOnTime(42, time);
    motorOnTime2(52, 42, time/2);
    motorOnTime(52, time);
    motorOnTime2(62, 52, time/2);
    motorOnTime(62, time);
    motorMultiplex(72, 73, 62, time/2);
    motorOnTime2(72, 73, time);
    motorOnTime2(83, 84, time);
    motorMultiplex(95, 83, 84, time/2);
    motorOnTime(95, time);
    motorOnTime2(96, 95, time/2);
    motorOnTime(96, time);
    motorOnTime2(97, 96, time/2);
    motorOnTime(97, time);
    motorOnTime2(98, 97, time/2);
    motorOnTime(98, time);

}

void letraE(int time){
    motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorOnTime2(88, 78, time/2);
    motorOnTime(88, time);
    motorOnTime2(98, 88, time/2);
    motorOnTime(98, time);

    gpioDelay(250000);

    motorOnTime(8, time);
    motorOnTime2(7, 8, time/2);
    motorOnTime(7, time);
    motorOnTime2(6, 7, time/2);
    motorOnTime(6, time);
    motorOnTime2(5, 6, time/2);
    motorOnTime(5, time);
    motorOnTime2(4, 5, time/2);
    motorOnTime(4, time);

    gpioDelay(250000);

    motorOnTime(48, time);
    motorOnTime2(47, 48, time/2);
    motorOnTime(47, time);
    motorOnTime2(46, 47, time/2);
    motorOnTime(46, time);
    motorOnTime2(45, 46, time/2);
    motorOnTime(45, time);
    motorOnTime2(44, 45, time/2);
    motorOnTime(44, time);

    gpioDelay(250000);

    motorOnTime(98, time);
    motorOnTime2(97, 98, time/2);
    motorOnTime(97, time);
    motorOnTime2(96, 97, time/2);
    motorOnTime(96, time);
    motorOnTime2(95, 96, time/2);
    motorOnTime(95, time);
    motorOnTime2(94, 95, time/2);
    motorOnTime(94, time);




}

void letraF(int time){
        motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorOnTime2(88, 78, time/2);
    motorOnTime(88, time);
    motorOnTime2(98, 88, time/2);
    motorOnTime(98, time);

    gpioDelay(250000);

    motorOnTime(8, time);
    motorOnTime2(7, 8, time/2);
    motorOnTime(7, time);
    motorOnTime2(6, 7, time/2);
    motorOnTime(6, time);
    motorOnTime2(5, 6, time/2);
    motorOnTime(5, time);
    motorOnTime2(4, 5, time/2);
    motorOnTime(4, time);

    gpioDelay(250000);

    motorOnTime(48, time);
    motorOnTime2(47, 48, time/2);
    motorOnTime(47, time);
    motorOnTime2(46, 47, time/2);
    motorOnTime(46, time);
    motorOnTime2(45, 46, time/2);
    motorOnTime(45, time);
    motorOnTime2(44, 45, time/2);
    motorOnTime(44, time);
}

void letraG(int time){
    motorOnTime(12, time);
    motorMultiplex(3, 13, 12, time/2);
    motorOnTime2(3, 13, time);
    motorMultiplex(4, 3, 13, time/2);
    motorOnTime(4, time);
    motorOnTime2(5, 4, time/2);
    motorOnTime(5, time);
    motorOnTime2(6, 5, time/2);
    motorOnTime(6, time);
    motorOnTime2(7, 6, time/2);
    motorOnTime(7, time);
    motorMultiplex(8, 18, 7, time/2);
    motorOnTime2(8, 18, time);
    motorOnTime2(19, 29, time);
    motorMultiplex(40, 19, 29, time/2);
    motorOnTime(40, time);
    motorOnTime2(50, 40, time/2);
    motorOnTime(50, time);
    motorOnTime2(60, 50, time/2);
    motorOnTime(60, time);
    motorOnTime2(70, 60, time/2);
    motorOnTime(70, time);
    motorMultiplex(79, 89, 70, time/2);
    motorOnTime2(79, 89, time);
    motorOnTime2(88, 98, time);
    motorMultiplex(87, 88, 98, time/2);
    motorOnTime(87, time);
    motorOnTime2(96, 87, time/2);
    motorOnTime(96, time);
    motorOnTime2(95, 96, time/2);
    motorOnTime(95, time);
    motorOnTime2(94, 95, time/2);
    motorOnTime(94, time);
    motorMultiplex(83, 93, 94, time/2);
    motorOnTime2(83, 93, time);
    motorOnTime2(72, 82, time);
    motorMultiplex(61, 72, 82, time/2);
    motorOnTime(61, time);
    motorOnTime2(51, 61, time/2);
    motorOnTime(51, time);
    motorOnTime2(52, 51, time/2);
    motorOnTime(52, time);
    motorOnTime2(53, 52, time/2);
    motorOnTime(53, time);
    motorOnTime2(54, 53, time/2);
    motorOnTime(54, time);
    motorOnTime2(55, 54, time/2);
    motorOnTime(55, time);
    motorOnTime2(56, 55, time/2);
    motorOnTime(56, time);
    motorOnTime2(57, 56, time/2);
    motorOnTime(57, time);



}

void letraH(int time){
    motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorOnTime2(88, 78, time/2);
    motorOnTime(88, time);
    motorOnTime2(98, 88, time/2);
    motorOnTime(98, time);

    motorOnTime(3, time);
    motorOnTime2(13, 3, time/2);
    motorOnTime(13, time);
    motorOnTime2(23, 13, time/2);
    motorOnTime(23, time);
    motorOnTime2(33, 23, time/2);
    motorOnTime(33, time);
    motorOnTime2(43, 33, time/2);
    motorOnTime(43, time);
    motorOnTime2(53, 43, time/2);
    motorOnTime(53, time);
    motorOnTime2(63, 53, time/2);
    motorOnTime(63, time);
    motorOnTime2(73, 63, time/2);
    motorOnTime(73, time);
    motorOnTime2(83, 73, time/2);
    motorOnTime(83, time);
    motorOnTime2(93, 83, time/2);
    motorOnTime(93, time);

    motorOnTime(48, time);
    motorOnTime2(47, 48, time/2);
    motorOnTime(47, time);
    motorOnTime2(46, 47, time/2);
    motorOnTime(46, time);
    motorOnTime2(45, 46, time/2);
    motorOnTime(45, time);
    motorOnTime2(44, 45, time/2);
    motorOnTime(44, time);
    motorOnTime2(43, 44, time/2);
    motorOnTime(43, time);

}

void letraI(int time){
    motorOnTime2(5, 6, time);
    motorOnTime4(15, 16, 5, 6, time/2);
    motorOnTime2(15, 16, time);
    motorOnTime4(25, 26, 15, 16, time/2);
    motorOnTime2(25, 26, time);
    motorOnTime4(35, 36, 25, 26, time/2);
    motorOnTime2(35, 36, time);
    motorOnTime4(45, 46, 35, 36, time/2);
    motorOnTime2(45, 46, time);
    motorOnTime4(55, 56, 45, 46, time/2);
    motorOnTime2(55, 56, time);
    motorOnTime4(65, 66, 55, 56, time/2);
    motorOnTime2(65, 66, time);
    motorOnTime4(75, 76, 65, 66, time/2);
    motorOnTime2(75, 76, time);
    motorOnTime4(85, 86, 75, 76, time/2);
    motorOnTime2(85, 86, time);
    motorOnTime4(95, 96, 85, 86, time/2);
    motorOnTime2(95, 96, time);

}

void letraJ(int time){
    motorOnTime(5, time);
    motorOnTime2(15, 5, time/2);
    motorOnTime(15, time);
    motorOnTime2(25, 15, time/2);
    motorOnTime(25, time);
    motorOnTime2(35, 25, time/2);
    motorOnTime(35, time);
    motorOnTime2(45, 35, time/2);
    motorOnTime(45, time);
    motorOnTime2(55, 45, time/2);
    motorOnTime(55, time);
    motorOnTime2(65, 55, time/2);
    motorOnTime(65, time);
    motorOnTime2(75, 65, time/2);
    motorOnTime(75, time);
    motorOnTime2(85, 75, time/2);
    motorOnTime(85, time);
    motorOnTime2(96, 85, time/2);
    motorOnTime(96, time);
    motorOnTime2(97, 96, time/2);
    motorOnTime(97, time);
    motorOnTime2(88, 97, time/2);
    motorOnTime(88, time);
    motorOnTime2(78, 88, time/2);
    motorOnTime(78, time);
}

void letraK(int time){
    motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorOnTime2(88, 78, time/2);
    motorOnTime(88, time);
    motorOnTime2(98, 88, time/2);
    motorOnTime(98, time);

    motorOnTime(3, time);
    motorOnTime2(14, 3, time/2);
    motorOnTime(14, time);
    motorOnTime2(25, 14, time/2);
    motorOnTime(25, time);
    motorOnTime2(36, 25, time/2);
    motorOnTime(36, time);
    motorOnTime2(47, 36, time/2);
    motorOnTime(47, time);
    motorOnTime2(56, 47, time/2);
    motorOnTime(56, time);
    motorMultiplex(65, 75, 56, time/2);
    motorOnTime2(65, 75, time);
    motorMultiplex(84, 65, 75, time/2);
    motorOnTime(84, time);
    motorOnTime2(93, 84, time/2);
    motorOnTime(93, time);
}

void letraL(int time){
    motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorOnTime2(88, 78, time/2);
    motorOnTime(88, time);
    motorOnTime2(98, 88, time/2);
    motorOnTime(98, time);
    motorOnTime2(97, 98, time/2);
    motorOnTime(97, time);
    motorOnTime2(96, 97, time/2);
    motorOnTime(96, time);
    motorOnTime2(95, 96, time/2);
    motorOnTime(95, time);
    motorOnTime2(94, 95, time/2);
    motorOnTime(94, time);
    motorOnTime2(93, 94, time/2);
    motorOnTime(93, time);
    motorOnTime2(92, 93, time/2);
    motorOnTime(92, time);

}

void letraM(int time){
    motorOnTime(99, time);
    motorOnTime2(89, 99, time/2);
    motorOnTime(89, time);
    motorOnTime2(79, 89, time/2);
    motorOnTime(79, time);
    motorOnTime2(69, 79, time/2);
    motorOnTime(69, time);
    motorOnTime2(59, 69, time/2);
    motorOnTime(59, time);
    motorOnTime2(49, 59, time/2);
    motorOnTime(49, time);
    motorOnTime2(39, 49, time/2);
    motorOnTime(39, time);
    motorOnTime2(29, 39, time/2);
    motorOnTime(29, time);
    motorOnTime2(19, 29, time/2);
    motorOnTime(19, time);
    motorOnTime2(9, 19, time/2);
    motorOnTime(9, time);

    motorMultiplex(18, 19, 9, time/2);

    motorOnTime2(18, 19, time);
    motorMultiplex(28, 18, 19, time/2);
    motorOnTime(28, time);
    motorMultiplex(37, 38, 28, time/2);
    motorOnTime2(37, 38, time);
    motorMultiplex(47, 37, 38, time/2);
    motorOnTime(47, time);
    motorMultiplex(56, 57, 47, time/2);
    motorOnTime2(56, 57, time);
    motorMultiplex(66, 56, 57, time/2);
    motorOnTime(66, time);
    motorOnTime2(65, 66, time/2);
    motorOnTime(65, time);
    motorMultiplex(54, 55, 65, time/2);
    motorOnTime2(54, 55, time);
    motorMultiplex(44, 54, 55, time/2);
    motorOnTime(44, time);
    motorMultiplex(33, 34, 44, time/2);
    motorOnTime2(33, 34, time);
    motorMultiplex(23, 33, 34, time/2);
    motorOnTime(23, time);
    motorMultiplex(12, 13, 23, time/2);
    motorOnTime2(12, 13, time);

    motorMultiplex(2, 12, 13, time/2);

    motorOnTime(2, time);
    motorOnTime2(12, 2, time/2);
    motorOnTime(12, time);
    motorOnTime2(22, 12, time/2);
    motorOnTime(22, time);
    motorOnTime2(32, 22, time/2);
    motorOnTime(32, time);
    motorOnTime2(42, 32, time/2);
    motorOnTime(42, time);
    motorOnTime2(52, 42, time/2);
    motorOnTime(52, time);
    motorOnTime2(62, 52, time/2);
    motorOnTime(62, time);
    motorOnTime2(72, 62, time/2);
    motorOnTime(72, time);
    motorOnTime2(82, 72, time/2);
    motorOnTime(82, time);
    motorOnTime2(92, 82, time/2);
    motorOnTime(92, time);

}

void letraN(int time){

    motorOnTime(100, time);
    motorOnTime2(90, 100, time/2);
    motorOnTime(90, time);
    motorOnTime2(80, 90, time/2);
    motorOnTime(80, time);
    motorOnTime2(70, 80, time/2);
    motorOnTime(70, time);
    motorOnTime2(60, 70, time/2);
    motorOnTime(60, time);
    motorOnTime2(50, 60, time/2);
    motorOnTime(50, time);
    motorOnTime2(40, 50, time/2);
    motorOnTime(40, time);
    motorOnTime2(30, 40, time/2);
    motorOnTime(30, time);
    motorOnTime2(20, 30, time/2);
    motorOnTime(20, time);
    motorOnTime2(10, 20, time/2);
    motorOnTime(10, time);

    motorOnTime2(19, 10, time/2);

    motorOnTime(19, time);
    motorOnTime2(28, 19, time/2);
    motorOnTime(28, time);
    motorOnTime2(37, 28, time/2);
    motorOnTime(37, time);
    motorOnTime2(46, 37, time/2);
    motorOnTime(46, time);
    motorOnTime2(55, 46, time/2);
    motorOnTime(55, time);
    motorOnTime2(64, 55, time/2);
    motorOnTime(64, time);
    motorOnTime2(73, 64, time/2);
    motorOnTime(73, time);
    motorOnTime2(82, 73, time/2);
    motorOnTime(82, time);

    motorOnTime2(91, 82, time/2);

    motorOnTime(91, time);
    motorOnTime2(81, 91, time/2);
    motorOnTime(81, time);
    motorOnTime2(71, 81, time/2);
    motorOnTime(71, time);
    motorOnTime2(61, 71, time/2);
    motorOnTime(61, time);
    motorOnTime2(51, 61, time/2);
    motorOnTime(51, time);
    motorOnTime2(41, 51, time/2);
    motorOnTime(41, time);
    motorOnTime2(31, 41, time/2);
    motorOnTime(31, time);
    motorOnTime2(21, 31, time/2);
    motorOnTime(21, time);
    motorOnTime2(11, 21, time/2);
    motorOnTime(11, time);
    motorOnTime2(1, 11, time/2);
    motorOnTime(1, time);

}

void letraO(int time){
    motorOnTime(12, time);
    motorMultiplex(3, 13, 12, time/2);
    motorOnTime2(3, 13, time);
    motorMultiplex(4, 3, 13, time/2);
    motorOnTime(4, time);
    motorOnTime2(5, 4, time/2);
    motorOnTime(5, time);
    motorOnTime2(6, 5, time/2);
    motorOnTime(6, time);
    motorOnTime2(7, 6, time/2);
    motorOnTime(7, time);
    motorMultiplex(8, 18, 7, time/2);
    motorOnTime2(8, 18, time);
    motorOnTime2(19, 29, time);
    motorMultiplex(40, 19, 29, time/2);
    motorOnTime(40, time);
    motorOnTime2(50, 40, time/2);
    motorOnTime(50, time);
    motorOnTime2(60, 50, time/2);
    motorOnTime(60, time);
    motorOnTime2(70, 60, time/2);
    motorOnTime(70, time);
    motorMultiplex(79, 89, 70, time/2);
    motorOnTime2(79, 89, time);
    motorOnTime2(88, 98, time);
    motorMultiplex(87, 88, 98, time/2);
    motorOnTime(87, time);
    motorOnTime2(96, 87, time/2);
    motorOnTime(96, time);
    motorOnTime2(95, 96, time/2);
    motorOnTime(95, time);
    motorOnTime2(94, 95, time/2);
    motorOnTime(94, time);
    motorMultiplex(83, 93, 94, time/2);
    motorOnTime2(83, 93, time);
    motorOnTime2(72, 82, time);
    motorMultiplex(61, 72, 82, time/2);
    motorOnTime(61, time);
    motorOnTime2(51, 61, time/2);
    motorOnTime(51, time);
    motorOnTime2(41, 51, time/2);
    motorOnTime(41, time);
    motorOnTime2(31, 41, time/2);
    motorOnTime(31, time);
    motorMultiplex(12, 22, 31, time/2);
    motorOnTime2(12, 22, time);
}

void letraP(int time){
        motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorOnTime2(88, 78, time/2);
    motorOnTime(88, time);
    motorOnTime2(98, 88, time/2);
    motorOnTime(98, time);

    motorOnTime(8, time);
    motorOnTime2(7, 8, time/2);
    motorOnTime(7, time);
    motorOnTime2(6, 7, time/2);
    motorOnTime(6, time);
    motorMultiplex(5, 15, 6, time/2);
    motorOnTime2(5, 15, time);
    motorMultiplex(24, 5, 15, time/2);
    motorOnTime(24, time);
    motorOnTime2(34, 24, time/2);
    motorOnTime(34, time);
    motorMultiplex(44, 45, 34, time/2);
    motorOnTime2(44, 45, time);
    motorMultiplex(56, 44, 45, time/2);
    motorOnTime(56, time);
    motorOnTime2(57, 56, time/2);
    motorOnTime(57, time);
    motorOnTime2(58, 57, time/2);
    motorOnTime(58, time);
}

void letraQ(int time){
    motorOnTime(12, time);
    motorMultiplex(3, 13, 12, time/2);
    motorOnTime2(3, 13, time);
    motorMultiplex(4, 3, 13, time/2);
    motorOnTime(4, time);
    motorOnTime2(5, 4, time/2);
    motorOnTime(5, time);
    motorOnTime2(6, 5, time/2);
    motorOnTime(6, time);
    motorOnTime2(7, 6, time/2);
    motorOnTime(7, time);
    motorMultiplex(8, 18, 7, time/2);
    motorOnTime2(8, 18, time);
    motorOnTime2(19, 29, time);
    motorMultiplex(40, 19, 29, time/2);
    motorOnTime(40, time);
    motorOnTime2(50, 40, time/2);
    motorOnTime(50, time);
    motorOnTime2(60, 50, time/2);
    motorOnTime(60, time);
    motorOnTime2(70, 60, time/2);
    motorOnTime(70, time);
    motorMultiplex(79, 89, 70, time/2);
    motorOnTime2(79, 89, time);
    motorOnTime2(88, 98, time);
    motorMultiplex(87, 88, 98, time/2);
    motorOnTime(87, time);
    motorOnTime2(96, 87, time/2);
    motorOnTime(96, time);
    motorOnTime2(95, 96, time/2);
    motorOnTime(95, time);
    motorOnTime2(94, 95, time/2);
    motorOnTime(94, time);
    motorMultiplex(83, 93, 94, time/2);
    motorOnTime2(83, 93, time);
    motorOnTime2(72, 82, time);
    motorMultiplex(61, 72, 82, time/2);
    motorOnTime(61, time);
    motorOnTime2(51, 61, time/2);
    motorOnTime(51, time);
    motorOnTime2(41, 51, time/2);
    motorOnTime(41, time);
    motorOnTime2(31, 41, time/2);
    motorOnTime(31, time);
    motorMultiplex(12, 22, 31, time/2);
    motorOnTime2(12, 22, time);

    motorOnTime(64, time);
    motorOnTime2(73, 64, time/2);
    motorOnTime(73, time);
    motorOnTime2(82, 73, time/2);
    motorOnTime(82, time);
    motorOnTime2(91, 82, time/2);
    motorOnTime(91, time);
}

void letraR(int time){
    motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorOnTime2(88, 78, time/2);
    motorOnTime(88, time);
    motorOnTime2(98, 88, time/2);
    motorOnTime(98, time);

    motorOnTime(8, time);
    motorOnTime2(7, 8, time/2);
    motorOnTime(7, time);
    motorOnTime2(6, 7, time/2);
    motorOnTime(6, time);
    motorMultiplex(5, 15, 6, time/2);
    motorOnTime2(5, 15, time);
    motorMultiplex(24, 5, 15, time/2);
    motorOnTime(24, time);
    motorOnTime2(34, 24, time/2);
    motorOnTime(34, time);
    motorMultiplex(44, 45, 34, time/2);
    motorOnTime2(44, 45, time);
    motorMultiplex(56, 44, 45, time/2);
    motorOnTime(56, time);
    motorOnTime2(57, 56, time/2);
    motorOnTime(57, time);
    motorOnTime2(58, 57, time/2);
    motorOnTime(58, time);

    motorOnTime2(57, 58, time/2);

    motorOnTime(57, time);
    motorOnTime2(66, 57, time/2);
    motorOnTime(66, time);
    motorOnTime2(75, 66, time/2);
    motorOnTime(75, time);
    motorOnTime2(84, 75, time/2);
    motorOnTime(84, time);
    motorOnTime2(93, 84, time/2);
    motorOnTime(93, time);

}

void letraS(int time){

    motorOnTime(13, time);
    motorOnTime2(4, 13, time/2);
    motorOnTime(4, time);
    motorOnTime2(5, 4, time/2);
    motorOnTime(5, time);
    motorMultiplex(6, 16, 5, time/2);
    motorOnTime2(6, 16, time);
    motorMultiplex(17, 6, 16, time/2);
    motorOnTime(17, time);
    motorOnTime2(27, 17, time/2);
    motorOnTime(27, time);
    motorOnTime2(37, 27, time/2);
    motorOnTime(37, time);
    motorMultiplex(36, 46, 37, time/2);
    motorOnTime2(36, 46, time);
    motorMultiplex(45, 36, 46, time/2);
    motorOnTime(45, time);
    motorMultiplex(44, 54, 45, time/2);
    motorOnTime2(44, 54, time);
    //motorOnTime2(53, 54, time);motorOnTime2(44, 54, time);
    motorOnTime2(53, 54, time);
    motorMultiplex(63, 53, 54, time/2);
    motorOnTime(63, time);
    motorOnTime2(73, 63, time/2);
    motorOnTime(73, time);
    motorMultiplex(83, 84, 73, time/2);
    motorOnTime2(83, 84, time);
    //motorOnTime2(94, 95, time);motorOnTime2(83, 84, time);
    motorOnTime2(94, 95, time);
    motorMultiplex(96, 94, 95, time/2);
    motorOnTime(96, time);
    motorMultiplex(87, 97, 96, time/2);
    motorOnTime2(87, 97, time);
    //motorOnTime2(87, 88, time);motorOnTime2(87, 97, time);
    motorOnTime2(87, 88, time);
    motorMultiplex(78, 87, 88, time/2);
    motorOnTime(78, time);



}

void letraT(int time){
    motorOnTime2(8, 18, time);
    motorOnTime4(7, 17, 8, 18, time/2);
    motorOnTime2(7, 17, time);
    motorOnTime4(6, 16, 7, 17, time/2);
    motorOnTime2(6, 16, time);
    motorOnTime4(5, 15, 6, 16, time/2);
    motorOnTime2(5, 15, time);
    motorOnTime4(4, 14, 5, 15, time/2);
    motorOnTime2(4, 14, time);
    motorOnTime4(3, 13, 4, 14, time/2);
    motorOnTime2(3, 13, time);
    gpioDelay(time*5000);
    motorOnTime2(15, 16, time);
    motorOnTime4(25, 26, 15, 16, time/2);
    motorOnTime2(25, 26, time);
    motorOnTime4(35, 36, 25, 26, time/2);
    motorOnTime2(35, 36, time);
    motorOnTime4(45, 46, 35, 36, time/2);
    motorOnTime2(45, 46, time);
    motorOnTime4(55, 56, 45, 46, time/2);
    motorOnTime2(55, 56, time);
    motorOnTime4(65, 66, 55, 56, time/2);
    motorOnTime2(65, 66, time);
    motorOnTime4(75, 76, 65, 66, time/2);
    motorOnTime2(75, 76, time);
    motorOnTime4(85, 86, 75, 76, time/2);
    motorOnTime2(85, 86, time);
    motorOnTime4(95, 96, 85, 86, time/2);
    motorOnTime2(95, 96, time);
}

void letraU(int time){
        motorOnTime(8, time);
    motorOnTime2(18, 8, time/2);
    motorOnTime(18, time);
    motorOnTime2(28, 18, time/2);
    motorOnTime(28, time);
    motorOnTime2(38, 28, time/2);
    motorOnTime(38, time);
    motorOnTime2(48, 38, time/2);
    motorOnTime(48, time);
    motorOnTime2(58, 48, time/2);
    motorOnTime(58, time);
    motorOnTime2(68, 58, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);

    motorMultiplex(87, 88, 78, time/2);

    motorOnTime2(87, 88, time);
    motorMultiplex(96, 87, 88, time/2);
    motorOnTime(96, time);
    motorOnTime2(95, 96, time/2);
    motorOnTime(95, time);
    motorMultiplex(83, 84, 95, time/2);
    motorOnTime2(83, 84, time);

    motorMultiplex(73, 83, 84, time/2);

    motorOnTime(73, time);
    motorOnTime2(63, 73, time/2);
    motorOnTime(63, time);
    motorOnTime2(53, 63, time/2);
    motorOnTime(53, time);
    motorOnTime2(43, 53, time/2);
    motorOnTime(43, time);
    motorOnTime2(33, 43, time/2);
    motorOnTime(33, time);
    motorOnTime2(23, 33, time/2);
    motorOnTime(23, time);
    motorOnTime2(13, 23, time/2);
    motorOnTime(13, time);
    motorOnTime2(3, 13, time/2);
    motorOnTime(3, time);


}

void letraV(int time){
    motorOnTime(9, time);
    motorMultiplex(18, 19, 9, time/2);
    motorOnTime2(18, 19, time);
    motorMultiplex(28, 18, 19, time/2);
    motorOnTime(28, time);
    motorMultiplex(38, 100, 28, time/2);
    motorOnTime2(38, 100, time);
    motorOnTime4(47, 48, 38, 100, time/2);
    motorOnTime2(47, 48, time);
    motorMultiplex(57, 47, 48, time/2);
    motorOnTime(57, time);
    motorMultiplex(66, 67, 57, time/2);
    motorOnTime2(66, 67, time);
    motorMultiplex(76, 66, 67, time/2);
    motorOnTime(76, time);
    motorMultiplex(85, 86, 76, time/2);
    motorOnTime2(85, 86, time);
    motorMultiplex(75, 85, 86, time/2);
    motorOnTime(75, time);
    motorMultiplex(64, 65, 75, time/2);
    motorOnTime2(64, 65, time);
    motorMultiplex(54, 64, 65, time/2);
    motorOnTime(54, time);
    motorMultiplex(43, 44, 54, time/2);
    motorOnTime2(43, 44, time);
    motorMultiplex(33, 43, 44, time/2);
    motorOnTime(33, time);
    motorOnTime2(23, 33, time/2);
    motorOnTime(23, time);
    motorMultiplex(12, 13, 23, time/2);
    motorOnTime2(12, 13, time);
    motorMultiplex(2, 12, 13, time/2);
    motorOnTime(2, time);
}

void letraW(int time){
    motorOnTime(20, time);
    motorMultiplex(29, 30, 20, time/2);
    motorOnTime2(29, 30, time);
    motorMultiplex(39, 29, 30, time/2);
    motorOnTime(39, time);
    motorOnTime2(49, 39, time/2);
    motorOnTime(49, time);
    motorMultiplex(58, 59, 49, time/2);
    motorOnTime2(58, 59, time);
    motorMultiplex(68, 58, 59, time/2);
    motorOnTime(68, time);
    motorOnTime2(78, 68, time/2);
    motorOnTime(78, time);
    motorMultiplex(87, 88, 78, time/2);
    motorOnTime2(87, 88, time);
    motorMultiplex(77, 87, 88, time/2);
    motorOnTime(77, time);
    motorOnTime2(67, 77, time/2);
    motorOnTime(67, time);
    motorMultiplex(56, 57, 67, time/2);
    motorOnTime2(56, 57, time);
    motorOnTime4(46, 47, 56, 57, time/2);
    motorOnTime2(46, 47, time);
    motorMultiplex(36, 46, 47, time/2);
    motorOnTime(36, time);
    motorOnTime2(26, 36, time/2);
    motorOnTime(26, time);
    motorMultiplex(15, 16, 26, time/2);
    motorOnTime2(15, 16, time);
    motorMultiplex(25, 15, 16, time/2);
    motorOnTime(25, time);
    motorOnTime2(35, 25, time/2);
    motorOnTime(35, time);
    motorMultiplex(44, 45, 35, time/2);
    motorOnTime2(44, 45, time);
    motorOnTime4(54, 55, 44, 45, time/2);
    motorOnTime2(54, 55, time);
    motorMultiplex(64, 54, 55, time/2);
    motorOnTime(64, time);
    motorOnTime2(74, 64, time/2);
    motorOnTime(74, time);
    motorMultiplex(83, 84, 74, time/2);
    motorOnTime2(83, 84, time);
    motorMultiplex(73, 83, 84, time/2);
    motorOnTime(73, time);
    motorOnTime2(63, 73, time/2);
    motorOnTime(63, time);
    motorMultiplex(52, 53, 63, time/2);
    motorOnTime2(52, 53, time);
    motorMultiplex(42, 52, 53, time/2);
    motorOnTime(42, time);
    motorOnTime2(32, 42, time/2);
    motorOnTime(32, time);
    motorMultiplex(22, 22, 32, time/2);
    motorOnTime2(22, 22, time);
    motorMultiplex(11, 22, 22, time/2);
    motorOnTime(11, time);

}

void letraX(int time){
    motorOnTime(8, time);
    motorMultiplex(17, 18, 8, time/2);
    motorOnTime2(17, 18, time);
    motorMultiplex(27, 17, 18, time/2);
    motorOnTime(27, time);
    motorMultiplex(36, 37, 27, time/2);
    motorOnTime2(36, 37, time);
    motorMultiplex(46, 36, 37, time/2);
    motorOnTime(46, time);
    motorOnTime2(55, 46, time/2);
    motorOnTime(55, time);
    motorMultiplex(64, 65, 55, time/2);
    motorOnTime2(64, 65, time);
    motorMultiplex(74, 64, 65, time/2);
    motorOnTime(74, time);
    motorMultiplex(83, 84, 74, time/2);
    motorOnTime2(83, 84, time);
    motorMultiplex(93, 83, 84, time/2);
    motorOnTime(93, time);

    motorOnTime(3, time);
    motorMultiplex(13, 14, 3, time/2);
    motorOnTime2(13, 14, time);
    motorMultiplex(24, 13, 14, time/2);
    motorOnTime(24, time);
    motorMultiplex(34, 35, 24, time/2);
    motorOnTime2(34, 35, time);
    motorMultiplex(45, 34, 35, time/2);
    motorOnTime(45, time);
    motorOnTime2(56, 45, time/2);
    motorOnTime(56, time);
    motorMultiplex(66, 67, 56, time/2);
    motorOnTime2(66, 67, time);
    motorMultiplex(77, 66, 67, time/2);
    motorOnTime(77, time);
    motorMultiplex(87, 88, 77, time/2);
    motorOnTime2(87, 88, time);
    motorMultiplex(98, 87, 88, time/2);
    motorOnTime(98, time);

}

void letraY(int time){
    motorOnTime(8, time);
    motorMultiplex(17, 18, 8, time/2);
    motorOnTime2(17, 18, time);
    motorMultiplex(27, 17, 18, time/2);
    motorOnTime(27, time);
    motorMultiplex(36, 37, 27, time/2);
    motorOnTime2(36, 37, time);
    motorMultiplex(46, 36, 37, time/2);
    motorOnTime(46, time);

    motorOnTime(3, time);
    motorMultiplex(13, 14, 3, time/2);
    motorOnTime2(13, 14, time);
    motorMultiplex(24, 13, 14, time/2);
    motorOnTime(24, time);
    motorMultiplex(34, 35, 24, time/2);
    motorOnTime2(34, 35, time);
    motorMultiplex(45, 34, 35, time/2);
    motorOnTime(45, time);
    motorOnTime2(56, 45, time/2);
    motorOnTime(56, time);
    motorMultiplex(66, 67, 56, time/2);
    motorOnTime2(66, 67, time);
    motorMultiplex(77, 66, 67, time/2);
    motorOnTime(77, time);
    motorMultiplex(87, 88, 77, time/2);
    motorOnTime2(87, 88, time);
    motorMultiplex(98, 87, 88, time/2);
    motorOnTime(98, time);

}

void letraZ(int time){
    motorOnTime(8, time);
    motorOnTime2(7, 8, time/2);
    motorOnTime(7, time);
    motorOnTime2(6, 7, time/2);
    motorOnTime(6, time);
    motorOnTime2(5, 6, time/2);
    motorOnTime(5, time);
    motorOnTime2(4, 5, time/2);
    motorOnTime(4, time);
    motorOnTime2(3, 4, time/2);
    motorOnTime(3, time);

    gpioDelay(time*5000);

    motorMultiplex(13, 14, 3, time/2);

    motorOnTime2(13, 14, time);
    motorMultiplex(24, 13, 14, time/2);
    motorOnTime(24, time);
    motorMultiplex(34, 35, 24, time/2);
    motorOnTime2(34, 35, time);
    motorMultiplex(45, 34, 35, time/2);
    motorOnTime(45, time);
    motorOnTime2(56, 45, time/2);
    motorOnTime(56, time);
    motorMultiplex(66, 67, 56, time/2);
    motorOnTime2(66, 67, time);
    motorMultiplex(77, 66, 67, time/2);
    motorOnTime(77, time);
    motorMultiplex(87, 88, 77, time/2);
    motorOnTime2(87, 88, time);
    motorMultiplex(98, 87, 88, time/2);
    motorOnTime(98, time);

    gpioDelay(time*5000);
    
    motorOnTime2(97, 98, time/2);

    motorOnTime(97, time);
    motorOnTime2(96, 97, time/2);
    motorOnTime(96, time);
    motorOnTime2(95, 96, time/2);
    motorOnTime(95, time);
    motorOnTime2(94, 95, time/2);
    motorOnTime(94, time);
    motorOnTime2(93, 94, time/2);
    motorOnTime(93, time);
}

void space(int time){
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

void letra(char l, int time){
    switch(l){
    case 'A':case 'a':
        letraA(time);
    break;
    case 'B':case 'b':
        letraB(time);
    break;
    case 'C':case 'c':
        letraC(time);
    break;
    case 'D':case 'd':
        letraD(time);
    break;
    case 'E':case 'e':
        letraE(time);
    break;
    case 'F':case 'f':
        letraF(time);
    break;
    case 'G':case 'g':
        letraG(time);
    break;
    case 'H':case 'h':
        letraH(time);
    break;
    case 'I':case 'i':
        letraI(time);
    break;
    case 'J':case 'j':
        letraJ(time);
    break;
    case 'K':case 'k':
        letraK(time);
    break;
    case 'L':case 'l':
        letraL(time);
    break;
    case 'M':case 'm':
        letraM(time);
    break;
    case 'N':case 'n':
        letraN(time);
    break;
    case 'O':case 'o':
        letraO(time);
    break;
    case 'P':case 'p':
        letraP(time);
    break;
    case 'Q':case 'q':
        letraQ(time);
    break;
    case 'R':case 'r':
        letraR(time);
    break;
    case 'S':case 's':
        letraS(time);
    break;
    case 'T':case 't':
        letraT(time);
    break;
    case 'U':case 'u':
        letraU(time);
    break;
    case 'V':case 'v':
        letraV(time);
    break;
    case 'W':case 'w':
        letraW(time);
    break;
    case 'X':case 'x':
        letraX(time);
    break;
    case 'Y':case 'y':
        letraY(time);
    break;
    case 'Z':case 'z':
        letraZ(time);
    break;
    case '*':
    break;
    default:
        gpioDelay(50000);
        space(time*2);
        gpioDelay(50000);
    break;
    }
}

