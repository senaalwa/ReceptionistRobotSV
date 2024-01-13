const byte address[6] = "00001";
int16_t received[3];
int16_t x_value, y_value, btn_state;

/**
 * @brief Inisialisasi NRF sebagai receiver
 * 
 */
void initializeRadio() {
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();
}

/**
 * @brief Menerima data dari transmitter remote-tx dan mengirimkan kembali melalu serial
 * 
 */
void receivingData() {
  if (radio.available()) {
    radio.read(&received, sizeof(received));
    x_value = received[0];
    y_value = received[1];
    btn_state = received[2];

    sendDataViaSS();
  }
}

/**
 * @brief Konfigurasi pengiriman data via serial
 * 
 */
void sendDataViaSS() {
  nanoSerial.print(x_value);
  nanoSerial.print("A");
  nanoSerial.print(y_value);
  nanoSerial.print("B");
  nanoSerial.print(btn_state);
  nanoSerial.print("C");
  nanoSerial.print("\n");
}

/**
 * @brief Digunakan untuk melihat data yang diterima melalu serial monitor
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