// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
#include <String.h>
#include "command.h"
#include <PID_v1.h>

#define panPin 3
#define tiltPin 5
#define LED 13


Servo panservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo tiltservo;
command_t serialCommand;
 
String inputString = "";
boolean stringComplete = false;

//Define Variables we'll be connecting to
double Setpoint_pan, Input_pan, Output_pan;
PID panPID(&Input_pan, &Output_pan, &Setpoint_pan,0,100,0, DIRECT);

double Setpoint_tilt, Input_tilt, Output_tilt;
PID tiltPID(&Input_tilt, &Output_tilt, &Setpoint_tilt,0,100,0, DIRECT);
 
void setup() 
{ 
  panservo.attach(panPin);  // attaches the servo on pin 3 and 5 to the servo object 
  tiltservo.attach(tiltPin);
  Serial.begin(115200);
  inputString.reserve(200);
  pinMode(LED, OUTPUT);
  panPID.SetOutputLimits(1000,2000);
  tiltPID.SetOutputLimits(1000,2000);
  panPID.SetSampleTime(10);
  tiltPID.SetSampleTime(10);
  Setpoint_pan = 0;
  Setpoint_tilt = 0;
  Input_pan = 0;
  Input_tilt = 0;
  tiltPID.SetMode(AUTOMATIC);
  panPID.SetMode(AUTOMATIC);
} 
 
 
void loop() 
{ 
//  for(int i = 1000; i < 2000; i++){
//    tiltservo.writeMicroseconds(i);
//    panservo.writeMicroseconds(i);
//    delay(100);
//  }
//  for(int i = 2000; i > 1000; i--){
//    tiltservo.writeMicroseconds(i);
//    panservo.writeMicroseconds(i);
//    //delay(100);
//  }
  if(stringComplete){
    Serial.println(inputString); 
    // clear the string:
    serialCommand = serialCommandParse(inputString);
//    Serial.println(serialCommand.panError);
//    Serial.println(serialCommand.tiltError);
//    Serial.println(serialCommand.fire);
    inputString = "";
    stringComplete = false;   
  }
  Input_pan = serialCommand.panError;
  Input_tilt = serialCommand.tiltError;
  panPID.Compute();
  tiltPID.Compute();
//  Serial.println(Output_pan);
//  Serial.println(Output_tilt);
  panservo.writeMicroseconds(Output_pan);
  tiltservo.writeMicroseconds(Output_tilt);
} 

void serialEvent()
{
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}

command_t serialCommandParse(String inputString){
  command_t returnCommand;
  // this means there are numbers, figure out what they are!
  returnCommand.panError = 0;
  returnCommand.tiltError = 0;
  returnCommand.fire = false;
  //read in the first number
  //initialize the loop counter
  int i = 1;
  //initialize the number buffer
  String numberBuffer = "";
  numberBuffer.reserve(10);
  while(inputString[i] != '|'){
    numberBuffer += inputString[i];
    i++;
  }
  returnCommand.panError = atoi(&numberBuffer[0]);
  i++;
  numberBuffer = "";
  //numberBuffer.reserve(10);
  while(inputString[i] != '\n'){
    numberBuffer += inputString[i];
    i++;
  }
  returnCommand.tiltError = atoi(&numberBuffer[0]);
     
  if(inputString[0] == '='){
    returnCommand.fire = false;
  }else if(inputString[0] == '!'){
    returnCommand.fire = true;
  }
  return returnCommand;
}
