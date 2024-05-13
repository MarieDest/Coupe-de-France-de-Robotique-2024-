#ifndef Menu_h
#define Menu_h


#include <LiquidCrystal.h> 


extern LiquidCrystal lcd; 

extern int xAxisPin; // define X pin of Joystick 

extern int zAxisPin; // define Z pin of Joystick 
extern int xVal;
extern int zVal; // define 3 variables to store the values of 3 direction 

extern int MenuEtage1; // valeur associée au menu 1 = Test 2= Homologation 3= Programme principal
extern int MenuEtage2; // valeur associée au menu 1 = Test 2= Homologation 3= Programme principal
extern int CurrentEtage;
extern bool ChangeEtage;
// ces deux variables permettent de changer la valeur de X toutes les 500 ms si la valeur de X change sur le joystick.
extern unsigned long elapsedTime, previousTime;
    
extern bool change ;
extern bool ComeBack;
// 2 caractères ont été crées : une flèche vers le haut et un carré vide pour éteindre tous les pixels. cf https://www.youtube.com/watch?v=R_LxirJ5R4A&t=575s   pour comment faire
extern byte Fleche_Haut[8];
extern byte Carre_Vide[8];
extern bool MenuChoisi;
extern bool Couleur_Choisie;
extern bool Couleur_needed;

extern String MenuComplet[4][3];
extern String Couleur[1][2];
void Set_Menu_Value();
void Select_Menu_Value();
void Select_Menu_Value_Etage1();
void Select_Menu_Value_Etage2();
int Set_Menu_Value(int Etage);
void setup_Menu();
int get_X_Val();
void SetChange();
void PrintDebug();
int get_Z_Val();
void SetCurrentEtage();
void SetFleche(int Etage);
void SetupSecMenu();
void ChoisirCouleur();
void setup_Couleur();
void select_Couleur();
void Set_Couleur();
void setCouleurChoisie(bool);
void setCouleurNeeded(bool);
bool getCouleurChoisie();
bool getCouleurNeeded();
void waitForTirette();
#endif //__Menu_H
