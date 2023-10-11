/////////////////////////////////
// Ultrasonic Sensor Code
//
// This program uses the HC-SR04 library
// and allows distance data to be read from
// the ultrasonic sensor.
// This code also introduces if/else
// statements to control LEDs based
// on distance data.
/////////////////////////////////

#include "SR04.h"  // Ultrasonic Sensor Library

int TRIG_PIN = 12; // Trigger pin on sensor
int ECHO_PIN = 11; // Echo pin on sensor
int LED1_PIN = 13;	// Pin for LED

SR04 ultrasonic_sensor1 = SR04(ECHO_PIN, TRIG_PIN);   // Ultrasonic Sensor Object, this is the sensor that you will control
long distance; // Variable for storing distance data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Starts the serial connection at 9600 baud rate
  delay(1000); // Give the program some time to setup
  pinMode(LED1_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  
  // Save distance value from ultrasonic sensor into distance variable
  distance = ultrasonic_sensor1.Distance();

  //  Print distance values from sensor into the serial console to read
  Serial.print(distance);
  Serial.println("cm");	// println prints on a new line to make things more readable
  delay(1000);	// Slow down the program to be able to read the results
  
  // Use if/else statements to turn on/off LED based on distance values
  if (distance > 50) {
	digitalWrite(LED1_PIN, HIGH);	// Turn on LED if distance is greater than 50
  }
  else {
	digitalWrite(LED1_PIN, LOW); // Turn off LED if distance is not greater than 50
  }
}


// Below is an example of turning on 3 LEDs based on different distances
// if (distance < 50) {
//		digitalWrite(LED1_PIN, HIGH);
//		digitalWrite(LED2_PIN, LOW);
//		digitalWrite(LED3_PIN, LOW);
// else if (distance >= 50 && distance < 100) {
//		digitalWrite(LED1_PIN, LOW);
//		digitalWrite(LED2_PIN, HIGH);
//		digitalWrite(LED3_PIN, LOW);
//}
// else if (distance >= 100) {
//		digitalWrite(LED1_PIN, LOW);
//		digitalWrite(LED2_PIN, LOW);
//		digitalWrite(LED3_PIN, HIGH);
//}
// else {
//		digitalWrite(LED1_PIN, LOW);
//		digitalWrite(LED2_PIN, LOW);
//		digitalWrite(LED3_PIN, LOW);
// }




