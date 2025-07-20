void setup()
{
  for(int i = 13; i > 10; i--)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

bool answer;
int r;
int g;
int b;

void loop()
{
  Serial.println("R(0-255): ");
  answer = false;
  while(answer == false)
  {
   	if(Serial.available() > 0)
    {
      r = Serial.parseInt(); 
      answer = true;
    }
  }
  
  Serial.println("G(0-255): ");
  answer = false;
  while(answer == false)
  {
   	if(Serial.available() > 0)
    {
      g = Serial.parseInt(); 
      answer = true;
    }
  }
  
  Serial.println("B(0-255): ");
  answer = false;
  while(answer == false)
  {
   	if(Serial.available() > 0)
    {
      b = Serial.parseInt(); 
      answer = true;
    }
  }
  
  analogWrite(13, r);
  analogWrite(12, b);
  analogWrite(11, g);
  Serial.println("RGB:(" + String(r) + ", " + String(g) + ", " + String(b) + ")");
  Serial.println("Try Again");
  
}