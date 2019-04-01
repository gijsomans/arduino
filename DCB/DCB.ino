int tijd;
byte cijfer[11][4] =
{ { 0, 0, 0, 0 }, // = 0
  { 0, 0, 0, 1 }, // = 1
  { 0, 0, 1, 0 }, // = 2
  { 0, 0, 1, 1 }, // = 3
  { 0, 1, 0, 0 }, // = 4
  { 0, 1, 0, 1 }, // = 5
  { 0, 1, 1, 0 }, // = 6
  { 0, 1, 1, 1 }, // = 7
  { 1, 0, 0, 0 }, // = 8
  { 1, 0, 0, 1 }, // = 9
  { 1, 1, 1, 1 } // = 0
};

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  digitalWrite(13, 1);
  digitalWrite(12, 1);
  digitalWrite(11, 1);
  digitalWrite(10, 1);
}

void schrijven_cijfer(byte digit) 
{
  digitalWrite(13, cijfer[digit][3]);
  digitalWrite(12, cijfer[digit][2]);
  digitalWrite(11, cijfer[digit][1]);
  digitalWrite(10, cijfer[digit][0]);
}

void loop() 
{
  tijd = 500 ;
  for (int i = 0; i <= 9; ++i)
  {
    schrijven_cijfer(i) ;
    delay(tijd);
  }

  tijd = 250 ;
  for (int i = 8; i >= 0; --i)
  {
    schrijven_cijfer(i) ;
    delay(tijd);
  }
}
