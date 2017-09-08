/*******************************************************************************
* File Name: main.c
*
* Version: 2.0
*
* Description:
*  The SAR ADC and PrISM datasheet example project.
*  This example project demonstrates SAR ADC measurements and transferring
*  results using ISR and DMA to the LCD and PrISM.
*
* Note:
*  Pin_Vin pin (P1[4]) should be connected to the VR.
*  Pin_LED pin (P1[6]) should be connected to the LED.
*  Verify that VR_PWR(J11) is jumpered to ON.
*
* Hardware Dependency:
*  CY8C55 Family Processor
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
#include <stdio.h>
#include "ServoMotor.h"
#include "pid.h"
#include "Bluetooth.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

#define size 20

uint8 dataReady_L = 0u;
uint16 result_L[size] = {0};
uint8 dataReady_R = 0u;
uint16 result_R[size] = {0};

//extern uint16 ADC_L;
//extern uint16 ADC_R;

CY_ISR(ADC_SAR_R_ISR_LOC)
{
        ADC_R = CY_GET_REG16(ADC_SAR_R_SAR_WRK_PTR);
        dataReady_R = 1u;
}
CY_ISR(ADC_SAR_L_ISR_LOC)
{
        ADC_L = CY_GET_REG16(ADC_SAR_L_SAR_WRK_PTR);
        dataReady_L = 1u;
}

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Main function performs following functions:
*   1. Initialises the DMA to move data from ADC_SAR_1 work registers to the
*      PrISM pulse density registers.
*   2. Initialises the ISR connected to the DMA nrq terminal(DMA done).
*   3. Initialises the LCD.
*   4. Initialises the PrISM with 1Mhz clock.
*   5. Initialises the two SAR ADCs.
*   6. Displays the results of ADC_SAR_1 when DmaDone ISR rises.
*      The results are read from PrISM pulse density register.
*   7. Displays the results of ADC_SAR_2 when internal EOC ISR rises.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{
    int temp;
    char8 resultStr[16u];
    float res;
    float sum;
    uint16 L,R;
    /* Initializes the LCD. */
    LCD_Start();
    LCD_Position(0u,0u);
    LCD_PrintString("ADC1=      V");
    LCD_Position(1u,0u);
    LCD_PrintString("ADC2=      V");



    ADC_SAR_L_Start();
    ADC_SAR_L_IRQ_StartEx(ADC_SAR_L_ISR_LOC);
    ADC_SAR_L_StartConvert();
    ADC_SAR_R_Start();
    ADC_SAR_R_IRQ_StartEx(ADC_SAR_R_ISR_LOC);
    ADC_SAR_R_StartConvert();
    CyGlobalIntEnable;
    
    UART_1_Start();
    UART_2_Start();
    UART_3_Start();
    UART_6_Start();
    
    SetServoMode(_TOP);
    SetMotorMode(_LEFT);
    SetMotorMode(_RIGHT);
    CyDelay(100);

    for(;;)
    {
        
        GetBluetoothString(buffer);
        if (buffer[0] != '\0')
        {
            
            sscanf(buffer, "%d", &temp);
            
            if (temp >= -80 && temp <= -20)
            {
                bias = temp;
            }
            LCD_ClearDisplay();
            LCD_PrintString(buffer);
        }
        
        
        
        uint8 i,j;
        if(dataReady_L != 0u)
        {
            sum = 0;
            res = ADC_SAR_L_CountsTo_Volts(ADC_L);
            sprintf((char *)resultStr,"%+1.2f",res);
            for(j=0;j<size-1;j++)
            {
                result_L[j] = result_L[j+1];
                sum += result_L[j+1];
            }
            result_L[size - 1] = ADC_L;
            sum = (sum+ADC_L)/size;
            L = sum;
            LCD_Position(0u,5u);
            LCD_PrintString("     ");
            //LCD_PrintString(resultStr);
            LCD_Position(0u,5u);
            LCD_PrintNumber(L);
            dataReady_L = 0u;
            //CyDelay(1);
        }
        if(dataReady_R != 0u)
        {
            sum = 0;
            res = ADC_SAR_R_CountsTo_Volts(ADC_R);
            sprintf((char *)resultStr,"%+1.2f",res);
            for(j=0;j<size-1;j++)
            {
                result_R[j] = result_R[j+1];
                sum += result_R[j+1];
            }
            result_R[size - 1] = ADC_R;
            sum = (sum+ADC_R)/size;
            R = sum;
            LCD_Position(1u,5u);
            LCD_PrintString("     ");
            LCD_Position(1u,5u);
            //LCD_PrintString(resultStr);
            LCD_PrintNumber(R);
            dataReady_R = 0u;
            //CyDelay(1);
        }
        //SetServoPosition(_TOP, 512, 0x01ff);
        PID();
        CyDelay(2);
    }
}


/* [] END OF FILE */
