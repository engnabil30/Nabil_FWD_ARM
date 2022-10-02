/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : PortCtrl_Types.h
 * 
 *  \category  : GPIO Driver
 * 
 *  \date      : 1 Oct. 2022
 * 
 *  \brief     : Contains types of configurations
 *  
 *  \details   : 
 *
 *********************************************************************************************************************/

#ifndef PORTCTRL_TYPES_H
#define PORTCTRL_TYPES_H

/* ================================================================================================================= */
/* ================                                     INCLUDES                                    ================ */
/* ================================================================================================================= */

#include "Std_Types.h"
#include "DioCtrl_Types.h"

/* ================================================================================================================= */
/* ================                         GLOBAL DATA TYPES AND STRUCTURES                        ================ */
/* ================================================================================================================= */

typedef uint8 Port_PinModeType;

typedef enum
{
    INPUT,
    OUTPUT
} Port_PinDirectionType;

typedef enum
{
    _2MA,
    _4MA,
    _8MA
} Port_PinOutputCurrentType;

typedef enum
{
    NONE,
    PULL_UP,
    PULL_DOWN
} Port_PinInternalAttachType;

typedef struct 
{
    Dio_PortType port;
    Dio_ChannelType pin;
    Port_PinDirectionType dir;
    Port_PinModeType mode;
    Port_PinInternalAttachType attach;
    Port_PinOutputCurrentType current;
} Port_ConfigType;


#endif /* PORTCTRL_TYPES_H */

/* ================================================================================================================= */
/* ================                          END OF FILE: PortCtrl_Types.h                          ================ */
/* ================================================================================================================= */
