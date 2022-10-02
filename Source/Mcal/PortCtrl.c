/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : PortCtrl.c
 * 
 *  \category  : GPIO Driver
 * 
 *  \date      : 1 Oct. 2022
 * 
 *  \brief     : Initializes port configuration depending on user preference
 *  
 *  \details   : 
 *
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "PortCtrl.h"

/* ================================================================================================================= */
/* ================                                GLOBAL FUNCTIONS                                 ================ */
/* ================================================================================================================= */

/*************************************************************************************
 *  \Syntax          : void Port_Init(void)
 *  \Description     : Initializes all port configurations with values from user
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Reentrant
 *  \Parameters (in) : None
 *  \Parameters (out): None
 *  \Return value:   : void
 ************************************************************************************/
void Port_Init(void)
{
    for (uint8 i = 0; i < GPIO_NO_ENABLED_PINS; i++)
    {
        if (userConfig[i].port == PORTA)
        {
            /* Pin Direction initialization */
            switch (userConfig[i].dir)
            {
                case INPUT:
                    BITBAND_PERI(GPIOA->DIR, userConfig[i].pin) = INPUT;
                    break;
                case OUTPUT:
                    BITBAND_PERI(GPIOA->DIR, userConfig[i].pin) = OUTPUT;
                    break;
            }

            /* Pin Mode initialization */
            if (userConfig[i].mode == 0)
            {
                BITBAND_PERI(GPIOA->DEN, userConfig[i].pin) = ENABLE;
            }
            else if (userConfig[i].mode > 0 && userConfig[i].mode < 16)
            {
                BITBAND_PERI(GPIOA->AFSEL, userConfig[i].pin) = ENABLE;
                GPIOA->PCTL |= (uint32)(userConfig[i].mode << (userConfig[i].pin * 4));
            }

            /* Pin Resistor Attachment initialization */
            switch (userConfig[i].attach)
            {
                case NONE:
                    BITBAND_PERI(GPIOA->PUR, userConfig[i].pin) = DISABLE;
                    BITBAND_PERI(GPIOA->PDR, userConfig[i].pin) = DISABLE;
                    break;
                case PULL_UP:
                    BITBAND_PERI(GPIOA->PUR, userConfig[i].pin) = ENABLE;
                    break;
                case PULL_DOWN:
                    BITBAND_PERI(GPIOA->PDR, userConfig[i].pin) = ENABLE;
                    break;
            }

            /* Pin Current initialization */
            switch (userConfig[i].current)
            {
                case _2MA:
                    BITBAND_PERI(GPIOA->DR2R, userConfig[i].pin) = ENABLE;
                    break;
                case _4MA:
                    BITBAND_PERI(GPIOA->DR4R, userConfig[i].pin) = ENABLE;
                    break;
                case _8MA:
                    BITBAND_PERI(GPIOA->DR8R, userConfig[i].pin) = ENABLE;
                    break;
            }
        }

        else if (userConfig[i].port == PORTB)
        {
            /* Pin Direction initialization */
            switch (userConfig[i].dir)
            {
                case INPUT:
                    BITBAND_PERI(GPIOB->DIR, userConfig[i].pin) = INPUT;
                    break;
                case OUTPUT:
                    BITBAND_PERI(GPIOB->DIR, userConfig[i].pin) = OUTPUT;
                    break;
            }

            /* Pin Mode initialization */
            if (userConfig[i].mode == 0)
            {
                BITBAND_PERI(GPIOB->DEN, userConfig[i].pin) = ENABLE;
            }
            else if (userConfig[i].mode > 0 && userConfig[i].mode < 16)
            {
                GPIOB->PCTL |= (uint32)(userConfig[i].mode << (userConfig[i].pin * 4));
            }

            /* Pin Resistor Attachment initialization */
            switch (userConfig[i].attach)
            {
                case NONE:
                    BITBAND_PERI(GPIOB->PUR, userConfig[i].pin) = DISABLE;
                    BITBAND_PERI(GPIOB->PDR, userConfig[i].pin) = DISABLE;
                    break;
                case PULL_UP:
                    BITBAND_PERI(GPIOB->PUR, userConfig[i].pin) = ENABLE;
                    break;
                case PULL_DOWN:
                    BITBAND_PERI(GPIOB->PDR, userConfig[i].pin) = ENABLE;
                    break;
            }

            /* Pin Current initialization */
            switch (userConfig[i].current)
            {
                case _2MA:
                    BITBAND_PERI(GPIOB->DR2R, userConfig[i].pin) = ENABLE;
                    break;
                case _4MA:
                    BITBAND_PERI(GPIOB->DR4R, userConfig[i].pin) = ENABLE;
                    break;
                case _8MA:
                    BITBAND_PERI(GPIOB->DR8R, userConfig[i].pin) = ENABLE;
                    break;
            }
        }

        else if (userConfig[i].port == PORTC)
        {
            /* Pin Direction initialization */
            switch (userConfig[i].dir)
            {
                case INPUT:
                    BITBAND_PERI(GPIOC->DIR, userConfig[i].pin) = INPUT;
                    break;
                case OUTPUT:
                    BITBAND_PERI(GPIOC->DIR, userConfig[i].pin) = OUTPUT;
                    break;
            }

            /* Pin Mode initialization */
            if (userConfig[i].mode == 0)
            {
                BITBAND_PERI(GPIOC->DEN, userConfig[i].pin) = ENABLE;
            }
            else if (userConfig[i].mode > 0 && userConfig[i].mode < 16)
            {
                GPIOC->PCTL |= (uint32)(userConfig[i].mode << (userConfig[i].pin * 4));
            }

            /* Pin Resistor Attachment initialization */
            switch (userConfig[i].attach)
            {
                case NONE:
                    BITBAND_PERI(GPIOC->PUR, userConfig[i].pin) = DISABLE;
                    BITBAND_PERI(GPIOC->PDR, userConfig[i].pin) = DISABLE;
                    break;
                case PULL_UP:
                    BITBAND_PERI(GPIOC->PUR, userConfig[i].pin) = ENABLE;
                    break;
                case PULL_DOWN:
                    BITBAND_PERI(GPIOC->PDR, userConfig[i].pin) = ENABLE;
                    break;
            }

            /* Pin Current initialization */
            switch (userConfig[i].current)
            {
                case _2MA:
                    BITBAND_PERI(GPIOC->DR2R, userConfig[i].pin) = ENABLE;
                    break;
                case _4MA:
                    BITBAND_PERI(GPIOC->DR4R, userConfig[i].pin) = ENABLE;
                    break;
                case _8MA:
                    BITBAND_PERI(GPIOC->DR8R, userConfig[i].pin) = ENABLE;
                    break;
            }
        }

        else if (userConfig[i].port == PORTD)
        {
            /* Pin Direction initialization */
            switch (userConfig[i].dir)
            {
                case INPUT:
                    BITBAND_PERI(GPIOD->DIR, userConfig[i].pin) = INPUT;
                    break;
                case OUTPUT:
                    BITBAND_PERI(GPIOD->DIR, userConfig[i].pin) = OUTPUT;
                    break;
            }

            /* Pin Mode initialization */
            if (userConfig[i].mode == 0)
            {
                BITBAND_PERI(GPIOD->DEN, userConfig[i].pin) = ENABLE;
            }
            else if (userConfig[i].mode > 0 && userConfig[i].mode < 16)
            {
                GPIOD->PCTL |= (uint32)(userConfig[i].mode << (userConfig[i].pin * 4));
            }

            /* Pin Resistor Attachment initialization */
            switch (userConfig[i].attach)
            {
                case NONE:
                    BITBAND_PERI(GPIOD->PUR, userConfig[i].pin) = DISABLE;
                    BITBAND_PERI(GPIOD->PDR, userConfig[i].pin) = DISABLE;
                    break;
                case PULL_UP:
                    BITBAND_PERI(GPIOD->PUR, userConfig[i].pin) = ENABLE;
                    break;
                case PULL_DOWN:
                    BITBAND_PERI(GPIOD->PDR, userConfig[i].pin) = ENABLE;
                    break;
            }

            /* Pin Current initialization */
            switch (userConfig[i].current)
            {
                case _2MA:
                    BITBAND_PERI(GPIOD->DR2R, userConfig[i].pin) = ENABLE;
                    break;
                case _4MA:
                    BITBAND_PERI(GPIOD->DR4R, userConfig[i].pin) = ENABLE;
                    break;
                case _8MA:
                    BITBAND_PERI(GPIOD->DR8R, userConfig[i].pin) = ENABLE;
                    break;
            }
        }

        else if (userConfig[i].port == PORTE)
        {
            /* Pin Direction initialization */
            switch (userConfig[i].dir)
            {
                case INPUT:
                    BITBAND_PERI(GPIOE->DIR, userConfig[i].pin) = INPUT;
                    break;
                case OUTPUT:
                    BITBAND_PERI(GPIOE->DIR, userConfig[i].pin) = OUTPUT;
                    break;
            }

            /* Pin Mode initialization */
            if (userConfig[i].mode == 0)
            {
                BITBAND_PERI(GPIOE->DEN, userConfig[i].pin) = ENABLE;
            }
            else if (userConfig[i].mode > 0 && userConfig[i].mode < 16)
            {
                GPIOE->PCTL |= (uint32)(userConfig[i].mode << (userConfig[i].pin * 4));
            }

            /* Pin Resistor Attachment initialization */
            switch (userConfig[i].attach)
            {
                case NONE:
                    BITBAND_PERI(GPIOE->PUR, userConfig[i].pin) = DISABLE;
                    BITBAND_PERI(GPIOE->PDR, userConfig[i].pin) = DISABLE;
                    break;
                case PULL_UP:
                    BITBAND_PERI(GPIOE->PUR, userConfig[i].pin) = ENABLE;
                    break;
                case PULL_DOWN:
                    BITBAND_PERI(GPIOE->PDR, userConfig[i].pin) = ENABLE;
                    break;
            }

            /* Pin Current initialization */
            switch (userConfig[i].current)
            {
                case _2MA:
                    BITBAND_PERI(GPIOE->DR2R, userConfig[i].pin) = ENABLE;
                    break;
                case _4MA:
                    BITBAND_PERI(GPIOE->DR4R, userConfig[i].pin) = ENABLE;
                    break;
                case _8MA:
                    BITBAND_PERI(GPIOE->DR8R, userConfig[i].pin) = ENABLE;
                    break;
            }
        }

        else if (userConfig[i].port == PORTF)
        {
            /* Pin Direction initialization */
            switch (userConfig[i].dir)
            {
                case INPUT:
                    BITBAND_PERI(GPIOF->DIR, userConfig[i].pin) = INPUT;
                    break;
                case OUTPUT:
                    BITBAND_PERI(GPIOF->DIR, userConfig[i].pin) = OUTPUT;
                    break;
            }

            /* Pin Mode initialization */
            if (userConfig[i].mode == 0)
            {
                BITBAND_PERI(GPIOF->DEN, userConfig[i].pin) = ENABLE;
            }
            else if (userConfig[i].mode > 0 && userConfig[i].mode < 16)
            {
                GPIOF->PCTL |= (uint32)(userConfig[i].mode << (userConfig[i].pin * 4));
            }

            /* Pin Resistor Attachment initialization */
            switch (userConfig[i].attach)
            {
                case NONE:
                    BITBAND_PERI(GPIOF->PUR, userConfig[i].pin) = DISABLE;
                    BITBAND_PERI(GPIOF->PDR, userConfig[i].pin) = DISABLE;
                    break;
                case PULL_UP:
                    BITBAND_PERI(GPIOF->PUR, userConfig[i].pin) = ENABLE;
                    break;
                case PULL_DOWN:
                    BITBAND_PERI(GPIOF->PDR, userConfig[i].pin) = ENABLE;
                    break;
            }

            /* Pin Current initialization */
            switch (userConfig[i].current)
            {
                case _2MA:
                    BITBAND_PERI(GPIOF->DR2R, userConfig[i].pin) = ENABLE;
                    break;
                case _4MA:
                    BITBAND_PERI(GPIOF->DR4R, userConfig[i].pin) = ENABLE;
                    break;
                case _8MA:
                    BITBAND_PERI(GPIOF->DR8R, userConfig[i].pin) = ENABLE;
                    break;
            }
        }
    }
}

/* ================================================================================================================= */
/* ================                             END OF FILE: PortCtrl.c                             ================ */
/* ================================================================================================================= */
