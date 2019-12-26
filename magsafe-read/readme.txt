http://www.righto.com/2013/06/teardown-and-exploration-of-magsafe.html

How to read the ID number
It's very easy to read the ID number from a Magsafe connector using an Arduino board and a single 2K pullup resistor, along with Paul Stoffregen's Arduino 1-Wire library and a simple Arduino program.

The circuit to access a 1-Wire chip from an Arduino is trivial - just a 2K pullup resistor.
Touching the ground wire to an outer ground pin of the Magsafe connector and the data wire to the inner adapter sense pin will let the Arduino immediately read and display the 64-bit ID number. The charger does not need to be plugged in to the wall - and in fact I recommend not plugging it in - since one interesting feature of the 1-Wire protocol is the device can power itself parasitically off the data wire, without a separate power source.


The 64-bit ID can be read out of a Magsafe connector by probing the outer pin with ground, and the middle pin with the 1-Wire data line.
To make things more convenient, the serial number can be displayed on an LCD display. The circuit looks complicated, but it's just a tangle of wires connecting the LCD display. Using a simple program, the 64-bit ID number is displayed on the bottom line of the display. The top line is a legend indicating the components of the code: "cc" CRC check, "id." customer id, "ww" wattage, "r" revision, "serial" serial number, and "ff" family. The number below corresponds to an 85 watt charger (55 hex = 85 decimal).


A 1-Wire ID reader with LCD display. Touching the wires to the contacts of the Magsafe connector displays the ID code on the bottom line of the display. The top line indicates the components of the code: CRC check, customer id, wattage, revision, serial number, and family.