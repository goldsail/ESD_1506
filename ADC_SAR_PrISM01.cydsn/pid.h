// author: Jiang LIU

#ifndef _PID_H
#define _PID_H
#include <project.h>

extern float32 Ek;
extern float32 Ek_1;
extern float32 Ek_2;
extern float32 Uk;
extern float32 Ukk;
extern float32 Kp;
extern float32 Ki;
extern float32 Kd;
extern float32 TopMotorAngleCoeff;
extern int16 ADC_L_balance;
extern int16 ADC_R_balance;
extern int16 ADC_L;
extern int16 ADC_R;
extern float32 range;
extern int16 speed1; // -0x03ff ~ 0x03ff
extern int16 speed2;
extern uint16 angle3; // 0 - 300 degrees
    
    
void PID();
/* [] END OF FILE */

#endif