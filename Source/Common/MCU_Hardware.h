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

/* <-----------------------------------------[ NVIC Peripheral Structures ]----------------------------------------> */
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

/* <-----------------------------------------[ SCB Peripheral Structures ]-----------------------------------------> */
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
    uint8 SYSPRIx[12];
} SYSPRI_Type;

/* <--------------------------------------[ System Control Module Structures ]-------------------------------------> */

/* Allowing accessing RCC register using bit fields */
typedef struct
{
    uint32 MOSCDIS      :1;
    uint32              :3;
    uint32 OSCSRC       :2;
    uint32 XTAL         :5;
    uint32 BYPASS       :1;
    uint32              :1;
    uint32 PWRDN        :1;
    uint32              :3;
    uint32 PWMDIV       :3;
    uint32 USEPWMDIV    :1;
    uint32              :1;
    uint32 USESYSDIV    :1;
    uint32 SYSDIV       :4;
    uint32 ACG          :1;
    uint32              :4;
} RCC_BF;

/* Allowing accessing RCC register using bit fields */
typedef struct
{
    uint32              :4;
    uint32 OSCSRC2      :3;
    uint32              :4;
    uint32 BYPASS2      :1;
    uint32              :1;
    uint32 PWRDN2       :1;
    uint32 USBPWRDN     :1;
    uint32              :7;
    uint32 SYSDIV2LSB   :1;
    uint32 SYSDIV2      :6;
    uint32              :1;
    uint32 DIV400       :1;
    uint32 USERCC2      :1;
} RCC2_BF;

