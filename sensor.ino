//dht 11 sensors
#include <DHT.h>
#define DHTPIN  9        // Set the DHT Pin.
#define DHTTYPE DHT11    //set the dht type. 

DHT dht(DHTPIN, DHTTYPE); 

int green_led =13;
int red_led=12;



void setup() {

Serial.begin(9600);
Serial.print("Temperature and Humidity Data)");
dht.begin();
pinMode(green_led,OUTPUT);
pinMode(red_led,OUTPUT);                         // Launch the DHT11 sensor
digitalWrite(green_led,LOW);
digitalWrite(red_led,LOW);


}

void loop() {
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
