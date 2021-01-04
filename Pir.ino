void Pir()
{
  LightSensorVal = analogRead(A0);
  PIRSensorVal = digitalRead(2);
  RelayOutputVal = 8;
  if (LightSensorVal < 600) {
    if (PIRSensorVal == HIGH) {
      digitalWrite(8, HIGH);
      delay(5000); // Wait for 5000 millisecond(s)
    } else {
      digitalWrite(8, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    }
  }
}
