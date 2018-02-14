#include <Servo.h>

Servo servomoteur2;

int motor_pin1 = 4;   // pin de la marche avant du moteur de droite 
int motor_pin2 = 5;   //pin de la marche arrière du moteur de droite 
int motor_pin3 = 6;   //pin de la marche avant du moteur de gauche  
int motor_pin4 = 7;   //pin de la marche arrière du moteur de gauche 
int servopin = 8;     // pin servomoteur capteur 
int sensorpin = 0;    // pin capteur
int dist = 0;
int leftdist = 0;
int rightdist = 0;
int object = 500;            //distance pour la quel le robot devrai chercher un autre route


void setup_1 ()
{
  pinMode(motor_pin1,OUTPUT);
  pinMode(motor_pin2,OUTPUT);
  pinMode(motor_pin3,OUTPUT);
  pinMode(motor_pin4,OUTPUT);
  servomoteur2.attach(servopin);
  servomoteur2.write(90);
  delay(700);
}

void loop_1() 
{
    int dist = analogRead(sensorpin); // lire les distance du capteur

    if(dist < object) 
    {   //si la distance est supérieur a 550 alors continuer en marche avant
        forward();                                
    }
    if(dist >= object) 
    {   //si la distance est inferieur ou égal a 550
        findroute();
    }
}
 
void forward() 
{                            // marche avant
    digitalWrite(motor_pin1,HIGH);      // moteur de droite en marche avant
    digitalWrite(motor_pin2,LOW);
    digitalWrite(motor_pin3,HIGH);    // moteur de gauche en marche avant
    digitalWrite(motor_pin4,LOW);
 }
 
void findroute() 
{        // procédure de recherche d'une route
    halt();                                            // arret
    backward();                                      //marche arrière
    lookleft();                                      //regarder a gauche
    lookright();                                  //regarder a droide 
                                        
    if ( leftdist < rightdist ) // comparer les donnés et executer la meilleur solution
    {
      turnleft();   
    }
    else
    {
      turnright ();
    }
}

void backward() 
{   // faire marche arrière
    digitalWrite(motor_pin1,LOW);
    digitalWrite(motor_pin2,HIGH);    // moteur de droite en marche arrière 
    digitalWrite(motor_pin3,LOW);
    digitalWrite(motor_pin4,HIGH);    // moteur de gauche en marche arrière
    delay(500);       //durée de la marche arrière
    halt();
}

void halt () 
{   //s'arreter
    digitalWrite(motor_pin1,LOW);   // couper tous les moteur
    digitalWrite(motor_pin2,LOW);
    digitalWrite(motor_pin3,LOW);
    digitalWrite(motor_pin4,LOW);
    delay(500);                          //marquer l'arret
}
 
void lookleft() 
{  //chercher un obstacle a gauche
    servomoteur2.write(150);                // tourner le servomoteur a gauche: 150°
    delay(700);                                //attendre que le servo prenne sa position 
    leftdist = analogRead(sensorpin);           // lire la distance
    servomoteur2.write(90);                     // revenir a la position initial  
    delay(700);                                //attendre que le servo prenne sa position 
}

void lookright () 
{     
  //chercher un obstacle a droite 
  servomoteur2.write(30);     //tourner le servomoteur a  droite: 30°
  delay(700);                 //attendre que le servo prenne sa position 
  rightdist = analogRead(sensorpin);  // lire la distance
  servomoteur2.write(90);             // revenir a la position initial            
  delay(700);                        //attendre que le servo prenne sa position 
}

void turnleft () 
{   //tourner a gauche 
    digitalWrite(motor_pin1,HIGH);      //moteur de droite en marche avant
    digitalWrite(motor_pin2,LOW);      
    digitalWrite(motor_pin3,LOW);
    digitalWrite(motor_pin4,HIGH);    // moteur de gauche en marche arriére 
    delay(1000);                    // attendre que le robot tourne
    halt();
}

void turnright () 
{   //tourner a droite
    digitalWrite(motor_pin1,LOW);      //moteur de droite en marche arriére 
    digitalWrite(motor_pin2,HIGH);    
    digitalWrite(motor_pin3,HIGH);    // moteur de gauche en sense avant
    digitalWrite(motor_pin4,LOW);
    delay(1000);                              // attendre que le robot tourne 
    halt();
}

