// Programme Principal.h

#ifndef _PROGRAMME PRINCIPAL_h
#define _PROGRAMME PRINCIPAL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

extern int COULEUR; // JAUNE = 0   VIOLET = 1 NON_CHOISIE = -1


void programme_principal_qualification();
void programme_principal_finale();
#endif

