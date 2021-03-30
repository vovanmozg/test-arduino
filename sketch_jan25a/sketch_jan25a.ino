void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);   

}

void loop() {

  for(int i=0; i<10; i++) {
    int p = 40;
    // put your main code here, to run repeatedly:
    digitalWrite(13, HIGH);   // зажигаем светодиод
    delay(p);              // ждем секунду
    digitalWrite(13, LOW);   // зажигаем светодиод
    delay(p);              // ждем секунду
  }

  digitalWrite(13, LOW);    // выключаем светодиод
  delay(1000);              // ждем секунду

}
