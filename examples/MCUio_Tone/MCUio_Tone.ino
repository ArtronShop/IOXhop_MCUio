/* File              : MCUio_Tone.ino 
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include <IOXhop_MCUio.h>

IOXhop_MCUio mcu(8);
// IOXhop_MCUio mcu(8, D1, D2); // if you use ESP8266 / ESP32, you can select SDA and SCL pin.

void setup() {
  Serial.begin(9600); // Setup serial
  delay(2000); // Wait MCU setup
  mcu.mode(9, OUTPUT); // Set pin 9 to OUTPUT mode
}

void loop() {
  mcu.tone(9, 2000); // Send sound 2KHz to pin 2
  delay(1000);
  mcu.Dtone(9); // Cancel send sound to pin 2
  delay(1000);
}