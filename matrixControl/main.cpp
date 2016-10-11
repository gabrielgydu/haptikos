#include <iostream>
#include <pigpio.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sstream>

#include "functions.hpp"
#include "alphabet.hpp"

using namespace std;

FILE *fp = NULL;
int j=0;
string input;

int main()
{
  if (gpioInitialise() >= 0){
    configPins();
  }

  for(int j = 1; j<=100; j++)motorOnTime(j, 1);

  cout << "H A P T I K O S " << endl;
  do{
  cout << "Enter command: " << endl
       << "1 - Old Haptices " << endl
       << "2 - New Haptices " << endl
       << "3 - Opt Haptices " << endl
       << "4 - Read File - Alphabet " << endl
       << "5 - Input - Alphabet " << endl
       << "6 - Read File - Braille " << endl
       << "7 - Input - Braille " << endl
       << "8 - Turn on motor " << endl;

  if (!getline(cin, input))return -1;

  if (!input.empty()) {
    if(input[0] == '1'){
      do{
      input.clear();
      cout << "Old Haptices - Select pattern: " << endl;
      getline(cin, input);
      if(!input.empty())
        if(!input.compare("an"))anger();
        else if(!input.compare("di"))disgust();
        else if(!input.compare("fe"))fear();
        else if(!input.compare("ha"))happiness();
        else if(!input.compare("sa"))sadness();
        else if(!input.compare("su"))surprise();
        else
          cout << "Invalid." << endl;
      }while(input.compare("up") != 0);
    }else if(input[0] == '2'){
      do{
      input.clear();
      cout << "New Haptices - Select pattern: " << endl;
      getline(cin, input);
      if(!input.empty())
        if(!input.compare("an"))angerNew();
        else if(!input.compare("di"))disgust();
        else if(!input.compare("fe"))fear();
        else if(!input.compare("ha"))happiness();
        else if(!input.compare("sa"))sadnessNew();
        else if(!input.compare("su"))surpriseNew1();
        //else if(!input.compare("su2"))surpriseNew2();
        //else if(!input.compare("su3"))surpriseNew3();
        //else if(!input.compare("su4"))surpriseNew4();
        else
          cout << "Invalid." << endl;
      }while(input.compare("up") != 0);
    }else if(input[0] == '3'){
      do{
      input.clear();
      cout << "Optimal Haptices - Select pattern: " << endl;
      getline(cin, input);
      if(!input.empty())
        if(!input.compare("an"))anger();
        else if(!input.compare("di"))disgust();
        else if(!input.compare("fe"))fear();
        else if(!input.compare("ha"))happiness();
        else if(!input.compare("sa"))sadness();
        else if(!input.compare("su"))surprise();
        else
          cout << "Invalid." << endl;
        }while(input.compare("up") != 0);
    }else if(input[0] == '4'){
      input.clear();
      cout << input << "Read file - Alphabet - " << endl;
      fp = fopen("input.txt", "r");
      if(!fp){
        cout << "Error opening file" << endl;
        break;
      }
      int k=0;
      char ch;
      while(ch != EOF){
        ch = fgetc(fp);
        letra(ch, 50);
        printf("%c\n", ch);
        gpioDelay(1000000);
      }
      fclose(fp);
    }else if(input[0] == '5'){
      do{
      input.clear();
      cout << input << "Input - Alphabet - " << endl;
      int k=0;
      getline(cin, input);
      if(!input.empty()){
        while(input[k] != '\0'){
          letra(input[k], 50);
          gpioDelay(1000000);
          k++;
        }
      }
      }while(input.compare("**") != 0);
    }else if(input[0] == '6'){
      input.clear();
      cout << input << "Read file - Braille - " << endl;
      fp = fopen("input.txt", "r");
      if(!fp){
        cout << "Error opening file" << endl;
        break;
      }
      int k=0;
      char ch;
      while(ch != EOF){
        ch = fgetc(fp);
        braille(ch, 1000);
        printf("%c\n", ch);
        gpioDelay(500000);
      }
      fclose(fp);
    }else if(input[0] == '7'){
      do{
      input.clear();
      cout << input << "Input - Braille - " << endl;
      int k=0;
      getline(cin, input);
      if(!input.empty()){
        while(input[k] != '\0'){
          braille(input[k], 2000);
          k++;
          gpioDelay(1000000);

        }
      }
      }while(input.compare("**") != 0);
    }else if(input[0] == '8'){
      input.clear();

      int m=0, time=100;

      cout << "Select motor by number: ";
      getline(cin, input);
      if(!input.empty()){
        stringstream(input) >> m;
        input.clear();

        cout << "For how long? (ms): ";
        getline(cin, input);
        if(!input.empty())
          stringstream(input) >> time;

        motorOnTime(m, time);
      }
    }else if(input[0] == 'c'){
    int j=1;
      do{
      input.clear();
      getline(cin, input);
      if(!input.empty()){
      //stringstream(input) >> j;
      cout << "Motor ON: "<< j << endl;
      motorOnTime(j, 1000);
      j++;

      }
      }while(input.compare("a") != 0);
      for(int k=1; k<= 100; k++)
      motorOff(k);
    }else if(input[0] == '9' && input[1] == '9'){
      //for(int k=1; k<= 100; k++)
      //motorOnTime(k, 1000);
        turnOn(10, 1);
        gpioDelay(1000000);
        turnOff(10, 1);

      /*for(int h=1; h<=12; h++){
      turnOn(0, h);
      gpioDelay(1000000);
      turnOff(0, h);
      gpioDelay(1000000);
      }*/

    }
  }
}while(input.compare("exit"));
  gpioTerminate();
  return 0;
}
