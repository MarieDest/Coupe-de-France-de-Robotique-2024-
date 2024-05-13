
#ifndef _ElectroAiamnt_h
#define _ElectroAiamnt_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif



#define Nb_ElectroAimant 3

void setupElectroAimant();
void activerElectroaimant(int);
void eteindreElectroaimant(int);

#endif
