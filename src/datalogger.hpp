#include <SD.h>
#include <SPI.h>
#include <time.h>

class datalogger
{
private:
    char fileName[16];
    File dataFile;
public:
    datalogger();
    ~datalogger();
    void RecordData(String message, int data[]);
};