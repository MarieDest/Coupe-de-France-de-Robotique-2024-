// 
// 
// 

#include "ProgrammePrincipal.h"
#include "ServoRS200.h"
#include "Moteur.h"
#include "ElectroAimant.h"
int COULEUR = -1;
void programme_principal_qualification() {
	AvanceMM(1300);
  delay(999999999);
}
void programme_principal_finale() {
  //programme qui va chercher les panneaux solaires et les tourne vers chez nous.
  // necessite de connaitre la couleur 
  if(COULEUR == 0){ //Couleur JAUNE
	AvanceMM(20);
  ServoPanneauOuvrir(COULEUR);
  //ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(210);


  ServoPanneauOuvrir(COULEUR);
  //ServoPanneauFermerDoucement(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(210);

  ServoPanneauOuvrir(COULEUR);
 // ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(540);


  ServoPanneauOuvrir(COULEUR);
 // ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(210);

  ServoPanneauOuvrir(COULEUR);
//  ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(210);

  ServoPanneauOuvrir(COULEUR);
  //ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
 AvanceMM(100);


  DroiteDeg(90);
  ServoBas();
  AvanceMM(400);
  GaucheDeg(90);
  AvanceMM(500);
  }
    if(COULEUR == 1){ //Couleur BLEU
	AvanceMM(20);
  ServoPanneauOuvrir(COULEUR);
 // ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(210);

  ServoPanneauOuvrir(COULEUR);
 // ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(210);

  ServoPanneauOuvrir(COULEUR);
// ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(540);


  ServoPanneauOuvrir(COULEUR);
 // ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(210);

  ServoPanneauOuvrir(COULEUR);
 // ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(210);

  ServoPanneauOuvrir(COULEUR);
 // ServoPanneauFermerDemi(COULEUR);
  ServoPanneauFermerDoucement(COULEUR);
  AvanceMM(100);

  GaucheDeg(90);
  ServoBas();
  AvanceMM(400);
  DroiteDeg(90);

 
  AvanceMM(500);
  }

  delay(999999999);

}

