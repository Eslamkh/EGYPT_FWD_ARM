/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  IntCtrl
 *
 *  Description:  Interrupts configuration      
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define IntCtrl_G_S_SELECT        IntCtrl_G1_S2
/* Options */
/*
 IntCtrl_G3_S0  
 IntCtrl_G2_S1 
 IntCtrl_G1_S2  
 IntCtrl_G0_S3  
*/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
    #define IntCtrl_GPIO_PORTA_E                 0
    #define IntCtrl_GPIO_PORTA_G_SG0             0
    #define IntCtrl_GPIO_PORTA_G_SG1             0
    #define IntCtrl_GPIO_PORTA_G_SG2             0

    #define IntCtrl_GPIO_PORTB_E                 0
    #define IntCtrl_GPIO_PORTB_G_SG0             0
    #define IntCtrl_GPIO_PORTB_G_SG1             0
    #define IntCtrl_GPIO_PORTB_G_SG2             0

    #define IntCtrl_GPIO_PORTC_E                0
    #define IntCtrl_GPIO_PORTC_G_SG0             0
    #define IntCtrl_GPIO_PORTC_G_SG1             0
    #define IntCtrl_GPIO_PORTC_G_SG2             0

    #define IntCtrl_GPIO_PORTD_E                0
    #define IntCtrl_GPIO_PORTD_G_SG0             0
    #define IntCtrl_GPIO_PORTD_G_SG1             0
    #define IntCtrl_GPIO_PORTD_G_SG2             0

    #define IntCtrl_GPIO_PORTE_E                0
    #define IntCtrl_GPIO_PORTE_G_SG0             0
    #define IntCtrl_GPIO_PORTE_G_SG1             0
    #define IntCtrl_GPIO_PORTE_G_SG2             0

    #define IntCtrl_UART0_E                     0
    #define IntCtrl_UART0_G_SG0                  0
    #define IntCtrl_UART0_G_SG1                  0
    #define IntCtrl_UART0_G_SG2                  0

    #define IntCtrl_UART1_E                     0
    #define IntCtrl_UART1_G_SG0                  0
    #define IntCtrl_UART1_G_SG1                  0
    #define IntCtrl_UART1_G_SG2                  0

    #define IntCtrl_SSI0_E                      0
    #define IntCtrl_SSI0_G_SG0                   0
    #define IntCtrl_SSI0_G_SG1                   0
    #define IntCtrl_SSI0_G_SG2                   0

    #define IntCtrl_I2C0_E                      0
    #define IntCtrl_I2C0_G_SG0                   0
    #define IntCtrl_I2C0_G_SG1                   0
    #define IntCtrl_I2C0_G_SG2                   0

    #define IntCtrl_PWM0_FAULT_E                0
    #define IntCtrl_PWM0_FAULT_G_SG0             0
    #define IntCtrl_PWM0_FAULT_G_SG1             0
    #define IntCtrl_PWM0_FAULT_G_SG2             0

    #define IntCtrl_PWM0_GENERATOR0_E           0
    #define IntCtrl_PWM0_GENERATOR0_G_SG0        0
    #define IntCtrl_PWM0_GENERATOR0_G_SG1        0
    #define IntCtrl_PWM0_GENERATOR0_G_SG2        0

    #define IntCtrl_PWM0_GENERATOR1_E           0
    #define IntCtrl_PWM0_GENERATOR1_G_SG0        0
    #define IntCtrl_PWM0_GENERATOR1_G_SG1        0
    #define IntCtrl_PWM0_GENERATOR1_G_SG2        0

    #define IntCtrl_PWM0_GENERATOR2_E           0
    #define IntCtrl_PWM0_GENERATOR2_G_SG0        0
    #define IntCtrl_PWM0_GENERATOR2_G_SG1        0
    #define IntCtrl_PWM0_GENERATOR2_G_SG2        0

    #define IntCtrl_QEI0_E                      0
    #define IntCtrl_QEI0_G_SG0                   0
    #define IntCtrl_QEI0_G_SG1                   0
    #define IntCtrl_QEI0_G_SG2                   0

    #define IntCtrl_ADC0_SEQUENCE0_E            0
    #define IntCtrl_ADC0_SEQUENCE0_G_SG0         0
    #define IntCtrl_ADC0_SEQUENCE0_G_SG1         0
    #define IntCtrl_ADC0_SEQUENCE0_G_SG2         0

    #define IntCtrl_ADC0_SEQUENCE1_E            0
    #define IntCtrl_ADC0_SEQUENCE1_G_SG0         0
    #define IntCtrl_ADC0_SEQUENCE1_G_SG1         0
    #define IntCtrl_ADC0_SEQUENCE1_G_SG2         0

    #define IntCtrl_ADC0_SEQUENCE2_E            0
    #define IntCtrl_ADC0_SEQUENCE2_G_SG0         0
    #define IntCtrl_ADC0_SEQUENCE2_G_SG1         0
    #define IntCtrl_ADC0_SEQUENCE2_G_SG2         0

    #define IntCtrl_ADC0_SEQUENCE3_E            0
    #define IntCtrl_ADC0_SEQUENCE3_G_SG0         0
    #define IntCtrl_ADC0_SEQUENCE3_G_SG1         0
    #define IntCtrl_ADC0_SEQUENCE3_G_SG2         0

    #define IntCtrl_WDT_0_1_E                   0
    #define IntCtrl_WDT_0_1_G_SG0                0
    #define IntCtrl_WDT_0_1_G_SG1                0
    #define IntCtrl_WDT_0_1_G_SG2                0

    #define IntCtrl_TIMER1632_0A_E              1
    #define IntCtrl_TIMER1632_0A_G_SG0           0
    #define IntCtrl_TIMER1632_0A_G_SG1           0
    #define IntCtrl_TIMER1632_0A_G_SG2           0

    #define IntCtrl_TIMER1632_0B_E              1
    #define IntCtrl_TIMER1632_0B_G_SG0           0
    #define IntCtrl_TIMER1632_0B_G_SG1           0
    #define IntCtrl_TIMER1632_0B_G_SG2           0

    #define IntCtrl_TIMER1632_1A_E              0
    #define IntCtrl_TIMER1632_1A_G_SG0           0
    #define IntCtrl_TIMER1632_1A_G_SG1           0
    #define IntCtrl_TIMER1632_1A_G_SG2           0

    #define IntCtrl_TIMER1632_1B_E              0
    #define IntCtrl_TIMER1632_1B_G_SG0           0
    #define IntCtrl_TIMER1632_1B_G_SG1           0
    #define IntCtrl_TIMER1632_1B_G_SG2           0

    #define IntCtrl_TIMER1632_2A_E              0
    #define IntCtrl_TIMER1632_2A_G_SG0           0
    #define IntCtrl_TIMER1632_2A_G_SG1           0
    #define IntCtrl_TIMER1632_2A_G_SG2           0

    #define IntCtrl_TIMER1632_2B_E              0
    #define IntCtrl_TIMER1632_2B_G_SG0           0
    #define IntCtrl_TIMER1632_2B_G_SG1           0
    #define IntCtrl_TIMER1632_2B_G_SG2           0

    #define IntCtrl_ANALOG_COMPERATOR0_E        0
    #define IntCtrl_ANALOG_COMPERATOR0_G_SG0     0
    #define IntCtrl_ANALOG_COMPERATOR0_G_SG1     0
    #define IntCtrl_ANALOG_COMPERATOR0_G_SG2     0

    #define IntCtrl_ANALOG_COMPERATOR1_E        0
    #define IntCtrl_ANALOG_COMPERATOR1_G_SG0     0
    #define IntCtrl_ANALOG_COMPERATOR1_G_SG1    0
    #define IntCtrl_ANALOG_COMPERATOR1_G_SG2     0

    #define IntCtrl_SYSTEM_CONTROL_E            0
    #define IntCtrl_SYSTEM_CONTROL_G_SG0         0
    #define IntCtrl_SYSTEM_CONTROL_G_SG1         0
    #define IntCtrl_SYSTEM_CONTROL_G_SG2         0

    #define IntCtrl_FLASH_EEPROM_CONTROL_E      0
    #define IntCtrl_FLASH_EEPROM_CONTROL_G_SG0   0
    #define IntCtrl_FLASH_EEPROM_CONTROL_G_SG1   0
    #define IntCtrl_FLASH_EEPROM_CONTROL_G_SG2   0

    #define IntCtrl_GPIO_PORTF_E                0
    #define IntCtrl_GPIO_PORTF_G_SG0             0
    #define IntCtrl_GPIO_PORTF_G_SG1             0
    #define IntCtrl_GPIO_PORTF_G_SG2             0

    #define IntCtrl_UART2_E                     0
    #define IntCtrl_UART2_G_SG0                  0
    #define IntCtrl_UART2_G_SG1                  0
    #define IntCtrl_UART2_G_SG2                  0

    #define IntCtrl_SSI1_E                      0
    #define IntCtrl_SSI1_G_SG0                   0
    #define IntCtrl_SSI1_G_SG1                   0
    #define IntCtrl_SSI1_G_SG2                   0

    #define IntCtrl_TIMER1632_3A_E              0
    #define IntCtrl_TIMER1632_3A_G_SG0           0
    #define IntCtrl_TIMER1632_3A_G_SG1           0
    #define IntCtrl_TIMER1632_3A_G_SG2           0

    #define IntCtrl_TIMER1632_3B_E              0
    #define IntCtrl_TIMER1632_3B_G_SG0           0
    #define IntCtrl_TIMER1632_3B_G_SG1           0
    #define IntCtrl_TIMER1632_3B_G_SG2           0

    #define IntCtrl_I2C1_E                      0
    #define IntCtrl_I2C1_G_SG0                   0
    #define IntCtrl_I2C1_G_SG1                   0
    #define IntCtrl_I2C1_G_SG2                   0

    #define IntCtrl_QEI1_E                      0
    #define IntCtrl_QEI1_G_SG0                   0
    #define IntCtrl_QEI1_G_SG1                   0
    #define IntCtrl_QEI1_G_SG2                   0

    #define IntCtrl_CAN0_E                      0
    #define IntCtrl_CAN0_G_SG0                   0
    #define IntCtrl_CAN0_G_SG1                   0
    #define IntCtrl_CAN0_G_SG2                   0

    #define IntCtrl_CAN1_E                      0
    #define IntCtrl_CAN1_G_SG0                   0
    #define IntCtrl_CAN1_G_SG1                  0
    #define IntCtrl_CAN1_G_SG2                   0

    #define IntCtrl_HIBERNATION_E               0
    #define IntCtrl_HIBERNATION_G_SG0            0
    #define IntCtrl_HIBERNATION_G_SG1            0
    #define IntCtrl_HIBERNATION_G_SG2            0

    #define IntCtrl_USB_E               0
    #define IntCtrl_USB_G_SG0            0
    #define IntCtrl_USB_G_SG1            0
    #define IntCtrl_USB_G_SG2            0

    #define IntCtrl_PWM_GENERATOR3_E            0
    #define IntCtrl_PWM_GENERATOR3_G_SG0         0
    #define IntCtrl_PWM_GENERATOR3_G_SG1         0
    #define IntCtrl_PWM_GENERATOR3_G_SG2         0

    #define IntCtrl_UDMA_SOFTWARE_E             0
    #define IntCtrl_UDMA_SOFTWARE_G_SG0          0
    #define IntCtrl_UDMA_SOFTWARE_G_SG1          0
    #define IntCtrl_UDMA_SOFTWARE_G_SG2          0

    #define IntCtrl_UDMA_ERROR_E                0
    #define IntCtrl_UDMA_ERROR_G_SG0             0
    #define IntCtrl_UDMA_ERROR_G_SG1             0
    #define IntCtrl_UDMA_ERROR_G_SG2             0

    #define IntCtrl_ADC1_SEQUENCE0_E            0
    #define IntCtrl_ADC1_SEQUENCE0_G_SG0         0
    #define IntCtrl_ADC1_SEQUENCE0_G_SG1         0
    #define IntCtrl_ADC1_SEQUENCE0_G_SG2         0

    #define IntCtrl_ADC1_SEQUENCE1_E            0
    #define IntCtrl_ADC1_SEQUENCE1_G_SG0         0
    #define IntCtrl_ADC1_SEQUENCE1_G_SG1         0
    #define IntCtrl_ADC1_SEQUENCE1_G_SG2         0

    #define IntCtrl_ADC1_SEQUENCE2_E            0
    #define IntCtrl_ADC1_SEQUENCE2_G_SG0         0
    #define IntCtrl_ADC1_SEQUENCE2_G_SG1         0
    #define IntCtrl_ADC1_SEQUENCE2_G_SG2         0

    #define IntCtrl_ADC1_SEQUENCE3_E            0
    #define IntCtrl_ADC1_SEQUENCE3_G_SG0         0
    #define IntCtrl_ADC1_SEQUENCE3_G_SG1         0
    #define IntCtrl_ADC1_SEQUENCE3_G_SG2         0

    #define IntCtrl_SSI2_E                      0
    #define IntCtrl_SSI2_G_SG0                   0
    #define IntCtrl_SSI2_G_SG1                   0
    #define IntCtrl_SSI2_G_SG2                   0

    #define IntCtrl_SSI3_E                      0
    #define IntCtrl_SSI3_G_SG0                   0
    #define IntCtrl_SSI3_G_SG1                   0
    #define IntCtrl_SSI3_G_SG2                   0

    #define IntCtrl_UART3_E                     0
    #define IntCtrl_UART3_G_SG0                  0
    #define IntCtrl_UART3_G_SG1                  0
    #define IntCtrl_UART3_G_SG2                  0

    #define IntCtrl_UART4_E                     0
    #define IntCtrl_UART4_G_SG0                  0
    #define IntCtrl_UART4_G_SG1                  0
    #define IntCtrl_UART4_G_SG2                  0

    #define IntCtrl_UART5_E                     0
    #define IntCtrl_UART5_G_SG0                  0
    #define IntCtrl_UART5_G_SG1                  0
    #define IntCtrl_UART5_G_SG2                  0

    #define IntCtrl_UART6_E                     0
    #define IntCtrl_UART6_G_SG0                  0
    #define IntCtrl_UART6_G_SG1                  0
    #define IntCtrl_UART6_G_SG2                  0

    #define IntCtrl_UART7_E                     0
    #define IntCtrl_UART7_G_SG0                  0
    #define IntCtrl_UART7_G_SG1                  0
    #define IntCtrl_UART7_G_SG2                  0
    
    #define IntCtrl_I2C2_E                      0
    #define IntCtrl_I2C2_G_SG0                   0
    #define IntCtrl_I2C2_G_SG1                   0
    #define IntCtrl_I2C2_G_SG2                   0

    #define IntCtrl_I2C3_E                      0
    #define IntCtrl_I2C3_G_SG0                   0
    #define IntCtrl_I2C3_G_SG1                   0
    #define IntCtrl_I2C3_G_SG2                   0

    #define IntCtrl_TIMER1632_4A_E              0
    #define IntCtrl_TIMER1632_4A_G_SG0           0
    #define IntCtrl_TIMER1632_4A_G_SG1           0
    #define IntCtrl_TIMER1632_4A_G_SG2           0

    #define IntCtrl_TIMER1632_4B_E              0
    #define IntCtrl_TIMER1632_4B_G_SG0           0
    #define IntCtrl_TIMER1632_4B_G_SG1           0
    #define IntCtrl_TIMER1632_4B_G_SG2           0

    #define IntCtrl_TIMER1632_5A_E              0
    #define IntCtrl_TIMER1632_5A_G_SG0           0
    #define IntCtrl_TIMER1632_5A_G_SG1           0
    #define IntCtrl_TIMER1632_5A_G_SG2           0

    #define IntCtrl_TIMER1632_5B_E              0
    #define IntCtrl_TIMER1632_5B_G_SG0           0
    #define IntCtrl_TIMER1632_5B_G_SG1           0
    #define IntCtrl_TIMER1632_5B_G_SG2           0

    #define IntCtrl_TIMER3264_0A_E              0
    #define IntCtrl_TIMER3264_0A_G_SG0           0
    #define IntCtrl_TIMER3264_0A_G_SG1           0
    #define IntCtrl_TIMER3264_0A_G_SG2           0

    #define IntCtrl_TIMER3264_0B_E              0
    #define IntCtrl_TIMER3264_0B_G_SG0           0
    #define IntCtrl_TIMER3264_0B_G_SG1           0
    #define IntCtrl_TIMER3264_0B_G_SG2           0

    #define IntCtrl_TIMER3264_1A_E              0
    #define IntCtrl_TIMER3264_1A_G_SG0           0
    #define IntCtrl_TIMER3264_1A_G_SG1           0
    #define IntCtrl_TIMER3264_1A_G_SG2           0

    #define IntCtrl_TIMER3264_1B_E              0
    #define IntCtrl_TIMER3264_1B_G_SG0           0
    #define IntCtrl_TIMER3264_1B_G_SG1           0
    #define IntCtrl_TIMER3264_1B_G_SG2           0

    #define IntCtrl_TIMER3264_2A_E              0
    #define IntCtrl_TIMER3264_2A_G_SG0           0
    #define IntCtrl_TIMER3264_2A_G_SG1           0
    #define IntCtrl_TIMER3264_2A_G_SG2           0

    #define IntCtrl_TIMER3264_2B_E              0
    #define IntCtrl_TIMER3264_2B_G_SG0           0
    #define IntCtrl_TIMER3264_2B_G_SG1           0
    #define IntCtrl_TIMER3264_2B_G_SG2           0

    #define IntCtrl_TIMER3264_3A_E              0
    #define IntCtrl_TIMER3264_3A_G_SG0           0
    #define IntCtrl_TIMER3264_3A_G_SG1           0
    #define IntCtrl_TIMER3264_3A_G_SG2           0

    #define IntCtrl_TIMER3264_3B_E              0
    #define IntCtrl_TIMER3264_3B_G_SG0           0
    #define IntCtrl_TIMER3264_3B_G_SG1           0
    #define IntCtrl_TIMER3264_3B_G_SG2           0

    #define IntCtrl_TIMER3264_4A_E              0
    #define IntCtrl_TIMER3264_4A_G_SG0           0
    #define IntCtrl_TIMER3264_4A_G_SG1           0
    #define IntCtrl_TIMER3264_4A_G_SG2           0

    #define IntCtrl_TIMER3264_4B_E              0
    #define IntCtrl_TIMER3264_4B_G_SG0           0
    #define IntCtrl_TIMER3264_4B_G_SG1           0
    #define IntCtrl_TIMER3264_4B_G_SG2           0

    #define IntCtrl_TIMER3264_5A_E              0
    #define IntCtrl_TIMER3264_5A_G_SG0           0
    #define IntCtrl_TIMER3264_5A_G_SG1           0
    #define IntCtrl_TIMER3264_5A_G_SG2           0

    #define IntCtrl_TIMER3264_5B_E              0
    #define IntCtrl_TIMER3264_5B_G_SG0           0
    #define IntCtrl_TIMER3264_5B_G_SG1           0
    #define IntCtrl_TIMER3264_5B_G_SG2           0

    #define IntCtrl_SYSTEM_EXCEPTION_E          0
    #define IntCtrl_SYSTEM_EXCEPTION_G_SG0       0
    #define IntCtrl_SYSTEM_EXCEPTION_G_SG1       0
    #define IntCtrl_SYSTEM_EXCEPTION_G_SG2       0

    #define IntCtrl_PWM1_GENERATOR0_E           0
    #define IntCtrl_PWM1_GENERATOR0_G_SG0        0
    #define IntCtrl_PWM1_GENERATOR0_G_SG1        0
    #define IntCtrl_PWM1_GENERATOR0_G_SG2        0

    #define IntCtrl_PWM1_GENERATOR1_E           0
    #define IntCtrl_PWM1_GENERATOR1_G_SG0        0
    #define IntCtrl_PWM1_GENERATOR1_G_SG1        0
    #define IntCtrl_PWM1_GENERATOR1_G_SG2        0

    #define IntCtrl_PWM1_GENERATOR2_E           0
    #define IntCtrl_PWM1_GENERATOR2_G_SG0        0
    #define IntCtrl_PWM1_GENERATOR2_G_SG1        0
    #define IntCtrl_PWM1_GENERATOR2_G_SG2        0

    #define IntCtrl_PWM1_GENERATOR3_E           0
    #define IntCtrl_PWM1_GENERATOR3_G_SG0        0
    #define IntCtrl_PWM1_GENERATOR3_G_SG1        0
    #define IntCtrl_PWM1_GENERATOR3_G_SG2        0

    #define IntCtrl_PWM1_FAULT_E                0
    #define IntCtrl_PWM1_FAULT_G_SG0             0
    #define IntCtrl_PWM1_FAULT_G_SG1             0
    #define IntCtrl_PWM1_FAULT_G_SG2             0
    

#endif
/***#define *************************************************************************************************************
 *  #define  FILE: IntCtrl_Cfg.h
 ***#define ************************************************************************************************************/
