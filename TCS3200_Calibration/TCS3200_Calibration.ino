 /*A program to "calibrate the values
 * of the TCS3200 Color Sensor
 * 
 * Use this with an excel file to know an estimative of values.
 * 
 * This will use as a function on the Color Sorting Machine
 * 
 * 
 *  Inspired from the code made by Dejan Nedelkovski
    https://www.youtube.com/user/DejanNedelkovski
 */
#include<Servo.h>

 //Define the pins of the color sensor
#define s0 2 //S0 pin of the sensor on Arduino pin#2 
#define s1 3 //S1 pin of the sensor on Arduino pin#3 
#define s2 4 //S2 pin of the sensor on Arduino pin#4 
#define s3 5 //S3 pin of the sensor on Arduino pin#5
#define sensorOut 6 //Output pin of the sensor on Arduino pin#6 


//Variable to save the data coming from the sensorOut
int frequency = 0;

// Variable to save the color
byte identifiedColor = 0;

//We can attach a Servo to help us feeding the parts if need
Servo feedingServo;

//Potentiometer to use a Servo if need
byte potControllerFeeding = A0;

void setup(){
  Serial.begin(9600);
  pinMode (s0, OUTPUT);
  pinMode (s1, OUTPUT);
  pinMode (s2, OUTPUT);
  pinMode (s3, OUTPUT);
  pinMode (sensorOut, INPUT);

 // Setting frequency-scaling to 100%
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  
 //Attaching the Servo
  feedingServo.attach (9);

  
}

void loop(){
  
//Where we are going to save the analog read
  int feedingServoPosition = analogRead(potControllerFeeding);

//Map the analog read (255) to convert it to degrees (180)
  int mappedFeeder = map(feedingServoPosition, 0, 1023, 0, 180);
 
//Write the readed degrees on the Servos
  feedingServo.write(mappedFeeder);

/******Begin the sequence for the Colors******
 * 
 */
  
      //---Read RED values... S2 LOW - S3 LOW---
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    frequency = pulseIn(sensorOut, LOW);

    int redValue = frequency;

    Serial.print("R=");
    Serial.print(redValue);
    Serial.print("  ");

    delay(50);

    //---Read Green values ... S2 LOW - S3 HIGH---
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    frequency = pulseIn(sensorOut, LOW);

    int greenValue = frequency;

    Serial.print("G=");
    Serial.print(greenValue);
    Serial.print("  ");

    delay(50);


    //---Read Blue values ... S2 HIGH - S3 LOW---
    digitalWrite(s2, HIGH);
    digitalWrite(s3, LOW);
    frequency = pulseIn(sensorOut, LOW);

    int blueValue = frequency ;

    Serial.print("B=");
    Serial.print(blueValue);
    Serial.println("  ");

    delay(50);

   //---Read Clear values ... S2 HIGH - S3 HIGH---
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  frequency = pulseIn(sensorOut, LOW);

  int clearValue = frequency ;

  Serial.print("C=");
  Serial.print(clearValue);
  Serial.println("  ");

  delay(50);


}//Close Loop
