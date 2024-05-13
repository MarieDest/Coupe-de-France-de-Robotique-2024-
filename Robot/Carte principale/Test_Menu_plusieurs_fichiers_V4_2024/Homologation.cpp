// 
// 
// 

#include "Homologation.h"
#include "Moteur.h"
#include "ServoRS200.h"

void homologation_statique_ferme(){
  ServoHaut();
  delay(999999999);

}
void homologation_statique_ouvert(){

ServoBas();
delay(99999999999);

}
/*
Attention!! pour l'homologation : 
Faire un programme qui va a droite, a gauche, en avant et en arrière pour avoir l'homologation dans toutes les directions. (et de long trajet pour avancer et reculer)
*/
void homologation_dynamique() {
AvanceMM(1000);
GaucheDeg(180);
ReculeMM(1000);
DroiteDeg(180);
//
AvanceMM(400);


delay(99999999999);
}
