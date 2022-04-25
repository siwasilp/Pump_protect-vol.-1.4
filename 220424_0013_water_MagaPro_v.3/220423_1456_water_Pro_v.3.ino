#include "para.h"
int   set_temp = 95;    // OV_Temp ให้สั่ง RL1 ทำงาน
float time_set = 5000;  // HR

void setup () {
  //eepr();
  setup_x();
  welcome();
  eepx();
  thermocouple.begin();  //ds18b20
}
unsigned long periodx = 1000;
unsigned long last_timex = 0;
void loop() {
 sts_temp = thermocouple.getTempCByIndex(0);  //ds18b20
  xxx();
  sensor();
  sw_ctrl();
  sw();
  printrun();
  peeb();
  df();
  RPM = 0;
  
  delay(1000);
}

void printrun()
{
  //--------------------------------------------------------------------
  sts_hour = time_now;   // EEP
  Serial.print(time_set); Serial.print(" >> "); Serial.println(sts_hour);
  
  //--------------------------------------------------------------------
  lcd.setCursor(0, 0);
  lcd.print("TEMP : ");
  lcd.print(sts_temp);
  lcd.print(" C ");
  lcd.setCursor(0, 1);
  lcd.print("RPM  : ");
  lcd.print(sts_rpm);
  lcd.print("   ");
  
  lcd.setCursor(0, 2);
  lcd.print("HOUR : ");
  lcd.print((int)sts_hour);
  lcd.print("/");
  lcd.print((int)time_set);
  lcd.print(" ");
  
  lcd.setCursor(0, 3);
  lcd.print("WATER_Lv : ");
  if (sts_waterLv == 0) {
    lcd.setCursor(11, 3);
    lcd.print("HIGH    ");
  }
  if (sts_waterLv == 1) {
    lcd.setCursor(11, 3);
    lcd.print("BETWEEN ");
  }
  if (sts_waterLv == 2) {
    lcd.setCursor(11, 3);
    lcd.print("LOW     ");
  }
  
}
