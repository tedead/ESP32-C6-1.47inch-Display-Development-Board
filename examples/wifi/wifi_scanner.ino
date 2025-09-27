/*
 * Wi-Fi Scanner Example
 * ESP32-C6 1.47inch Display Development Board
 * 
 * Scans for available Wi-Fi networks and displays them on the screen.
 * Demonstrates Wi-Fi 6 capabilities of ESP32-C6.
 * 
 * Required Libraries:
 * - TFT_eSPI
 * - WiFi (built-in)
 * 
 * Board: ESP32C6 Dev Module
 */

#include <WiFi.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  
  // Initialize display
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  
  // Display title
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("Wi-Fi Scanner", 10, 10);
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);
  tft.drawString("Scanning networks...", 10, 35);
  
  // Set WiFi to station mode
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
  Serial.println("Wi-Fi Scanner Starting...");
}

void loop() {
  scanAndDisplayNetworks();
  delay(10000); // Wait 10 seconds before next scan
}

void scanAndDisplayNetworks() {
  // Clear previous results
  tft.fillRect(0, 50, 320, 122, TFT_BLACK);
  
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.setTextSize(1);
  tft.drawString("Scanning...", 10, 50);
  
  Serial.println("Starting Wi-Fi scan...");
  int n = WiFi.scanNetworks();
  
  // Clear scanning message
  tft.fillRect(0, 50, 320, 122, TFT_BLACK);
  
  if (n == 0) {
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.drawString("No networks found", 10, 50);
    Serial.println("No networks found");
  } else {
    Serial.printf("Found %d networks:\n", n);
    
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.drawString("Found " + String(n) + " networks:", 10, 50);
    
    // Display up to 8 networks
    int maxDisplay = min(n, 8);
    for (int i = 0; i < maxDisplay; i++) {
      String ssid = WiFi.SSID(i);
      int rssi = WiFi.RSSI(i);
      String encryption = getEncryptionType(WiFi.encryptionType(i));
      
      // Color based on signal strength
      uint16_t color = TFT_RED;
      if (rssi > -50) color = TFT_GREEN;
      else if (rssi > -70) color = TFT_YELLOW;
      
      // Display network info
      tft.setTextColor(color, TFT_BLACK);
      String networkInfo = ssid.substring(0, 15); // Truncate long names
      if (ssid.length() > 15) networkInfo += "...";
      networkInfo += " (" + String(rssi) + "dBm)";
      
      tft.drawString(networkInfo, 10, 70 + (i * 12));
      
      Serial.printf("%d: %s (%d dBm) %s\n", 
                    i + 1, ssid.c_str(), rssi, encryption.c_str());
    }
    
    if (n > 8) {
      tft.setTextColor(TFT_ORANGE, TFT_BLACK);
      tft.drawString("+" + String(n - 8) + " more...", 10, 166);
    }
  }
  
  // Show last scan time
  tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
  tft.drawString("Last scan: " + String(millis() / 1000) + "s", 180, 166);
}

String getEncryptionType(wifi_auth_mode_t encryptionType) {
  switch (encryptionType) {
    case WIFI_AUTH_OPEN:
      return "Open";
    case WIFI_AUTH_WEP:
      return "WEP";
    case WIFI_AUTH_WPA_PSK:
      return "WPA";
    case WIFI_AUTH_WPA2_PSK:
      return "WPA2";
    case WIFI_AUTH_WPA_WPA2_PSK:
      return "WPA/WPA2";
    case WIFI_AUTH_WPA2_ENTERPRISE:
      return "WPA2-EAP";
    case WIFI_AUTH_WPA3_PSK:
      return "WPA3";
    case WIFI_AUTH_WPA2_WPA3_PSK:
      return "WPA2/WPA3";
    default:
      return "Unknown";
  }
}