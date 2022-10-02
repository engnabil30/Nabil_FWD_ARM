/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : McuCtrl.c
 * 
 *  \category  : MCU Driver
 * 
 *  \date      : 27 Sep. 2022
 * 
 *  \brief     : Source file for McuCtrl
 *  
 *  \details   : 
 *
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "McuCtrl.h"

/* ================================================================================================================= */
/* ================                                GLOBAL FUNCTIONS                                 ================ */
/* ================================================================================================================= */

/******************************************************************************************
 *  \Syntax          : void McuCtrl_Init(void)
 *  \Description     : Initializes MCU Driver using user configurations of Reset & Clock
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Non Reentrant
 *  \Parameters (in) : None
 *  \Parameters (out): None
 *  \Return value:   : void
 *****************************************************************************************/
void McuCtrl_Init(void)
{
    /* Initialization of Clock Source */
    #if (CLOCK_OSC_SOURCE == 0)
        #if (XTAL_VALUE >=0 && XTAL_VALUE <= 20)
            SYSCTRL->RCC.XTAL = XTAL_VALUE + 0x6U;
        #else
            SYSCTRL->RCC.XTAL = 15 + 0x6U;
        #endif

        SYSCTRL->RCC.MOSCDIS = 0x00;        /* Enable Main Oscillator */

        SYSCTRL->RCC.OSCSRC = 0x00;         /* Clock Source is Main Oscillator */
    #elif (CLOCK_OSC_SOURCE == 1)
        SYSCTRL->RCC.OSCSRC = 0x01;         /* Clock Source is PIOSC (Precision internal oscillator) */
    #elif (CLOCK_OSC_SOURCE == 2)
        SYSCTRL->RCC.OSCSRC = 0x02;         /* Clock Source is PIOSC / 4 */
    #elif (CLOCK_OSC_SOURCE == 3)
        SYSCTRL->RCC.OSCSRC = 0x03;         /* Clock Source is LFIOSC (Low-frequency internal oscillator) */
    #else
        SYSCTRL->RCC.OSCSRC = 0x01;         /* Default Clock Source is PIOSC */
    #endif

    /* Initialization of PLL */
    #if (ENABLE_PLL == 1)
        #if (CLOCK_OSC_SOURCE == 0 || CLOCK_OSC_SOURCE == 1)
            SYSCTRL->RCC.BYPASS = 0;  /* Needs 0 to enable PLL */
            SYSCTRL->RCC.PWRDN = 0;   /* Needs 0 to Enable PLL */

            while (GET_BIT(SYSCTRL->PLLSTAT, 0) == 0)   /* Check if PLL still Unlocked */
            {
                
                /* Do nothing waiting for PLL to be locked */
            }
        #endif

    #else
        SYSCTRL->RCC.BYPASS = 1;            /* Disable PLL by default */
        SYSCTRL->RCC.PWRDN = 1;             /* Disable PLL by default */
    #endif

    /* Initialization of system clock division */
    #if (ENABLE_SYSTEM_DIVISION == 1 || ENABLE_PLL == 1)
        #if (SYSTEM_DIVISION_VALUE >= 1 && SYSTEM_DIVISION_VALUE <= 16)
            SYSCTRL->RCC.SYSDIV = SYSTEM_DIVISION_VALUE - 1;    /* Taking 1 to match the right input starting from 0 */

        #else
            SYSCTRL->RCC.SYSDIV = 0xF;      /* Default Divisor /16 */
        #endif
        SYSCTRL->RCC.USESYSDIV = 1;

    #else
        SYSCTRL->RCC.SYSDIV = 0;
    #endif

    /* Initialization of Clock Gating for different peripherals */

    /* RCGC0 Register Peripherals */
    #if (ENABLE_WDT0 == 1)
        SET_BIT(SYSCTRL->RCGC0, 0);
    #endif

    #if (ENABLE_HIB == 1)
        SET_BIT(SYSCTRL->RCGC0, 6);
    #endif

    #if (ENABLE_ADC0 == 1)
        SET_BIT(SYSCTRL->RCGC0, 16);
    #endif

    #if (ENABLE_ADC1 == 1)
        SET_BIT(SYSCTRL->RCGC0, 17);
    #endif

    #if (ENABLE_PWM0 == 1)
        SET_BIT(SYSCTRL->RCGC0, 20);
    #endif

    #if (ENABLE_CAN0 == 1)
        SET_BIT(SYSCTRL->RCGC0, 24);
    #endif

    #if (ENABLE_CAN1 == 1)
        SET_BIT(SYSCTRL->RCGC0, 25);
    #endif

    #if (ENABLE_WDT1 == 1)
        SET_BIT(SYSCTRL->RCGC0, 28);
    #endif

    /* RCGC1 Register Peripherals */
    #if (ENABLE_UART0 == 1)
        SET_BIT(SYSCTRL->RCGC1, 0);
    #endif
    
    #if (ENABLE_UART1 == 1)
        SET_BIT(SYSCTRL->RCGC1, 1);
    #endif

    #if (ENABLE_UART2 == 1)
        SET_BIT(SYSCTRL->RCGC1, 2);
    #endif

    #if (ENABLE_SSI0 == 1)
        SET_BIT(SYSCTRL->RCGC1, 4);
    #endif

    #if (ENABLE_SSI1 == 1)
        SET_BIT(SYSCTRL->RCGC1, 5);
    #endif

    #if (ENABLE_QEI0 == 1)
        SET_BIT(SYSCTRL->RCGC1, 8);
    #endif

    #if (ENABLE_QEI1 == 1)
        SET_BIT(SYSCTRL->RCGC1, 9);
    #endif

    #if (ENABLE_I2C0 == 1)
        SET_BIT(SYSCTRL->RCGC1, 12);
    #endif

    #if (ENABLE_I2C1 == 1)
        SET_BIT(SYSCTRL->RCGC1, 14);
    #endif

    #if (ENABLE_TIMER0 == 1)
        SET_BIT(SYSCTRL->RCGC1, 16);
    #endif

    #if (ENABLE_TIMER1 == 1)
        SET_BIT(SYSCTRL->RCGC1, 17);
    #endif

    #if (ENABLE_TIMER2 == 1)
        SET_BIT(SYSCTRL->RCGC1, 18);
    #endif

    #if (ENABLE_TIMER3 == 1)
        SET_BIT(SYSCTRL->RCGC1, 19);
    #endif

    #if (ENABLE_COMP0 == 1)
        SET_BIT(SYSCTRL->RCGC1, 24);
    #endif

    #if (ENABLE_COMP1 == 1)
        SET_BIT(SYSCTRL->RCGC1, 25);
    #endif

    /* RCGC2 Register Peripherals */
    #if (ENABLE_GPIOA == 1)
        SET_BIT(SYSCTRL->RCGC2, 0);
    #endif

    #if (ENABLE_GPIOB == 1)
        SET_BIT(SYSCTRL->RCGC2, 1);
    #endif

    #if (ENABLE_GPIOC == 1)
        SET_BIT(SYSCTRL->RCGC2, 2);
    #endif

    #if (ENABLE_GPIOD == 1)
        SET_BIT(SYSCTRL->RCGC2, 3);
    #endif

    #if (ENABLE_GPIOE == 1)
        SET_BIT(SYSCTRL->RCGC2, 4);
    #endif

    #if (ENABLE_GPIOF == 1)
        SET_BIT(SYSCTRL->RCGC2, 5);
    #endif

    #if (ENABLE_UDMA == 1)
        SET_BIT(SYSCTRL->RCGC2, 13);
    #endif

    #if (ENABLE_USB0 == 1)
        SET_BIT(SYSCTRL->RCGC2, 16);
    #endif
}

/* ================================================================================================================= */
/* ================                              END OF FILE: McuCtrl.c                             ================ */
/* ================================================================================================================= */
