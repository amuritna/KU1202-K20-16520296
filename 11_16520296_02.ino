// inisialisasi
int sensePin = A0;						// pin -> baca output sensor 
int sensorInput;						// var -> simpan nilai output sensor 
double temp;							// var -> simpan nilai suhu (dalam derajat Celcius)

// setup
void setup() {
	Serial.begin(9600); 				// mulai port serial 
}

// ulangi
void loop() {
	sensorInput = analogRead(sensePin);		// baca sensor analog 

  	// konversi
  	temp = (double)sensorInput / 1024; 		// hitung persentase dari pembacaan input 
	temp *= 5;								// kalikan dengan 5V untuk mendapatkan nilai tegangan 
	temp -= 0.5; 							// dikurangi dengan offset 
	temp *= 100;							// konversi menjadi derajat Celcius 
	
  	// output
	Serial.print("Suhu: ");
	Serial.print(temp);
	Serial.println(" Celcius");
}
