#include "CAN.hpp"

// 22 CAN1 TX 
// 23 CAN RX
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;

FlexCAN_T4 CAN_begin(){
    can1.begin();
    can1.setBaudRate(1000000);
    can1.setMaxMB(16);
    can1.enableFIFO();
    can1.enableFIFOInterrupt();
    can1.onReceive(canSniff);
    can1.mailboxStatus();
}
