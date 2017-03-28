/* File              : IOXhop_MCUio.cpp 
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include "IOXhop_MCUio.h"

IOXhop_MCUio::IOXhop_MCUio(int devAddr) {
	_devAddr = devAddr;
	Wire.begin();
}

#ifdef ESP8266
IOXhop_MCUio::IOXhop_MCUio(int devAddr, int sda, int scl) {
	_devAddr = devAddr;
	Wire.begin(sda, scl);
}
#endif // ESP8266

void IOXhop_MCUio::mode(int pin, int mode) {
	_i2cWrite(pin+1, mode == OUTPUT ? 0x01 : 0x0);
	/* Wire.beginTransmission(8);
	Wire.write(pin+1);
	Wire.write(mode == OUTPUT ? 0x01 : 0x0);
	Wire.endTransmission(); */
}

void IOXhop_MCUio::set(int pin, int lavel) {
	_i2cWrite(pin + 21, lavel == HIGH ? 0x01 : 0x0);
	/* Wire.beginTransmission(8);
	Wire.write(pin+21);
	Wire.write(laval == HIGH ? 0x01 : 0x0);
	Wire.endTransmission(); */
}

int IOXhop_MCUio::get(int pin) {
	return _i2cRead(pin+21);
	/* Wire.beginTransmission(8);
	Wire.write(pin+21);
	Wire.endTransmission(false);
	Wire.requestFrom(8, 1, true);
	delay(1);
	if (Wire.available()) {
		return Wire.read() == 0x01 ? HIGH : LOW;
	}
	return 0xFFFF; */
}

int IOXhop_MCUio::Aget(int pin) {
	if ((pin - 14 + 41) < 41) return 0xFFFF;
  
	Wire.beginTransmission(_devAddr);
	Wire.write((pin - 14) * 2 + 41);
	Wire.endTransmission(false);
	Wire.requestFrom((int)_devAddr, 2, true);
	delay(1);
	if (Wire.available()) {
		return Wire.read()|Wire.read()<<8;
	}
	return 0xFFFF;
}

void IOXhop_MCUio::pwm(int pin, byte value) {
	int addr = 0;
	if (pin == 3) addr = 53;
	else if (pin == 5) addr = 54;
	else if (pin == 6) addr = 55;
	else if (pin == 9) addr = 56;
	else if (pin == 10) addr = 57;
	else if (pin == 11) addr = 58;
	_i2cWrite(addr, value);
	/* Wire.beginTransmission(8);
	Wire.write(addr);
	Wire.write(value);
	Wire.endTransmission(); */
}

void IOXhop_MCUio::tone(int pin, int frequency) {
	Wire.beginTransmission(_devAddr);
	Wire.write(59);
	Wire.write((frequency>>8)&0xFF);
	Wire.write(60);
	Wire.write(frequency&0xFF);
	Wire.write(61);
	Wire.write((pin&0x0F)|0x10);
	Wire.endTransmission();
}

void IOXhop_MCUio::Dtone(int pin) {
	_i2cWrite(61, pin&0x0F);
	/* Wire.beginTransmission(8);
	Wire.write(61);
	Wire.write(pin&0x0F);
	Wire.endTransmission(); */
}

void IOXhop_MCUio::_i2cWrite(int addr, byte value) {
	Wire.beginTransmission(_devAddr);
	Wire.write(addr);
	Wire.write(value);
	Wire.endTransmission();
}

byte IOXhop_MCUio::_i2cRead(int addr) {
	Wire.beginTransmission(_devAddr);
	Wire.write(addr);
	Wire.endTransmission(false);
	Wire.requestFrom((int)_devAddr, 1, true);
	delay(1);
	if (Wire.available()) {
		return Wire.read() == 0x01 ? HIGH : LOW;
	}
	return 0xFF;
}
