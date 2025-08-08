# Smart Solar Powered Lamp

## Overview
This project is a fully self-sustaining solar-powered lighting system built with **Arduino**, designed to operate autonomously for off-grid use.  
It uses a **5V solar panel** for energy harvesting, a **TP4056 lithium battery charging module** for battery management, and an **MT3608 boost converter** to ensure consistent power output for the microcontroller and connected components.

---

## Features
- ☀️ **Solar Energy Harvesting** with automatic battery charging
- 🔋 **Li-ion Battery Storage** for night-time operation
- 📟 **Real-Time Status Display** on 16x2 I2C LCD
- 🌗 **Automatic Light Control** using an LDR (Light Dependent Resistor)
- 📊 **Battery Voltage Monitoring** via voltage divider
- ⚡ **Boost Converter Integration** for stable output voltage
- 🛠 Autonomous system with low-power conservation mode

---

## Hardware Requirements
- Arduino Uno (or compatible board)
- 5V solar panel
- TP4056 lithium battery charging module
- 3.7V Li-ion battery
- MT3608 boost converter
- LDR (photoresistor)
- Resistors for voltage divider (e.g., 10kΩ, 4.7kΩ)
- 16x2 I2C LCD display module
- LED lamp module or high-power LED
- Breadboard and jumper wires

---

## Software Requirements
- Arduino IDE
- Required libraries:
  - `LiquidCrystal_I2C.h`
  - `Wire.h`

---

## How It Works
1. **Solar Charging**  
   The 5V solar panel charges the 3.7V Li-ion battery through the TP4056 module.
2. **Voltage Boosting**  
   The MT3608 boost converter raises the voltage to the required level for the Arduino and LED lamp.
3. **Battery Monitoring**  
   A voltage divider feeds battery voltage to an Arduino analog pin, allowing the system to calculate battery percentage.
4. **Ambient Light Detection**  
   An LDR, connected via a resistor voltage divider, measures light intensity.
5. **Automatic Lamp Control**  
   - Lamp turns **on** when ambient light is below the set threshold **and** battery voltage is above 3.3V.
   - Lamp stays **off** in daylight or if the battery is too low, to conserve energy.
6. **LCD Display**  
   Displays battery voltage, battery percentage, and system status in real time.

---

## Usage
1. **Clone the Repository**
2. **Upload the Code** to your Arduino
3. **Connect Components**
4. **Place in Sunlight** for charging and let the system run autonomously

## Example Output (LCD)
Battery: 4.08V
Charge: 85%
Status: Lamp OFF


(Values update in real-time depending on light and battery level.)

## Lessons Learned
- Integrating solar charging modules with boost converters.
- Using analog voltage dividers for real-time measurement.
- Implementing automated decision logic for power conservation.
- Combining energy harvesting and embedded control for autonomous systems.
- Soldering connections

