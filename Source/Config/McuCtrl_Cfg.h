/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : McuCtrl_Cfg.h
 * 
 *  \category  : MCU Driver
 * 
 *  \date      : 27 Sep. 2022
 * 
 *  \brief     : Configurations file for McuCtrl 
 *  
 *  \details   : 
 *
 *********************************************************************************************************************/

#ifndef MCUCTRL_CFG_H
#define MCUCTRL_CFG_H

/* ================================================================================================================= */
/* ================                                     INCLUDES                                    ================ */
/* ================================================================================================================= */

#include "Std_Types.h"

/* ================================================================================================================= */
/* ================                      User Configurations for System Clock                       ================ */
/* ================================================================================================================= */

/**********************************************************************************************************************
 *  Configuration of Source of clock:
 *  0 -> Main Oscillator
 *  1 -> PIOSC (Precision internal oscillator)       (Default)
 *  3 -> PIOSC/4 (Precision internal oscillator / 4)
 *  4 -> LFIOSC (Low-frequency internal oscillator)
 *********************************************************************************************************************/
#define CLOCK_OSC_SOURCE 1

/**********************************************************************************************************************
 *  Configuration of Main Oscillator value:
 *  0 -> 4.0 MHz
 *  1 -> 4.096 MHz
 *  2 -> 4.9152 MHz
 *  3 -> 5 MHz (USB) (Least for PLL)
 *  4 -> 5.12 MHz
 *  5 -> 6 MHz (USB)
 *  6 -> 6.144 MHz
 *  7 -> 7.3728 MHz
 *  8 -> 8 MHz (USB)
 *  9 -> 8.192 MHz
 * 10 -> 10.0 MHz (USB)
 * 11 -> 12.0 MHz (USB)
 * 12 -> 12.288 MHz
 * 13 -> 13.56 MHz
 * 14 -> 14.31818 MHz
 * 15 -> 16.0 MHz (USB) (Default)
 * 16 -> 16.384 MHz
 * 17 -> 18.0 MHz (USB)
 * 18 -> 20.0 MHz (USB)
 * 19 -> 24.0 MHz (USB)
 * 20 -> 25.0 MHz (USB)
 * 
 * Note: Takes effect only if Main Oscillator is the clock source
 *********************************************************************************************************************/
#define XTAL_VALUE 15


/**********************************************************************************************************************
 *  Enable/Disable PLL :
 *  0 -> Disable PLL        (Default)
 *  1 -> Enable PLL
 * 
 * Note: Takes effect only if (PIOSC/Main Oscillator) is the clock source
 *********************************************************************************************************************/
#define ENABLE_PLL 0

/**********************************************************************************************************************
 *  Configuration of whether you want to divide clock frequency or not:
 *  0 -> Disable System division        (Default)
 *  1 -> Enable System division
 *********************************************************************************************************************/
#define ENABLE_SYSTEM_DIVISION 0

/**********************************************************************************************************************
 *  Configuration of divisor value:
 *  1 -> Source Frequency / 1
 *  2 -> Source Frequency / 2
 *  3 -> Source Frequency / 3
 *  4 -> Source Frequency / 4
 *  5 -> Source Frequency / 5
 *  6 -> Source Frequency / 6
 *  7 -> Source Frequency / 7
 *  8 -> Source Frequency / 8
 *  9 -> Source Frequency / 9
 * 10 -> Source Frequency / 10
 * 11 -> Source Frequency / 11
 * 12 -> Source Frequency / 12
 * 13 -> Source Frequency / 13
 * 14 -> Source Frequency / 14
 * 15 -> Source Frequency / 15
 * 16 -> Source Frequency / 16      (Default)
 *********************************************************************************************************************/
#define SYSTEM_DIVISION_VALUE 2

/* ================================================================================================================= */
/* ================                      User Configurations for Clock Gating                       ================ */
/* ================================================================================================================= */

/**********************************************************************************************************************
 *  Configuration of Clock Gating for each peripheral:
 *  0 -> Disable Clock for Peripheral
 *  1 -> Enable Clock for Peripheral
 * Defualt -> All modules are turned off by default to save power
 *********************************************************************************************************************/
#define ENABLE_WDT0   0             /* Watchdog Timer module 0 */

#define ENABLE_HIB    0             /* Hibernation module */

#define ENABLE_ADC0   0             /* ADC0 module */

#define ENABLE_ADC1   0             /* ADC0 module */

#define ENABLE_PWM0   0             /* PWM0 module */

#define ENABLE_CAN0   0             /* CAN0 module */

#define ENABLE_CAN1   0             /* CAN1 module */

#define ENABLE_WDT1   0             /* Watchdog Timer 1 module */

#define ENABLE_UART0  0             /* UART0 module */

#define ENABLE_UART1  0             /* UART1 module */

#define ENABLE_UART2  0             /* UART2 module */

#define ENABLE_SSI0   0             /* SSI0 module */

#define ENABLE_SSI1   0             /* SSI1 module */

#define ENABLE_QEI0   0             /* QEI0 module */

#define ENABLE_QEI1   0             /* QEI1 module */

#define ENABLE_I2C0   0             /* I2C0 module */

#define ENABLE_I2C1   0             /* I2C1 module */

#define ENABLE_TIMER0 0             /* Timer 0 module */

#define ENABLE_TIMER1 0             /* Timer 1 module */

#define ENABLE_TIMER2 0             /* Timer 2 module */

#define ENABLE_TIMER3 0             /* Timer 3 module */

#define ENABLE_COMP0  0             /* Analog Comparator 0 Module */

#define ENABLE_COMP1  0             /* Analog Comparator 1 Module */

#define ENABLE_GPIOA  1             /* GPIOA module */

#define ENABLE_GPIOB  0             /* GPIOB module */

#define ENABLE_GPIOC  0             /* GPIOC module */

#define ENABLE_GPIOD  0             /* GPIOD module */

#define ENABLE_GPIOE  0             /* GPIOE module */

#define ENABLE_GPIOF  0             /* GPIOF module */

#define ENABLE_UDMA   0             /* UDMA Module */

#define ENABLE_USB0   0             /* USB0 Module */

#endif /* MCUCTRL_CFG_H */

/* ================================================================================================================= */
/* ================                            END OF FILE: McuCtrl_Cfg.h                           ================ */
/* ================================================================================================================= */
