/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial/
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  
  for (int i=2; i<=11 ; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}
void ledcontrol(int i){
  for (int n=0;n<=i ; n++) {
    digitalWrite(n+2, HIGH);
  }
  for (int n=9;n>=i;n--) {
    digitalWrite(n+2, LOW);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  int ledBar = map(sensorValue, 0, 1023, 0, 10);
  ledcontrol(ledBar);
  Serial.println(sensorValue);
  delay(100);  // delay in between reads for stability
}
