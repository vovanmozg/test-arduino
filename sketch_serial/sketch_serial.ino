#include <stdarg.h>

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(counter++);  // prints hello with ending line break 
  delay(1000);
}
