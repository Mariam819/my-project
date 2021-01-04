void ultraSonic() 
{ 
  digitalWrite (trigger_pin, LOW);
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
