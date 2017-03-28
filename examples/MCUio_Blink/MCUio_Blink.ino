/* File              : MCUio_Blink.ino 
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include <IOXhop_MCUio.h>

IOXhop_MCUio mcu(8);
// IOXhop_MCUio mcu(8, D1, D2); // if you use ESP8266 / ESP32, you can select SDA and SCL pin.

void setup() {
  delay(2000); // Wait MCU setup
  mcu.mode(13, OUTPUT); // Set pin 13 to OUTPUT
}

void loop() {
  mcu.set(13, HIGH); // Set pin 13 to logic 1 (HIGH)
  delay(500);
  mcu.set(13, LOW); // Set pin 13 to logic 0 (LOW)
  delay(500);
}