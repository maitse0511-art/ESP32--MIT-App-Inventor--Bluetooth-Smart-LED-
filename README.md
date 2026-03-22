# ESP32--MIT-App-Inventor--Bluetooth-Smart-LED-
A complete IoT project demonstrating Bluetooth Classic communication between ESP32 microcontroller and Android smartphone. Includes ESP32 Arduino code and MIT App Inventor project files. Perfect for beginners learning Bluetooth control, IoT basics, and Android app development without coding
 Features

- 🔵 Bluetooth Classic communication
- 📱 Custom Android app built with visual programming
- 💡 Simple ON/OFF LED control
- 🔌 Easy to extend for multiple devices
- 📚 Perfect for beginners learning IoT

Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) (with ESP32 board support)
- [MIT App Inventor](http://ai2.appinventor.mit.edu/) account (free)
- Android device (phone/tablet) running Android 4.4+

- **Simple Circuit:**
- ESP32 GPIO 2 → 220Ω Resistor → LED Anode (+)
- ESP32 GND → LED Cathode (-)

# MIT App Inventor Guide
# Step 1: Create Project
Visit MIT App Inventor

Click "Start new project"
Name it ESP32_LED_Control

# Step 2: Design View
Add these components to your app:

Component	Palette Section	Name	Purpose
BluetoothClient	Connectivity	BluetoothClient1	Bluetooth connection
ListPicker	User Interface	DeviceListPicker	Select ESP32 device
Button	User Interface	ConnectButton	Connect to ESP32
Button	User Interface	BtnON	Turn LED ON
Button	User Interface	BtnOFF	Turn LED OFF
Label	User Interface	StatusLabel	Show connection status

# Step 3: Blocks (Programming Logic)
Connect Button:
text
When ConnectButton.Click
  Call DeviceListPicker.GetAddressesAndNames
  Set DeviceListPicker.Elements to get AddressesAndNames
Device Selection:

text
When DeviceListPicker.AfterPicking
  Call BluetoothClient1.Connect address: DeviceListPicker.Selection
  Set StatusLabel.Text to "Connected to: " + DeviceListPicker.Selection
LED Control:

text
When BtnON.Click
  Call BluetoothClient1.SendText text: "1"
  Set StatusLabel.Text to "LED is ON"

When BtnOFF.Click
  Call BluetoothClient1.SendText text: "0"
  Set StatusLabel.Text to "LED is OFF"

# Step 4: Build APK
Click "Build" in the top menu

Select "Android App (.apk)"

Download and install on your Android device

🚀 Getting Started
Quick Start Guide
 Hardware Setup
Connect LED to ESP32 (GPIO 2 + resistor)
Power ESP32 via USB

 Program ESP32
Upload Arduino code to ESP32
Open Serial Monitor to verify

 Pair Devices
Phone Settings → Bluetooth
Scan for "ESP32-Bluetooth"
Tap to pair

📱 Install & Use App
Install APK on Android
Open app and tap "Connect"
Select paired ESP32
Press ON/OFF to control LED

# Future Improvements:
Control multiple LEDs/RGB LED
Add brightness control (PWM)
Display sensor data (temperature, humidity)
Add password protection
Voice control integration
Widget for quick access
Support multiple ESP32 devices
Add servo motor control
Implement reconnect on app launch
