/*

  The circuit:
 * LCD RS pin to digital pin A0
 * LCD Enable pin to digital pin A1
 * LCD D4 pin to digital pin A2
 * LCD D5 pin to digital pin A3
 * LCD D6 pin to digital pin A4
 * LCD D7 pin to digital pin A5
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 
 */
// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
Servo myservo;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
int trigger_pin = 13;
int echo_pin = 12;
int buzzer_pin = 11; 
int mot_min = 0;  
int mot_max = 90; 
int time;
int distance; 
int time1,time2 ;
//Keypad config
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char StorePass[]="1234ABC";
int i=0,count=0,number=sizeof(StorePass)-1;
char pass[sizeof(StorePass)-1];

void setup() {
   myservo.attach(10); //attach the servo to pin D10
  pinMode(buzzer_pin,OUTPUT);
   pinMode (trigger_pin, OUTPUT); 
   pinMode (echo_pin, INPUT);
 
 
  Serial.begin (9600);
  lcd.begin(16, 2);
    lcd.setCursor(0, 0);
  lcd.print("Enter the Pass");
  lcd.setCursor(0, 1);
  myservo.write(mot_min);  

}

void loop(){
  
if(millis()-time1>=1000)
  {
  time1=millis();
  ultraSonic();
  
  } 
  
 else if(millis()-time2>=5)
  {
  time2=millis();
   keyPad();
   
  
  }
  
 
}
