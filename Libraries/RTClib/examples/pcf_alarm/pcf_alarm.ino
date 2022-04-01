#include <Wire.h>
#include <RTClib.h>

PCF8563 rtc;
DateTime alarm_l;
const byte rtc_int = 2;

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  pinMode(rtc_int, INPUT);
  attachInterrupt(digitalPinToInterrupt(rtc_int), interrupt, FALLING);
  Wire.begin();
  rtc.begin();

  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
  else {
    Serial.println("RTC OK");
    DateTime now = DateTime(2020, 4, 1, 12, 00, 0);
    rtc.adjust(now);

    setAlarm(1);
  }
}

void loop() {
  DateTime now = rtc.now();
  char buf[100];
  strncpy(buf, "DD.MM.YYYY hh:mm:ss", 100);
  Serial.println(now.format(buf));

  delay(1000);
}

void interrupt() {
  Serial.println("WakeUp atmega");
}

void setAlarm(int value) {
  char buf[100];
  strncpy(buf, "DD.MM.YYYY hh:mm:ss", 100);

  DateTime alarm = rtc.now();
  alarm.setminute(alarm.minute() + value);
  Serial.print("Setting alarm: ");
  strncpy(buf, "DD hh:mm MM", 100);
  Serial.println(alarm.format(buf));
  rtc.set_alarm(alarm, {1, 0, 0, 0});
  rtc.on_alarm();
}
