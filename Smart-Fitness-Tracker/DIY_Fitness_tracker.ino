#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MPU6050_light.h>

// LCD & MPU setup
LiquidCrystal_I2C lcd(0x27, 16, 2);
MPU6050 mpu(Wire);

// Vibration & LED pins
const int vibPin = 2;
const int ledPin = 6;

// Vibration latch
bool vibrationLatch = false;
unsigned long lastVibTime = 0;
const unsigned long debounceDelay = 200;   // ms
const unsigned long latchDuration = 1000;  // ms

// LCD update timing
unsigned long lastUpdate = 0;
const unsigned long updateInterval = 500; // ms

void setup() {
  Serial.begin(9600);

  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");

  // MPU
  Wire.begin();
  if (mpu.begin() != 0) {
    lcd.clear();
    lcd.print("MPU ERROR!");
    while (1); // Stop if MPU not found
  }
  mpu.calcOffsets(true, true);
  delay(500);
  lcd.clear();

  // Pins
  pinMode(vibPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  mpu.update();
  delay(10); // Smooth readings

  // Vibration detection with debounce
  if (digitalRead(vibPin) == LOW && millis() - lastVibTime > debounceDelay) {
    vibrationLatch = true;
    lastVibTime = millis();
  }
  if (vibrationLatch && millis() - lastVibTime > latchDuration) {
    vibrationLatch = false;
  }

  // LED follows vibration latch
  digitalWrite(ledPin, vibrationLatch ? HIGH : LOW);

  // LCD update
  if (millis() - lastUpdate >= updateInterval) {
    lastUpdate = millis();

    lcd.setCursor(0, 0);
    lcd.print("P:");
    lcd.print(mpu.getAngleX(), 1); // 1 decimal place
    lcd.print(" R:");
    lcd.print(mpu.getAngleY(), 1);
    lcd.print("   "); // Clear leftovers

    lcd.setCursor(0, 1);
    lcd.print("V:");
    lcd.print(vibrationLatch ? "Y" : "N");
    lcd.print("        ");
  }
}