/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
    uint32 B0  :1;
    uint32 B1  :1;
    uint32 B2  :1;
    uint32 B3  :1;
    uint32 B4  :1;
    uint32 B5  :1;
    uint32 B6  :1;
    uint32 B7  :1;
    uint32 B8  :1;
    uint32 B9  :1;
    uint32 B10 :1;
    uint32 B11 :1;
    uint32 B12 :1;
    uint32 B13 :1; 
    uint32 B14 :1; 
    uint32 B15 :1; 
    uint32 B16 :1;
    uint32 B17 :1;
    uint32 B18 :1;
    uint32 B19 :1;
    uint32 B20 :1;
    uint32 B21 :1;
    uint32 B22 :1;
    uint32 B23 :1;
    uint32 B24 :1;
    uint32 B25 :1;
    uint32 B26 :1;
    uint32 B27 :1;
    uint32 B28 :1;
    uint32 B29 :1; 
    uint32 B30 :1; 
    uint32 B31 :1; 
}BF_Type;

typedef struct
{
    uint32 EN0;
    uint32 EN1;
    uint32 EN2;
    uint32 EN3;
    uint32 EN4;
    uint32 DIS0;
    uint32 DIS1;
    uint32 DIS2;
    uint32 DIS3;
    uint32 DIS4;
    uint32 PEND0;
    uint32 PEND1;
    uint32 PEND2;
    uint32 PEND3;
    uint32 PEND4;
    uint32 UNPEND0;
    uint32 UNPEND1;
    uint32 UNPEND2;
    uint32 UNPEND3;
    uint32 UNPEND4;
    uint32 ACTIVE0;
    uint32 ACTIVE1;
    uint32 ACTIVE2;
    uint32 ACTIVE3;
    uint32 ACTIVE4;
    uint32 PRI0;
    uint32 PRI1;
    uint32 PRI2;
    uint32 PRI3;
    uint32 PRI4;
    uint32 PRI5;
    uint32 PRI6;
    uint32 PRI7;
    uint32 PRI8;
    uint32 PRI9;
    uint32 PRI10;
    uint32 PRI11;
    uint32 PRI12;
    uint32 PRI13;
    uint32 PRI14;
    uint32 PRI15;
    uint32 PRI16;
    uint32 PRI17;
    uint32 PRI18;
    uint32 PRI19;
    uint32 PRI20;
    uint32 PRI21;
    uint32 PRI22;
    uint32 PRI23;
    uint32 PRI24;
    uint32 PRI25;
    uint32 PRI26;
    uint32 PRI27;
    uint32 PRI28;
    uint32 PRI29;
    uint32 PRI30;
    uint32 PRI31;
    uint32 PRI32;
    uint32 PRI33;
    uint32 PRI34;
    uint32 SWTRIG;
}NVIC_R;
typedef union
{
    NVIC_R R;
    BF_Type B;
}NVIC_tag;

typedef struct
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef struct
{
    uint32 GPIODIR;
    uint32 GPIODIS;
    uint32 GPIOIBE;
    uint32 GPIOIEV;
    uint32 GPIOIM;
    uint32 GPIORIS;
    uint32 GPIOMIS;
    uint32 GPIOICR;
    uint32 GPIOAFSEL;
    uint32 reserved[55];
    uint32 GPIODR2R;
    uint32 GPIODR4R;
    uint32 GPIODR8R;
    uint32 GPIOODR;
    uint32 GPIOPUR;
    uint32 GPIOPDR;
    uint32 GPIOSLR;
    uint32 GPIODEN;
    uint32 GPIOLOCK;
    uint32 GPIOCR;
    uint32 GPIOAMSEL;
    uint32 GPIOPCTL;
    uint32 GPIOADCCTL;
    uint32 GPIODMACTL;
    uint32 GPIOPeriphID4;
    uint32 GPIOPeriphID5;
    uint32 GPIOPeriphID6;
    uint32 GPIOPeriphID7;
    uint32 GPIOPeriphID0;
    uint32 GPIOPeriphID1;
    uint32 GPIOPeriphID2;
    uint32 GPIOPeriphID3;
    uint32 GPIOPCellID0;
    uint32 GPIOPCellID1;
    uint32 GPIOPCellID2;
    uint32 GPIOPCellID3;
}GPIO_R;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS                     0xE000E000
#define GPIO_PORTA_BASE_ADDRESS_APB                    0x40004000
#define GPIO_PORTB_BASE_ADDRESS_APB                    0x40005000
#define GPIO_PORTC_BASE_ADDRESS_APB                    0x40006000
#define GPIO_PORTD_BASE_ADDRESS_APB                    0x40007000
#define GPIO_PORTE_BASE_ADDRESS_APB                    0x40024000
#define GPIO_PORTF_BASE_ADDRESS_APB                    0x40025000
/*NVIC Registers*/
#define NVIC_REG                                   ((volatile NVIC_tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x100)) 
/*End of NVIC Registers*/

