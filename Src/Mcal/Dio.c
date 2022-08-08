/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital input output driver.
 *
 *      \details  the driver controls all Digital input outputs channels.
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    /* Declare return variable */
    Dio_LevelType level;
    /* Declare address mask */
    uint8 addressMask;
    /* Determine the port by integer division by 8 */
    Dio_PortType portId;
    portId = ChannelId/8;

    switch (portId)
    {
    case Dio_PortA:
        /* determine address mask */
        addressMask = 0x01<<ChannelId;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTA_APB+addressMask);
        break;
    
    case Dio_PortB:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-8;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTB_APB+addressMask);
        break;
    
    case Dio_PortC:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-16;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTC_APB+addressMask);
        break;
    
    case Dio_PortD:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-24;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTD_APB+addressMask);
        break;
    
    case Dio_PortE:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-32;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTE_APB+addressMask);
        break;
    
    case Dio_PortF:
       /* determine address mask */
        addressMask = 0x01<<ChannelId-40;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTF_APB+addressMask);
        break;
    
    default:
        break;
    }
    return level;
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
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    /* Declare address mask */
    uint16 addressMask;
    /* Determine the port by integer division by 8 */
    Dio_PortType portId;
    portId = ChannelId/8;
    switch (portId)
    {
    case Dio_PortA:
        /* determine address mask */
        addressMask = 0x01<<ChannelId;
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTA_APB+addressMask) = Level;
        break;
    
    case Dio_PortB:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-8;
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTB_APB+addressMask) = Level;
        break;
    
    case Dio_PortC:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-16;
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTC_APB+addressMask) = Level;
        break;
    
    case Dio_PortD:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-24;
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTD_APB+addressMask) = Level;
        break;
    
    case Dio_PortE:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-32;
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTE_APB+addressMask) = Level;
        break;
    
    case Dio_PortF:
       /* determine address mask */
        addressMask = 0x01<<ChannelId-40;
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTF_APB+addressMask) = Level;
        break;
    
    default:
        break;
    }
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
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    /* Declare return variable */
    Dio_PortLevelType level;
    /* Declare address mask */
    uint8 addressMask = 0xFF;

    switch (PortId)
    {
    case Dio_PortA:
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTA_APB+addressMask);
        break;
    
    case Dio_PortB:
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTB_APB+addressMask);
        break;
    
    case Dio_PortC:
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTC_APB+addressMask);
        break;
    
    case Dio_PortD:
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTD_APB+addressMask);
        break;
    
    case Dio_PortE:
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTE_APB+addressMask);
        break;
    
    case Dio_PortF:
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTF_APB+addressMask);
        break;
    
    default:
        break;
    }
    return level;
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
void Dio_WritPort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    /* Declare address mask */
    uint8 addressMask = 0xFF;

    switch (PortId)
    {
    case Dio_PortA:
        /* read from GPIODATA + address mask */
        *(GPIODATA_PORTA_APB+addressMask) = Level;
        break;
    
    case Dio_PortB:
        /* read from GPIODATA + address mask */
        *(GPIODATA_PORTB_APB+addressMask) = Level;
        break;
    
    case Dio_PortC:
        /* read from GPIODATA + address mask */
        *(GPIODATA_PORTC_APB+addressMask) = Level;
        break;
    
    case Dio_PortD:
        /* read from GPIODATA + address mask */
        *(GPIODATA_PORTD_APB+addressMask) = Level;
        break;
    
    case Dio_PortE:
        /* read from GPIODATA + address mask */
        *(GPIODATA_PORTE_APB+addressMask) = Level;
        break;
    
    case Dio_PortF:
        /* read from GPIODATA + address mask */
        *(GPIODATA_PORTF_APB+addressMask) = Level;
        break;
    
    default:
        break;
    }
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
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    /* Declare return variable */
    Dio_LevelType level;
    /* Declare address mask */
    uint8 addressMask;
    /* Determine the port by integer division by 8 */
    Dio_PortType portId;
    portId = ChannelId/8;

    switch (portId)
    {
    case Dio_PortA:
        /* determine address mask */
        addressMask = 0x01<<ChannelId;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTA_APB+addressMask);
        /* flip level */
        if(GPIO_HIGH == level)
        {
            level = GPIO_LOW;
        }
        else
        {
            level = GPIO_HIGH;
        }
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTA_APB+addressMask) = level;
        break;
    
    case Dio_PortB:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-8;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTB_APB+addressMask);
        /* flip level */
        if(GPIO_HIGH == level)
        {
            level = GPIO_LOW;
        }
        else
        {
            level = GPIO_HIGH;
        }
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTB_APB+addressMask) = level;
        break;
    
    case Dio_PortC:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-16;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTC_APB+addressMask);
        /* flip level */
        if(GPIO_HIGH == level)
        {
            level = GPIO_LOW;
        }
        else
        {
            level = GPIO_HIGH;
        }
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTC_APB+addressMask) = level;
        break;
    
    case Dio_PortD:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-24;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTD_APB+addressMask);
        /* flip level */
        if(GPIO_HIGH == level)
        {
            level = GPIO_LOW;
        }
        else
        {
            level = GPIO_HIGH;
        }
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTD_APB+addressMask) = level;
        break;
    
    case Dio_PortE:
        /* determine address mask */
        addressMask = 0x01<<ChannelId-32;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTE_APB+addressMask);
        /* flip level */
        if(GPIO_HIGH == level)
        {
            level = GPIO_LOW;
        }
        else
        {
            level = GPIO_HIGH;
        }
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTE_APB+addressMask) = level;
        break;
    
    case Dio_PortF:
       /* determine address mask */
        addressMask = 0x01<<ChannelId-40;
        /* read from GPIODATA + address mask */
        level = *(GPIODATA_PORTF_APB+addressMask);
        /* flip level */
        if(GPIO_LOW == level)
        {
            level = GPIO_HIGH;
        }
        else
        {
 						level = GPIO_LOW;	
        }
        /* write in GPIODATA + address mask */
        *(GPIODATA_PORTF_APB+addressMask) = level;
        break;
    
    default:
        break;
    }
    return level;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
