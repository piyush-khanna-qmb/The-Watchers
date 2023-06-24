// Piyush Khanna ji
// [Sun] 25/06/2023, 12:39 AM

#include <WiFi.h>

// Wi-Fi settings
const char* ssid = "MyESP32Hotspot";
const char* password = "password";
const char* serverIP = "192.168.4.1";

// Server port
const int serverPort = 80;

WiFiClient client;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  client.setTimeout(5000);
}

void loop() {
  // Check if the client is not connected or has disconnected
  if (!client.connected()) {
    // Connect to the server
    if (client.connect(serverIP, serverPort)) {
      Serial.println("Connected to server");

      // Request data from the server
      client.println("GET / HTTP/1.1");
      client.println("Host: " + String(serverIP));
      client.println("Connection: close");
      client.println();
    } else {
      Serial.println("Connection to server failed");
    }
  }

  // Read the server response
  while (client.available()) {
    String response = client.readStringUntil('\n');
    Serial.println("Received message: " + response);
    // Add your code here to process the received message as needed
  }

  // Close the connection if the server has disconnected
  if (!client.connected()) {
    client.stop();
    Serial.println("Server disconnected");
  }
}
