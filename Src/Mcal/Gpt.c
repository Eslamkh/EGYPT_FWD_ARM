/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief  General purpose timer driver.
 *
 *      \details  the driver controls all timer channels.
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpt.h"
#include "Gpt_Cfg.h"
#include "Bit_Math.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static void (*TIMER_Callback[12]) (void) ;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void TIMER0A_Handler(void)
{
		/* Clear Interrupt flag */
	SET_BIT(GPT0_REG->GPTMICR,0);
    if(TIMER_Callback[0] != NULL_PTR)
    {
        TIMER_Callback[0]();
    }
}
void TIMER0B_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT0_REG->GPTMICR,0);
    if(TIMER_Callback[0] != NULL_PTR)
    {
        TIMER_Callback[0]();
    }
}
void TIMER1A_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT1_REG->GPTMICR,0);
	if(TIMER_Callback[1] != NULL_PTR)
    {
        TIMER_Callback[1]();
    }
}
void TIMER1B_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT1_REG->GPTMICR,0);
	if(TIMER_Callback[1] != NULL_PTR)
    {
        TIMER_Callback[1]();
    }
}
void TIMER2A_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT2_REG->GPTMICR,0);
	if(TIMER_Callback[2] != NULL_PTR)
    {
        TIMER_Callback[2]();
    }
}
void TIMER2B_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT2_REG->GPTMICR,0);
	if(TIMER_Callback[2] != NULL_PTR)
    {
        TIMER_Callback[2]();
    }
}
void TIMER3A_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT3_REG->GPTMICR,0);
	if(TIMER_Callback[3] != NULL_PTR)
    {
        TIMER_Callback[3]();
    }
}
void TIMER3B_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT3_REG->GPTMICR,0);
	if(TIMER_Callback[3] != NULL_PTR)
    {
        TIMER_Callback[3]();
    }
}
void TIMER4A_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT4_REG->GPTMICR,0);
	if(TIMER_Callback[4] != NULL_PTR)
    {
        TIMER_Callback[4]();
    }
}
void TIMER4B_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT4_REG->GPTMICR,0);
	if(TIMER_Callback[4] != NULL_PTR)
    {
        TIMER_Callback[4]();
    }
}
void TIMER5A_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT5_REG->GPTMICR,0);
	if(TIMER_Callback[5] != NULL_PTR)
    {
        TIMER_Callback[5]();
    }
}
void TIMER5B_Handler(void)
{
	/* Clear Interrupt flag */
		SET_BIT(GPT5_REG->GPTMICR,0);
	if(TIMER_Callback[5] != NULL_PTR)
    {
        TIMER_Callback[5]();
    }	
}
void WTIMER0A_Handler(void)
{
	if(TIMER_Callback[6] != NULL_PTR)
    {
        TIMER_Callback[6]();
    }	
}
void WTIMER0B_Handler(void)
{
	if(TIMER_Callback[6] != NULL_PTR)
    {
        TIMER_Callback[6]();
    }
}
void WTIMER1A_Handler(void)
{
	if(TIMER_Callback[7] != NULL_PTR)
    {
        TIMER_Callback[7]();
    }
}
void WTIMER1B_Handler(void)
{
	if(TIMER_Callback[7] != NULL_PTR)
    {
        TIMER_Callback[7]();
    }
}
void WTIMER2A_Handler(void)
{
	if(TIMER_Callback[8] != NULL_PTR)
    {
        TIMER_Callback[8]();
    }
}
void WTIMER2B_Handler(void)
{
	if(TIMER_Callback[8] != NULL_PTR)
    {
        TIMER_Callback[8]();
    }
}
void WTIMER3A_Handler(void)
{
	if(TIMER_Callback[9] != NULL_PTR)
    {
        TIMER_Callback[9]();
    }
}
void WTIMER3B_Handler(void)
{
	if(TIMER_Callback[9] != NULL_PTR)
    {
        TIMER_Callback[9]();
    }
}
void WTIMER4A_Handler(void)
{
	if(TIMER_Callback[10] != NULL_PTR)
    {
        TIMER_Callback[10]();
    }
}
void WTIMER4B_Handler(void)
{
	if(TIMER_Callback[10] != NULL_PTR)
    {
        TIMER_Callback[10]();
    }
}
void WTIMER5A_Handler(void)
{
if(TIMER_Callback[11] != NULL_PTR)
    {
        TIMER_Callback[11]();
    }
}
void WTIMER5B_Handler(void)
{
if(TIMER_Callback[11] != NULL_PTR)
    {
        TIMER_Callback[11]();
    }
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
    /* Init HW timer module according to ConfigPtr configuration*/
    for(uint8 timer=0; timer<GPT_NUM_OF_ACTIVATED_CHANNELS; timer++)
    {
        switch (ConfigPtr->Gpt_ChannelId)
        {
        case GPT_TIMER_0:
            /* Ensure the timer is disabled  before making any changes */
            CLR_BIT(GPT0_REG->GPTMCTL,0);
            //CLR_BIT(GPT0_REG->GPTMCTL,8);
            /* Write the GPTM Configuration Register with 0x0 */
            GPT0_REG-> GPTMCFG = 0x0;
            /* Write Timer mode */
            GPT0_REG->GPTMTAMR = ConfigPtr->Gpt_ChannelMode;
            GPT0_REG->GPTMTBMR = ConfigPtr->Gpt_ChannelMode;
            /* Set timer to count down */
            CLR_BIT(GPT0_REG->GPTMTAMR,4);
            CLR_BIT(GPT0_REG->GPTMTBMR,4);
            /* Disable all intterrupt notification controlled by Gpt module*/
            GPT0_REG->GPTMIMR = 0x0;
						SET_BIT(GPT0_REG->GPTMICR,8);
						SET_BIT(GPT0_REG->GPTMICR,4);
						TIMER_Callback[0]=ConfigPtr->Gpt_Notification;
            break;
        
        default:
            break;
        }
    }
    

    /* Enable all enabled Gpt Predef timers at value 0*/
}
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    switch (Channel)
    {
    case GPT_TIMER_0:
        CLR_BIT(GPT0_REG->GPTMIMR,0);
        //CLR_BIT(GPT0_REG->GPTMIMR,8);
        break;
    
    default:
        break;
    }
}
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    switch (Channel)
    {
    case GPT_TIMER_0:
        SET_BIT(GPT0_REG->GPTMIMR,0);
        //SET_BIT(GPT0_REG->GPTMIMR,8);
        break;
    
    default:
        break;
    }
}
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value)
{
    switch (Channel)
    {
    case GPT_TIMER_0:
        /* Set the load register */
        GPT0_REG->GPTMTAILR = Value;
				GPT0_REG->GPTMTBILR = Value;
        /* Start the timer */
        SET_BIT(GPT0_REG->GPTMCTL,0);
        //SET_BIT(GPT0_REG->GPTMCTL,8);
        break;
    
    default:
        break;
    }
}
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    switch (Channel)
    {
    case GPT_TIMER_0:
        /* Set the load register */
        GPT0_REG->GPTMTAILR = 0x0;
        /* Start the timer */
        CLR_BIT(GPT0_REG->GPTMCTL,0);
        //CLR_BIT(GPT0_REG->GPTMCTL,8);
        break;
    
    default:
        break;
    }
}
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    Gpt_ValueType currentReading;
    Gpt_ValueType loadedValue; 
    switch (Channel)
    {
    case GPT_TIMER_0:
        currentReading = GPT0_REG->GPTMTAV;
        loadedValue = GPT0_REG->GPTMTAILR;
        break;
    
    default:
        break;
    }
    return loadedValue - currentReading;
}
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    Gpt_ValueType currentReading;
    Gpt_ValueType loadedValue; 
    switch (Channel)
    {
    case GPT_TIMER_0:
        currentReading = GPT0_REG->GPTMTAV;
        loadedValue = GPT0_REG->GPTMTAILR;
        break;
    
    default:
        break;
    }
    return currentReading;
}
Std_ReturnType  Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimerValuePtr)
{
    return E_NOT_OK;
}

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
