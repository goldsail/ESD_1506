//************* temperature.c ********************
// Ӳ�����ӣ�/
// ʵ������ OLED����ʾ�Դ��¶ȴ������Ķ���������UART���͸�����
//**************************************************

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/fpu.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/pin_map.h"
#include "grlib/grlib.h"
#include "drivers/cfal96x64x16.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"
#include "inc/hw_gpio.h"

#include "inc/hw_ints.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/uart.h"


#include <math.h>

// ���ڽ����жϷ������
void UARTIntHandler(void)
{
    unsigned long ulStatus;
    // ��ȡ�ж�״̬
    ulStatus = ROM_UARTIntStatus(UART0_BASE, true);
    // ����жϱ�־
    ROM_UARTIntClear(UART0_BASE, ulStatus);
    // ֱ������FIFO��û������ʱ���˳�ѭ��
    while(ROM_UARTCharsAvail(UART0_BASE))
    {
        // �����ڽ��յ��ַ����ط�
        ROM_UARTCharPutNonBlocking(UART0_BASE,
                        ROM_UARTCharGetNonBlocking(UART0_BASE));
    }
}

//  ���ڷ��ͺ���
void UARTSend(const unsigned char *pucBuffer, unsigned long ulCount)
{
    while(ulCount--)
    {
        // ��Ҫ���͵��ַ�д��UART
        ROM_UARTCharPutNonBlocking(UART0_BASE, *pucBuffer++);
    }
}


int main(void)
{
	int flag = 0;
	int lastTemperature;


    tContext sContext;
    tRectangle sRect;
    unsigned long ulADC0_Value;
    unsigned char ulADC0_v[8];
    unsigned char ulADC0_UART[100] = "xxxx.xx\r\n";
    const char chars[16]={"0123456789ABCDEF"};
    float fTemperature;
    int dTemperature;

    // ʹ��FPU
    FPUEnable();
    FPULazyStackingEnable();

    // ����ϵͳʱ��Ϊ50MHz (400/2/4=50)
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    //

    /*
    // ����ʱ��ֱ��ʹ���ⲿ����
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                           SYSCTL_XTAL_16MHZ);
                           */

	// ʹ���õ�������
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    // ����PA0��PA1Ϊ����0����
	ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	// ʹ���ж�
	// ROM_IntMasterEnable();

	// ����UART0Ϊ115200,8-N-1
	ROM_UARTConfigSetExpClk(UART0_BASE, ROM_SysCtlClockGet(), 115200,
						   (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
							 UART_CONFIG_PAR_NONE));
	// ʹ�ܴ����ж�
	// ROM_IntEnable(INT_UART0);
	// ROM_UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);

	//

    // ��ʼ��ADC0/PE3
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    // ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_7);
    // ����ADC�ο���ѹΪ�ⲿ3V
    ROM_ADCReferenceSet(ADC0_BASE, ADC_REF_EXT_3V);
    // ����ADC�ɼ�����
    ROM_ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
    // ROM_ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0 | ADC_CTL_END | ADC_CTL_IE);
    ROM_ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH20 | ADC_CTL_END | ADC_CTL_IE);
    // ʹ��ADC�ɼ�����
    ROM_ADCSequenceEnable(ADC0_BASE, 0);
    ROM_ADCIntClear(ADC0_BASE, 0);
    ROM_ADCIntEnable(ADC0_BASE, 0);

    // ��ʼ����ʾģ��
    CFAL96x64x16Init();
    GrContextInit(&sContext, &g_sCFAL96x64x16);

    while(1)
    {
    	// �����ɼ�
    	ADCProcessorTrigger(ADC0_BASE, 0);
    	// �ȴ��ɼ�����
    	while(!ADCIntStatus(ADC0_BASE, 0, false)) ;
    	// ��ȡ�ɼ����
    	ADCSequenceDataGet(ADC0_BASE, 0, &ulADC0_Value);
        // ���ɼ������32λ�޷�����ת��Ϊchar

    	// reference voltage 3V, ADC range from 0 to 4095 (12-digit precision)
    	fTemperature = (((float)ulADC0_Value) / 4095) * 3;
    	// dTemperature = -1481.96 + sqrtf((219262 + 1.8639 - fTemperature) / (3.88 * 0.00001));
    	dTemperature = 100 * 1000 * (1.8663 - fTemperature) / (11.69);

    	// use a linear filter to diminish noise
    	if (flag)
    	{
    		dTemperature = 0.95 * (float)lastTemperature + 0.05 * (float)dTemperature;
    	}
    	else
    	{
    		flag = 1;
    	}
    	lastTemperature = dTemperature;

    	ulADC0_v[0] = '0';
		ulADC0_v[1] = chars[(dTemperature / 100000) % 10];
		ulADC0_v[2] = chars[(dTemperature / 10000) % 10];
		ulADC0_v[3] = chars[(dTemperature / 1000) % 10];
        ulADC0_v[4] = chars[(dTemperature / 100) % 10];
        ulADC0_v[5] = '.';
        ulADC0_v[6] = chars[(dTemperature / 10) % 10];
        ulADC0_v[7] = chars[(dTemperature / 1) % 10];

        ulADC0_UART[0] = ulADC0_v[0];
        ulADC0_UART[1] = ulADC0_v[1];
        ulADC0_UART[2] = ulADC0_v[2];
        ulADC0_UART[3] = ulADC0_v[3];
        ulADC0_UART[4] = ulADC0_v[4];
        ulADC0_UART[5] = ulADC0_v[5];
        ulADC0_UART[6] = ulADC0_v[6];
        ulADC0_UART[7] = ulADC0_v[7];


        // ��ʱ
    	SysCtlDelay(SysCtlClockGet() / 12);

        // ��Ļ������24�������ɫ�����ϴε���ʾ���
        sRect.sXMin = 0;
        sRect.sYMin = 0;
        sRect.sXMax = GrContextDpyWidthGet(&sContext) - 1;
        sRect.sYMax = 23;
        GrContextForegroundSet(&sContext, ClrDarkKhaki);
        GrRectFill(&sContext, &sRect);

        // ����ɫ��ı�Ե���ð׿�
        GrContextForegroundSet(&sContext, ClrWhite);
        GrRectDraw(&sContext, &sRect);

        // ��ʾ�������ƺͲɼ����
        GrContextFontSet(&sContext, g_pFontCm12);
        GrStringDrawCentered(&sContext, ulADC0_v, 8,
                             GrContextDpyWidthGet(&sContext) / 2, 10, 0);
        GrStringDrawCentered(&sContext, "Temperature", -1,
                             GrContextDpyWidthGet(&sContext) / 2,
                             ((GrContextDpyHeightGet(&sContext) - 24) / 2) + 30,
                             0);
        GrStringDrawCentered(&sContext, "(degrees decimal)", -1,
                                     GrContextDpyWidthGet(&sContext) / 2,
                                     ((GrContextDpyHeightGet(&sContext) - 24) / 2) + 12,
                                     0);

        // ������ʾ
        GrFlush(&sContext);


        UARTSend((unsigned char *)ulADC0_UART, 10);
    }
}

