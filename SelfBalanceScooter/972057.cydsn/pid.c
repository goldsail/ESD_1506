// author: Jiang LIU

#include "pid.h"

float32 Ek = 0;
float32 Ek_1 = 0;
float32 Ek_2 = 0;
float32 Uk = 0;
float32 Ukk = 0;
float32 Kp = 10.5;
float32 Ki = 0.09;
float32 Kd = 0.48;//0,2
float32 TopMotorAngleCoeff = 4;
int16 ADC_L_balance = 690; 
int16 ADC_R_balance = 720; 
//int16 bias = ADC_L_balance - ADC_R_balance;
int16 bias = -20;

int16 ADC_L;
int16 ADC_R;
float32 range = 10;
int16 speed1 = 0; // -0x03ff ~ 0x03ff
int16 speed2 = 0;
uint16 angle3 = 0; // 0 - 300 degrees

#define CompensateCoeff (1.0)

void PID()
{
    Ek = (ADC_L - ADC_R) - bias;
    Uk = Kp * (Ek - Ek_1 + Ki*Ek + Kd*(Ek - 2*Ek_1 + Ek_2)) + 0.95 * Ukk;
    Ukk = Uk;
    Ek_2 = Ek_1;
    Ek_1 = Ek;
    if(Uk>=-range && Ukk <=range)
    {
        speed1 = speed2 = 0;
        angle3 = 512;
    }
    else
    {
        if(Uk > 1023) Uk = 1023;
        if(Uk < -1023) Uk = -1023;
        speed1 = CompensateCoeff * Uk;
        speed2 = -CompensateCoeff * Uk;
        angle3 = 512 + (CompensateCoeff * Uk / TopMotorAngleCoeff);
    }
    SetMotorSpeed(_LEFT, speed1, 255);
    SetMotorSpeed(_RIGHT, speed2, 255);
    SetServoPosition(_TOP, angle3, 0x03ff);
}