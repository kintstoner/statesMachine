# States Machine Example
  Sometimes you will need to switch between whats going to be executed on the loop section,
  this is called the machine state, it can be multiple things like diferent methods of motor
  control, switching between manual or automatic modes...etc 

  This example demonstrates a simple states machine who will switch the RGB led color depending on wich
  state its actually running.

  Materials:
  
    - 2 push buttons.
    - 2 resistors (1 kOhm).
    - 3 resistors (220 Ohm).
    - RGB Led.
    

  The circuit:

    - Right pushbutton --> PIN 3
    - Left pushbutton --> PIN 2

    - RGB led to (9,11,10) PINS  // Red = 9 , Green = 11,  Blue = 10 //

  Created 28 January 2020
  By A.Roca
  
  https://github.com/kintstoner/statesMachine
