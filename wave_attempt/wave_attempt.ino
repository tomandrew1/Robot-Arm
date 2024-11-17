#include <Servo.h>

// Define the variable to store the state of the angle
int angleA;
int angleB;
// Define pin for led for lightshow!!
int led = 9;

// Create the servo objects for A and B
Servo myServoA;
Servo myServoB;

// Define servoType to control each individually
char servoType;

// Define the pin for PWM control
const int servoPinA = 3;  // Pin 3 will be used for controlling the servo A
const int servoPinB = 5;  // Pin 5 will be used for controlling the servo B

// Increment amount
int rotateAmount = 1;


void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Attach the Servo object to pin 3,5
  myServoA.attach(servoPinA);
  myServoB.attach(servoPinB);

  // Callibration for SteadyB()
  angleA = 0;
  angleB = 180;
  myServoA.write(angleA);
  myServoB.write(angleB);
  delay(2000);


  // Wave();
  // Line();
}

void loop() {

  SteadyB();

  // Add a small delay to avoid flooding the serial monitor
  delay(100);
}

void SteadyB(){
  // Write to A and B 
  if (angleA >= 0 && angleA <= 180){
    myServoA.write(angleA);
  }
  if (angleB >= 0 && angleB <= 180){
    myServoB.write(angleB);
  }
  // Increment A and set B
  angleA += rotateAmount;
  angleB = 180 - angleA;

  // Swap direction if end met
  if (angleA < 0 || angleA > 90) {
    rotateAmount = -rotateAmount;
  }
}

void Wave() {
  // Callibrate servos
  angleA = 0;
  angleB = 180;
  myServoA.write(angleA);
  myServoB.write(angleB);
  delay(2000);

  // Move arm up 
  while (angleA < 70 && angleB > 110){
    if (angleA < 70){
      myServoA.write(angleA);
      angleA += rotateAmount;
    }
    if (angleB > 110){
      myServoB.write(angleB);
      angleB -= rotateAmount;
    }
    delay(100);
  }
  // Wave forward
  while (angleB > 0){
    myServoB.write(angleB);
    angleB -= 4 * rotateAmount;
    delay(100);
  }
  // Wave backward
  while (angleB < 110){
    myServoB.write(angleB);
    angleB += 4 * rotateAmount;
    delay(100);
  }
  // Move arm down
  while (angleA > 0 && angleB < 180){
    if (angleA > 0){
      myServoA.write(angleA);
      angleA -= rotateAmount;
    }
    if (angleB < 180){
      myServoB.write(angleB);
      angleB += rotateAmount;
    }
    delay(100);
  }
}

void Line(){
  // Callibrate Servos
  angleA = 0;
  angleB = 90;
  myServoA.write(angleA);
  myServoB.write(angleB);
  delay(2000);

  // Increment until angleA 90
  while (angleA < 90){
    if (angleA >= 0 && angleA <= 180){
      myServoA.write(angleA);
    }
    if (angleB >= 0 && angleB <= 180){
      myServoB.write(angleB);
    }
    angleA += rotateAmount;
    angleB = 180 - angleA - (asin(1-sin(PI*angleA / 180)) * (180/PI));

    // Printing for debugging
    Serial.println("A");
    Serial.println(angleA);
    Serial.println("B");
    Serial.println(angleB);
    delay(100);
  }
}