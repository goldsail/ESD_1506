/***************************************************************************//**
* \file USBUART_1506_audio.h
* \version 3.0
*
* \brief
*  This file provides function prototypes and constants for the USBFS component 
*  Audio class.
*
* Related Document:
*  Universal Serial Bus Device Class Definition for Audio Devices Release 1.0
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_USBUART_1506_audio_H)
#define CY_USBFS_USBUART_1506_audio_H

#include "USBUART_1506.h"


/***************************************
* Custom Declarations
***************************************/

/* `#START CUSTOM_CONSTANTS` Place your declaration here */

/* `#END` */


/***************************************
*  Constants for USBUART_1506_audio API.
***************************************/

/* Audio Class-Specific Request Codes (AUDIO Table A-9) */
#define USBUART_1506_REQUEST_CODE_UNDEFINED     (0x00u)
#define USBUART_1506_SET_CUR                    (0x01u)
#define USBUART_1506_GET_CUR                    (0x81u)
#define USBUART_1506_SET_MIN                    (0x02u)
#define USBUART_1506_GET_MIN                    (0x82u)
#define USBUART_1506_SET_MAX                    (0x03u)
#define USBUART_1506_GET_MAX                    (0x83u)
#define USBUART_1506_SET_RES                    (0x04u)
#define USBUART_1506_GET_RES                    (0x84u)
#define USBUART_1506_SET_MEM                    (0x05u)
#define USBUART_1506_GET_MEM                    (0x85u)
#define USBUART_1506_GET_STAT                   (0xFFu)

/* point Control Selectors (AUDIO Table A-19) */
#define USBUART_1506_EP_CONTROL_UNDEFINED       (0x00u)
#define USBUART_1506_SAMPLING_FREQ_CONTROL      (0x01u)
#define USBUART_1506_PITCH_CONTROL              (0x02u)

/* Feature Unit Control Selectors (AUDIO Table A-11) */
#define USBUART_1506_FU_CONTROL_UNDEFINED       (0x00u)
#define USBUART_1506_MUTE_CONTROL               (0x01u)
#define USBUART_1506_VOLUME_CONTROL             (0x02u)
#define USBUART_1506_BASS_CONTROL               (0x03u)
#define USBUART_1506_MID_CONTROL                (0x04u)
#define USBUART_1506_TREBLE_CONTROL             (0x05u)
#define USBUART_1506_GRAPHIC_EQUALIZER_CONTROL  (0x06u)
#define USBUART_1506_AUTOMATIC_GAIN_CONTROL     (0x07u)
#define USBUART_1506_DELAY_CONTROL              (0x08u)
#define USBUART_1506_BASS_BOOST_CONTROL         (0x09u)
#define USBUART_1506_LOUDNESS_CONTROL           (0x0Au)

#define USBUART_1506_SAMPLE_FREQ_LEN            (3u)
#define USBUART_1506_VOLUME_LEN                 (2u)

#if !defined(USER_SUPPLIED_DEFAULT_VOLUME_VALUE)
    #define USBUART_1506_VOL_MIN_MSB            (0x80u)
    #define USBUART_1506_VOL_MIN_LSB            (0x01u)
    #define USBUART_1506_VOL_MAX_MSB            (0x7Fu)
    #define USBUART_1506_VOL_MAX_LSB            (0xFFu)
    #define USBUART_1506_VOL_RES_MSB            (0x00u)
    #define USBUART_1506_VOL_RES_LSB            (0x01u)
#endif /* USER_SUPPLIED_DEFAULT_VOLUME_VALUE */


/***************************************
* External data references
***************************************/
/**
* \addtogroup group_audio
* @{
*/
extern volatile uint8 USBUART_1506_currentSampleFrequency[USBUART_1506_MAX_EP][USBUART_1506_SAMPLE_FREQ_LEN];
extern volatile uint8 USBUART_1506_frequencyChanged;
extern volatile uint8 USBUART_1506_currentMute;
extern volatile uint8 USBUART_1506_currentVolume[USBUART_1506_VOLUME_LEN];
/** @} audio */

extern volatile uint8 USBUART_1506_minimumVolume[USBUART_1506_VOLUME_LEN];
extern volatile uint8 USBUART_1506_maximumVolume[USBUART_1506_VOLUME_LEN];
extern volatile uint8 USBUART_1506_resolutionVolume[USBUART_1506_VOLUME_LEN];

#endif /*  CY_USBFS_USBUART_1506_audio_H */


/* [] END OF FILE */
