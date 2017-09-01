
#include <device.h>


#define PackageSize (0x40)
#define BufferSize (0x8000)
#define PackageNumber (BufferSize / PackageSize)

uint8 buffer[BufferSize + 0xF];
uint8 package[PackageSize + 0xF];

void PrintString(const char8 *str);
void Init();


int main()
{
    int i;
    int j;
    register int8 Voltage;
    
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
                        if (package[0] == 0x01)
                        {
                            PrintString("Recorded");
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
                    buffer[i] = Voltage;
                    package[i % PackageSize] = Voltage;
                    
                }
                
            }
            else if (package[0] == 0x02) // replay the current buffer
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
            else if (package[0] == 0x03)
            {
                
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

