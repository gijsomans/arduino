//in deze functie wordt de kluis geopent als de code klopt
void unlockVault()
{
  numPad();
  if (eggCount == 3 && value == 10) {
    egg();
  } else if (pinCount == 4 && value == 12) {
    Serial.println("code klopt");
    rightCode();
  } else if (pinCount != 4 && value == 12) {
    wrongCode();
  } else if (value == 10) {
    clearCode();
  }
}

//in de functie word als de code goed is en de reset knop niet ingedrukt is de kluis geopend
//als de reset knop wel ingedrukt is kun je de pincode veranderen 
void rightCode() {
  button = digitalRead(15);
  if (button == 0)
  {
    digitalWrite(18, HIGH);
    tone(16, 200, 250);
    delay(250);
    digitalWrite(19, LOW);
    delay(50);
    digitalWrite(19, HIGH);
    tone(16, 200, 250);
    delay(250);
    digitalWrite(19, LOW);
    digitalWrite(18, HIGH);
    changeCode();
    digitalWrite(18, LOW);

  } else {
    tone(16, 600, 1000);
    digitalWrite(17, HIGH);
    digitalWrite(14, HIGH);
    delay(1000);
    digitalWrite(14, LOW);
    digitalWrite(17, LOW);
    for (int i = 0; i < 4; i++) {
      enterCode[i] = 0;
    }
  }
}

//als de pincode niet klopt word deze functie uitgevoerd en gaat de kluis niet open
void wrongCode() {
  digitalWrite(18, HIGH);
  tone(16, 200, 500);
  delay(1000);
  digitalWrite(18, LOW);
  for (int i = 0; i < 4; i++) {
    enterCode[i] = 0;
  }
}

//als er op de clear knop word gedrukt wordt deze functie uitgevoerd en word de ingevoerde code gewist
void clearCode() {
  digitalWrite(19, HIGH);
  tone(16, 800, 250);
  delay(250);
  digitalWrite(19, LOW);
  delay(50);
  digitalWrite(19, HIGH);
  tone(16, 800, 250);
  delay(250);
  digitalWrite(19, LOW);
  for (int i = 0; i < 4; i++) {
    enterCode[i] = 0;
  }
}
