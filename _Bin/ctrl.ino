
void sw_ctrl() {

  if (digitalRead(in_wtL) == 0) {
    digitalWrite(re_waterLv, LOW);
    sts_waterLv = 0;
  }
  if (digitalRead(in_wtH) == 0) {
    digitalWrite(re_waterLv, HIGH);
    sts_waterLv = 1;
  }

  if (digitalRead(in_Fule) == 0) {
    digitalWrite(re_FuleLv, LOW);
    digitalWrite(led_r, LOW);
  } else {
    digitalWrite(re_FuleLv, HIGH);
    digitalWrite(led_r, HIGH);
  }

  if (digitalRead(in_oil) == 0) {
    digitalWrite(re_oilLv, LOW);
    digitalWrite(led_y, LOW);
  } else {
    digitalWrite(re_oilLv, HIGH);
    digitalWrite(led_y, HIGH);
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
