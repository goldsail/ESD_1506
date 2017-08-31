
#include <device.h>

#define THREASHOLD (32)

int main()
{
    register int8 currVoltage;
    register int8 lastVoltage;
    
	/* Initialization */
	LCD_1506_Start();
    ADC_1506_Start();               
    VDAC_1506_Start();             
    Opamp_1506_Start();
	
	/* Print Hello World on LCD */
	LCD_1506_PrintString("Hello World");
    
    ADC_1506_StartConvert();

    /* Loop forever */
	for(;;)
    {
        lastVoltage = currVoltage;
        ADC_1506_IsEndConversion(ADC_1506_WAIT_FOR_RESULT);
        currVoltage = ADC_1506_GetResult8();
        if (currVoltage > lastVoltage + THREASHOLD)
        {
            currVoltage = lastVoltage + THREASHOLD;
        }
        if (currVoltage < lastVoltage - THREASHOLD)
        {
            currVoltage = lastVoltage - THREASHOLD;
        }
        VDAC_1506_SetValue(currVoltage);
    }
}

