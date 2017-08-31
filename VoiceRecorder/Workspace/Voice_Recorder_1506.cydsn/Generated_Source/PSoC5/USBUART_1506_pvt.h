/***************************************************************************//**
* \file .h
* \version 3.0
*
* \brief
*  This file provides private function prototypes and constants for the 
*  USBFS component. It is not intended to be used in the user project.
*
********************************************************************************
* \copyright
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_USBUART_1506_pvt_H)
#define CY_USBFS_USBUART_1506_pvt_H

#include "USBUART_1506.h"
   
#ifdef USBUART_1506_ENABLE_AUDIO_CLASS
    #include "USBUART_1506_audio.h"
#endif /* USBUART_1506_ENABLE_AUDIO_CLASS */

#ifdef USBUART_1506_ENABLE_CDC_CLASS
    #include "USBUART_1506_cdc.h"
#endif /* USBUART_1506_ENABLE_CDC_CLASS */

#if (USBUART_1506_ENABLE_MIDI_CLASS)
    #include "USBUART_1506_midi.h"
#endif /* (USBUART_1506_ENABLE_MIDI_CLASS) */

#if (USBUART_1506_ENABLE_MSC_CLASS)
    #include "USBUART_1506_msc.h"
#endif /* (USBUART_1506_ENABLE_MSC_CLASS) */

#if (USBUART_1506_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        #include <CyDMA.h>
    #else
        #include <CyDmac.h>
        #if ((USBUART_1506_EP_MANAGEMENT_DMA_AUTO) && (USBUART_1506_EP_DMA_AUTO_OPT == 0u))
            #include "USBUART_1506_EP_DMA_Done_isr.h"
            #include "USBUART_1506_EP8_DMA_Done_SR.h"
            #include "USBUART_1506_EP17_DMA_Done_SR.h"
        #endif /* ((USBUART_1506_EP_MANAGEMENT_DMA_AUTO) && (USBUART_1506_EP_DMA_AUTO_OPT == 0u)) */
    #endif /* (CY_PSOC4) */
#endif /* (USBUART_1506_EP_MANAGEMENT_DMA) */

#if (USBUART_1506_DMA1_ACTIVE)
    #include "USBUART_1506_ep1_dma.h"
    #define USBUART_1506_EP1_DMA_CH     (USBUART_1506_ep1_dma_CHANNEL)
#endif /* (USBUART_1506_DMA1_ACTIVE) */

#if (USBUART_1506_DMA2_ACTIVE)
    #include "USBUART_1506_ep2_dma.h"
    #define USBUART_1506_EP2_DMA_CH     (USBUART_1506_ep2_dma_CHANNEL)
#endif /* (USBUART_1506_DMA2_ACTIVE) */

#if (USBUART_1506_DMA3_ACTIVE)
    #include "USBUART_1506_ep3_dma.h"
    #define USBUART_1506_EP3_DMA_CH     (USBUART_1506_ep3_dma_CHANNEL)
#endif /* (USBUART_1506_DMA3_ACTIVE) */

#if (USBUART_1506_DMA4_ACTIVE)
    #include "USBUART_1506_ep4_dma.h"
    #define USBUART_1506_EP4_DMA_CH     (USBUART_1506_ep4_dma_CHANNEL)
#endif /* (USBUART_1506_DMA4_ACTIVE) */

#if (USBUART_1506_DMA5_ACTIVE)
    #include "USBUART_1506_ep5_dma.h"
    #define USBUART_1506_EP5_DMA_CH     (USBUART_1506_ep5_dma_CHANNEL)
#endif /* (USBUART_1506_DMA5_ACTIVE) */

#if (USBUART_1506_DMA6_ACTIVE)
    #include "USBUART_1506_ep6_dma.h"
    #define USBUART_1506_EP6_DMA_CH     (USBUART_1506_ep6_dma_CHANNEL)
#endif /* (USBUART_1506_DMA6_ACTIVE) */

#if (USBUART_1506_DMA7_ACTIVE)
    #include "USBUART_1506_ep7_dma.h"
    #define USBUART_1506_EP7_DMA_CH     (USBUART_1506_ep7_dma_CHANNEL)
