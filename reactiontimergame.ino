//This aims to create a Reaction Timer Game - Steven Lin

//Initializes var time which will hold the reaction time
unsigned long time;
//Initializes var gameStart which will hold the state of the game
bool gameStart = false;


void setup()
{
  /*
  Sets the pin connected to the LED(12) to OUTPUT in order to
  use the digitalWrite function to apply a voltage to light up 
  the LED
  */
  pinMode(12, OUTPUT);
  /*
  Sets the pin connected to the button(11) to INPUT_PULLUP - sets
  pin 11 to HIGH(when read) by default until the button is pressed 
  - connects pin to ground - sets pin 11 to LOW - can be read with 
  digitalRead to be used in if statements
  */
  pinMode(11, INPUT_PULLUP);
  //Initializes serial monitor to enable analog output
  Serial.begin(9600);
}

void loop()
{
  if(!gameStart && digitalRead(11) == LOW)//Checks for button press
  {
    delay(10); //Debounce
    while(digitalRead(11) == LOW); //Wait for button to release
    
    for(int num = 3; num > 0; num--)//Flash 3x to signify start
    {
      digitalWrite(12, HIGH);
      delay(100);
      digitalWrite(12,LOW);
      delay(100);
    }
    
    delay(random(900,2900));//Random delay before turn on LED
    digitalWrite(12, HIGH);
    time = millis();//Record current runtime
    gameStart = true;//set game state to start
    while(gameStart == true)
    {
      if(digitalRead(11) == LOW)
      {
        delay(10);
      	while(digitalRead(11) == LOW);
      
      	digitalWrite(12, LOW);
      	time = millis() - time;//subtract current runtime from prev
        //to get reaction time
      
      	Serial.print("Reaction time(ms): ");
        Serial.println(time);
      
      	gameStart = false;//set game start to stop
        break;//brute force break loop because I'm lazy and I had 
        //bad luck with loops for the past 3 hours
      }
    }
  }
  delay(500);//prevent accidental restart
}
