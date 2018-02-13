#include <Servo.h>
Servo servomoteur1; //servomoteur trappe gauche
Servo servomoteur3; //servomoteur trappe droite

int microrupteur = 12;  //capteur de pression trappe
int pin_servo1 = 6;    // pin servomoteur gauche :6
int pin_servo3 = 7;   //pin servomoteur droit :7
 
void setup() {
                        pinMode(microrupteur, INPUT);
                        
 
                        pinMode(pin_servo1, OUTPUT);
                        pinMode(pin_servo3, OUTPUT);
     
                        servomoteur1.attach(3,1000,2000);
                        servomoteur1.write(90);
                        servomoteur3.attach(3,1000,2000);
                        servomoteur3.write(90);
}
 
void loop() {
          if (microrupteur == HIGH)   //ouvre la trape si le capteur est enclenché
          { servomoteur1.write(90);
          servomoteur3.write(90);
            delay( 2000 ); 
          }
           else
          { servomoteur1.write(-90); } //autraument ferme la trape
          servomoteur3.write(90);
                                     
}
