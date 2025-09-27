# Hello World Display Example

This example demonstrates basic display functionality by showing text and simple graphics on the 1.47-inch LCD display.

## Description

The program initializes the display and shows:
- Board title text
- "Hello World!" message
- Decorative border and circles
- Animated color gradient bars

## Hardware Requirements

- ESP32-C6 1.47" Display Development Board
- USB-C cable for programming and power

## Display Connections

The display is connected via SPI interface:
- **CS (Chip Select)**: GPIO10
- **DC (Data/Command)**: GPIO2
- **RST (Reset)**: GPIO1
- **SDA (MOSI)**: GPIO7
- **SCL (SCLK)**: GPIO6
- **BLK (Backlight)**: GPIO3

## Software Requirements

- Arduino IDE 2.0+ with ESP32 support
- TFT_eSPI library

## Library Installation

1. Open Arduino IDE
2. Go to `Tools > Manage Libraries`
3. Search for "TFT_eSPI" by Bodmer
4. Click Install

### TFT_eSPI Configuration

The TFT_eSPI library needs to be configured for this board. Create or modify the file:
`Arduino/libraries/TFT_eSPI/User_Setup.h`

Add these configuration lines:
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

## Installation

1. Install the TFT_eSPI library as described above
2. Configure TFT_eSPI for this board
3. Open Arduino IDE
4. Load this sketch: `File > Open > hello_world.ino`
5. Select board: `Tools > Board > ESP32 Arduino > ESP32C6 Dev Module`
6. Select correct COM port: `Tools > Port`
7. Upload: `Ctrl+U` or click Upload button

## Expected Behavior

- Display shows "ESP32-C6 Development Board" at the top
- Large "Hello World!" text in the center
- White border around the screen
- Red and blue circles in bottom corners
- Animated color gradient bars at the bottom
- Serial monitor shows initialization messages

## Troubleshooting

### Display is blank or corrupted
- Check TFT_eSPI library configuration
- Verify pin connections match the configuration
- Ensure adequate power supply (USB should be sufficient)
- Try different SPI frequency (lower values like 20000000)

### Compilation errors
- Make sure TFT_eSPI library is installed
- Check that User_Setup.h is properly configured
- Verify ESP32 board package is installed

### Display shows wrong colors or orientation
- Try different rotation values: `tft.setRotation(0)` through `tft.setRotation(3)`
- Check if display controller is ST7789V or similar

## Code Explanation

### Display Initialization
```cpp
tft.init();                    // Initialize display
tft.setRotation(1);           // Landscape orientation
tft.fillScreen(TFT_BLACK);    // Clear screen
```

### Text Display
```cpp
tft.setTextColor(TFT_WHITE, TFT_BLACK);  // Text color and background
tft.setTextSize(2);                      // Text size multiplier
tft.setCursor(20, 20);                   // Position cursor
tft.println("ESP32-C6");                 // Print text
```

### Graphics
```cpp
tft.drawRect(10, 10, width, height, TFT_WHITE);    // Draw rectangle
tft.fillCircle(x, y, radius, TFT_RED);             // Draw filled circle
```

### Color Animation
The `colorCycle()` function creates animated gradient bars using RGB color values.

## Display Specifications

- **Resolution**: 172 x 320 pixels
- **Colors**: 65K (16-bit RGB)
- **Controller**: ST7789V (typical)
- **Interface**: 4-wire SPI
- **Backlight**: PWM controllable

## Modifications

### Change Text Content
Modify the `displayHelloWorld()` function to show different text:
```cpp
tft.setCursor(50, 90);
tft.println("Your");
tft.setCursor(50, 130);
tft.println("Text!");
```

### Add More Graphics
```cpp
// Draw lines
tft.drawLine(x1, y1, x2, y2, TFT_GREEN);

// Draw triangles
tft.drawTriangle(x1, y1, x2, y2, x3, y3, TFT_BLUE);

// Draw filled rectangles
tft.fillRect(x, y, width, height, TFT_YELLOW);
```

### Control Backlight
```cpp
// Backlight is connected to GPIO3
pinMode(3, OUTPUT);
analogWrite(3, 128);  // 50% brightness (0-255)
```

## Next Steps

After successfully running this example:
1. Try modifying colors and text
2. Explore the [display_graphics](../../display/display_graphics/) example for advanced graphics
3. Combine with sensor readings to create a data display
4. Create simple user interfaces with buttons and menus