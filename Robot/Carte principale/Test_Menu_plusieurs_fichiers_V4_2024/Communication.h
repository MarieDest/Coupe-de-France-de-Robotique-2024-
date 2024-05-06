// Communication.h

#ifndef _Communication_h
#define _Communication_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
  #include <Wire.h>
#else
  #include "WProgram.h"
  #include <Wire.h>
#endif

void setupComm();
TwoWire getWire();
void setEtat(String Etat_Value);
void Comm();
void printSerial(String message);
void printSoftSerial(String message);
void RecupMessage(String message);
void condition();
void receiveEvent(int);
#endif
