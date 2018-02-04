// motor control pins
int leftMotorForward = 3;
int leftMotorBackward = 9;
int rightMotorForward = 11;
int rightMotorBackward = 10;

int stopButton = 2;
int speedDial = 15;

int speaker = 14;

int speed = 100; // min 60? max 254? USB vs 9V differs
int state = 1;


void setup() { 
  // put your setup code here, to run once:
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(stopButton, INPUT_PULLUP);
  pinMode(speedDial, INPUT);
  pinMode(speaker, OUTPUT);

  tone(speaker, 400, 200);
  delay(300);
  tone(speaker, 400, 200);
  delay(300);
  tone(speaker, 400, 200);
  delay(1000);
  startMelody();

  listenSpeedDial();
}



void loop() {
  listenStop();
  listenSpeedDial();
  dance();
  
}

void listenStop() {
  if (digitalRead(stopButton) == 0) {
    move(100, 0, 0, 0, 0);
    // halt program for 10 seconds
    tone(speaker, 800, 500);
    delay(10*1000);

    setup();
    //startMelody();
  }
}

void listenSpeedDial() {
    speed = 200;
    //speed = map(analogRead(speedDial), 0, 60, 1023, 250);
}

void startMelody() {
    tone(speaker, 400, 200);
    delay(200);
    tone(speaker, 500, 200);
    delay(200);
    tone(speaker, 600, 200);
    delay(200);
}

void move(int time, int lF, int lB, int rF, int rB) {
  analogWrite(leftMotorForward, lF);
  analogWrite(leftMotorBackward, lB);
  analogWrite(rightMotorForward, rF);
  analogWrite(rightMotorBackward, rB);
  delay(time);
}

void dance() {
  listenStop();
  
  state = random(1,5);
  switch(state) {
    case 1:
      // forwards
      tone(speaker, 440, 200);
      move(2000, speed, 0, speed, 0);
      break;
    case 2:
      // backwards
      tone(speaker, 294, 200);
      move(2000, 0, speed, 0, speed);
      break;
    case 3:
      // turn left
      tone(speaker, 523, 200);
      delay(200);
      tone(speaker, 523, 200);
      move(1000, 0, speed, speed, 0);
      break;
    case 4:
      // turn right
      tone(speaker, 587, 200);
      move(1000, speed, 0, 0, speed);
      break;  
  }
}
