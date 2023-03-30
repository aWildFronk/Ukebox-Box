//Things to add if I want to tryhard:
//Make the display for longer text - scrolling --No clue how to do that with the way I implemented this :(

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buttonOne = 3;      // This is the play/pause/scroll button
const int buttonTwo = 2;      //This is the Select Button
enum state {MENU,PLAYING};
enum state states;
int maxStates = 2;
int mode = 0;                 //This is to select between Mode 0 (plucking) or Mode 1 (Strumming)

bool isPlaying = true;

int songSelect = 0;
const int songCount = 3;
char *songOptions[] = {"Over The Rainbow","Song B", "Song C"};
int songCodes[] = {1,2,3};

void setup() {
  Serial.begin(9600);
  pinMode(buttonOne,INPUT_PULLUP);
  pinMode(buttonTwo,INPUT_PULLUP);
/*
  attachInterrupt(digitalPinToInterrupt(buttonOne), Button1, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonTwo), Button2, FALLING);
  */

  lcd.begin(16, 2);
  updateDisplay();
}

void loop() {
  if(digitalRead(buttonOne)==0){
    Button1();
    delay(300);                       //free will is an illusion
      }
  if(digitalRead(buttonTwo)==0){
    Button2();
    delay(300);
    }

}

void updateDisplay(){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.clear();
  if(states == MENU){
    lcd.setCursor(0,0);
    lcd.write("Now Selecting ");
    lcd.setCursor(0,1);
    lcd.write(songOptions[songSelect]);             //might be some error because pass by reference??
    
  }
  else if(states == PLAYING){
    lcd.setCursor(0,1);
    lcd.write(songOptions[songSelect]);
    lcd.setCursor(0,0);
    if( isPlaying == false){
      lcd.write("Paused.");
    }
    else{
      lcd.write("Playing.");
      }
    }
}


void Button1(){       //function for button1 interupt. will pause/play if in playing mode, will scroll through MENU options, will scroll though mode options
  if(states == MENU){
    songSelect++;
    if(songSelect >= songCount)
      songSelect = 0;      
  }        
  else if(states == PLAYING){
    pausePlay();
  }
  updateDisplay();
}

void Button2(){    //if in MODE state, will select mode, if in MENU state, will select song, if in PLAYING, will go back to menu, and pause? Something like that
  if(states == MENU)
  {
    states = PLAYING;
    play();
  }
  else if(states == PLAYING){
    if(!isPlaying)
      pausePlay();
    states = MENU;
  }
  updateDisplay();
}

void play(){
  int selectedSong = 0;
  selectedSong = songCodes[songSelect];
  Serial.println(selectedSong);
}

void pausePlay(){     //insert some way of pausing it
  isPlaying = !isPlaying;
  return;
  }


