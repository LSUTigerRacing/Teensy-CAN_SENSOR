#include <Arduino.h>
#include "CAN.hpp"
#include <LCD_I2C.h>
#include "datalogger.hpp"

void setup() {
  Serial.begin(115200);
  datalogger logger.begin();
}

void loop() {
  can1.events();
  logger.RecordData();
}
