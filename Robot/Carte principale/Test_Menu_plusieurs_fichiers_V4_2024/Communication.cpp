#include <Arduino.h>
#include "Communication.h"
#include "ProgrammePrincipal.h"
#include "Tests.h"
#include <SoftwareSerial.h>
#include <Wire.h>

#define Carte_Secondaire_Adresse = 0x02;
int incomingByte ;      
char myStr[1000];
char value;
int i = 0;
char time;
int lastMessageIndex = 0;
String Message = "";
int idx0,idx1,idx2,idx3;
String distAvStr,distArStr,distGStr,distDStr;
int distAv,distAr,distG,distD;
SoftwareSerial SoftSerial(28,26); // RX, TX//on informe le microcontrôleur que l'on utilise ses broches pour une connexion série


String keyWords[] = {"  distAv =","   distAr =","   distG =","   distD ="};
String Etat = "";

long StartTime =0;
long  CurrentTime =0 ;

void setupComm(){
  //Serial.begin(9600);
  Serial3.begin(9600);
  SoftSerial.begin(9600);
  Wire.begin(8);
  Wire.onReceive(receiveEvent); // register event
 
/*  while (!Wire.available()) {  
    delay(300);   
    
  }*/
  
  
}

TwoWire getWire(){
  return Wire;
}

void setEtat(String Etat_Value){
  Etat = Etat_Value;
}

void analyse_I2C(int value){
  if(value<50 ){
    notInterrupted_moteur = true;
  }else{
    notInterrupted_moteur = false;
  }
}
void Comm_I2C(){
  String readed = "";
  if(Wire.available()){
    readed = Wire.read();
  }
  analyse_I2C(readed.toInt());
}
void receiveEvent(int howMany) {
  String phrase = "";
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    phrase += c;
    //Serial.print(c);         // print the character
  }
  char x = Wire.read();    // receive byte as an integer
  phrase += x;
  Serial.println(phrase);         // print the integer
  if(CurrentTime<StartTime+100000){
  if(phrase=="truc detecte"){
    notInterrupted_moteur = false;
  }
    if(phrase=="plus de truc"){
    notInterrupted_moteur = true;
  }
  }else{
    notInterrupted_moteur = false;
  }
}
void Comm() {
   // check if data is available
  Serial.println("comm activated"); 
  if (Serial3.available() > 0) {
     
      incomingByte = Serial3.read();
      myStr[i]=(char)incomingByte;
      //Serial.println("Value comm available = "+ (String) incomingByte + "traduit par = "+ myStr[i]); 
      //Serial.print(myStr[i]);
      i = i+1;
      if(incomingByte == 13){//13 = retour chariot
        Message = "";
        for (int k = lastMessageIndex; k <=i; k++)
          { 
            Message = Message+myStr[k];
          }
        Serial.println("le message reçu est : "+Message);
        lastMessageIndex = i;
      }
      RecupMessage(Message);
  }
}
void printSerial(String message){
  Serial3.println(message);
}
void printSoftSerial(String message){
  SoftSerial.println(message);
}
void RecupMessage(String message){
  
        idx0=message.indexOf(keyWords[0]);
        if(idx0>=0){
          idx1=message.indexOf(keyWords[1]);
          if(idx1>=0){
            idx2=message.indexOf(keyWords[2]);
            if(idx2>=0){
              idx3=message.indexOf(keyWords[3]);
              if(idx3>=0){
                    distAvStr = message.substring(idx0+keyWords[0].length(),idx1);
                    distArStr = message.substring(idx1+keyWords[1].length(),idx2);
                    distGStr = message.substring(idx2+keyWords[2].length(),idx3);
                    distDStr = message.substring(idx3+keyWords[3].length());
                    //Serial.println("trouvé : "+(String)distAv+"  "+ (String)distAr+ "  "+(String)distG+"  "+(String)distD+"   ");
                    distAv = distAvStr.toInt();
                    distAr = distArStr.toInt();
                    distG = distGStr.toInt();
                    distD = distDStr.toInt();
                }
              }
            }
          }
          condition();
}
     

void condition(){
   if(Etat == "Avance"){
        if(distAv <30){
          notInterrupted_moteur = true;
        }else{
          notInterrupted_moteur = false;
        }
      }
}
