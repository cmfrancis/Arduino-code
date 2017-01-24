/* LucidTronix
   Daisy Chained Shift Registers
   74HC595 connected to 7-Segment LED display
   Tutorial at:
   http://www.lucidtronix.com/tutorials/40
   April 2013
*/

int dataPin = 7;
int latchPin = 5;
int clockPin = 6;

//                     HBCDEGFA
//                         0          1          2           3          4           5           6           7           8           9
//                        0x7B       0x60       0x5D        0x75       0x66        0x37        0x3F        0x61        0x7F        0x77
byte dec_digits[] = {0b01111011, 0b01100000, 0b01011101, 0b01110101, 0b01100110, 0b00110111, 0b00111111, 0b01100001, 0b01111111, 0b01110111 };

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int thousandsColumn = 0; thousandsColumn < 10; thousandsColumn++) {
    for (int hundredsColumn = 0; hundredsColumn < 10; hundredsColumn++) {
      for (int tensColumn = 0; tensColumn < 10; tensColumn++) {
        for (int onesColumn = 0; onesColumn < 10; onesColumn++) {
          // take the latchPin low so
          // the LEDs don't change while you're sending in bits:
          digitalWrite(latchPin, LOW);
          // shift out the bits:
          shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[onesColumn]);
          shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[tensColumn]);
          shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[hundredsColumn]);
          shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[thousandsColumn]);
          //take the latch pin high so the LEDs will light up:
          digitalWrite(latchPin, HIGH);
          // pause before next value:
          delay(100);
        }
      }
    }
  }
}


