#include <Servo.h>
#include <SoftwareSerial.h>
#include<JQ6500_Serial.h>
SoftwareSerial mySerial(3,4); 
JQ6500_Serial mp3(mySerial);
Servo myservo1;   //Eye
Servo myservo2;   //Head
Servo myservo3;   //Jaw

int measure(void);
void play(void);
 
int trigPin = 8;    
int echoPin = 9; 
long duration, dist, average;
long aver[3]; 
int var=0; 

void setup()
{
 Serial.begin(9600); 
 myservo1.attach(5);//eyes
 myservo2.attach(6);//head
 myservo3.attach(7);//Jaw
 pinMode(trigPin, OUTPUT);  
 pinMode(echoPin, INPUT); 
  mySerial.begin(9600);
  mp3.reset();
  mp3.setVolume(50);
  mp3.setLoopMode(MP3_LOOP_NONE);
  mp3.play();
} 

int measure(void)
{  
  for (int i=0;i<=2;i++) 
    {   
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    dist = (duration/2) / 29.1;    //obtain distance
    aver[i]=dist;            
    delay(10);              //delay between measurements
  }
   dist=(aver[0]+aver[1]+aver[2])/3;
   return(dist);
}

void play(void)
{
  mp3.setVolume(50);
  mp3.play();
  mp3.playFileByIndexNumber(1);
  delay(15000);
  mp3.reset();
}




void loop()
{
  int d=measure();
  if(d<=50)
  {
    play();
    myservo1.write(110);  //eye close
    myservo2.write(120);  //Head center
    myservo3.write(65);   //Jaw Close
    delay(500);
for(pos3=65; pos3<=117; pos3+=1) //Jaw Open
{
  myservo3.write(pos3);
  delay(6);
}
for(pos3=117; pos3>=65; pos3-=1)  //Jaw Close
{
  myservo3.write(pos3);
  delay(6);
}
}
else
{
  //Move center to Right
for(pos1=110; pos1<=150; pos1+=1) //eye movement
{
  myservo1.write(pos1);
  delay(35);
}
delay(500);

for(pos2=120; pos2<=150; pos2+=1) //neck movement 
{
  myservo2.write(pos2);
  delay(35);
}

for(pos1=150; pos1>=110; pos1-=1) //eye movement
{
  myservo1.write(pos1);
  delay(35);
}
delay(500);

for(pos2=150; pos2>=120; pos2-=1) //neck movement 
{
  myservo2.write(pos2);
  delay(35);
}
delay(500);


//Move center to left

for(pos1=110; pos1>=70; pos1-=1) //eye movement
{
  myservo1.write(pos1);
  delay(35);
}
delay(500);

for(pos2=120; pos2>=90; pos2-=1) //neck movement 
{
  myservo2.write(pos2);
  delay(35);
}
delay(500);

//Move left to center

for(pos1=70; pos1<=110; pos1+=1) //eye movement
{
  myservo1.write(pos1);
  delay(35);
}
delay(500);

for(pos2=90; pos2<=120; pos2+=1) //neck movement 
{
  myservo2.write(pos2);
  delay(35);
}
delay(500);
}
}
