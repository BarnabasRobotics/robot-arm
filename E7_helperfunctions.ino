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
      delay(100);
      
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
      delay(100);
    
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

  moveClaw(180);
  delay(1000);
  moveExtend(160);
  delay(1000);
  moveClaw(0);
  delay(1000);
  moveTilt(160);
  delay(1000);
  moveExtend(40);

/*
  moveClaw(0);
  moveClaw(180);
  moveClaw(0);
  
  moveBase(0);
  moveBase(180);
  moveBase(90);
  
  moveTilt(0);
  moveTilt(180);
  moveTilt(90);
  
  moveExtend(0);
  moveExtend(180);
  moveExtend(90);
*/

  while (1==1) {
    //-do nothing
  }

}
