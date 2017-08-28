/******************************************************************************
* File Name: Main.c
* Version 1.1
*
* Description:
* This file contains the main function for the CapSense test.
*
* Note:
*
* Code tested with:
* PSoC Creator: 3.0
* Device Tested With: CY8C5868AXI-LP035
* Compiler    : ARMGCC 4.4.1, ARM RVDS Generic , ARM MDK Generic
*
********************************************************************************
* Copyright (2013), Cypress Semiconductor Corporation. All Rights Reserved.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress)
* and is protected by and subject to worldwide patent protection (United
* States and foreign), United States copyright laws and international treaty
* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
* non-transferable license to copy, use, modify, create derivative works of,
* and compile the Cypress Source Code and derivative works for the sole
* purpose of creating custom software in support of licensee product to be
* used only in conjunction with a Cypress integrated circuit as specified in
* the applicable agreement. Any reproduction, modification, translation,
* compilation, or representation of this software except as specified above 
* is prohibited without the express written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. 
*
* Use of this Software may be limited by and subject to the applicable Cypress
* software license agreement. 
*******************************************************************************/

/******************************************************************************
*                           THEORY OF OPERATION
* This project demonstrates the capsense application using on board 5 segment 
* capsense slider and 2 capsense buttons. The button state is displayed on the LCD
* as on or off. Finger position on the slider is displayed as 0 - 100%. If no 
* finger is there the slider position is displayed as "----".
*
* Hardware connection on the Kit
* Slider - P5[0] - P5[4]
* Button1 - P5[5]
* Button2 - P5[6]
* LCD 2[0-6]
******************************************************************************/ 
#include <device.h>
#include <project.h>

#include "stdio.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

/* Define constants for capsense button and slider */
#define ON           (1)
#define OFF          (0)
#define NO_FINGER    (0xFF)

int main()
{
    uint8 buffer[5] = "xxx\r\n";
    uint8 statusButton0 = OFF;
    uint8 statusButton1 = OFF;
    uint16 sliderPosition = NO_FINGER;
    uint16 lastPosition = NO_FINGER;
    
    uint16 lastFlux = 50;
    uint16 count = 0;
    
    CYGlobalIntEnable; 
    
    PWM_Start();
    
    USBUART_1_Start(0u, USBUART_1_3V_OPERATION);

    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("Btn0 Btn1 Slider");

    /* Start capsense and initialize baselines and enable scan */
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    
    
    /* Wait for Device to enumerate */
    // while(!USBUART_1_GetConfiguration());

    /* Enumeration is done, enable OUT endpoint for receive data from Host */
    USBUART_1_CDC_Init();
    

    while(1)
    {
        count++;
        PWM_WriteCompare((uint8)((float)lastFlux / 100 * 255));
        buffer[0] = '0' + (lastFlux / 100 % 10);
        buffer[1] = '0' + (lastFlux / 10 % 10);
        buffer[2] = '0' + (lastFlux / 1 % 10);
        
        // while(USBUART_1_CDCIsReady() == 0u);    /* Wait till component is ready to send more data to the PC */ 
        if (count % 100 == 0)
        {
            // USBUART_1_PutData(buffer, 5);       /* Send data back to PC */
        }
        
        
        
        /* Update baseline for all the sensors */
        CapSense_UpdateEnabledBaselines();
		
	    CapSense_ScanEnabledWidgets();
		/* If scanning is completed update the baseline count and check if sensor is active */  
        while(CapSense_IsBusy() != 0)
        {

            /* Test if button widget is active */
            statusButton0 = CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN);
            statusButton1 = CapSense_CheckIsWidgetActive(CapSense_BUTTON1__BTN);
            sliderPosition =(uint8)CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS);

            /* Display button 1 status on LCD */
            LCD_Position(1,0);
            if( statusButton0 == ON )
            {
                LCD_PrintString("On ");
            }
            else
            {
                LCD_PrintString("Off");
            }

            /* Display button 1 status on LCD */
            LCD_Position(1,5);
            if( statusButton1 == ON )
            {
                LCD_PrintString("On ");
            }
            else
            {
                LCD_PrintString("Off");
            }

		    LCD_Position(1,10);
            
		    if(sliderPosition == NO_FINGER)
            {
                LCD_PrintString("----");
				lastPosition = NO_FINGER;
            }
            
            /* Finger detected on the slider */
            else
            {
                /* If finger position on the slider is changed then update the LCD */
                if(sliderPosition != lastPosition)
                {
                    LCD_Position(1,10);
                    LCD_PrintString("    ");
                    LCD_Position(1,10);
                    LCD_PrintNumber(sliderPosition);
                    LCD_PutChar('%');
                    lastPosition = sliderPosition; 
                    lastFlux = sliderPosition;
                }
            }
        }
    }    
}

/* [] END OF FILE */


