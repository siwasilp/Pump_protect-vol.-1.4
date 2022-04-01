#include "para.h"
int ii = 0;
float dd = 0;
void setup () {
  setup_x();
  welcome();
  eepx();
  ii = time_now;
  dd = time_now - ii;
  temp = dd ;
}

void loop() {
  sw_ctrl();
  sw();
  printrun();
  peeb();

  //==================== TIME ======================
  if (true) {
    if ( millis() - ltime > timer) {
      if (temp > 0.60) {
        temp = 0;
      }
      temp = temp + 0.01;
      Serial.print(temp); Serial.print(" >>> ");
      // EEPROM.put(timeNow_add, time_now);
      //EEPROM.get(timeNow_add, time_now);
      time_now = time_now + temp;
      Serial.println(time_now);
      ltime == millis();
    }
  }
  //==============================================

}

void printrun()
{
  sts_hour = time_now;
  lcd.setCursor(0, 0);
  lcd.print("TEMP : ");
  lcd.setCursor(0, 1);
  lcd.print("RPM  : ");
  lcd.setCursor(0, 2);
  lcd.print("HOUR : ");
  lcd.print(sts_hour);
  lcd.print(" Hr ");
  lcd.setCursor(0, 3);
  lcd.print("WATER_Lv : ");
  if (sts_waterLv == 1) {
    lcd.setCursor(11, 3);
    lcd.print("LOW  ");
  }
  if (sts_waterLv == 0) {
    lcd.setCursor(11, 3);
    lcd.print("HIGH ");
  }
}
