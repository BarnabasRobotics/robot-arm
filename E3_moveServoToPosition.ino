/*
Challenge #1: Create functions for moveAngleUp and 
moveAngleDown
Challenge #2: Using these functions, move between 0,15, 
90, 145,180,60, 30,10 ... 2 sec delay between each move
Challenge #3: Create moveBaseMotor master function
Challenge #4: Create move sequence using moveBaseMotor
Challenge #5: Sweep from 0 to 180 and back to 0 in 15
degree increments using moveBaseMotor.  Add delay
between each move
*/

#include <Servo.h>

//- servos move half a circle 0-180 degrees.
Servo baseMotor;

//- runs only once when you turn on
void setup() {
  baseMotor.attach(6);
  baseMotor.write(0);
  
  delay(1000);
  
}

void moveBaseMotor(int target) {
  
  //- figure out if we need to move up or down
  
  int myCurrentAngle = baseMotor.read();
  
  //- if myCurrentAngle is > target, go down
  if (myCurrentAngle > target) {
    moveAngleDown(target);
  }
  
  //- if myCurrentAngle is < target, go up
  if (myCurrentAngle < target) {
    moveAngleUp(target);
  }
  
}

void moveAngleUp(int target) {
  
  int angle = baseMotor.read();
  
  while (angle <= target) {
    
    //-do this code
    baseMotor.write(angle);
    delay(30);
    
    angle = angle + 15;
    
  }
  
}

void moveAngleDown(int target) {
  
  int angle = baseMotor.read();
  
  while (angle >= target) {
    
    baseMotor.write(angle);
    delay(30);
    
    angle = angle - 15;
    
  }
}
  

//- runs forever in a loop after setup
void loop() {
  
  int counter = 0;
  int angle = 0;
  
  moveBaseMotor(15);
  delay(2000);
  moveBaseMotor(0);
  delay(2000);
  moveBaseMotor(45);
  delay(2000);
  moveBaseMotor(160);
  delay(2000);
  moveBaseMotor(90);

  while (1==1) {
    //-do nothing
  }

}
