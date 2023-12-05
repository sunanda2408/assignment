const int lm35Pin = A0; // LM35 sensor connected to analog pin A0
const int ledPin = 13;  // Onboard LED connected to digital pin 13

void setup() {
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600);       // Initialize serial communication at 9600 bps
}

void loop() {
  // Read the temperature from LM35 sensor
  int sensorValue = analogRead(lm35Pin);
  
  // Convert the sensor value to temperature in degrees Celsius
  float temperature = (sensorValue * 5.0 / 1023) * 100;

  // Print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Check temperature conditions and control the LED accordingly
  if (temperature < 30) {
    blinkLED(250);  // Blink every 250 milliseconds
  } else {
    blinkLED(500);  // Blink every 500 milliseconds
  }
}

// Function to make the LED blink at a given interval
void blinkLED(int interval) {
  digitalWrite(ledPin, HIGH); // Turn on the LED
  delay(interval);             // Wait for the specified interval
  digitalWrite(ledPin, LOW);  // Turn off the LED
  delay(interval);             // Wait for the specified interval
}
