void getRemoteData() {
  while (REMOTE.available()) {
    c = REMOTE.read();

    if (c == '\n') {
      break;
    } else {
      data_in += c;
    }
  }

  if (c == '\n') {
    processDataFromSerial();
  }
}

void processDataFromSerial() {
  index_a = data_in.indexOf("A");
  index_b = data_in.indexOf("B");
  index_c = data_in.indexOf("C");

  x_str = data_in.substring(0, index_a);
  y_str = data_in.substring(index_a + 1, index_b);
  btn_str = data_in.substring(index_b + 1, index_c);

  if (x_str.toInt() >= 0 && x_str.toInt() <= 1023) x_value = x_str.toInt();
  if (y_str.toInt() >= 0 && y_str.toInt() <= 1023) y_value = y_str.toInt();
  if (btn_str.toInt() >= 0 && btn_str.toInt() <= 1) btn_state = btn_str.toInt();

  c = 0;
  data_in = "";
}

void controlByRemote() {
  if (btn_state) {
    if (x_value > 420 && x_value < 600 && y_value > 420 && y_value < 600) {
      stop();
    } else {
      if (x_value >= 600 && y_value >= 420 && y_value < 600) {
        if (front_distance < 40) {
          stop();
          return;
        }
        speed = map(x_value, 600, 1023, 20, 50);
        forward();
      }
      if (x_value < 420 && y_value >= 420 && y_value < 600) {
        if (back_distance < 40) {
          stop();
          return;
        }
        speed = map(x_value, 420, 0, 20, 50);
        backward();
      }
      if (y_value >= 600 && x_value >= 420 && x_value < 600) {
        if (right_distance < 40) {
          stop();
          return;
        }
        speed = map(y_value, 600, 1023, 10, 35);
        turnRight();
      }
      if (y_value < 420 && x_value >= 420 && x_value < 600) {
        if (left_distance < 40) {
          stop();
          return;
        }
        speed = map(y_value, 420, 0, 10, 35);
        turnLeft();
      }
    }
  } else {
    if (y_value >= 600 && x_value >= 420 && x_value < 600) {
      speed = map(y_value, 600, 1023, 10, 40);
      rotateRight();
    }
    if (y_value < 420 && x_value >= 420 && x_value < 600) {
      speed = map(y_value, 420, 0, 10, 40);
      rotateLeft();
    }
  }
}