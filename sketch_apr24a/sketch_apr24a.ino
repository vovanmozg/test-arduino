int RedPin = 11; //the Red pin connects to digital pin 11 on the arduino
int BluePin = 10; //the Blue pin connects to digital pin 10 on the arduino
int GreenPin = 9 ;//the Green pin connects to digital pin 11 on the arduino
int value; //this will hold the value of a for loop we will createint RedPin = 11; //the Red pin connects to digital pin 11 on the arduino

const int touchPin = 3;
//store the time when last event happened
unsigned long lastEvent = 0;
//store the state of LED
boolean ledOn = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(touchPin, INPUT);
}

int i = 1;

void loop() {

  //read touch sensor state
  int touchState = digitalRead(touchPin);

  //only interested in the HIGH signal
  if (touchState == HIGH) {
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(11, LOW);
    delay(500);
    
  }
  else {

    digitalWrite(12, LOW);
  }
  
    
}
