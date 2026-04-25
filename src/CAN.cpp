#include "CAN.hpp"

// 22 CAN1 TX 
// 23 CAN RX
FlexCAN_T4<CAN1, RX_SIZE_1024, TX_SIZE_16> can1;
bool pendingMessage;
CAN_message_t msg_cpy;

struct signalName {
        //Motor Contoller Signals
        float DUTY_CYCLE;
        float MC_INPUT_V;
        float AC_Current;
        float DC_Current;
        float MC_Temp;
        float Motor_Temp;
        float Fault_Code;
        float FOC_id;
        float FOC_iq;
        float MC_Throttle;
        float Brake;
        //BMS
        float Pack_Current;
        float Pack_Insta_Volta;
        float Pack_SOC;
        float Relay_State;
        float Check_Sum;
        float PACK_DCL;
        float PACK_CCL;
        float Cell_High;
        float Cell_Low;
        float CRC_Check_Sum;
        //Tire Signals
        float LF_Tire_Temp_01;
        float LF_Tire_Temp_02;
        float LF_Tire_Temp_03;
        float LF_Tire_Temp_04;
        float LF_Tire_Temp_05;
        float LF_Tire_Temp_06;
        float LF_Tire_Temp_07;
        float LF_Tire_Temp_08;
        float LF_Tire_Temp_09;
        float LF_Tire_Temp_10;
        float LF_Tire_Temp_11;
        float LF_Tire_Temp_12;
        float LF_Tire_Temp_13;
        float LF_Tire_Temp_14;
        float LF_Tire_Temp_15;
        float LF_Tire_Temp_16;
        float RF_Tire_Temp_01;
        float RF_Tire_Temp_02;
        float RF_Tire_Temp_03;
        float RF_Tire_Temp_04;
        float RF_Tire_Temp_05;
        float RF_Tire_Temp_06;
        float RF_Tire_Temp_07;
        float RF_Tire_Temp_08;
        float RF_Tire_Temp_09;
        float RF_Tire_Temp_10;
        float RF_Tire_Temp_11;
        float RF_Tire_Temp_12;
        float RF_Tire_Temp_13;
        float RF_Tire_Temp_14;
        float RF_Tire_Temp_15;
        float RF_Tire_Temp_16;
        float LR_Tire_Temp_01;
        float LR_Tire_Temp_02;
        float LR_Tire_Temp_03;
        float LR_Tire_Temp_04;
        float LR_Tire_Temp_05;
        float LR_Tire_Temp_06;
        float LR_Tire_Temp_07;
        float LR_Tire_Temp_08;
        float LR_Tire_Temp_09;
        float LR_Tire_Temp_10;
        float LR_Tire_Temp_11;
        float LR_Tire_Temp_12;
        float LR_Tire_Temp_13;
        float LR_Tire_Temp_14;
        float LR_Tire_Temp_15;
        float LR_Tire_Temp_16;
        float RR_Tire_Temp_01;
        float RR_Tire_Temp_02;
        float RR_Tire_Temp_03;
        float RR_Tire_Temp_04;
        float RR_Tire_Temp_05;
        float RR_Tire_Temp_06;
        float RR_Tire_Temp_07;
        float RR_Tire_Temp_08;
        float RR_Tire_Temp_09;
        float RR_Tire_Temp_10;
        float RR_Tire_Temp_11;
        float RR_Tire_Temp_12;
        float RR_Tire_Temp_13;
        float RR_Tire_Temp_14;
        float RR_Tire_Temp_15;
        float RR_Tire_Temp_16;
        //Brake Signals
        float LF_Sensor_Temp;
        float RF_Sensor_Temp;
        float LR_Sensor_Temp;
        float RR_Sensor_Temp;
        //Rotor Signals
        float LF_Rotor_Temp_01;
        float LF_Rotor_Temp_02;
        float LF_Rotor_Temp_03;
        float LF_Rotor_Temp_04;
        float LF_Rotor_Temp_05;
        float LF_Rotor_Temp_06;
        float LF_Rotor_Temp_07;
        float LF_Rotor_Temp_08;
        float LF_Rotor_Temp_09;
        float LF_Rotor_Temp_10;
        float LF_Rotor_Temp_11;
        float LF_Rotor_Temp_12;
        float LF_Rotor_Temp_13;
        float LF_Rotor_Temp_14;
        float LF_Rotor_Temp_15;
        float LF_Rotor_Temp_16;
        float RF_Rotor_Temp_01;
        float RF_Rotor_Temp_02;
        float RF_Rotor_Temp_03;
        float RF_Rotor_Temp_04;
        float RF_Rotor_Temp_05;
        float RF_Rotor_Temp_06;
        float RF_Rotor_Temp_07;
        float RF_Rotor_Temp_08;
        float RF_Rotor_Temp_09;
        float RF_Rotor_Temp_10;
        float RF_Rotor_Temp_11;
        float RF_Rotor_Temp_12;
        float RF_Rotor_Temp_13;
        float RF_Rotor_Temp_14;
        float RF_Rotor_Temp_15;
        float RF_Rotor_Temp_16;
        float LR_Rotor_Temp_01;
        float LR_Rotor_Temp_02;
        float LR_Rotor_Temp_03;
        float LR_Rotor_Temp_04;
        float LR_Rotor_Temp_05;
        float LR_Rotor_Temp_06;
        float LR_Rotor_Temp_07;
        float LR_Rotor_Temp_08;
        float LR_Rotor_Temp_09;
        float LR_Rotor_Temp_10;
        float LR_Rotor_Temp_11;
        float LR_Rotor_Temp_12;
        float LR_Rotor_Temp_13;
        float LR_Rotor_Temp_14;
        float LR_Rotor_Temp_15;
        float LR_Rotor_Temp_16;
        float RR_Rotor_Temp_01;
        float RR_Rotor_Temp_02;
        float RR_Rotor_Temp_03;
        float RR_Rotor_Temp_04;
        float RR_Rotor_Temp_05;
        float RR_Rotor_Temp_06;
        float RR_Rotor_Temp_07;
        float RR_Rotor_Temp_08;
        float RR_Rotor_Temp_09;
        float RR_Rotor_Temp_10;
        float RR_Rotor_Temp_11;
        float RR_Rotor_Temp_12;
        float RR_Rotor_Temp_13;
        float RR_Rotor_Temp_14;
        float RR_Rotor_Temp_15;
        float RR_Rotor_Temp_16;
    }sigName;

