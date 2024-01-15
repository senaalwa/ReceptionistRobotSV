#include <MFRC522.h>
#include <Servo.h>
#include <SPI.h>

Servo MyServo;
MFRC522 rfid(53, 49);

#define SCREEN Serial
#define REMOTE Serial1

// Screen Test
int data;

void setup() {
  SCREEN.begin(9600);
  REMOTE.begin(57600);
  SPI.begin();
  rfid.PCD_Init();
  digitalWrite(LED_BUILTIN, LOW);

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
    } else if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
      SCREEN.println("RFID Detected!");
      SCREEN.write(1);
      SCREEN.flush();
      delay(1500);
    } else if (data == 'S') {
      stop();
    }
  }
}
