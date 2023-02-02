

void setup() { 
  pinMode(3, OUTPUT);
}

void beep(double freq, double length, int pause) {
  for (int j = 0; j < freq * length / 1000; j++) { // See NOTE on rest_count
    digitalWrite(3,HIGH);
    delay(1000 / freq / 2);
  
    digitalWrite(3, LOW);
    delay(1000 / freq / 2);
  }
      
  delay(pause); 
}

void loop() {


  beep(500, 1500, 500);
  beep(2x00, 1500, 500);

}

