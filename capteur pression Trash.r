

#include <Servo.h>
#define SERVOS 3 // define the number of servos

int servoPins[] = {4,5,6};
Servo myservo[SERVOS];
 
int InputSensor[3];
int val[4];

//------------- SETUP -------------//   
void setup()
{
  Serial.begin(9600);
  for(int i = 0; i<=3; i++){
       InputSensor[i] = i;
       myservo[i].attach(servoPins[i]);
    }
}
 
 
//------------- LOOP -------------// 
void loop()
{
   for(int i=0; i<=3; i++){
     val[i] = analogRead(InputSensor[i]);
     val[i] = map(val[i], 0, 1023, 0, 180);   
     myservo[i].write(val[i]);
      delay(15);
   }

  // force sensor value
  Serial.println(val[0]);
  Serial.println(val[1]);
  Serial.println(val[2]);
}

