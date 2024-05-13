#define _ServoRS200_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
  #include <Wire.h>
#else
	#include "WProgram.h"
  #include <Wire.h>
#endif

#define Pin_Servo 35
#define Min_Position_Servo 130
#define Max_Position_Servo 40
#define Middle_Position_Servo 82

void setupServo();

void ServoBas();
void ServoHaut();
void ServoMiddle();
void ServoPanneauOuvrir(int);
void ServoPanneauFermerDemi(int);
void ServoPanneauFermerDoucement(int);
void ServoPanneauFermer(int);