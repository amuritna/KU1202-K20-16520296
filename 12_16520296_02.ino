#include <Servo.h>

Servo servo_0; // declare servo
const int servoPin = 7; // servo 0 pin
const int ledPin = 2; // LED pin
int pos = 0; // servo position (in degrees)

void setup() {
  pinMode(ledPin, OUTPUT); // ledPin as output
  servo_0.attach(servoPin); // attach servo
  servo_0.write(pos); // initialize servo
}

void loop() {
  digitalWrite(2, HIGH); // LED on
  for (pos = 0; pos <= 90; pos += 1) {
    servo_0.write(pos); // spin servo
    delay(15);
  }
  delay(2000);
  
  digitalWrite(2, LOW); // LED off
  for (pos = 90; pos >= 0; pos -= 1) {
    servo_0.write(pos); // spin servo
    delay(15);
  }
  
  delay(2000);
}
    
