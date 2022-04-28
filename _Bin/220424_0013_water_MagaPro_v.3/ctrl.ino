
void sw_ctrl() {
  //Serial.println(sts_temp);
  if (sts_temp > set_temp) {         // OV_Temp ให้สั่ง RL1 ทำงาน
    def = 1;
  }

  //----------------------------------------------------------------------------------------------


  if (digitalRead(in_wtH) == 0 && digitalRead(in_wtL) == 0 && counter > 3) { // 1.ถ้า in_WtL=hi , in_WtH=hi  => display WATER_Lv=HIGH
    digitalWrite(re_waterH_AutoStart, HIGH);
    sts_waterLv = 0;
  }
  else if (digitalRead(in_wtH) == 0 && digitalRead(in_wtL) == 0 && sts_rpm == 0) {
    counter++;
    digitalWrite(re_waterH_AutoStart, LOW);
    delay(5000);
    digitalWrite(re_waterH_AutoStart, HIGH);
    delay(3000);
    sts_waterLv = 0;
  }
  else {
  }

  //-----------------------------------------------------------------------------------------------

  if (digitalRead(in_wtH) == 0 && digitalRead(in_wtL) == 1) { // 2.ถ้า in_WtL=hi , in_WtH=low => display WATER_Lv= BETWEEN
    //digitalWrite(re_waterH_AutoStart, LOW);
    sts_waterLv = 1;
  }
  if (digitalRead(in_wtH) == 1 && digitalRead(in_wtL) == 0) { // 2.ถ้า in_WtL=hi , in_WtH=low => display WATER_Lv= BETWEEN
    // digitalWrite(re_waterH_AutoStart, LOW);
    sts_waterLv = 1;
  }
  if (digitalRead(in_wtH) == 1 && digitalRead(in_wtL) == 1) { // 3.in_WtL=low   , in_WtH=low => display WATER_Lv=LOW     ok
    counter = 0;
    digitalWrite(re_waterH_AutoStart, HIGH);
    sts_waterLv = 2;
    digitalWrite(re_waterL_Stop, LOW);
  }
  else {
    digitalWrite(re_waterL_Stop, HIGH);

  }

  //Serial.print(digitalRead(in_wtH));  Serial.print(" "); Serial.print(digitalRead(in_wtL));  Serial.print(" ");  Serial.println(sts_waterLv);



  //--------------------------------------------
  if (digitalRead(in_oil) == 0) {
    digitalWrite(re_oilLv, LOW);
    digitalWrite(led_y, 0);
    delay(100);
    digitalWrite(led_y, 1);
    delay(100);
  }
  else {
    digitalWrite(re_oilLv, HIGH);
    digitalWrite(led_y, 1);
  }
  //---------------------------------------------
  if (digitalRead(in_Fule) == 0) {
    //digitalWrite(re_waterL_Stop, LOW);
    digitalWrite(led_y, 0);
  } else {
    //digitalWrite(re_waterL_Stop, HIGH);
  }
  //---------------------------------------------
  if (digitalRead(in_Emr) == 0) {
    digitalWrite(re_overtemp, LOW);
    delay(500);
    digitalWrite(re_overtemp, HIGH);
    digitalWrite(re_waterH_AutoStart, LOW);
    delay(500);
    digitalWrite(re_waterH_AutoStart, HIGH);
    digitalWrite(re_waterL_Stop, LOW);
    delay(500);
    digitalWrite(re_waterL_Stop, HIGH);
    digitalWrite(re_oilLv, LOW);
    delay(500);
    digitalWrite(re_oilLv, HIGH);
    digitalWrite(led_r, 0);
    delay(500);
    digitalWrite(led_r, 1);;
    
    digitalWrite(led_y, 1);
    delay(500);
    digitalWrite(led_y, 0);
    
    digitalWrite(led_g, 1);
    delay(500);
    digitalWrite(led_g, 1);
  }
}
