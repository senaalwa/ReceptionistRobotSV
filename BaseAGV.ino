#include <Servo.h>
#include <SPI.h>

Servo MyServo;

#define SCREEN Serial
#define REMOTE Serial1

void setup() {
  SCREEN.begin(9600);
  REMOTE.begin(57600);
  SPI.begin();

  initializeMotor();
  initializeUsonic();
  initializeServo();
}

void loop() {
  if (REMOTE.available()) {
    getRemoteData();
    getUsonicData();
    controlByRemote();
    delay(100);
  } else {
    if (SCREEN.available()) {
      controlByScreen();
    }
  }
}
