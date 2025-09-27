/*
 * ESP32-C6 LED Blink Example
 * 
 * This example demonstrates basic GPIO control by blinking the built-in LED.
 * 
 * Hardware Requirements:
 * - ESP32-C6 1.47" Display Development Board
 * 
 * Connections:
 * - Built-in LED is connected to GPIO21
 * 
 * Author: ESP32-C6 Development Board Community
 * License: MIT
 */

#define LED_PIN 21      // Built-in LED pin
#define BLINK_DELAY 1000  // Blink interval in milliseconds

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Print welcome message
  Serial.println("ESP32-C6 LED Blink Example");
  Serial.println("LED will blink every " + String(BLINK_DELAY) + "ms");
  Serial.println("---");
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(BLINK_DELAY);
  
  // Turn the LED off
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(BLINK_DELAY);
}