/* Joanna Ponce AS1 */
#include "LedControl.h"

LedControl lc=LedControl(6,8,7,1);

/* RGB LED */
int redLedPin = 4;
int greenLedPin = 3;
int blueLedPin = 2;
bool commonAnode = true; 


/* BUTTONS */
const int button1 = A1;
const int button2 = A2;
const int button3 = A3;
const int button4 = A4;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

/* BUTTON STATES */
bool buttonActive = false;
int buttonCurrent = 0;

/* EMOJIS */
byte smile[8]={B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
byte sad[8]={B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};
byte neutral[8]={B00111100,B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};
byte heart[8]={B00000000,B01100110,B11111111,B11111111,B11111111,B01111110,B00111100,B00011000};
byte heartMed[8]={B00000000,B00000000,B00100100,B01111110,B01111110,B00111100,B00011000,B00000000};
byte heartSmall[8]={B00000000,B00000000,B00000000,B00000000,B00011000,B00000000,B00000000,B00000000};
byte start[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};


void setup() {

  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

  setupButtons();

  setupRGB();

}

/* RGB LED SETUP */
void setupRGB(){
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

/* BUTTONS SETUP */
void setupButtons(){
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
}

/* DISPLAY EMOJIS */
void displayEmoji(int state, byte emoji[], int button) {
  
  if (state == LOW)
  {
    displayScreen(emoji);
    buttonActive = true;
    buttonCurrent = button; 
  } 
  else{
    if (buttonActive == false){
      displayScreen(start);
    }
    else {
      if(buttonCurrent == button){
        buttonActive = false;
        displayScreen(start);
      }
    }
  }
  
}

void displayScreen (byte buffer2[]){
  for (byte i = 0; i < 8; i++) {
    lc.setRow(0,i,buffer2[i]); 
  }
}

void loop() { 
  buttonState1 = digitalRead(button1); 
  buttonState2 = digitalRead(button2); 
  buttonState3 = digitalRead(button3);
  buttonState4 = digitalRead(button4);

  displayEmoji(buttonState1,smile, 1);
  delay(50); 
  displayEmoji(buttonState2,sad, 2);
  delay(50); 
  displayEmoji(buttonState3,neutral, 3);
  delay(50);

  /* animated heart emoji */ 
  displayEmoji(buttonState4,heartSmall, 4);
  delay(100);
  displayEmoji(buttonState4,heartMed, 4);
  delay(100);
  displayEmoji(buttonState4,heart, 4);
  
  /* rgb led display */
  setLED(255,0,0); //red
  delay(1000);
  setLED(0,255,0); //green
  delay(1000);
  setLED(0,0,255); // blue
  delay(1000);
  setLED(255,0,255);//magenta
  delay(1000);
}

void setLED(int RLED, int GLED, int BLED){
    if(commonAnode){
        RLED = map(RLED, 0,255, 255,0);
        GLED = map(GLED, 0,255, 255,0);
        BLED = map(BLED, 0,255, 255,0);
    }
    analogWrite(blueLedPin, BLED); 
    analogWrite(greenLedPin, GLED);
    analogWrite(redLedPin, RLED);
}
