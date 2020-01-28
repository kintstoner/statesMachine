# States Machine Example
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

    -right pushbutton to PIN 3
    -left pushbutton to PIN 2
    -RGB led to (9,11,10) PINS  // Red = 9 , Green = 11,  Blue = 10 //
    -Each Color pin of the RGB Led its connected trought a 220 Ohm resistor.
  
  Created 28 January 2020
  By A.Roca
  
  https://github.com/kintstoner/statesMachine
