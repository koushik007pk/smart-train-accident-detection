#include <Servo.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

#define IR_PIN D1
#define FLAME_PIN A0
#define LED_PIN D5
#define BUZZER_PIN D6

Servo myServo;
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* server = "api.thingspeak.com";

WiFiClient client;

void setup() {
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);
  pinMode(FLAME_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  myServo.attach(D7);
  myServo.write(0); // Set servo to default position (0 degrees)

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  ThingSpeak.begin(client);
}

void loop() {
  int IRValue = digitalRead(IR_PIN);
  int flameValue = analogRead(FLAME_PIN);

  if (IRValue == 1) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    myServo.write(90); // Apply brakes (servo at 90 degrees)
    Serial.println("Link not connected");
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    myServo.write(0); // Release brakes (servo at 0 degrees)
    Serial.println("Link connected");
  }

  if (flameValue < 100) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    myServo.write(90); // Apply brakes (servo at 90 degrees)
    Serial.println("Fire Detected in Train");
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    myServo.write(0); // Release brakes (servo at 0 degrees)
    Serial.println("No Fire Detected");
  }

  // Send sensor values to ThingSpeak
  ThingSpeak.writeField(THINGSPEAK_CHANNEL_ID, 1, IRValue);
  ThingSpeak.writeField(THINGSPEAK_CHANNEL_ID, 2, flameValue);

  delay(1000); // Wait for 1 second before repeating the loop
}
