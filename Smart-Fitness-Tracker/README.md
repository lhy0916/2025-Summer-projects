# DIY Fitness Tracker (Motion & Vibration Monitoring System)

## Overview
This proof-of-concept project integrates **motion sensing** and **vibration detection** into a single Arduino-based system for exercise and movement tracking.  
Built with an **Arduino Uno**, **MPU6050 motion sensor**, **SW-18010P vibration switch**, **16x2 I²C LCD**, and an **LED indicator**, the system measures and displays pitch and roll in real time while detecting vibration events that trigger both visual and display feedback.

The design demonstrates the integration of multiple sensors over a shared I²C bus, with **vibration event latching** and **debounce logic** implemented to ensure accurate triggering.

---

## Features
- 📐 **Real-Time Pitch & Roll Measurement** with MPU6050
- 📳 **Vibration Detection** with latch and debounce filtering
- 💡 **LED Indicator** triggered on vibration events
- 📟 **16x2 I²C LCD** real-time display
- 🔄 **Sensor Integration** over shared I²C bus
- 🛠 Adaptable for fitness tracking, rep counting, sports analysis, and industrial monitoring

---

## Hardware Requirements
- Arduino Uno (or compatible)
- MPU6050 6-axis accelerometer & gyroscope module
- SW-18010P vibration switch
- 16x2 I²C LCD display module
- LED
- Resistors (for LED current limiting)
- Breadboard and jumper wires
- Power source (USB recommended for stability during prototype phase)

---

## Software Requirements
- Arduino IDE
- Required libraries:
  - `Wire.h` (built-in)
  - `LiquidCrystal_I2C.h`
  - `MPU6050_light.h`

---

## How It Works
1. **Motion Sensing**  
   The MPU6050 measures pitch and roll angles in real time, sending the data to the Arduino via I²C.
2. **Vibration Detection**  
   The SW-18010P vibration switch detects impacts. The system uses a **debounce delay** to avoid false triggers and a **latch mechanism** to keep the LED on briefly after detection.
3. **Display Updates**  
   The LCD continuously displays the pitch and roll angles. On vibration events, it switches to show a "vibration detected" message alongside LED activation.
4. **Power Considerations**  
   USB power provided more stable voltage and eliminated sensor dropouts compared to using a boost converter and battery during the breadboard phase.

---

## Usage
1. **Clone the Repository**:
2. **Upload the Code** to your Arduino
3. **Connect Components**
4. **Run the system** and tilt and shake the sensor to see real-time pitch/roll updates and vibration event triggers

## Example Ouput (LCD)
P: -8.0  R: 0.1

V: ON

(Pitch, roll, and vibration status update dynamically.)

## Lessons Learned
- Challenges of power stability in breadboard prototypes.
- Differences between prototype builds and portable ruggedized systems.
- Potential adaptations for: Rep counting & form tracking in gym equipment, Sports motion analysis, Vibration monitoring for machinery maintenance
