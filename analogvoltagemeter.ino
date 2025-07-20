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
  if(sensorValue <= 341)
  {
  	digitalWrite(12, HIGH);
    delay(100);
  }
  else if(sensorValue <= 682 && sensorValue > 341)
  {
    digitalWrite(10, HIGH);
    delay(100);
  }
  else if(sensorValue <= 1023 && sensorValue > 682);
  {
    digitalWrite(11, HIGH);
    delay(100);
  }
  Serial.println(sensorValue);
}