#endif /* (USBUART_1506_DMA7_ACTIVE) */

#if (USBUART_1506_DMA8_ACTIVE)
    #include "USBUART_1506_ep8_dma.h"
    #define USBUART_1506_EP8_DMA_CH     (USBUART_1506_ep8_dma_CHANNEL)
#endif /* (USBUART_1506_DMA8_ACTIVE) */


/***************************************
*     Private Variables
***************************************/

/* Generated external references for descriptors. */
extern const uint8 CYCODE USBUART_1506_DEVICE0_DESCR[18u];
extern const uint8 CYCODE USBUART_1506_DEVICE0_CONFIGURATION0_DESCR[67u];
extern const T_USBUART_1506_EP_SETTINGS_BLOCK CYCODE USBUART_1506_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[3u];
extern const uint8 CYCODE USBUART_1506_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[2u];
extern const T_USBUART_1506_LUT CYCODE USBUART_1506_DEVICE0_CONFIGURATION0_TABLE[5u];
extern const T_USBUART_1506_LUT CYCODE USBUART_1506_DEVICE0_TABLE[3u];
extern const T_USBUART_1506_LUT CYCODE USBUART_1506_TABLE[1u];
extern const uint8 CYCODE USBUART_1506_SN_STRING_DESCRIPTOR[2];
extern const uint8 CYCODE USBUART_1506_STRING_DESCRIPTORS[159u];


extern const uint8 CYCODE USBUART_1506_MSOS_DESCRIPTOR[USBUART_1506_MSOS_DESCRIPTOR_LENGTH];
extern const uint8 CYCODE USBUART_1506_MSOS_CONFIGURATION_DESCR[USBUART_1506_MSOS_CONF_DESCR_LENGTH];
#if defined(USBUART_1506_ENABLE_IDSN_STRING)
    extern uint8 USBUART_1506_idSerialNumberStringDescriptor[USBUART_1506_IDSN_DESCR_LENGTH];
#endif /* (USBUART_1506_ENABLE_IDSN_STRING) */

extern volatile uint8 USBUART_1506_interfaceNumber;
extern volatile uint8 USBUART_1506_interfaceSetting[USBUART_1506_MAX_INTERFACES_NUMBER];
extern volatile uint8 USBUART_1506_interfaceSettingLast[USBUART_1506_MAX_INTERFACES_NUMBER];
extern volatile uint8 USBUART_1506_deviceAddress;
extern volatile uint8 USBUART_1506_interfaceStatus[USBUART_1506_MAX_INTERFACES_NUMBER];
extern const uint8 CYCODE *USBUART_1506_interfaceClass;

extern volatile T_USBUART_1506_EP_CTL_BLOCK USBUART_1506_EP[USBUART_1506_MAX_EP];
extern volatile T_USBUART_1506_TD USBUART_1506_currentTD;

#if (USBUART_1506_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        extern const uint8 USBUART_1506_DmaChan[USBUART_1506_MAX_EP];
    #else
        extern uint8 USBUART_1506_DmaChan[USBUART_1506_MAX_EP];
        extern uint8 USBUART_1506_DmaTd  [USBUART_1506_MAX_EP];
    #endif /* (CY_PSOC4) */
#endif /* (USBUART_1506_EP_MANAGEMENT_DMA) */

#if (USBUART_1506_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    extern uint8  USBUART_1506_DmaEpBurstCnt   [USBUART_1506_MAX_EP];
    extern uint8  USBUART_1506_DmaEpLastBurstEl[USBUART_1506_MAX_EP];

    extern uint8  USBUART_1506_DmaEpBurstCntBackup  [USBUART_1506_MAX_EP];
    extern uint32 USBUART_1506_DmaEpBufferAddrBackup[USBUART_1506_MAX_EP];
    
    extern const uint8 USBUART_1506_DmaReqOut     [USBUART_1506_MAX_EP];    
    extern const uint8 USBUART_1506_DmaBurstEndOut[USBUART_1506_MAX_EP];
