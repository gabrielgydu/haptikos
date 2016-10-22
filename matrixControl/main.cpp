#include <iostream>
#include <pigpio.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sstream>

#include "functions.hpp"
#include "alphabet.hpp"
#include "braille.hpp"

using namespace std;

FILE *fp = NULL;
int j=0;
int tAlfabeto = 100;
string input;

int main()
{
  if (gpioInitialise() >= 0){
    configPins();
  }

  for(int j = 1; j<=100; j++)motorOnTime(j, 1);

  cout << "H A P T I K O S " << endl;
  do{
  cout << "Menu: " << endl
       << "1 - Haptices " << endl
       << "2 - Alfabeto de forma" << endl
       << "3 - Braille " << endl
       << "4 - Arquivo - Alfabeto " << endl
       << "5 - Arquivo - Braille " << endl
       //<< "6 -  " << endl
       //<< "7 -  " << endl
       << "8 - Ligar Motor " << endl
       << "0 - Configuracoes " << endl;

  if (!getline(cin, input))return -1;

  if (!input.empty()) {
    if(input[0] == '1'){
      do{
        input.clear();
        cout << "Haptices: " << endl;
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
        cout << "Alfabeto" << endl;
        int k=0;
        getline(cin, input);
        if(!input.empty()){
          while(input[k] != '\0'){
            letra(input[k], tAlfabeto);
            gpioDelay(1000000);
            k++;
          }
        }
      }while(input.compare("**") != 0);
    }else if(input[0] == '3'){
      do{
      input.clear();
      cout << "Braille" << endl;
      int k=0;
      getline(cin, input);
      if(!input.empty()){
        while(input[k] != '\0'){
          braille(input[k], 1000);
          k++;
          gpioDelay(2000000);

        }
      }
      }while(input.compare("**") != 0);
    }else if(input[0] == '4'){
      input.clear();
      cout << "Read file - Alphabet - " << endl;
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
      input.clear();
      cout << "Read file - Braille - " << endl;
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
    }else if(input[0] == '6'){
        motorOnTime(8, 1000);
        gpioDelay(1000000);
        motorOnTime(48, 1000);
        gpioDelay(1000000);
        motorOnTime(88, 1000);
        gpioDelay(1000000);
        motorOnTime(4, 1000);
        gpioDelay(1000000);
        motorOnTime(44, 1000);
        gpioDelay(1000000);
        motorOnTime(84, 1000);


    }else if(input[0] == '7'){
    for(int g=1; g<=100; g++){
    cout << "Motor: " << g << endl;
    motorOnTime(g, 500);
    }}else if(input[0] == 't'){
    do{
    input.clear();
    getline(cin, input);
    if(!input.empty()){
    if (input[0] == '1')
    brailleCell("100000", 1000);
    else if (input[0] == '2')
    brailleCell("010000", 1000);
    else if (input[0] == '3')
    brailleCell("001000", 1000);
    else if (input[0] == '4')
    brailleCell("000100", 1000);
    else if (input[0] == '5')
    brailleCell("000010", 1000);
    else if (input[0] == '6')
    brailleCell("000001", 1000);
    }
    }while(input[0] != '*');


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
    }else if(input[0] == '0'){
      do{
        input.clear();
        cout << "Configuracoes" << endl;
        cout << "1 - Tempo/Motor Alfabeto" << endl;
        getline(cin, input);
        if(!input.empty()){
          if(input[0] == '1'){
            cout << "Tempo atual: " << tAlfabeto << endl;
            cout << "Digite o novo tempo em ms:" << endl;
            getline(cin, input);
            if(!input.empty())
              stringstream(input) >> tAlfabeto;
              cout << "Novo tempo: " << tAlfabeto << endl;
          }
        }
      }while(input.compare("up") != 0);
    }
    }
}while(input.compare("exit"));
  gpioTerminate();
  return 0;
}
