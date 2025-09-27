# ESP32-C6 1.47inch Display Development Board

A comprehensive information repository for the ESP32-C6 1.47inch Display Development Board - a powerful IoT development platform featuring Wi-Fi 6, Bluetooth 5 (LE), and a vibrant 1.47-inch color display.

![ESP32-C6 Board](https://img.shields.io/badge/ESP32--C6-Development%20Board-blue)
![Display](https://img.shields.io/badge/Display-1.47%20inch%20TFT-green)
![License](https://img.shields.io/github/license/tedead/ESP32-C6-1.47inch-Display-Development-Board)

## 📋 Table of Contents

- [Board Overview](#-board-overview)
- [Key Features](#-key-features)
- [Hardware Specifications](#-hardware-specifications)
- [Pin Mapping](#-pin-mapping)
- [Display Information](#-display-information)
- [Getting Started](#-getting-started)
- [Development Environment](#-development-environment)
- [Programming Examples](#-programming-examples)
- [Troubleshooting](#-troubleshooting)
- [Resources](#-resources)

## 🔍 Board Overview

The ESP32-C6 1.47inch Display Development Board combines the powerful ESP32-C6 microcontroller with a high-quality 1.47-inch TFT display, making it ideal for IoT projects that require both processing power and visual feedback.

### What makes this board special:
- **Latest ESP32-C6 chip** with RISC-V architecture
- **Built-in 1.47" TFT display** for immediate visual feedback
- **Wi-Fi 6 (802.11ax)** support for modern connectivity
- **Bluetooth 5 (LE)** for low-energy applications
- **Compact form factor** perfect for prototyping

## ⭐ Key Features

### Microcontroller (ESP32-C6)
- **CPU**: 32-bit RISC-V single-core processor, up to 160 MHz
- **Memory**: 512 KB SRAM, 4 MB Flash (expandable)
- **Wireless**: 
  - Wi-Fi 6 (802.11ax) 2.4 GHz
  - Bluetooth 5 (LE) with Bluetooth mesh support
- **Security**: Hardware-based security features, secure boot, flash encryption
- **Low Power**: Multiple power modes for battery-powered applications

### Display
- **Size**: 1.47 inches diagonal
- **Resolution**: 320x172 pixels
- **Interface**: SPI
- **Colors**: 65K colors (16-bit)
- **Driver**: ST7789V or similar
- **Viewing angle**: Wide viewing angle

### Connectivity & I/O
- **GPIO pins**: Multiple digital I/O pins
- **ADC**: 12-bit ADC channels
- **PWM**: Multiple PWM channels
- **Interfaces**: SPI, I2C, UART
- **USB**: USB-C for programming and power

## 🔧 Hardware Specifications

| Component | Specification |
|-----------|---------------|
| **Microcontroller** | ESP32-C6 (RISC-V, 160MHz) |
| **Flash Memory** | 4MB (typical) |
| **SRAM** | 512KB |
| **Display** | 1.47" TFT LCD, 320x172px |
| **Display Interface** | SPI |
| **Wireless** | Wi-Fi 6 (2.4GHz) + Bluetooth 5 LE |
| **USB** | USB-C connector |
| **Power Supply** | 3.3V/5V via USB-C |
| **Operating Voltage** | 3.3V |
| **Dimensions** | TBD (board-specific) |
| **Temperature Range** | -40°C to +85°C |

## 📌 Pin Mapping

### Display Connections (Internal)
| Display Pin | ESP32-C6 GPIO | Function |
|-------------|---------------|----------|
| SCL | GPIO6 | SPI Clock |
| SDA | GPIO7 | SPI Data |
| RES | GPIO10 | Reset |
| DC | GPIO11 | Data/Command |
| CS | GPIO20 | Chip Select |
| BLK | GPIO15 | Backlight |

### Available GPIO Pins
| Pin | GPIO | Function | Notes |
|-----|------|----------|-------|
| 1 | GPIO0 | Digital I/O | Boot button |
| 2 | GPIO1 | Digital I/O/ADC | |
| 3 | GPIO2 | Digital I/O/ADC | |
| 4 | GPIO3 | Digital I/O/ADC | |
| 5 | GPIO4 | Digital I/O/ADC | |
| 6 | GPIO5 | Digital I/O/ADC | |
| ... | ... | ... | More pins available |

> **Note**: Exact pin mapping may vary by board revision. Consult your board's documentation for precise details.

## 📺 Display Information

### Display Specifications
- **Controller**: ST7789V (or compatible)
- **Resolution**: 320 x 172 pixels
- **Color Depth**: 16-bit (65,536 colors)
- **Interface**: 4-wire SPI
- **Backlight**: LED backlight with PWM control
- **Viewing Angle**: 70°/70°/70°/70° (Up/Down/Left/Right)

### Display Libraries
Popular libraries for driving the display:
- **TFT_eSPI** - Arduino library with ESP32-C6 support
- **LovyanGFX** - High-performance graphics library
- **Adafruit GFX** - With ST7789 driver
- **ESP-IDF components** - For native ESP-IDF development

## 🚀 Getting Started

### Prerequisites
- ESP32-C6 1.47inch Display Development Board
- USB-C cable
- Computer with Arduino IDE or ESP-IDF installed

### Quick Start Steps

1. **Install Development Environment**
   ```bash
   # For Arduino IDE
   # Install ESP32 board package v3.0.0 or later
   # Board: "ESP32C6 Dev Module"
   
   # For ESP-IDF
   git clone --recursive https://github.com/espressif/esp-idf.git
   cd esp-idf
   ./install.sh esp32c6
   ```

2. **Connect the Board**
   - Connect USB-C cable to your board and computer
   - Board should appear as a serial device

3. **First Program - Display Test**
   ```cpp
   #include <TFT_eSPI.h>
   
   TFT_eSPI tft = TFT_eSPI();
   
   void setup() {
     tft.init();
     tft.setRotation(1);
     tft.fillScreen(TFT_BLACK);
     tft.setTextColor(TFT_WHITE);
     tft.setTextSize(2);
     tft.drawString("Hello ESP32-C6!", 10, 10);
   }
   
   void loop() {
     // Your code here
   }
   ```

## 🛠 Development Environment

### Arduino IDE Setup

1. **Install Arduino IDE** (version 2.0+)
2. **Add ESP32 Board Package**:
   - File → Preferences
   - Add to Additional Board Manager URLs:
     ```
     https://espressif.github.io/arduino-esp32/package_esp32_index.json
     ```
3. **Install ESP32 Package**:
   - Tools → Board → Boards Manager
   - Search "ESP32" and install version 3.0.0+
4. **Select Board**:
   - Tools → Board → ESP32 Arduino → ESP32C6 Dev Module

### Required Libraries
```bash
# Essential libraries for display
TFT_eSPI by Bodmer
Adafruit GFX Library
WiFi (built-in)
BluetoothSerial (built-in)
```

### ESP-IDF Setup
```bash
# Clone ESP-IDF
git clone --recursive https://github.com/espressif/esp-idf.git
cd esp-idf

# Install for ESP32-C6
./install.sh esp32c6

# Setup environment
. ./export.sh

# Create new project
idf.py create-project my_project
```

## 💻 Programming Examples

### Example 1: Basic Display Test
```cpp
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  
  tft.init();
  tft.setRotation(1); // Landscape
  tft.fillScreen(TFT_BLACK);
  
  // Draw some text
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("ESP32-C6", 10, 10);
  
  // Draw a rectangle
  tft.drawRect(10, 40, 100, 60, TFT_BLUE);
  
  // Draw a filled circle
  tft.fillCircle(200, 80, 30, TFT_RED);
}

void loop() {
  // Update display or handle other tasks
  delay(1000);
}
```

### Example 2: Wi-Fi Connection with Display
```cpp
#include <WiFi.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

const char* ssid = "your_wifi_name";
const char* password = "your_wifi_password";

void setup() {
  Serial.begin(115200);
  
  // Initialize display
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(1);
  
  // Connect to WiFi
  tft.drawString("Connecting to WiFi...", 10, 10);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    tft.drawString(".", tft.getCursorX(), tft.getCursorY());
  }
  
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0);
  tft.println("WiFi Connected!");
  tft.println("IP: " + WiFi.localIP().toString());
}

void loop() {
  // Your main code here
}
```

### Example 3: Sensor Data Visualization
```cpp
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}

void loop() {
  // Simulate sensor reading
  float temperature = 20.0 + (random(0, 100) / 10.0);
  
  // Clear previous reading
  tft.fillRect(0, 0, 320, 50, TFT_BLACK);
  
  // Display temperature
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(3);
  tft.setCursor(10, 10);
  tft.print("Temp: ");
  tft.print(temperature, 1);
  tft.print("C");
  
  // Visual thermometer
  int barHeight = map(temperature * 10, 200, 300, 0, 100);
  tft.fillRect(250, 120, 30, 100, TFT_BLACK); // Clear old bar
  tft.drawRect(250, 20, 30, 100, TFT_WHITE);  // Border
  tft.fillRect(251, 120 - barHeight, 28, barHeight, TFT_RED); // Fill
  
  delay(2000);
}
```

## 🐛 Troubleshooting

### Common Issues and Solutions

#### Board Not Detected
**Problem**: Computer doesn't recognize the board
**Solutions**:
- Check USB-C cable (ensure it supports data transfer)
- Install CH340/CP2102 drivers if needed
- Try a different USB port
- Press and hold BOOT button while connecting

#### Display Not Working
**Problem**: Display remains blank or shows garbage
**Solutions**:
- Check TFT_eSPI library configuration
- Verify pin definitions match your board
- Ensure proper power supply (3.3V)
- Check SPI connections

#### Compilation Errors
**Problem**: Code won't compile
**Solutions**:
- Update ESP32 board package to latest version (3.0.0+)
- Install required libraries
- Select correct board: "ESP32C6 Dev Module"
- Check for typos in pin definitions

#### Wi-Fi Connection Issues
**Problem**: Can't connect to Wi-Fi
**Solutions**:
- Verify SSID and password
- Check 2.4GHz network (ESP32-C6 doesn't support 5GHz)
- Ensure network allows new devices
- Try connecting to mobile hotspot for testing

#### Upload Issues
**Problem**: Can't upload code to board
**Solutions**:
- Press and hold BOOT button during upload
- Check serial port selection
- Reduce upload speed in Arduino IDE
- Try different USB cable or port

### Debug Tools
```cpp
// Enable debug output
#define DEBUG_ESP_WIFI
#define DEBUG_ESP_HTTP_CLIENT

// Serial debugging
Serial.begin(115200);
Serial.println("Debug message");

// Display debugging
tft.println("Status: " + String(value));
```

## 📚 Resources

### Official Documentation
- [ESP32-C6 Technical Reference Manual](https://www.espressif.com/sites/default/files/documentation/esp32-c6_technical_reference_manual_en.pdf)
- [ESP32-C6 Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf)
- [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c6/)

### Libraries and Tools
- [TFT_eSPI Library](https://github.com/Bodmer/TFT_eSPI) - Display graphics library
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32) - Arduino support
- [PlatformIO](https://platformio.org/) - Alternative IDE

### Community and Support
- [ESP32 Forum](https://www.esp32.com/) - Official Espressif forum
- [Arduino ESP32 Community](https://github.com/espressif/arduino-esp32/discussions)
- [Reddit r/esp32](https://www.reddit.com/r/esp32/) - Community discussions

### Example Projects
- IoT Weather Station with Display
- Home Automation Controller
- Data Logger with Visualization
- Bluetooth/Wi-Fi Bridge Applications

---

## 📄 License

This repository is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit issues, feature requests, or pull requests to improve this information repository.

---

*This repository serves as a comprehensive information hub for the ESP32-C6 1.47inch Display Development Board. For hardware purchases, consult your preferred electronics supplier.*
