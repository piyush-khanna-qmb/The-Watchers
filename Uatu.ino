// Piyush Khanna ji
// [Sun] 25/06/2023, 12:39 AM

#include <WiFi.h>

////////////////// HC-SR04 Sensor Pins //////////////////

const int triggerPin = 32;
const int echoPin = 33;
const int distanceThreshold = 30; // in centimeters

////////////////// HC-SR04 Sensor Pins //////////////////

////////////////// Wi-Fi settings //////////////////

const char* ssid = "MyESP32Hotspot";
const char* password = "password";

////////////////// Wi-Fi settings //////////////////

////////////////// Server settings //////////////////

WiFiServer server(80);
WiFiClient client;

////////////////// Server settings //////////////////

void setup() {
  Serial.begin(115200);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Ye ji banega Hot-sapot
  WiFi.softAP(ssid, password);
  IPAddress localIP = WiFi.softAPIP();
  Serial.print("Hotspot IP address: ");
  Serial.println(localIP);

  // Start the server
  server.begin();
}

void loop() {
  // Check if a new client is available
  if (!client.connected()) {
    client = server.available();
    delay(1);
  }

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  Serial.println(distance);

  if (distance < distanceThreshold) {
    Serial.println("Intrusion alert!");

    // Send "Hello" message to the client
    if (client.connected()) {
      client.println("Hi");
    }
    delay(100);
  }

  if (!client.connected()) {
    client.stop();
    Serial.println("Client disconnected");
  }
}
