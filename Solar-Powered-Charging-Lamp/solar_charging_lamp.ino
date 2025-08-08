#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Replace 0x27 with 0x3F if your LCD uses a different address
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin assignments
const int ledControlPin = 3;  
const int batteryPin = A0;    // Reads voltage divider from TP4056 B+
const int ldrPin = A1;        // Reads LDR

// Configuration
const float vcc = 4.98;               // Measured Arduino VCC
const float dividerRatio = 2.0;       // For 10k + 10k voltage divider
const float minBatteryVoltage = 3.0;  // Battery empty
const float maxBatteryVoltage = 4.2;  // Battery full
const int lightThreshold = 800;       // Adjust based on your lighting

void setup() {
  pinMode(ledControlPin, OUTPUT);
  digitalWrite(ledControlPin, LOW);

  lcd.begin(16, 2);
  lcd.backlight();

  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Smart Solar Lamp");
  delay(1500);
  lcd.clear();
}

void loop() {
  // ----------- Read Battery Voltage -----------
  int batteryADC = analogRead(batteryPin);
  float measuredVoltage = (batteryADC / 1023.0) * vcc * dividerRatio;
  int batteryPercent = (measuredVoltage - minBatteryVoltage) / (maxBatteryVoltage - minBatteryVoltage) * 100;
  batteryPercent = constrain(batteryPercent, 0, 100);

  // ----------- Read Light Level -----------
  int ldrValue = analogRead(ldrPin);
  bool isDark = ldrValue < lightThreshold;

  // ----------- LED Control Logic -----------
  bool batteryOK = measuredVoltage > 3.3;

  if (isDark && batteryOK) {
    digitalWrite(ledControlPin, HIGH);  // Lamp ON
  } else {
    digitalWrite(ledControlPin, LOW);   // Lamp OFF
  }

  // ----------- Serial Monitor Debugging -----------
  Serial.print("Battery Voltage: ");
  Serial.print(measuredVoltage);
  Serial.print(" V | %: ");
  Serial.print(batteryPercent);
  Serial.print(" | LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Lamp: ");
  Serial.println((isDark && batteryOK) ? "ON" : "OFF");

  // ----------- LCD Output -----------
  lcd.setCursor(0, 0);
  lcd.print("Battery: ");
  lcd.print(batteryPercent);
  lcd.print("%   ");  // Clear trailing chars

  lcd.setCursor(0, 1);
  if (!batteryOK) {
    lcd.print("Low Power Mode   ");
  } else if (isDark) {
    lcd.print("Lamp: ON         ");
  } else {
    lcd.print("Lamp: OFF        ");
  }

  delay(1000);}