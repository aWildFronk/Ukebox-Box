//Things to add if I want to tryhard:
//Make the display for longer text - scrolling --No clue how to do that with the way I implemented this :(

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buttonOne = 3;      // This is the play/pause/scroll button
const int buttonTwo = 2;      //This is the Select Button
enum state { MODES, MENU,PLAYING};
enum state states;
int maxStates = 2;
int mode = 0;                 //This is to select between Mode 0 (plucking) or Mode 1 (Strumming)

bool isPlaying = true;

int strumSelect = 0;
const int strumCount = 4;
char *strumSongOptions[] = {"Riptide","Song B", "Song C","MODE SELECTION"};
int strumCodes[] = {1,2,3,69};         //this would be an unique ID for each song to send to the arduino, so that it knows which song to play.
                                    //The index should math the songs in the option idex's

int pluckSelect = 0;
const int pluckCount = 4;
char *pluckSongOptions[] = {"Over Rainbow","Song B", "Song C", "MODE SELECTION"};
int pluckCodes[] = {1,2,3,69};

void setup() {
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
  if(states == MODES){
    lcd.setCursor(0,0);
    if(mode == 1){
      lcd.print("MODE: STRUM");
    }
    else 
      lcd.print("MODE: PLUCK");
    
  }
  else if(states == MENU){
    
    lcd.setCursor(0,0);
    lcd.write("Now Selecting ");
    lcd.setCursor(0,1);
    if(mode == 0){
      lcd.write(pluckSongOptions[pluckSelect]);             //might be some error because pass by reference??
    }

    else
      lcd.write(strumSongOptions[strumSelect]);
  }
  else if(states == PLAYING){
     lcd.setCursor(0,1);
    if(mode == 0){
      lcd.write(pluckSongOptions[pluckSelect]);
      
    }
    else
      lcd.write(strumSongOptions[strumSelect]); 


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
  if(states == MODES){
    mode++;
      if (mode >= maxStates)
        mode = 0;
  }
  else if(states == MENU){
    if(mode == 0){
      pluckSelect++;
      if(pluckSelect >= pluckCount)
        pluckSelect = 0;        
    }
    else if(mode == 1){
      strumSelect++;
      if(strumSelect >= strumCount)
        strumSelect = 0;        
    }
  }
  else if(states == PLAYING){
    pausePlay();
  }
  updateDisplay();

}

void Button2(){    //if in MODE state, will select mode, if in MENU state, will select song, if in PLAYING, will go back to menu, and pause? Something like that
  if(states == MODES)
    states = MENU;
  else if(states == MENU)
  {
    states = PLAYING;
    if(mode == 0)
      play(mode);
    else
      play(mode);
  }
  else if(states == PLAYING){
    if(!isPlaying)
      pausePlay();
    states = MENU;
  }
  updateDisplay();
}

void play(int modetemp){
  int selectedSong;
  if(modetemp == 0){
    selectedSong = pluckCodes[pluckSelect];
  }
  else
    selectedSong = pluckCodes[strumSelect];
  if(selectedSong == 69){                                 //may have issue with this. IDK
    states = MODES;
    return;
    }
  else
    Serial.println(selectedSong);
}

void pausePlay(){     //insert some way of pausing it
  isPlaying = !isPlaying;
  return;
  }


