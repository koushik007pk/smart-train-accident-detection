# smart-train-accident-detection


The Train Safety Monitoring System is an Arduino-based project that monitors the status of an infrared (IR) sensor and a flame sensor to ensure the safety of a train. It detects the link status and the presence of fire, activating alarms and brakes when necessary.

## Components Used

- Arduino (ESP8266)
- Servo Motor
- Infrared (IR) Sensor
- Flame Sensor
- LED
- Buzzer

## Pin Configuration

- IR Sensor: D1
- Flame Sensor: A0
- LED: D5
- Buzzer: D6
- Servo Motor: D7

## Dependencies

- Servo Library
- ESP8266WiFi Library
- ThingSpeak Library

## Setup

1. **WiFi Configuration:**
   Replace `"YOUR_WIFI_SSID"` and `"YOUR_WIFI_PASSWORD"` in the code with your actual WiFi credentials.

2. **ThingSpeak Configuration:**
   Replace `THINGSPEAK_CHANNEL_ID` in the code with your ThingSpeak channel ID.

## Usage

1. Connect the components based on the provided pin configuration.

2. Upload the code to your Arduino (ESP8266) board.

3. Monitor the serial output to observe the system's behavior.

4. Ensure that the required libraries are installed.

5. Verify that the WiFi connection and ThingSpeak communication are functioning as expected.

## Important Notes

- **Sensor Status:**
  - IR Sensor: 1 (Link not connected) or 0 (Link connected)
  - Flame Sensor: Analog value (Depicting flame intensity)

- **Alarm Activation:**
  - LED and Buzzer: Activated when the link is not connected or fire is detected.

- **Servo Motor:**
  - Brakes applied (servo at 90 degrees) when an issue is detected.

## Contributing

Contributions are welcome! Feel free to open issues and propose improvements.

## License

This project is licensed under the [MIT License](LICENSE).
