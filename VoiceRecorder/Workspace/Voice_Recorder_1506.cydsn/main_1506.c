
#include <device.h>

#define THRESHOLD (1)
#define PackageSize (0x40)
#define BufferSize (0x8000)
#define PackageNumber (BufferSize / PackageSize)

uint8 buffer[BufferSize + 0xF];
uint8 package[PackageSize + 0xF];

void PrintString(const char8 *str);
void Init();


int main()
{
    int32 i;
    int32 j;
    register int8 Voltage;
    register int8 lastVoltage;
    int32 length;
    
    Init();

    while (1) // main loop
    {
        if (USBUART_1506_DataIsReady() != 0u)
        {
            USBUART_1506_GetAll(package);
            
            if (package[0] == 0x00) // start recording
            {
                PrintString("Recording");
                
                for (i = 0; ; i = (i + 1) % BufferSize)
                {
                    if (USBUART_1506_DataIsReady() != 0u)
                    {
                        USBUART_1506_GetAll(package);
                        if (package[0] == 0x00)
                        {
                            PrintString("Ready");
                            break;
                        }
                    }
                    if (i % PackageSize == 0)
                    {
                        while(USBUART_1506_CDCIsReady() == 0u);
                        USBUART_1506_PutData(package, PackageSize);
                    }
                    
                    ADC_1506_IsEndConversion(ADC_1506_WAIT_FOR_RESULT);
                    Voltage = ADC_1506_GetResult8();
                    
                    if (Voltage > lastVoltage + THRESHOLD)
                    {
                        Voltage = lastVoltage + THRESHOLD;
                    }
                    if (Voltage < lastVoltage - THRESHOLD)
                    {
                        Voltage = lastVoltage - THRESHOLD;
                    }
                    lastVoltage = Voltage;
                    
                    buffer[i] = Voltage;
                    package[i % PackageSize] = Voltage;
                    
                }
                
            }
            else if (package[0] == 0x01) // replay the current buffer
            {
                PrintString("Replaying");
                for (i = 0; i < BufferSize; i++)
                {
                    ADC_1506_IsEndConversion(ADC_1506_WAIT_FOR_RESULT);
                    ADC_1506_GetResult8();
                    VDAC_1506_SetValue(buffer[i]);
                }
                PrintString("Ready");
            }
            else if (package[0] == 0x02) // transfer and play the record in hexadecimal
            {
                PrintString("Playing");
                length = (((int32)package[1]) << 24) | (((int32)package[2]) << 16) | (((int32)package[3]) << 8) | (((int32)package[4]) << 0);
                for (i = 0, j = 5; i < length; i++, j++)
                {
                    if (j == PackageSize)
                    {
                        while (USBUART_1506_DataIsReady() == 0u);
                        USBUART_1506_GetAll(package);
                        j = 0;
                    }
                    ADC_1506_IsEndConversion(ADC_1506_WAIT_FOR_RESULT);
                    ADC_1506_GetResult8();
                    VDAC_1506_SetValue(package[j]);
                }
                PrintString("Ready");
            }
            else if (package[0] == 0x03) // direct access
            {
                PrintString("Direct Access");
                while (1)
                {
                    if (USBUART_1506_DataIsReady() != 0u)
                    {
                        USBUART_1506_GetAll(package);
                        if (package[0] == 0x03)
                        {
                            break;
                        }
                    }
                    ADC_1506_IsEndConversion(ADC_1506_WAIT_FOR_RESULT);
                    Voltage = ADC_1506_GetResult8();
                    VDAC_1506_SetValue(Voltage);
                }
                PrintString("Ready");
            }
        }
    }
    
}

void PrintString(const char8 *str)
{
    LCD_1506_ClearDisplay();
    CyDelay(100);
    LCD_1506_PrintString(str);
    CyDelay(100);
}

void Init()
{
    /* Enable Global Interrupts */
    CyGlobalIntEnable;    
    
	/* Initialization */
	LCD_1506_Start();
    ADC_1506_Start();               
    VDAC_1506_Start();             
    Opamp_1506_Start();
    USBUART_1506_Start(0u, USBUART_1506_3V_OPERATION);
    
    PrintString("");
    
    while (!USBUART_1506_GetConfiguration());
    USBUART_1506_CDC_Init();
	
    ADC_1506_StartConvert();
    
    PrintString("Ready");
}

