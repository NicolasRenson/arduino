 int buzzer = 9; //pin buzzer
 int led = 2; //pin led 


void setup(){
 
  pinMode(buzzer, OUTPUT); // definition d'un sortie
  pinMode(led, OUTPUT); // definition d'un sortie
}

void loop(){
 
  tone(buzzer, 1000); // emission d'un signala la frequence 1KHz 
  delay(500);        // pour 0,5s
  noTone(buzzer);     // arret de l'emission .
  delay(1000);        // attendre 1 seconde
digitalWrite(led, HIGH);  //on alimente le circuit de led



}
    
