/*
Challenge #1: Create individual move functions to simplify code
Challenge #2: Experiment with picking up an object
*/

#include <Servo.h>

#define CLAW_OPEN 120
#define CLAW_CLOSE 5

#define BASE_MAX 180
#define BASE_MIN 0

#define TILT_MAX 180
#define TILT_MIN 120

#define EXTEND_MAX 150
#define EXTEND_MIN 75

//- servos move half a circle 0-180 degrees.
Servo baseMotor;
Servo tiltMotor;
Servo extendMotor;
Servo clawMotor;

//- runs only once when you turn on
void setup() {
  baseMotor.attach(6);
  tiltMotor.attach(9);
  extendMotor.attach(10);
  clawMotor.attach(11);
  
  home();
  
  delay(1000);
  
  Serial.begin(9600);
  
}

void home() {
  tiltMotor.write(90);
  baseMotor.write(90);
  extendMotor.write(90);
  clawMotor.write(90);
}


void moveMotor(Servo motor, int target, int min, int max) {
  
  //- figure out if we need to move up or down
  
  int myCurrentAngle = motor.read();
  
  //- if myCurrentAngle is > target, go down
  if (myCurrentAngle > target) {
      moveAngleDown(target,motor,min,max);
  }
  
  //- if myCurrentAngle is < target, go up
  if (myCurrentAngle < target) {
      moveAngleUp(target,motor,min,max);
  }
  
}

void moveAngleUp(int target, Servo motor, int min, int max) {
  
  int angle = motor.read();
  
  while (angle <= target) {
    
    if (angle <= max) {
    
      //-do this code
      motor.write(angle);
      delay(20);
      
      angle = angle + 5;
    }
    else {
      break;
    }
    
  }
  
}

void moveAngleDown(int target, Servo motor, int min, int max) {
  
  int angle = motor.read();
  
  while (angle >= target) {
    
    if (angle >= min) {
    
      motor.write(angle);
      delay(20);
    
      angle = angle - 5;
    }
    else {
      break;
    }
    
  }
}
  
  
void moveClaw(int target) {
  moveMotor(clawMotor,target,CLAW_CLOSE, CLAW_OPEN);
}

void moveBase(int target) {
  moveMotor(baseMotor,target, BASE_MIN, BASE_MAX);
}

void moveTilt(int target) {
  moveMotor(tiltMotor,target,TILT_MIN, TILT_MAX);
}

void moveExtend(int target) {
  moveMotor(extendMotor,target,EXTEND_MIN, EXTEND_MAX);
}

//- runs forever in a loop after setup
void loop() {
  
  
  //- analogRead(0) -> CONTROL 1 -> Base Motor
  //- analogRead(1) -> CONTROL 2 -> Tilt Motor
  //- analogRead(2) -> CONTROL 3 -> Extend Motor
  //- analogRead(3) -> CONTROL 4 -> Claw Motor
  //- range of analog is [0-1023]
  

  //- comment this out if you want faster processing
/*
  Serial.print("Base: ");
  Serial.println(analogRead(0));

  Serial.print("Tilt: ");
  Serial.println(analogRead(1));
  
  Serial.print("Extend: ");
  Serial.println(analogRead(2));
  
  Serial.print("Claw: ");
  Serial.println(analogRead(3));
  
  Serial.println();
  
  delay(500);
*/

  //-BaseMotor
  moveBase(map(analogRead(0),0,1023,BASE_MIN,BASE_MAX));
  
  //-TiltMotor
  moveTilt(map(analogRead(1),0,1023,TILT_MIN,TILT_MAX));
  
  //-ExtendMotor
  moveExtend(map(analogRead(2),0,1023,EXTEND_MIN,EXTEND_MAX));
  
  //-ClawMotor
  moveClaw(map(analogRead(3),0,1023,CLAW_CLOSE,CLAW_OPEN));
  
  
}
