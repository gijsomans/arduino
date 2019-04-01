#include <EEPROM.h>

//dit is de variabele voor de ingevoerde waarde
int value;

//dit zijn een paar variabelen om een aantal dingen te tellen
int keyPressed = 0;
int button = 0;
int eggCount = 0;
int pinCount= 0;

//dit zijn arrays voor de keypad
int colom[3] = {9,7,5};
int row[4] = {8,12,6,4};
int numbers[4][3]={
{1,2,3},
{4,5,6},
{7,8,9},
{10,11,12}
};

//dit zijn de arrays voor het invoeren en checken van de pincode
int enterCode[4] = {0, 0, 0, 0};
int pinCode[4];
int eggCode [3] = {11,6,6};

void setup() {
  // begin serial connection
  Serial.begin(9600);
  pinSetup();
}
 
void loop(){
  //hier word de pincode uit de EEPROM gehaald
  for(int i = 0; i < 4; i++){
    pinCode[i] = EEPROM.read(i);
  }
  //dit zijn de functies om de kluis te laten werken
  inputCode();
  printCode();
  checkCode();
  unlockVault();
  
}
