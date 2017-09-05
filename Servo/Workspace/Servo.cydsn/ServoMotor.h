// author: Fan JIN
    
#ifndef _SERVOMOTOR_H
#define _SERVOMOTOR_H

#include <project.h>
#include "stdio.h"

#define ID_TOP (4)  
#define ID_LEFT (1)
#define ID_RIGHT (3)
    

void setServoMode(uint8 id);

// postiion ranges from 0x0000 to 0x03ff
// speed ranges from 0x0000 to 0x03ff
void SetServoPosition(uint8 id, uint16 position, uint16 speed);

void SetMotorMode(uint8 id);

// speed ranges from -0x03ff to 0x03ff
// acceleration ranges from 0x00 to 0x20
void SetMotorSpeed(uint8 id, int16 speed, uint8 acceleration);

#endif