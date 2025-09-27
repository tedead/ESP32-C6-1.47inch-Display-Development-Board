# Wi-Fi Connection and Web Server Example

This example demonstrates connecting the ESP32-C6 to a Wi-Fi network and creating a simple web server for remote control and monitoring.

## Description

The program:
- Connects to your Wi-Fi network
- Displays connection status on the LCD
- Creates a web server with control interface
- Allows remote LED control via web browser
- Shows board information and status

## Hardware Requirements

- ESP32-C6 1.47" Display Development Board
- USB-C cable for programming and power
- 2.4GHz Wi-Fi network

## Software Requirements

- Arduino IDE 2.0+ with ESP32 support
- TFT_eSPI library
- Built-in WiFi and WebServer libraries (included with ESP32 package)

## Configuration

### Wi-Fi Credentials
Before uploading, modify these lines in the code with your Wi-Fi details:
```cpp
const char* ssid = "YourWiFiNetwork";     // Replace with your Wi-Fi name
const char* password = "YourWiFiPassword"; // Replace with your Wi-Fi password
```

### TFT_eSPI Library Setup
Ensure TFT_eSPI is configured as described in the [hello_world example](../../basic/hello_world/README.md).

## Installation

1. Install required libraries (TFT_eSPI)
2. Configure Wi-Fi credentials in the code
3. Open Arduino IDE
4. Load this sketch: `File > Open > wifi_connection.ino`
5. Select board: `Tools > Board > ESP32 Arduino > ESP32C6 Dev Module`
6. Select correct COM port: `Tools > Port`
7. Upload: `Ctrl+U` or click Upload button

## Expected Behavior

### Display Output
- Shows "Connecting to WiFi..." during connection
- Displays connection status and IP address
- Shows current LED state and uptime
- Updates status information periodically

### Web Interface
- Access via `http://[IP_ADDRESS]` in your browser
- Control panel with board information
- LED control buttons (ON/OFF/TOGGLE)
- Real-time status display

### Serial Monitor Output
```
ESP32-C6 Wi-Fi Connection Example
Connecting to YourWiFiNetwork
....
WiFi connected!
IP address: 192.168.1.100
Web server started
```

## Web Interface Features

### Main Control Panel
- **Board Information**: Chip model, free memory, Wi-Fi signal strength
- **LED Control**: Buttons to turn LED on/off or toggle
- **Status Display**: Current LED state and system information

### API Endpoints
- `GET /` - Main control panel (HTML)
- `GET /led/on` - Turn LED on
- `GET /led/off` - Turn LED off  
- `GET /led/toggle` - Toggle LED state
- `GET /status` - JSON status information

### JSON Status Response
```json
{
  "chipModel": "ESP32-C6",
  "freeHeap": 123456,
  "wifiRSSI": -45,
  "ipAddress": "192.168.1.100",
  "ledState": true,
  "uptime": 12345
}
```

## Troubleshooting

### Wi-Fi Connection Issues
- **Wrong credentials**: Double-check SSID and password
- **Network compatibility**: Ensure 2.4GHz network (5GHz not supported)
- **Signal strength**: Move closer to router if connection fails
- **Router settings**: Check if MAC filtering or security settings block connection

### Web Server Not Accessible
- **Firewall**: Check if firewall blocks the connection
- **Network isolation**: Some routers isolate clients
- **IP address**: Verify the correct IP from serial monitor or display
- **Port blocking**: Try different port if 80 is blocked

### Display Issues
- Refer to troubleshooting in [hello_world example](../../basic/hello_world/README.md)

### Upload/Compilation Errors
- **Board selection**: Ensure ESP32C6 Dev Module is selected
- **Libraries**: Install TFT_eSPI and configure properly
- **Port selection**: Select correct COM port

## Code Explanation

### Wi-Fi Connection
```cpp
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  // Connection retry logic
}
```

### Web Server Setup
```cpp
WebServer server(80);
server.on("/", handleRoot);      // Handle root page
server.on("/led/on", handleLEDOn); // Handle LED control
server.begin();                  // Start server
```

### Request Handling
```cpp
void handleRoot() {
  String html = "<!DOCTYPE html>..."; // Build HTML page
  server.send(200, "text/html", html); // Send response
}
```

## Security Considerations

This is a basic example for learning purposes. For production use:
- Use HTTPS instead of HTTP
- Implement authentication
- Validate input parameters
- Use secure Wi-Fi (WPA3/WPA2)
- Consider using WebSocket for real-time updates

## Modifications

### Add More Control Features
```cpp
// Add more endpoints
server.on("/brightness", handleBrightness);
server.on("/temperature", handleTemperature);
```

### Enhanced Web Interface
- Add JavaScript for dynamic updates
- Implement WebSocket for real-time communication
- Create mobile-responsive design
- Add CSS styling for better appearance

### IoT Integration
- Send data to cloud services (AWS IoT, Google Cloud)
- Implement MQTT for message queuing
- Add sensor readings to web interface
- Create RESTful API for external applications

### Security Enhancements
```cpp
// Basic authentication example
if (!server.authenticate("admin", "password")) {
  return server.requestAuthentication();
}
```

## Performance Tips

- Use `server.handleClient()` frequently in main loop
- Avoid long delays in request handlers
- Consider using async web server for better performance
- Monitor memory usage with `ESP.getFreeHeap()`

## Next Steps

After successfully running this example:
1. Try adding more sensors and display their data on the web interface
2. Explore the [mqtt_client](../mqtt_client/) example for IoT messaging
3. Implement OTA (Over-The-Air) updates via web interface
4. Create a complete IoT dashboard with data logging