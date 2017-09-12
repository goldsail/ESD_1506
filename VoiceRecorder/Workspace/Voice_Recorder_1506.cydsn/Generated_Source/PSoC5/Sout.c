/*******************************************************************************
* File Name: Sout.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Sout.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Sout__PORT == 15 && ((Sout__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Sout_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Sout_Write(uint8 value) 
{
    uint8 staticBits = (Sout_DR & (uint8)(~Sout_MASK));
    Sout_DR = staticBits | ((uint8)(value << Sout_SHIFT) & Sout_MASK);
}


/*******************************************************************************
* Function Name: Sout_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void Sout_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Sout_0, mode);
}


/*******************************************************************************
* Function Name: Sout_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Sout_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Sout_Read(void) 
{
    return (Sout_PS & Sout_MASK) >> Sout_SHIFT;
}


/*******************************************************************************
* Function Name: Sout_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Sout_ReadDataReg(void) 
{
    return (Sout_DR & Sout_MASK) >> Sout_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Sout_INTSTAT) 

    /*******************************************************************************
    * Function Name: Sout_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Sout_ClearInterrupt(void) 
    {
        return (Sout_INTSTAT & Sout_MASK) >> Sout_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
