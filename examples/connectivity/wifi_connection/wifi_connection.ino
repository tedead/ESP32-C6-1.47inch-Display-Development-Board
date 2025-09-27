/*
 * ESP32-C6 Wi-Fi Connection Example
 * 
 * This example demonstrates Wi-Fi connectivity and creates a simple web server
 * that displays board information and allows basic control.
 * 
 * Hardware Requirements:
 * - ESP32-C6 1.47" Display Development Board
 * - Wi-Fi network (2.4GHz)
 * 
 * Features:
 * - Connect to Wi-Fi network
 * - Display connection status on LCD
 * - Host a simple web server
 * - Control LED via web interface
 * 
 * Author: ESP32-C6 Development Board Community
 * License: MIT
 */

#include <WiFi.h>
#include <WebServer.h>
#include <SPI.h>
#include <TFT_eSPI.h>

// Wi-Fi credentials (replace with your network details)
const char* ssid = "YourWiFiNetwork";
const char* password = "YourWiFiPassword";

// Create objects
TFT_eSPI tft = TFT_eSPI();
WebServer server(80);

// Pin definitions
#define LED_PIN 21
#define BACKLIGHT_PIN 3

// Global variables
bool ledState = false;
unsigned long lastUpdate = 0;
int connectionAttempts = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("ESP32-C6 Wi-Fi Connection Example");
  
  // Initialize pins
  pinMode(LED_PIN, OUTPUT);
  pinMode(BACKLIGHT_PIN, OUTPUT);
  analogWrite(BACKLIGHT_PIN, 200);  // Set backlight brightness
  
  // Initialize display
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  
  displayStatus("Initializing...", TFT_YELLOW);
  
  // Start Wi-Fi connection
  connectToWiFi();
  
  // Setup web server routes
  setupWebServer();
  
  // Start the server
  server.begin();
  Serial.println("Web server started");
  
  displayConnectionInfo();
}

void loop() {
  // Handle web server requests
  server.handleClient();
  
  // Update display periodically
  if (millis() - lastUpdate > 5000) {
    updateDisplay();
    lastUpdate = millis();
  }
  
  // Blink LED to show activity
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(1900);
  }
}

void connectToWiFi() {
  displayStatus("Connecting to WiFi...", TFT_YELLOW);
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  connectionAttempts = 0;
  while (WiFi.status() != WL_CONNECTED && connectionAttempts < 20) {
    delay(1000);
    Serial.print(".");
    connectionAttempts++;
    
    // Update display with dots
    tft.fillRect(0, 100, tft.width(), 30, TFT_BLACK);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(10, 110);
    tft.print("Attempts: ");
    tft.print(connectionAttempts);
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    displayStatus("WiFi Connected!", TFT_GREEN);
  } else {
    Serial.println("");
    Serial.println("WiFi connection failed!");
    displayStatus("WiFi Failed!", TFT_RED);
  }
}

void setupWebServer() {
  // Root page
  server.on("/", handleRoot);
  
  // LED control endpoints
  server.on("/led/on", handleLEDOn);
  server.on("/led/off", handleLEDOff);
  server.on("/led/toggle", handleLEDToggle);
  
  // Status page
  server.on("/status", handleStatus);
  
  // Handle not found
  server.onNotFound(handleNotFound);
}

