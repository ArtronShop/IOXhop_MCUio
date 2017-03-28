/* File              : MCUio_DigitalReadSerial.ino 
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include <IOXhop_MCUio.h>

IOXhop_MCUio mcu(8);
// IOXhop_MCUio mcu(8, D1, D2); // if you use ESP8266 / ESP32, you can select SDA and SCL pin.

void setup() {
  Serial.begin(9600); // Setup serial
  delay(2000); // Wait MCU setup
  mcu.mode(2, INPUT); // Set pin 2 to INPUT mode
}

void loop() {
  int value = mcu.get(2); // Read digital value from pin 2
  Serial.println(value); // Send value to Serial Monitor
  delay(10);
}