#include <Servo.h>
#include <Wire.h> // This is mandatory to run I2C comms from the mega and uno


#define SLAVE_ADDRESS 9



int songReceive = 5;

Servo servoA;
Servo servoE;
Servo servoC;
Servo servoG;

// initialize the Servo pins
int stringA = 10;
int stringE = 8;
int stringC = 9;
int stringG = 11;

// initialize the solenoid pins
int solenoidG1 = 40;
int solenoidC1 = 34;
int solenoidA1 = 37;
int solenoidE1 = 31;
//int solenoidG2 = 31;
int solenoidC2 = 34;
int solenoidA2 = 32;
int solenoidE2 = 33;
int solenoidG3 = 35;    
//int solenoidC3 = 39;
int solenoidA3 = 38;
int solenoidE3 = 39;

//SERVO HELPERS
bool previouspluckA = false;
bool previouspluckE = false;
bool previouspluckC = false;
bool previouspluckG = false;

//Servo Angle
int angA = 0;
int angE = 0;
int angC = 0;
int angG = 0;

//int note_length = 0;    //to specify what length of note
int whole = 750;        //arbitrary values, just to indicate relative length of each note
int half = 500;
int quarter = 250;
int eigth = 200;

void setup() {
  Serial.begin(9600);

  Wire.begin(SLAVE_ADDRESS); // initialize I2C comm
  Wire.onReceive(receiveData);
  
  // Setup for Servo pins 
  servoA.attach(stringA);
  servoE.attach(stringE);
  servoC.attach(stringC);
  servoG.attach(stringG);
  
  
  //Setup for solenoid pins (rename based on string/fret)
  pinMode(solenoidA1, OUTPUT);
  pinMode(solenoidA2, OUTPUT);
  pinMode(solenoidA3, OUTPUT);
  pinMode(solenoidE1, OUTPUT);
  pinMode(solenoidE2, OUTPUT);
  pinMode(solenoidE3, OUTPUT);
  pinMode(solenoidC1, OUTPUT);
  pinMode(solenoidC2, OUTPUT);
  //pinMode(solenoidC3, OUTPUT);
  pinMode(solenoidG1, OUTPUT);
  //pinMode(solenoidG2, OUTPUT);
  pinMode(solenoidG3, OUTPUT);
}

void receiveData(int bytes){
  songReceive = Wire.read();
  Serial.println(songReceive);
}

void solenoidOff(){
  digitalWrite(solenoidA1, LOW);
  digitalWrite(solenoidA2, LOW);
  digitalWrite(solenoidA3, LOW);
  digitalWrite(solenoidE1, LOW);
  digitalWrite(solenoidE2, LOW);
  digitalWrite(solenoidE3, LOW);
  digitalWrite(solenoidC1, LOW);
  digitalWrite(solenoidC2, LOW);
  digitalWrite(solenoidG1, LOW);
  digitalWrite(solenoidG3, LOW);
}

// SERVO COMMANDS 
void pluckA(int solenoid, int note_length){
  solenoidOff();
  if (solenoid != 0 && previouspluckA == false) {    //if not an open string and is the first pluck
    for (angA = 25; angA <= 25; angA++) {
      digitalWrite(solenoid, HIGH);
      servoA.write(angA);
      delay(500);
    }
    previouspluckA = true;
  }

  else if (solenoid != 0 && previouspluckA == true) {  //if not an open string and is not the first pluck
    for (angA = 0; angA >= 0; angA--) {
      digitalWrite(solenoid, HIGH);
      servoA.write(angA);
      delay(500);
    }
    previouspluckA = false;
  }

  //digitalWrite(solenoid, LOW);
  delay(50);
}

