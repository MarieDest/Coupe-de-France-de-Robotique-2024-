// 
// 
// 

#include "Relays.h"

int IN1 = 2;
int IN2 = 3;


void setupRelay()
{
	relay_init();//initialize the relay
}

void relay_init(void)//initialize the relay
{
	//set all the relays OUTPUT
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	relay_SetStatus(OFF, OFF); //turn off all the relay
}
//set the status of relays
void relay_SetStatus(unsigned char status_1, unsigned char status_2)
{
	digitalWrite(IN1, status_1);
	digitalWrite(IN2, status_2);
}
