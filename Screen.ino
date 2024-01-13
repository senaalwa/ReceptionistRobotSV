/**
 * @brief Inisialisasi LCD I2C
 * 
 */
void initializeScreen() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

/**
 * @brief Menampilkan data X,Y,BTN pada LCD 16x2
 * 
 */
void displayData() {
  lcd.setCursor(0, 0);
  lcd.print("x: ");
  lcd.print(x_value);
  lcd.setCursor(8, 0);
  lcd.print("y: ");
  lcd.print(y_value);

  lcd.setCursor(0, 1);
  lcd.print("state: ");
  lcd.print(btn_state == LOW ? "Press" : "Not Press");
}