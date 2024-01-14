// STORAGE DATA SERIAL FROM REMOTE
char c;
String data_in, x_str = "", y_str = "", btn_str = "";
int8_t index_a, index_b, index_c;

// ACTUAL DATA TO USE
int16_t x_value, y_value, btn_state;
int16_t speed = 30;

// SERVO CONNECTION
const int8_t SERVO_PIN = 46;
int16_t pos = 90;

// ULTRASONIC CONFIGURATION DATA
int64_t duration;
int16_t distance;
int16_t front_distance, back_distance, right_distance, left_distance; // In CM

// ULTRASONIC PIN
const byte TRIGPIN1 = 10;
const byte ECHOPIN1 = 11;
const byte TRIGPIN2 = 12;
const byte ECHOPIN2 = 13;
const byte TRIGPIN3 = 14;
const byte ECHOPIN3 = 15;
const byte TRIGPIN4 = 16;
const byte ECHOPIN4 = 17;

// DRIVER MOTOR IBT PIN
// Motor KANAN BELAKANG
const byte IN1_M1 = 23;
const byte IN2_M1 = 25;
const byte PWM_M1 = 5;

// Motor KANAN DEPAN
const byte IN1_M2 = 22;
const byte IN2_M2 = 24;
const byte PWM_M2 = 7;

// Motor KIRI DEPAN
const byte IN1_M3 = 28;
const byte IN2_M3 = 29;
const byte PWM_M3 = 8;

// Motor KIRI BELAKANG
const byte IN1_M4 = 26;
const byte IN2_M4 = 27;
const byte PWM_M4 = 6;