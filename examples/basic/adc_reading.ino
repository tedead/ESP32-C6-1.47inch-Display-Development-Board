/*
 * ADC Reading Example
 * ESP32-C6 1.47inch Display Development Board
 * 
 * Reads analog values from GPIO pins and displays them on screen.
 * Useful for sensor readings, battery monitoring, etc.
 * 
 * Required Libraries:
 * - TFT_eSPI
 * 
 * Board: ESP32C6 Dev Module
 * 
 * Connections:
 * - Connect analog sensor or potentiometer to GPIO0 (ADC1_0)
 * - Connect another sensor to GPIO1 (ADC1_1) - optional
 */

#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

// ADC pins (using first two ADC channels)
const int ADC_PIN_1 = 0; // GPIO0 = ADC1_0
const int ADC_PIN_2 = 1; // GPIO1 = ADC1_1

void setup() {
  Serial.begin(115200);
  
  // Initialize display
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  
  // Display title
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("ADC Monitor", 10, 10);
  
  // Setup ADC
  analogReadResolution(12); // 12-bit resolution (0-4095)
  
  Serial.println("ADC Monitor Started");
  Serial.println("Connect sensors to GPIO0 and GPIO1");
}

void loop() {
  // Read ADC values
  int adc1_raw = analogRead(ADC_PIN_1);
  int adc2_raw = analogRead(ADC_PIN_2);
  
  // Convert to voltage (3.3V reference)
  float voltage1 = adc1_raw * (3.3 / 4095.0);
  float voltage2 = adc2_raw * (3.3 / 4095.0);
  
  // Calculate percentages
  float percent1 = (adc1_raw / 4095.0) * 100;
  float percent2 = (adc2_raw / 4095.0) * 100;
  
  // Display readings
  displayReadings(adc1_raw, adc2_raw, voltage1, voltage2, percent1, percent2);
  
  // Serial output for debugging
  Serial.printf("ADC1: %d (%.2fV, %.1f%%) | ADC2: %d (%.2fV, %.1f%%)\n", 
                adc1_raw, voltage1, percent1, adc2_raw, voltage2, percent2);
  
  delay(500); // Update every 500ms
}

void displayReadings(int raw1, int raw2, float volt1, float volt2, float pct1, float pct2) {
  // Clear previous readings
  tft.fillRect(0, 40, 320, 132, TFT_BLACK);
  
  // Channel 1 (GPIO0)
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(1);
  tft.drawString("Channel 1 (GPIO0):", 10, 50);
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString(String(raw1), 10, 65);
  
  tft.setTextSize(1);
  tft.drawString("(" + String(volt1, 2) + "V, " + String(pct1, 1) + "%)", 80, 70);
  
  // Visual bar for Channel 1
  drawProgressBar(10, 85, 200, 15, pct1, TFT_GREEN);
  
  // Channel 2 (GPIO1)
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.setTextSize(1);
  tft.drawString("Channel 2 (GPIO1):", 10, 110);
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString(String(raw2), 10, 125);
  
  tft.setTextSize(1);
  tft.drawString("(" + String(volt2, 2) + "V, " + String(pct2, 1) + "%)", 80, 130);
  
  // Visual bar for Channel 2
  drawProgressBar(10, 145, 200, 15, pct2, TFT_YELLOW);
}

void drawProgressBar(int x, int y, int width, int height, float percentage, uint16_t color) {
  // Draw border
  tft.drawRect(x, y, width, height, TFT_WHITE);
  
  // Clear inside
  tft.fillRect(x + 1, y + 1, width - 2, height - 2, TFT_BLACK);
  
  // Draw filled portion
  int fillWidth = (width - 2) * (percentage / 100.0);
  if (fillWidth > 0) {
    tft.fillRect(x + 1, y + 1, fillWidth, height - 2, color);
  }
  
  // Add percentage text
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  String pctText = String(percentage, 1) + "%";
  tft.drawString(pctText, x + width + 5, y + 3);
}