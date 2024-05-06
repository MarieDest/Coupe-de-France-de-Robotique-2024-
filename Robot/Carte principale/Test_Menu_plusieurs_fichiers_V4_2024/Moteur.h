#ifndef _Moteur_h
#define _Moteur_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
  #include <Wire.h>
#else
	#include "WProgram.h"
  #include <Wire.h>
#endif

byte getSoft();
void encoderReset();
long encoder1();
long encoder2();
void volts();
void stopMotor();
void setWire(TwoWire);
void AvanceMM(int);
void ReculeMM(int);
void GaucheDeg(int);
void DroiteDeg(int);
#endif