#else
    #if (USBUART_1506_EP_DMA_AUTO_OPT == 0u)
        extern uint8 USBUART_1506_DmaNextTd[USBUART_1506_MAX_EP];
        extern volatile uint16 USBUART_1506_inLength [USBUART_1506_MAX_EP];
        extern volatile uint8  USBUART_1506_inBufFull[USBUART_1506_MAX_EP];
        extern const uint8 USBUART_1506_epX_TD_TERMOUT_EN[USBUART_1506_MAX_EP];
        extern const uint8 *USBUART_1506_inDataPointer[USBUART_1506_MAX_EP];
    #endif /* (USBUART_1506_EP_DMA_AUTO_OPT == 0u) */
#endif /* CY_PSOC4 */
#endif /* (USBUART_1506_EP_MANAGEMENT_DMA_AUTO) */

extern volatile uint8 USBUART_1506_ep0Toggle;
extern volatile uint8 USBUART_1506_lastPacketSize;
extern volatile uint8 USBUART_1506_ep0Mode;
extern volatile uint8 USBUART_1506_ep0Count;
extern volatile uint16 USBUART_1506_transferByteCount;


/***************************************
*     Private Function Prototypes
***************************************/
void  USBUART_1506_ReInitComponent(void)            ;
void  USBUART_1506_HandleSetup(void)                ;
void  USBUART_1506_HandleIN(void)                   ;
void  USBUART_1506_HandleOUT(void)                  ;
void  USBUART_1506_LoadEP0(void)                    ;
uint8 USBUART_1506_InitControlRead(void)            ;
uint8 USBUART_1506_InitControlWrite(void)           ;
void  USBUART_1506_ControlReadDataStage(void)       ;
void  USBUART_1506_ControlReadStatusStage(void)     ;
void  USBUART_1506_ControlReadPrematureStatus(void) ;
uint8 USBUART_1506_InitControlWrite(void)           ;
uint8 USBUART_1506_InitZeroLengthControlTransfer(void) ;
void  USBUART_1506_ControlWriteDataStage(void)      ;
void  USBUART_1506_ControlWriteStatusStage(void)    ;
void  USBUART_1506_ControlWritePrematureStatus(void);
uint8 USBUART_1506_InitNoDataControlTransfer(void)  ;
void  USBUART_1506_NoDataControlStatusStage(void)   ;
void  USBUART_1506_InitializeStatusBlock(void)      ;
void  USBUART_1506_UpdateStatusBlock(uint8 completionCode) ;
uint8 USBUART_1506_DispatchClassRqst(void)          ;

void USBUART_1506_Config(uint8 clearAltSetting) ;
void USBUART_1506_ConfigAltChanged(void)        ;
void USBUART_1506_ConfigReg(void)               ;
void USBUART_1506_EpStateInit(void)             ;


const T_USBUART_1506_LUT CYCODE *USBUART_1506_GetConfigTablePtr(uint8 confIndex);
const T_USBUART_1506_LUT CYCODE *USBUART_1506_GetDeviceTablePtr(void)           ;
#if (USBUART_1506_BOS_ENABLE)
    const T_USBUART_1506_LUT CYCODE *USBUART_1506_GetBOSPtr(void)               ;
#endif /* (USBUART_1506_BOS_ENABLE) */
const uint8 CYCODE *USBUART_1506_GetInterfaceClassTablePtr(void)                    ;uint8 USBUART_1506_ClearEndpointHalt(void)                                          ;
uint8 USBUART_1506_SetEndpointHalt(void)                                            ;
uint8 USBUART_1506_ValidateAlternateSetting(void)                                   ;

void USBUART_1506_SaveConfig(void)      ;
void USBUART_1506_RestoreConfig(void)   ;

#if (CY_PSOC3 || CY_PSOC5LP)
    #if (USBUART_1506_EP_MANAGEMENT_DMA_AUTO && (USBUART_1506_EP_DMA_AUTO_OPT == 0u))
        void USBUART_1506_LoadNextInEP(uint8 epNumber, uint8 mode)  ;
    #endif /* (USBUART_1506_EP_MANAGEMENT_DMA_AUTO && (USBUART_1506_EP_DMA_AUTO_OPT == 0u)) */
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

