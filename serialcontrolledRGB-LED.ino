void setup()
{
  for(int i = 13; i > 10; i--)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

int r;
int g;
int b;

void loop()
{
  Serial.println("R(0-255): ");
  while(Serial.available() == 0)
  {
   	if(Serial.available() > 0)
    {
      r = Serial.parseInt(); 
    }
  }
  
  Serial.println("G(0-255): ");
  while(Serial.available() == 0)
  {
   	if(Serial.available() > 0)
    {
      g = Serial.parseInt(); 
    }
  }
  
  Serial.println("B(0-255): ");
  while(Serial.available() == 0)
  {
   	if(Serial.available() > 0)
    {
      b = Serial.parseInt(); 
    }
  }
  
  analogWrite(13, r);
  analogWrite(12, b);
  analogWrite(11, g);
  Serial.println("(" + String(r) + ", " + String(g) + ", " + String(b) + ")");
  Serial.println("Try Again!");
}
