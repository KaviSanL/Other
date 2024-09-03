#include <Servo.h>

Servo servo3;
Servo servo4;

 
int pos1 = 90; 
int pos2 = 0;

const int RELAY_PINR1 = 9; // R up   
const int RELAY_PINR2 = 10; // R down
const int RELAY_PINL1 = 4; // L up   
const int RELAY_PINL2 = 5; // L down

Servo servo;     
int trigPin = 2;    
int echoPin = 3;   
int i=0;
long duration, dist, average;   
long aver[3];

void setup() {
    Serial.begin(9600); 
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);
 servo3.attach(8);// R Hand
 servo4.attach(11);// L Hand
 pinMode(RELAY_PINR1, OUTPUT);
 pinMode(RELAY_PINR2, OUTPUT);
 pinMode(RELAY_PINL1, OUTPUT);
 pinMode(RELAY_PINL2, OUTPUT);
}


void loop() { 

digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = duration * 0.034/2;
Serial.println(dist);

if(dist>100){
  digitalWrite(RELAY_PINL1, HIGH);   //Left hand up
  delay(1200);                     
  digitalWrite(RELAY_PINL1, LOW);    
  delay(3000); 
 
  for (pos2 = 0; pos2 <= 180; pos2 += 1) //Hold the fingers 
  { 
    servo3.write(pos2);              
    delay(15);                      
  }
  for (pos2 = 180; pos2 >= 0; pos2 -= 1) //Release the fingers
  { 
    servo3.write(pos2);              
    delay(15);                       
  }
  
  digitalWrite(RELAY_PINL2, HIGH);    //Left hand down
  delay(600);                     
  digitalWrite(RELAY_PINL2, LOW);    
  delay(3000);

  digitalWrite(RELAY_PINR1, HIGH);   //Right hand up
  delay(1200);                     
  digitalWrite(RELAY_PINR1, LOW);    
  delay(3000); 
 
  for (pos2 = 0; pos2 <= 180; pos2 += 1) //Hold the fingers 
  { 
    servo4.write(pos2);              
    delay(15);                      
  }
  for (pos2 = 180; pos2 >= 0; pos2 -= 1) //Release the fingers
  { 
    servo4.write(pos2);              
    delay(15);                       
  }
  
  digitalWrite(RELAY_PINR2, HIGH);    //Right hand down
  delay(600);                     
  digitalWrite(RELAY_PINR2, LOW);    
  delay(3000);

}

else if(dist>=70 && dist<=100)
{

  digitalWrite(RELAY_PINR1, HIGH);   //Right hand up
  delay(1200);                     
  digitalWrite(RELAY_PINR1, LOW);    
  delay(3000);
 
}


else
{
  digitalWrite(RELAY_PINR1, HIGH);   //Right hand up
  delay(1200);                     
  digitalWrite(RELAY_PINR1, LOW);    
  delay(3000);
  
  for (pos2 = 0; pos2 <= 180; pos2 += 1) //Hold the fingers 
  { 
    servo4.write(pos2);              
    delay(15);                      
  }

  digitalWrite(RELAY_PINR2, HIGH);    //Right hand down
  delay(300);                     
  digitalWrite(RELAY_PINR2, LOW);    
  delay(400);
  
  digitalWrite(RELAY_PINR1, HIGH);   //Right hand up
  delay(350);                     
  digitalWrite(RELAY_PINR1, LOW);    
  delay(400);

  digitalWrite(RELAY_PINR2, HIGH);    //Right hand down
  delay(300);                     
  digitalWrite(RELAY_PINR2, LOW);    
  delay(400);

  digitalWrite(RELAY_PINR1, HIGH);   //Right hand up
  delay(500);                     
  digitalWrite(RELAY_PINR1, LOW);    
  delay(300);
  
  for (pos2 = 180; pos2 >= 0; pos2 -= 1) //Release the fingers
  { 
    servo4.write(pos2);              
    delay(15);                       
  }
  digitalWrite(RELAY_PINR2, HIGH);    //Right hand down
  delay(600);                     
  digitalWrite(RELAY_PINR2, LOW);    
  delay(5000);
}
Serial.print(dist);
}
  