struct Signal{
    char Name[32];
    uint8_t startBit;
    uint8_t length;
    float scale;
    float offset;
    bool isSigned;
};
uint32_t extractBits(const uint8_t* frameData, uint8_t startBit, uint8_t length, bool isSigned) {
    uint32_t raw = 0;
    
    // Convert Motorola start bit (MSB) to the actual bit position
    int bit = (startBit / 8) * 8 + (7 - (startBit % 8));
    
    for (int i = length - 1; i >= 0; i--) {
        // Extract bit from frame
        if (frameData[bit / 8] & (1 << (7 - (bit % 8))))
            raw |= (1u << i);
        
        // Advance to next bit in Motorola order
        if ((bit % 8) == 0)
            bit += 15;  // wrap to MSB of next byte
        else
            bit--;
    }

    // Handle signed values using two's complement
    if (isSigned && (raw & (1u << (length - 1)))) {
        raw |= ~((1u << length) - 1);
    }

    return raw;
}

float decodeSignal(const uint8_t* frameData, Signal& sig) {
    uint32_t raw = extractBits(frameData, sig.startBit, sig.length, sig.isSigned);
    if (sig.scale == 1.0f && sig.offset == 0.0f)
        return (float)(int32_t)raw;
    return ((int32_t)raw * sig.scale) + sig.offset;
}

