#include <Servo.h>

Servo servo_0; // declare servo
const int servoPin = 7; // servo pin
// LED pins (R, G, B respectively)
const int ledR_Pin = 2;
const int ledB_Pin = 3;
const int ledG_Pin = 4;
const int buzzPin = 8;
int pos = 0; // servo position

void setup() {
  // set pins as output
  pinMode(ledR_Pin, OUTPUT);
  pinMode(ledB_Pin, OUTPUT);
  pinMode(ledG_Pin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  // attach servo and initialize
  servo_0.attach(servoPin);
  servo_0.write(pos);
}

void loop() {
  tone(buzzPin, 523, 500); // tone, f=523Hz, duration = 500ms
  // green
  digitalWrite(4, HIGH);
  for (pos = 0; pos <= 90; pos += 1) {
    servo_0.write(pos);
    delay(15);
  }
  delay(2000);
  
  // red
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  for (pos = 90; pos >= 0; pos -= 1) {
    servo_0.write(pos);
    delay(15);
  }
  
  // yellow
  digitalWrite(4, HIGH);
  delay(2000);
  digitalWrite(2, LOW);
}
