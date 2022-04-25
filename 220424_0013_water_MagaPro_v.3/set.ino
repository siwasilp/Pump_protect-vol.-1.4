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
  pinMode(re_waterH_AutoStart, OUTPUT);
  pinMode(re_waterL_Stop, OUTPUT);
  pinMode(re_oilLv, OUTPUT);
  
  // EDIT LED HW_N
  digitalWrite(led_r, LOW);
  digitalWrite(led_y, HIGH);
  digitalWrite(led_g, HIGH);

  digitalWrite(re_overtemp, HIGH);
  digitalWrite(re_waterH_AutoStart, HIGH);
  digitalWrite(re_waterL_Stop, HIGH);
  digitalWrite(re_oilLv, HIGH);
  // ========================== thermo ===============================
  pinMode(thermo_vcc_pin, OUTPUT);
  pinMode(thermo_gnd_pin, OUTPUT);
  digitalWrite(thermo_vcc_pin, HIGH);
  digitalWrite(thermo_gnd_pin, LOW);
  // ========================= RPM =================================
  pinMode(2, INPUT_PULLUP); 
  attachInterrupt(0, sens, FALLING);
  // ========================= time ==================================
  
  Wire.begin();
  RTC.begin();
  lcd.init();
  lcd.backlight();
  //คอมเม้นออกเพื่อตั้งเวลา   yyyy,mm,dd,hh,mm,00
  //RTC.adjust(DateTime(2022,04,25,16,37,00));
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    //RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  DateTime now = RTC.now();
  lcd.clear();
}
