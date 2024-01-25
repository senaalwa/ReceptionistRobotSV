/**
 * @brief Inisialiasi pin IN1,IN2,PWM sebagai output untuk mengendalikan motor
 * 
 */
void initializeMotor() {
  pinMode(IN1_M1, OUTPUT);
  pinMode(IN2_M1, OUTPUT);
  pinMode(PWM_M1, OUTPUT);
  pinMode(IN1_M2, OUTPUT);
  pinMode(IN2_M2, OUTPUT);
  pinMode(PWM_M2, OUTPUT);
  pinMode(IN1_M3, OUTPUT);
  pinMode(IN2_M3, OUTPUT);
  pinMode(PWM_M3, OUTPUT);
  pinMode(IN1_M4, OUTPUT);
  pinMode(IN2_M4, OUTPUT);
  pinMode(PWM_M4, OUTPUT);
}

//! RIGHT SIDE => (HIGH, LOW, clockwise): true, (LOW, HIGH, !clockwise): false
//! LEFT SIDE => (HIGH, LOW, !clockwise): false, (LOW, HIGH, clockwise): true

/**
 * @brief Menggerakkan robot agar maju
 * 
 */
void forward() {
  runRightBackward(true, speed);
  runRightForward(true, speed);
  runLeftBackward(false, speed);
  runLeftForward(false, speed);
}

/**
 * @brief Menggerakkan robot agar mundur
 * 
 */
void backward() {
  runRightBackward(false, speed);
  runRightForward(false, speed);
  runLeftBackward(true, speed);
  runLeftForward(true, speed);
}

/**
 * @brief Menggerakkan robot agar bergeser ke kanan
 * 
 */
void turnRight() {
  runRightBackward(true, speed);
  runRightForward(false, speed);
  runLeftForward(false, speed);
  runLeftBackward(true, speed);
}

/**
 * @brief Menggerakkan robot agar bergeser ke kiri
 * 
 */
void turnLeft() {
  runRightBackward(false, speed);
  runRightForward(true, speed);
  runLeftForward(true, speed);
  runLeftBackward(false, speed);
}

/**
 * @brief Menggerakkan robot agar berputar ke kanan
 * 
 */
void rotateRight() {
  runRightBackward(true, speed);
  runRightForward(true, speed);
  runLeftForward(true, speed);
  runLeftBackward(true, speed);
}

/**
 * @brief Menggerakkan robot agar berputar ke kiri
 * 
 */
void rotateLeft() {
  runRightBackward(false, speed);
  runRightForward(false, speed);
  runLeftForward(false, speed);
  runLeftBackward(false, speed);
}

/**
 * @brief Menghentikan pergerakan robot
 * 
 */
void stop() {
  digitalWrite(IN1_M1, LOW);
  digitalWrite(IN2_M1, LOW);
  digitalWrite(IN1_M2, LOW);
  digitalWrite(IN2_M2, LOW);
  digitalWrite(IN1_M3, LOW);
  digitalWrite(IN2_M3, LOW);
  digitalWrite(IN1_M4, LOW);
  digitalWrite(IN2_M4, LOW);
  analogWrite(PWM_M1, 0);
  analogWrite(PWM_M2, 0);
  analogWrite(PWM_M3, 0);
  analogWrite(PWM_M4, 0);
}

/**
 * @brief Menggerakkan motor kiri depan
 * 
 * @param is_clockwise arah putaran motor (searah jarum jam/tidak)
 * @param velocity kecepatan motor (0 - 255)
 */
void runLeftForward(bool is_clockwise, uint8_t velocity) {
  if (!is_clockwise) {
    digitalWrite(IN1_M3, HIGH);
    digitalWrite(IN2_M3, LOW);
  }
  if (is_clockwise) {
    digitalWrite(IN1_M3, LOW);
    digitalWrite(IN2_M3, HIGH);
  }
  analogWrite(PWM_M3, velocity);
}

/**
 * @brief Menggerakkan motor kiri belakang
 * 
 * @param is_clockwise arah putaran motor (searah jarum jam/tidak)
 * @param velocity kecepatan motor (0 - 255)
 */
void runLeftBackward(bool is_clockwise, uint8_t velocity) {
  if (!is_clockwise) {
    digitalWrite(IN1_M4, HIGH);
    digitalWrite(IN2_M4, LOW);
  }
  if (is_clockwise) {
    digitalWrite(IN1_M4, LOW);
    digitalWrite(IN2_M4, HIGH);
  }
  analogWrite(PWM_M4, velocity);
}

/**
 * @brief Menggerakkan motor kanan depan
 * 
 * @param is_clockwise arah putaran motor (searah jarum jam/tidak)
 * @param velocity kecepatan motor (0 - 255)
 */
void runRightBackward(bool is_clockwise, uint8_t velocity) {
  if (!is_clockwise) {
    digitalWrite(IN1_M1, LOW);
    digitalWrite(IN2_M1, HIGH);
  }
  if (is_clockwise) {
    digitalWrite(IN1_M1, HIGH);
    digitalWrite(IN2_M1, LOW);
  }
  analogWrite(PWM_M1, velocity);
}

/**
 * @brief Menggerakkan motor kanan belakang
 * 
 * @param is_clockwise arah putaran motor (searah jarum jam/tidak)
 * @param velocity kecepatan motor (0 - 255)
 */
void runRightForward(bool is_clockwise, uint8_t velocity) {
  if (!is_clockwise) {
    digitalWrite(IN1_M2, LOW);
    digitalWrite(IN2_M2, HIGH);
  }
  if (is_clockwise) {
    digitalWrite(IN1_M2, HIGH);
    digitalWrite(IN2_M2, LOW);
  }
  analogWrite(PWM_M2, velocity);
}