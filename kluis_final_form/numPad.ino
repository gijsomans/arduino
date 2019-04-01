//in deze functie word de keypad uitgelezen en word de buzzer en de led aan en uitgezet
void numPad() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(row[i], HIGH);
  }
  value = 0;
  keyPressed = 0;
  while (value == 0) {

    for (int x = 0; x < 4; x++) {
      digitalWrite(row[x], LOW);
      for (int y = 0; y < 3; y++) {
        if (digitalRead(colom[y]) == LOW)
        {
          if (numbers[x][y] == 10 || numbers[x][y] == 12) {
            value = numbers[x][y];
          } else {
            value = numbers[x][y];
            keyPressed = 1;
          }
        }
      }
      digitalWrite(row[x], HIGH);
    }

    if (keyPressed == 1)
    {
      tone(16, 400, 200);
      digitalWrite(19, HIGH);
      delay(200);
      digitalWrite(19, LOW);
    }
  }
}
