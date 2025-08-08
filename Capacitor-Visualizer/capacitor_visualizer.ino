const int chargePin = 4;
const int dischargePin = 7;
const int sensePin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(chargePin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    // === CHARGE ===
    digitalWrite(chargePin, HIGH);
    pinMode(dischargePin, INPUT);  // Set to high-Z (floating)

    while (analogRead(sensePin) < 1010) {
      float voltage = analogRead(sensePin) * (5.0 / 1023.0);
      Serial.println(voltage);
      delay(500);
    }

    // === DISCHARGE ===
    digitalWrite(chargePin, LOW);
    pinMode(dischargePin, OUTPUT);
    digitalWrite(dischargePin, LOW);  // Pull to GND

    while (analogRead(sensePin) > 10) {
      float voltage = analogRead(sensePin) * (5.0 / 1023.0);
      Serial.println(voltage);
      delay(50000);
    }
  }

  // === STOP HERE AFTER 3 CYCLES ===
  while (true);  // Infinite stop
}