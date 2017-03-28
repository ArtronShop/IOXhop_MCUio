# IOXhop_MCUio Library for Arduino
## English

### Install
 * Download library file : https://github.com/ioxhop/IOXhop_MCUio/releases/download/1.0/IOXhop_MCUio.zip
 * Run arduino ide, click Sketch > Include Library > Add .ZIP Library...
 * Select file library
 * Finish !
 
### Devices Support
 * ESP8266 / ESP8285 / ESP32
 * All arduino boards
 
### License
This library open source. Copied, distributed for free
 * http://www.ioxhop.com/

## ภาษาไทย
ไลบารี่นี้ใช้สำหรับทำให้บอร์ด Arduino หรือไมโครคอนโทรลเลอร์เป็นอุปกรณ์ขยายพอร์ต เหมาะสำหรับใช้กับ ESP8266 ที่มีพอร์ตการเชื่อมต่อน้อย

### การ Setup บอร์ด

ให้อัพโหลด Sketch ลงบอร์ดให้ตรงชิป เช่น Arduino Uno R3 ใช้ชิป ATmega328 ก็ให้อัพโหลด Sketch ของ ATmega328 โดยใช้โปรแกรม Arduino ในการคอมไพล์และอัพโหลด

### การต่อวงจร

ให้ต่อขา SCL และ SDA ให้ตรงกัน ระหว่างบอร์ด Arduino ที่นำมาใช้เป็นตัวขยายพอร์ต กับบอร์ดที่นำมาใช้เป็นตัวสั่งงาน กรณีใช้บอร์ด ESP8266 / ESP8285 / ESP32 สามารถเลือกขา SCL SDA ได้ โดยในการสร้างออปเจค IOXhop_MCUio ให้ใส่ชื่อขาลงไปเพิ่มตามรูปแบบ IOXhop_MCUio(int devAddr, int sda, int scl)

### การติดตั้งไลบารี่
 * ดาว์โหลดไฟล์ไลบารี่ที่ https://github.com/ioxhop/IOXhop_MCUio/releases/download/1.0/IOXhop_MCUio.zip
 * เปิดโปรแกรม Arduino IDE ขึ้นมา จากนั้นกดไปที่ Sketch > Include Library > Add .ZIP Library...
 * เลือกไฟล์ที่ได้ดาว์โหลดไว้
 * เสร็จสิ้นการติดตั้ง

### รายการอุปกรณ์ที่ไลบารี่รองรับ
 * ESP8266 / ESP8285 / ESP32
 * บอร์ด Arduino ทุกรุ่น

### ตัวอย่าง

MCUio_Blink.ino

```Arduino
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
```

MCUio_AnalogReadSerial.ino

```Arduino
/* File              : MCUio_AnalogReadSerial.ino 
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include <IOXhop_MCUio.h>

IOXhop_MCUio mcu(8);
// IOXhop_MCUio mcu(8, D1, D2); // if you use ESP8266 / ESP32, you can select SDA and SCL pin.

void setup() {
  Serial.begin(9600); // Setup serial
  delay(2000); // Wait MCU setup
}

void loop() {
  int value = mcu.Aget(mcu.A0); // Read analog value from A0
  Serial.println(value); // Send value to Serial Monitor
  delay(10);
}
```

ดูตัวอย่างอื่น ๆ ได้ใน Examples


### รายละเอียดฟังก์ชั่น

#### IOXhop_MCUio(int devAddr, int sda = A4, int scl = A5) ;

**ค่าพารามิเตอร์**

*(int) devAddr* - ตำแหน่งของอุปกรณ์บนบัส I2C หากไม่แก้โค้ดใน Sketch จะมีค่าเป็น 0x08

*(int) sda* - หมายเลขขาที่ต่อกับขา SDA ของอุปกรณ์

*(int) scl* - หมายเลขขาที่ต่อกับขา SCL ของอุปกรณ์

**ค่าส่งกลับ**

ไม่มี

#### void IOXhop_MCUio::mode(int pin, int mode)

ใช้ตั้งโหมดของขา GPIO ให้เป็นอินพุต หรือเอาต์พุต

**ค่าพารามิเตอร์**

