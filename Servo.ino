void initializeServo() {
  MyServo.attach(SERVO_PIN);
  MyServo.write(0);
  delay(1000);
  MyServo.write(pos);
  delay(1000);
}

void controlByScreen() {
  int data = SCREEN.read();

  if (data == 'L') {
    servoStep(90, 180, true);
    speed = 30;
    rotateLeft();
    delay(100);
    servoStep(180, 90, false);
    data = 'S';
    stop();

  } else if (data == 'R') {
    servoStep(90, 0, false);
    speed = 30;
    rotateRight();
    delay(100);
    servoStep(0, 90, true);
    data = 'S';
    stop();

  } else {
    stop();
  }
}

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