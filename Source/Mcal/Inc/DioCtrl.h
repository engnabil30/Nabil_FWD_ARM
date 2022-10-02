/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : DioCtrl.h
 * 
 *  \category  : GPIO Driver
 * 
 *  \date      : 29 Sep. 2022
 * 
 *  \brief     : Interface file for DioCtrl
 *  
 *  \details   : 
 *
 *********************************************************************************************************************/

#ifndef DIOCTRL_H
#define DIOCTRL_H

/* ================================================================================================================= */
/* ================                                     INCLUDES                                    ================ */
/* ================================================================================================================= */

#include "DioCtrl_Types.h"
#include "Macros.h"
#include "MCU_Hardware.h"

/* ================================================================================================================= */
/* ================                            GLOBAL FUNCTION PROTOTYPES                           ================ */
/* ================================================================================================================= */

/******************************************************************************************************
 *  \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortType portId, Dio_ChannelType channelId)
 *  \Description     : Reads the value of specific bit in specific port
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Reentrant
 *  \Parameters (in) : portId       Id of Port in which the pin we want to read from
 *                     channelId    Id of the Pin we want to read
 *  \Parameters (out): None
 *  \Return value:   : Dio_LevelType
 *****************************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType portId, Dio_ChannelType channelId);

/******************************************************************************************************
 *  \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortType portId, Dio_ChannelType channelId, Dio_LevelType level)
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
void Dio_WriteChannel(Dio_PortType portId, Dio_ChannelType channelId, Dio_LevelType level);

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
void Dio_FlipChannel(Dio_PortType portId, Dio_ChannelType channelId);

/******************************************************************************************************
 *  \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType portId)
 *  \Description     : Reads the value of specific port
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Reentrant
 *  \Parameters (in) : portId       Id of Port to be read
 *  \Parameters (out): None
 *  \Return value:   : Dio_PortLevelType
 *****************************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType portId);

/******************************************************************************************************
 *  \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType portId)
 *  \Description     : Reads the value of specific port
 *
 *  \Sync\Async      : Synchronous
 *  \Reentrancy      : Reentrant
 *  \Parameters (in) : portId       Id of Port to write on
 *                     level        The 8-bit value to be wrote on port (Ex. 0x54)
 *  \Parameters (out): None
 *  \Return value:   : Dio_PortLevelType
 *****************************************************************************************************/
void Dio_WritePort(Dio_PortType portId, Dio_PortLevelType level);

#endif /* DIOCTRL_H */

/* ================================================================================================================= */
/* ================                             END OF FILE: DioCtrl.h                              ================ */
/* ================================================================================================================= */
