
#include "ProgrammePrincipal.h"
#include "Homologation.h"
#include "Tests.h"
#include "Menu.h"
#include "Relays.h"
#include "Communication.h"


String Programme_a_lancer[3][3] = {
	{"Test_1M","Test_360_degres","Test?"},
	{"homologation_statique_ferme","homologation_statique_ouvert","homologation_dynamique"},
	{"programme_principal_qualification","programme_principal_finale",""}
};
String Menu_str = "";
bool relayOK = false;
bool notInterrupted = true;
const int Pin_Tirette = 33;


void setup() {
  
  setupComm();
  pinMode(Pin_Tirette , INPUT_PULLUP);
  setup_Menu();
  setup_Moteur();
  //setupRelay();
  
  setEtat("Avance");
  
 //attachInterrupt(digitalPinToInterrupt(21), iSR, CHANGE);
 // attachInterrupt(digitalPinToInterrupt(3), iSR2, FALLING);// on ne peut pas avoir 2 interruptions sur le meme pin.
}

void loop() {
  
	//if (relayOK == false){
	//	relayOK = true;
	//	relay_SetStatus(ON, OFF);   // allume le premier relay
	//	delay(1000);				// attends 2 sec 
	//	relay_SetStatus(ON, ON);	//avant d'allumer le deuxi�me relay
	//}
  
	digitalWrite(35, LOW);
	if( notInterrupted){
		if (MenuChoisi == LOW) {
      //Serial.println("choisir menu");
			Set_Menu_Value();
			Select_Menu_Value();
		}

		if (MenuEtage1 == 3 && MenuChoisi) {
			if (COULEUR == -1) {
				ChoisirCouleur();
				Serial.print(COULEUR);
			}
		}
	 delay(300);
   if(MenuChoisi){
    waitForTirette();
		// lancement du programme d�termin� dans le menu avant. 
		switch (MenuEtage1) {
		case 1 : 
			if (MenuEtage2 == 1) { Test_1M(); }
			else if (MenuEtage2 == 2) { Test_360_degres(); }
      else{ TestNull();}
			break;
		case 2 : 
			if (MenuEtage2 == 1) { homologation_statique_ferme(); }
			else if (MenuEtage2 == 2) { homologation_statique_ouvert(); }
			else { homologation_dynamique(); }
			break;
		case 3 : 
			if (MenuEtage2 == 1) { programme_principal_qualification(); }
			else if (MenuEtage2 == 2) { programme_principal_finale(); }
			break;
		}
   } 
  
	}
 
}
