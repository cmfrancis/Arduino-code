/* 
   Four daisy Chained Shift Registers that create a 4 digit counter.
   74HC595 connected to 7-Segment LED display. The bit order corrosponds to the SparkFun Large Digit Driver
   but feel free to rearange your bits if you use a different order.
*/

int dataPin = 7;
int latchPin = 5;
int clockPin = 6;

// Segment letter in a 7 segment display:      HBCDEGFA
// Digit to display:       0          1          2           3          4           5           6           7           8           9
// Hex value:             0x7B       0x60       0x5D        0x75       0x66        0x37        0x3F        0x61        0x7F        0x77
byte dec_digits[] = {0b01111011, 0b01100000, 0b01011101, 0b01110101, 0b01100110, 0b00110111, 0b00111111, 0b01100001, 0b01111111, 0b01110111 };
// 0b means binary, 0 is off, 1 is on. We're turning on and off different segments here to create numbers on the display.

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int thousandsColumn = 0; thousandsColumn < 10; thousandsColumn++) {  //First digit  (Xnnn)
    for (int hundredsColumn = 0; hundredsColumn < 10; hundredsColumn++) {   //Second digit (nXnn)
      for (int tensColumn = 0; tensColumn < 10; tensColumn++) {             //Third digit  (nnXn)
        for (int onesColumn = 0; onesColumn < 10; onesColumn++) {           //Fourth digit (nnnX)
          
          // take the latchPin low so
          // the LEDs don't change while you're sending in bits:
          digitalWrite(latchPin, LOW);
          
          // shift out the bits:
          shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[onesColumn]);      //Write out first digit 
          shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[tensColumn]);      //Write out second digit
          shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[hundredsColumn]);  //Write out third digit
          shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[thousandsColumn]); //Write out fourth digit
          
          //take the latch pin high so the LEDs will light up:
          digitalWrite(latchPin, HIGH);
          
          // pause before next value:
          delay(100);
        }
      }
    }
  }
}
