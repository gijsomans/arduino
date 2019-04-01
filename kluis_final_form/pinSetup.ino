void pinSetup() {
  pinMode(19, OUTPUT);  //geel led
  pinMode(16, OUTPUT);  //buzzer
  pinMode(17, OUTPUT);  //groen led
  pinMode(18, OUTPUT);  //rood led
  pinMode(14, OUTPUT);  //relais
  pinMode(15, INPUT_PULLUP); //set knop
  //configure alle collomen
  for(int i = 0; i < 3;i++){
  pinMode(colom[i], INPUT_PULLUP); //1 , 4, 6
  }
  //configure alle rijen
  for(int i = 0; i < 4;i++){
  pinMode(row[i], OUTPUT); //2,3,5,7
  }
}
