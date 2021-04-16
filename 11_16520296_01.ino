const int pingPin = 7;					// pin Arduino -> baca output sensor

void setup() {
	Serial.begin(9600);						// mulai port serial
}

void loop() {
	long duration, cm; 						// inisialisasi variabel durasi dan jarak (cm)
		
	pinMode(pingPin, OUTPUT); 				// atur pin sebagai OUTPUT
	digitalWrite(pingPin, LOW); 			// beri sinyal awal LOW 
	delayMicroseconds(2);					// jeda 2 microsecond 
	digitalWrite(pingPin, HIGH);			// trigger sensor dengan sinyal HIGH 
	delayMicroseconds(5);					// trigger sensor selama 5 microsecond 
	digitalWrite(pingPin, LOW); 			// beri sinyal LOW 
	
	pinMode(pingPin, INPUT);				// atur pin sebagai INPUT
	duration = pulseIn(pingPin, HIGH);		// sinyal HIGH untuk dapat durasi dalam microsecond 
	cm = microsecondsToCentimeters(duration); // konversi microsecond ke cm 

  	// output
  	Serial.print(cm);
	Serial.print("cm");
	Serial.println();
	delay(100);
}

long microsecondsToCentimeters (long microseconds) { // definisikan fungsi yang mengonversi durasi menjadi jarak 
	// kecepatan suara: 350 m/s atau 29 microsecond/cm 
	// dibagi dua untuk mencari jarak sensor-objek 
	return microseconds / 29 / 2;
}
