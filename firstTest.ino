#include <Servo.h>

Servo stringA;          // create servo object to control each servo
Servo stringE;
Servo stringC;
Servo stringG;

// Solenoid Initialize Solenoid_FretNumber_StringNumber 
// G - Thickest  E - Thinnest Goes from thickest to thinnest
int solenoid_1_G = 38;
int solenoid_1_C = 34;
int solenoid_1_A = 37;
int solenoid_1_E = 40;
int solenoid_2_G = 31;
int solenoid_2_C = 35;
int solenoid_2_A = 32;
//int solenoid_2_E = 37;
int solenoid_3_G = 32;
int solenoid_3_C = 39;
int solenoid_3_A = 36;
int solenoid_3_E = 33;

// Servo Helpers 
int tempo = 60;        //specific bpm for the song

int pos = 0;            // variable to store the servo position
int previous_pluck = 0; //variable to show previous position of servo (left = 0, right = 1 or vice versa lol)

int note_length = 0;    //to specify what length of note
int eigth = 100;        //arbitrary values, just to indicate relative length of each note
int quarter = 50;
int half = 25;
int whole = 13;

int adjusted_note = 0; //arbitrary delay value to make the note lengths correct = note_length*tempo (then divided by a constant, which is determined through testing)
int repeats = 0;       //indicate how many times to repeat pluck of notes of same string in succession (notes must be same duration)



void setup() {
  stringA.attach(9);    // attaches the servo on pin 9 to the servo object
  stringE.attach(8);
  stringG.attach(10);
  stringC.attach(11);


// 
  pinMode(solenoid_1_G, OUTPUT);
  pinMode(solenoid_1_C, OUTPUT);
  pinMode(solenoid_1_A, OUTPUT);
  pinMode(solenoid_1_E, OUTPUT);
  pinMode(solenoid_2_G, OUTPUT);
  pinMode(solenoid_2_C, OUTPUT);
  pinMode(solenoid_2_A, OUTPUT);
  //pinMode(solenoid_2_E, OUTPUT);
  pinMode(solenoid_3_G, OUTPUT);
  pinMode(solenoid_3_C, OUTPUT);
  pinMode(solenoid_3_A, OUTPUT);
  pinMode(solenoid_3_E, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  playChords();

}



void pluckSequence(){
  pluck(stringE, quarter);  // I
  pluck(stringA, quarter);
  pluck(stringG, quarter);  // was
  pluck(stringC, quarter);  // scared
}

void playChords() {
  Am();
  delay(50);
  pluckSequence();
  delay(3000);
  Cmaj();
  delay(50);
  pluckSequence();
  delay(3000);
  Gmaj();
  delay(50);
  pluckSequence();
  delay(3000);
  }
void Am(){

  digitalWrite(solenoid_2_G, HIGH);
  
}

void Cmaj() {
  digitalWrite(solenoid_3_A, HIGH);
  
}

void Gmaj(){
  digitalWrite(solenoid_2_C, HIGH);
  digitalWrite(solenoid_3_E, HIGH);
  digitalWrite(solenoid_2_A, HIGH);
}

void pluck(Servo &obj, int note_length){
     if (previous_pluck == 0) {
        for (pos = 0; pos <= 20; pos += 1) { // goes from 0 degrees to 20 degrees
          obj.write(pos);                   // tell servo to go to position in variable 'pos'
          delay(10);                       // waits 15 ms for the servo to reach the position
        }
      previous_pluck = 1;
      Serial.println(previous_pluck);
     }
     
     else {
      for (pos = 20; pos >= 0; pos -= 1) { // goes from 20 degrees to 0 degrees
          obj.write(pos);              // tell servo to go to position in variable 'pos'
          delay(10);                     // waits 15 ms for the servo to reach the position
      }
      previous_pluck = 0;
      Serial.println(previous_pluck);
    }
 
    adjusted_note = (note_length/tempo)*150;
    Serial.println(adjusted_note);
    delay(adjusted_note);
    }

