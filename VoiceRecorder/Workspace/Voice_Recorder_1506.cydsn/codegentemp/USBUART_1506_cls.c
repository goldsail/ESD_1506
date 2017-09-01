/***************************************************************************//**
* \file USBUART_1506_cls.c
* \version 3.0
*
* \brief
*  This file contains the USB Class request handler.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBUART_1506_pvt.h"
#include "cyapicallbacks.h"

#if(USBUART_1506_EXTERN_CLS == USBUART_1506_FALSE)

/***************************************
* User Implemented Class Driver Declarations.
***************************************/
/* `#START USER_DEFINED_CLASS_DECLARATIONS` Place your declaration here */

/* `#END` */


/*******************************************************************************
* Function Name: USBUART_1506_DispatchClassRqst
****************************************************************************//**
*  This routine dispatches class specific requests depend on interface class.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 USBUART_1506_DispatchClassRqst(void) 
{
    uint8 requestHandled;
    uint8 interfaceNumber;

    /* Get interface to which request is intended. */
    switch (USBUART_1506_bmRequestTypeReg & USBUART_1506_RQST_RCPT_MASK)
    {
        case USBUART_1506_RQST_RCPT_IFC:
            /* Class-specific request directed to interface: wIndexLoReg 
            * contains interface number.
            */
            interfaceNumber = (uint8) USBUART_1506_wIndexLoReg;
            break;
        
        case USBUART_1506_RQST_RCPT_EP:
            /* Class-specific request directed to endpoint: wIndexLoReg contains 
            * endpoint number. Find interface related to endpoint, 
            */
            interfaceNumber = USBUART_1506_EP[USBUART_1506_wIndexLoReg & USBUART_1506_DIR_UNUSED].interface;
            break;
            
        default:
            /* Default interface is zero. */
            interfaceNumber = 0u;
            break;
    }

#if (defined(USBUART_1506_ENABLE_HID_CLASS) ||\
            defined(USBUART_1506_ENABLE_AUDIO_CLASS) ||\
            defined(USBUART_1506_ENABLE_CDC_CLASS) ||\
            USBUART_1506_ENABLE_MSC_CLASS)

    /* Handle class request depends on interface type. */
    switch (USBUART_1506_interfaceClass[interfaceNumber])
    {
    #if defined(USBUART_1506_ENABLE_HID_CLASS)
        case USBUART_1506_CLASS_HID:
            requestHandled = USBUART_1506_DispatchHIDClassRqst();
            break;
    #endif /* (USBUART_1506_ENABLE_HID_CLASS) */
            
    #if defined(USBUART_1506_ENABLE_AUDIO_CLASS)
        case USBUART_1506_CLASS_AUDIO:
            requestHandled = USBUART_1506_DispatchAUDIOClassRqst();
            break;
    #endif /* (USBUART_1506_CLASS_AUDIO) */
            
    #if defined(USBUART_1506_ENABLE_CDC_CLASS)
        case USBUART_1506_CLASS_CDC:
            requestHandled = USBUART_1506_DispatchCDCClassRqst();
            break;
    #endif /* (USBUART_1506_ENABLE_CDC_CLASS) */
        
    #if (USBUART_1506_ENABLE_MSC_CLASS)
        case USBUART_1506_CLASS_MSD:
        #if (USBUART_1506_HANDLE_MSC_REQUESTS)
            /* MSC requests are handled by the component. */
            requestHandled = USBUART_1506_DispatchMSCClassRqst();
        #elif defined(USBUART_1506_DISPATCH_MSC_CLASS_RQST_CALLBACK)
            /* MSC requests are handled by user defined callbcak. */
            requestHandled = USBUART_1506_DispatchMSCClassRqst_Callback();
        #else
            /* MSC requests are not handled. */
            requestHandled = USBUART_1506_FALSE;
        #endif /* (USBUART_1506_HANDLE_MSC_REQUESTS) */
            break;
    #endif /* (USBUART_1506_ENABLE_MSC_CLASS) */
        
        default:
            /* Request is not handled: unknown class request type. */
            requestHandled = USBUART_1506_FALSE;
            break;
    }
#else /*No class is defined*/
    if (0u != interfaceNumber)
    {
        /* Suppress warning message */
    }
    requestHandled = USBUART_1506_FALSE;
#endif /*HID or AUDIO or MSC or CDC class enabled*/

    /* `#START USER_DEFINED_CLASS_CODE` Place your Class request here */

    /* `#END` */

#ifdef USBUART_1506_DISPATCH_CLASS_RQST_CALLBACK
    if (USBUART_1506_FALSE == requestHandled)
    {
        requestHandled = USBUART_1506_DispatchClassRqst_Callback(interfaceNumber);
    }
#endif /* (USBUART_1506_DISPATCH_CLASS_RQST_CALLBACK) */

    return (requestHandled);
}


/*******************************************************************************
* Additional user functions supporting Class Specific Requests
********************************************************************************/

/* `#START CLASS_SPECIFIC_FUNCTIONS` Place any additional functions here */

/* `#END` */

#endif /* USBUART_1506_EXTERN_CLS */


/* [] END OF FILE */