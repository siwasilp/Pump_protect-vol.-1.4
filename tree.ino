void welcome() {
  for (int i = 0 ; i < 2 ; i++) {
    clock_x();
    digitalWrite(led_g, LOW);
    delay(500);
    digitalWrite(led_g, HIGH);
    delay(500);
  }
  lcd.clear();
  while (digitalRead(sw_1) == 0) {
    lcd.setCursor(0, 0);
    lcd.print("SET_DEFAULT...");
    lcd.setCursor(3, 2);
    lcd.print("Loading");
    for (int j = 0 ; j < 5 ; j++) {
      for (int i = 0 ; i < 7 ; i++) {
        lcd.setCursor(10 + i, 2);
        lcd.print(".  ");
        delay(200);
        digitalWrite(led_g, LOW);
        delay(50);
        digitalWrite(led_g, HIGH);
        delay(50);
      }
    }
    for (int i = 0 ; i < 5 ; i++) {
      digitalWrite(led_g, LOW);
      lcd.setCursor(0, 2);
      lcd.print("                    ");
      delay(500);
      lcd.setCursor(0, 2);
      lcd.print(">>> Succeed_full <<<");
      delay(500);
      digitalWrite(led_g, HIGH);
    }
    eepr();
    lcd.setCursor(0, 2);
    lcd.print(">>> Succeed_full <<<");
    lcd.setCursor(2, 3);
    lcd.print(time_now);
    lcd.setCursor(9, 3);
    lcd.print("/");
    lcd.setCursor(11, 3);
    lcd.print(time_set);
    delay(2000);
    lcd.clear();

  }
}
