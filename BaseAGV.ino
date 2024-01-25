// Include library yang dibutuhkan
#include <MFRC522.h>
#include <Servo.h>
#include <SPI.h>

// Inisialisasi objek servo dan rfid
Servo MyServo;
MFRC522 rfid(53, 49);

#define SCREEN Serial
#define REMOTE Serial1

// Data dari touch screen
int data;

void setup() {
  // Inisialisasi komunikasi serial dan SPI
  SCREEN.begin(9600);  // baud rate layar
  REMOTE.begin(57600); // baud rate receiver remote
  SPI.begin();

  // Inisialisasi modul RFID dan matikan led di arduino mega
  rfid.PCD_Init();
  digitalWrite(LED_BUILTIN, LOW);

  // Inisialisasi perangkat motor driver, ultrasonic, dan servo
  initializeMotor();
  initializeUsonic();
  initializeServo();
}

void loop() {
  // Cek ketersediaan data dari remote
  if (REMOTE.available()) {
    // Ambil data dari remote dan ultrasonic
    getRemoteData();
    getUsonicData();
    // Kontrol robot dari remote
    controlByRemote();
    delay(100);
  } else {
    // Jika tidak ada data dari remote (remote mati)
    if (SCREEN.available()) {
      // Kontrol robot dari layar sentuh
      controlByScreen();
      // Cek apakah ada kartu rfid baru yang terdeteksi
    } else if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
      // Mengirim nilai 1 ke serial yang terhubung pada layar
      SCREEN.println("RFID Detected!");
      SCREEN.write(1);
      SCREEN.flush();
      delay(1500);
      // Jika variabel data memiliki nilai S
    } else if (data == 'S') {
      // Hentikan pergerakan motor robot
      stop();
    }
  }
}
