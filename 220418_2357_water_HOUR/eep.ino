void eepr() {
  Serial.print("Writing...>>> @ ");
  EEPROM.put(timeSet_add, time_set);
  Serial.print(timeSet_add);
  Serial.print(" >>> ");
  Serial.println(time_set);
  Serial.print("Reading...>>> ");
  EEPROM.get(timeSet_add, time_set);
  Serial.println(time_set);
  //-----------------------------------------------
  Serial.print("Writing...>>> @ ");
  EEPROM.put(timeNow_add, time_now);
  Serial.print(timeNow_add);
  Serial.print(" >>> ");
  Serial.println(time_now);
  Serial.print("Reading...>>> ");
  EEPROM.get(timeNow_add, time_now);
  Serial.println(time_now);
}


void eepx() {
  Serial.print("Reading...>>> ");
  EEPROM.get(timeSet_add, time_set);
  Serial.println(time_set);
  //-----------------------------------------------
  Serial.print("Reading...>>> ");
  EEPROM.get(timeNow_add, time_now);
  Serial.println(time_now);
}
