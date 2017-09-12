/***************************************************************************//**
* \file USBUART_1506_cdc.h
* \version 3.0
*
* \brief
*  This file provides function prototypes and constants for the USBFS component 
*  CDC class.
*
* Related Document:
*  Universal Serial Bus Class Definitions for Communication Devices Version 1.1
*
********************************************************************************
* \copyright
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_USBUART_1506_cdc_H)
#define CY_USBFS_USBUART_1506_cdc_H

#include "USBUART_1506.h"


/*******************************************************************************
* Prototypes of the USBUART_1506_cdc API.
*******************************************************************************/
/**
* \addtogroup group_cdc
* @{
*/
#if (USBUART_1506_ENABLE_CDC_CLASS_API != 0u)
    uint8 USBUART_1506_CDC_Init(void)            ;
    void USBUART_1506_PutData(const uint8* pData, uint16 length) ;
    void USBUART_1506_PutString(const char8 string[])            ;
    void USBUART_1506_PutChar(char8 txDataByte) ;
    void USBUART_1506_PutCRLF(void)             ;
    uint16 USBUART_1506_GetCount(void)          ;
    uint8  USBUART_1506_CDCIsReady(void)        ;
    uint8  USBUART_1506_DataIsReady(void)       ;
    uint16 USBUART_1506_GetData(uint8* pData, uint16 length)     ;
    uint16 USBUART_1506_GetAll(uint8* pData)    ;
    uint8  USBUART_1506_GetChar(void)           ;
    uint8  USBUART_1506_IsLineChanged(void)     ;
    uint32 USBUART_1506_GetDTERate(void)        ;
    uint8  USBUART_1506_GetCharFormat(void)     ;
    uint8  USBUART_1506_GetParityType(void)     ;
    uint8  USBUART_1506_GetDataBits(void)       ;
    uint16 USBUART_1506_GetLineControl(void)    ;
    void USBUART_1506_SendSerialState (uint16 serialState) ;
    uint16 USBUART_1506_GetSerialState (void)   ;
    void USBUART_1506_SetComPort (uint8 comNumber) ;
    uint8 USBUART_1506_GetComPort (void)        ;
    uint8 USBUART_1506_NotificationIsReady(void) ;

#endif  /* (USBUART_1506_ENABLE_CDC_CLASS_API) */
/** @} cdc */

/*******************************************************************************
*  Constants for USBUART_1506_cdc API.
*******************************************************************************/

/* CDC Class-Specific Request Codes (CDC ver 1.2 Table 19) */
#define USBUART_1506_CDC_SET_LINE_CODING        (0x20u)
#define USBUART_1506_CDC_GET_LINE_CODING        (0x21u)
#define USBUART_1506_CDC_SET_CONTROL_LINE_STATE (0x22u)

/*PSTN Subclass Specific Notifications (CDC ver 1.2 Table 30)*/
#define USBUART_1506_SERIAL_STATE               (0x20u)

#define USBUART_1506_LINE_CODING_CHANGED        (0x01u)
#define USBUART_1506_LINE_CONTROL_CHANGED       (0x02u)

#define USBUART_1506_1_STOPBIT                  (0x00u)
#define USBUART_1506_1_5_STOPBITS               (0x01u)
#define USBUART_1506_2_STOPBITS                 (0x02u)

#define USBUART_1506_PARITY_NONE                (0x00u)
#define USBUART_1506_PARITY_ODD                 (0x01u)
#define USBUART_1506_PARITY_EVEN                (0x02u)
#define USBUART_1506_PARITY_MARK                (0x03u)
#define USBUART_1506_PARITY_SPACE               (0x04u)

#define USBUART_1506_LINE_CODING_SIZE           (0x07u)
#define USBUART_1506_LINE_CODING_RATE           (0x00u)
#define USBUART_1506_LINE_CODING_STOP_BITS      (0x04u)
#define USBUART_1506_LINE_CODING_PARITY         (0x05u)
#define USBUART_1506_LINE_CODING_DATA_BITS      (0x06u)

#define USBUART_1506_LINE_CONTROL_DTR           (0x01u)
#define USBUART_1506_LINE_CONTROL_RTS           (0x02u)

#define USBUART_1506_MAX_MULTI_COM_NUM          (2u) 

#define USBUART_1506_COM_PORT1                  (0u) 
#define USBUART_1506_COM_PORT2                  (1u) 

#define USBUART_1506_SUCCESS                    (0u)
#define USBUART_1506_FAILURE                    (1u)

#define USBUART_1506_SERIAL_STATE_SIZE          (10u)

/* SerialState constants*/
#define USBUART_1506_SERIAL_STATE_REQUEST_TYPE  (0xA1u)
#define USBUART_1506_SERIAL_STATE_LENGTH        (0x2u)

/*******************************************************************************
* External data references
*******************************************************************************/
/**
* \addtogroup group_cdc
* @{
*/
extern volatile uint8  USBUART_1506_linesCoding[USBUART_1506_MAX_MULTI_COM_NUM][USBUART_1506_LINE_CODING_SIZE];
extern volatile uint8  USBUART_1506_linesChanged[USBUART_1506_MAX_MULTI_COM_NUM];
extern volatile uint16 USBUART_1506_linesControlBitmap[USBUART_1506_MAX_MULTI_COM_NUM];
extern volatile uint16 USBUART_1506_serialStateBitmap[USBUART_1506_MAX_MULTI_COM_NUM];
extern volatile uint8  USBUART_1506_cdcDataInEp[USBUART_1506_MAX_MULTI_COM_NUM];
extern volatile uint8  USBUART_1506_cdcDataOutEp[USBUART_1506_MAX_MULTI_COM_NUM];
extern volatile uint8  USBUART_1506_cdcCommInInterruptEp[USBUART_1506_MAX_MULTI_COM_NUM];
/** @} cdc */

/*******************************************************************************
* The following code is DEPRECATED and
* must not be used.
*******************************************************************************/


#define USBUART_1506_lineCoding             USBUART_1506_linesCoding[0]
#define USBUART_1506_lineChanged            USBUART_1506_linesChanged[0]
#define USBUART_1506_lineControlBitmap      USBUART_1506_linesControlBitmap[0]
#define USBUART_1506_cdc_data_in_ep         USBUART_1506_cdcDataInEp[0]
#define USBUART_1506_cdc_data_out_ep        USBUART_1506_cdcDataOutEp[0]

#endif /* (CY_USBFS_USBUART_1506_cdc_H) */


/* [] END OF FILE */
