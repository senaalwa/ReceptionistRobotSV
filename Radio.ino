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

  // packing data
  payload[0] = x_value;
  payload[1] = y_value;
  payload[2] = btn_state;

  // pengiriman data
  radio.write(&payload, sizeof(payload));
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