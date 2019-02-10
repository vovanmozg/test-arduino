int redpin = 10; //select the pin for the red LED
int bluepin =9; // select the pin for the  blue LED
int greenpin = 11;// select the pin for the green LED

int val;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}

int red = 0;
int green = 0;
int blue = 0;;


void loop() {
  red = random(2) * 255;
  blue = random(2) * 255;
  green = random(2) * 255;
  
  
  analogWrite(redpin, red);  //set PWM value for red
  analogWrite(bluepin, blue); //set PWM value for blue
  analogWrite(greenpin, green); //set PWM value for green
   
  delay(1000); 
  Serial.println(red); //print current value 
}
