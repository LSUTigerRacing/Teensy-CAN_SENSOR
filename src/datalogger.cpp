#include "datalogger.hpp"

    char fileName[16];
    File dataFile;
    void datalogger_init(){
        if(SD.begin(BUILTIN_SDCARD)){
            int driveNum = 0;
            snprintf(fileName, sizeof(fileName), "Drive%d.csv", driveNum); 
            bool fileExists = SD.exists(fileName);
            while(fileExists){
                snprintf(fileName, sizeof(fileName), "Drive%d.csv", driveNum); 
                SD.exists(fileName);
                ++driveNum;
            }
            dataFile = SD.open(fileName,FILE_WRITE);
            dataFile.println("Time, Message, Val_1, Val_2, Val_3, Val_4, Val_5, Val_6, Val_7, Val_8");
            dataFile.flush();
        }
        else{
            Serial.printf("Error connecting to SD card \n");
        }
    }

void RecordData(CAN_message_t msg){
    dataFile.print(msg.timestamp + ',');
    dataFile.print(msg.id + ',');
    switch(msg.id){
        case 17: // General_Data1
            dataFile.printf("%3f,%3f\n",sigName.DUTY_CYCLE,sigName.MC_INPUT_V);
            break;

        case 117: // General_Data2
            dataFile.printf("%3f,%3f\n",sigName.AC_Current,sigName.DC_Current);
            break;

        case 217: // General_Data3
            dataFile.printf("%3f,%3f,3%d\n",sigName.MC_Temp,sigName.Motor_Temp,sigName.Fault_Code);
            break;

        case 317: // General_Data4
            dataFile.printf("%3d,%3d\n",sigName.FOC_id,sigName.FOC_iq);
            break;

        case 417: // General_Data5
            dataFile.printf("%3f,%3f\n",sigName.MC_Throttle,sigName.Brake);
            break;
        
        case 1712: //BMS1
            dataFile.printf("%3f,%3f,%3f,%3f,%3f\n",sigName.Pack_Current,sigName.Pack_Insta_Volta,
                sigName.Pack_SOC,sigName.Relay_State,sigName.Check_Sum);
            break;
        
        case 1713: //BMS2
                dataFile.printf("%3f,%3f,%3f,%3f,%3f\n",sigName.PACK_DCL,sigName.PACK_CCL,
                    sigName.Cell_High,sigName.Cell_Low,sigName.CRC_Check_Sum);
                break;
       // --- LF Tire Temps ---
case 1200:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LF_Tire_Temp_01, sigName.LF_Tire_Temp_02, sigName.LF_Tire_Temp_03, sigName.LF_Tire_Temp_04);
    break;

case 1201:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LF_Tire_Temp_05, sigName.LF_Tire_Temp_06, sigName.LF_Tire_Temp_07, sigName.LF_Tire_Temp_08);
    break;

case 1202:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LF_Tire_Temp_09, sigName.LF_Tire_Temp_10, sigName.LF_Tire_Temp_11, sigName.LF_Tire_Temp_12);
    break;

case 1203:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LF_Tire_Temp_13, sigName.LF_Tire_Temp_14, sigName.LF_Tire_Temp_15, sigName.LF_Tire_Temp_16);
    break;

// --- RF Tire Temps ---
case 1204:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RF_Tire_Temp_01, sigName.RF_Tire_Temp_02, sigName.RF_Tire_Temp_03, sigName.RF_Tire_Temp_04);
    break;

case 1205:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RF_Tire_Temp_05, sigName.RF_Tire_Temp_06, sigName.RF_Tire_Temp_07, sigName.RF_Tire_Temp_08);
    break;

case 1206:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RF_Tire_Temp_09, sigName.RF_Tire_Temp_10, sigName.RF_Tire_Temp_11, sigName.RF_Tire_Temp_12);
    break;

case 1207:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RF_Tire_Temp_13, sigName.RF_Tire_Temp_14, sigName.RF_Tire_Temp_15, sigName.RF_Tire_Temp_16);
    break;

// --- LR Tire Temps ---
case 1208:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LR_Tire_Temp_01, sigName.LR_Tire_Temp_02, sigName.LR_Tire_Temp_03, sigName.LR_Tire_Temp_04);
    break;

case 1209:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LR_Tire_Temp_05, sigName.LR_Tire_Temp_06, sigName.LR_Tire_Temp_07, sigName.LR_Tire_Temp_08);
    break;

case 1210:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LR_Tire_Temp_09, sigName.LR_Tire_Temp_10, sigName.LR_Tire_Temp_11, sigName.LR_Tire_Temp_12);
    break;

case 1211:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LR_Tire_Temp_13, sigName.LR_Tire_Temp_14, sigName.LR_Tire_Temp_15, sigName.LR_Tire_Temp_16);
    break;

// --- RR Tire Temps ---
case 1212:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RR_Tire_Temp_01, sigName.RR_Tire_Temp_02, sigName.RR_Tire_Temp_03, sigName.RR_Tire_Temp_04);
    break;

