#include <ArduinoBLE.h>

// Define the BLE Service and Characteristic UUIDs
// You will use these exact UUIDs in your MIT App Inventor project
const char* serviceUuid = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
const char* characteristicUuid = "beb5483e-36e1-4688-b7f5-ea07361b26a8";

const int ledPin = 2; // The pin your LED is connected to

// Create the BLE Characteristic
BLEUnsignedCharCharacteristic ledCharacteristic(characteristicUuid, BLERead | BLEWrite);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Initialize the BLE hardware
  if (!BLE.begin()) {
    Serial.println("Starting BLE failed!");
    while (1);
  }

  // Set the name your phone will see when scanning
  BLE.setLocalName("ESP32-LED");
  BLE.setAdvertisedServiceUuid(serviceUuid);

  // Add the characteristic to the service
  BLE.addService(serviceUuid);
  BLE.addCharacteristic(ledCharacteristic);

  // Set an initial value
  ledCharacteristic.writeValue(0);

  // Start advertising so the phone can find it
  BLE.advertise();

  Serial.println("BLE LED Peripheral is now advertising...");
}

void loop() {
  // Wait for a Bluetooth Low Energy central (your phone) to connect
  BLEDevice central = BLE.central();

  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    // While the phone is connected, check if the characteristic was written to
    while (central.connected()) {
      if (ledCharacteristic.written()) {
        uint8_t value = ledCharacteristic.value();
        Serial.print("Received value: ");
        Serial.println(value);

        if (value == 1) {
          digitalWrite(ledPin, HIGH);
        } else {
          digitalWrite(ledPin, LOW);
        }
      }
    }

    Serial.println("Disconnected from central.");
  }
}