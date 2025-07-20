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
  while(sensorValue <= 341 && sensorValue > 0)
  {
    sensorValue = analogRead(A0);
    digitalWrite(12, HIGH);
    Serial.println(sensorValue);
    if(sensorValue > 341 || sensorValue == 0)
    {
      digitalWrite(12, LOW);
      break;
    }
  }
  while(sensorValue <= 682 && sensorValue > 341)
  {
    sensorValue = analogRead(A0);
    digitalWrite(10, HIGH);
    Serial.println(sensorValue);
    if(sensorValue > 682 || sensorValue < 341)
    {
      digitalWrite(10, LOW);
      break;
    }
  }
  while(sensorValue <= 1023 && sensorValue > 682)
  {
    sensorValue = analogRead(A0);
    digitalWrite(11, HIGH);
    Serial.println(sensorValue);
    if(sensorValue < 682)
    {
      digitalWrite(11, LOW);
      break;
    }
  }
}
