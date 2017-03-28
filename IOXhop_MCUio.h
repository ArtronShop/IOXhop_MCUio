/* File              : IOXhop_MCUio.h 
   Codeing By IOXhop : www.ioxhop.com
   Sonthaya Nongnuch : www.fb.me/maxthai */

#include "Arduino.h"
#include "Wire.h"

class IOXhop_MCUio {
	public:
		
		// Define pin
		int A0 = 14, A1 = 15, A2 = 16, A3 = 17, A4 = 18, A5 = 19;
		
		IOXhop_MCUio(int devAddr) ;
		#ifdef ESP8266
		IOXhop_MCUio(int devAddr, int sda, int scl) ;
		#endif // ESP8266
		
		void mode(int pin, int mode) ;
		void set(int pin, int lavel) ;
		int get(int pin) ;
		int Aget(int pin) ;
		void pwm(int pin, byte value) ;
		void tone(int pin, int frequency) ;
		void Dtone(int pin) ;
		
	private:
		byte _devAddr = 0x0;
		void _i2cWrite(int addr, byte value) ;
		byte _i2cRead(int addr) ;

}
;