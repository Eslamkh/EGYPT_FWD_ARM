/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define IntCtrl_G3_S0                   0xFA050400                   
#define IntCtrl_G2_S1                   0xFA050500   
#define IntCtrl_G1_S2                   0xFA050600     
#define IntCtrl_G0_S3                   0xFA050700 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    IntCtrl_Reset =1,
    IntCtrl_NMI,
    IntCtrl_HARD_FAULT,
    IntCtrl_MEMORY_MANAGEMENT_FAULT,
    IntCtrl_BUS_FAULT,
    IntCtrl_USAGE_FAULT,
    IntCtrl_SVCALL = 11,
    IntCtrl_PENDSV = 14,
    IntCtrl_SYSTICK = 15,
    IntCtrl_GPIO_PORTA,
    IntCtrl_GPIO_PORTB,
    IntCtrl_GPIO_PORTC,
    IntCtrl_GPIO_PORTD,
    IntCtrl_GPIO_PORTE,
    IntCtrl_UART0,
    IntCtrl_UART1,
    IntCtrl_SSI0,
    IntCtrl_I2C0,
    IntCtrl_PWM0_FAULT,
    IntCtrl_PWM0_GENERATOR0,
    IntCtrl_PWM0_GENERATOR1,
    IntCtrl_PWM0_GENERATOR2,
    IntCtrl_QEI0,
    IntCtrl_ADC0_SEQUENCE0,
    IntCtrl_ADC0_SEQUENCE1,
    IntCtrl_ADC0_SEQUENCE2,
    IntCtrl_ADC0_SEQUENCE3,
    IntCtrl_WDT_0_1,
    IntCtrl_TIMER1632_0A,
    IntCtrl_TIMER1632_0B,
    IntCtrl_TIMER1632_1A,
    IntCtrl_TIMER1632_1B,
    IntCtrl_TIMER1632_2A,
    IntCtrl_TIMER1632_2B,
    IntCtrl_ANALOG_COMPERATOR0,
    IntCtrl_ANALOG_COMPERATOR1,
    IntCtrl_SYSTEM_CONTROL = 44,
    IntCtrl_FLASH_EEPROM_CONTROL,
    IntCtrl_GPIO_PORTF,
    IntCtrl_UART2 = 49,
    IntCtrl_SSI1,
    IntCtrl_TIMER1632_3A,
    IntCtrl_TIMER1632_3B,
    IntCtrl_I2C1,
    IntCtrl_QEI1,
    IntCtrl_CAN0,
    IntCtrl_CAN1,
    IntCtrl_HIBERNATION = 59,
    IntCtrl_PWM_GENERATOR3,
    IntCtrl_UDMA_SOFTWARE,
    IntCtrl_UDMA_ERROR,
    IntCtrl_ADC1_SEQUENCE0,
    IntCtrl_ADC1_SEQUENCE1,
    IntCtrl_ADC1_SEQUENCE2,
    IntCtrl_ADC1_SEQUENCE3,
    IntCtrl_SSI2 = 73,
    IntCtrl_SSI3,
    IntCtrl_UART3,
    IntCtrl_UART4,
    IntCtrl_UART5,
    IntCtrl_UART6,
    IntCtrl_UART7,
    IntCtrl_I2C2 = 84,
    IntCtrl_I2C3,
    IntCtrl_TIMER1632_4A,
    IntCtrl_TIMER1632_4B,
    IntCtrl_TIMER1632_5A = 108,
    IntCtrl_TIMER1632_5B,
    IntCtrl_TIMER3264_0A,
    IntCtrl_TIMER3264_0B,
    IntCtrl_TIMER3264_1A,
    IntCtrl_TIMER3264_1B,
    IntCtrl_TIMER3264_2A,
    IntCtrl_TIMER3264_2B,
    IntCtrl_TIMER3264_3A,
    IntCtrl_TIMER3264_3B,
    IntCtrl_TIMER3264_4A,
    IntCtrl_TIMER3264_4B,
    IntCtrl_TIMER3264_5A,
    IntCtrl_TIMER3264_5B,
    IntCtrl_SYSTEM_EXCEPTION,
    IntCtrl_PWM1_GENERATOR0 = 150,
    IntCtrl_PWM1_GENERATOR1,
    IntCtrl_PWM1_GENERATOR2,
    IntCtrl_PWM1_GENERATOR3,
    IntCtrl_PWM1_FAULT
}IntCtrl_InterruptType;

typedef struct
{
    uint8 peripheralGate;
    uint8 groupPriority;
    uint8 subGroupPriority;
}IntCtrl_Config;
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
