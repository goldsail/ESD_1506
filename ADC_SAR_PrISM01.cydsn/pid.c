// author: Jiang LIU

#include "pid.h"

float32 Ek = 0;
float32 Ek_1 = 0;
float32 Ek_2 = 0;
float32 Uk = 0;
float32 Ukk = 0;
float32 Kp = 8;
float32 Ki = 0.01;
float32 Kd = 0.1;
float32 TopMotorAngleCoeff = 4;
int16 ADC_L_balance = 765;
int16 ADC_R_balance = 765;
int16 ADC_L;
int16 ADC_R;
float32 range = 100;
int16 speed1 = 0; // -0x03ff ~ 0x03ff
int16 speed2 = 0;
uint16 angle3 = 0; // 0 - 300 degrees

void PID()
{
    Ek = (ADC_L - ADC_R) - (ADC_L_balance - ADC_R_balance);
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
        
        speed1 = Uk;
        speed2 = -Uk;
        angle3 = 512 + (Uk / TopMotorAngleCoeff);
    }
}