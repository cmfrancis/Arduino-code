/* Not So Wireless Wireless Joystick USB Example
 * by: Alex Wende
 * SparkFun Electronics
 * date: 9/28/16
 * Modified by: Chris Francis
 * date: 1/14/17
 * Added: A,B,X,Y,Select,Start and Down buttons
 * 
 * license: Creative Commons Attribution-ShareAlike 4.0 (CC BY-SA 4.0)
 * Do whatever you'd like with this code, use it for any purpose.
 * Please attribute and keep this license.
 * 
 * This example sends ASCII arrow key characters over USB when the left
 * joystick is moved or keyboard presses when trigger or right buttonpad buttons are pressed.
 * Shoulder buttons act as 'Start' and 'Select' buttons similar to a NES gamepad.
 * Left joystick acts as a D-pad while right joystick buttons act as A,B,X,Y buttons. (SNES gamepad)
 * 
 * Hardware setup:
 * Left analog stick = installed. Right analog stick = NOT installed. 4 push buttons installed in place of 
 + right analog stick. Shoulder buttons = installed.

#include "Keyboard.h"

#define H_JOYSTICK    A2
#define V_JOYSTICK    A3
#define L_BUTTON      5       //Left stick button. Not used in this example.
#define R_TRIGGER     3
#define L_TRIGGER     6
#define A_BUTTON      9
#define B_BUTTON      2       //Also used as the right stick button if analog joystick installed.
#define X_BUTTON      8
#define Y_BUTTON      4


void setup() {
  pinMode(R_TRIGGER, INPUT_PULLUP);
  pinMode(L_TRIGGER, INPUT_PULLUP);
  pinMode(A_BUTTON, INPUT_PULLUP);
  pinMode(B_BUTTON, INPUT_PULLUP);
  pinMode(X_BUTTON, INPUT_PULLUP);
  pinMode(Y_BUTTON, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  uint16_t hStick = analogRead(H_JOYSTICK);
  uint16_t vStick = analogRead(V_JOYSTICK);

  if(hStick > 766) Keyboard.press(KEY_LEFT_ARROW);
  else if(hStick < 255) Keyboard.press(KEY_RIGHT_ARROW);
  else{
    Keyboard.release(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);
  }

  if(vStick > 766) Keyboard.press(KEY_UP_ARROW);
  else if(vStick < 255) Keyboard.press(KEY_DOWN_ARROW);
  else{
    Keyboard.release(KEY_UP_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);
  }

  if(digitalRead(L_TRIGGER) == LOW){        //Select
    Keyboard.press('2');
  }
  else{
    Keyboard.release('2');
  }

  if(digitalRead(R_TRIGGER) == LOW){        //Start
    Keyboard.press('1');
  }
  else{
    Keyboard.release('1');
  }

  if(digitalRead(A_BUTTON) == LOW){         //A
    Keyboard.press('a');
  }
  else{
    Keyboard.release('a');
  }
 
  if(digitalRead(B_BUTTON) == LOW){         //B
    Keyboard.press('b');
  }
  else{
    Keyboard.release('b');
  }
  
   if(digitalRead(X_BUTTON) == LOW){        //X
    Keyboard.press('x');
  }
  else{
    Keyboard.release('x');
  }
  
   if(digitalRead(Y_BUTTON) == LOW){        //Y
    Keyboard.press('y');
  }
  else{
    Keyboard.release('y');
  }
}
