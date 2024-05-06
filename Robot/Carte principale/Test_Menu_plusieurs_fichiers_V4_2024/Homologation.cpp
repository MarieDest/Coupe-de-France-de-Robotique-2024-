// 
// 
// 

#include "Homologation.h"
#include "Moteur.h"

void homologation_statique_ferme(){
  GaucheDeg(360);
  delay(999999999);

}
void homologation_statique_ouvert(){

AvanceMM(1750);
DroiteDeg(180);
AvanceMM(1650);
delay(99999999999);

}
void homologation_dynamique() {
AvanceMM(1750);
GaucheDeg(180);
AvanceMM(1650);
delay(99999999999);
}
