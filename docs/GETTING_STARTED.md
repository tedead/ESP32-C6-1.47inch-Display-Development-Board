# Getting Started with ESP32-C6 1.47inch Display Development Board

## Quick Setup Guide

### 1. Hardware Requirements
- ESP32-C6 1.47inch Display Development Board
- USB-C cable (data-capable)
- Computer with USB port

### 2. Software Installation

#### Option A: Arduino IDE (Recommended for Beginners)
1. Download and install [Arduino IDE 2.0+](https://www.arduino.cc/en/software)
2. Open Arduino IDE
3. Go to File → Preferences
4. Add this URL to "Additional Board Manager URLs":
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
5. Go to Tools → Board → Boards Manager
6. Search for "ESP32" and install "esp32 by Espressif Systems" (v3.0.0+)
7. Select Tools → Board → ESP32 Arduino → "ESP32C6 Dev Module"

#### Option B: PlatformIO (Advanced Users)
1. Install [VS Code](https://code.visualstudio.com/)
2. Install PlatformIO extension
3. Create new project with framework "Arduino" and board "esp32-c6-devkitc-1"

### 3. First Program

Create a new sketch and copy this code:

```cpp
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  
  // Initialize the display
  tft.init();
  tft.setRotation(1); // Landscape orientation
  tft.fillScreen(TFT_BLACK);
  
  // Display welcome message
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  tft.drawString("Hello World!", 50, 50);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(1);
  tft.drawString("ESP32-C6 is working!", 50, 80);
  
  Serial.println("Display initialized successfully!");
}

void loop() {
  // Blink built-in LED if available
  delay(1000);
}
```

### 4. Upload Instructions

1. Connect your board via USB-C
2. Press and hold the BOOT button (if upload fails)
3. Click Upload in Arduino IDE
4. Release BOOT button when upload starts
5. Wait for "Done uploading" message

### 5. Troubleshooting First Run

**No display output?**
- Check power connection
- Verify TFT_eSPI library is installed
- Ensure correct board selection

**Upload fails?**
- Hold BOOT button during upload
- Check USB cable (must support data)
- Try different USB port
- Verify correct COM port selection

**Display garbled?**
- Check pin configuration in TFT_eSPI User_Setup.h
- Verify rotation setting (0-3)
- Reset the board

### Next Steps
- Try the example programs in the main README
- Explore Wi-Fi connectivity examples
- Learn about GPIO pin usage
- Create your first IoT project!

For more detailed information, refer to the main [README.md](../README.md).