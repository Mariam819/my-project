void dht11() {
  delay(2000);
   float hum = dht.readHumidity();
    float temp = dht.readTemperature();
    
    Serial.print(" Humidity = ");
    Serial.println(hum);

    Serial.println(" Temperature = ");
    Serial.println(temp);
 delay(1000);                         // Wait 1 seconds before updating the values.
  float T = dht.readTemperature();

  if(T<=40)
  {
    digitalWrite(green_led, HIGH);    // The green led will turn on.
    digitalWrite(red_led, LOW);       //The red led will turn off.
  
  }

  else if(T>40){
   digitalWrite(green_led, LOW);    // The green led will turn off.
   digitalWrite(red_led, HIGH);       //The red led will turn on.
  }

  
 
}
