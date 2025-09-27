# Pin Reference Guide for ESP32-C6 1.47inch Display Development Board

## GPIO Pin Mapping

### Display Connection (Internal)
The display is connected internally via SPI. These pins are used by the display and should not be reassigned:

| Display Function | ESP32-C6 GPIO | Description |
|------------------|---------------|-------------|
| SPI Clock (SCL)  | GPIO6         | SPI clock signal |
| SPI Data (SDA)   | GPIO7         | SPI data (MOSI) |
| Reset (RES)      | GPIO10        | Display reset |
| Data/Cmd (DC)    | GPIO11        | Data/Command select |
| Chip Select (CS) | GPIO20        | SPI chip select |
| Backlight (BLK)  | GPIO15        | Backlight control (PWM) |

### Available GPIO Pins

| Pin | GPIO | Type | Functions | Notes |
|-----|------|------|-----------|-------|
| 1   | GPIO0  | I/O  | Digital, ADC1_0 | Boot button, pull-up required |
| 2   | GPIO1  | I/O  | Digital, ADC1_1 | |
| 3   | GPIO2  | I/O  | Digital, ADC1_2 | |
| 4   | GPIO3  | I/O  | Digital, ADC1_3 | |
| 5   | GPIO4  | I/O  | Digital, ADC1_4 | |
| 6   | GPIO5  | I/O  | Digital, ADC1_5 | |
| 7   | GPIO8  | I/O  | Digital | Strapping pin |
| 8   | GPIO9  | I/O  | Digital | Strapping pin |
| 9   | GPIO12 | I/O  | Digital | |
| 10  | GPIO13 | I/O  | Digital | |
| 11  | GPIO14 | I/O  | Digital | |
| 12  | GPIO16 | I/O  | Digital | |
| 13  | GPIO17 | I/O  | Digital | |
| 14  | GPIO18 | I/O  | Digital | |
| 15  | GPIO19 | I/O  | Digital | |
| 16  | GPIO21 | I/O  | Digital | |
| 17  | GPIO22 | I/O  | Digital | |
| 18  | GPIO23 | I/O  | Digital | |

### Special Function Pins

#### ADC (Analog to Digital Converter)
- **ADC1**: GPIO0-GPIO5 (6 channels)
- **Resolution**: 12-bit (0-4095)
- **Voltage**: 0-3.3V (with attenuation settings)

#### PWM (Pulse Width Modulation)
- **Available on**: Most GPIO pins
- **Channels**: Up to 8 channels
- **Resolution**: 8-16 bit
- **Frequency**: Up to 40 MHz

#### SPI
- **SPI2** (available for user):
  - MOSI: Configurable
  - MISO: Configurable
  - CLK: Configurable
  - CS: Configurable
- **SPI3** (used by display)

#### I2C
- **I2C0** (available for user):
  - SDA: Configurable (e.g., GPIO21)
  - SCL: Configurable (e.g., GPIO22)

#### UART
- **UART0**: USB programming interface
- **UART1**: 
  - TX: Configurable
  - RX: Configurable

### Pin Configuration Examples

#### Basic Digital I/O
```cpp
// Setup pin as output
pinMode(GPIO1, OUTPUT);
digitalWrite(GPIO1, HIGH);

// Setup pin as input with pull-up
pinMode(GPIO2, INPUT_PULLUP);
bool state = digitalRead(GPIO2);
```

#### ADC Reading
```cpp
// Read analog value (0-4095)
int adcValue = analogRead(GPIO0);
float voltage = adcValue * (3.3 / 4095.0);
```

#### PWM Output
```cpp
// Setup PWM (pin, frequency, resolution)
ledcSetup(0, 5000, 8); // Channel 0, 5kHz, 8-bit
ledcAttachPin(GPIO1, 0); // Attach pin to channel

// Set duty cycle (0-255 for 8-bit)
ledcWrite(0, 128); // 50% duty cycle
```

#### I2C Setup
```cpp
#include <Wire.h>

void setup() {
  Wire.begin(21, 22); // SDA, SCL
  // I2C communication code
}
```

#### SPI Setup
```cpp
#include <SPI.h>

void setup() {
  SPI.begin(18, 19, 23, 5); // SCK, MISO, MOSI, SS
  // SPI communication code
}
```

### Important Notes

1. **Reserved Pins**: GPIO6, 7, 10, 11, 15, 20 are used by the internal display
2. **Strapping Pins**: GPIO8, GPIO9 have special boot functions
3. **Boot Pin**: GPIO0 is connected to the boot button
4. **Input Only**: Some pins may be input-only (check specific board documentation)
5. **Current Limits**: Each GPIO can source/sink up to 20mA (40mA max per pin)

### Power Pins

| Pin | Function | Voltage | Notes |
|-----|----------|---------|-------|
| VCC/3V3 | Power Supply | 3.3V | Main power rail |
| 5V | USB Power | 5V | From USB-C connector |
| GND | Ground | 0V | Common ground |
| EN | Enable | 3.3V | Reset pin (active low) |

### Schematic Reference

For detailed electrical specifications and connections, refer to:
- ESP32-C6 datasheet
- Board schematic (if available from manufacturer)
- Pin capability matrix in ESP32-C6 technical reference manual

---

**Warning**: Always verify pin assignments with your specific board documentation, as different manufacturers may use slightly different configurations.