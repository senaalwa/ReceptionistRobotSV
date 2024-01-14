void initializeUsonic() {
  pinMode(TRIGPIN1, OUTPUT);  // KIRI
  pinMode(ECHOPIN1, INPUT_PULLUP);
  pinMode(TRIGPIN2, OUTPUT);  // BELAKANG
  pinMode(ECHOPIN2, INPUT_PULLUP);
  pinMode(TRIGPIN3, OUTPUT);  // DEPAN
  pinMode(ECHOPIN3, INPUT_PULLUP);
  pinMode(TRIGPIN4, OUTPUT);  // KANAN
  pinMode(ECHOPIN4, INPUT_PULLUP);
}

int16_t getDistanceInCm(uint8_t trig_pin, uint8_t echo_pin, bool use_filter) {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH, 26000);
  distance = duration * 0.034 / 2;

  if (use_filter) {
    return filterUsonic(distance);
  }
  return distance;
}

// KALMAN FILTER
int16_t filterUsonic(int16_t U) {
  static const double R = 40;
  static const double H = 1.00;
  static double Q = 10;
  static double P = 0;
  static double U_hat = 0;
  static double K = 0;
  K = P * H / (H * P * H + R);
  U_hat += +K * (U - H * U_hat);
  P = (1 - K * H) * P + Q;
  return U_hat;
}

void getUsonicData() {
  front_distance = getDistanceInCm(TRIGPIN3, ECHOPIN3, false);
  if (getDistanceInCm(TRIGPIN2, ECHOPIN2, true) != 0) back_distance = getDistanceInCm(TRIGPIN2, ECHOPIN2, false);
  if (getDistanceInCm(TRIGPIN4, ECHOPIN4, false) != 0) right_distance = getDistanceInCm(TRIGPIN4, ECHOPIN4, false);
  if (getDistanceInCm(TRIGPIN1, ECHOPIN1, false) != 0) left_distance = getDistanceInCm(TRIGPIN1, ECHOPIN1, false);
}