void pluckE(int solenoid, int noteLength){
  solenoidOff();
  if (solenoid != 0 && previouspluckE == false) {    //if not an open string and is the first pluck
    for (angE = 25; angE <= 25; angE++) {
      digitalWrite(solenoid, HIGH);
      servoE.write(angE);
      delay(noteLength);
    }
    previouspluckE = true;
  }

  else if (solenoid != 0 && previouspluckE == true) {  //if not an open string and is not the first pluck
    for (angE = 0; angE >= 0; angE--) {
      digitalWrite(solenoid, HIGH);
      servoE.write(angE);
      delay(noteLength);
    }
    previouspluckE = false;
  }
  
  //digitalWrite(solenoid, LOW);
  delay(50);
}

void pluckC(int solenoid, int noteLength){
  solenoidOff();
  if (solenoid != 0 && previouspluckC == false) {    //if not an open string and is the first pluck
    for (angC = 25; angC <= 25; angC++) {
      digitalWrite(solenoid, HIGH);
      servoC.write(angC);
      delay(noteLength);
    }
    previouspluckC = true;
  }

  else if (solenoid != 0 && previouspluckC == true) {  //if not an open string and is not the first pluck
    for (angC = 0; angC >= 0; angC--) {
      digitalWrite(solenoid, HIGH);
      servoC.write(angC);
      delay(noteLength);
    }
    previouspluckC = false;
  }
  
  //digitalWrite(solenoid, LOW);
  delay(50);
}

void pluckG(int solenoid, int noteLength){
  solenoidOff();
  if (solenoid != 0 && previouspluckG == false) {    //if not an open string and is the first pluck
    for (angG = 25; angG <= 25; angG++) {
      digitalWrite(solenoid, HIGH);
      servoG.write(angG);
      delay(noteLength);
    }
    previouspluckG = true;
  }

  else if (solenoid != 0 && previouspluckG == true) {  //if not an open string and is not the first pluck
    for (angG = 0; angG >= 0; angG--) {
      digitalWrite(solenoid, HIGH);
      servoG.write(angC);
      delay(noteLength);
    }
    previouspluckG = false;
  }
  
  //digitalWrite(solenoid, LOW);
  delay(50);
}

void pluckOpenA(int noteLength) {
  solenoidOff();
  if (previouspluckA == false) {
    servoA.write(25);                     //move to position 20
    delay(noteLength);
    previouspluckA = true;
  }
  else {
    servoA.write(0);                       //move to position 0
    delay(noteLength);
    previouspluckA = false;
    }
}

void pluckOpenE(int noteLength) {
  solenoidOff();
  if (previouspluckE == false) {
    servoE.write(25);                     //move to position 20
    delay(noteLength);
    previouspluckE = true;
  }
  else {
    servoE.write(0);                       //move to position 0
    delay(noteLength);
    previouspluckE = false;
  }
}

void pluckOpenC(int noteLength) {
  solenoidOff();
  if (previouspluckC == false) {
    servoC.write(25);                     //move to position 20
    delay(noteLength);
    previouspluckC = true;
  }
  else {
    servoC.write(0);                       //move to position 0
    delay(noteLength);
    previouspluckC = false;
  }
}

void pluckOpenG(int noteLength) {
  solenoidOff();
  if (previouspluckG == false) {
    servoG.write(25);                     //move to position 20
    delay(noteLength);
    previouspluckG = true;
  }
  else {
    servoG.write(0);                       //move to position 0
    delay(noteLength);
    previouspluckG = false;
  }
}


//SONG FUNCTIONS

