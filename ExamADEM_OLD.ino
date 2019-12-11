//This code is made for exam in ADEM spring 2020
//And will be able to control a Dynamixel motor aswell as other features

#include <Arduino.h> //Standard Arduino libary
#include "Functions.h"

FunctionsClass function;

const unsigned long Interval = 100;   
unsigned long PreviousTime = 0;
int maxTemp = 50;

void setup() {

  Serial.flush();                                       // Clear the serial buffer of garbage data before running the code.
  Serial.begin(SERVO_SET_Baudrate);                                  // Start serial communication on baudrate 57600
 
 
  function.setTorquePacket(0x03, true); //Set holding torque for whatever motor
   function.setTorquePacket(0x02, true);
  function.setTorquePacket(0x01, true);

  function.SetPGain(0x01, 75);
}

void loop() {
 unsigned long CurrentTime = millis();

 if(CurrentTime-PreviousTime >= Interval){
  
   function.ReadTemp(0x01); 
   //Serial.println("read"); 
  
   int currentTemp = function.Status_Packet1[9];
  PreviousTime = CurrentTime;
  if(currentTemp >= maxTemp){                    //Function to reboot servo if temperature goes above 50
    function.rebootDynamixelPacket(0x01);
    }
  }

  
}

  
