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
int redi = 1;
int green = 0;
int greeni = 1;
int blue = 0;
int bluei = 1;


void loop() {
  red += redi;
  blue += bluei;
  green += greeni;
  
  if (red > 255) { 
    red = 255;
    redi = -1;
  }

  if (red < 0) {
    red = 0;
    redi = 1;
  }
  
  if (blue > 255) {
    blue = 255;
    bluei = -2;
  }

  if (blue < 0) {
    blue = 0;
    bluei = 2;
  }

  if (green > 255) {
    green = 255;
    greeni = -3;
  }

  if (green < 0) {
    green = 0;
    greeni = 3;
  }
  
  analogWrite(redpin, red);  //set PWM value for red
  analogWrite(bluepin, blue); //set PWM value for blue
  analogWrite(greenpin, green); //set PWM value for green
   
  delay(30); 
  Serial.println(red); //print current value 
}

void loop2() 
{
  for(val = 255; val > 0; val--)
  {
    analogWrite(redpin, val);  //set PWM value for red
    analogWrite(bluepin, 255 - val); //set PWM value for blue
    analogWrite(greenpin, 128 - val); //set PWM value for green
    Serial.println(val); //print current value 
    delay(100); 
  }
  for(val = 0; val < 255; val++)
  {
    analogWrite(redpin, val);
    analogWrite(bluepin, 255 - val);
    analogWrite(greenpin, 128 - val);
    Serial.println(val);
    delay(100); 
  }
}
