void setup_x() {
  Serial.begin(9600);

  pinMode(sw_1, INPUT_PULLUP);

  pinMode(in_wtL, INPUT_PULLUP);
  pinMode(in_wtH, INPUT_PULLUP);
  pinMode(in_Fule, INPUT_PULLUP);
  pinMode(in_oil, INPUT_PULLUP);
  pinMode(in_Emr, INPUT_PULLUP);

  pinMode(led_r, OUTPUT);
  pinMode(led_y, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(re_overtemp, OUTPUT);
  pinMode(re_waterLv, OUTPUT);
  pinMode(re_FuleLv, OUTPUT);
  pinMode(re_oilLv, OUTPUT);

  digitalWrite(led_r, HIGH);
  digitalWrite(led_y, HIGH);
  digitalWrite(led_g, HIGH);

  digitalWrite(re_overtemp, HIGH);
  digitalWrite(re_waterLv, HIGH);
  digitalWrite(re_FuleLv, HIGH);
  digitalWrite(re_oilLv, HIGH);

  // --------------------------- time -------------------------------
  Wire.begin();
  RTC.begin();
  lcd.init();
  lcd.backlight();
  //คอมเม้นออกเพื่อตั้งเวลา  yyyy,mm,dd,hh,mm,00
  //RTC.adjust(DateTime(2022,03,25,17,54,00));
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    //RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  DateTime now = RTC.now();
  lcd.clear();
}
