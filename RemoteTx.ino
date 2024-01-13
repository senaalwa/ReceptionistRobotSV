#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DESTRUCT OBJECT NRF DAN LCD I2C
RF24 radio(7, 8);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  initializeMode();
  initializeRadio();
  initializeScreen();

  Serial.println("Setup Successfully.");
  delay(3000);
}

void loop() {
  getSendData();
  displayData();
  debugData();

  delay(100);
}
