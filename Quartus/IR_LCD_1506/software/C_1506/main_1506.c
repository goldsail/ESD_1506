/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include "system.h"
#include "LCD_1506_Qsys.h"
#include "sys/alt_irq.h"

unsigned char LCD_Data[17] = {"IR_1506  waiting"};


unsigned int *pUser_IR = IR_1506_BASE; //����ָ��ָ����Qsys�����ɵ�IR����ģ��
unsigned int IR_Data;
unsigned char Data_Ready;

unsigned char numberConvert[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void IR_Handler()
{
	Data_Ready = 1;
	IR_Data = *(pUser_IR);
}

int IR_Init()
{
	/*��Ҫ��ʾ�� 2017.07.12
	 * 1.��ע���жϺ���ʱ���жϿ�������ź�Ӳ���жϺ���������ֱ�Ӵ�system.h����
	 * 2.��Quartus15.0��֮ǰ�İ汾�У����ɵ�system.h�ļ���Bug,���������ж�����źŵ�ģ�飬���жϿ�������ź�Ӳ���жϺ�
	 *   Ϊ-1��
	 * 3.��Ҫ�ֶ��޸�system.h���жϿ�������ź�Ӳ���жϺţ��úſ�����Qsys�п�����������������ͬ��
	 * */
    int States;
    States = alt_ic_isr_register(
    		 IR_1506_IRQ_INTERRUPT_CONTROLLER_ID,   // �жϿ�������ţ���system.h����
    		 IR_1506_IRQ,                           // Ӳ���жϺţ���system.h����
    		 IR_Handler,                          // �жϷ����Ӻ���
			 NULL,                                    // ָ�����豸����ʵ����ص����ݽṹ��
			 0
						);
    return States;
}

void numberInput(int num, int *currPos); // �˸��� -1 ��ʾ
void delay();

int main()
{
	int currPos = -1;
	int States;
	unsigned char KEY_CODE;
    printf("Hello from Nios II!\n");
    States = IR_Init();
    LCD_Disp(1, 0 , "                " , 16);
    delay();
    LCD_Disp(1, 0 , LCD_Data , 16);
    delay();
    LCD_Disp(2, 0 , "                " , 16);
    delay();

	printf("States: %d\n", States);

	while(1)
	{
        if(Data_Ready == 1)
		{
            Data_Ready = 0;
			KEY_CODE = (IR_Data >> 16) & 0xff;
			switch(KEY_CODE)
			{
			    case 0x00: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:0",7); delay(); numberInput(0, &currPos); break;
			    case 0x01: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:1",7); delay(); numberInput(1, &currPos); break;
			    case 0x02: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:2",7); delay(); numberInput(2, &currPos); break;
			    case 0x03: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:3",7); delay(); numberInput(3, &currPos); break;
			    case 0x04: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:4",7); delay(); numberInput(4, &currPos); break;
			    case 0x05: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:5",7); delay(); numberInput(5, &currPos); break;
			    case 0x06: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:6",7); delay(); numberInput(6, &currPos); break;
			    case 0x07: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:7",7); delay(); numberInput(7, &currPos); break;
			    case 0x08: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:8",7); delay(); numberInput(8, &currPos); break;
			    case 0x09: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Key:9",7); delay(); numberInput(9, &currPos); break;
			    case 0x17: LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Bcksp",7); delay(); numberInput(-1, &currPos); break;
			    default:   LCD_Disp(1,9,"       ",7); delay(); LCD_Disp(1,9,"  Unknw",7); delay(); break;
		    }
		}
	}


    return 0;
}

void numberInput(int num, int *currPos)
{
	if (num > 9)
	{
		num = 9;
	}

	// �˸��� -1 ��ʾ
	if (num < 0)
	{
		if (*currPos >= 0)
		{
			LCD_Disp(2, *currPos, " ", 1);
			delay();
			(*currPos)--;
		}
	}
	else
	{
		if (*currPos < 16)
		{
			(*currPos)++;
			LCD_Disp(2, *currPos, " ", 1);
			delay();
			LCD_Disp(2, *currPos, numberConvert[num], 1);
			delay();
		}
	}

}

void delay()
{
	// ���ü�����ʱ�İ취���ȴ�LCDˢ��
	// ���뷨  credit to ������
	int i;
	for (i = 0; i < 100000; i++);
}
