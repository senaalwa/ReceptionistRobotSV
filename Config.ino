// JOYSTICK PIN
#define X_AXIS A12
#define Y_AXIS A14
#define BUTTON 32

// LED SETUP
#define LED_1 29
#define LED_2 31

// NRF24L01 SETUP
const byte address[6] = "00001";
int16_t payload[3];
int16_t x_value, y_value, btn_state;

/**
 * @brief Inisialisasi pinMode pada tiap komponen dan melakukan setup awal
 * 
 */
void initializeMode() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);

  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);
}