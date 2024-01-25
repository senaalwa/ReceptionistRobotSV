/**
 * @brief Membaca data dari modul remote hingga menemukan karakter newline ('\n').
 * Setelah itu, memanggil fungsi processDataFromSerial() untuk memproses data yang telah diterima.
 * 
 */
void getRemoteData() {
  // Saat data remote tersedia
  while (REMOTE.available()) {
    // Baca data dari remote hingga karakter newline('\n')
    c = REMOTE.read();

    if (c == '\n') {
      break;
    } else {
      data_in += c;
    }
  }
  // Jika terdapat karakter ('\n') proses data yang diterima
  if (c == '\n') {
    processDataFromSerial();
  }
}

/**
 * @brief Memproses data yang diterima dari modul remote. 
 * Data tersebut dipecah menjadi tiga bagian (x, y, dan btn) berdasarkan karakter 'A', 'B', dan 'C'.
 * 
 */
void processDataFromSerial() {
  index_a = data_in.indexOf("A");
  index_b = data_in.indexOf("B");
  index_c = data_in.indexOf("C");

  // Data dipisah menjadi tiga bagian
  x_str = data_in.substring(0, index_a);
  y_str = data_in.substring(index_a + 1, index_b);
  btn_str = data_in.substring(index_b + 1, index_c);

  // Konversi string menjadi integer
  if (x_str.toInt() >= 0 && x_str.toInt() <= 1023) x_value = x_str.toInt();
  if (y_str.toInt() >= 0 && y_str.toInt() <= 1023) y_value = y_str.toInt();
  if (btn_str.toInt() >= 0 && btn_str.toInt() <= 1) btn_state = btn_str.toInt();

  // Reset variabel untuk loop berikutnya
  c = 0;
  data_in = "";
}

/**
 * @brief Mengendalikan pergerakan robot berdasarkan data yang diterima dari modul remote.
 * 
 */
void controlByRemote() {
  /* Cek apakah tombol joystick ditekan
    btn_state==true -> tombol tidak ditekan
    btn_state==false -> tombol ditekan
  */
  if (btn_state) {
    // Posisi joystick netral atau ditengah maka hentikan robot
    if (x_value > 420 && x_value < 600 && y_value > 420 && y_value < 600) {
      stop();
    } else {
      /* Posisi joystick ke atas dan jarak objek dengan ultrasonic di depan >= 40
         maka gerakkan robot maju ke depan */ 
      if (x_value >= 600 && y_value >= 420 && y_value < 600) {
        if (front_distance < 40) {
          stop();
          return;
        }
        speed = map(x_value, 600, 1023, 20, 50);
        forward();
      }
      /* Posisi joystick ke bawah dan jarak objek dengan ultrasonic di belakang >= 40
         maka gerakkan robot mundur ke belakang */ 
      if (x_value < 420 && y_value >= 420 && y_value < 600) {
        if (back_distance < 40) {
          stop();
          return;
        }
        speed = map(x_value, 420, 0, 20, 50);
        backward();
      }
      /* Posisi joystick ke kanan dan jarak objek dengan ultrasonic di kanan >= 40
         maka gerakkan robot bergeser ke kanan */
      if (y_value >= 600 && x_value >= 420 && x_value < 600) {
        if (right_distance < 40) {
          stop();
          return;
        }
        speed = map(y_value, 600, 1023, 10, 35);
        turnRight();
      }
      /* Posisi joystick ke kiri dan jarak objek dengan ultrasonic di kiri >= 40
         maka gerakkan robot bergeser ke kiri */
      if (y_value < 420 && x_value >= 420 && x_value < 600) {
        if (left_distance < 40) {
          stop();
          return;
        }
        speed = map(y_value, 420, 0, 10, 35);
        turnLeft();
      }
    }
  // Posisi tombol di tekan
  } else {
    // Posisi joystick ke kanan maka gerakkan robot berputar ke kanan
    if (y_value >= 600 && x_value >= 420 && x_value < 600) {
      speed = map(y_value, 600, 1023, 10, 40);
      rotateRight();
    }
    // Posisi joystick ke kiri maka gerakkan robot berputar ke kiri
    if (y_value < 420 && x_value >= 420 && x_value < 600) {
      speed = map(y_value, 420, 0, 10, 40);
      rotateLeft();
    }
  }
}