/* Structure of all registers in System control module */
typedef struct
{
    uint32 DID0;
    uint32 DID1;
    uint32 DC0;
    uint32 RESERVED1;
    uint32 DC1;
    uint32 DC2;
    uint32 DC3;
    uint32 DC4;
    uint32 DC5;
    uint32 DC6;
    uint32 DC7;
    uint32 DC8;
    uint32 PBORCTL;
    uint32 RESERVED2[3];
    uint32 SRCR0;
    uint32 SRCR1;
    uint32 SRCR2;
    uint32 RESERVED2_5;
    uint32 RIS;
    uint32 IMC;
    uint32 MISC;
    uint32 RESC;
    RCC_BF RCC;
    uint32 RESERVED3[2];
    uint32 GPIOHBCTL;
    RCC2_BF RCC2;
    uint32 RESERVED4[2];
    uint32 MOSCCTL;
    uint32 RESERVED5[32];
    uint32 RCGC0;
    uint32 RCGC1;
    uint32 RCGC2;
    uint32 RESERVED5_5;
    uint32 SCGC0;
    uint32 SCGC1;
    uint32 SCGC2;
    uint32 RESERVED5_7;
    uint32 DCGC0;
    uint32 DCGC1;
    uint32 DCGC2;
    uint32 RESERVED5_8[6];
    uint32 DSLPCLKCFG;
    uint32 RESERVED6;
    uint32 SYSPROP;
    uint32 PIOSCCAL;
    uint32 PIOSCSTAT;
    uint32 RESERVED7[2];
    uint32 PLLFREQ0;
    uint32 PLLFREQ1;
    uint32 PLLSTAT;
    uint32 RESERVED8[7];
    uint32 SLPPWRCFG;
    uint32 DSLPPWRCFG;
    uint32 DC9;
    uint32 RESERVED8_5[3];
    uint32 NVMSTAT;
    uint32 RESERVED9[4];
    uint32 LDOSPCTL;
    uint32 LDOSPCAL;
    uint32 LDODPCTL;
    uint32 LDODPCAL;
    uint32 RESERVED10[2];
    uint32 SDPMST;
    uint32 RESERVED11[76];
    uint32 PPWD;
    uint32 PPTIMER;
    uint32 PPGPIO;
    uint32 PPDMA;
    uint32 RESERVED12;
    uint32 PPHIB;
    uint32 PPUART;
    uint32 PPSSI;
    uint32 PPI2C;
    uint32 RESERVED13;
    uint32 PPUSB;
    uint32 RESERVED14[2];
    uint32 PPCAN;
    uint32 PPADC;
    uint32 PPACMP;
    uint32 PPPWM;
    uint32 PPQEI;
    uint32 RESERVED15[4];
    uint32 PPEEPROM;
    uint32 PPWTIMER;
    uint32 RESERVED16[104];
    uint32 SRWD;
    uint32 SRTIMER;
    uint32 SRGPIO;
    uint32 SRDMA;
    uint32 RESERVED17;
    uint32 SRHIB;
    uint32 SRUART;
    uint32 SRSSI;
    uint32 SRI2C;
    uint32 RESERVED18;
    uint32 SRUSB;
    uint32 RESERVED19[2];
    uint32 SRCAN;
    uint32 SRADC;
    uint32 SRACMP;
    uint32 SRPWM;
    uint32 SRQEI;
    uint32 RESERVED20[4];
    uint32 SREEPROM;
    uint32 SRWTIMER;
    uint32 RESERVED21[40];
    uint32 RCGCWD;
    uint32 RCGCTIMER;
    uint32 RCGCGPIO;
    uint32 RCGCDMA;
    uint32 RESERVED22;
    uint32 RCGCHIB;
    uint32 RCGCUART;
    uint32 RCGCSSI;
    uint32 RCGCI2C;
    uint32 RESERVED23;
    uint32 RCGCUSB;
    uint32 RESERVED24[2];
    uint32 RCGCCAN;
    uint32 RCGCADC;
    uint32 RCGCACMP;
    uint32 RCGCPWM;
    uint32 RCGCQEI;
    uint32 RESERVED25[4];
    uint32 RCGCEEPROM;
    uint32 RCGCWTIMER;
    uint32 RESERVED26[40];
    uint32 SCGCWD;
    uint32 SCGCTIMER;
    uint32 SCGCGPIO;
    uint32 SCGCDMA;
    uint32 RESERVED27;
    uint32 SCGCHIB;
    uint32 SCGCUART;
    uint32 SCGCSSI;
    uint32 SCGCI2C;
    uint32 RESERVED28;
    uint32 SCGCUSB;
    uint32 RESERVED29[2];
    uint32 SCGCCAN;
    uint32 SCGCADC;
    uint32 SCGCACMP;
    uint32 SCGCPWM;
    uint32 SCGCQEI;
    uint32 RESERVED30[4];
    uint32 SCGCEEPROM;
    uint32 SCGCWTIMER;
    uint32 RESERVED31[40];
    uint32 DCGCWD;
    uint32 DCGCTIMER;
    uint32 DCGCGPIO;
    uint32 DCGCDMA;
    uint32 RESERVED32;
    uint32 DCGCHIB;
    uint32 DCGCUART;
    uint32 DCGCSSI;
    uint32 DCGCI2C;
    uint32 RESERVED33;
    uint32 DCGCUSB;
    uint32 RESERVED34[2];
    uint32 DCGCCAN;
    uint32 DCGCADC;
    uint32 DCGCACMP;
    uint32 DCGCPWM;
    uint32 DCGCQEI;
    uint32 RESERVED35[4];
    uint32 DCGCEEPROM;
    uint32 DCGCWTIMER;
    uint32 RESERVED36[104];
    uint32 PRWD;
    uint32 PRTIMER;
    uint32 PRGPIO;
    uint32 PRDMA;
    uint32 RESERVED37;
    uint32 PRHIB;
    uint32 PRUART;
    uint32 PRSSI;
    uint32 PRI2C;
    uint32 RESERVED38;
    uint32 PRUSB;
    uint32 RESERVED39[2];
    uint32 PRCAN;
    uint32 PRADC;
    uint32 PRACMP;
    uint32 PRPWM;
    uint32 PRQEI;
    uint32 RESERVED40[4];
    uint32 PREEPROM;
    uint32 PRWTIMER;
} SYSCTRL_Type;


/* <-------------------------------------------[ GPIO Module Structures ]------------------------------------------> */

/* GPIO Registers structure */
typedef struct 
{
    uint32 RESERVED1[255];
    uint32 DATA;
    uint32 DIR;
    uint32 IS;
    uint32 IBE;
    uint32 IEV;
    uint32 IM;
    uint32 RIS;
    uint32 MIS;
    uint32 ICR;
    uint32 AFSEL;
    uint32 RESERVED2[55];
    uint32 DR2R;
    uint32 DR4R;
    uint32 DR8R;
    uint32 ODR;
    uint32 PUR;
    uint32 PDR;
    uint32 SLR;
    uint32 DEN;
    uint32 LOCK;
    uint32 CR;
    uint32 AMSEL;
    uint32 PCTL;
    uint32 ADCCTL;
    uint32 DMACT;
} GPIO_Type;

typedef struct 
{
    uint32 DATA[8];
} GPIODATA_Type;

