#include "para.h"
int   set_temp = 95;    // OV_Temp ให้สั่ง RL1 ทำงาน
float time_set = 5000;  // HR

void setup () {
  setup_x();
  welcome();
  eepx();
}
unsigned long periodx = 1000;
unsigned long last_timex = 0;
void loop() {
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
  sts_hour = time_now;
  lcd.setCursor(0, 0);
  lcd.print("TEMP : ");
  lcd.print(sts_temp);
  lcd.print(" C ");
  lcd.setCursor(0, 1);
  lcd.print("RPM  : ");
  lcd.print(sts_rpm);
  Serial.println(sts_rpm);
  lcd.print("   ");
  lcd.setCursor(0, 2);
  lcd.print("HOUR : ");
  lcd.print(sts_hour);
  lcd.print(" hr ");
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

void xxx() {

  int wings = 3; // no of wings of rotating object, for disc object use 1 with white tape on one side
  int RPMnew = RPM / wings; //here we used fan which has 3 wings
  //  Serial.print(RPMnew);
  //  Serial.print(" Rot/sec :");  //Revolutions per second
  //  Serial.print((RPMnew*60));
  //  Serial.println("Rot/min. ");   //Revolutions per minute
  sts_rpm = RPMnew * 60;
}
