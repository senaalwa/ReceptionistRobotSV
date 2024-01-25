// Include Library
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SoftwareSerial.h>

// Inisialisasi objek radio NRF24L01 dan komunikasi software serial
RF24 radio(8, 10); // CE=8, CSN=10
SoftwareSerial nanoSerial(4, 3); // RX=4 TX=3

void setup() {
  // Mulai komunikasi serial dengan baud 9600
  Serial.begin(9600);
  // Mulai komunikasi software serial dengan baud 57600 untuk perangkat arduino nano
  nanoSerial.begin(57600);
  // Inisialisasi modul radio NRF24L01
  initializeRadio();

  Serial.println("Setup Successfully.");
  delay(3000);
}

void loop() {
  // Menerima data melalui modul NRF24L01
  receivingData();
  // Menampilkan data pada serial monitor
  debugData();

  delay(100);
}
