const int buzzer = 8;

int echoPin = 2; 
int trigPin = 3; 
 
void setup() {

      Serial.begin (9600); 
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    
  pinMode(buzzer, OUTPUT);

}

void loop() {


      int duration, cm; 
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
    duration = pulseIn(echoPin, HIGH); 
    cm = duration / 58;
    Serial.print(duration); 
    Serial.println(" cm"); 



  const int f = duration;
  tone(buzzer, f);
  delay(100);
  noTone(buzzer);
  if(duration > 0) {
    delay(duration/10 );  
  }
  


}
