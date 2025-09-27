# LED Blink Example

This example demonstrates the most basic functionality of the ESP32-C6 development board by blinking the built-in LED.

## Description

The program continuously blinks the LED connected to GPIO21 at 1-second intervals, providing visual feedback that the board is operating correctly.

## Hardware Requirements

- ESP32-C6 1.47" Display Development Board
- USB-C cable for programming and power

## Wiring

No additional wiring required - uses the built-in LED on GPIO21.

## Software Requirements

- Arduino IDE 2.0+ with ESP32 support
- No additional libraries required

## Installation

1. Open Arduino IDE
2. Load this sketch: `File > Open > blink_led.ino`
3. Select board: `Tools > Board > ESP32 Arduino > ESP32C6 Dev Module`
4. Select correct COM port: `Tools > Port`
5. Upload: `Ctrl+U` or click Upload button

## Expected Behavior

- The built-in LED will blink on and off every second
- Serial monitor will display "LED ON" and "LED OFF" messages
- Serial monitor baud rate: 115200

## Troubleshooting

### LED doesn't blink
- Check that the correct board is selected
- Verify the COM port is correct
- Ensure the board is properly connected via USB
- Try pressing the RESET button after upload

### Serial monitor shows no output
- Check that serial monitor baud rate is set to 115200
- Verify the correct COM port is selected
- Try closing and reopening the serial monitor

## Code Explanation

```cpp
#define LED_PIN 21      // GPIO21 is connected to built-in LED
#define BLINK_DELAY 1000  // 1000ms = 1 second delay
```

The code defines the LED pin (GPIO21) and blink delay (1000ms).

```cpp
pinMode(LED_PIN, OUTPUT);
```

Configures GPIO21 as an output pin to drive the LED.

```cpp
digitalWrite(LED_PIN, HIGH);  // Turn LED on
digitalWrite(LED_PIN, LOW);   // Turn LED off
```

These functions control the LED state - HIGH turns it on, LOW turns it off.

## Modifications

### Change Blink Speed
Modify the `BLINK_DELAY` value:
- Faster blinking: Use smaller values (e.g., 100 for very fast)
- Slower blinking: Use larger values (e.g., 2000 for 2-second intervals)

### Different Blink Pattern
Create more complex patterns by varying the ON and OFF delays:
```cpp
digitalWrite(LED_PIN, HIGH);
delay(100);  // Short on time
digitalWrite(LED_PIN, LOW);
delay(1000); // Long off time
```

### Use External LED
To use an external LED:
1. Connect LED cathode (-) to GND through a 220Ω resistor
2. Connect LED anode (+) to any available GPIO pin
3. Change `LED_PIN` to your chosen GPIO number

## Next Steps

After successfully running this example:
1. Try the [hello_world](../hello_world/) example to test the display
2. Explore the [connectivity examples](../../connectivity/) for Wi-Fi functionality
3. Experiment with other GPIO pins and sensors