#include "ServoRS200.h"

#include <Servo.h>  // on inclut la bibliothèque pour piloter un servomoteur

Servo monServo;  // on crée l'objet monServo
Servo ServoDroitPanneau; 
Servo ServoGauchePanneau; 

void setupServo()
{
 monServo.attach(Pin_Servo); 
 
 ServoDroitPanneau.attach(37); 
  ServoGauchePanneau.attach(39); 
  ServoDroitPanneau.write(90);
  ServoGauchePanneau.write(0);
}


void ServoBas(){
   monServo.write(Min_Position_Servo);
}
void ServoHaut(){
   monServo.write(Max_Position_Servo);
}
void ServoMiddle(){
   monServo.write(Middle_Position_Servo);
}
void ServoPanneauOuvrir(int COULEUR){
  if(COULEUR ==1 ){
    //Jaune?
    ServoDroitPanneau.write(45);//35
     delay(300);
  }else{
     ServoGauchePanneau.write(45);//55
      delay(300);
  }
}
void ServoPanneauFermerDemi(int COULEUR){
  if(COULEUR ==1 ){
    //Jaune?
    ServoDroitPanneau.write(65);
    delay(300);
  }else{
     ServoGauchePanneau.write(25);
      delay(300);
  }
}void ServoPanneauFermerDoucement(int COULEUR){
  if(COULEUR ==1 ){
    //Jaune?
    ServoDroitPanneau.write(45);delay(300);
    ServoDroitPanneau.write(55);delay(300);
    ServoDroitPanneau.write(65);delay(300);
    ServoDroitPanneau.write(75);delay(300);
    ServoDroitPanneau.write(85);delay(300);
    ServoDroitPanneau.write(90);
    delay(300);
  }else{
     ServoGauchePanneau.write(45);
     ServoGauchePanneau.write(35);delay(300);
    ServoGauchePanneau.write(25);delay(300);
    ServoGauchePanneau.write(15);delay(300);
    ServoGauchePanneau.write(5);delay(300);
    ServoGauchePanneau.write(0);delay(300);
    
  }
}
void ServoPanneauFermer(int COULEUR){
  if(COULEUR ==1 ){
    //Jaune?
    ServoDroitPanneau.write(90);
     delay(300);
   
  }else{
     ServoGauchePanneau.write(0);
      delay(300);
  }
}
