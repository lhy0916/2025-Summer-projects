# Arduino-Controlled Dual V8 Engine Demonstrator

This project demonstrates **embedded motor control + mechanical coupling** using two LEGO-compatible V8 engine models.  
An Arduino Uno, L298N motor driver, and dual 3.7 V Li-ion battery pack control the primary engine.  
A second engine is linked via a direct shaft connection, running passively through torque transfer.

## 🔧 Features
- **Throttle control** via potentiometer (PWM speed regulation)
- **Start/Stop button** with software debounce
- **10-second timed run** (automatic cycle)
- **Dual-engine synchronization** with rigid shaft linkage
- **Power delivery** using 2× 3.7 V Li-ion cells in series (~7.4 V)

## 📷 System Overview
- Arduino Uno controls motor driver (L298N)  
- Potentiometer = adjustable throttle  
- Button D2 = Start/Stop  
- Button D4 = Timed 10-second run  
- LEGO engine A = driven by Arduino system  
- LEGO engine B = runs passively through torque transfer  

![Dual Engine Setup](final-setup.jpg)

## 🖥️ Wiring
- ENA → D5  
- IN1 → D8  
- IN2 → D9  
- Potentiometer → A0  
- Button D2 → GND (Start/Stop)  
- Button D4 → GND (Timed Run)  
- Motor → OUT1, OUT2 on L298N  
- Batteries (2× 3.7 V in series) → +12V, GND on L298N


## 💻 Code
See [Arduino_Controlled_Dual_V8_Engine_Demostrator.ino](Arduino_Controlled_Dual_V8_Engine_Demostrator.ino) for the Arduino sketch.

```cpp
// Example snippet
int ENA = 5, IN1 = 8, IN2 = 9;
...
analogWrite(ENA, pwm); // control speed
