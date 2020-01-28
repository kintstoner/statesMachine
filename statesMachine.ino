/*
  States Machine

  Sometimes you will need to switch between whats going to be executed on the loop section,
  this is called the machine state, it can be multiple things like diferent methods of motor
  control, switching between manual or automatic modes...etc 

  This example demonstrates a simple states machine who will switch the RGB led color depending on wich
  state its actually running.

  Materials:
  
    - 2 push buttons.
    - 3 resistors (220 Ohm).
    - RGB Led.
    

  The circuit:

  right pushbutton to PIN 3
  left pushbutton to PIN 2

  RGB led to (9,11,10) PINS  // Red = 9 , Green = 11,  Blue = 10 //
  Each Color pin of the RGB its connected trought a 220 Ohm resistor.

  Created 28 January 2020
  By A.Roca
  
  https://github.com/kintstoner/statesMachine

*/

//PinOut Variables
//RGB LED
const byte red_light_pin= 9;  
const byte green_light_pin = 11;
const byte blue_light_pin = 10;
//Push Buttons
const byte rightPin = 3;
const byte leftPin = 2;

//Changing Variables
int right = 0; // Variables for storing buttons digital input.
int left = 0;
int machineState = 1;  // Variable for store the machine-state.

void setup() {

  // declare INPUT buttons 
  pinMode(rightPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  
  machineState = 1; //initializes machine state to 1
  
}
void loop() {

  loopMachineState(); // States Machine Loop Function

  //Read digital inputs 
  right = digitalRead(rightPin);
  left = digitalRead(leftPin);

  //Check if buttons are pressed - delay added to prevent bouncing.
  // Since we are using INPUT_PULLUP the button its pressed on LOW state.
  
  if(right == LOW){ //if right button pressed. 
    
    machineState++; //increase machine state by one.
    delay(100); 
    
  
  }
  if(left == LOW){ //if left button pressed.
    
    machineState--; //decrease machine state by one.
    delay(100);
  
  }
  
}

void loopMachineState(){
  
  // Loops a State depending on machineState variable, initial state is "1".
  // You can make it non-rotable by putting machineState = 1 in case 0 and machineState = 4 in case 5.
  // You can also add as many states as u want !!
  
  switch(machineState){
    
    case 0:
      machineState = 4;
      // to make it rotable  when you go less than 1 jumps into the last state 4.
      break;
    case 1:
      RGB_color(255, 0, 0); // Red
      delay(100);
      break;
    case 2:
      RGB_color(0, 255, 0); // Green
      delay(100);
      break;
    case 3:
      RGB_color(0, 0, 255); // Blue
      delay(100);
      break;
    case 4:
      RGB_color(255, 255, 0); // Yellow
      delay(100);
      break;
    case 5:
      machineState = 1;
      // to make it rotable  when you go further than 4 jumps into the first state 1.
      break;
  
  }

}

// This is a function writes the output of the RGB led.

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
