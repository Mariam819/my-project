#include <Servo.h>
Servo myservo;
int trigger_pin = 13;
int echo_pin = 12;
int buzzer_pin = 11; 
int mot_min = 0;  
int mot_max = 90; 
int time;
int distance; 
void setup() 
{
        Serial.begin (9600); 
        pinMode (trigger_pin, OUTPUT); 
        pinMode (echo_pin, INPUT);
        pinMode (buzzer_pin, OUTPUT);
        myservo.attach(10);
  //put the servo in the close position first
  myservo.write(mot_min); 
}
void loop() 
{   digitalWrite (trigger_pin, LOW);
    delayMicroseconds (2);
    digitalWrite (trigger_pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigger_pin, LOW);
  // Distance Calculation
    time = pulseIn (echo_pin, HIGH);
    distance = (time * 0.034) / 2;

  if (distance <= 10) 
        {
        Serial.println (" Door Open ");
        Serial.print (" Distance= ");              
        Serial.println (distance);
      myservo.write(mot_max); 
      digitalWrite (buzzer_pin, HIGH);
        delay (500);
        }
  else {
        Serial.println (" Door closed ");
        Serial.print (" Distance= ");              
        Serial.print (distance);  
        myservo.write(mot_min); 
        digitalWrite (buzzer_pin, LOW);
        delay (500);        
       } 
}
