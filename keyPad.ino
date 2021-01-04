


void keyPad() 
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
        lcd.setCursor(0,0);
        lcd.print("Correct Pass    ");
        delay(1000);
         myservo.write(mot_max);
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
        lcd.setCursor(0,0);
        lcd.print("Wrong Pass     ");
         myservo.write(mot_min);
        delay(2000);
      analogWrite(buzzer_pin,240);
      delay(250);
      analogWrite(buzzer_pin,200);
      delay(250);
      analogWrite(buzzer_pin,180);
      delay(250);
      analogWrite(buzzer_pin,250);
      delay(250);
      analogWrite(buzzer_pin,LOW);
         
        i=0;
        count=0;
        lcd.setCursor(0,0);
        lcd.print("Enter the Pass");
        lcd.setCursor(0,1);
}
