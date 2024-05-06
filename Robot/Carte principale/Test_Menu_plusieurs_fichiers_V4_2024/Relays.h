// Relays.h

#ifndef _Relays_h
#define _Relays_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

 //the relays connect to

#define ON   0
#define OFF  1
void setupRelay(void);
void relay_init(void);
void relay_SetStatus(unsigned char status_1, unsigned char status_2);
