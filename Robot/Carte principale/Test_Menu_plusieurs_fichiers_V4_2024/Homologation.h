// Homologation.h

#ifndef _HOMOLOGATION_h
#define _HOMOLOGATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

void homologation_statique_ferme();
void homologation_statique_ouvert();
void homologation_dynamique();
#endif
