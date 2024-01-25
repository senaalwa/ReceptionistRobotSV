/**
 * @brief Inisialisasi NRF sebagai transmitter
 * 
 */
void initializeRadio() {
  radio.begin();
  // Set alamat modul transceiver
  radio.openWritingPipe(address);
  // Set tingkat transmisi, semakin tinggi semakin jauh dapat mentransmisi tp boros daya
  radio.setPALevel(RF24_PA_HIGH);
  // Modul berfungsi sebagai pengirim
  radio.stopListening();
}

/**
 * @brief Mengambil data dari input joystick dan button lalu mengirimkan data melalui NRF24L01
 * 
 */
void getSendData() {
  // membaca input
  x_value = analogRead(X_AXIS);
  y_value = analogRead(Y_AXIS);
  btn_state = digitalRead(BUTTON);
  switchBtnValue();

  // packing data
  payload[0] = x_value;
  payload[1] = y_value;
  payload[2] = btn_state;
  payload[3] = value_mode;

  // pengiriman data
  radio.write(&payload, sizeof(payload));
}

/**
 * @brief Merubah value_mode dari button switch dengan 3 pilihan
 * 
 */
void switchBtnValue() {
  bool switch_pressed = digitalRead(SWITCH);

  // Jika button ditekan
  if (switch_pressed) {
    // Jika value bukan 3 maka increment 1
    if (value_mode != 3) {
      value_mode += 1;
    // Jika 3 kembalikan ke 1
    } else {
      value_mode = 1;
    }
    delay(250);
  }
}

/**
 * @brief Digunakan untuk melihat data yang terkirim melalu serial monitor
 * 
 */
void debugData() {
  Serial.print("X_Axis:");
  Serial.print(x_value);
  Serial.print(",");
  Serial.print("Y_Axis:");
  Serial.print(y_value);
  Serial.print(",");
  Serial.print("State:");
  Serial.println(btn_state);
}