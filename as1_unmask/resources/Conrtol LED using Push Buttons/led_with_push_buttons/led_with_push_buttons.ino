const int BUTTON1 = 2;
const int BUTTON2 = 4;
const int BUTTON3 = 6;
const int BUTTON4 = 3;
const int LED1 = 8;
const int LED2 = 12;
const int LED3 = 11;
const int LED4 = 9;
int BUTTONstate1 = 0;
int BUTTONstate2 = 0;
int BUTTONstate3 = 0;
int BUTTONstate4 = 0;

void setup()
{
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  digitalWrite(LED1, LOW);
  
}

void loop()

{
  
  BUTTONstate1 = digitalRead(BUTTON1);
  if (BUTTONstate1 == HIGH)
  {
    digitalWrite(LED1, HIGH);
  } 
  else{
    digitalWrite(LED1, LOW);
  }
  BUTTONstate2 = digitalRead(BUTTON2);
  if (BUTTONstate2 == HIGH)
  {
    digitalWrite(LED2, HIGH);
  } 
  else{
    digitalWrite(LED2, LOW);
  }
  BUTTONstate3 = digitalRead(BUTTON3);
  if (BUTTONstate3 == HIGH)
  {
    digitalWrite(LED3, HIGH);
  } 
  else{
    digitalWrite(LED3, LOW);
  }
  BUTTONstate4 = digitalRead(BUTTON4);
  if (BUTTONstate4 == HIGH)
  {
    digitalWrite(LED4, HIGH);
  } 
  else{
    digitalWrite(LED4, LOW);
  }
}
