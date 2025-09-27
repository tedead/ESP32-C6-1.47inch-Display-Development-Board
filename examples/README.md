# Example Code for ESP32-C6 1.47" Display Development Board

This directory contains various example projects demonstrating the capabilities of the ESP32-C6 development board with integrated 1.47-inch display.

## Example Categories

### Basic Examples
1. **[blink_led](basic/blink_led/)** - Simple LED blinking example
2. **[hello_world](basic/hello_world/)** - Basic display output
3. **[serial_communication](basic/serial_communication/)** - UART communication example

### Display Examples
4. **[display_graphics](display/display_graphics/)** - Drawing shapes and text
5. **[display_images](display/display_images/)** - Image display from flash
6. **[display_animation](display/display_animation/)** - Simple animations
7. **[touchscreen](display/touchscreen/)** - Touch input handling (if available)

### Connectivity Examples
8. **[wifi_connection](connectivity/wifi_connection/)** - Wi-Fi connection and web server
9. **[bluetooth_beacon](connectivity/bluetooth_beacon/)** - BLE advertising
10. **[mqtt_client](connectivity/mqtt_client/)** - MQTT communication
11. **[http_client](connectivity/http_client/)** - HTTP requests and responses

### Sensor Integration
12. **[temperature_sensor](sensors/temperature_sensor/)** - Built-in temperature sensor
13. **[adc_reading](sensors/adc_reading/)** - Analog input reading
14. **[i2c_sensor](sensors/i2c_sensor/)** - I2C sensor communication

### Advanced Examples
15. **[ota_update](advanced/ota_update/)** - Over-the-air firmware updates
16. **[deep_sleep](advanced/deep_sleep/)** - Power management and sleep modes
17. **[web_interface](advanced/web_interface/)** - Complete web-based control panel
18. **[data_logger](advanced/data_logger/)** - Data logging to SD card or flash

### IoT Integration
19. **[aws_iot](iot/aws_iot/)** - Amazon Web Services IoT integration
20. **[google_cloud](iot/google_cloud/)** - Google Cloud IoT integration
21. **[home_assistant](iot/home_assistant/)** - Home Assistant integration

## Getting Started

1. Choose an example that matches your interest
2. Navigate to the example directory
3. Read the README.md file in each example
4. Follow the setup instructions
5. Upload the code to your board

## Hardware Requirements

Most examples require only the ESP32-C6 development board. Additional hardware requirements are specified in each example's README.md file.

## Software Requirements

- Arduino IDE 2.0+ with ESP32 package installed, or
- ESP-IDF development environment
- Required libraries (specified in each example)

## Library Installation

Common libraries used across examples:

### Arduino IDE
```
Tools > Manage Libraries
Search and install:
- TFT_eSPI (for display)
- WiFi (built-in)
- ArduinoJson (for JSON handling)
- PubSubClient (for MQTT)
- AsyncTCP (for async web server)
- ESPAsyncWebServer (for web server)
```

### ESP-IDF
Most ESP-IDF examples use built-in components or components from the ESP Component Registry.

## Troubleshooting

### Common Issues
- **Compilation errors**: Check library versions and board selection
- **Upload failures**: Ensure correct COM port and enter programming mode
- **Display issues**: Verify pin connections and library configuration
- **Wi-Fi connection problems**: Check credentials and network settings

### Debug Tips
1. Enable Serial Monitor at 115200 baud
2. Add debug prints to track program flow
3. Check power supply stability
4. Verify pin connections with multimeter

## Contributing

Feel free to contribute your own examples:

1. Create a new directory with a descriptive name
2. Include complete source code
3. Add a detailed README.md with:
   - Purpose and functionality
   - Hardware requirements
   - Wiring diagram (if applicable)
   - Installation steps
   - Expected output
4. Test thoroughly before submitting

## Support

For questions about specific examples:
1. Check the example's README.md first
2. Look at the troubleshooting section
3. Search existing issues
4. Create a new issue with details about your problem

---

**Note**: Examples are provided for educational and demonstration purposes. Adapt them according to your specific requirements and test thoroughly before using in production.