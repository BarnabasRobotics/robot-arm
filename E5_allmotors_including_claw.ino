/*
Challenge #1: Wire and test claw motor
Challenge #2: Find min and max angles for all motors and create the macros
Challenge #3: Run through all the motors using the min/max values
Challenge #4: Code the robot to pick up a marker
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


void moveMotor(Servo motor, int target) {
  
  //- figure out if we need to move up or down
  
  int myCurrentAngle = motor.read();
  
  //- if myCurrentAngle is > target, go down
  if (myCurrentAngle > target) {
    moveAngleDown(target,motor);
  }
  
  //- if myCurrentAngle is < target, go up
  if (myCurrentAngle < target) {
    moveAngleUp(target,motor);
  }
  
}

void moveAngleUp(int target, Servo motor) {
  
  int angle = motor.read();
  
  while (angle <= target) {
    
    //-do this code
    motor.write(angle);
    delay(100);
    
    angle = angle + 5;
    
  }
  
}

void moveAngleDown(int target, Servo motor) {
  
  int angle = motor.read();
  
  while (angle >= target) {
    
    motor.write(angle);
    delay(100);
    
    angle = angle - 5;
    
  }
}
  

//- runs forever in a loop after setup
void loop() {
  
  
  moveMotor(clawMotor,CLAW_CLOSE);
  delay(1000);
  moveMotor(clawMotor,CLAW_OPEN);
  delay(1000);
  moveMotor(clawMotor,CLAW_CLOSE);
 

  moveMotor(baseMotor,BASE_MIN);
  delay(1000);
  moveMotor(baseMotor,BASE_MAX);
  delay(1000);
  moveMotor(baseMotor,BASE_MIN);
  delay(1000);

  
  moveMotor(tiltMotor,TILT_MIN);
  delay(1000);
  moveMotor(tiltMotor,TILT_MAX);
  delay(1000);
  moveMotor(tiltMotor,TILT_MIN);
  

  moveMotor(extendMotor,EXTEND_MIN);
  delay(1000);
  moveMotor(extendMotor,EXTEND_MAX);
  delay(1000);
  moveMotor(extendMotor,EXTEND_MIN);

  
  while (1==1) {
    //-do nothing
  }

}
