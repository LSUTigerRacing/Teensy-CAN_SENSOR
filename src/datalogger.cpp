#include "datalogger.hpp"

class datalogger
{
private:
    char fileName[16];
    File dataFile;
public:
    datalogger::datalogger(/* args */){
        if(!SD.begin(BUILTIN_SDCARD)){
            int driveNum = 0;
            sniprintf(fileName, sizeof(fileName), "Drive%4d.csv", driveNum); 
            bool fileExists = SD.exists(fileName);
            while(fileExists){
                sniprintf(fileName, sizeof(fileName), "Drive%4d.csv", driveNum); 
                SD.exists(fileName);
                ++driveNum;
            }
            dataFile = SD.open(fileName,FILE_WRITE);
            dataFile.println("Time, Message, Val_1, Val_2, Val_3, Val_4, Val_5, Val_6, Val_7, Val_8");
        }
        else{
            Serial.printf("Error connecting to SD card \n");
        }
    }

    datalogger::~datalogger(){
        dataFile.close();
    }

    void datalogger::RecordData(String message, int data[]){
        
        dataFile.print(message + ',');
        for(int i = 0; i < sizeof(data)/sizeof(int); i++){
            if(data[i] != NULL){
                dataFile.printf("%3d,", data[i]);
            }
            else{
                dataFile.println();
            }
        }
    }

};