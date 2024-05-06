#ifndef _1M_h
#define _1M_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

// programme qui doit r�aliser un mouvement de 1 mtre pour le robot

#define X_STEP_PIN 34
#define X_DIR_PIN 36
#define X_ENABLE_PIN 38
#define X_Y_SLEEP_PIN 53
#define X_Y_RESET_PIN 51

#define Y_STEP_PIN 42
#define Y_DIR_PIN 40
#define Y_ENABLE_PIN 43

extern bool notInterrupted_moteur;

void setup_Moteur();
void setInterruption(bool noInterrupt);
void Test_1M();
void Test_360_degres();
/*
void Droite(int);
void Gauche(int);
void AvanceMM(int);
void ReculeMM(int);
*/
void TestNull();

#endif