#if defined(USBUART_1506_ENABLE_IDSN_STRING)
    void USBUART_1506_ReadDieID(uint8 descr[])  ;
#endif /* USBUART_1506_ENABLE_IDSN_STRING */

#if defined(USBUART_1506_ENABLE_HID_CLASS)
    uint8 USBUART_1506_DispatchHIDClassRqst(void) ;
#endif /* (USBUART_1506_ENABLE_HID_CLASS) */

#if defined(USBUART_1506_ENABLE_AUDIO_CLASS)
    uint8 USBUART_1506_DispatchAUDIOClassRqst(void) ;
#endif /* (USBUART_1506_ENABLE_AUDIO_CLASS) */

#if defined(USBUART_1506_ENABLE_CDC_CLASS)
    uint8 USBUART_1506_DispatchCDCClassRqst(void) ;
#endif /* (USBUART_1506_ENABLE_CDC_CLASS) */

#if (USBUART_1506_ENABLE_MSC_CLASS)
    #if (USBUART_1506_HANDLE_MSC_REQUESTS)
        uint8 USBUART_1506_DispatchMSCClassRqst(void) ;
    #endif /* (USBUART_1506_HANDLE_MSC_REQUESTS) */
#endif /* (USBUART_1506_ENABLE_MSC_CLASS */

CY_ISR_PROTO(USBUART_1506_EP_0_ISR);
CY_ISR_PROTO(USBUART_1506_BUS_RESET_ISR);

#if (USBUART_1506_SOF_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_SOF_ISR);
#endif /* (USBUART_1506_SOF_ISR_ACTIVE) */

#if (USBUART_1506_EP1_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_EP_1_ISR);
#endif /* (USBUART_1506_EP1_ISR_ACTIVE) */

#if (USBUART_1506_EP2_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_EP_2_ISR);
#endif /* (USBUART_1506_EP2_ISR_ACTIVE) */

#if (USBUART_1506_EP3_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_EP_3_ISR);
#endif /* (USBUART_1506_EP3_ISR_ACTIVE) */

#if (USBUART_1506_EP4_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_EP_4_ISR);
#endif /* (USBUART_1506_EP4_ISR_ACTIVE) */

#if (USBUART_1506_EP5_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_EP_5_ISR);
#endif /* (USBUART_1506_EP5_ISR_ACTIVE) */

#if (USBUART_1506_EP6_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_EP_6_ISR);
#endif /* (USBUART_1506_EP6_ISR_ACTIVE) */

#if (USBUART_1506_EP7_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_EP_7_ISR);
#endif /* (USBUART_1506_EP7_ISR_ACTIVE) */

#if (USBUART_1506_EP8_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_EP_8_ISR);
#endif /* (USBUART_1506_EP8_ISR_ACTIVE) */

#if (USBUART_1506_EP_MANAGEMENT_DMA)
    CY_ISR_PROTO(USBUART_1506_ARB_ISR);
#endif /* (USBUART_1506_EP_MANAGEMENT_DMA) */

#if (USBUART_1506_DP_ISR_ACTIVE)
    CY_ISR_PROTO(USBUART_1506_DP_ISR);
#endif /* (USBUART_1506_DP_ISR_ACTIVE) */

#if (CY_PSOC4)
    CY_ISR_PROTO(USBUART_1506_INTR_HI_ISR);
    CY_ISR_PROTO(USBUART_1506_INTR_MED_ISR);
    CY_ISR_PROTO(USBUART_1506_INTR_LO_ISR);
    #if (USBUART_1506_LPM_ACTIVE)
        CY_ISR_PROTO(USBUART_1506_LPM_ISR);
    #endif /* (USBUART_1506_LPM_ACTIVE) */
#endif /* (CY_PSOC4) */

