/*
Challenge #1: Calibration your 1-winged servo horn
Challenge #2: Make it go back in forth between 0 and 180
Challenge #3: Move it between 0, 90 and 180
Challenge #4: Move it like: 0, 90, 180, 90, 0
Challenge #5: Move it like: 0, 45, 90, 135, 180, 135, 90, 45, 0
Challenge #6: Move it as close as possible to 30 seconds on a clock

Challenge #7: Move it like: 0, 90, 180, 90, 0 x 5
Challenge #8: Do challenge #7, but x 10
Challenge #9: Do Challenge #4 and #5, but with while loops
Challenge #10: Do challenge #6 but with a while loop
Challenge #11: How many seconds will it take if we increment by 2 degrees?  Try it out and see to confirm!
Challenge #12: How many seconds will it take if we increment by 1 degrees?  Try it out and see to confirm!
Challenge #13: Move between 1 and 180 and make sure to use this statement in your while loop 
               angle = angle * 2;

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
  
  int counter = 0;
  int angle = 0;
  
  //- move from 0 to 180
  while (angle <= 180) {
    
    //-do this code
    baseMotor.write(angle);
    delay(1000);
    
    angle = angle + 6;
    
  }
  
  //- move from 180 to 0
  angle = 180;
  while (angle >= 0) {
    
    baseMotor.write(angle);
    delay(1000);
    
    angle = angle - 6;
    
  }
  
  
  while (1==1) {
    //-do nothing
  }

}
