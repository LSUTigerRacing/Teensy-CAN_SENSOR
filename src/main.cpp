#include <Arduino.h>
#include "CAN.hpp"
#include "screen.hpp"
#include "datalogger.hpp"

void setup() {
  Serial.begin(115200);
  LCD_init();
  CAN_init();
}

void loop() {
  can1.events();
  if(pendingMessage){
    pendingMessage = false; 
    RecordData();
    LCD_Update();
  }
}
