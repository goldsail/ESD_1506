#include "Bluetooth.h"

uint8 buffer[BufferSize];

void GetBluetoothString(uint8 *buffer)
{
    int i;
    uint8 ch;
    for (i = 0; i < BufferSize; i++)
        {
            ch = buffer[i] = UART_6_GetChar();
            if (ch == '\r' || ch == '\n' || ch == '\0')
            {
                buffer[i] = '\0';
                break;
            }
        }
}