void processMessage(const CAN_message_t& msg) {
    pendingMessage = true;
    msg_cpy = msg;
    switch (msg.id) {
        case 17: // General_Data1
            sigName.DUTY_CYCLE = decodeSignal(msg.buf, (struct Signal){{"DUTY_CYCLE"}, 31, 16, 1.0f, 0.0f, false});
            sigName.MC_INPUT_V = decodeSignal(msg.buf, (struct Signal){{"MC_INPUT_V"}, 47, 16, 1.0f, 0.0f, false});
            Serial.printf("DUTY_CYCLE: %.2f  MC_INPUT_V: %.2f\n",
                sigName.DUTY_CYCLE, sigName.MC_INPUT_V);
            break;

        case 117: // General_Data2
            sigName.AC_Current = decodeSignal(msg.buf, (struct Signal){{"AC_Current"}, 0,  16, 1.0f, 0.0f, false});
            sigName.DC_Current = decodeSignal(msg.buf, (struct Signal){{"DC_Current"}, 16, 16, 1.0f, 0.0f, false});
            Serial.printf("AC_Current: %.2f  DC_Current: %.2f\n",
                sigName.AC_Current, sigName.DC_Current);
            break;

        case 217: // General_Data3
            sigName.MC_Temp    = decodeSignal(msg.buf, (struct Signal){{"MC_Temp"},    0,  16, 1.0f, 0.0f, false});
            sigName.Motor_Temp = decodeSignal(msg.buf, (struct Signal){{"Motor_Temp"}, 16, 16, 1.0f, 0.0f, false});
            sigName.Fault_Code = (uint8_t)decodeSignal(msg.buf, (struct Signal){{"Fault_Code"}, 32, 8, 1.0f, 0.0f, false});
            Serial.printf("MC_Temp: %.2f  Motor_Temp: %.2f  Fault: %d\n",
                sigName.MC_Temp, sigName.Motor_Temp, sigName.Fault_Code);
            break;

        case 317: // General_Data4
            sigName.FOC_id = decodeSignal(msg.buf, (struct Signal){{"FOC_id"}, 0,  32, 1.0f, 0.0f, false});
            sigName.FOC_iq = decodeSignal(msg.buf, (struct Signal){{"FOC_iq"}, 32, 32, 1.0f, 0.0f, false});
            Serial.printf("FOC_id: %.2f  FOC_iq: %.2f\n",
                sigName.FOC_id, sigName.FOC_iq);
            break;

        case 417: // General_Data5
            sigName.MC_Throttle = decodeSignal(msg.buf, (struct Signal){{"MC_Throttle"}, 0, 8,  1.0f, 0.0f, false});
            sigName.Brake       = decodeSignal(msg.buf, (struct Signal){{"Brake"},8, 16, 1.0f, 0.0f, false});
            Serial.printf("MC_Throttle: %.2f  Brake: %.2f\n",
                sigName.MC_Throttle, sigName.Brake);
            break;
        
        case 1712:
            sigName.Pack_Current = decodeSignal(msg.buf, (struct Signal){{"Pack_Current"},0,16,1,0,false});
            sigName.Pack_Insta_Volta = decodeSignal(msg.buf, (struct Signal){{"Pack_Insta_Volta"},16,16,1,0,false});
            sigName.Pack_SOC = decodeSignal(msg.buf,(struct Signal){{"Pack_SOC"},32,8,1,0,false});
            sigName.Relay_State = decodeSignal(msg.buf,(struct Signal){{"Relay_State"},40,16,1,0,false});
            sigName.Check_Sum = decodeSignal(msg.buf,(struct Signal){{"Check_Sum"},56,8,1,1720,false});
            break;
        
        case 1713:
                sigName.PACK_DCL = decodeSignal(msg.buf, (struct Signal){{"PACK_DCL"},0,16,1,0,false});
                sigName.PACK_CCL = decodeSignal(msg.buf, (struct Signal){{"PACK_CCL"},16,8,1,0,false});
                sigName.Cell_High = decodeSignal(msg.buf,(struct Signal){{"Cell_High"},24,8,1,0,false});
                sigName.Cell_Low = decodeSignal(msg.buf,(struct Signal){{"Cell_Low"},32,8,1,0,false});
                sigName.CRC_Check_Sum = decodeSignal(msg.buf, (struct Signal){{"CRC_Check_Sum"},55,8,1,1721,false});
                break;
        case 1200:
                sigName.LF_Tire_Temp_01 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_01"},7,16,.1,-100,true});
                sigName.LF_Tire_Temp_02 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_02"},23,16,.1,-100,true});
                sigName.LF_Tire_Temp_03 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_03"},39,16,.1,-100,true});
                sigName.LF_Tire_Temp_04 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_04"},55,16,.1,-100,true});
                break;
        
        case 1201:
                sigName.LF_Tire_Temp_05 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_05"},7,16,.1,-100,true});
                sigName.LF_Tire_Temp_06 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_06"},23,16,.1,-100,true});
                sigName.LF_Tire_Temp_07 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_07"},39,16,.1,-100,true});
                sigName.LF_Tire_Temp_08 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_08"},55,16,.1,-100,true});
                break;
        
        case 1202:
                sigName.LF_Tire_Temp_09 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_09"},7,16,.1,-100,true});
                sigName.LF_Tire_Temp_10 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_10"},23,16,.1,-100,true});
                sigName.LF_Tire_Temp_11 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_11"},39,16,.1,-100,true});
                sigName.LF_Tire_Temp_12 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_12"},55,16,.1,-100,true});
                break;
        
        case 1203:
                sigName.LF_Tire_Temp_13 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_13"},7,16,.1,-100,true});
                sigName.LF_Tire_Temp_14 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_14"},23,16,.1,-100,true});
                sigName.LF_Tire_Temp_15 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_15"},39,16,.1,-100,true});
                sigName.LF_Tire_Temp_16 = decodeSignal(msg.buf, (struct Signal){{"LF_Tire_Temp_16"},55,16,.1,-100,true});
                break;
        
        case 1204:
                sigName.RF_Tire_Temp_01 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_01"},7,16,.1,-100,true});
                sigName.RF_Tire_Temp_02 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_02"},23,16,.1,-100,true});
                sigName.RF_Tire_Temp_03 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_03"},39,16,.1,-100,true});
                sigName.RF_Tire_Temp_04 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_04"},55,16,.1,-100,true});
                break;
        
        case 1205:
                sigName.RF_Tire_Temp_05 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_05"},7,16,.1,-100,true});
                sigName.RF_Tire_Temp_06 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_06"},23,16,.1,-100,true});
                sigName.RF_Tire_Temp_07 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_07"},39,16,.1,-100,true});
                sigName.RF_Tire_Temp_08 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_08"},55,16,.1,-100,true});
                break;
        
        case 1206:
                sigName.RF_Tire_Temp_09 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_09"},7,16,.1,-100,true});
                sigName.RF_Tire_Temp_10 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_10"},23,16,.1,-100,true});
                sigName.RF_Tire_Temp_11 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_11"},39,16,.1,-100,true});
                sigName.RF_Tire_Temp_12 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_12"},55,16,.1,-100,true});
                break;
        
        case 1207:
                sigName.RF_Tire_Temp_13 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_13"},7,16,.1,-100,true});
                sigName.RF_Tire_Temp_14 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_14"},23,16,.1,-100,true});
                sigName.RF_Tire_Temp_15 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_15"},39,16,.1,-100,true});
                sigName.RF_Tire_Temp_16 = decodeSignal(msg.buf, (struct Signal){{"RF_Tire_Temp_16"},55,16,.1,-100,true});
                break;
        
        case 1208:
                sigName.LR_Tire_Temp_01 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_01"},7,16,.1,-100,true});
                sigName.LR_Tire_Temp_02 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_02"},23,16,.1,-100,true});
                sigName.LR_Tire_Temp_03 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_03"},39,16,.1,-100,true});
                sigName.LR_Tire_Temp_04 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_04"},55,16,.1,-100,true});
                break;
        
        case 1209:
                sigName.LR_Tire_Temp_05 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_05"},7,16,.1,-100,true});
                sigName.LR_Tire_Temp_06 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_06"},23,16,.1,-100,true});
                sigName.LR_Tire_Temp_07 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_07"},39,16,.1,-100,true});
                sigName.LR_Tire_Temp_08 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_08"},55,16,.1,-100,true});
                break;
        
        case 1210:
                sigName.LR_Tire_Temp_09 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_09"},7,16,.1,-100,true});
                sigName.LR_Tire_Temp_10 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_10"},23,16,.1,-100,true});
                sigName.LR_Tire_Temp_11 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_11"},39,16,.1,-100,true});
                sigName.LR_Tire_Temp_12 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_12"},55,16,.1,-100,true});
                break;
        
        case 1211:
                sigName.LR_Tire_Temp_13 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_13"},7,16,.1,-100,true});
                sigName.LR_Tire_Temp_14 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_14"},23,16,.1,-100,true});
                sigName.LR_Tire_Temp_15 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_15"},39,16,.1,-100,true});
                sigName.LR_Tire_Temp_16 = decodeSignal(msg.buf, (struct Signal){{"LR_Tire_Temp_16"},55,16,.1,-100,true});
                break;
        
        case 1212:
                sigName.RR_Tire_Temp_01 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_01"},7,16,.1,-100,true});
                sigName.RR_Tire_Temp_02 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_02"},23,16,.1,-100,true});
                sigName.RR_Tire_Temp_03 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_03"},39,16,.1,-100,true});
                sigName.RR_Tire_Temp_04 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_04"},55,16,.1,-100,true});
                break;
        
        case 1213:
                sigName.RR_Tire_Temp_05 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_05"},7,16,.1,-100,true});
                sigName.RR_Tire_Temp_06 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_06"},23,16,.1,-100,true});
                sigName.RR_Tire_Temp_07 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_07"},39,16,.1,-100,true});
                sigName.RR_Tire_Temp_08 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_08"},55,16,.1,-100,true});
                break;
        
        case 1214:
                sigName.RR_Tire_Temp_09 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_09"},7,16,.1,-100,true});
                sigName.RR_Tire_Temp_10 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_10"},23,16,.1,-100,true});
                sigName.RR_Tire_Temp_11 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_11"},39,16,.1,-100,true});
                sigName.RR_Tire_Temp_12 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_12"},55,16,.1,-100,true});
                break;
        
        case 1215:
                sigName.RR_Tire_Temp_13 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_13"},7,16,.1,-100,true});
                sigName.RR_Tire_Temp_14 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_14"},23,16,.1,-100,true});
                sigName.RR_Tire_Temp_15 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_15"},39,16,.1,-100,true});
                sigName.RR_Tire_Temp_16 = decodeSignal(msg.buf, (struct Signal){{"RR_Tire_Temp_16"},55,16,.1,-100,true});
                break;
        
        // Brake Sensor Temps (single signal, 2 byte messages)
case 1224: // LF_IRTS_Brake_5
    sigName.LF_Sensor_Temp = decodeSignal(msg.buf, (Signal){{"LF_Sensor_Temp"}, 7, 16, 0.1f, -100.0f, false});
    break;

case 1229: // RF_IRTS_Brake_5
    sigName.RF_Sensor_Temp = decodeSignal(msg.buf, (Signal){{"RF_Sensor_Temp"}, 7, 16, 0.1f, -100.0f, false});
    break;

case 1234: // LR_IRTS_Brake_5
    sigName.LR_Sensor_Temp = decodeSignal(msg.buf, (Signal){{"LR_Sensor_Temp"}, 7, 16, 0.1f, -100.0f, false});
    break;

case 1239: // RR_IRTS_Brake_5
    sigName.RR_Sensor_Temp = decodeSignal(msg.buf, (Signal){{"RR_Sensor_Temp"}, 7, 16, 0.1f, -100.0f, false});
    break;

// LF Rotor Temps
case 1220: // LF_IRTS_Brake_1
    sigName.LF_Rotor_Temp_01 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_01"}, 7,  16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_02 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_02"}, 23, 16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_03 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_03"}, 39, 16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_04 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_04"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1221: // LF_IRTS_Brake_2
    sigName.LF_Rotor_Temp_05 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_05"}, 7,  16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_06 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_06"}, 23, 16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_07 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_07"}, 39, 16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_08 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_08"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1222: // LF_IRTS_Brake_3
    sigName.LF_Rotor_Temp_09 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_09"}, 7,  16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_10 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_10"}, 23, 16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_11 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_11"}, 39, 16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_12 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_12"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1223: // LF_IRTS_Brake_4
    sigName.LF_Rotor_Temp_13 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_13"}, 7,  16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_14 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_14"}, 23, 16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_15 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_15"}, 39, 16, 0.1f, -100.0f, false});
    sigName.LF_Rotor_Temp_16 = decodeSignal(msg.buf, (Signal){{"LF_Rotor_Temp_16"}, 55, 16, 0.1f, -100.0f, false});
    break;

