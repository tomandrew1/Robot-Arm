#include <Servo.h>

// Define var to store the state of the input pin
// This var will also be modified to become angle of rotation of servo
int angle;
// Define var to input angle of rotation from serial monitor
int angleInput;

// Create servo object to interact with servo
Servo myServo;

// Define the pin for PWM control
const int servoPin = 3;  // Pin 3 will be used for controlling the servo

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Set A0 as an input
  pinMode(A0, INPUT); // This is the potentiometer
  // Set led as output
  // pinMode(led, OUTPUT); // This was for testing potentiometer

  // Attach the Servo object to pin connected to servo
  myServo.attach(servoPin);
}

void loop() {
  // // Read the state of A0 (potentiometer) in form of int between 0-1023
  // angle = analogRead(A0);
  // // Divide potentiometer input to be in form of the servo angle input (0-180)
  // angle = angle / (5.683); 
  // // Move the servo to the angle calculated and print for testing
  // myServo.write(angle);
  // Serial.println(angle);


  // Check if data is available in the Serial buffer
  if (Serial.available() > 0) {
    // Read the integer from the Serial Monitor
    angleInput = Serial.parseInt();
    // Print the angle to screen and read for saving the value
    Serial.println(angleInput);
    Serial.read();
  }
  // Move the servo to the angle inputted
  myServo.write(angleInput);

  // Add a small delay to avoid flooding the serial monitor
  delay(100);
}
