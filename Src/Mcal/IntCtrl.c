/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Bit_Math.h"
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define IntCtrl_RESERVERD     0                     /*Reserved Interrupt number in ENx register*/
#define IntCtrl_RESERVERD_P   000                   /*Reserved Interrupt number in PRIx register*/

#define CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b20,b21,b22,b23,b24,b25,b26,b27,b28,b29,b30,b31)	0b##b31##b30##b29##b28##b27##b26##b25##b24##b23##b22##b21##b20##b19##b18##b17##b16##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b20,b21,b22,b23,b24,b25,b26,b27,b28,b29,b30,b31)	CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16,b17,b18,b19,b20,b21,b22,b23,b24,b25,b26,b27,b28,b29,b30,b31)

    #define EN0_INITIAL  CONC(IntCtrl_GPIO_PORTD_E,IntCtrl_GPIO_PORTC_E,IntCtrl_GPIO_PORTB_E,IntCtrl_GPIO_PORTA_E,\
                             IntCtrl_GPIO_PORTE_E,IntCtrl_UART0_E,IntCtrl_UART1_E,IntCtrl_SSI0_E,\
                             IntCtrl_I2C0_E,IntCtrl_PWM0_FAULT_E,IntCtrl_PWM0_GENERATOR0_E,IntCtrl_PWM0_GENERATOR1_E,\
                             IntCtrl_PWM0_GENERATOR2_E,IntCtrl_QEI0_E,IntCtrl_ADC0_SEQUENCE0_E,IntCtrl_ADC0_SEQUENCE1_E,\
                             IntCtrl_ADC0_SEQUENCE2_E,IntCtrl_ADC0_SEQUENCE3_E,IntCtrl_WDT_0_1_E,IntCtrl_TIMER1632_0A_E,\
                             IntCtrl_TIMER1632_0B_E,IntCtrl_TIMER1632_1A_E,IntCtrl_TIMER1632_1B_E,IntCtrl_TIMER1632_2A_E,\
                             IntCtrl_TIMER1632_2B_E,IntCtrl_ANALOG_COMPERATOR0_E,IntCtrl_ANALOG_COMPERATOR1_E,IntCtrl_RESERVERD,\
                             IntCtrl_SYSTEM_CONTROL_E,IntCtrl_FLASH_EEPROM_CONTROL_E,IntCtrl_GPIO_PORTF_E,IntCtrl_RESERVERD)

    #define EN1_INITIAL  CONC(IntCtrl_RESERVERD,IntCtrl_UART2_E,IntCtrl_SSI1_E,IntCtrl_TIMER1632_3A_E,\
                            IntCtrl_TIMER1632_3B_E,IntCtrl_I2C1_E,IntCtrl_QEI1_E,IntCtrl_CAN0_E,\
                            IntCtrl_CAN1_E,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_HIBERNATION_E,\
                            IntCtrl_USB_E,IntCtrl_PWM_GENERATOR3_E,IntCtrl_UDMA_SOFTWARE_E,IntCtrl_UDMA_ERROR_E,\
                            IntCtrl_ADC1_SEQUENCE0_E,IntCtrl_ADC1_SEQUENCE1_E,IntCtrl_ADC1_SEQUENCE2_E,\
                            IntCtrl_ADC1_SEQUENCE3_E,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_SSI2_E,IntCtrl_SSI3_E,\
                            IntCtrl_UART3_E,IntCtrl_UART4_E,IntCtrl_UART5_E,IntCtrl_UART6_E,IntCtrl_UART7_E)

    #define EN2_INITIAL  CONC(IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_I2C2_E,IntCtrl_I2C3_E,IntCtrl_TIMER1632_4A_E,IntCtrl_TIMER1632_4B_E,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_TIMER1632_5A_E,\
                            IntCtrl_TIMER1632_5B_E,IntCtrl_TIMER3264_0A_E,IntCtrl_TIMER3264_0B_E,IntCtrl_TIMER3264_1A_E,\
                            IntCtrl_TIMER3264_1B_E,IntCtrl_TIMER3264_2A_E,IntCtrl_TIMER3264_2B_E)

    #define EN3_INITIAL  CONC(IntCtrl_TIMER3264_3A_E,IntCtrl_TIMER3264_3B_E,IntCtrl_TIMER3264_4A_E,IntCtrl_TIMER3264_4B_E,\
                            IntCtrl_TIMER3264_5A_E,IntCtrl_TIMER3264_5B_E,IntCtrl_SYSTEM_EXCEPTION_E,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD)
														

    #define EN4_INITIAL  CONC(IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_PWM1_GENERATOR0_E,IntCtrl_PWM1_GENERATOR1_E,\
                            IntCtrl_PWM1_GENERATOR2_E,IntCtrl_PWM1_GENERATOR3_E,IntCtrl_PWM1_FAULT_E,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,\
                            IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD,IntCtrl_RESERVERD)

		/*
		#define CONC_HELPERB(b0,b01,b02,b1,b11,b12,b2,b21,b22,b3,b31,b32)	0b##b3##b31##b32##b2##b21##b22##b1##b11##b12##b0###b01##b02
    #define CONCB(b0,b01,b02,b1,b11,b12,b2,b21,b22,b3,b31,b32) CONC_HELPERB(b0,b01,b02,b1,b11,b12,b2,b21,b22,b3,b31,b32)

    #define PRI0_INITIAL   CONCB(IntCtrl_GPIO_PORTA_SG2,IntCtrl_GPIO_PORTA_SG1,IntCtrl_GPIO_PORTA_SG0,IntCtrl_GPIO_PORTB_SG2,IntCtrl_GPIO_PORTB_SG1,IntCtrl_GPIO_PORTB_SG0,IntCtrl_GPIO_PORTC_SG2,IntCtrl_GPIO_PORTC_SG1,IntCtrl_GPIO_PORTC_SG0,IntCtrl_GPIO_PORTD_SG2,IntCtrl_GPIO_PORTD_SG1,IntCtrl_GPIO_PORTD_SG0)
    #define PRI1_INITIAL   CONCB(IntCtrl_GPIO_PORTE_G_SG2,IntCtrl_GPIO_PORTE_G_SG1,IntCtrl_GPIO_PORTE_G_SG0,IntCtrl_UART0_G_SG2,IntCtrl_UART0_G_SG1,IntCtrl_UART0_G_SG0,IntCtrl_UART1_G_SG2,IntCtrl_UART1_G_SG1,IntCtrl_UART1_G_SG0,IntCtrl_SSI0_G_SG2,IntCtrl_SSI0_G_SG1,IntCtrl_SSI0_G_SG0)
    #define PRI2_INITIAL   CONCB(IntCtrl_I2C0_G_SG2,IntCtrl_I2C0_G_SG1,IntCtrl_I2C0_G_SG0,IntCtrl_PWM0_FAULT_G_SG2,IntCtrl_PWM0_FAULT_G_SG1,IntCtrl_PWM0_FAULT_G_SG0,IntCtrl_PWM0_GENERATOR0_G_SG2,IntCtrl_PWM0_GENERATOR0_G_SG1,IntCtrl_PWM0_GENERATOR0_G_SG0,IntCtrl_PWM0_GENERATOR1_G_SG2,IntCtrl_PWM0_GENERATOR1_G_SG1,IntCtrl_PWM0_GENERATOR1_G_SG0)
    #define PRI3_INITIAL   CONCB(IntCtrl_PWM0_GENERATOR2_G_SG2,IntCtrl_PWM0_GENERATOR2_G_SG1,IntCtrl_PWM0_GENERATOR2_G_SG0,IntCtrl_QEI0_G_SG2,IntCtrl_QEI0_G_SG1,IntCtrl_QEI0_G_SG0,IntCtrl_ADC0_SEQUENCE0_G_SG2,IntCtrl_ADC0_SEQUENCE0_G_SG1.IntCtrl_ADC0_SEQUENCE0_G_SG0,IntCtrl_ADC0_SEQUENCE1_G_SG2,IntCtrl_ADC0_SEQUENCE1_G_SG1,IntCtrl_ADC0_SEQUENCE1_G_SG0)
    #define PRI4_INITIAL   CONCB(IntCtrl_ADC0_SEQUENCE2_G_SG2,IntCtrl_ADC0_SEQUENCE2_G_SG1,IntCtrl_ADC0_SEQUENCE2_G_SG0,IntCtrl_ADC0_SEQUENCE3_G_SG2,IntCtrl_ADC0_SEQUENCE3_G_SG1,IntCtrl_ADC0_SEQUENCE3_G_SG0,IntCtrl_WDT_0_1_G_SG2,IntCtrl_WDT_0_1_G_SG1,IntCtrl_WDT_0_1_G_SG0,IntCtrl_TIMER1632_0A_G_SG2,IntCtrl_TIMER1632_0A_G_SG1,IntCtrl_TIMER1632_0A_G_SG0)
    
    #define PRI5_INITIAL   CONCB(IntCtrl_TIMER1632_0B_G_SG,IntCtrl_TIMER1632_1A_G_SG,IntCtrl_TIMER1632_1B_G_SG,IntCtrl_TIMER1632_2A_G_SG)
    #define PRI6_INITIAL   CONCB(IntCtrl_TIMER1632_2B_G_SG,IntCtrl_ANALOG_COMPERATOR0_G_SG,IntCtrl_ANALOG_COMPERATOR1_G_SG,IntCtrl_RESERVERD_P)
    #define PRI7_INITIAL   CONCB(IntCtrl_SYSTEM_CONTROL_G_SG,IntCtrl_FLASH_EEPROM_CONTROL_G_SG,IntCtrl_GPIO_PORTF_G_SG,IntCtrl_RESERVERD_P)
    #define PRI8_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_UART2_G_SG,IntCtrl_SSI1_G_SG,IntCtrl_TIMER1632_3A_G_SG)
    #define PRI9_INITIAL   CONCB(IntCtrl_TIMER1632_3B_G_SG,IntCtrl_I2C1_G_SG,IntCtrl_QEI1_G_SG,IntCtrl_CAN0_G_SG)
    
    #define PRI10_INITIAL   CONCB(IntCtrl_CAN1_G_SG,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_HIBERNATION_G_SG)
    #define PRI11_INITIAL   CONCB(IntCtrl_USB_G_SG,IntCtrl_PWM_GENERATOR3_G_SG,IntCtrl_UDMA_SOFTWARE_G_SG,IntCtrl_UDMA_ERROR_G_SG)
    #define PRI12_INITIAL   CONCB(IntCtrl_ADC1_SEQUENCE0_G_SG,IntCtrl_ADC1_SEQUENCE1_G_SG,IntCtrl_ADC1_SEQUENCE2_G_SG,IntCtrl_ADC1_SEQUENCE3_G_SG)
    #define PRI13_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI14_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_SSI2_G_SG,IntCtrl_SSI3_G_SG,IntCtrl_UART3_G_SG)

    #define PRI15_INITIAL   CONCB(IntCtrl_UART4_G_SG,IntCtrl_UART5_G_SG,IntCtrl_UART6_G_SG,IntCtrl_UART7_G_SG)
    #define PRI16_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI17_INITIAL   CONCB(IntCtrl_I2C2_G_SG,IntCtrl_I2C3_G_SG,IntCtrl_TIMER1632_4A_G_SG,IntCtrl_TIMER1632_4B_G_SG)
    #define PRI18_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI19_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)

    #define PRI20_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI21_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI22_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI23_INITIAL   CONCB(IntCtrl_TIMER1632_5A_G_SG,IntCtrl_TIMER1632_5B_G_SG,IntCtrl_TIMER3264_0A_G_SG,IntCtrl_TIMER3264_0B_G_SG)
    #define PRI24_INITIAL   CONCB(IntCtrl_TIMER3264_1A_G_SG,IntCtrl_TIMER3264_1B_G_SG,IntCtrl_TIMER3264_2A_G_SG,IntCtrl_TIMER3264_2B_G_SG)

    #define PRI25_INITIAL   CONCB(IntCtrl_TIMER3264_3A_G_SG,IntCtrl_TIMER3264_3B_G_SG,IntCtrl_TIMER3264_4A_G_SG,IntCtrl_TIMER3264_4B_G_SG)
    #define PRI26_INITIAL   CONCB(IntCtrl_TIMER3264_5A_G_SG,IntCtrl_TIMER3264_5B_G_SG,IntCtrl_SYSTEM_EXCEPTION_G_SG,IntCtrl_RESERVERD_P)
    #define PRI27_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI28_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI29_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)

    #define PRI30_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI31_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI32_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P)
    #define PRI33_INITIAL   CONCB(IntCtrl_RESERVERD_P,IntCtrl_RESERVERD_P,IntCtrl_PWM1_GENERATOR0_G_SG,IntCtrl_PWM1_GENERATOR1_G_SG)
    #define PRI34_INITIAL   CONCB(IntCtrl_PWM1_GENERATOR2_G_SG,IntCtrl_PWM1_GENERATOR3_G_SG,IntCtrl_PWM1_FAULT_G_SG,IntCtrl_RESERVERD_P)
    */

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    SCB_APINT = IntCtrl_G_S_SELECT;
    
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
	
  NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTA_G_SG0<<24;
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTA_G_SG1<<25;
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTA_G_SG2<<26;
	
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTB_G_SG0<<16;
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTB_G_SG1<<17;
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTB_G_SG2<<18;
	
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTC_G_SG0<<8;
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTC_G_SG1<<9;
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTC_G_SG2<<10;
	
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTD_G_SG0<<0;
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTD_G_SG1<<1;
	NVIC_REG->R.PRI0 |= IntCtrl_GPIO_PORTD_G_SG2<<2;
	
	

	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
    NVIC_REG ->R.EN0 = EN0_INITIAL;
    NVIC_REG ->R.EN1 = EN1_INITIAL;
    NVIC_REG ->R.EN2 = EN2_INITIAL;
    NVIC_REG ->R.EN3 = EN3_INITIAL;
    NVIC_REG ->R.EN4 = EN4_INITIAL;

	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