case 1213:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RR_Tire_Temp_05, sigName.RR_Tire_Temp_06, sigName.RR_Tire_Temp_07, sigName.RR_Tire_Temp_08);
    break;

case 1214:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RR_Tire_Temp_09, sigName.RR_Tire_Temp_10, sigName.RR_Tire_Temp_11, sigName.RR_Tire_Temp_12);
    break;

case 1215:
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RR_Tire_Temp_13, sigName.RR_Tire_Temp_14, sigName.RR_Tire_Temp_15, sigName.RR_Tire_Temp_16);
    break;
        
        // Brake Sensor Temps (single signal, 2 byte messages)
case 1224: // LF_IRTS_Brake_5
    dataFile.printf("%3f\n",sigName.LF_Sensor_Temp);
    break;

case 1229: // RF_IRTS_Brake_5
    dataFile.printf("%3f\n",sigName.RF_Sensor_Temp);
    break;

case 1234: // LR_IRTS_Brake_5
    dataFile.printf("%3f\n",sigName.LR_Sensor_Temp);
    break;

case 1239: // RR_IRTS_Brake_5
    dataFile.printf("%3f\n",sigName.RR_Sensor_Temp);
    break;

// LF Rotor Temps
case 1221: // LF_IRTS_Brake_2
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LF_Rotor_Temp_05, sigName.LF_Rotor_Temp_06, sigName.LF_Rotor_Temp_07, sigName.LF_Rotor_Temp_08);
    break;

case 1222: // LF_IRTS_Brake_3
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LF_Rotor_Temp_09, sigName.LF_Rotor_Temp_10, sigName.LF_Rotor_Temp_11, sigName.LF_Rotor_Temp_12);
    break;

case 1223: // LF_IRTS_Brake_4
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LF_Rotor_Temp_13, sigName.LF_Rotor_Temp_14, sigName.LF_Rotor_Temp_15, sigName.LF_Rotor_Temp_16);
    break;

// --- RF Rotor Temps ---
case 1225: // RF_IRTS_Brake_1
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RF_Rotor_Temp_01, sigName.RF_Rotor_Temp_02, sigName.RF_Rotor_Temp_03, sigName.RF_Rotor_Temp_04);
    break;

case 1226: // RF_IRTS_Brake_2
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RF_Rotor_Temp_05, sigName.RF_Rotor_Temp_06, sigName.RF_Rotor_Temp_07, sigName.RF_Rotor_Temp_08);
    break;

case 1227: // RF_IRTS_Brake_3
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RF_Rotor_Temp_09, sigName.RF_Rotor_Temp_10, sigName.RF_Rotor_Temp_11, sigName.RF_Rotor_Temp_12);
    break;

case 1228: // RF_IRTS_Brake_4
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RF_Rotor_Temp_13, sigName.RF_Rotor_Temp_14, sigName.RF_Rotor_Temp_15, sigName.RF_Rotor_Temp_16);
    break;

// --- LR Rotor Temps ---
case 1230: // LR_IRTS_Brake_1
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LR_Rotor_Temp_01, sigName.LR_Rotor_Temp_02, sigName.LR_Rotor_Temp_03, sigName.LR_Rotor_Temp_04);
    break;

case 1231: // LR_IRTS_Brake_2
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LR_Rotor_Temp_05, sigName.LR_Rotor_Temp_06, sigName.LR_Rotor_Temp_07, sigName.LR_Rotor_Temp_08);
    break;

case 1232: // LR_IRTS_Brake_3
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LR_Rotor_Temp_09, sigName.LR_Rotor_Temp_10, sigName.LR_Rotor_Temp_11, sigName.LR_Rotor_Temp_12);
    break;

case 1233: // LR_IRTS_Brake_4
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.LR_Rotor_Temp_13, sigName.LR_Rotor_Temp_14, sigName.LR_Rotor_Temp_15, sigName.LR_Rotor_Temp_16);
    break;

// --- RR Rotor Temps ---
case 1235: // RR_IRTS_Brake_1
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RR_Rotor_Temp_01, sigName.RR_Rotor_Temp_02, sigName.RR_Rotor_Temp_03, sigName.RR_Rotor_Temp_04);
    break;

case 1236: // RR_IRTS_Brake_2
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RR_Rotor_Temp_05, sigName.RR_Rotor_Temp_06, sigName.RR_Rotor_Temp_07, sigName.RR_Rotor_Temp_08);
    break;

case 1237: // RR_IRTS_Brake_3
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RR_Rotor_Temp_09, sigName.RR_Rotor_Temp_10, sigName.RR_Rotor_Temp_11, sigName.RR_Rotor_Temp_12);
    break;

case 1238: // RR_IRTS_Brake_4
    dataFile.printf("%3f,%3f,%3f,%3f\n", sigName.RR_Rotor_Temp_13, sigName.RR_Rotor_Temp_14, sigName.RR_Rotor_Temp_15, sigName.RR_Rotor_Temp_16);
    break;
default:
    // Unknown message ID
    break;
    }
    dataFile.flush();
}