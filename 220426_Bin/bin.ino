void clock_x () {
  DateTime now = RTC.now();
  sprintf( sbuf, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  sprintf( buf, "%02d/%02d/%02d", now.day(), now.month(), now.year());
  lcd.setCursor(6, 1);
  lcd.print(sbuf);
  lcd.setCursor(5, 2);
  lcd.print(buf);
  printFrame();
}


void peeb() {
  if ( millis() - last_time > period) {
    digitalWrite(led_g, LOW);
    delay(80);
    digitalWrite(led_g, HIGH);
    delay(80);
    digitalWrite(led_g, LOW);
    delay(80);
    digitalWrite(led_g, HIGH);
    last_time = millis();
  }
}

void sw() {
  while (digitalRead(sw_1) == 0) {
    int a;

    clock_x();

    if (digitalRead(sw_1) == 0 &&  a == 0) {
      a = 1;
      lcd.clear();
    }
    if (digitalRead(sw_1) == 1) {
      a = 0;
      lcd.setCursor(1, 3);
      lcd.print("                  ");
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
}
void printFrame()
{
  lcd.setCursor(1, 0);
  lcd.print("------------------");
  lcd.setCursor(1, 3);
  lcd.print("------------------");

  lcd.setCursor(0, 1);
  lcd.write(byte(0));

  lcd.setCursor(0, 2);
  lcd.write(byte(0));

  lcd.setCursor(19, 1);
  lcd.write(byte(0));

  lcd.setCursor(19, 2);
  lcd.write(byte(0));

  lcd.setCursor(0, 0);
  lcd.write(byte(1));
  lcd.setCursor(19, 0);
  lcd.write(byte(2));
  lcd.setCursor(0, 3);
  lcd.write(byte(3));
  lcd.setCursor(19, 3);
  lcd.write(byte(4));
}

byte verticalLine[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte char2[8] = {
  B00000,
  B00000,
  B00000,
  B11100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte char1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00111,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};

byte char3[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte char4[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b11100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
