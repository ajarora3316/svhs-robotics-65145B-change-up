/*----------------------------------------------------------------------------*/
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*----------------------------------------------------------------------------*/

/* THURSDAY TODO: REMOVE CONTROLLER CONFIG ENTIRELY AND TEST AND VICE VERSA (FUNCTIONS), DIVIDING RPM VALUES*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    11, 12, 19, 20  
// chuteMotor           motor         5               
// leftIntake           motor         1               
// rightIntake          motor         10              
// Controller1          controller                    
// chuteMotor2          motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
using namespace vex;
competition Competition; // A global instance of competition

/* define your global instances of motors and other devices here */
motor_group cycler (leftIntake, rightIntake, chuteMotor, chuteMotor2);

/* insert url to motor label diagram here */

void whenControllerR1Pressed(){ // pulling balls into the chute by running intake and chute motors
  cycler.setVelocity(200, rpm); // set velocity of left/right intake motors and chute motor
  cycler.spin(reverse); // spin cycler motors inwards
  
  waitUntil(!Controller1.ButtonR1.pressing());

  cycler.stop(); // stop motors once R1 is released
}

void whenControllerR2Pressed(){ // pushing balls out the bottom of the chute by running intake and chute motors IN REVERSE
  cycler.setVelocity(200, rpm); // set velocity of left/right cycler motors 
  cycler.spin(forward); // spin left and right intake motors outwards
  waitUntil(!Controller1.ButtonR2.pressing());
  cycler.stop(); // stop motors once R2 is released
}


void whenControllerAxis3Pressed() {
  Drivetrain.setDriveVelocity(50, rpm);
  Drivetrain.drive(forward);

Controller1.Axis3.position();  // Axes 3 and 4 are on the left joystick of the controller
  waitUntil(!Controller1.Axis3.position(percent) && !Controller1.Axis4.position(percent));
  Drivetrain.stop();
}


/* pre-autonomous code below the cut */
void pre_auton(void) {
  vexcodeInit();  // Initializing Robot Configuration. DO NOT REMOVE!
  leftIntake.setPosition(0,degrees); // sets track to flap-less position to stay within side limit
  rightIntake.setPosition(0, degrees);

  cycler.setVelocity(110, rpm); // set rpm for all motors
  Drivetrain.setDriveVelocity(50, percent);
}


/* autonomous code below the cut */
void skillsAutonomous(void) {
  vexcodeInit(); // Initializing Robot Configuration. DO NOT REMOVE!
/* -------------------------------- SKILLS AUTONOMOUS code is as follows: -------------------------------- */
 // First Goal Draft
  Drivetrain.setDriveVelocity(50, percent);
  cycler.spinFor(forward,1500,degrees);
  Drivetrain.driveFor(forward,6,inches);
  cycler.spinFor(forward,2000,degrees);

  Drivetrain.driveFor(forward,13,inches);
  Drivetrain.turnFor(left,60,degrees);

  Drivetrain.driveFor(forward,30,inches);
  cycler.spinFor(forward,4000,degrees);
  Drivetrain.driveFor(reverse,5,inches);
  Drivetrain.turnFor(left,65,degrees);
  Drivetrain.driveFor(forward,18,inches);
  cycler.spinFor(forward,3000,degrees);

  // Second Goal Draft
  Drivetrain.driveFor(reverse,5,inches);
  Drivetrain.turnFor(left,35,degrees);

  // Throw red balls on floor
  cycler.spinFor(forward,3000,degrees);

  // Second Goal Draft Cont.
  Drivetrain.turnFor(left,100,degrees);
  Drivetrain.driveFor(forward,24,inches);

  // Pickup blue ball
  cycler.spinFor(forward,3000,degrees);
  Drivetrain.turnFor(left,30,degrees);
  Drivetrain.driveFor(forward,12,inches);

  // Score blue + pickup 3 red
  cycler.spinFor(forward,3000,degrees);
  Drivetrain.driveFor(reverse,5,inches);
  Drivetrain.turnFor(left,90,degrees);

  // eject red balls 
  cycler.spinFor(forward,3000,degrees);

  // Third Goal Draft
  Drivetrain.driveFor(forward,12,inches);
  cycler.spinFor(forward,3000,degrees);
  Drivetrain.driveFor(forward,12,inches);
  cycler.spinFor(forward,3000,degrees);

  // Eject red Ball
  Drivetrain.driveFor(reverse,5,inches);
  Drivetrain.turnFor(left,90,degrees);
  cycler.spinFor(forward,3000,degrees);
  Drivetrain.turnFor(right,135,degrees);

  // Navigate towards a ball
  Drivetrain.driveFor(forward,12,inches);
  cycler.spinFor(forward,3000,degrees);
}

void leftMatchAutonomous(void){   // this auton is for normal matches
  // move forward, turn left, intake ball 
  Drivetrain.driveFor(forward, 12, inches); 
  Drivetrain.turnFor(left, 90, degrees);
  Drivetrain.driveFor(forward, 12, inches); 
  cycler.spinFor(forward, 1000, degrees);
  Drivetrain.driveFor(forward, 2, inches); 
  cycler.spinFor(forward, 1000, degrees);

  // back up and position against center of goal, then eject red ball
  Drivetrain.driveFor(reverse, 4, inches); 
  cycler.spinFor(forward, 1000, degrees);
  Drivetrain.driveFor(forward, 2, inches); 
  Drivetrain.turnFor(left, 30, degrees);
  cycler.spinFor(reverse, 3000, degrees);

  // backup, turning right, moving towards goal H
  Drivetrain.driveFor(reverse, 12, inches); 
  Drivetrain.turnFor(right, 50, degrees);
  Drivetrain.driveFor(forward, 16, inches);

  // move forward and intake ball
  Drivetrain.turnFor(left, 75, degrees);
  Drivetrain.driveFor(forward, 8, inches);
  cycler.spinFor(forward, 3000, degrees);

  // back up, reorient, advance, and eject ball into goal H
  Drivetrain.driveFor(reverse, 7, inches); 
  Drivetrain.turnFor(left, 30, degrees);
  Drivetrain.driveFor(forward, 8, inches);
  cycler.spinFor(reverse, 3000, degrees);

  // backup, reorient, and advance towards corner goal
  Drivetrain.driveFor(reverse, 8, inches); 
  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(forward, 20, inches); 
  Drivetrain.turnFor(left, 100, degrees);
  cycler.spinFor(forward, 1000, degrees);
  Drivetrain.driveFor(forward, 16, inches); 
  cycler.spinFor(forward, 3000, degrees);
  
  // eject ball, backup, reorient
  Drivetrain.driveFor(reverse, 36, inches); // determine msmt. on field
  Drivetrain.turnFor(right, 180, degrees);
  cycler.spinFor(forward, 3000, degrees);
}

void rightMatchAutonomous(void) {
  // right side autonomous here
}

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) { // Each time through the loop your program should update motor + servo values based on feedback from the joysticks.
  Controller1.Axis3.changed(whenControllerAxis3Pressed);
  Controller1.ButtonR1.pressed(whenControllerR1Pressed);
  Controller1.ButtonR2.pressed(whenControllerR2Pressed);

  wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }
}

// Main will set up the competition functions and callbacks.
int main() {
  Competition.autonomous(leftMatchAutonomous); // set callbacks
  Competition.drivercontrol(usercontrol);
  pre_auton();
  
  while (true) {
    wait(1, sec);
  }
}