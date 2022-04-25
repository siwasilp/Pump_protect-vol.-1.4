#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
RTC_DS3231 RTC;
LiquidCrystal_I2C lcd(0x27, 20, 4);

unsigned long period = 30000;
unsigned long last_time = 0;

char sbuf[64];
char buf[64];

int in_wtL     = 10;
int in_wtH     = 12;
int in_oil     = 14;
int in_Fule    = 16;
int in_Emr     = 18;

int sw_1    = 11;

int led_g   = 13;
int led_y   = 15;
int led_r   = 17;

int re_overtemp = 3;
int re_waterLv  = 5;
int re_FuleLv   = 7;
int re_oilLv    = 9;

//--------------------------
float temp = 0;
float sts_temp = 0;
int   sts_rpm = 0;
float sts_hour = 0;
int sts_waterLv = 0;  // ok

//------------------------

float time_now;
float time_set = 5000;  //HR

int timeNow_add = 50;
int timeSet_add = 0;

unsigned long timer = 5000;
unsigned long ltime = 0;
