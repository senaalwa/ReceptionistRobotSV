// Include library
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi object NRF24L01 dan LCD
RF24 radio(7, 8); // CE=7, CSN=8
LiquidCrystal_I2C lcd(0x27, 16, 2); // Addr, Col, Row

void setup() {
  // Buka komunikasi serial dengan baud rate 9600
  Serial.begin(9600);

  // Inisialisai perangkat radio nrf dan lcd i2c
  initializeMode();
  initializeRadio();
  initializeScreen();

  Serial.println("Setup Successfully.");
  delay(3000);
}

void loop() {
  // Ambil data dari joystick, button dan mengirim melalui NRF24L01
  getSendData();
  // Menampilkan data pada LCD
  displayData();
  // Menampilkan data pada serial monitor
  debugData();

  delay(100);
}
