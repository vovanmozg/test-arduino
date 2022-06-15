// Sound generation depending on the accelerometeron
// 
//
// D3 -> buzzer
// GND -> buzzer
// 3V3 -> gyro: VCC, SD0
// GND -> gyro: GND
// A4 -> gyro: SDA
// A5 -> gyro: SCL
// 
// Sources:
// http://adam-meyer.com/arduino/images/2011/06/L3G4200D-hookup2.png
// https://wikihandbk.com/wiki/Arduino:%D0%9F%D1%80%D0%B8%D0%BC%D0%B5%D1%80%D1%8B/Smoothing
// http://adam-meyer.com/arduino/L3G4200D

#include <Wire.h>

#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0x23
#define CTRL_REG5 0x24

int targetPin = 3;
int L3G4200D_Address = 105; //I2C address of the L3G4200D

int x;
int y;
int z;

int xAr[10];
int yAr[10];
int zAr[10];

int xTotal = 0;
int yTotal = 0;
int zTotal = 0;

int index = 0;
const int numReadings = 10;


void setup(){
  pinMode(3, OUTPUT);//buzzer
  pinMode(13, OUTPUT);//led indicator when singing a note


  Wire.begin();
  Serial.begin(9600);

  Serial.println("starting up L3G4200D");
  setupL3G4200D(2000); // Configure L3G4200  - 250, 500 or 2000 deg/sec

  delay(1500); //wait for the sensor to be ready 
}

int smooth(int val) {
   // берем последнее значение...
  xTotal = xTotal - xAr[index]; 
  // ...которое было считано от сенсора:
  xAr[index] = val; 
  // добавляем его к общей сумме:
  xTotal = xTotal + xAr[index];       
  // продвигаемся к следующему значению в массиве:  
  index = index + 1;                    

  // если мы в конце массива...
  if (index >= numReadings)              
    // ...возвращаемся к началу: 
    index = 0;                           

  // вычисляем среднее значение:
  return abs(xTotal / numReadings);         
}

void loop(){
   getGyroValues();  // This will update x, y, and z with new values

  Serial.print("X:");
  Serial.print(x);
  Serial.print(" ");
  Serial.print(smooth(x));
  
  Serial.print(" Y:");
  Serial.print(y);

  Serial.print(" Z:");
  Serial.println(z);

  long length = 50;
  long frequency = 400 + smooth(x);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  for (long i = 0; i < numCycles; i++) {
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  
  delay(100); //Just here to slow down the serial to make it more readable
}

void getGyroValues(){

  byte xMSB = readRegister(L3G4200D_Address, 0x29);
  byte xLSB = readRegister(L3G4200D_Address, 0x28);
  x = ((xMSB << 8) | xLSB);

  byte yMSB = readRegister(L3G4200D_Address, 0x2B);
  byte yLSB = readRegister(L3G4200D_Address, 0x2A);
  y = ((yMSB << 8) | yLSB);

  byte zMSB = readRegister(L3G4200D_Address, 0x2D);
  byte zLSB = readRegister(L3G4200D_Address, 0x2C);
  z = ((zMSB << 8) | zLSB);
}

int setupL3G4200D(int scale){
  //From  Jim Lindblom of Sparkfun's code

  // Enable x, y, z and turn off power down:
  writeRegister(L3G4200D_Address, CTRL_REG1, 0b00001111);

  // If you'd like to adjust/use the HPF, you can edit the line below to configure CTRL_REG2:
  writeRegister(L3G4200D_Address, CTRL_REG2, 0b00000000);

  // Configure CTRL_REG3 to generate data ready interrupt on INT2
  // No interrupts used on INT1, if you'd like to configure INT1
  // or INT2 otherwise, consult the datasheet:
  writeRegister(L3G4200D_Address, CTRL_REG3, 0b00001000);

  // CTRL_REG4 controls the full-scale range, among other things:

  if(scale == 250){
    writeRegister(L3G4200D_Address, CTRL_REG4, 0b00000000);
  }else if(scale == 500){
    writeRegister(L3G4200D_Address, CTRL_REG4, 0b00010000);
  }else{
    writeRegister(L3G4200D_Address, CTRL_REG4, 0b00110000);
  }

  // CTRL_REG5 controls high-pass filtering of outputs, use it
  // if you'd like:
  writeRegister(L3G4200D_Address, CTRL_REG5, 0b00000000);
}

void writeRegister(int deviceAddress, byte address, byte val) {
    Wire.beginTransmission(deviceAddress); // start transmission to device 
    Wire.write(address);       // send register address
    Wire.write(val);         // send value to write
    Wire.endTransmission();     // end transmission
}

int readRegister(int deviceAddress, byte address){

    int v;
    Wire.beginTransmission(deviceAddress);
    Wire.write(address); // register to read
    Wire.endTransmission();

    Wire.requestFrom(deviceAddress, 1); // read a byte

    while(!Wire.available()) {
        // waiting
    }

    v = Wire.read();
    return v;
}
