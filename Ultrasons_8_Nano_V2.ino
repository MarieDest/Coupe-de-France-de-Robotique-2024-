#include <Wire.h> 
#define MAX_DISTANCE 200
#define Carte_Principale_Addresse 0x1E   
// Broche connectée au ST_CP du 74HC595
const int verrou = 8;
// Broche connectée au SH_CP du 74HC595
const int horloge = 9;
// Broche connectée au DS du 74HC595
const int data = 7;
float timeOut = MAX_DISTANCE *60;
int soundVelocity = 340;
 byte pinsUltrasons[8]={
    A6, //Ultrason 1
    A3, //Ultrason 2
    2, //Ultrason 3
    3, //Ultrason 4
    A7, //Ultrason 5
    6, //Ultrason 6
    5, //Ultrason 7
    4, //Ultrason 8
  };
  bool firstTransmission = true;
void setup()
{
    // On met les broches en sortie
    pinMode(verrou, OUTPUT);
    pinMode(horloge, OUTPUT);
    pinMode(data, OUTPUT);
    for (int i = 0; i < 8; i++)
    {
      pinMode(pinsUltrasons[i],INPUT);
    }
    Serial.begin(9600);
    Wire.begin(8);  
   // Wire.onRequest(requestEvent);
    
}

void requestEvent() {
  if(firstTransmission){
Wire.write("capteurs = 8   "); // respond with message of 6 bytes
  // as expected by master
  firstTransmission = false;
  }else{
   // Wire.write((String)); // respond with message of 6 bytes
  }
  
}
void loop()
{
    
    
    for (int i = 0; i < 8; i++)
    {
        // On active le verrou le temps de transférer les données
        digitalWrite(verrou, LOW);
        // on envoie la donnée
        // ici, c'est assez simple.
        // On va décaler l'octet 00000001 i fois puis l'envoyer
        shiftOut(data, horloge, MSBFIRST, ~(0x01 << i));
        // et enfin on relache le verrou
        digitalWrite(verrou, HIGH);
        // une petite pause pour constater l'affichage
      
         delayMicroseconds(10);
         shiftOut(data, horloge, MSBFIRST, 0x00);
         int pingTime = pulseIn(pinsUltrasons[i],HIGH,timeOut);
         int distance = (float) pingTime * soundVelocity /2/ 10000;
         Serial.println("Ultrason i = "+String(i)+"distance = "+String(distance));
         Wire.beginTransmission(8);//peut etre pas necessaire
         Wire.write( distance); 
         Wire.endTransmission();
         delay(1000);
        
    }
    
    
}