/* ================================================================================================================= */
/* ================                              GLOBAL CONSTANT MACROS                             ================ */
/* ================================================================================================================= */

/* <------------------------------------[ Cortex-M4 Registers Base Addresses ]-------------------------------------> */
#define CORE_PERI_BASE_ADDRESS                       0xE000E000UL
#define NVIC                                         ((volatile NVIC_Type*)(CORE_PERI_BASE_ADDRESS + 0x100))
#define SCB                                          ((volatile SYSPRI_Type*)(CORE_PERI_BASE_ADDRESS + 0xD18))

/* <-------------------------------------[ SCB Peripheral Registers Addresses ]------------------------------------> */
#define SYSHNDCTRL                                   (*((volatile SYSHNDCTRL_BF*)(CORE_PERI_BASE_ADDRESS + 0xD24)))
#define APINT                                        *((volatile uint32*)(CORE_PERI_BASE_ADDRESS + 0xD0C))
#define SYSPRI1                                      *((volatile uint32*)(CORE_PERI_BASE_ADDRESS + 0xD18))
#define INTCTRL                                      (*((volatile INTCTRL_Tag*)(CORE_PERI_BASE_ADDRESS + 0xD04)))

/* <------------------------------------[ MCU Peripherals Registers Addresses ]------------------------------------> */

/* Bit-Banding region */
#define BITBAND_PERI_BASE_ADDRESS                    0x40000000UL
#define BITBAND_ALIAS_BASE_ADDRESS                   0x42000000UL

/* System Control Module */
#define SYSTEM_CTRL_BASE_ADDRESS                     0x400FE000UL
#define SYSCTRL                                      ((volatile SYSCTRL_Type*)(SYSTEM_CTRL_BASE_ADDRESS))

/* GPIO Module */
#define GPIOA_BASE_ADDRESS                           0x40004000UL
#define GPIOB_BASE_ADDRESS                           0x40005000UL
#define GPIOC_BASE_ADDRESS                           0x40006000UL
#define GPIOD_BASE_ADDRESS                           0x40007000UL
#define GPIOE_BASE_ADDRESS                           0x40024000UL
#define GPIOF_BASE_ADDRESS                           0x40025000UL

#define GPIOA_AHB_BASE_ADDRESS                       0x40058000UL
#define GPIOB_AHB_BASE_ADDRESS                       0x40059000UL
#define GPIOC_AHB_BASE_ADDRESS                       0x4005A000UL
#define GPIOD_AHB_BASE_ADDRESS                       0x4005B000UL
#define GPIOE_AHB_BASE_ADDRESS                       0x4005C000UL
#define GPIOF_AHB_BASE_ADDRESS                       0x4005D000UL

#ifdef PORTA_AHB
#define GPIOA                                        ((volatile GPIO_Type*)(GPIOA_AHB_BASE_ADDRESS))
#else
#define GPIOA                                        ((volatile GPIO_Type*)(GPIOA_BASE_ADDRESS))
#endif
#ifdef PORTB_AHB
#define GPIOB                                        ((volatile GPIO_Type*)(GPIOB_AHB_BASE_ADDRESS))
#else
#define GPIOB                                        ((volatile GPIO_Type*)(GPIOB_BASE_ADDRESS))
#endif
#ifdef PORTC_AHB
#define GPIOC                                        ((volatile GPIO_Type*)(GPIOC_AHB_BASE_ADDRESS))
#else
#define GPIOC                                        ((volatile GPIO_Type*)(GPIOC_BASE_ADDRESS))
#endif
#ifdef PORTD_AHB
#define GPIOD                                        ((volatile GPIO_Type*)(GPIOD_AHB_BASE_ADDRESS))
#else
#define GPIOD                                        ((volatile GPIO_Type*)(GPIOD_BASE_ADDRESS))
#endif
#ifdef PORTE_AHB
#define GPIOE                                        ((volatile GPIO_Type*)(GPIOE_AHB_BASE_ADDRESS))
#else
#define GPIOE                                        ((volatile GPIO_Type*)(GPIOE_BASE_ADDRESS))
#endif
#ifdef GPIOF_AHB
#define GPIOF                                        ((volatile GPIO_Type*)(GPIOF_AHB_BASE_ADDRESS))
#else
#define GPIOF                                        ((volatile GPIO_Type*)(GPIOF_BASE_ADDRESS))
#endif

#endif /* MCU_HARDWARE_H */

/* ================================================================================================================= */
/* ================                           END OF FILE: MCU_Hardware.h                           ================ */
/* ================================================================================================================= */
