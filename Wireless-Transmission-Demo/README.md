# Wireless Transmission Demo (RF433 Weather Monitoring System)

## Overview
This project is a wireless environmental monitoring system built with **Arduino microcontrollers**, an **RF433 transmitter-receiver module**, and a **DHT11 temperature and humidity sensor**.  
The **transmitter Arduino** collects live environmental data and sends it wirelessly to the **receiver Arduino** using the **RadioHead ASK** protocol. A custom packet format was designed to include both sensor readings and a timestamp, enabling synchronized data transmission and verification.

---

## Features
- 📡 **Wireless RF433 Transmission** of sensor readings
- 🌡 **Real-Time Temperature & Humidity Monitoring** with DHT11 sensor
- ⏱ **Timestamped Data Packets** for synchronization
- 🔌 **Terminal-Based Output** via Arduino Serial Monitor
- 🔧 **Custom Encoding & Parsing Protocol**
- 💡 Includes LED status indicators for transmission events

---

## Hardware Requirements
- 2 × Arduino Uno (or compatible boards)
- 1 × RF433 Transmitter module
- 1 × RF433 Receiver module
- 1 × DHT11 Temperature & Humidity sensor
- Resistors (e.g., 220 Ω for LEDs)
- LEDs (for status indication)
- Breadboard and jumper wires
- USB cables for both Arduinos

---

## Software Requirements
- Arduino IDE
- Required libraries:
  - `Bonezegei_DHT11.h` *(for DHT11 sensor handling)*
  - `RH_ASK.h` *(for RadioHead ASK protocol)*
  - `SPI.h` *(required by RadioHead library)*

Install libraries via Arduino IDE’s **Library Manager** or manually:
1. Go to **Sketch → Include Library → Manage Libraries…**
2. Search for and install:
   - **Bonezegei_DHT11**
   - **RadioHead**

---

## How It Works
1. **Data Collection**  
   The transmitter Arduino reads temperature and humidity values from the DHT11 sensor.
2. **Data Packaging**  
   Readings are combined with a timestamp and encoded into a compact string format.
3. **Wireless Transmission**  
   The data packet is sent via the RF433 transmitter using the RadioHead ASK protocol.
4. **Reception & Decoding**  
   The receiver Arduino, equipped with the RF433 receiver, listens for incoming packets, decodes them, and outputs the results via the Serial Monitor.
5. **LED Indicators**  
   LEDs are used to signal when data is being sent or successfully received.

---

## Usage
1. **Clone the Repository**:
2. **Upload Transmitter Code** to the first Arduino (transmitter.ino)
3. **Upload Receiver Code** to the second Arduino (receiver.ino
4. **Connect Hardware** according to the wiring diagram (see wiring_diagram.png)
5. **Open Serial Monitor** on the receiver Arduino at 9600 baud to view incoming data.

## Example output
[2025-08-07 15:12:45] Temp: 23.40 °C | Humidity: 56.0 %
[2025-08-07 15:12:55] Temp: 23.42 °C | Humidity: 55.9 %
[2025-08-07 15:13:05] Temp: 23.45 °C | Humidity: 56.1 %

## Lessons Learned
- Integrating sensors with wireless communication modules.
- Designing a simple but effective custom data protocol.
- Understanding timing synchronization between microcontrollers.
- Troubleshooting RF transmission failures due to:
- Power regulation issues
- Loose breadboard connections
- Electrical interference
- Using LED indicators for real-time hardware debugging.
