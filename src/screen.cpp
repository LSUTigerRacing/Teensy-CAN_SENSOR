#include "screen.hpp"

LCD_I2C lcd(0x27);

uint8_t currentPage =0;
uint32_t lastChange;

void LCD_init(){
    lcd.begin();
    lcd.backlight();
    lcd.clear();
}

void LCD_Update(){
    enum PAGES{
        MOTOR1,
        MOTOR2,
        MOTOR3,
        MOTOR4,
        MOTOR5,
        BMS1,
        BMS2,
    };
    if(millis() - lastChange > 2500){
        lastChange =millis();
        currentPage++;
        lcd.clear();
    }

    switch(currentPage){
        case MOTOR1:
            lcd.setCursor(0,0);
            lcd.printf("MC Temp: %3f",sigName.MC_Temp);
            lcd.setCursor(0,1);
            lcd.printf("Motor Temp: %3f",sigName.Motor_Temp);
            break;
        
        case MOTOR2:
            lcd.setCursor(0,0);
            lcd.printf("AC Curr: %3f",sigName.AC_Current);
            lcd.setCursor(0,1);
            lcd.printf("DC Curr: %3f",sigName.DC_Current);
            break;

        case MOTOR3:
            lcd.setCursor(0,0);
            lcd.printf("MC Temp: %3f",sigName.MC_Temp);
            lcd.setCursor(0,1);
            lcd.printf("Motor Temp: %3f",sigName.Motor_Temp);
            break;
        
        case MOTOR4:
            lcd.setCursor(0,0);
            lcd.printf("Duty Cycle: %3f",sigName.DUTY_CYCLE);
            lcd.setCursor(0,1);
            lcd.printf("MC in volt: %3f",sigName.MC_INPUT_V);
            break;

        case MOTOR5:
            lcd.setCursor(0,0);
            lcd.printf("MC Throt: %3f",sigName.MC_Throttle);
            lcd.setCursor(0,1);
            lcd.printf("Fault Code: %3f",sigName.Fault_Code);
            break;

        case BMS1:
            lcd.setCursor(0,0);
            lcd.printf("Pack Curr: %3f",sigName.Pack_Current);
            lcd.setCursor(0,1);
            lcd.printf("Pack Volt: %3f",sigName.Pack_Insta_Volta);
            break;
        
        case BMS2:
            lcd.setCursor(0,0);
            lcd.printf("Cell High: %3f",sigName.Cell_High);
            lcd.setCursor(0,1);
            lcd.printf("Cell Low: %3f",sigName.Cell_Low);
            break;
    }
}