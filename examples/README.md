# Code Examples for ESP32-C6 1.47inch Display Development Board

This directory contains practical code examples for the ESP32-C6 1.47inch Display Development Board.

## Examples Included

### Basic Examples
1. **[hello_display.ino](basic/hello_display.ino)** - Basic display initialization and text output
2. **[gpio_test.ino](basic/gpio_test.ino)** - Digital I/O and LED control
3. **[adc_reading.ino](basic/adc_reading.ino)** - Analog input reading and display

### Wi-Fi Examples
4. **[wifi_scanner.ino](wifi/wifi_scanner.ino)** - Wi-Fi network scanner with display output
5. **[wifi_client.ino](wifi/wifi_client.ino)** - Connect to Wi-Fi and show status
6. **[web_server.ino](wifi/web_server.ino)** - Simple web server with display

### Bluetooth Examples
7. **[bluetooth_serial.ino](bluetooth/bluetooth_serial.ino)** - Bluetooth serial communication
8. **[ble_beacon.ino](bluetooth/ble_beacon.ino)** - BLE beacon advertisement

### Advanced Examples
9. **[sensor_dashboard.ino](advanced/sensor_dashboard.ino)** - Multi-sensor data display
10. **[weather_station.ino](advanced/weather_station.ino)** - Complete weather station
11. **[data_logger.ino](advanced/data_logger.ino)** - Data logging to file system

## How to Use

1. Copy the desired example code
2. Open Arduino IDE
3. Select board: ESP32C6 Dev Module
4. Install required libraries (mentioned in each example)
5. Upload to your board

## Library Dependencies

Most examples require these libraries:
- **TFT_eSPI** - For display control
- **WiFi** - Built-in Wi-Fi functionality
- **ArduinoJson** - JSON parsing (some examples)
- **PubSubClient** - MQTT client (IoT examples)

Install via Arduino Library Manager or PlatformIO.

## Configuration Notes

- Display pins are pre-configured for this board
- Modify Wi-Fi credentials in examples before uploading
- Some examples may require additional hardware (sensors, LEDs, etc.)
- Check serial monitor (115200 baud) for debug output

For more information, see the main [README.md](../README.md).