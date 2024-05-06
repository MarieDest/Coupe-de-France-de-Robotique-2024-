// 
// 
// 

#include "Relays.h"

/*
 * This is the Arduino the 2-channel relay sketch.
 * In this example, when a low level is supplied to
 * signal terminal of the 2-channel relay, the LED
 * on the relay will light up. Otherwise, it will
 * turn off. If a periodic high and low level is
 * supplied to the signal terminal, you can see
 * the LED will cycle between on and off.
 * Tutorial URL http://osoyoo.com/2017/07/31/arduino-lesson-2-channel-relay-module/
 * CopyRight www.osoyoo.com
 */
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
