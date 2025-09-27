# Hardware Documentation

## ESP32-C6 1.47" Display Development Board - Hardware Specifications

### Overview
This document provides detailed hardware information for the ESP32-C6 development board with integrated 1.47-inch display.

## Block Diagram
```
    USB-C ──┐
            │
    ┌───────▼────────┐    ┌─────────────────┐
    │   Power Mgmt   │    │   1.47" LCD     │
    │   (3.3V LDO)   │    │   172x320px     │
    └───────┬────────┘    │   SPI Interface │
            │             └─────────┬───────┘
    ┌───────▼────────┐              │
    │   ESP32-C6     │◄─────────────┘
    │   RISC-V Core  │
    │   Wi-Fi 6      │    ┌─────────────────┐
    │   Bluetooth 5  │    │   GPIO Header   │
    │                │◄───┤   Expansion     │
    └────────────────┘    └─────────────────┘
```

## Power System

### Power Input Options
1. **USB-C Connector**: 5V input, recommended for development
2. **VIN Pin**: 3.3V - 5.5V input, for external power supply
3. **3V3 Pin**: 3.3V regulated input (bypass LDO)

### Power Distribution
- **Input Voltage**: 5V (USB-C) or 3.3-5.5V (VIN)
- **Regulated Output**: 3.3V @ 600mA (typical)
- **LDO Regulator**: High-efficiency switching regulator
- **Power Consumption**:
  - Active (Wi-Fi TX): ~200mA
  - Active (CPU only): ~50mA
  - Light sleep: ~2mA
  - Deep sleep: ~10µA

## ESP32-C6 Microcontroller

### Core Specifications
- **CPU**: RISC-V single-core, up to 160MHz
- **Memory**: 
  - 512KB SRAM
  - 4MB Flash (on-module)
  - 16KB RTC SRAM
- **Wireless**:
  - Wi-Fi 6 (802.11ax), 2.4GHz
  - Bluetooth 5.0 LE
  - Thread/Zigbee support
- **Peripherals**:
  - 30 GPIO pins (programmable)
  - 7 ADC channels (12-bit)
  - 2 DAC channels (8-bit)
  - 4 SPI interfaces
  - 2 I2C interfaces
  - 3 UART interfaces
  - 1 I2S interface
  - PWM on all GPIO pins

### GPIO Capabilities
| GPIO | ADC | DAC | RTC | SPI | I2C | UART | Special Function |
|------|-----|-----|-----|-----|-----|------|------------------|
| 0    | ADC1_CH0 | - | RTC_GPIO0 | - | - | - | Boot mode |
| 1    | ADC1_CH1 | - | RTC_GPIO1 | - | - | - | LCD Reset |
| 2    | ADC1_CH2 | - | RTC_GPIO2 | - | - | - | LCD DC |
| 3    | ADC1_CH3 | - | RTC_GPIO3 | - | - | - | LCD Backlight |
| 4    | ADC1_CH4 | - | RTC_GPIO4 | - | SDA | - | - |
| 5    | ADC1_CH5 | - | RTC_GPIO5 | - | SCL | - | - |
| 6    | - | - | - | SCLK | - | - | LCD SCLK |
| 7    | - | - | - | MOSI | - | - | LCD MOSI |
| 8    | - | - | - | - | - | - | General I/O |
| 9    | - | - | - | - | - | - | General I/O |
| 10   | - | - | - | CS | - | - | LCD CS |
| 16   | - | - | - | - | - | RX | Serial RX |
| 17   | - | - | - | - | - | TX | Serial TX |
| 18   | - | - | - | - | - | - | General I/O |
| 19   | - | - | - | - | - | - | General I/O |
| 20   | - | - | - | - | - | - | General I/O |
| 21   | - | - | - | - | - | - | User LED |

## Display System

### LCD Specifications
- **Size**: 1.47 inches diagonal
- **Resolution**: 172 x 320 pixels
- **Color Depth**: 16-bit (65K colors)
- **Controller**: ST7789V (typical)
- **Interface**: 4-wire SPI
- **Backlight**: LED with PWM control
- **Viewing Angle**: 80°/80°/80°/80° (U/D/L/R)
- **Brightness**: 300 cd/m² (typical)

### Display Interface
```
ESP32-C6 Pin  │  LCD Pin     │  Function
─────────────┼─────────────┼─────────────
GPIO10       │  CS          │  Chip Select
GPIO2        │  DC          │  Data/Command
GPIO1        │  RST         │  Reset
GPIO7        │  SDA (MOSI)  │  Serial Data
GPIO6        │  SCL (SCLK)  │  Serial Clock
GPIO3        │  BLK         │  Backlight Control
3V3          │  VCC         │  Power Supply
GND          │  GND         │  Ground
```

### Display Timing
- **SPI Clock**: Up to 80MHz
- **Write Cycle**: ~125ns
- **Reset Pulse**: Minimum 1ms
- **Initialization Time**: ~120ms