void playRickroll(){
  //Never Gonna Give You Up Melody
  double factor = 0.75;
  
  delay(1000);
  pluckOpenC(quarter*factor);            //C0
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckE(solenoidE1, quarter*factor);    //E1
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckOpenA(half*factor);               //A0
  pluckOpenA(half*factor);               //A0
  pluckOpenG(half*factor);               //G0
  delay(half*factor);                   //^Never gonna give you up^
  
  pluckOpenC(quarter*factor);            //C0
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckE(solenoidE1, quarter*factor);    //E1
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckOpenG(half*factor);               //G0
  pluckOpenG(half*factor);               //G0
  pluckE(solenoidE1, half*factor);       //E1
  delay(half*factor);                    //^Never gonna let you down^
  
  pluckOpenC(quarter*factor);            //C0
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckE(solenoidE1, quarter*factor);    //E1
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckE(solenoidE1, half*factor);       //E1
  pluckOpenG(half*factor);               //G0
  pluckOpenE(half*factor);               //E0
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckOpenC(quarter*factor);            //C0
  pluckOpenC(half*factor);               //C0
  pluckOpenG(half*factor);               //G0
  pluckE(solenoidE1, quarter*factor);    //E1 
  delay(half*factor);                   //^Never gonna run around and desert you^
  
  pluckOpenC(quarter*factor);            //C0
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckE(solenoidE1, quarter*factor);    //E1
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckOpenA(half*factor);               //A0
  pluckOpenA(half*factor);               //A0
  pluckOpenG(half*factor);               //G0
  delay(half*factor);                   //^Never gonna make you cry^      
  
  pluckOpenC(quarter*factor);            //C0
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckE(solenoidE1, quarter*factor);    //E1
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckA(solenoidA3, half*factor);       //A3
  pluckOpenE(half*factor);               //E0
  pluckE(solenoidE1, half*factor);       //E1
  delay(half*factor);                   //^Never gonna say goodbye^
  
  pluckOpenC(quarter*factor);            //C0
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckE(solenoidE1, quarter*factor);    //E1
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckE(solenoidE1, half*factor);       //E1
  pluckOpenG(half*factor);               //G0
  pluckOpenE(half*factor);               //E0
  pluckC(solenoidC2, quarter*factor);    //C2
  pluckOpenC(quarter*factor);            //C0
  pluckOpenC(half*factor);               //C0
  pluckOpenG(half*factor);               //G0
  pluckE(solenoidE1, quarter*factor);    //E1
  delay(whole);                   //^Never gonna tell a lie and hurt you^

  solenoidOff();
}

void playHappybirthday(){
  delay(1000);
  pluckOpenC(quarter);
  pluckOpenC(quarter);
  pluckC(solenoidC2, half);
  pluckOpenC(half);
  pluckE(solenoidE1, half);
  pluckOpenE(half);
  delay(half);                //^Happy birthday to you^

  pluckOpenC(quarter);
  pluckOpenC(quarter);
  pluckC(solenoidC2, half);
  pluckOpenC(half);
  pluckE(solenoidE3, half);
  pluckE(solenoidE1, half);   
  delay(half);                //^Happy birthday to you^

  pluckOpenC(half);
  pluckOpenC(half);
  pluckA(solenoidA3, half);
  pluckOpenA(half);
  pluckE(solenoidE1, half);
  pluckOpenE(quarter);
  pluckC(solenoidC2, quarter);
  delay(quarter);             //^Happy birthday dear ____^

  pluckA(solenoidA1, quarter);
  pluckA(solenoidA1, quarter);
  pluckOpenA(half);
  pluckE(solenoidE1, half);
  pluckE(solenoidE3, half);
  pluckE(solenoidE1, half);
  delay(1000);                //^Happy birthday to you^

  solenoidOff();
}

