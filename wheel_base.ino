//#include "HID-Project.h"                                        // HID library, supports keyboard, mouse, gamepad, macro keypad, etc
//any references to HID stuff will be commented out for testing on the 2560.

//define pins
int steeringPin = A0;
int throttlePin = A2;
int brakePin = A4;
int clutchPin = A6;

//define integers for each axis
int steering;
int throttle;
int brake;
int clutch;

//integer for which pin to poll
int target;

void setup() {
   Serial.begin(115200);  // start serial for debugging
  //commented out for testing on 2650
  //Gamepad.begin(); //init gamepad HID
}

// returns INT value
int pollSensor(int target){
  int result = analogRead(target);                                  //read potentiometer pin
  result = map(result,0,1023,-32768,32767);                         //map to signed int -32k to 32k
  return(result);
}

void loop() {
                                                                        //polls each in turn and sets value in HID library  
  steering = pollSensor(steeringPin);                                   //read sensor first pass to switch ADC multiplexer to desired pin
  delay(10);                                                            //let ADC multiplexer switch fully to desired pin
  steering = pollSensor(steeringPin);                                   //read sensor again now that ADC multiplexer has fully switched
  //commented out for testing on 2650
  //Gamepad.xAxis(steering);                                            //set value for HID library
    
  throttle = pollSensor(throttlePin);
  delay(10);
  throttle = pollSensor(throttlePin);
  //commented out for testing on 2650
  //Gamepad.yAxis(throttle);
  
  
  brake = pollSensor(brakePin);
  delay(10);
  brake = pollSensor(brakePin);
  //commented out for testing on 2650
  //Gamepad.zAxis(brake);
  
  clutch = pollSensor(clutchPin);
  delay(10);
  clutch = pollSensor(clutchPin);
  //commented out for testing on 2650
  //Gamepad.rxAxis(clutch);

  //commented out for testing on 2650
  //Gamepad.write();                                                    //send HID data to PC
  
  Serial.println("steering: " + String(steering) + " throttle: " + String(throttle) + " brake: " + String(brake) + " clutch: " + String(clutch) );
  
}
