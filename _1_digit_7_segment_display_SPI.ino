/* This is example code for the SparkFun Large Digit Driver that uses SPI
 * Wiring is as follows:
 * Board-->Host
 *   GND-->GND
 *   LAT-->CS
 *   CLK-->SCK
 *   SER-->MOSI
 *   +5V-->5V
 *  +12V-->12V
*/ 
  
#include <SPI.h>

int CS = 10;

// This matches the configuration for the SFE Large Digit Driver and creates digits to be displayed.
//  Segments           HBCDEGFA
//  Digit                  0          1          2           3          4           5           6           7           8           9
//  Hex                   0x7B       0x60       0x5D        0x75       0x66        0x37        0x3F        0x61        0x7F        0x77
//  Binary             01111011    01100000    01011101    01110101    01100110    00110111    00111111    01100001    01111111    01110111

byte dec_digits[] = {0b01111011, 0b01100000, 0b01011101, 0b01110101, 0b01100110, 0b00110111, 0b00111111, 0b01100001, 0b01111111, 0b01110111 };

void setup() {
      //set pins to output so you can control the shift register
  pinMode(CS, OUTPUT);
  SPI.begin();
}

void loop() {
  for (int digitOne = 0; digitOne < 10; digitOne++) {
      // take the CS low so the LEDs don't change while you're sending in bits:
    digitalWrite(CS, LOW);
      // shift out the bits:
    SPI.transfer(dec_digits[digitOne]);
      //take the latch pin (CS) high so the LEDs will light up:
    digitalWrite(CS, HIGH);
      // pause before next value:
    delay(1000);
  }
}

