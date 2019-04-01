#include <EEPROM.h>
int highScore;
const int LED[4] = {7, 2, 3, 12};
const int BUTTON[4] = {6, 4, 5, 11};
const int BUZZER = 13;
int buttonpress = 0;
int counter = 0;
int level = 1;
int pattern[100];
int check[100];
int timedelay = 250;

void setup() {
  pinMode(BUZZER, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(BUTTON[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(LED[i], OUTPUT);
  }
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  highScore = EEPROM.read(0);
  Serial.print("highScore: ");
  Serial.println(highScore);
  makePattern();
  showPattern();
  //  Serial.print("pattern: ");
  for (int i = 0; i < level; i++) {
    //    Serial.print(pattern[i]);
    if (pattern[i] == 3)
    {
      Serial.print("geel");
    }
    if (pattern[i] == 2)
    {
      Serial.print("groen");
    }
    if (pattern[i] == 1)
    {
      Serial.print("blauw");
    }
    if (pattern[i] == 0)
    {
      Serial.print("rood");
    }
    Serial.print(",");
  }
  Serial.println(" ");
  inputCode();
  Serial.print("counter: ");
  Serial.println(counter);
  Serial.println(" ");
  if (counter == level) {
    if (timedelay > 100)
    {
      timedelay -= 25;
    }
    Serial.print("timedelay: ");
    Serial.println(timedelay);
    level++;
  } else {
    level = 0;
  }
}

int buttonpressed() {
  buttonpress = 5;
  while (buttonpress == 5) {
    for (int i = 0; i < 4; i++) {
      int lees = digitalRead(BUTTON[i]);
      if (lees == LOW) {
        if (i == 0) {
          tone(BUZZER, 330, timedelay);
        } else if (i == 1) {
          tone(BUZZER, 196, timedelay);
        } else if (i == 2) {
          tone(BUZZER, 392, timedelay);
        } else if (i == 3) {
          tone(BUZZER, 262, timedelay);
        }
        digitalWrite(LED[i], HIGH);
        delay(timedelay);
        digitalWrite(LED[i], LOW);
        delay(timedelay);
        buttonpress = i;
      }
    }
  }
  return buttonpress;
}

void makePattern() {
  long x = random(4);
  Serial.print("gekozen: ");
  Serial.println(x);
  pattern[level - 1] = x;
}

void showPattern() {
  for (int i = 0; i < level; i++) {
    if (pattern[i] == 0) {
      tone(BUZZER, 330, timedelay);
    } else if (pattern[i] == 1) {
      tone(BUZZER, 196, timedelay);
    } else if (pattern[i] == 2) {
      tone(BUZZER, 392, timedelay);
    } else if (pattern[i] == 3) {
      tone(BUZZER, 262, timedelay);
    }
    digitalWrite(LED[pattern[i]], HIGH);
    delay(timedelay);
    digitalWrite(LED[pattern[i]], LOW);
    delay(timedelay);
  }
}
void inputCode() {
  counter = 0;
  for (int i = 0; i < level; i++) {
    check[i] = buttonpressed();
    checkCode(i);
    Serial.print("button: ");
    Serial.println(check[i]);
  }
}
void checkCode(int i) {
  if (pattern[i] == check[i]) {
    counter++;
  }
  else if (pattern[i] != check[i])
  {
    timedelay = 250;
    level = 0;
  }
  if (level > highScore) {
    EEPROM.write(0, level - 1);
  }
}