// RF Rotor Temps
case 1225: // RF_IRTS_Brake_1
    sigName.RF_Rotor_Temp_01 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_01"}, 7,  16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_02 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_02"}, 23, 16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_03 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_03"}, 39, 16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_04 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_04"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1226: // RF_IRTS_Brake_2
    sigName.RF_Rotor_Temp_05 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_05"}, 7,  16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_06 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_06"}, 23, 16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_07 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_07"}, 39, 16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_08 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_08"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1227: // RF_IRTS_Brake_3
    sigName.RF_Rotor_Temp_09 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_09"}, 7,  16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_10 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_10"}, 23, 16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_11 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_11"}, 39, 16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_12 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_12"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1228: // RF_IRTS_Brake_4
    sigName.RF_Rotor_Temp_13 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_13"}, 7,  16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_14 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_14"}, 23, 16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_15 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_15"}, 39, 16, 0.1f, -100.0f, false});
    sigName.RF_Rotor_Temp_16 = decodeSignal(msg.buf, (Signal){{"RF_Rotor_Temp_16"}, 55, 16, 0.1f, -100.0f, false});
    break;

// LR Rotor Temps
case 1230: // LR_IRTS_Brake_1
    sigName.LR_Rotor_Temp_01 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_01"}, 7,  16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_02 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_02"}, 23, 16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_03 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_03"}, 39, 16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_04 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_04"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1231: // LR_IRTS_Brake_2
    sigName.LR_Rotor_Temp_05 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_05"}, 7,  16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_06 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_06"}, 23, 16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_07 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_07"}, 39, 16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_08 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_08"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1232: // LR_IRTS_Brake_3
    sigName.LR_Rotor_Temp_09 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_09"}, 7,  16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_10 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_10"}, 23, 16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_11 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_11"}, 39, 16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_12 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_12"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1233: // LR_IRTS_Brake_4
    sigName.LR_Rotor_Temp_13 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_13"}, 7,  16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_14 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_14"}, 23, 16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_15 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_15"}, 39, 16, 0.1f, -100.0f, false});
    sigName.LR_Rotor_Temp_16 = decodeSignal(msg.buf, (Signal){{"LR_Rotor_Temp_16"}, 55, 16, 0.1f, -100.0f, false});
    break;

