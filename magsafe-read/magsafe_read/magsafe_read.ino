// Experiment with the magsafe connector and the DS2413 1-Wire Dual Channel Addressable Switch
// More information at http://righto.com/magsafe
// Ken Shirriff
// www.righto.com
// For information on DS2413, see http://datasheets.maximintegrated.com/en/ds/DS2413.pdf


#include <OneWire.h>

OneWire net(10);  // on pin 10

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  // Read rom address
  net.reset();
  net.write(0x33, true /* power on */); // READ ROM
  byte addr[8];
  net.read_bytes(addr, 8);
  if (addr[0] == 0x00 || addr[0] == 0xff) {
    // No device present
    return;
  }
  for (int8_t i = 7; i >= 0; i--) {
    Serial.print(addr[i]>>4, HEX);
    Serial.print(addr[i]&0x0f, HEX);
  }
  Serial.println();
}
