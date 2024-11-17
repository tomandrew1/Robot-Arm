#include <Servo.h>

// Define the variable to store the state of the input pin
int angle;
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


void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Attach the Servo object to pin 3,5
  myServoA.attach(servoPinA);
  myServoB.attach(servoPinB);

}

void loop() {
  // Check if data is available in the Serial buffer
  if (Serial.available() > 0) {
    // Read the string from the Serial Monitor
    servoType = (char)Serial.read();
    // Read angle from Serial
    angle = Serial.parseInt();

    // For debugging
    Serial.println(servoType);
    Serial.println(angle);
    Serial.read();
  }
  if (angle >= 0 && angle <= 180){
    // If A inputted write to A
    if (servoType == 'A') {
      myServoA.write(angle);
    }
    // If B inputted write to B
    else if (servoType == 'B') {
      myServoB.write(angle);
    }
  }

  // Add a small delay to avoid flooding the serial monitor
  delay(100);
}