/*SCB Registers*/
#define SCB_APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define SCB_INTCTRL                                ((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
/*End of SCB Registers*/

/*Dio Registers*/
#define GPIODATA_PORTA_APB                          ((volatile uint32*)(GPIO_PORTA_BASE_ADDRESS_APB+0x000))
#define GPIODATA_PORTB_APB                          ((volatile uint32*)(GPIO_PORTB_BASE_ADDRESS_APB+0x000))
#define GPIODATA_PORTC_APB                          ((volatile uint32*)(GPIO_PORTC_BASE_ADDRESS_APB+0x000))
#define GPIODATA_PORTD_APB                          ((volatile uint32*)(GPIO_PORTD_BASE_ADDRESS_APB+0x000))
#define GPIODATA_PORTE_APB                          ((volatile uint32*)(GPIO_PORTE_BASE_ADDRESS_APB+0x000))
#define GPIODATA_PORTF_APB                          ((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS_APB+0x000))

#define GPIOA_REG                                   ((volatile GPIO_R*)(GPIO_PORTA_BASE_ADDRESS_APB+0x400))
#define GPIOB_REG                                   ((volatile GPIO_R*)(GPIO_PORTB_BASE_ADDRESS_APB+0x400))
#define GPIOC_REG                                   ((volatile GPIO_R*)(GPIO_PORTC_BASE_ADDRESS_APB+0x400))
#define GPIOD_REG                                   ((volatile GPIO_R*)(GPIO_PORTD_BASE_ADDRESS_APB+0x400))
#define GPIOE_REG                                   ((volatile GPIO_R*)(GPIO_PORTE_BASE_ADDRESS_APB+0x400))
#define GPIOF_REG                                   ((volatile GPIO_R*)(GPIO_PORTF_BASE_ADDRESS_APB+0x400))
/*End of Dio Registers*/

/*System control Registers*/

#define RCGCGPIO                                    ((volatile BF_Type*)(0x400FE000+0x608))
#define RCGCTIMER                                   ((volatile BF_Type*)(0x400FE000+0x604))
/*End of System control Registers*/

/*General purpose timer Registers*/
typedef struct
{
    uint32 GPTMCFG;
    uint32 GPTMTAMR;
    uint32 GPTMTBMR;
    uint32 GPTMCTL;
    uint32 GPTMSYNC;
    uint32 reserved;
    uint32 GPTMIMR;
    uint32 GPTMRIS;
    uint32 GPTMMIS;
    uint32 GPTMICR;
    uint32 GPTMTAILR;
    uint32 GPTMTBILR;
    uint32 GPTMTAMATCHR;
    uint32 GPTMTBMATCHR;
    uint32 GPTMTAPR;
    uint32 GPTMTBPR;
    uint32 GPTMTAPMR;
    uint32 GPTMTBPMR;
    uint32 GPTMTAR;
    uint32 GPTMTBR;
    uint32 GPTMTAV;
    uint32 GPTMTBV;
    uint32 GPTMRTCPD;
    uint32 GPTMTAPS;
    uint32 GPTMTBPS;
    uint32 GPTMTAPV;
    uint32 GPTMTBPV;
}GPT_R;

#define GPT_BASE_ADDRESS                           0x40030000


#define GPT0_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS))
#define GPT1_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0x1000))
#define GPT2_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0x2000))
#define GPT3_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0x3000))
#define GPT4_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0x4000))
#define GPT5_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0x5000))

#define GPWT0_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0x6000))
#define GPWT1_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0x7000))
#define GPWT2_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0xC000))
#define GPWT3_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0xD000))
#define GPWT4_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0xE000))
#define GPWT5_REG                                   ((volatile GPT_R*)(GPT_BASE_ADDRESS+0xF000))
/*End of General purpose timer Registers*/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
