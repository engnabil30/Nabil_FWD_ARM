/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : MCU_Hardware.h
 * 
 *  \category  : 
 * 
 *  \date      : 22 Sept. 2022
 * 
 *  \brief     : ARM Cortex-M4 TM4C123GH6PM Registers definitions
 *  
 *  \details   : All MCU ARM Cortex-M4 related addresses
 *
 *********************************************************************************************************************/

#ifndef MCU_HARDWARE_H
#define MCU_HARDWARE_H

/* ================================================================================================================= */
/* ================                                     INCLUDES                                    ================ */
/* ================================================================================================================= */

#include "Std_Types.h"

/* ================================================================================================================= */
/* ================                         GLOBAL DATA TYPES AND STRUCTURES                        ================ */
/* ================================================================================================================= */

typedef struct
{
    uint32 VECACT       :8;
    uint32              :3;
    uint32 RETBASE      :1;
    uint32 VECPEND      :8;
    uint32              :2;
    uint32 ISRPEND      :1;
    uint32 ISRPRE       :1;
    uint32              :1;
    uint32 PENDSTCLR    :1;
    uint32 PENDSTSET    :1;
    uint32 UNPENDSV     :1;
    uint32 PENDSV       :1;
    uint32              :2;
    uint32 NMISET       :1;
} INTCTRL_BF;

typedef union
{
    uint32 R;
    INTCTRL_BF B;
} INTCTRL_Tag;

typedef struct
{
    uint32 MEMA         :1;
    uint32 BUSA         :1;
    uint32              :1;
    uint32 USGA         :1;
    uint32              :3;
    uint32 SVCA         :1;
    uint32 MON          :1;
    uint32              :1;
    uint32 PNDSV        :1;
    uint32 TICK         :1;
    uint32 USAGEP       :1;
    uint32 MEMP         :1;
    uint32 BUSP         :1;
    uint32 SVC          :1;
    uint32 MEM          :1;
    uint32 BUS          :1;
    uint32 USAGE        :1;
    uint32              :13;
} SYSHNDCTRL_BF;

typedef struct 
{
    uint32 ENx[5U];
    uint32 RESERVED1[27U];
    uint32 DISx[5U];
    uint32 RESERVED2[27U];
    uint32 PENDx[5];
    uint32 RESERVED3[27];
    uint32 UNPENDx[5U];
    uint32 RESERVED4[27U];
    uint32 ACTIVEx[5U];
    uint32 RESERVED5[59U];
    uint8 PRIx[140U];
    uint32 RESERVED6[669U];
    uint32 SWTRIG;
} NVIC_Type;

typedef struct 
{
    uint8 SYSPRIx[12];
} SYSPRI_Type;



/* ================================================================================================================= */
/* ================                              GLOBAL CONSTANT MACROS                             ================ */
/* ================================================================================================================= */

/* <------------------------------------[ Cortex-M4 Registers Base Addresses ]-------------------------------------> */
#define CORE_PERI_BASE_ADDRESS                       0xE000E000
#define NVIC                                         ((volatile NVIC_Type*)(CORE_PERI_BASE_ADDRESS + 0x100))
#define SCB                                          ((volatile SYSPRI_Type*)(CORE_PERI_BASE_ADDRESS + 0xD18))
#define PRI0                                         (*((volatile uint32*)(CORE_PERI_BASE_ADDRESS + 0x400)))

/* <-------------------------------------[ SCB Peripheral Registers Addresses ]------------------------------------> */
#define SYSHNDCTRL                                   (*((volatile SYSHNDCTRL_BF*)(CORE_PERI_BASE_ADDRESS + 0xD24)))
#define APINT                                        *((volatile uint32*)(CORE_PERI_BASE_ADDRESS + 0xD0C))
#define SYSPRI1                                      *((volatile uint32*)(CORE_PERI_BASE_ADDRESS + 0xD18))
#define INTCTRL                                      (*((volatile INTCTRL_Tag*)(CORE_PERI_BASE_ADDRESS + 0xD04)))

/* <------------------------------------[ NVIC Peripheral Registers Addresses ]------------------------------------> */


#endif /* MCU_HARDWARE_H */

/* ================================================================================================================= */
/* ================                           END OF FILE: MCU_Hardware.h                           ================ */
/* ================================================================================================================= */
