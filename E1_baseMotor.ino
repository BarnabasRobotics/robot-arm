/*
Challenge #1: Calibration your 1-winged servo horn
Challenge #2: Make it go back in forth between 0 and 180
Challenge #3: Move it between 0, 90 and 180
Challenge #4: Move it like: 0, 90, 180, 90, 0
Challenge #5: Move it like: 0, 45, 90, 135, 180, 135, 90, 45, 0
Challenge #6: Move it as close as possible to 30 seconds on a clock


*/

#include <Servo.h>

//- servos move half a circle 0-180 degrees.
Servo baseMotor;

//- runs only once when you turn on
void setup() {
  baseMotor.attach(6);
}


//- runs forever in a loop after setup
void loop() {
  
  baseMotor.write(0);
  delay(1000);
  baseMotor.write(180);
  delay(1000);
  
}