// RR Rotor Temps
case 1235: // RR_IRTS_Brake_1
    sigName.RR_Rotor_Temp_01 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_01"}, 7,  16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_02 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_02"}, 23, 16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_03 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_03"}, 39, 16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_04 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_04"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1236: // RR_IRTS_Brake_2
    sigName.RR_Rotor_Temp_05 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_05"}, 7,  16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_06 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_06"}, 23, 16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_07 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_07"}, 39, 16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_08 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_08"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1237: // RR_IRTS_Brake_3
    sigName.RR_Rotor_Temp_09 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_09"}, 7,  16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_10 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_10"}, 23, 16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_11 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_11"}, 39, 16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_12 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_12"}, 55, 16, 0.1f, -100.0f, false});
    break;

case 1238: // RR_IRTS_Brake_4
    sigName.RR_Rotor_Temp_13 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_13"}, 7,  16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_14 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_14"}, 23, 16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_15 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_15"}, 39, 16, 0.1f, -100.0f, false});
    sigName.RR_Rotor_Temp_16 = decodeSignal(msg.buf, (Signal){{"RR_Rotor_Temp_16"}, 55, 16, 0.1f, -100.0f, false});
    break;
        default:
            // Unknown message ID
            break;
    }
}

void CAN_init(){
    can1.begin();
    can1.setBaudRate(1000000);
    can1.setMaxMB(16);
    can1.enableFIFO();
    can1.onReceive(processMessage);
    can1.setMaxMB(64);
}