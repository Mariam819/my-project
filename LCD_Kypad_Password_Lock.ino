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

#define led 13
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Servo myservo;
int buzzer=11;     //pin for the buzzer beep
int mot_min = 0;   //min servo angle  (set yours)
int mot_max = 90; //Max servo angle   (set yours)

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
  pinMode(buzzer,OUTPUT); 
 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Enter the Pass");
  lcd.setCursor(0, 1);
  pinMode(led,OUTPUT);
   //put the servo in the close position first
  myservo.write(mot_min);  
  
}

void loop() 
{
  char key = keypad.getKey();
  
  if (key>='0'&&key!='D')
  {
    lcd.print('*');
    pass[i]=key;
    i++;
  }else if(key=='D')
  {
    if(i==number)
    {
      for(int j=0;j<number;j++)
      {
        if(pass[j]==StorePass[j])count++;
      }
      if(count==number)
      {
        lcd.clear();
        digitalWrite(led,HIGH);
        lcd.setCursor(0,0);
        lcd.print("Correct Pass    ");
        delay(200);
         myservo.write(mot_max);
          analogWrite(buzzer,240);
      delay(250);
      analogWrite(buzzer,200);
      delay(250);
      analogWrite(buzzer,180);
      delay(250);
      analogWrite(buzzer,250);
      delay(250);
      analogWrite(buzzer,LOW);
      delay(1000);
        i=0;
        count=0;
        lcd.setCursor(0,0);
        lcd.print("Enter the Pass");
        lcd.setCursor(0,1);
      }else
      {
        printt();
      }
    }else
    {
      printt();
    }
  }
}

void printt()
{
        lcd.clear();
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
        lcd.print("Wrong Pass     ");
        delay(2000);
          myservo.write(mot_min);
        i=0;
        count=0;
        lcd.setCursor(0,0);
        lcd.print("Enter the Pass");
        lcd.setCursor(0,1);
}
