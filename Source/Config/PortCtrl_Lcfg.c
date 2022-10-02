/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : PortCtrl_Lcfg.c
 * 
 *  \category  : GPIO Driver
 * 
 *  \date      : 1 Oct. 2022
 * 
 *  \brief     : Contains configurations of the user
 *  
 *  \details   : 
 *
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "PortCtrl_Cfg.h"

/* ================================================================================================================= */
/* ================                             PORT USER CONFIGURATION                             ================ */
/* ================================================================================================================= */

/**********************************************************************************************************************
 *  Configuration port pins, Please type your configurations as following:
 * 
 *  {PORT, PIN, DIRECTION, AFSEL, ATTACHMENT, CURRENT}
 *  each configuration in new line seperated by comma
 * 
 *  PORT            PIN             DIRECTION           AFSEL               ATTACHMENT              CURRENT
 *  ----            ---             ---------           -------             ----------              -------
 *  PORTA           PIN0            INPUT               0 (DIO)             NONE                    _2MA
 *  PORTB           PIN1            OUTPUT              1                   PULL-UP                 _4MA
 *  PORTC           PIN2                                2                   PULL-DOWN               _8MA
 *  PORTD           PIN3                                3 
 *  PORTE           PIN4                                4
 *  PORTF           PIN5                                5
 *                  PIN6                                6
 *                  PIN7                                7
 *                                                      8
 *                                                      9
 *                                                      14
 *                                                      15
 * 
 *  Note: AFSEL Encodings 10-13 are not used on this device.
 *********************************************************************************************************************/
Port_ConfigType userConfig[GPIO_PINS_NUMBER] = 
{
    {PORTA, PIN1, OUTPUT, 0, PULL_UP, _8MA},
    {PORTA, PIN5, OUTPUT, 1, PULL_DOWN, _4MA},
    {PORTA, PIN2, OUTPUT, 0, DISABLE, _2MA},
    {PORTA, PIN3, OUTPUT, 5, PULL_UP, _8MA}
};



/* ================================================================================================================= */
/* ================                          END OF FILE: PortCtrl_Lcfg.c                           ================ */
/* ================================================================================================================= */
