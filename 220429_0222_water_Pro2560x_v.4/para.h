#include <Wire.h>
#include <SPI.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
//#include <max6675.h> //max6675
#include <OneWire.h> //ds18b20
#include <DallasTemperature.h> //ds18b20


DS3231 RTC;
LiquidCrystal_I2C lcd(0x27, 20, 4);

unsigned long period = 30000;
unsigned long last_time = 0;

char sbuf[64];
char buf[64];

int in_wtL     = 12;
int in_wtH     = 10;
int in_oil     = 14;
int in_Fule    = 16;
int in_Emr     = 18;

int sw_1    = 11;

int led_g   = 13;
int led_y   = 15;
int led_r   = 17;

//------------ RELAY --------------
int re_overtemp          = 9;
int re_waterH_AutoStart  = 7; //re_waterLv  7
int re_waterL_Stop       = 5; //re_FuleLv   5
int re_oilLv             = 3;

//---------------- MAX6675 -----------------
//int thermo_gnd_pin = 43; //max6675
//int thermo_vcc_pin = 45; //max6675
//int thermo_so_pin  = 51; //max6675
//int thermo_cs_pin  = 49; //max6675
//int thermo_sck_pin = 47; //max6675
//MAX6675 thermocouple(thermo_sck_pin, thermo_cs_pin, thermo_so_pin); //max6675

//------------------ ds18b20 ------------------
int thermo_gnd_pin = 31; //ds18b20
int thermo_vcc_pin = 33; //ds18b20
int thermo_dat_pin = 35; //ds18b20

#define ONE_WIRE_BUS 35   //ds18b20
OneWire oneWire(ONE_WIRE_BUS); //ds18b20
DallasTemperature thermocouple(&oneWire); //ds18b20
//---------------------------------------------

float temp = 0;
float sts_temp = 0;
int   sts_rpm = 0;
float sts_hour = 0;
int sts_waterLv = 0;  // ok
int counter = 0;

//------------------------
int def = 0;

unsigned long lastflash;
int RPM;
int ledState = 1;

long h = 0;
int m = 0;
int s = 0;
int ms = 0;

void stopwatch()
{
  lcd.setCursor(7, 2);
  lcd.print(h);         //writing hours
  lcd.print(":");
  lcd.print(m);         //writing minutes
  lcd.print(":");
  lcd.print(s);         //writing seconds
  ms = ms + 10;
  if (ms == 590)
  {

  }

  if (ms == 590)  //if state for counting up seconds
  {
    ms = 0;
    s = s + 1;
  }

  if (s == 60)  //if state for counting up minutes
  {
    s = 0;
    m = m + 1;
  }

  if (m == 60)   //if state for counting up hours
  {
    m = 00;
    h = h + 01;
  }
}


void sens() {
  RPM++;
  Serial.println("x");
  counter = 0;
  ledState = !ledState;
}

//-----------------------

float time_now;


int timeNow_add = 50;
int timeSet_add = 0;

unsigned long timer = 5000;
unsigned long ltime = 0;

//----------------------
unsigned long start, finished, elapsed;
boolean r = false;
// Variables for button debounce time
long lastButtonPressTime = 0; // the last time the button was pressed
long debounceDelay = 50; // the debounce time; keep this as low as possible
//----------------------