#if (USBUART_1506_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    #if (USBUART_1506_DMA1_ACTIVE)
        void USBUART_1506_EP1_DMA_DONE_ISR(void);
    #endif /* (USBUART_1506_DMA1_ACTIVE) */

    #if (USBUART_1506_DMA2_ACTIVE)
        void USBUART_1506_EP2_DMA_DONE_ISR(void);
    #endif /* (USBUART_1506_DMA2_ACTIVE) */

    #if (USBUART_1506_DMA3_ACTIVE)
        void USBUART_1506_EP3_DMA_DONE_ISR(void);
    #endif /* (USBUART_1506_DMA3_ACTIVE) */

    #if (USBUART_1506_DMA4_ACTIVE)
        void USBUART_1506_EP4_DMA_DONE_ISR(void);
    #endif /* (USBUART_1506_DMA4_ACTIVE) */

    #if (USBUART_1506_DMA5_ACTIVE)
        void USBUART_1506_EP5_DMA_DONE_ISR(void);
    #endif /* (USBUART_1506_DMA5_ACTIVE) */

    #if (USBUART_1506_DMA6_ACTIVE)
        void USBUART_1506_EP6_DMA_DONE_ISR(void);
    #endif /* (USBUART_1506_DMA6_ACTIVE) */

    #if (USBUART_1506_DMA7_ACTIVE)
        void USBUART_1506_EP7_DMA_DONE_ISR(void);
    #endif /* (USBUART_1506_DMA7_ACTIVE) */

    #if (USBUART_1506_DMA8_ACTIVE)
        void USBUART_1506_EP8_DMA_DONE_ISR(void);
    #endif /* (USBUART_1506_DMA8_ACTIVE) */

#else
    #if (USBUART_1506_EP_DMA_AUTO_OPT == 0u)
        CY_ISR_PROTO(USBUART_1506_EP_DMA_DONE_ISR);
    #endif /* (USBUART_1506_EP_DMA_AUTO_OPT == 0u) */
#endif /* (CY_PSOC4) */
#endif /* (USBUART_1506_EP_MANAGEMENT_DMA_AUTO) */


/***************************************
*         Request Handlers
***************************************/

uint8 USBUART_1506_HandleStandardRqst(void) ;
uint8 USBUART_1506_DispatchClassRqst(void)  ;
uint8 USBUART_1506_HandleVendorRqst(void)   ;


/***************************************
*    HID Internal references
***************************************/

#if defined(USBUART_1506_ENABLE_HID_CLASS)
    void USBUART_1506_FindReport(void)            ;
    void USBUART_1506_FindReportDescriptor(void)  ;
    void USBUART_1506_FindHidClassDecriptor(void) ;
#endif /* USBUART_1506_ENABLE_HID_CLASS */


/***************************************
*    MIDI Internal references
***************************************/

#if defined(USBUART_1506_ENABLE_MIDI_STREAMING)
    void USBUART_1506_MIDI_IN_EP_Service(void)  ;
#endif /* (USBUART_1506_ENABLE_MIDI_STREAMING) */


/***************************************
*    CDC Internal references
***************************************/

#if defined(USBUART_1506_ENABLE_CDC_CLASS)

    typedef struct
    {
        uint8  bRequestType;
        uint8  bNotification;
        uint8  wValue;
        uint8  wValueMSB;
        uint8  wIndex;
        uint8  wIndexMSB;
        uint8  wLength;
        uint8  wLengthMSB;
        uint8  wSerialState;
        uint8  wSerialStateMSB;
    } t_USBUART_1506_cdc_notification;

    uint8 USBUART_1506_GetInterfaceComPort(uint8 interface) ;
    uint8 USBUART_1506_Cdc_EpInit( const T_USBUART_1506_EP_SETTINGS_BLOCK CYCODE *pEP, uint8 epNum, uint8 cdcComNums) ;

    extern volatile uint8  USBUART_1506_cdc_dataInEpList[USBUART_1506_MAX_MULTI_COM_NUM];
    extern volatile uint8  USBUART_1506_cdc_dataOutEpList[USBUART_1506_MAX_MULTI_COM_NUM];
    extern volatile uint8  USBUART_1506_cdc_commInEpList[USBUART_1506_MAX_MULTI_COM_NUM];
#endif /* (USBUART_1506_ENABLE_CDC_CLASS) */


#endif /* CY_USBFS_USBUART_1506_pvt_H */


/* [] END OF FILE */
