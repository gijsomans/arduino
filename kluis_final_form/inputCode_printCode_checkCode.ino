void inputCode()
{//hier word de ingevoerde code in de array gezet 
  for (int i = 0; i < 4; i++) {
    numPad();
    enterCode[i] = value;
  }
}
void printCode()
{
  //hier word de code geprint zodat je kunt zien wat er ingevoerd is en wat de pincode is
  Serial.print("code: ");
  Serial.print(pinCode[0]);
  Serial.print(pinCode[1]);
  Serial.print(pinCode[2]);
  Serial.println(pinCode[3]);
  Serial.print("invoer: ");
  Serial.print(enterCode[0]);
  Serial.print(enterCode[1]);
  Serial.print(enterCode[2]);
  Serial.println(enterCode[3]);


}

//in deze functie word er gekeken of dat pincode klopt
void checkCode()
{
  eggCount = 0;
  pinCount = 0;
  for (int i = 0; i < 4; i++) {
    if (enterCode[i] == pinCode[i]) {
      pinCount++;
    }
  }
  Serial.print("aantal goed: ");
  Serial.println(pinCount);
  for (int i = 0; i < 3; i++) {
    if (enterCode[i] == eggCode[i]) {
      eggCount++;
    }
  }
}
