/*******************************************************************************
* File Name: main.c
*
* Version: 2.1
*
* Description:
*  This project demonstrates the UART reception mechanism. 
*  Data typed on the hyperterminal is sent through serial port and displayed
*  on the LCD.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>

#include "Bluetooth.h"

#define LCD_NUM_COLUMNS (16u)


int main()
{   
    char8 ch;       /* Data received from the Serial port */
    uint8 count = 0u;
    uint8 pos = 0u;

    CyGlobalIntEnable; /* Enable all interrupts by the processor. */

    LCD_Char_1_Start();
    UART_1_Start();
    
    while(1)
    {
        GetBluetoothString(buffer);
        
        LCD_Char_1_Position(0u, 0);
        LCD_Char_1_PrintString("                ");
        CyDelay(5);
        LCD_Char_1_Position(0u, 0);
        LCD_Char_1_PrintString(buffer); 
        CyDelay(20);
        
    }
}


/* [] END OF FILE */
