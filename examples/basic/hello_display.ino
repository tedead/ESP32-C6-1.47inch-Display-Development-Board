/*
 * Hello Display Example
 * ESP32-C6 1.47inch Display Development Board
 * 
 * This example demonstrates basic display initialization
 * and text output functionality.
 * 
 * Required Libraries:
 * - TFT_eSPI
 * 
 * Board: ESP32C6 Dev Module
 */

#include <TFT_eSPI.h>

// Create display object
TFT_eSPI tft = TFT_eSPI();

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("ESP32-C6 Display Example Starting...");
  
  // Initialize the display
  tft.init();
  tft.setRotation(1); // Landscape orientation (0-3)
  tft.fillScreen(TFT_BLACK);
  
  // Display basic text
  displayWelcomeScreen();
  
  Serial.println("Display initialized successfully!");
}

void loop() {
  // Show dynamic content
  showTime();
  delay(1000);
}

void displayWelcomeScreen() {
  // Clear screen
  tft.fillScreen(TFT_BLACK);
  
  // Title
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("ESP32-C6", 10, 10);
  
  // Subtitle
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  tft.drawString("1.47\" Display Board", 10, 35);
  
  // Features list
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.drawString("Features:", 10, 60);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.drawString("- Wi-Fi 6 (802.11ax)", 20, 75);
  tft.drawString("- Bluetooth 5 LE", 20, 90);
  tft.drawString("- RISC-V Processor", 20, 105);
  tft.drawString("- 320x172 Display", 20, 120);
  
  // Draw some graphics
  tft.drawRect(200, 60, 100, 80, TFT_BLUE);
  tft.fillCircle(250, 100, 20, TFT_RED);
  tft.drawLine(200, 60, 300, 140, TFT_WHITE);
  
  delay(3000);
}

void showTime() {
  static unsigned long lastUpdate = 0;
  static int seconds = 0;
  
  if (millis() - lastUpdate > 1000) {
    // Clear time area
    tft.fillRect(10, 150, 200, 20, TFT_BLACK);
    
    // Display uptime
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(1);
    tft.drawString("Uptime: " + String(seconds) + " seconds", 10, 150);
    
    seconds++;
    lastUpdate = millis();
  }
}