*(int) pin* - หมายเลขขา เช่น ขา 13 สามารถใส่ตัวเลขได้เลย แต่หากเป็นชื่อขา ให้ใส่ชื่อออปเจคที่สร้างไว้ข้างหน้า เช่น ขา A0 จะต้องใส่ mcu.A0

*(int) mode* - โหมดของขา สามารถเป็นไปได้ดังนี้

 * INPUT - ตั้งให้ขามีสถานะเป็นอินพุต
 * OUTPUT - ตั้งให้ขามีสถานะเป็นเอาต์พุต

**ค่าส่งกลับ**

ไม่มี

#### void IOXhop_MCUio::set(int pin, int lavel)

ใช้เขียนค่าแบบดิจิตอลออกขา GPIO (ต้องเรียกคำสั่งตั้งโหมดให้ขาที่ต้องการเป็น OUTPUT ก่อนด้วย)

**ค่าพารามิเตอร์**

*(int) pin* - หมายเลขขา

*(int) lavel* - สถานะทางลอจิกที่ต้องการ สามารถเป็นไปได้ดังนี้

 * HIGH - ตั้งให้ขามีสถานะทางดิจิตอลเป็นลอจิก 1 (HIGH)
 * LOW - ตั้งให้ขามีสถานะทางดิจิตอลเป็นลอจิก 0 (LOW)

**ค่าส่งกลับ**

ไม่มี


#### int IOXhop_MCUio::get(int pin)

ใช้อ่านสถานะแบบดิจิตอลที่ขา GPIO (ต้องเรียกคำสั่งตั้งโหมดให้ขาที่ต้องการเป็น INPUT ก่อนด้วย)

**ค่าพารามิเตอร์**

*(int) pin* - หมายเลขขา

**ค่าส่งกลับ**

*(int)* เป็นไปได้ดังนี้

 * ให้ค่า 1 เมื่อสถานะที่อ่านได้คือ HIGH
  * ให้ค่า 0 เมื่อสถานะที่อ่านได้เป็น LOW

#### int IOXhop_MCUio::Aget(int pin)

ใช้อ่านสถานะแบบอนาล็อกที่ขา GPIO โดยมีความละเอียด 10 บิต หรือ 0 - 1023 (รอรับเฉพาะขา A0 - A3)

**ค่าพารามิเตอร์**

*(int) pin* - หมายเลขขา (รอรับเฉพาะขา A0 - A3)

**ค่าส่งกลับ**

*(int)* ค่าที่ได้จะอยู่ในช่วง 0 - 1023 ที่แรงดันอ้างอิงเท่าแรงดัน VCC

### void IOXhop_MCUio::pwm(int pin, byte value)

เลือกใช้เอาต์พุตแบบ PWM ออกที่ขาดิจิตอล 3 5 6 10 และ 11

**ค่าพารามิเตอร์**

*(int) pin* - หมายเลขขา (รอรับเฉพาะขา 3 5 6 10 และ 11)

*(byte) value* - ความกว้างพัลส์ที่ต้องการ ความละเอียด 8 บิต หรืออยู่ในช่วง 0 - 255 โดยที่ 255 คือ 100%

**ค่าส่งกลับ**

ไม่มี

#### void IOXhop_MCUio::tone(int pin, int frequency)

ส่งสัญญาณเสียงความถี่ที่กำหนดออกที่ขา GPIO

**ค่าพารามิเตอร์**

*(int) pin* - หมายเลขขา

*(int) frequency* - ความถี่เสียงที่ต้องการ (สำหรับบัสเซอร์ แนะนำ 2000 หรือ 2KHz จะใช้เสียงดังที่สุด)

**ค่าส่งกลับ**

ไม่มี

#### IOXhop_MCUio::Dtone(int pin)

ยกเลิกการส่งสัญญาณเสียงออกที่ขา GPIO

**ค่าพารามิเตอร์**

*(int) pin* - หมายเลขขา

**ค่าส่งกลับ**

ไม่มี

### ลิขสิทธิ์การใช้งาน
ผู้จัดทำอนุญาตให้นำไปใช้งาน และแจกจ่ายได้โดยคงไว้ซึ่งที่มาของเนื้อหา ห้ามมีให้นำไปใช้งานในเชิงพาณีย์โดยตรง เช่น การนำไปจำหน่าย
 * http://www.ioxhop.com/
 
