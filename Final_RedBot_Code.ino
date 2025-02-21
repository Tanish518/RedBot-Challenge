#include <RedBot.h>

// Initialize RedBot components
RedBotMotors motors;

// Motor speed (adjust as needed)
int motorSpeed = 200; // Reduced base speed range: -255 to 255
int turnSpeed = 150; // Reduced maximum speed for sharper turns

// Time durations for straight movement and turns (in milliseconds)
const int straightTime = 2700; // Base time to move straight (adjust as needed)
const int additionalTime = 2000; // Additional time for 15 cm (adjust based on speed)
const int firstTurnTime = 250; // Slightly sharper turn for all turns
const int alienTurnTime = 150; //Turn to go towards the alien 
const int secondTurnTime = 400; // Sharper turn for the second turn (reduced by 50 ms)
const int thirdTargetExtraTime = -100; // Reduce the third target distance by 2 seconds

void setup() {
  Serial.begin(9600); // Initialize serial communication
  delay(2000); // Wait for 1 second before starting
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
}

void loop() {
  // Move straight and perform turns based on the sequence
  moveStraight(1700); // Move straight for the first target duration + 15 cm

 //////ONLY USE CODE BELOW IF USING MOTOR TO CONTROL CLAW MECHANISM
 //go into the alien  
 // turnLeft(180);
 // moveStraight(700);

  // Have the claw open 
 // digitalWrite(A4,HIGH);
  //digitalWrite(A5,LOW);
  //delay(700);
  //digitalWrite(A4,LOW);
  //digitalWrite(A5,HIGH);
  //delay(700);

  //close the claw
  //digitalWrite(A4,LOW);
 // digitalWrite(A5,LOW);

//back out of alien area
 // moveBackwards(600);
 // turnLeft(300); // Sharper turn after the second target duration
//  moveBackwards(500); // Move straight for the second target duration
 // turnRight(275); // Sharper turn after the second target duration

//if not going into alien area, turn onto ramp
  turnRight(430);
  moveStraight(450);
  turnRight(430);
  
//on the ramp
  moveStraight(2500); // Move straight for the third target duration (reduced by 2 seconds)
  turnLeft(460); // Turn left after the third target distance

//horizantal long area 
  moveStraight(1800); // Move straight for the fourth target duration
  moveBackwards(200);
  turnLeft(460); // Turn left after the fourth target distance

//final leg
  moveStraight(1800); // Move straight for the fifth target duration

  // Stop the motors after completing all movements
  motors.brake();
  while (true); // Stop the program
}

// Function to move straight for a given duration
void moveStraight(int duration) {
  // Inverted motors: swap the motor directions
  motors.leftDrive(170); // Left motor backward
  motors.rightDrive(160); // Right motor backward
  delay(duration); // Move for the specified duration
  motors.brake(); // Stop the motors
  delay(500); // Pause before the next action
}


// Function to move backwards for a given duration
void moveBackwards(int duration) {
  // Inverted motors: swap the motor directions
  motors.leftDrive(-170); // Left motor backward
  motors.rightDrive(-160); // Right motor backward
  delay(duration); // Move for the specified duration
  motors.brake(); // Stop the motors
  delay(500); // Pause before the next action
}

// Function to turn right with adjustable turn time
void turnRight(int turnDuration) {
  // Inverted motors: swap the motor directions
  motors.leftDrive(turnSpeed); // Left motor backward at maximum speed
  motors.rightDrive(-turnSpeed); // Right motor forward at maximum speed
  delay(turnDuration); // Turn for the specified duration
  motors.brake(); // Stop the motors
  delay(500); // Pause before the next action
}

// Function to turn left with adjustable turn time
void turnLeft(int turnDuration) {
  // Inverted motors: swap the motor directions
  motors.leftDrive(-turnSpeed); // Left motor forward at maximum speed
  motors.rightDrive(turnSpeed); // Right motor backward at maximum speed
  delay(turnDuration); // Turn for the specified duration
  motors.brake(); // Stop the motors
  delay(500); // Pause before the next action
}