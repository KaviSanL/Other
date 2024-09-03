/* A program to calibrate the feeding and decision Servo
 *  for the Color Soting machine.
 *  
 *  We will use 2 Potentiometer 2k Ohms (or other) 
 *  to read the Analog Input and write it down on the Servos
*/

#include<Servo.h>

//Declaring our Servos
Servo feedingServo;
Servo decisionServo;

//Delcaring our Potentiometers
byte potControllerFeeding = A0;
byte potControllerDecision = A2;

void setup() {

  //Attaching the Servos
  feedingServo.attach (9);
  decisionServo.attach(11);

  //PinMode for our Potentiometers
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);

  //Begin Serial communication
  Serial.begin(9600);

}//Close setup

void loop() {

//Where we are going to save the analog read
  int feedingServoPosition = analogRead(potControllerFeeding);
  int decisionServoPosition = analogRead(potControllerDecision);

//Map the analog read (255) to convert it to degrees (180)
  int mappedFeeder = map(feedingServoPosition, 0, 1023, 0, 180);
  int mappedDecision = map(decisionServoPosition, 0, 1023, 0, 180);

//Write the readed degrees on the Servos
  feedingServo.write(mappedFeeder);
  decisionServo.write(mappedDecision);


//Print the current position to know what values to use next.
  Serial.print("The feeding servo is in position = ");
  Serial.println(mappedFeeder);

  Serial.print("The decision servo is in position = ");
  Serial.println(mappedDecision);
  Serial.println("");

  delay(200);

}//close loop
