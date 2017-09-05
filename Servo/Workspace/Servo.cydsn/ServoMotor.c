// author: Fan JIN

#include "ServoMotor.h"
#include "stdio.h"

void SetServoPosition(uint8 id, uint16 position, uint16 speed)
{
    // position ranges from 0x0000 to 0x03ff
    
    uint8 checksum;
    checksum = id + 0x07 + 0x03 + 0x1e + (position & 0xFF) + (position >> 8) + (speed & 0xff) + (speed >> 8);
    checksum ^= 0xFF;
    
    UART_1_PutChar(0xff);
    UART_1_PutChar(0xff);
    UART_1_PutChar(id);
    UART_1_PutChar(0x07);
    UART_1_PutChar(0x03);
    UART_1_PutChar(0x1e);
    UART_1_PutChar(position & 0xFF);
    UART_1_PutChar(position >> 8);
    UART_1_PutChar(speed & 0xff);
    UART_1_PutChar(speed >> 8);
    UART_1_PutChar(checksum);
    CyDelay(2);
}

void SetServoMode(uint8 id)
{
    uint8 checksum;
    
    checksum = id + 0x07 + 0x03 + 0x06 + 0x00 + 0xff + 0x03 + 0x00;
    checksum ^= 0xFF;
    
    switch (id)
    {
    case ID_TOP:
        UART_1_PutChar(0xff);
        UART_1_PutChar(0xff);
        UART_1_PutChar(id);
        UART_1_PutChar(0x07);
        UART_1_PutChar(0x03);
        UART_1_PutChar(0x06);
        UART_1_PutChar(0x00);
        UART_1_PutChar(0x00);
        UART_1_PutChar(0xff);
        UART_1_PutChar(0x03);
        UART_1_PutChar(checksum);
        break;
    }
    
    CyDelay(2);
    
}

void SetMotorMode(uint8 id)
{
    uint8 checksum;
    
    checksum = id + 0x07 + 0x03 + 0x06 + 0x00 + 0x00 + 0x00 + 0x00;
    checksum ^= 0xFF;
    
    switch (id)
    {
    case ID_LEFT:
        UART_2_PutChar(0xff);
        UART_2_PutChar(0xff);
        UART_2_PutChar(id);
        UART_2_PutChar(0x07);
        UART_2_PutChar(0x03);
        UART_2_PutChar(0x06);
        UART_2_PutChar(0x00);
        UART_2_PutChar(0x00);
        UART_2_PutChar(0x00);
        UART_2_PutChar(0x00);
        UART_2_PutChar(checksum);
        break;
        
    case ID_RIGHT:
        UART_3_PutChar(0xff);
        UART_3_PutChar(0xff);
        UART_3_PutChar(id);
        UART_3_PutChar(0x07);
        UART_3_PutChar(0x03);
        UART_3_PutChar(0x06);
        UART_3_PutChar(0x00);
        UART_3_PutChar(0x00);
        UART_3_PutChar(0x00);
        UART_3_PutChar(0x00);
        UART_3_PutChar(checksum);
        break;
    }
    
    CyDelay(2);
    
    
    
}

void SetMotorSpeed(uint8 id, int16 speed, uint8 acceleration)
{
    // speed ranges from -1023 to 1023
    
    if (speed > 1023)
        speed = 1023;
    
    if (speed < -1023)
        speed = -1023;
    
    if (speed < 0)
    {
        speed = -speed;
        speed |= 0x0400;
    }
    
    
    uint8 checksum;
    
    if (id == ID_LEFT)
    {
        checksum = id + 0x07 + 0x03 + 0x20 + (speed & 0xff) + (speed >> 8) + acceleration + acceleration;
        checksum ^= 0xff;
        
        UART_2_PutChar(0xff);
        UART_2_PutChar(0xff);
        UART_2_PutChar(id);
        UART_2_PutChar(0x07);
        UART_2_PutChar(0x03);
        UART_2_PutChar(0x20);
        UART_2_PutChar(speed & 0xff);
        UART_2_PutChar(speed >> 8);
        UART_2_PutChar(acceleration);
        UART_2_PutChar(acceleration);
        UART_2_PutChar(checksum);
        
        CyDelay(2);
    }
    else if (id == ID_RIGHT)
    {
        checksum = id + 0x07 + 0x03 + 0x20 + (speed & 0xff) + (speed >> 8) + acceleration + acceleration;
        checksum ^= 0xff;
        
        UART_3_PutChar(0xff);
        UART_3_PutChar(0xff);
        UART_3_PutChar(id);
        UART_3_PutChar(0x07);
        UART_3_PutChar(0x03);
        UART_3_PutChar(0x20);
        UART_3_PutChar(speed & 0xff);
        UART_3_PutChar(speed >> 8);
        UART_3_PutChar(acceleration);
        UART_3_PutChar(acceleration);
        UART_3_PutChar(checksum);
        
        CyDelay(2);
    }
}