void handleRoot() {
  String html = "<!DOCTYPE html><html>";
  html += "<head><title>ESP32-C6 Control Panel</title></head>";
  html += "<body style='font-family: Arial; margin: 40px;'>";
  html += "<h1>ESP32-C6 Development Board</h1>";
  html += "<h2>Control Panel</h2>";
  
  html += "<div style='background: #f0f0f0; padding: 20px; border-radius: 10px; margin: 20px 0;'>";
  html += "<h3>Board Information</h3>";
  html += "<p><strong>Chip Model:</strong> " + String(ESP.getChipModel()) + "</p>";
  html += "<p><strong>Free Heap:</strong> " + String(ESP.getFreeHeap()) + " bytes</p>";
  html += "<p><strong>Wi-Fi RSSI:</strong> " + String(WiFi.RSSI()) + " dBm</p>";
  html += "<p><strong>IP Address:</strong> " + WiFi.localIP().toString() + "</p>";
  html += "</div>";
  
  html += "<div style='background: #e8f4f8; padding: 20px; border-radius: 10px; margin: 20px 0;'>";
  html += "<h3>LED Control</h3>";
  html += "<p>Current LED State: <strong>" + String(ledState ? "ON" : "OFF") + "</strong></p>";
  html += "<button onclick=\"location.href='/led/on'\" style='background: #4CAF50; color: white; padding: 10px 20px; margin: 5px; border: none; border-radius: 5px; cursor: pointer;'>LED ON</button>";
  html += "<button onclick=\"location.href='/led/off'\" style='background: #f44336; color: white; padding: 10px 20px; margin: 5px; border: none; border-radius: 5px; cursor: pointer;'>LED OFF</button>";
  html += "<button onclick=\"location.href='/led/toggle'\" style='background: #2196F3; color: white; padding: 10px 20px; margin: 5px; border: none; border-radius: 5px; cursor: pointer;'>TOGGLE</button>";
  html += "</div>";
  
  html += "<p><a href='/status'>View JSON Status</a></p>";
  html += "<p style='color: #666; font-size: 12px;'>ESP32-C6 Development Board - Web Interface</p>";
  html += "</body></html>";
  
  server.send(200, "text/html", html);
}

void handleLEDOn() {
  ledState = true;
  digitalWrite(LED_PIN, HIGH);
  updateDisplay();
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLEDOff() {
  ledState = false;
  digitalWrite(LED_PIN, LOW);
  updateDisplay();
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLEDToggle() {
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
  updateDisplay();
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleStatus() {
  String json = "{";
  json += "\"chipModel\":\"" + String(ESP.getChipModel()) + "\",";
  json += "\"freeHeap\":" + String(ESP.getFreeHeap()) + ",";
  json += "\"wifiRSSI\":" + String(WiFi.RSSI()) + ",";
  json += "\"ipAddress\":\"" + WiFi.localIP().toString() + "\",";
  json += "\"ledState\":" + String(ledState ? "true" : "false") + ",";
  json += "\"uptime\":" + String(millis()) + "";
  json += "}";
  
  server.send(200, "application/json", json);
}

void handleNotFound() {
  server.send(404, "text/plain", "Not Found");
}

void displayStatus(String message, uint16_t color) {
  tft.fillRect(0, 0, tft.width(), 80, TFT_BLACK);
  tft.setTextColor(color);
  tft.setTextSize(2);
  tft.setCursor(10, 30);
  tft.println(message);
}

void displayConnectionInfo() {
  tft.fillScreen(TFT_BLACK);
  
  // Title
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("ESP32-C6 WiFi");
  
  if (WiFi.status() == WL_CONNECTED) {
    // Connection details
    tft.setTextColor(TFT_GREEN);
    tft.setTextSize(1);
    tft.setCursor(10, 40);
    tft.println("Connected to: " + String(ssid));
    
    tft.setCursor(10, 55);
    tft.println("IP: " + WiFi.localIP().toString());
    
    tft.setCursor(10, 70);
    tft.println("RSSI: " + String(WiFi.RSSI()) + " dBm");
    
    // Web server info
    tft.setTextColor(TFT_CYAN);
    tft.setCursor(10, 90);
    tft.println("Web Server: Running");
    tft.setCursor(10, 105);
    tft.println("Access: http://" + WiFi.localIP().toString());
    
  } else {
    tft.setTextColor(TFT_RED);
    tft.setTextSize(1);
    tft.setCursor(10, 40);
    tft.println("WiFi: Disconnected");
  }
  
  updateDisplay();
}

void updateDisplay() {
  // Update LED status
  tft.fillRect(0, 130, tft.width(), 40, TFT_BLACK);
  tft.setTextColor(ledState ? TFT_GREEN : TFT_RED);
  tft.setTextSize(1);
  tft.setCursor(10, 140);
  tft.println("LED Status: " + String(ledState ? "ON" : "OFF"));
  
  // Update uptime
  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(10, 155);
  tft.println("Uptime: " + String(millis() / 1000) + "s");
}