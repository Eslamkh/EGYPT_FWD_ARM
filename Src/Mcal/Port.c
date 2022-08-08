/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  Port driver.
 *
 *      \details  the driver initializea all Digital input outputs channels with configuration.
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"
#include "Port_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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
void Port_Init (const Port_ConfigType* ptrConfig)
{
    uint8 portId;
    uint8 channelId;
    uint8 addressMask;
    for(uint8 pin=0 ; pin<PORT_NUM_OF_ACTIVATED_CHANNELS ; pin++)
    {
        portId = (ptrConfig[pin].PortChannelId)/8;
        switch (portId)
        {
        case Port_PortA:
            /* get the value of cahnnelId*/
            channelId = ptrConfig[pin].PortChannelId;
            /* determine address mask */
            addressMask = 0x01<<channelId;
						/* Ulock Lock register*/
						GPIOA_REG->GPIOLOCK = 0x4C4F434B;
						/* Set the corresponding bit in commit register*/
						SET_BIT(GPIOA_REG->GPIOCR,channelId);
            /* handle pin direction */
            if(PORT_PIN_DIRECTION_OUTPUT == ptrConfig[pin].PortPinDirection)
            {
                SET_BIT(GPIOA_REG->GPIODIR,channelId);
            }
            else
            {
                /* default value is input*/
                /* handle Internal attach value*/
                switch (ptrConfig[pin].PortPinInternalAttach)
                {
                case PORT_PIN_ATTACH_OPEN_DDRAIN:
                    SET_BIT(GPIOA_REG->GPIOODR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_DOWN:
                    SET_BIT(GPIOA_REG->GPIOPDR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_UP:
                    SET_BIT(GPIOA_REG->GPIOPUR,channelId);
                    break;
                
                default:
                    break;
                }
            }
						/* handle pin mode value*/
            if(PORT_MODE_CHANNEL_DIO != ptrConfig[pin].PortPinMode)
            {
                SET_BIT(GPIOA_REG->GPIOAFSEL,channelId);
                GPIOA_REG->GPIOPCTL |= (ptrConfig[pin].PortPinMode<<(channelId*4));
            }
						else
						{
							SET_BIT(GPIOA_REG->GPIODEN,channelId);
						}
						 /* handle output current value*/
            switch (ptrConfig[pin].PortPinOutputCurrent)
            {
            case PORT_PIN_CURRENT_2:
                SET_BIT(GPIOA_REG->GPIODR2R,channelId);
								break;
            case PORT_PIN_CURRENT_4:
                SET_BIT(GPIOA_REG->GPIODR4R,channelId);
								break;
            case PORT_PIN_CURRENT_8:
                SET_BIT(GPIOA_REG->GPIODR8R,channelId);
                break;
            
            default:
                break;
            }
						/* handle pin value*/
            *(GPIODATA_PORTA_APB+addressMask) = ptrConfig[pin].PortPinLevelValue;
            break;
        
        case Port_PortB:
            /* get the value of cahnnelId*/
            channelId = ptrConfig[pin].PortChannelId -8;
            /* determine address mask */
            addressMask = 0x01<<channelId;
						/* Ulock Lock register*/
						GPIOB_REG->GPIOLOCK = 0x4C4F434B;
						/* Set the corresponding bit in commit register*/
						SET_BIT(GPIOB_REG->GPIOCR,channelId);
            /* handle pin direction */
            if(PORT_PIN_DIRECTION_OUTPUT == ptrConfig[pin].PortPinDirection)
            {
                SET_BIT(GPIOB_REG->GPIODIR,channelId);
            }
            else
            {
                /* default value is input*/
                /* handle Internal attach value*/
                switch (ptrConfig[pin].PortPinInternalAttach)
                {
                case PORT_PIN_ATTACH_OPEN_DDRAIN:
                    SET_BIT(GPIOB_REG->GPIOODR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_DOWN:
                    SET_BIT(GPIOB_REG->GPIOPDR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_UP:
                    SET_BIT(GPIOB_REG->GPIOPUR,channelId);
                    break;
                
                default:
                    break;
                }
            }
						/* handle pin mode value*/
            if(PORT_MODE_CHANNEL_DIO != ptrConfig[pin].PortPinMode)
            {
                SET_BIT(GPIOB_REG->GPIOAFSEL,channelId);
                GPIOB_REG->GPIOPCTL |= (ptrConfig[pin].PortPinMode<<(channelId*4));
            }
						else
						{
							SET_BIT(GPIOB_REG->GPIODEN,channelId);
						}
						 /* handle output current value*/
            switch (ptrConfig[pin].PortPinOutputCurrent)
            {
            case PORT_PIN_CURRENT_2:
                SET_BIT(GPIOB_REG->GPIODR2R,channelId);
								break;
            case PORT_PIN_CURRENT_4:
                SET_BIT(GPIOB_REG->GPIODR4R,channelId);
								break;
            case PORT_PIN_CURRENT_8:
                SET_BIT(GPIOB_REG->GPIODR8R,channelId);
                break;
            
            default:
                break;
            }
						/* handle pin value*/
            *(GPIODATA_PORTB_APB+addressMask) = ptrConfig[pin].PortPinLevelValue;
            break;
        
        case Port_PortC:
            /* get the value of cahnnelId*/
            channelId = ptrConfig[pin].PortChannelId -16;
            /* determine address mask */
            addressMask = 0x01<<channelId;
						/* Ulock Lock register*/
						GPIOC_REG->GPIOLOCK = 0x4C4F434B;
						/* Set the corresponding bit in commit register*/
						SET_BIT(GPIOC_REG->GPIOCR,channelId);
            /* handle pin direction */
            if(PORT_PIN_DIRECTION_OUTPUT == ptrConfig[pin].PortPinDirection)
            {
                SET_BIT(GPIOC_REG->GPIODIR,channelId);
            }
            else
            {
                /* default value is input*/
                /* handle Internal attach value*/
                switch (ptrConfig[pin].PortPinInternalAttach)
                {
                case PORT_PIN_ATTACH_OPEN_DDRAIN:
                    SET_BIT(GPIOC_REG->GPIOODR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_DOWN:
                    SET_BIT(GPIOC_REG->GPIOPDR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_UP:
                    SET_BIT(GPIOC_REG->GPIOPUR,channelId);
                    break;
                
                default:
                    break;
                }
            }
						/* handle pin mode value*/
            if(PORT_MODE_CHANNEL_DIO != ptrConfig[pin].PortPinMode)
            {
                SET_BIT(GPIOC_REG->GPIOAFSEL,channelId);
                GPIOC_REG->GPIOPCTL |= (ptrConfig[pin].PortPinMode<<(channelId*4));
            }
						else
						{
							SET_BIT(GPIOC_REG->GPIODEN,channelId);
						}
						 /* handle output current value*/
            switch (ptrConfig[pin].PortPinOutputCurrent)
            {
            case PORT_PIN_CURRENT_2:
                SET_BIT(GPIOC_REG->GPIODR2R,channelId);
								break;
            case PORT_PIN_CURRENT_4:
                SET_BIT(GPIOC_REG->GPIODR4R,channelId);
								break;
            case PORT_PIN_CURRENT_8:
                SET_BIT(GPIOC_REG->GPIODR8R,channelId);
                break;
            
            default:
                break;
            }
						/* handle pin value*/
            *(GPIODATA_PORTC_APB+addressMask) = ptrConfig[pin].PortPinLevelValue;
            break;
        
        case Port_PortD:
            /* get the value of cahnnelId*/
            channelId = ptrConfig[pin].PortChannelId -24;
            /* determine address mask */
            addressMask = 0x01<<channelId;
						/* Ulock Lock register*/
						GPIOD_REG->GPIOLOCK = 0x4C4F434B;
						/* Set the corresponding bit in commit register*/
						SET_BIT(GPIOD_REG->GPIOCR,channelId);
            /* handle pin direction */
            if(PORT_PIN_DIRECTION_OUTPUT == ptrConfig[pin].PortPinDirection)
            {
                SET_BIT(GPIOD_REG->GPIODIR,channelId);
            }
            else
            {
                /* default value is input*/
                /* handle Internal attach value*/
                switch (ptrConfig[pin].PortPinInternalAttach)
                {
                case PORT_PIN_ATTACH_OPEN_DDRAIN:
                    SET_BIT(GPIOD_REG->GPIOODR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_DOWN:
                    SET_BIT(GPIOD_REG->GPIOPDR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_UP:
                    SET_BIT(GPIOD_REG->GPIOPUR,channelId);
                    break;
                
                default:
                    break;
                }
            }
						/* handle pin mode value*/
            if(PORT_MODE_CHANNEL_DIO != ptrConfig[pin].PortPinMode)
            {
                SET_BIT(GPIOD_REG->GPIOAFSEL,channelId);
                GPIOD_REG->GPIOPCTL |= (ptrConfig[pin].PortPinMode<<(channelId*4));
            }
						else
						{
							SET_BIT(GPIOD_REG->GPIODEN,channelId);
						}
						 /* handle output current value*/
            switch (ptrConfig[pin].PortPinOutputCurrent)
            {
            case PORT_PIN_CURRENT_2:
                SET_BIT(GPIOD_REG->GPIODR2R,channelId);
								break;
            case PORT_PIN_CURRENT_4:
                SET_BIT(GPIOD_REG->GPIODR4R,channelId);
								break;
            case PORT_PIN_CURRENT_8:
                SET_BIT(GPIOD_REG->GPIODR8R,channelId);
                break;
            
            default:
                break;
            }
						/* handle pin value*/
            *(GPIODATA_PORTD_APB+addressMask) = ptrConfig[pin].PortPinLevelValue;
            break;
        
        case Port_PortE:
            /* get the value of cahnnelId*/
            channelId = ptrConfig[pin].PortChannelId -32;
            /* determine address mask */
            addressMask = 0x01<<channelId;
						/* Ulock Lock register*/
						GPIOE_REG->GPIOLOCK = 0x4C4F434B;
						/* Set the corresponding bit in commit register*/
						SET_BIT(GPIOE_REG->GPIOCR,channelId);
				
            /* handle pin direction */
            if(PORT_PIN_DIRECTION_OUTPUT == ptrConfig[pin].PortPinDirection)
            {
                SET_BIT(GPIOE_REG->GPIODIR,channelId);
            }
            else
            {
                /* default value is input*/
                /* handle Internal attach value*/
                switch (ptrConfig[pin].PortPinInternalAttach)
                {
                case PORT_PIN_ATTACH_OPEN_DDRAIN:
                    SET_BIT(GPIOE_REG->GPIOODR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_DOWN:
                    SET_BIT(GPIOE_REG->GPIOPDR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_UP:
                    SET_BIT(GPIOE_REG->GPIOPUR,channelId);
                    break;
                
                default:
                    break;
                }
            }
						/* handle pin mode value*/
            if(PORT_MODE_CHANNEL_DIO != ptrConfig[pin].PortPinMode)
            {
                SET_BIT(GPIOE_REG->GPIOAFSEL,channelId);
                GPIOE_REG->GPIOPCTL |= (ptrConfig[pin].PortPinMode<<(channelId*4));
            }
						else
						{
							SET_BIT(GPIOE_REG->GPIODEN,channelId);
						}
						 /* handle output current value*/
            switch (ptrConfig[pin].PortPinOutputCurrent)
            {
            case PORT_PIN_CURRENT_2:
                SET_BIT(GPIOE_REG->GPIODR2R,channelId);
								break;
            case PORT_PIN_CURRENT_4:
                SET_BIT(GPIOE_REG->GPIODR4R,channelId);
								break;
            case PORT_PIN_CURRENT_8:
                SET_BIT(GPIOE_REG->GPIODR8R,channelId);
                break;
            
            default:
                break;
            }
						/* handle pin value*/
            *(GPIODATA_PORTE_APB+addressMask) = ptrConfig[pin].PortPinLevelValue;
            break;
        
        case Port_PortF:
            /* get the value of cahnnelId*/
            channelId = ptrConfig[pin].PortChannelId -40;
            /* determine address mask */
            addressMask = 0x01<<channelId;
						/* Ulock Lock register*/
						GPIOF_REG->GPIOLOCK = 0x4C4F434B;
						/* Set the corresponding bit in commit register*/
						SET_BIT(GPIOF_REG->GPIOCR,channelId);
            /* handle pin direction */
            if(PORT_PIN_DIRECTION_OUTPUT == ptrConfig[pin].PortPinDirection)
            {
                SET_BIT(GPIOF_REG->GPIODIR,channelId);
            }
            else
            {
                /* default value is input*/
                /* handle Internal attach value*/
                switch (ptrConfig[pin].PortPinInternalAttach)
                {
                case PORT_PIN_ATTACH_OPEN_DDRAIN:
                    SET_BIT(GPIOF_REG->GPIOODR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_DOWN:
                    SET_BIT(GPIOF_REG->GPIOPDR,channelId);
										break;
                case PORT_PIN_ATTACH_PULL_UP:
                    SET_BIT(GPIOF_REG->GPIOPUR,channelId);
                    break;
                
                default:
                    break;
                }
            }
						/* handle pin mode value*/
            if(PORT_MODE_CHANNEL_DIO != ptrConfig[pin].PortPinMode)
            {
                SET_BIT(GPIOF_REG->GPIOAFSEL,channelId);
                GPIOF_REG->GPIOPCTL |= (ptrConfig[pin].PortPinMode<<(channelId*4));
            }
						else
						{
							SET_BIT(GPIOF_REG->GPIODEN,channelId);
						}
						 /* handle output current value*/
            switch (ptrConfig[pin].PortPinOutputCurrent)
            {
            case PORT_PIN_CURRENT_2:
                SET_BIT(GPIOF_REG->GPIODR2R,channelId);
								break;
            case PORT_PIN_CURRENT_4:
                SET_BIT(GPIOF_REG->GPIODR4R,channelId);
								break;
            case PORT_PIN_CURRENT_8:
                SET_BIT(GPIOF_REG->GPIODR8R,channelId);
                break;
            
            default:
                break;
            }
						/* handle pin value*/
            *(GPIODATA_PORTF_APB+addressMask) = ptrConfig[pin].PortPinLevelValue;
            break;
        
        default:
            break;
        }
    }
}

    


/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
