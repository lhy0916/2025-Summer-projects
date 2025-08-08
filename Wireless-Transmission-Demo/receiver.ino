#include <RH_ASK.h>
#include <SPI.h>

#define LED_PIN 7

RH_ASK driver(1000, 11, 12);  // 1000 bps, Rx on pin 11, Tx not used

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  
  if (!driver.init()) {
    Serial.println("Receiver init failed");
  } else {
    Serial.println("Receiver ready");
  }
}

void loop() {
  if (driver.available()) {
    uint8_t buf[64];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) {
      buf[buflen] = '\0';  // Null-terminate string

      String receivedMsg = String((char*)buf);
      Serial.print("Received: ");
      Serial.println(receivedMsg);  // This should match the "timestamp,temperature,humidity" format

      // Optional: parse and display values on Serial Monitor
      int firstComma = receivedMsg.indexOf(',');
      int secondComma = receivedMsg.indexOf(',', firstComma + 1);

      if (firstComma > 0 && secondComma > firstComma) {
        String timeStr = receivedMsg.substring(0, firstComma);
        String tempStr = receivedMsg.substring(firstComma + 1, secondComma);
        String humStr  = receivedMsg.substring(secondComma + 1);

        Serial.print("Parsed Time (ms): ");
        Serial.println(timeStr);
        Serial.print("Parsed Temp (°C): ");
        Serial.println(tempStr);
        Serial.print("Parsed Humidity (%): ");
        Serial.println(humStr);
      }
    }
  }
}