// author: Fan JIN

#include "ServoMotor.h"
#include "stdio.h"

void SetServoPosition(uint8 id, uint16 position, uint16 speed)
{
    // position ranges from 0x0000 to 0x03ff
    
    uint8 checksum;
    checksum = ID + 0x07 + 0x03 + 0x1e + (position & 0xFF) + (position >> 8) + (speed & 0xff) + (speed >> 8);
    checksum ^= 0xFF;
    
    if (id == _TOP)
    {
        UART_1_PutChar(0xff);
        UART_1_PutChar(0xff);
        UART_1_PutChar(ID);
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
}

void SetServoMode(uint8 id)
{
    uint8 checksum;
    
    checksum = ID + 0x07 + 0x03 + 0x06 + 0x00 + 0xff + 0x03 + 0x00;
    checksum ^= 0xFF;
    
    if (id == _TOP)
    {
        UART_1_PutChar(0xff);
        UART_1_PutChar(0xff);
        UART_1_PutChar(ID);
        UART_1_PutChar(0x07);
        UART_1_PutChar(0x03);
        UART_1_PutChar(0x06);
        UART_1_PutChar(0x00);
        UART_1_PutChar(0x00);
        UART_1_PutChar(0xff);
        UART_1_PutChar(0x03);
        UART_1_PutChar(checksum);
    }
    
    CyDelay(2);
    
}

void SetMotorMode(uint8 id)
{
    uint8 checksum;
    
    checksum = ID + 0x07 + 0x03 + 0x06 + 0x00 + 0x00 + 0x00 + 0x00;
    checksum ^= 0xFF;
    
    if (id == _LEFT)
    {
        UART_2_PutChar(0xff);
        UART_2_PutChar(0xff);
        UART_2_PutChar(ID);
        UART_2_PutChar(0x07);
        UART_2_PutChar(0x03);
        UART_2_PutChar(0x06);
        UART_2_PutChar(0x00);
        UART_2_PutChar(0x00);
        UART_2_PutChar(0x00);
        UART_2_PutChar(0x00);
        UART_2_PutChar(checksum);
    }
        
    if (id == _RIGHT)
    {
        UART_3_PutChar(0xff);
        UART_3_PutChar(0xff);
        UART_3_PutChar(ID);
        UART_3_PutChar(0x07);
        UART_3_PutChar(0x03);
        UART_3_PutChar(0x06);
        UART_3_PutChar(0x00);
        UART_3_PutChar(0x00);
        UART_3_PutChar(0x00);
        UART_3_PutChar(0x00);
        UART_3_PutChar(checksum);
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
    
    if (id == _LEFT)
    {
        checksum = ID + 0x06 + 0x03 + 0x20 + (speed & 0xff) + (speed >> 8) + acceleration;
        checksum ^= 0xff;
        
        UART_2_PutChar(0xff);
        UART_2_PutChar(0xff);
        UART_2_PutChar(ID);
        UART_2_PutChar(0x06);
        UART_2_PutChar(0x03);
        UART_2_PutChar(0x20);
        UART_2_PutChar(speed & 0xff);
        UART_2_PutChar(speed >> 8);
        UART_2_PutChar(acceleration);
        UART_2_PutChar(checksum);
        
        CyDelay(2);
    }
    
    if (id == _RIGHT)
    {
        checksum = ID + 0x06 + 0x03 + 0x20 + (speed & 0xff) + (speed >> 8) + acceleration;
        checksum ^= 0xff;
        
        UART_3_PutChar(0xff);
        UART_3_PutChar(0xff);
        UART_3_PutChar(ID);
        UART_3_PutChar(0x06);
        UART_3_PutChar(0x03);
        UART_3_PutChar(0x20);
        UART_3_PutChar(speed & 0xff);
        UART_3_PutChar(speed >> 8);
        UART_3_PutChar(acceleration);
        UART_3_PutChar(checksum);
        
        CyDelay(2);
    }
}

void GetMotorSpeed(uint8 id, int16 *speed)
{
    uint8 checksum;
    uint8 low;
    uint8 high;
    uint16 temp;
    
    if (id == _LEFT)
    {
        checksum = ID + 0x04 + 0x02 + 0x26 + 0x02;
        checksum ^= 0xff;
        
        UART_2_PutChar(0xff);
        UART_2_PutChar(0xff);
        UART_2_PutChar(ID);
        UART_2_PutChar(0x04);
        UART_2_PutChar(0x02);
        UART_2_PutChar(0x26);
        UART_2_PutChar(0x02);
        UART_2_PutChar(checksum);
        
        UART_2_GetChar();
        UART_2_GetChar();
        UART_2_GetChar();
        UART_2_GetChar();
        UART_2_GetChar();
        low = UART_2_GetChar();
        high = UART_2_GetChar();
        UART_2_GetChar();
        
        temp = (((uint16)high) << 8) | (uint16)low;
        
        if (temp & 0x0400)
        {
            temp &= 0xfbff;
            *speed = ((int16)temp);
        }
        else
        {
            *speed = ((int16)temp);
        }
        
    }
    
    if (id == _RIGHT)
    {
        checksum = ID + 0x04 + 0x02 + 0x26 + 0x02;
        checksum ^= 0xff;
        
        UART_3_PutChar(0xff);
        UART_3_PutChar(0xff);
        UART_3_PutChar(ID);
        UART_3_PutChar(0x04);
        UART_3_PutChar(0x02);
        UART_3_PutChar(0x26);
        UART_3_PutChar(0x02);
        UART_3_PutChar(checksum);
        
        UART_3_GetChar();
        UART_3_GetChar();
        UART_3_GetChar();
        UART_3_GetChar();
        UART_3_GetChar();
        low = UART_3_GetChar();
        high = UART_3_GetChar();
        UART_3_GetChar();
        
        temp = (((uint16)high) << 8) | (uint16)low;
        
        if (temp & 0x0400)
        {
            temp &= 0xfbff;
            *speed = ((int16)temp);
        }
        else
        {
            *speed = ((int16)temp);
        }
        
    }
    
}

void GetServoPosition(uint8 id, uint16 *position)
{
    uint8 checksum;
    uint8 low;
    uint8 high;
    uint16 temp;
    
    if (id == _TOP)
    {
        checksum = ID + 0x04 + 0x02 + 0x24 + 0x02;
        checksum ^= 0xff;
        
        UART_1_PutChar(0xff);
        UART_1_PutChar(0xff);
        UART_1_PutChar(ID);
        UART_1_PutChar(0x04);
        UART_1_PutChar(0x02);
        UART_1_PutChar(0x24);
        UART_1_PutChar(0x02);
        UART_1_PutChar(checksum);
        
        UART_1_GetChar();
        UART_1_GetChar();
        UART_1_GetChar();
        UART_1_GetChar();
        UART_1_GetChar();
        low = UART_1_GetChar();
        high = UART_1_GetChar();
        UART_1_GetChar();
        
        temp = (((uint16)high) << 8) | (uint16)low;
        *position = temp;
        
    }
    
}