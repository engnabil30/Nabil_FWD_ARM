/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : IntCtrl.h
 * 
 *  \category  : IntCtrl Module
 * 
 *  \date      : 22 September 2022
 * 
 *  \brief     : Nested Vector Interrupt Controller (NVIC) Driver
 *  
 *  \details   : The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *               Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "IntCtrl.h"

/* ================================================================================================================= */
/* ================                                GLOBAL FUNCTIONS                                 ================ */
/* ================================================================================================================= */

/******************************************************************************
 * \Syntax          : void IntCtrl_Init(void)
 * \Description     : initialize Nvic/SCB Module by parsing the Configuration
 *                    into NVIC/SCB registers
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IntCtrl_Init(void)
{
    // Configure Grouping/Sub-Grouping System in SCB_APINT register
    #if (GROUPING_SYSTEM_CONTROL == 0)
        APINT = 0x05FA0000 | 0x400;        // XXX System Configuration
    #elif (GROUPING_SYSTEM_CONTROL == 1)
        APINT = 0x05FA0000 | 0x500;        // XXY System Configuration
    #elif (GROUPING_SYSTEM_CONTROL == 2)
        APINT = 0x05FA0000 | 0x600;        // XYY System Configuration
    #elif (GROUPING_SYSTEM_CONTROL == 3)
        APINT = 0x05FA0000 | 0x700;        // YYY System Configuration
    #else
        APINT = 0x05FA0000 | 0x400;        // XXX System Configuration
    #endif

    // Assign Group/Sub-Group priority in NVIC_PRIx and SCB_SYSPRIx Registers
    for (uint8 i = 0; i < NO_INTERRUPTS_ENABLED; i++)
    {
        if (intEnable[i].intId >= 0)
        {
            NVIC->PRIx[(uint32)(intEnable[i].intId)] |= ((((uint32)(intEnable[i].priority)) << 5U) & (uint32)0xFFU);
        }
    }

    // Enable/Disable based on user configurations in NVIC_ENx and SCB_SYSHNDCTRL Registers
    for (uint8 i = 0; i < NO_INTERRUPTS_ENABLED; i++)
    {
        if (intEnable[i].intId >= 0)
        {
            NVIC->ENx[((uint32)intEnable[i].intId) >> 5U] |= (1U << (((uint32)intEnable[i].intId) & 0x1FU));
        }
        else
        {
            if (intEnable[i].intId == BusFault_IRQn)
            {
                SYSHNDCTRL.BUS = ENABLE;
            }
            else if (intEnable[i].intId == UsageFault_IRQn)
            {
                SYSHNDCTRL.USAGE = ENABLE;
            }
            else if (intEnable[i].intId == MemoryManagement_IRQn)
            {
                SYSHNDCTRL.MEM = ENABLE;
            }
        }
    }

    return;
}

/* ================================================================================================================= */
/* ================                              END OF FILE: IntCtrl.c                             ================ */
/* ================================================================================================================= */
