#define MAX_DISTANCE 200
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
         delay(1000);
        
    }
}

void envoi_ordre(int dataPin, int clockPin, boolean sens, char donnee)
{
    // on va parcourir chaque bit de l'octet
    for(int i=0; i<8; i++)
    {
        // on met l'horloge à l'état bas
        digitalWrite(clockPin, LOW);
        // on met le bit de donnée courante en place
        if(sens)
        {
            digitalWrite(dataPin,donnee & 0x01 << i);
        }
        else
        {
            digitalWrite(dataPin, donnee & 0x80 >> i);
        }
        // enfin on remet l'horloge à l'état haut pour
        // faire prendre en compte cette dernière
        digitalWrite(clockPin, HIGH);
    }
}
