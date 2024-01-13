/**
 * @brief Inisialisasi NRF sebagai transmitter
 * 
 */
void initializeRadio() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
}

/**
 * @brief Mengambil data dari input joystick dan button lalu mengirimkan data melalui NRF
 * 
 */
void getSendData() {
  x_value = analogRead(X_AXIS);
  y_value = analogRead(Y_AXIS);
  btn_state = digitalRead(BUTTON);

  payload[0] = x_value;
  payload[1] = y_value;
  payload[2] = btn_state;

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