void playLoveStory() {
  double factor = 1.5;
  
  pluckOpenA(eigth*factor);
  pluckA(solenoidA1, eigth*factor);
  pluckA(solenoidA1, quarter*factor);
  pluckA(solenoidA1, quarter*1.5*factor);
  pluckA(solenoidA1, eigth*factor); 

  pluckOpenA(eigth*factor);
  pluckA(solenoidA1, quarter*factor);
  pluckA(solenoidA3, quarter*1.5*factor);
  pluckA(solenoidA1, eigth*factor);
  pluckA(solenoidA1, eigth*factor);

  pluckOpenA(eigth*factor);
  pluckA(solenoidA1, quarter*factor);
  pluckA(solenoidA1, quarter*1.5*factor);
  pluckA(solenoidA1, eigth*factor);
  pluckA(solenoidA1, eigth*factor);

  pluckOpenA(eigth*2);
  pluckA(solenoidA1, quarter*factor);
  pluckA(solenoidA3, quarter*factor);
  pluckA(solenoidA1, eigth*factor);
  pluckOpenA(eigth*2);
  pluckA(solenoidA1, eigth*1.5*factor);

  pluckC(solenoidC2, whole);

  delay(half);
  pluckA(solenoidA1, eigth*factor);
  pluckA(solenoidA1, eigth*factor);
  pluckOpenA(quarter*factor);

  pluckOpenC(eigth*factor);
  pluckOpenC(eigth*factor);
  pluckC(solenoidC2, half*1.5*factor);

  delay(whole);

  pluckOpenA(eigth*factor);
  pluckA(solenoidA1, quarter*factor);
  pluckA(solenoidA1, quarter*1.5*factor);
  pluckA(solenoidA1, quarter*factor);
  pluckA(solenoidA1, quarter*factor);

  pluckOpenA(eigth*factor);
  pluckOpenA(eigth*factor);
  pluckA(solenoidA1, eigth*factor);
  pluckA(solenoidA3, quarter*factor);
  pluckA(solenoidA1, quarter*1.5*factor);

  pluckOpenA(eigth*factor);
  pluckA(solenoidA1, quarter*factor);
  pluckA(solenoidA1, quarter*factor);
  pluckA(solenoidA1, eigth*factor);
  pluckA(solenoidA1, eigth*factor);
  pluckA(solenoidA1, eigth*factor);

  pluckOpenA(eigth*factor);
  pluckA(solenoidA1, quarter*factor);
  pluckA(solenoidA3, quarter*factor);
  pluckA(solenoidA1, eigth*factor);
  pluckOpenA(eigth*factor);
  pluckA(solenoidA1, eigth*factor);

  pluckC(solenoidC2, whole);

  delay(half);
  pluckA(solenoidA1, eigth*factor);
  pluckOpenA(eigth*factor);
  pluckOpenC(eigth*factor);
  pluckOpenC(quarter*1.5*factor);
  pluckC(solenoidC2, half*1.5*factor);

  delay(half+quarter);
  pluckA(solenoidA1, eigth*factor);
  
  solenoidOff();
}

void playSoulsister(){
  delay(1000);
  pluckOpenA(half);

  pluckE(solenoidE3, 600);
  pluckE(solenoidE1, half);
  pluckE(solenoidE3, half);
  pluckOpenA(half);
  pluckE(solenoidE1, quarter);
  pluckC(solenoidC2, quarter);
  delay(half);

  pluckE(solenoidE1, half);
  pluckE(solenoidE3, half);
  pluckOpenA(half);
  pluckE(solenoidE1, quarter);
  pluckC(solenoidC2, quarter);
  delay(whole);

  pluckE(solenoidE1, quarter);
  pluckOpenA(half);
  pluckOpenA(half);
  pluckOpenA(whole);
  delay(quarter);

  pluckE(solenoidE3, eigth);
  pluckOpenA(eigth);
  pluckA(solenoidA1, eigth);
  pluckOpenA(eigth);
  pluckE(solenoidE3, eigth);
  
}

void loop(){
  //Serial.println(songReceive);  USED TO RUN I2C TRANSMISSION TEST
 // delay(1500);
  
  while(songReceive == 0 || songReceive == 1 || songReceive == 2 ) {
    if(songReceive == 0) {
      playHappybirthday();
      solenoidOff();
      
    }
    else if(songReceive == 1) {
      playLoveStory();
      solenoidOff();
    }
    else {
      playRickroll();
      solenoidOff();
    }
  }

  //playLoveStory();
  //playHappybirthday();
 // playRickroll();
  //playSoulsister();
}