#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SoftwareSerial.h>

RF24 radio(8, 10);
SoftwareSerial nanoSerial(4, 3);

void setup() {
  Serial.begin(9600);
  nanoSerial.begin(57600);
  initializeRadio();

  Serial.println("Setup Successfully.");
  delay(3000);
}

void loop() {
  receivingData();
  debugData();

  delay(100);
}
