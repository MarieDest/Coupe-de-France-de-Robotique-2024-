#include "ElectroAimant.h"

int Pin_ElectroAimant[]={28,32,50};
void setupElectroAimant(){
  for (int i = 1; i <=Nb_ElectroAimant; i ++){ 
    pinMode(Pin_ElectroAimant[i-1],OUTPUT);
  }
}

void  activerElectroaimant(int num_ElectroAimant){ //1,2 ou 3
  digitalWrite(Pin_ElectroAimant[num_ElectroAimant-1], HIGH);
}


void  eteindreElectroaimant(int num_ElectroAimant){ //1,2 ou 3
  digitalWrite(Pin_ElectroAimant[num_ElectroAimant-1], LOW);
}