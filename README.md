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

### ลิขสิทธิ์การใช้งาน
ผู้จัดทำอนุญาตให้นำไปใช้งาน และแจกจ่ายได้โดยคงไว้ซึ่งที่มาของเนื้อหา ห้ามมีให้นำไปใช้งานในเชิงพาณีย์โดยตรง เช่น การนำไปจำหน่าย
 * http://www.ioxhop.com/
