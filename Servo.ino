/**
 * @brief inisialisasi motor servo, mengatur posisi awal, 
 * dan memberikan delay sebelum melanjutkan eksekusi program.
 * 
 */
void initializeServo() {
  MyServo.attach(SERVO_PIN);
  MyServo.write(pos);
  delay(1000);
}

/**
 * @brief Membaca data dari SCREEN serial dan mengambil tindakan sesuai dengan data yang diterima.
 * 
 */
void controlByScreen() {
  // Baca 1 byte data dari layar
  data = SCREEN.read();

  // Jika data adalah 'L', maka melakukan serangkaian tindakan untuk memutar robot ke kiri dan menggerakkan servo
  if (data == 'L') {
    servoStep(90, 180, true);
    speed = 30;
    rotateLeft();
    delay(250);
    servoStep(180, 90, false);
    data = 'S';
    stop();

  // Jika data adalah 'R', melakukan serangkaian tindakan untuk memutar robot ke kanan dan menggerakkan servo.
  } else if (data == 'R') {
    servoStep(90, 0, false);
    speed = 30;
    rotateRight();
    delay(250);
    servoStep(0, 90, true);
    data = 'S';
    stop();
  }
}

/**
 * @brief Menggerakkan motor servo dari posisi awal ke posisi akhir 
 * dengan menentukan arah (inkremental atau dekremental).
 * 
 * @param awal posisi awal servo
 * @param akhir posisi akhir servo
 * @param is_increment menentukan apakah gerakan servo increment/decrement
 */
void servoStep(int awal, int akhir, bool is_increment) {
  if (is_increment) {
    for (pos = awal; pos <= akhir; pos += 1) {
      MyServo.write(pos);
      delay(10);
    }
  } else {
    for (pos = awal; pos >= akhir; pos -= 1) {
      MyServo.write(pos);
      delay(10);
    }
  }
}