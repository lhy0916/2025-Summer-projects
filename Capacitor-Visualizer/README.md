# Capacitor Charge/Discharge Visualizer

**Description:**  
An Arduino-based RC circuit visualization project that measures and plots the voltage across a capacitor during charge and discharge cycles.

## Hardware
- Arduino Uno R3
- Electrolytic capacitors (100µF, 470µF)
- Resistors (10kΩ)
- Breadboard + jumper wires
- Pushbutton
- USB cable for Arduino

## Wiring
| Component        | Arduino Pin |
|------------------|-------------|
| Capacitor + lead | A0          |
| Pushbutton       | Digital 2   |
| Resistor         | Between 5V and capacitor |
| GND connections  | GND         |

## Setup
- Install Arduino IDE
- Connect Arduino via USB
- Upload `src/main.ino`

## How to Run
1. Open Serial Monitor at 9600 baud.
2. Press pushbutton to start charging/discharging.
3. Record voltage readings or plot in Python.

## Notes
- Use Python for live plotting.
- Adjust resistor/capacitor values for different time constants.
