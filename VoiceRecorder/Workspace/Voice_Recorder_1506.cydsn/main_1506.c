
#include <device.h>

#define THREASHOLD (4)

#define PackageSize (0x40)
#define buffer_len (0x8000)
#define PackageNumber (buffer_len / PackageSize)

uint8 buffer[buffer_len];
uint8 buf[PackageSize + 0xF];


int main()
{
    int i;
    int j;
    register int8 currVoltage;
    register int8 lastVoltage;
    register int8 Voltage;
    int count;
    
    /* Enable Global Interrupts */
    CyGlobalIntEnable;    
    
	/* Initialization */
	LCD_1506_Start();
    ADC_1506_Start();               
    VDAC_1506_Start();             
    Opamp_1506_Start();
    USBUART_1506_Start(0u, USBUART_1506_3V_OPERATION);
    LCD_1506_ClearDisplay();
    CyDelay(100);
    while (!USBUART_1506_GetConfiguration());
    USBUART_1506_CDC_Init();
	
    ADC_1506_StartConvert();
    
    LCD_1506_PrintString("Ready");

    while (1)
    {
        if (USBUART_1506_DataIsReady() != 0u)
        {
            count = USBUART_1506_GetAll(buf);
            LCD_1506_PrintNumber(count);
            
            if (buf[0] == '0') // start recording
            {
                LCD_1506_ClearDisplay();
                CyDelay(100);
                LCD_1506_PrintString("Recording");
                CyDelay(100);
                
                for(i = 0; i < buffer_len; i++)
                {
                    lastVoltage = currVoltage;
                    ADC_1506_IsEndConversion(ADC_1506_WAIT_FOR_RESULT);
                    currVoltage = ADC_1506_GetResult8();
                    Voltage = currVoltage;
                    if (Voltage > lastVoltage + THREASHOLD)
                    {
                        Voltage = lastVoltage + THREASHOLD;
                    }
                    if (Voltage < lastVoltage - THREASHOLD)
                    {
                        Voltage = lastVoltage - THREASHOLD;
                    }
                    buffer[i] = Voltage;
                }
                
                LCD_1506_ClearDisplay();
                CyDelay(100);
                LCD_1506_PrintString("Transferring");
                CyDelay(100);
                
                for (i = 0; i < PackageNumber; i++)
                {
                    while(USBUART_1506_CDCIsReady() == 0u);
                    USBUART_1506_PutData(&buffer[i * PackageSize], PackageSize);
                }
                
                LCD_1506_ClearDisplay();
                CyDelay(100);
                LCD_1506_PrintString("Transferred");
                CyDelay(100);
            }
            else
            {
                LCD_1506_ClearDisplay();
                CyDelay(100);
                LCD_1506_PrintString("Replaying");
                CyDelay(100);
                for (i = 0; i < buffer_len; i++)
                {
                    ADC_1506_IsEndConversion(ADC_1506_WAIT_FOR_RESULT);
                    ADC_1506_GetResult8();
                    VDAC_1506_SetValue(buffer[i]);
                }
                LCD_1506_ClearDisplay();
                CyDelay(100);
                LCD_1506_PrintString("Ready");
                CyDelay(100);
            }
            
        }
    }
    
}

