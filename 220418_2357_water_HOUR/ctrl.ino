
void sw_ctrl() {
  //Serial.println(sts_temp);
  if (sts_temp > set_temp) {         // OV_Temp ให้สั่ง RL1 ทำงาน
    def = 1;
  }
  if (digitalRead(in_wtH) == 0 && digitalRead(in_wtL) == 0) { // 1.ถ้า in_WtL=hi , in_WtH=hi  => display WATER_Lv=HIGH
    digitalWrite(re_waterLv, LOW);
    sts_waterLv = 0;
  }
  if (digitalRead(in_wtH) == 0 && digitalRead(in_wtL) == 1) { // 2.ถ้า in_WtL=hi , in_WtH=low => display WATER_Lv= BETWEEN
    //digitalWrite(re_waterLv, LOW);
    sts_waterLv = 1;
  }
  if (digitalRead(in_wtH) == 1 && digitalRead(in_wtL) == 0) { // 2.ถ้า in_WtL=hi , in_WtH=low => display WATER_Lv= BETWEEN
    // digitalWrite(re_waterLv, LOW);
    sts_waterLv = 1;
  }
  if (digitalRead(in_wtH) == 1 && digitalRead(in_wtL) == 1) { // 3.in_WtL=low   , in_WtH=low => display WATER_Lv=LOW
    digitalWrite(re_waterLv, HIGH);
    sts_waterLv = 2;
  }
  //Serial.print(digitalRead(in_wtH));  Serial.print(" "); Serial.print(digitalRead(in_wtL));  Serial.print(" ");  Serial.println(sts_waterLv);


 

  if (digitalRead(in_oil) == 0) {
    digitalWrite(re_oilLv, LOW);
    digitalWrite(led_y, HIGH);
    delay(100);
    digitalWrite(led_y, LOW);
    delay(100);
  }
  else {
    digitalWrite(re_oilLv, HIGH);
    digitalWrite(led_y, LOW);
  }

   if (digitalRead(in_Fule) == 0) {
    digitalWrite(re_FuleLv, LOW);
    digitalWrite(led_y, HIGH);
  } else {
    digitalWrite(re_FuleLv, HIGH);
  }

  if (digitalRead(in_Emr) == 0) {
    digitalWrite(re_overtemp, LOW);
    delay(500);
    digitalWrite(re_overtemp, HIGH);
    digitalWrite(re_waterLv, LOW);
    delay(500);
    digitalWrite(re_waterLv, HIGH);
    digitalWrite(re_FuleLv, LOW);
    delay(500);
    digitalWrite(re_FuleLv, HIGH);
    digitalWrite(re_oilLv, LOW);
    delay(500);
    digitalWrite(re_oilLv, HIGH);
    digitalWrite(led_r, LOW);
    delay(500);
    digitalWrite(led_r, HIGH);;
    digitalWrite(led_y, LOW);
    delay(500);
    digitalWrite(led_y, HIGH);
    digitalWrite(led_g, LOW);
    delay(500);
    digitalWrite(led_g, HIGH);
  }
}
