#include <Bonezegei_DHT11.h>
#include <RH_ASK.h>
#include <SPI.h>

#define DHTPIN 2
#define LEDPIN 7
#define TXPIN 12  // 433 MHz data pin

Bonezegei_DHT11 dht(DHTPIN);
RH_ASK driver(1000, 11, 12); // 1000bps, default Rx=-11, Tx=12

void setup() {
  Serial.begin(9600);
  dht.begin();
  driver.init();
  pinMode(LEDPIN, OUTPUT);
  if (!driver.init()) {
    Serial.println("Transmitter init failed");
  } else {
    Serial.println("Transmitter ready");}
}

void loop() {
  if (dht.getData()) {
    float temperature = dht.getTemperature();
    float humidity = dht.getHumidity();       // <-- Added humidity
    unsigned long timestamp = millis();

    char msg[64];
    // Format: timestamp,temperature,humidity
    sprintf(msg, "%lu,%.2f,%.2f", timestamp, temperature, humidity);

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);

    Serial.println(msg);  // Prints: 2548931,23.10,45.80

    digitalWrite(LEDPIN, HIGH);
    delay(200);
    digitalWrite(LEDPIN, LOW);
  } else {
    Serial.println("DHT Read Failed");
  }

  delay(2000);  // Wait 2 seconds
}