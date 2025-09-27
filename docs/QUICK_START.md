# ESP32-C6 Development Board - Quick Start Guide

This guide helps you get your ESP32-C6 development board up and running quickly.

## 📦 What's in the Box

- ESP32-C6 Development Board with 1.47" LCD Display
- USB-C Cable (if included)
- Quick reference card (if included)

*Note: Components may vary by supplier*

## ⚡ Quick Setup (5 Minutes)

### Step 1: Install Arduino IDE
1. Download Arduino IDE 2.0+ from [arduino.cc](https://www.arduino.cc/en/software)
2. Install and launch Arduino IDE

### Step 2: Add ESP32 Support
1. Go to `File > Preferences`
2. Add this URL to "Additional Board Manager URLs":
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
3. Go to `Tools > Board > Board Manager`
4. Search for "ESP32" and install latest version by Espressif

### Step 3: Configure Board
1. Select `Tools > Board > ESP32 Arduino > ESP32C6 Dev Module`
2. Connect board via USB-C cable
3. Select correct port in `Tools > Port`

### Step 4: Test Upload
1. Open `File > Examples > Basics > Blink`
2. Change LED pin to 21: `#define LED_BUILTIN 21`
3. Click Upload (Ctrl+U)
4. LED should blink every second

## 🔧 First Project: Display Hello World

### Install Display Library
1. Go to `Tools > Manage Libraries`
2. Search "TFT_eSPI" by Bodmer
3. Click Install

### Configure Display Library
Edit `Arduino/libraries/TFT_eSPI/User_Setup.h`:
```cpp
#define ST7789_DRIVER
#define TFT_WIDTH  172
#define TFT_HEIGHT 320

#define TFT_CS   10
#define TFT_DC    2  
#define TFT_RST   1
#define TFT_MOSI  7
#define TFT_SCLK  6
#define TFT_BL    3

#define SPI_FREQUENCY  27000000
```

### Upload Display Example
Use the [hello_world example](../examples/basic/hello_world/) from this repository.

## 🔍 Troubleshooting

| Problem | Solution |
|---------|----------|
| Board not detected | Check USB cable, try different port |
| Upload fails | Hold BOOT button while uploading |
| Display blank | Verify TFT_eSPI configuration |
| Wi-Fi won't connect | Check 2.4GHz network, credentials |

## 📋 Pin Reference Card

```
GPIO21 - Built-in LED    GPIO10 - LCD CS
GPIO16 - Serial RX       GPIO2  - LCD DC  
GPIO17 - Serial TX       GPIO1  - LCD RST
GPIO0  - Boot button     GPIO7  - LCD MOSI
                         GPIO6  - LCD SCLK
                         GPIO3  - LCD Backlight
```

## 🌐 Wi-Fi Quick Connect

```cpp
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.begin("YourWiFi", "YourPassword");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("Connected!");
  Serial.println(WiFi.localIP());
}
```

## 🚀 Next Steps

1. ✅ **Basic Setup** - LED blink and display test
2. 📊 **Try Examples** - Explore [examples directory](../examples/)
3. 🌐 **Wi-Fi Projects** - Web server, IoT connectivity
4. 📱 **Advanced Projects** - Sensors, data logging, OTA updates

## 📚 Additional Resources

- **Complete Documentation**: [README.md](../README.md)
- **Hardware Details**: [HARDWARE.md](../HARDWARE.md) 
- **Example Code**: [examples/](../examples/)
- **Contribution Guide**: [CONTRIBUTING.md](../CONTRIBUTING.md)

## 💡 Pro Tips

- Always use 3.3V logic levels
- Keep wires short for stable display operation
- Use quality USB cable for programming
- Monitor serial output at 115200 baud for debugging
- Hold BOOT button if upload fails

---

**Need Help?** Check the troubleshooting section or create an issue on GitHub.