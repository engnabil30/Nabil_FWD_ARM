/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : DioCtrl.c
 * 
 *  \category  : GPIO Driver
 * 
 *  \date      : 29 Sep. 2022
 * 
 *  \brief     : Operations of single bit (Read, Write)
 *  
 *  \details   : 
 *
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "DioCtrl.h"

/* ================================================================================================================= */
/* ================                                GLOBAL FUNCTIONS                                 ================ */
/* ================================================================================================================= */

/******************************************************************************************************
 *  \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortType portId, Dio_ChannelType channelId);
 *  \Description     : Reads the value of specific bit in specific port
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Reentrant
 *  \Parameters (in) : portId       Id of Port in which the pin we want to read from
 *                     channelId    Id of the Pin we want to read
 *  \Parameters (out): None
 *  \Return value:   : Dio_LevelType
 *****************************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType portId, Dio_ChannelType channelId)
{
    switch (portId)
    {
    case PORTA:
        return ((Dio_LevelType)BITBAND_PERI(GPIOA->DATA, channelId));
    case PORTB:
        return ((Dio_LevelType)BITBAND_PERI(GPIOB->DATA, channelId));
    case PORTC:
        return ((Dio_LevelType)BITBAND_PERI(GPIOC->DATA, channelId));
    case PORTD:
        return ((Dio_LevelType)BITBAND_PERI(GPIOD->DATA, channelId));
    case PORTE:
        return ((Dio_LevelType)BITBAND_PERI(GPIOE->DATA, channelId));
    case PORTF:
        return ((Dio_LevelType)BITBAND_PERI(GPIOF->DATA, channelId));
    }
}

/******************************************************************************************************
 *  \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortType portId, Dio_ChannelType channelId, Dio_LevelType level);
 *  \Description     : Sets the level value to specific PIN in specific Port
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Reentrant
 *  \Parameters (in) : portId       Id of Port in which the pin we want to write on
 *                     channelId    Id of the Pin we want to read
 *                     Level        Level of channel to be set whether HIGH or LOW
 *  \Parameters (out): None
 *  \Return value:   : void
 *****************************************************************************************************/
void Dio_WriteChannel(Dio_PortType portId, Dio_ChannelType channelId, Dio_LevelType level)
{
    switch (portId)
    {
    case PORTA:
        BITBAND_PERI(GPIOA->DATA, channelId) = level;
        break;
    case PORTB:
        BITBAND_PERI(GPIOB->DATA, channelId) = level;
        break;
    case PORTC:
        BITBAND_PERI(GPIOC->DATA, channelId) = level;
        break;
    case PORTD:
        BITBAND_PERI(GPIOD->DATA, channelId) = level;
        break;
    case PORTE:
        BITBAND_PERI(GPIOE->DATA, channelId) = level;
        break;
    case PORTF:
        BITBAND_PERI(GPIOF->DATA, channelId) = level;
        break;
    }
}

/******************************************************************************************************
 *  \Syntax          : void Dio_FlipChannel(Dio_PortType portId, Dio_ChannelType channelId)
 *  \Description     : Flip/Toggle the value of specific bit in specific port
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Reentrant
 *  \Parameters (in) : portId       Id of Port in which the pin we want to read from
 *                     channelId    Id of the Pin we want to read
 *  \Parameters (out): None
 *  \Return value:   : void
 *****************************************************************************************************/
void Dio_FlipChannel(Dio_PortType portId, Dio_ChannelType channelId)
{
    switch (portId)
    {
    case PORTA:
        BITBAND_PERI(GPIOA->DATA, channelId) ^= 1;
        break;
    case PORTB:
        BITBAND_PERI(GPIOB->DATA, channelId) ^= 1;
        break;
    case PORTC:
        BITBAND_PERI(GPIOC->DATA, channelId) ^= 1;
        break;
    case PORTD:
        BITBAND_PERI(GPIOD->DATA, channelId) ^= 1;
        break;
    case PORTE:
        BITBAND_PERI(GPIOE->DATA, channelId) ^= 1;
        break;
    case PORTF:
        BITBAND_PERI(GPIOF->DATA, channelId) ^= 1;
        break;
    }
}

/******************************************************************************************************
 *  \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType portId);
 *  \Description     : Reads the value of specific port
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Reentrant
 *  \Parameters (in) : portId       Id of Port to be read
 *  \Parameters (out): None
 *  \Return value:   : Dio_PortLevelType
 *****************************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType portId)
{
    switch (portId)
    {
    case PORTA:
        return ((Dio_PortLevelType)GPIOA->DATA);
    case PORTB:
        return ((Dio_PortLevelType)GPIOB->DATA);
    case PORTC:
        return ((Dio_PortLevelType)GPIOC->DATA);
    case PORTD:
        return ((Dio_PortLevelType)GPIOD->DATA);
    case PORTE:
        return ((Dio_PortLevelType)GPIOE->DATA);
    case PORTF:
        return ((Dio_PortLevelType)GPIOF->DATA);
    }
}

/******************************************************************************************************
 *  \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType portId);
 *  \Description     : Reads the value of specific port
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Reentrant
 *  \Parameters (in) : portId       Id of Port to write on
 *                     level        The 8-bit value to be wrote on port (Ex. 0x54);
 *  \Parameters (out): None
 *  \Return value:   : Dio_PortLevelType
 *****************************************************************************************************/
void Dio_WritePort(Dio_PortType portId, Dio_PortLevelType level)
{
    switch (portId)
    {
    case PORTA:
        (GPIOA->DATA) = level;
        break;
    case PORTB:
        (GPIOB->DATA) = level;
        break;
    case PORTC:
        (GPIOC->DATA) = level;
        break;
    case PORTD:
        (GPIOD->DATA) = level;
        break;
    case PORTE:
        (GPIOE->DATA) = level;
        break;
    case PORTF:
        (GPIOF->DATA) = level;
        break;
    }
}

/* ================================================================================================================= */
/* ================                             END OF FILE: DioCtrl.c                              ================ */
/* ================================================================================================================= */
