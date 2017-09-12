/*******************************************************************************
* File Name: Sin.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Sin_H) /* Pins Sin_H */
#define CY_PINS_Sin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sin_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sin__PORT == 15 && ((Sin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Sin_Write(uint8 value) ;
void    Sin_SetDriveMode(uint8 mode) ;
uint8   Sin_ReadDataReg(void) ;
uint8   Sin_Read(void) ;
uint8   Sin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Sin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Sin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Sin_DM_RES_UP          PIN_DM_RES_UP
#define Sin_DM_RES_DWN         PIN_DM_RES_DWN
#define Sin_DM_OD_LO           PIN_DM_OD_LO
#define Sin_DM_OD_HI           PIN_DM_OD_HI
#define Sin_DM_STRONG          PIN_DM_STRONG
#define Sin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Sin_MASK               Sin__MASK
#define Sin_SHIFT              Sin__SHIFT
#define Sin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sin_PS                     (* (reg8 *) Sin__PS)
/* Data Register */
#define Sin_DR                     (* (reg8 *) Sin__DR)
/* Port Number */
#define Sin_PRT_NUM                (* (reg8 *) Sin__PRT) 
/* Connect to Analog Globals */                                                  
#define Sin_AG                     (* (reg8 *) Sin__AG)                       
/* Analog MUX bux enable */
#define Sin_AMUX                   (* (reg8 *) Sin__AMUX) 
/* Bidirectional Enable */                                                        
#define Sin_BIE                    (* (reg8 *) Sin__BIE)
/* Bit-mask for Aliased Register Access */
#define Sin_BIT_MASK               (* (reg8 *) Sin__BIT_MASK)
/* Bypass Enable */
#define Sin_BYP                    (* (reg8 *) Sin__BYP)
/* Port wide control signals */                                                   
#define Sin_CTL                    (* (reg8 *) Sin__CTL)
/* Drive Modes */
#define Sin_DM0                    (* (reg8 *) Sin__DM0) 
#define Sin_DM1                    (* (reg8 *) Sin__DM1)
#define Sin_DM2                    (* (reg8 *) Sin__DM2) 
/* Input Buffer Disable Override */
#define Sin_INP_DIS                (* (reg8 *) Sin__INP_DIS)
/* LCD Common or Segment Drive */
#define Sin_LCD_COM_SEG            (* (reg8 *) Sin__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sin_LCD_EN                 (* (reg8 *) Sin__LCD_EN)
/* Slew Rate Control */
#define Sin_SLW                    (* (reg8 *) Sin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sin_PRTDSI__CAPS_SEL       (* (reg8 *) Sin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sin_PRTDSI__OE_SEL0        (* (reg8 *) Sin__PRTDSI__OE_SEL0) 
#define Sin_PRTDSI__OE_SEL1        (* (reg8 *) Sin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sin_PRTDSI__OUT_SEL0       (* (reg8 *) Sin__PRTDSI__OUT_SEL0) 
#define Sin_PRTDSI__OUT_SEL1       (* (reg8 *) Sin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sin_PRTDSI__SYNC_OUT       (* (reg8 *) Sin__PRTDSI__SYNC_OUT) 


#if defined(Sin__INTSTAT)  /* Interrupt Registers */

    #define Sin_INTSTAT                (* (reg8 *) Sin__INTSTAT)
    #define Sin_SNAP                   (* (reg8 *) Sin__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sin_H */


/* [] END OF FILE */
