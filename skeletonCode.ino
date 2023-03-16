#include <Servo.h>
#include <Wire.h> // This is mandatory to run I2C comms from the mega and uno


#define SLAVE_ADDRESS 9

int data_receive;

int datasend;

int 

// initialize the Servo pins
int stringA = 8;
int stringE = 9;
int stringC = 10;
int stringG = 12;

// initialize the solenoid pints

int solenoid1 = 13;
int solenoid2 = 14;
int solenoid3 = 15;
int solenoid4 = 16;
int solenoid5 = 17;
int solenoid6 = 18;
int solenoid7 = 19;
int solenoid8 = 20;
int solenoid9 = 21;

//SERVO HELPERS
bool previouspluck = false;
int note_length = 0;    //to specify what length of note
int whole = 100;        //arbitrary values, just to indicate relative length of each note
int half = 50;
int quarter = 25;
int eigth = 13;

int adjusted_note = 0; //arbitrary delay value to make the note lengths correct = note_length*tempo (then divided by a constant, which is determined through testing)
int repeats = 0;       //indicate how many times to repeat pluck of notes of same string in succession (notes must be same duration)


//

void setup() {
  Serial.begin(9600)

  Wire.begin(); // initialize I2C comm
  // Setup for Servo pins 
  Serial.attach(stringA);
  Serial.attach(stringE);
  Serial.attach(stringC);
  Serial.attach(stringG);
//Setup for solenoid pins
  pinMode(solenoid1, OUTPUT);
  pinMode(solenoid2, OUTPUT);
  pinMode(solenoid3, OUTPUT);
  pinMode(solenoid4, OUTPUT);
  pinMode(solenoid5, OUTPUT);
  pinMode(solenoid6, OUTPUT);
  pinMode(solenoid7, OUTPUT);
  pinMode(solenoid8, OUTPUT);
  pinMode(solenoid9, OUTPUT);

  Wire.begin();
}

void receiveData(){
  data_receive = Wire.read();
  Serial.println(data_receive);
}

void loop(){
  // Send some data to the slave uno. This bit of code to be included on the master side only 
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(datasend);

  Wire.endTransmission();




  
}


// SERVO COMMANDS 
void pluck(Servo &obj, int note_length){
  int pos = 0;

     if (previouspluck == false) {
        for (pos = 0; pos <= 20; pos +=1) { // goes from 0 degrees to 20 degrees
          obj.write(pos);                   // tell servo to go to position in variable 'pos'
          delay(10);                       // waits 15 ms for the servo to reach the position
        }
      previouspluck = true;
      Serial.println(previouspluck);
     }
     
     else {
      for (pos = 20; pos >= 0; pos -=1) { // goes from 20 degrees to 0 degrees
          obj.write(pos);              // tell servo to go to position in variable 'pos'
          delay(10);                     // waits 15 ms for the servo to reach the position
      }
      previouspluck = false;
      Serial.println(previouspluck);
    }
 
    adjusted_note = (note_length*tempo)/6;   // good concept Rachel! this idea will be helpful in determining what the future tempo calibration could look like
    Serial.println(adjusted_note);
    delay(adjusted_note);
    }

void testPluck(){
  pluck(stringE, quarter);  // I
  pluck(stringE, quarter);  // was
  pluck(stringE, quarter);  // scared
  pluck(stringE, quarter);  // of
  pluck(stringA, quarter);  // dentists      
}

// F U N C T I O N S    FOR     C   H   O   R  D  S 

// Chords for Riptide -->  Am, G, C, Gsus4, Fadd9

void Am(){

  // this is where the digitalWrite functions for the solenoids go

  // this is random command just to give the idea of how its gonna work
  digitalWrite(solenoid1, HIGH);
  digitalWrite(solenoid3, HIGH);
  digitalWrite(solenoid9, HIGH);
}

void G(){

  // this is where the digitalWrite functions for the solenoids go

  // this is random command just to give the idea of how its gonna work
  digitalWrite(solenoid1, HIGH);
  digitalWrite(solenoid3, HIGH);
  digitalWrite(solenoid9, HIGH);
}

void C(){

  // this is where the digitalWrite functions for the solenoids go

  // this is random command just to give the idea of how its gonna work
  digitalWrite(solenoid1, HIGH);
  digitalWrite(solenoid3, HIGH);
  digitalWrite(solenoid9, HIGH);
}

void Gsus4(){

  // this is where the digitalWrite functions for the solenoids go

  // this is random command just to give the idea of how its gonna work
  digitalWrite(solenoid1, HIGH);
  digitalWrite(solenoid3, HIGH);
  digitalWrite(solenoid9, HIGH);
}


void Fadd9(){

  // this is where the digitalWrite functions for the solenoids go

  // this is random command just to give the idea of how its gonna work
  digitalWrite(solenoid1, HIGH);
  digitalWrite(solenoid3, HIGH);
  digitalWrite(solenoid9, HIGH);
}