## Physical Layout

### Board Dimensions
- **Length**: TBD mm
- **Width**: TBD mm  
- **Thickness**: TBD mm (including components)
- **Weight**: TBD grams

### Component Placement
```
     USB-C
    ┌─────┐
    │  ┌──┴──┐
[RST]│  │ USB │
    │  └─────┘     ┌─────────────┐
[BOOT] │           │             │
    │  │           │  1.47" LCD  │
    │  │           │   Display   │
    │  │           │             │
    └──┤           └─────────────┤
       │  ESP32-C6                │
       │   Module                 │
       │                         │
       └─────────────────────────┘
        ││││││││││││││││││││││││││
        GPIO Header Pins
```

### Mechanical Considerations
- **Mounting**: 4x M2.5 mounting holes
- **Clearance**: 2mm minimum component clearance
- **Connector**: USB-C rated for 10,000+ insertion cycles
- **Environmental**: Operating temperature -40°C to +85°C

## Electrical Characteristics

### Absolute Maximum Ratings
- **Supply Voltage (VCC)**: -0.3V to +3.6V
- **Input Voltage (VIN)**: -0.3V to +6V
- **I/O Pin Voltage**: -0.3V to VCC+0.3V
- **Storage Temperature**: -65°C to +150°C
- **ESD Protection**: 2kV (Human Body Model)

### Recommended Operating Conditions
- **Supply Voltage**: 3.0V to 3.6V
- **Operating Temperature**: -40°C to +85°C
- **Humidity**: 10% to 90% RH (non-condensing)

### Current Consumption
| Mode | Current (typ) | Current (max) |
|------|---------------|---------------|
| Active (CPU + Wi-Fi TX) | 200mA | 300mA |
| Active (CPU only) | 50mA | 80mA |
| Light Sleep | 2mA | 5mA |
| Deep Sleep | 10µA | 50µA |
| Modem Sleep | 15mA | 25mA |

## Thermal Management

### Thermal Characteristics
- **Junction Temperature**: 125°C maximum
- **Thermal Resistance**: 
  - Junction to Ambient: 45°C/W (in free air)
  - Junction to Case: 15°C/W

### Cooling Recommendations
- Natural convection sufficient for normal operation
- Consider heat sink for high-power applications
- Maintain adequate airflow in enclosed designs
- Monitor junction temperature in extreme conditions

## EMC and Compliance

### Certifications
- **FCC Part 15**: Class B digital device
- **CE**: European Conformity marking
- **IC**: Industry Canada certification
- **RoHS**: Lead-free compliance
- **REACH**: Chemical substance regulation

### Antenna Considerations
- **Type**: PCB antenna (on-module)
- **Frequency**: 2.4GHz ISM band
- **Gain**: 2dBi (typical)
- **Impedance**: 50Ω
- **Keep-out Zone**: 5mm around antenna area

## Design Guidelines

### PCB Layout
- **Layer Stack**: 4-layer recommended
- **Trace Width**: 
  - Power: 0.2mm minimum (3.3V), 0.3mm minimum (5V)
  - Signal: 0.1mm minimum
  - High-speed: Use controlled impedance
- **Via Size**: 0.1mm minimum drill

### Signal Integrity
- **Ground Plane**: Solid ground plane recommended
- **Power Decoupling**: 
  - 100nF ceramic capacitors near power pins
  - 10µF tantalum capacitor for bulk storage
- **Crystal**: Use matched load capacitors
- **High-Speed Signals**: Keep traces short and matched

### ESD Protection
- Use ESD protection diodes on exposed I/O
- Implement proper grounding techniques
- Follow IEC 61000-4-2 guidelines

## Schematic Information

### Power Supply Circuit
```
VIN ──┬── LDO Regulator ──┬── 3V3 (ESP32-C6)
      │   (3.3V/600mA)    │
      ├── Power LED       ├── 3V3 (LCD)
      └── Fuse            └── 3V3 (GPIO Header)
          (500mA)
```

### Reset Circuit
```
EN ──┬── 10kΩ ── 3V3
     │
     ├── 100nF ── GND
     │
     └── Reset Button ── GND
```

### Programming Circuit
```
GPIO0 ──┬── 10kΩ ── 3V3
        │
        └── Boot Button ── GND
```

## Manufacturing Notes

### Assembly Process
1. SMD components placement
2. Reflow soldering (lead-free)
3. Through-hole component insertion
4. Wave soldering or selective soldering
5. Final inspection and testing

### Test Points
- **Power**: 3V3, GND, VIN test points
- **Programming**: EN, GPIO0 test points  
- **Debug**: TX, RX test points
- **Display**: CS, DC, RST test points

### Quality Control
- Visual inspection
- In-circuit testing (ICT)
- Functional testing
- Wi-Fi performance testing
- Display functionality testing

---

**Note**: This hardware documentation is for reference only. Always consult the latest official documentation and perform your own verification before using in production designs.