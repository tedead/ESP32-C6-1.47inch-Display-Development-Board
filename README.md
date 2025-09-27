# ESP32-C6 1.47" Display Development Board

A comprehensive development board featuring the ESP32-C6 microcontroller with an integrated 1.47-inch color display, perfect for IoT projects, embedded applications, and prototyping.

## 📋 Table of Contents

- [Features](#features)
- [Specifications](#specifications)
- [Hardware Overview](#hardware-overview)
- [Getting Started](#getting-started)
- [Pin Configuration](#pin-configuration)
- [Example Code](#example-code)
- [Troubleshooting](#troubleshooting)
- [Resources](#resources)
- [Contributing](#contributing)
- [License](#license)

## ✨ Features

- **ESP32-C6 SoC**: RISC-V single-core processor with Wi-Fi 6 and Bluetooth 5 support
- **1.47" Color Display**: High-resolution LCD display for visual feedback
- **Compact Design**: Small form factor ideal for embedded projects
- **Rich Connectivity**: Built-in Wi-Fi, Bluetooth, and GPIO pins
- **Development-Friendly**: Arduino IDE and ESP-IDF compatible
- **Low Power Consumption**: Optimized for battery-powered applications

## 📊 Specifications

### Microcontroller
- **SoC**: ESP32-C6
- **Architecture**: RISC-V single-core processor
- **Operating Frequency**: Up to 160 MHz
- **Flash Memory**: 4MB (typical)
- **RAM**: 512KB SRAM
- **Wi-Fi**: 802.11ax (Wi-Fi 6)
- **Bluetooth**: Bluetooth 5.0 LE
- **Operating Voltage**: 3.3V
- **Input Voltage**: 5V (via USB) or 3.3-5V (via VIN pin)

### Display
- **Size**: 1.47 inches
- **Type**: Color LCD
- **Resolution**: 172 x 320 pixels (typical)
- **Interface**: SPI
- **Colors**: 65K colors (16-bit)

### Physical
- **Dimensions**: TBD
- **Weight**: TBD
- **Operating Temperature**: -40°C to +85°C

## 🔧 Hardware Overview

### Key Components
1. **ESP32-C6 Module**: Main processing unit
2. **1.47" LCD Display**: Visual output interface
3. **USB-C Connector**: Programming and power
4. **GPIO Header Pins**: External connections
5. **Reset Button**: Hardware reset
6. **Boot Button**: Programming mode selection
7. **Power LED**: Status indicator
8. **User LED**: Programmable indicator

### Power Supply
The board can be powered through:
- USB-C connector (5V)
- VIN pin (3.3V - 5V)
- 3V3 pin (3.3V regulated)

## 🚀 Getting Started

### Prerequisites
- USB-C cable
- Computer with Windows, macOS, or Linux
- Arduino IDE 2.0+ or ESP-IDF development environment

### Installation Steps

#### Option 1: Arduino IDE
1. Install Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
2. Add ESP32 board package:
   - Go to `File > Preferences`
   - Add this URL to "Additional Board Manager URLs":
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Open `Tools > Board > Board Manager`
   - Search for "ESP32" and install the latest version
3. Select board: `Tools > Board > ESP32 Arduino > ESP32C6 Dev Module`

#### Option 2: ESP-IDF
1. Install ESP-IDF following the [official guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c6/get-started/)
2. Set up the development environment
3. Create a new project or use existing examples

### First Upload
1. Connect the board via USB-C cable
2. Hold the BOOT button while pressing RESET to enter programming mode
3. Select the correct COM port in your IDE
4. Upload a simple "Hello World" program

## 📌 Pin Configuration

### GPIO Pin Layout
```
                    ESP32-C6 Development Board
                           USB-C
                    [BOOT]     [RESET]
                    
    3V3  [ ]                           [ ]  GND
    EN   [ ]                           [ ]  GPIO21
    GPIO0[ ]                           [ ]  GPIO20  
    GPIO1[ ]                           [ ]  GPIO19
    GPIO2[ ]                           [ ]  GPIO18
    GPIO3[ ]                           [ ]  GPIO9
    GPIO4[ ]         1.47" LCD         [ ]  GPIO8
    GPIO5[ ]                           [ ]  GPIO7
    GPIO6[ ]                           [ ]  RX
    GND  [ ]                           [ ]  TX
    VIN  [ ]                           [ ]  GPIO10
```

### Display Connection
The 1.47" LCD display is connected via SPI:
- **CS (Chip Select)**: GPIO10
- **DC (Data/Command)**: GPIO2
- **RST (Reset)**: GPIO1
- **SDA (MOSI)**: GPIO7
- **SCL (SCLK)**: GPIO6
- **BLK (Backlight)**: GPIO3

### Special Pins
- **GPIO0**: Boot mode selection (pulled up, connect to GND for programming)
- **EN**: Reset pin (active low)
- **GPIO21**: Built-in LED
- **TX/RX**: Serial communication (GPIO16/GPIO17)

## 💻 Example Code

### Basic LED Blink
```cpp
#define LED_PIN 21

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
```

### Display Hello World
```cpp
#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  tft.drawString("Hello World!", 10, 10, 2);
}

void loop() {
  // Your main code here
}
```

### Wi-Fi Connection
```cpp
#include <WiFi.h>

const char* ssid = "your-wifi-name";
const char* password = "your-wifi-password";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your main code here
}
```

## 🔍 Troubleshooting

### Common Issues

#### Upload Errors
- **Problem**: "Failed to connect" or "No serial data received"
- **Solution**: 
  1. Hold BOOT button while pressing RESET
  2. Check USB cable and drivers
  3. Verify correct COM port selection
  4. Try different baud rate (115200 or 921600)

#### Display Not Working
- **Problem**: Blank or corrupted display
- **Solution**:
  1. Verify SPI pin connections
  2. Check display library configuration
  3. Ensure adequate power supply
  4. Try different display initialization settings

#### Wi-Fi Connection Issues
- **Problem**: Cannot connect to Wi-Fi
- **Solution**:
  1. Verify SSID and password
  2. Check Wi-Fi band (2.4GHz supported)
  3. Ensure router compatibility with Wi-Fi 6
  4. Check signal strength and range

#### Power Issues
- **Problem**: Board not powering on or unstable operation
- **Solution**:
  1. Use quality USB cable
  2. Check power supply capacity (minimum 500mA)
  3. Verify voltage levels on VIN and 3V3 pins
  4. Check for short circuits

### Debug Tips
1. Use Serial Monitor for debugging (115200 baud)
2. Add debug prints to track program flow
3. Check pin connections with multimeter
4. Use oscilloscope for SPI signal analysis
5. Monitor power consumption

## 📚 Resources

### Official Documentation
- [ESP32-C6 Technical Reference](https://www.espressif.com/sites/default/files/documentation/esp32-c6_technical_reference_manual_en.pdf)
- [ESP32-C6 Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf)
- [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c6/)

### Libraries and Tools
- [Arduino Core for ESP32](https://github.com/espressif/arduino-esp32)
- [TFT_eSPI Display Library](https://github.com/Bodmer/TFT_eSPI)
- [ESP32 Dev Tools](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c6/get-started/)

### Community and Support
- [ESP32 Forum](https://www.esp32.com/)
- [Arduino Forum](https://forum.arduino.cc/)
- [ESP32 Reddit Community](https://www.reddit.com/r/esp32/)

## 🤝 Contributing

We welcome contributions to improve this project! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/amazing-feature`
3. **Commit your changes**: `git commit -m 'Add amazing feature'`
4. **Push to the branch**: `git push origin feature/amazing-feature`
5. **Open a Pull Request**

### Contribution Guidelines
- Follow existing code style and formatting
- Add comments for complex code sections
- Test your changes thoroughly
- Update documentation as needed
- Provide clear commit messages

### Reporting Issues
If you find a bug or have a suggestion:
1. Check existing issues first
2. Create a new issue with detailed description
3. Include relevant code snippets or error messages
4. Specify hardware and software versions

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Disclaimer**: This documentation is community-maintained. Always refer to official Espressif documentation for the most current and accurate technical specifications.
