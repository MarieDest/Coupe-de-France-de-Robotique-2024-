#include "Moteur.h"
#include "Communication.h"
#include <Wire.h>

#include <Arduino.h>
#include "Communication.h"
#include "ProgrammePrincipal.h"
#include "Tests.h"
#include <SoftwareSerial.h>
#include <Wire.h>

#define CMD                 (byte)0x00                        // Values of 0 eing sent using write have to be cast as a byte to stop them being misinterperted as NULL
#define MD25ADDRESS         0x58                              // Address of the MD25
#define SOFTWAREREG         0x0D                              // Byte to read the software version
#define SPEED1              (byte)0x00                        // Byte to send speed to first motor
#define SPEED2              0x01                              // Byte to send speed to second motor
#define ENCODERONE          0x02                              // Byte to read motor encoder 1
#define ENCODERTWO          0x06                              // Byte to read motor encoder 2
#define VOLTREAD            0x0A                              // Byte to read battery volts
#define RESETENCODERS       0x20

#define PasPour1M           1149                               //1149    
#define PasPour360Deg       1701                              // à realiser sur une surface plane

void setup_Moteur()
{
  setWire(getWire());
	byte SoftVersion = getSoft();
}

byte getSoft(){                                              // Function that gets the software version
  Wire.beginTransmission(MD25ADDRESS);                      // Send byte to read software version as a single byte
  Wire.write(SOFTWAREREG);
  Wire.endTransmission();
  
  Wire.requestFrom(MD25ADDRESS, 1);                         // request 1 byte form MD25
  while(Wire.available() < 1);                              // Wait for it to arrive
  byte software = Wire.read();                            // Read it in
  
  return(software);
}
void encodeReset(TwoWire Wire){                                        // This function resets the encoder values to 0
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(CMD);
  Wire.write(0x20);                                         // Putting the value 0x20 to reset encoders
  Wire.endTransmission(); 
}
long encoder1(){    
  //CurrentTime = millis();                                        // Function to read and display value of encoder 1 as a long
  Wire.beginTransmission(MD25ADDRESS);                      // Send byte to get a reading from encoder 1
  Wire.write(ENCODERONE);
  Wire.endTransmission();
  
  Wire.requestFrom(MD25ADDRESS, 4);                         // Request 4 bytes from MD25
  while(Wire.available() < 4);                              // Wait for 4 bytes to arrive
  long poss1 = Wire.read();                                 // First byte for encoder 1, HH.
  poss1 <<= 8;
  poss1 += Wire.read();                                     // Second byte for encoder 1, HL
  poss1 <<= 8;
  poss1 += Wire.read();                                     // Third byte for encoder 1, LH
  poss1 <<= 8;
  poss1  +=Wire.read();                                     // Fourth byte for encoder 1, LL

  
  delay(50);                                                // Wait for everything to make sure everything is sent
  
  return(poss1);
}

long encoder2(){            
  CurrentTime=millis();                                // Function to read and display velue of encoder 2 as a long
  Wire.beginTransmission(MD25ADDRESS);           
  Wire.write(ENCODERTWO);
  Wire.endTransmission();
  
  Wire.requestFrom(MD25ADDRESS, 4);                         // Request 4 bytes from MD25
  while(Wire.available() < 4);                              // Wait for 4 bytes to become available
  long poss2 = Wire.read();
  poss2 <<= 8;
  poss2 += Wire.read();                
  poss2 <<= 8;
  poss2 += Wire.read();                
  poss2 <<= 8;
  poss2  +=Wire.read();               
  
 
  delay(50);                                                // Wait to make sure everything is sent
   
  return(poss2);
}
void volts(){                                               // Function to read and display battery volts as a single byte
  Wire.beginTransmission(MD25ADDRESS);                      // Send byte to read volts
  Wire.write(VOLTREAD);
  Wire.endTransmission();
  
  Wire.requestFrom(MD25ADDRESS, 1);
  while(Wire.available() < 1);                               
  int batteryVolts = Wire.read();
  
  
  delay(50);                                                // Wait to make sure everything is sent
}
void stopMotor(){                                           // Function to stop motors
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED2);
  Wire.write(128);                                           // Sends a value of 128 to motor 2 this value stops the motor
  Wire.endTransmission();
  
  Wire.beginTransmission(MD25ADDRESS);
  Wire.write(SPEED1);
  Wire.write(128);
  Wire.endTransmission();
}  
void setWire(TwoWire wireComm){
  Wire = wireComm;
}

