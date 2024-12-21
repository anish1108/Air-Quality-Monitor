#include <WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "System Administrator";
const char* password = "123123123";

// MQTT Server
const char* mqtt_server = "test.mosquitto.org"; // Example public MQTT broker
const int mqtt_port = 1883;

// Variables
const int airQualityPin = 34; // Analog pin connected to MQ-7
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.println("started");
  Serial.begin(115200);
  Serial.println("2222");

  // Initialize WiFi
  connectToWiFi();
  Serial.println("3333");

  // Set MQTT Server
  client.setServer(mqtt_server, mqtt_port);
  Serial.println("4444");

  // Initialize the Air Quality Sensor
  pinMode(airQualityPin, INPUT);
  Serial.println("5555");
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  // Read air quality
  int sensorValue = analogRead(airQualityPin);
  float voltage = sensorValue * (3.3 / 4095.0); // Convert ADC to voltage
  Serial.print("Air Quality Voltage: ");
  Serial.println(voltage);

  // Send data to MQTT
  char message[50];
  snprintf(message, 50, "Air Quality Voltage: %.2f", voltage);
  client.publish("air_quality/data", message);

  delay(2000);
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

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
      client.subscribe("air_quality/data");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
