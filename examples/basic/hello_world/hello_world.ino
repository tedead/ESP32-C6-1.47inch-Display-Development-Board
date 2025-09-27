/*
 * ESP32-C6 Hello World Display Example
 * 
 * This example demonstrates basic display functionality by showing text and graphics
 * on the 1.47-inch LCD display.
 * 
 * Hardware Requirements:
 * - ESP32-C6 1.47" Display Development Board
 * 
 * Display Connections:
 * - CS:  GPIO10
 * - DC:  GPIO2
 * - RST: GPIO1
 * - SDA: GPIO7
 * - SCL: GPIO6
 * - BLK: GPIO3
 * 
 * Author: ESP32-C6 Development Board Community
 * License: MIT
 */

#include <SPI.h>
#include <TFT_eSPI.h>

// Create display object
TFT_eSPI tft = TFT_eSPI();

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("ESP32-C6 Display Hello World Example");
  
  // Initialize the display
  tft.init();
  tft.setRotation(1);  // Landscape orientation
  
  // Clear screen with black background
  tft.fillScreen(TFT_BLACK);
  
  // Display hello world message
  displayHelloWorld();
  
  Serial.println("Display initialized and hello world displayed!");
}

void loop() {
  // Display a simple animation
  colorCycle();
  delay(2000);
}

void displayHelloWorld() {
  // Set text properties
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  
  // Display title
  tft.setCursor(20, 20);
  tft.println("ESP32-C6");
  
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.setCursor(20, 50);
  tft.println("Development Board");
  
  // Display hello world
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(50, 90);
  tft.println("Hello");
  tft.setCursor(50, 130);
  tft.println("World!");
  
  // Draw some decorative elements
  tft.drawRect(10, 10, tft.width() - 20, tft.height() - 20, TFT_WHITE);
  tft.fillCircle(30, tft.height() - 30, 8, TFT_RED);
  tft.fillCircle(tft.width() - 30, tft.height() - 30, 8, TFT_BLUE);
}

void colorCycle() {
  // Create a simple color cycling effect
  static uint16_t color = 0;
  
  // Draw gradient bars
  for (int i = 0; i < 10; i++) {
    uint16_t barColor = tft.color565(
      (color + i * 25) % 255,
      (color + i * 15) % 255,
      (color + i * 35) % 255
    );
    tft.fillRect(i * (tft.width() / 10), tft.height() - 40, 
                 tft.width() / 10, 30, barColor);
  }
  
  color += 10;
  if (color > 255) color = 0;
}