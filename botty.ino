
int leftMotorForward = 3;
int leftMotorBackward = 9;
int rightMotorForward = 11;
int rightMotorBackward = 10;

int speed = 100;
int state = 1;


void setup() {
  // put your setup code here, to run once:
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
}

void move(int time, int lF, int lB, int rF, int rB) {
  analogWrite(leftMotorForward, lF);
  analogWrite(leftMotorBackward, lB);
  analogWrite(rightMotorForward, rF);
  analogWrite(rightMotorBackward, rB);
  delay(time);
}

void loop() {
  dance();
  
}

void dance() {
  // put your main code here, to run repeatedly:
  state = random(1,5);
  switch(state) {
    case 1:
      // forwards
      move(2000, speed, 0, speed, 0);
      break;
    case 2:
      // backwards
      move(2000, 0, speed, 0, speed);
      break;
    case 3:
      // turn left
      move(1000, 0, speed, speed, 0);
      break;
    case 4:
      // turn right
      move(1000, speed, 0, 0, speed);
      break;  
  }
}
