//ROBOT NAVIGATION
//STUDENT: Austin Frasier
//Due Date: 3/21/2019
//This sketch is a required assignment for ENSC 1411 at HBU

//DESCRIPTION: This sketch provides code in the Arduino IDE langue to allow an Arduino-based
//servo-driven mobile robot to navigate a series of seven Cybersecurity Threats, achieved by pushing Husky
//objects around a field comprised of the HBU campus and various waypoints.

//ORANIZATION: This sketch is comprised of the following sections:
//1. Setup: includes required servo library, assigns motors, and begins serial monitor.
//2. Loop: main routine that performs the seven missions in order
//3. Mission library: top-level navigation commands, includes pauses for re-alignment
//4. Navigation commands: library of low-level navigation commands

//REVISION HISTORY
// 3/7/2019 Initial creation of code
// 3/11/2019 Setup of DDOS and PhishingAttack libraries
// 3/19/2019 Worked on remaining mission Libraries
// 3/21/2019 Finished commenting 

//*****************
// 1. SETUP
//*****************

#include <Servo.h> //include required servo library

Servo servoL;  //define left servo as servoL
Servo servoR; //define Right servo as servoR


void setup(){
  Serial.begin(9600); //begin serial monitor at 9600 baud rate
  servoL.attach(12); //attach servoL to Analog Pin 12 for servo control
  servoR.attach(11); //attach ServoR to Analog pin 11 for servo control
}

//**************
//2. LOOP -- main program loop
//**************

void loop(){  
    DDos();  // Runs DDos library
    PhishingAttack();  // Runs PhishingAttack library
    NetworkIntrusion(); // Runs NetworkIntrusion library
    RansomwareAttack(); // Runs RansomwareAttack Library
    BotnetInfection(); // Runs BotnetInfection Library
    SpywareInfection(); // Runs SpywareInfection library
    //IdentityTheft(); // Runs IdentityTheft library

    exit(0);
}

//****************
//3. MISSION LIBRARY
//****************

// Delays tell you how long the function called is ran for in milliseconds

// 3.1 individual navigation commands for distributed denial of service mission

  void DDos()
  {
  forward();
  delay(1800); 
  left_turn();
  delay(270); 
  forward();
  delay(800); 
  left_turn();
  delay(1050); 
  forward();
  delay(475); 
  }
// 3.2 individual navigation commands for PhishingAttack Mission
  void PhishingAttack()
  {
  backward();
  delay(600); 
  right_turn();
  delay(650); 
  forward();
  delay(1000); 
  left_turn();
  delay(450); 
  forward();
  delay(800); 
  left_turn();
  delay(700); 
  forward();
  delay(250);
  left_turn();
  delay(850);
  forward();
  delay(1600);
  right_turn();
  delay(850);
  forward();
  delay(1700);
  right_turn();
  delay(500);
  forward();
  delay(1700);
  off();
  delay(5000);
  }
// 3.3 individual navigation commands for NetworkIntrusion Mission
  void NetworkIntrusion()
  {
  forward();
  delay(1450);
  }
// 3.4 individual navigation commands for RansomwareAttack Mission
  void RansomwareAttack()
  {
  backward();
  delay(600);
  right_turn();
  delay(1200);
  forward();
  delay(675);
  slow_right();
  delay(1500);
  forward();
  delay(900);
  off();
  delay(5000);
  }
// 3.5 individual navigation commands for BotnetInfection Mission
  void BotnetInfection()
  {
  
  }
// 3.6 individual navigation commands for SpywareInfection Mission
  void SpywareInfection()
  {
  forward();
  delay(1100);
  backward();
  delay(1200);
  }
// 3.7 indivdual navigation commands for IdentityTheft Mission
  void IdentityTheft()
  {
  
  }

//****************
// 4. NAVIGATION COMMANDS
//****************

void forward()  // moves robot forward at max speed
{
  servoL.writeMicroseconds(1700); // sets the left motor to turn a little less than max speed (this motor is stronger than the right one)
  servoR.writeMicroseconds(1000); // sets the right motor to turn a max speed
}

void backward()  // moves robot backwards at max speed
{
  servoL.writeMicroseconds(1200); // sets the left motor to turn at little less than max speed in opposite direction
  servoR.writeMicroseconds(2000); // set the right motor to turn at max speed in opposite direction
}

void right_turn() //makes robot rotate without moving in any direction to the right
{
  servoL.writeMicroseconds(2000); // sets left motor to max speed
  servoR.writeMicroseconds(1470); // sets right motor off
}

void left_turn() // rotates robot to the left
{
  servoL.writeMicroseconds(1470); //Left motor is off
  servoR.writeMicroseconds(1000); // Right motor is on at max speed
}

void off() // stops all movement
{
  servoL.writeMicroseconds(1470); //Left motor off
  servoR.writeMicroseconds(1470); //Right motor off
}

void slow_forward() //moves the robot forward at a slower pace
  {
  servoL.writeMicroseconds(1600); // Left motor is on only 100 microseconds above off
  servoR.writeMicroseconds(1350); // Right motor is on only 150 microseconds below off
  }
  
void slow_right() // tunrs the robot to the right in a wide angle
  {
  servoL.writeMicroseconds(1650); // Left motor is slightly stronger than right motor
  servoR.writeMicroseconds(1420); // right motor is on but not to fast 
  }
  
void slow_left() // turns the robot to the left in a wide angle
  {
  servoL.writeMicroseconds(1560); // Left motor is barely on
  servoR.writeMicroseconds(1380); // Right motor is stronger than the left motor 
  }
