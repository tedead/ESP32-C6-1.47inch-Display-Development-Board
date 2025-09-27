# ESP32-C6 Pinout Reference

This document provides detailed pinout information for the ESP32-C6 development board with 1.47" display.

## 🔌 GPIO Pinout Diagram

```
                    ESP32-C6 Development Board
                           [USB-C]
                    [BOOT]     [RESET]
                    
    3V3  [ ]                           [ ]  GND
    EN   [ ]                           [ ]  GPIO21  (LED)
    GPIO0[ ] (Boot)                    [ ]  GPIO20  
    GPIO1[ ] (LCD RST)                 [ ]  GPIO19
    GPIO2[ ] (LCD DC)                  [ ]  GPIO18
    GPIO3[ ] (LCD BL)                  [ ]  GPIO9
    GPIO4[ ]         1.47" LCD         [ ]  GPIO8
    GPIO5[ ]                           [ ]  GPIO7   (LCD MOSI)
    GPIO6[ ] (LCD SCLK)                [ ]  TX      (GPIO17)
    GND  [ ]                           [ ]  RX      (GPIO16)
    VIN  [ ]                           [ ]  GPIO10  (LCD CS)
```

## 📍 Pin Functions

### Power Pins
| Pin | Function | Voltage | Notes |
|-----|----------|---------|-------|
| 3V3 | 3.3V Output | 3.3V | Regulated output from LDO |
| VIN | Voltage Input | 3.3V-5.5V | External power input |
| GND | Ground | 0V | Common ground |
| EN  | Enable/Reset | 3.3V | Active low reset |

### GPIO Pins
| GPIO | Pin Name | Function | Capabilities | Notes |
|------|----------|----------|--------------|-------|
| 0    | GPIO0    | Boot Mode | ADC1_CH0, RTC_GPIO0 | Boot button, programming mode |
| 1    | GPIO1    | LCD Reset | ADC1_CH1, RTC_GPIO1 | Display reset control |
| 2    | GPIO2    | LCD DC | ADC1_CH2, RTC_GPIO2 | Display data/command |
| 3    | GPIO3    | LCD Backlight | ADC1_CH3, RTC_GPIO3 | PWM backlight control |
| 4    | GPIO4    | General I/O | ADC1_CH4, RTC_GPIO4, I2C_SDA | Available for user |
| 5    | GPIO5    | General I/O | ADC1_CH5, RTC_GPIO5, I2C_SCL | Available for user |
| 6    | GPIO6    | LCD Clock | SPI_SCLK | Display SPI clock |
| 7    | GPIO7    | LCD Data | SPI_MOSI | Display SPI data |
| 8    | GPIO8    | General I/O | - | Available for user |
| 9    | GPIO9    | General I/O | - | Available for user |
| 10   | GPIO10   | LCD CS | SPI_CS | Display chip select |
| 16   | RX       | Serial RX | UART0_RXD | Serial receive |
| 17   | TX       | Serial TX | UART0_TXD | Serial transmit |
| 18   | GPIO18   | General I/O | - | Available for user |
| 19   | GPIO19   | General I/O | - | Available for user |
| 20   | GPIO20   | General I/O | - | Available for user |
| 21   | GPIO21   | LED | - | Built-in LED |

### Special Pins
| Pin | Function | Description |
|-----|----------|-------------|
| BOOT | Programming Mode | Hold low during reset for download mode |
| RESET | Hardware Reset | Press to reset the microcontroller |
| USB+ | USB Data Plus | USB communication |
| USB- | USB Data Minus | USB communication |

## 🖥️ Display Connections

The 1.47" LCD display uses SPI interface:

| Display Signal | ESP32-C6 GPIO | Function |
|----------------|---------------|----------|
| VCC | 3V3 | Power supply |
| GND | GND | Ground |
| CS | GPIO10 | Chip select |
| RST | GPIO1 | Reset |
| DC | GPIO2 | Data/Command selection |
| SDA (MOSI) | GPIO7 | Serial data input |
| SCL (SCLK) | GPIO6 | Serial clock |
| BLK | GPIO3 | Backlight control |

## ⚡ Electrical Specifications

### GPIO Characteristics
- **Logic Level**: 3.3V
- **Input High (VIH)**: 2.0V min
- **Input Low (VIL)**: 0.8V max
- **Output High (VOH)**: 2.4V min @ 12mA
- **Output Low (VOL)**: 0.4V max @ 12mA
- **Maximum Current per Pin**: 40mA
- **Maximum Total Current**: 400mA

### ADC Specifications
- **Resolution**: 12-bit (0-4095)
- **Input Voltage Range**: 0V to 3.3V
- **Reference Voltage**: 3.3V (internal)
- **ADC Channels**: 7 channels (GPIO0-5 + internal temperature)

### PWM Specifications
- **Channels**: All GPIO pins support PWM
- **Resolution**: Up to 16-bit
- **Frequency**: 1Hz to 40MHz
- **Duty Cycle**: 0-100%

## 🔧 Programming Interface

### UART (Serial)
- **Default Baud Rate**: 115200
- **TX Pin**: GPIO17
- **RX Pin**: GPIO16
- **Flow Control**: None (default)

### SPI Interface
Multiple SPI interfaces available:
- **SPI0/1**: Used by flash memory (not available)
- **SPI2 (HSPI)**: Used by display
- **SPI3 (VSPI)**: Available for external devices

### I2C Interface
- **Default SDA**: GPIO4
- **Default SCL**: GPIO5
- **Clock Speed**: Up to 400kHz (Fast mode)
- **Pull-up Resistors**: External required (4.7kΩ typical)

## 🌐 Wireless Specifications

### Wi-Fi
- **Standard**: 802.11ax (Wi-Fi 6)
- **Frequency**: 2.4GHz only
- **Modes**: Station (STA), Access Point (AP), STA+AP
- **Security**: WPA3/WPA2/WPA/WEP
- **Antenna**: PCB trace antenna (built-in)

### Bluetooth
- **Version**: Bluetooth 5.0 LE
- **Protocols**: BLE, Mesh
- **Power**: Class 1, 2, and 3
- **Range**: Up to 100m (line of sight)

## 🔍 Pin Usage Guidelines

### Available for General Use
Safe to use for sensors, actuators, and general I/O:
- GPIO4, GPIO5 (I2C capable)
- GPIO8, GPIO9, GPIO18, GPIO19, GPIO20

### Reserved/Special Purpose
Avoid using these pins for general I/O:
- GPIO0: Boot mode selection
- GPIO1: Display reset
- GPIO2: Display DC
- GPIO3: Display backlight
- GPIO6: Display clock
- GPIO7: Display data
- GPIO10: Display CS
- GPIO16: Serial RX
- GPIO17: Serial TX
- GPIO21: Built-in LED

### Best Practices

#### Input Pins
```cpp
pinMode(pin, INPUT);           // Floating input
pinMode(pin, INPUT_PULLUP);    // Input with pull-up
pinMode(pin, INPUT_PULLDOWN);  // Input with pull-down
```

#### Output Pins
```cpp
pinMode(pin, OUTPUT);
digitalWrite(pin, HIGH/LOW);   // Digital output
analogWrite(pin, 0-255);       // PWM output (8-bit)
```

#### Analog Input
```cpp
int value = analogRead(pin);   // Returns 0-4095 (12-bit)
float voltage = value * 3.3 / 4095.0;
```

---

**Note**: Always verify pin assignments with actual hardware. Pin functions may vary between board revisions.