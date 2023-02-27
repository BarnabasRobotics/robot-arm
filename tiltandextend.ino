/*
Challenge #1: Add tilt & extend motors.  Test 0-180 degrees
Challenge #2: Add home() function to move everything to 90 degrees
Challenge #3: Update moveMotor to take in Servo motor parameter
Challenge #4: Move all motors in a sequence.  Keep an eye on cables.
Challenge #5: Play with motor movement speed
*/

#include <Servo.h>

//- servos move half a circle 0-180 degrees.
Servo baseMotor;
Servo tiltMotor;
Servo extendMotor;

//- runs only once when you turn on
void setup() {
  baseMotor.attach(6);
  tiltMotor.attach(9);
  extendMotor.attach(10);
  
  home();
  
  delay(1000);
  
}

void home() {
  tiltMotor.write(90);
  baseMotor.write(90);
  extendMotor.write(90);
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
    delay(1000);
    
    angle = angle + 15;
    
  }
  
}

void moveAngleDown(int target, Servo motor) {
  
  int angle = motor.read();
  
  while (angle >= target) {
    
    motor.write(angle);
    delay(1000);
    
    angle = angle - 15;
    
  }
}
  

//- runs forever in a loop after setup
void loop() {
  
  moveMotor(baseMotor,0);
  delay(1000);
  moveMotor(baseMotor,90);
  delay(1000);
  moveMotor(baseMotor,180);
  delay(1000);
  
  moveMotor(tiltMotor,0);
  delay(1000);
  moveMotor(tiltMotor,90);
  delay(1000);
  moveMotor(tiltMotor,180);
  delay(1000);
  
  
  moveMotor(extendMotor,0);
  delay(1000);
  moveMotor(extendMotor,90);
  delay(1000);
  moveMotor(extendMotor,180);
  delay(1000);
  
  while (1==1) {
    //-do nothing
  }

}
