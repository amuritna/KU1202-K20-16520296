// pin yang terhubung ke NPN Transistor
int npnPin = 7;
// pin yang terhubung ke buzzer
const int buzzPin = 8;

void setup() {
  pinMode(npnPin, OUTPUT); // sebagai output dari pin NPN
  pinMode(buzzPin, OUTPUT); // sebagai output dari pin buzzer
  Serial.begin(9600); // mulai port serial
}

void loop() {
  // nada f=523Hz, durasi=500ms
  tone(buzzPin, 523, 500);
  Serial.println("Start");
  // motor menyala
  digitalWrite(npnPin, HIGH);
  delay(5000);
  // motor mati
  Serial.println("Stop");
  digitalWrite(npnPin, LOW);
  delay(5000);
}
