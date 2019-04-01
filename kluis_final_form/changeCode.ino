// dit is de functie om de code te veranderen
void changeCode()
{
  for (int i = 0; i < 4; i++) {
    numPad();
    pinCode[i] = value;
    EEPROM.write(i,value);
  }
}
