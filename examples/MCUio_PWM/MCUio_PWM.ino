/* File              : MCUio_PWM.ino 
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include <IOXhop_MCUio.h>

IOXhop_MCUio mcu(8);
// IOXhop_MCUio mcu(8, D1, D2); // if you use ESP8266 / ESP32, you can select SDA and SCL pin.

void setup() {
  delay(2000); // Wait MCU setup
  mcu.mode(9, OUTPUT); // Set pin 13 to OUTPUT
}

void loop() {
  int value = mcu.Aget(mcu.A0); // Read analog value from A0
  int pulse_width = map(value, 0, 1023, 0, 255); // Resolution resize
  mcu.pwm(9, pulse_width); // Use pin 9 in PWM mode
  delay(10);
}