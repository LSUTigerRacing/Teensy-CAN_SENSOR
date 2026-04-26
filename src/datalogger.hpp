#include <SD.h>
#include <SPI.h>
#include <time.h>
#include "CAN.hpp"

extern char fileName[16];
extern File dataFile;
void datalogger_init();
void RecordData(CAN_message_t msg);