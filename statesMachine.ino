/*
  States Machine

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

  right pushbutton to PIN 3
  left pushbutton to PIN 2

  RGB led to (9,11,10) PINS  // Red = 9 , Green = 11,  Blue = 10 //

  Created 28 January 2020
  By A.Roca
  
  http://url/of/online/tutorial.cc

*/

int red_light_pin= 9;
int green_light_pin = 11;
int blue_light_pin = 10;

int rightPin = 3;
int leftPin = 2;
int right = 0;
int left = 0;

int machineState = 0;

void setup() {
  
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);
  
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  
  machineState = 1;
  
}
void loop() {
  
  right = digitalRead(rightPin);
  left = digitalRead(leftPin);
  
  loopMachineState();
  
  if(right == HIGH){
    
    machineState++;
    
    delay(200);
    
  
  }
  if(left == HIGH){
    
    machineState--;
    
    delay(200);
  
  }
  
}

void loopMachineState(){
  
  switch(machineState){
    
    case 0:
      machineState = 4;
      
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
      
      break;
  
  }

}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
