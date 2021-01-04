#include <DHT.h>
#define DHTPIN  9        // Set the DHT Pin.
#define DHTTYPE DHT11    //set the dht type. 

DHT dht(DHTPIN, DHTTYPE); 

int green_led =13;
int red_led=12;
int LightSensorVal = 0;

int PIRSensorVal = 0;

int RelayOutputVal = 0;





void setup() {
  Serial.begin(9600);
Serial.print("Temperature and Humidity Data)");
dht.begin();
   pinMode(green_led,OUTPUT);
   pinMode(red_led,OUTPUT);                         // Launch the DHT11 sensor
   pinMode(A0, INPUT);
   pinMode(2, INPUT);
   pinMode(8, OUTPUT);
   digitalWrite(green_led,LOW);
 digitalWrite(red_led,LOW);
} 

void loop() {
Pir();
dht11();

}