//************ Mouvements ************************//

void AvanceMM(int nb_mm){
float begin_value_enc1 = encoder1(); 
Serial.print("nb_mm = "+String(nb_mm)+"PasPour1M = "+String(PasPour1M)+" eq : nb_mm* PasPour1M/1000 = " + float((float(nb_mm)*float(PasPour1M))/float(1000)));
do{       
  if(notInterrupted_moteur){                                                         // Start loop to drive motors forward
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 2 at speed value stored in x
    Wire.write(SPEED2);
    Wire.write(135);    //146                                        
    Wire.endTransmission();
  
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 1 at speed value stored in x
    Wire.write(SPEED1);
    Wire.write(135);//146
    Wire.endTransmission();
 
   // encoder1();                                             // Calls a function that reads and displays value of encoder 1 to LCD03
   // encoder2();                                             // Calls a function that reads and displays value of encoder 2 to LCD03
   // volts();
  }else{
    stopMotor();
  }                                               // Calls function that reads and displays battery volts
 }while(encoder1() < begin_value_enc1+float((float(nb_mm)* float(PasPour1M)/float(1000))));                                 
 stopMotor();   
}
void ReculeMM(int nb_mm){
  float begin_value_enc1 = encoder1(); 
  do{    
    if(notInterrupted_moteur){                                                    // Start loop to drive motors forward
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 2 at speed value stored in x
    Wire.write(SPEED2);
    Wire.write(110);                                           
    Wire.endTransmission();
  
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 1 at speed value stored in x
    Wire.write(SPEED1);
    Wire.write(110);
    Wire.endTransmission();
 
    encoder1();                                             // Calls a function that reads and displays value of encoder 1 to LCD03
    encoder2();               
    }else{
      stopMotor();
    }                              // Calls a function that reads and displays value of encoder 2 to LCD03
   // volts();                                                // Calls function that reads and displays battery volts
 }while(encoder1() > (begin_value_enc1-float((float(nb_mm)* float(PasPour1M)/float(1000)))));                                 
 
 stopMotor();
}
void DroiteDeg(int nb_deg){
    float begin_value_enc1 = encoder1(); 
  do{  
    if(notInterrupted_moteur){                                                              // Start loop to drive motors forward
    Wire.beginTransmission(MD25ADDRESS);                    // Drive motor 1 at speed value stored in x
    Wire.write(SPEED1);
    Wire.write(135);//146
    Wire.endTransmission();
 
    encoder1();  
    }else{
      stopMotor();
    }                                           // Calls a function that reads and displays value of encoder 1 to LCD03
   
 }while(encoder1() < (begin_value_enc1+float(float(nb_deg)* float(PasPour360Deg)/360.0)));                                 
 
 stopMotor();
}
void GaucheDeg(int nb_deg){
  float begin_value_enc2 = encoder2(); 
  Serial.print("begin_value_enc2"+ String(begin_value_enc2)+"nb_deg = "+String(nb_deg)+"PasPour1M = "+String(PasPour360Deg)+" eq : nb_mm* PasPour1M/1000 = " + float((float(nb_deg)*float(PasPour360Deg))/float(360)));

  do{                               
    if(notInterrupted_moteur){                                 
    Wire.beginTransmission(MD25ADDRESS);                   
    Wire.write(SPEED2);
    Wire.write(135); ////146
    Wire.endTransmission();
 
    encoder2();                                             // Calls a function that reads and displays value of encoder 1 to LCD03
    }else{
      stopMotor();
    }
 }while(encoder2() <(begin_value_enc2+float(float(nb_deg)* float(PasPour360Deg)/360.0)));                                 
 
 stopMotor();
}
