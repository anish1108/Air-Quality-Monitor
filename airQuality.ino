#include <WiFi.h>
#include <PubSubClient.h>

// Wi-Fi credentials
const char* ssid = "System Administrator";
const char* password = "123123123";

// MQTT Server
// const char* mqtt_server = "mqtt.arduino.cc";
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

// Variables
const int airQualityPin = 34; // Analog pin connected to MQ-7 sensor
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  connectToWiFi();

  // Set MQTT server
  client.setServer(mqtt_server, mqtt_port);

  // Connect to MQTT broker
  connectToMQTT();

  // Initialize the Air Quality Sensor
  pinMode(airQualityPin, INPUT);
}

void loop() {
  if (!client.connected()) {
    connectToMQTT(); // Reconnect if disconnected
  }
  client.loop();

  // Read air quality
  int sensorValue = analogRead(airQualityPin);
  float voltage = sensorValue * (3.3 / 4095.0); // Convert ADC value to voltage
  Serial.print("Air Quality Voltage: ");
  Serial.println(voltage);

  // Publish air quality data to MQTT
  char message[50];
  snprintf(message, 50, "Air Quality Voltage: %.2f V", voltage);
  client.publish("air_quality/data", message);

  delay(2000); // Publish data every 2 seconds
}

void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
}

void connectToMQTT() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client_12345")) {
      Serial.println("Connected to MQTT!");
      client.subscribe("air_quality/data"); 
    } else {
      Serial.print("Failed, rc=");
      Serial.println(client.state());
      delay(5000);
    }
  }
}
