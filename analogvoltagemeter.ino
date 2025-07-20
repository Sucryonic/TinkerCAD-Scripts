void setup()
{
  for(int i = 3; i > 0; i--)
  {
    pinMode(9+i, OUTPUT);
  }
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(A0); 
  while(sensorValue != 0)
  {
    if(sensorValue <= 341)
    {
      delay(10);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
    }else if(sensorValue <= 682 && sensorValue > 341)
      {
        delay(10);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, LOW);
      }else if(sensorValue <= 1023 && sensorValue > 682);
        {
          delay(10);
          digitalWrite(11, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(12, LOW);
        }
  }
  Serial.println(sensorValue);
}
