/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  Port
 *
 *  Description:   header file for Port types
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* PortPinMode Options*/
#define PORT_MODE_CHANNEL_DIO                   0

#define PORT_MODE_CHANNEL_A0_U0RX               1
#define PORT_MODE_CHANNEL_A1_U0TX               1
#define PORT_MODE_CHANNEL_B0_U1RX               1
#define PORT_MODE_CHANNEL_B1_U1TX               1
#define PORT_MODE_CHANNEL_C0_SWCLK              1
#define PORT_MODE_CHANNEL_C1_SWDIO              1
#define PORT_MODE_CHANNEL_C2_TDI                1
#define PORT_MODE_CHANNEL_C3_TDO                1
#define PORT_MODE_CHANNEL_C4_U4RX               1
#define PORT_MODE_CHANNEL_C5_U4TX               1
#define PORT_MODE_CHANNEL_C6_U3RX               1
#define PORT_MODE_CHANNEL_C7_U3TX               1
#define PORT_MODE_CHANNEL_D0_SSI3CLK            1
#define PORT_MODE_CHANNEL_D1_SSI3FSS            1
#define PORT_MODE_CHANNEL_D2_SSI3RX             1
#define PORT_MODE_CHANNEL_D3_SSI3TX             1
#define PORT_MODE_CHANNEL_D4_U6RX               1
#define PORT_MODE_CHANNEL_D5_U6TX               1
#define PORT_MODE_CHANNEL_D6_U2RX               1
#define PORT_MODE_CHANNEL_D7_U2TX               1
#define PORT_MODE_CHANNEL_E0_U7RX               1
#define PORT_MODE_CHANNEL_E1_U7TX               1
#define PORT_MODE_CHANNEL_E4_U5RX               1
#define PORT_MODE_CHANNEL_E5_U5TX               1
#define PORT_MODE_CHANNEL_F0_U1RTS              1
#define PORT_MODE_CHANNEL_F1_U1CTS              1

#define PORT_MODE_CHANNEL_A2_SSI0CLK            2
#define PORT_MODE_CHANNEL_A3_SSI0FSS            2
#define PORT_MODE_CHANNEL_A4_SSI0RX             2
#define PORT_MODE_CHANNEL_A5_SSI0TX             2
#define PORT_MODE_CHANNEL_B4_SSI2CLK            2
#define PORT_MODE_CHANNEL_B5_SSI2FSS            2
#define PORT_MODE_CHANNEL_B6_SSI2RX             2
#define PORT_MODE_CHANNEL_B7_SSI2TX             2
#define PORT_MODE_CHANNEL_C4_U1RX               2
#define PORT_MODE_CHANNEL_C5_U1TX               2
#define PORT_MODE_CHANNEL_D0_SSI1CLK            2
#define PORT_MODE_CHANNEL_D1_SSI1FSS            2
#define PORT_MODE_CHANNEL_D2_SSI1RX             2
#define PORT_MODE_CHANNEL_D3_SSI1TX             2
#define PORT_MODE_CHANNEL_F0_SSI1RX             2
#define PORT_MODE_CHANNEL_F1_SSI1TX             2
#define PORT_MODE_CHANNEL_F2_SSI1CLK            2
#define PORT_MODE_CHANNEL_F3_SSI1FSS            2

#define PORT_MODE_CHANNEL_A6_I2C1SCL            3
#define PORT_MODE_CHANNEL_A7_I2C1SDA            3
#define PORT_MODE_CHANNEL_B2_I2C0SCL            3
#define PORT_MODE_CHANNEL_B3_I2C0SDA            3
#define PORT_MODE_CHANNEL_D0_I2C3SCL            3
#define PORT_MODE_CHANNEL_D1_I2C3SDA            3
#define PORT_MODE_CHANNEL_E4_I2C2SCL            3
#define PORT_MODE_CHANNEL_E5_I2C2SDA            3
#define PORT_MODE_CHANNEL_F0_CAN0RX             3
#define PORT_MODE_CHANNEL_F3_CAN0TX             3

#define PORT_MODE_CHANNEL_B4_M0PWM2             4
#define PORT_MODE_CHANNEL_B5_M0PWM3             4
#define PORT_MODE_CHANNEL_B6_M0PWM0             4
#define PORT_MODE_CHANNEL_B7_M0PWM1             4
#define PORT_MODE_CHANNEL_C4_M0PWM6             4
#define PORT_MODE_CHANNEL_C5_M0PWM7             4
#define PORT_MODE_CHANNEL_D0_M0PWM6             4
#define PORT_MODE_CHANNEL_D1_M0PWM7             4
#define PORT_MODE_CHANNEL_D2_M0FAULT0           4
#define PORT_MODE_CHANNEL_D6_M0FAULT0           4
#define PORT_MODE_CHANNEL_E4_M0PWM4             4
#define PORT_MODE_CHANNEL_E5_M0PWM5             4
#define PORT_MODE_CHANNEL_F2_M0FAULT0           4

#define PORT_MODE_CHANNEL_A6_M1PWM2             5
#define PORT_MODE_CHANNEL_A7_M1PWM3             5
#define PORT_MODE_CHANNEL_D0_M1PWM0             5
#define PORT_MODE_CHANNEL_D1_M1PWM1             5
#define PORT_MODE_CHANNEL_E4_M1PWM2             5
#define PORT_MODE_CHANNEL_E5_M1PWM3             5
#define PORT_MODE_CHANNEL_F0_M1PWM4             5
#define PORT_MODE_CHANNEL_F1_M1PWM5             5
#define PORT_MODE_CHANNEL_F2_M1PWM6             5
#define PORT_MODE_CHANNEL_F3_M1PWM7             5
#define PORT_MODE_CHANNEL_F4_M1FAULT0           5

#define PORT_MODE_CHANNEL_C4_IDX1               6
#define PORT_MODE_CHANNEL_C5_PHA1               6
#define PORT_MODE_CHANNEL_C6_PHB1               6
#define PORT_MODE_CHANNEL_D3_IDX0               6
#define PORT_MODE_CHANNEL_D6_PHA0               6
#define PORT_MODE_CHANNEL_D7_PHB0               6
#define PORT_MODE_CHANNEL_F0_PHA0               6
#define PORT_MODE_CHANNEL_F1_PHB0               6
#define PORT_MODE_CHANNEL_F4_IDX0               6

#define PORT_MODE_CHANNEL_B0_T2CCP0             7
#define PORT_MODE_CHANNEL_B1_T2CCP1             7
#define PORT_MODE_CHANNEL_B2_T3CCP0             7
#define PORT_MODE_CHANNEL_B3_T3CCP1             7
#define PORT_MODE_CHANNEL_B4_T1CCP0             7
#define PORT_MODE_CHANNEL_B5_T1CCP1             7
#define PORT_MODE_CHANNEL_B6_T0CCP0             7
#define PORT_MODE_CHANNEL_B7_T0CCP1             7
#define PORT_MODE_CHANNEL_C0_T4CCP0             7
#define PORT_MODE_CHANNEL_C1_T4CCP1             7
#define PORT_MODE_CHANNEL_C2_T5CCP0             7
#define PORT_MODE_CHANNEL_C3_T5CCP1             7
#define PORT_MODE_CHANNEL_C4_WT0CCP0            7
#define PORT_MODE_CHANNEL_C5_WT0CCP1            7
#define PORT_MODE_CHANNEL_C6_WT1CCP0            7
#define PORT_MODE_CHANNEL_C7_WT1CCP1            7
#define PORT_MODE_CHANNEL_D0_WT2CCP0            7
#define PORT_MODE_CHANNEL_D1_WT2CCP1            7
#define PORT_MODE_CHANNEL_D2_WT3CCP0            7
#define PORT_MODE_CHANNEL_D3_WT3CCP1            7
#define PORT_MODE_CHANNEL_D4_WT4CCP0            7
#define PORT_MODE_CHANNEL_D5_WT4CCP1            7
#define PORT_MODE_CHANNEL_D6_WT5CCP0            7
#define PORT_MODE_CHANNEL_D7_WT5CCP1            7
#define PORT_MODE_CHANNEL_F0_T0CCP0             7
#define PORT_MODE_CHANNEL_F1_T0CCP1             7
#define PORT_MODE_CHANNEL_F2_T1CCP0             7
#define PORT_MODE_CHANNEL_F3_T1CCP1             7
#define PORT_MODE_CHANNEL_F4_T2CCP0             7

#define PORT_MODE_CHANNEL_A0_CAN1RX             8
#define PORT_MODE_CHANNEL_A1_CAN1TX             8
#define PORT_MODE_CHANNEL_B4_CAN1RX             8
#define PORT_MODE_CHANNEL_B5_CAN1TX             8
#define PORT_MODE_CHANNEL_C4_U1RTS              8
#define PORT_MODE_CHANNEL_C5_U1CTS              8
#define PORT_MODE_CHANNEL_C6_USB0EPEN           8
#define PORT_MODE_CHANNEL_C7_USB0PFLT           8
#define PORT_MODE_CHANNEL_D2_USB0EPEN           8
#define PORT_MODE_CHANNEL_D3_USB0PFLT           8
#define PORT_MODE_CHANNEL_D7_NMI                8
#define PORT_MODE_CHANNEL_E4_CAN0RX             8
#define PORT_MODE_CHANNEL_E5_CAN0TX             8
#define PORT_MODE_CHANNEL_F0_NMI                8
#define PORT_MODE_CHANNEL_F4_USB0EPEN           8

#define PORT_MODE_CHANNEL_F0_C0O                9
#define PORT_MODE_CHANNEL_F1_C1O                9

#define PORT_MODE_CHANNEL_F1_TRD1               14
#define PORT_MODE_CHANNEL_F2_TRD0               14
#define PORT_MODE_CHANNEL_F3_TRCLK              14
/* End of PortPinMode Options*/

/* PortPinDirection Options*/
#define PORT_PIN_DIRECTION_INPUT                0
#define PORT_PIN_DIRECTION_OUTPUT               1
/* End of PortPinDirection Options*/

/* PortPinOutputCurrent Options*/
#define PORT_PIN_CURRENT_2                      0
#define PORT_PIN_CURRENT_4                      1
#define PORT_PIN_CURRENT_8                      2
/* End of PortPinOutputCurrent Options*/

/* PortPinValue Options*/
#define PORT_PIN_VALUE_LOW                      0
#define PORT_PIN_VALUE_HIGH                     0xFF
/* End of PortPinValue Options*/

/* PortPinInternalAttach Options*/
#define PORT_PIN_ATTACH_OPEN_DDRAIN            0
#define PORT_PIN_ATTACH_PULL_UP                1
#define PORT_PIN_ATTACH_PULL_DOWN              2
#define PORT_PIN_ATTACH_NA                     3
/* End of PortPinInternalAttach Options*/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
    Port_Channel_A0 =0,
    Port_Channel_A1,
    Port_Channel_A2,
    Port_Channel_A3,
    Port_Channel_A4,
    Port_Channel_A5,
    Port_Channel_A6,
    Port_Channel_A7,

    Port_Channel_B0,
    Port_Channel_B1,
    Port_Channel_B2,
    Port_Channel_B3,
    Port_Channel_B4,
    Port_Channel_B5,
    Port_Channel_B6,
    Port_Channel_B7,

    Port_Channel_C0,
    Port_Channel_C1,
    Port_Channel_C2,
    Port_Channel_C3,
    Port_Channel_C4,
    Port_Channel_C5,
    Port_Channel_C6,
    Port_Channel_C7,

    Port_Channel_D0,
    Port_Channel_D1,
    Port_Channel_D2,
    Port_Channel_D3,
    Port_Channel_D4,
    Port_Channel_D5,
    Port_Channel_D6,
    Port_Channel_D7,

    Port_Channel_E0,
    Port_Channel_E1,
    Port_Channel_E2,
    Port_Channel_E3,
    Port_Channel_E4,
    Port_Channel_E5,
    Port_Channel_E6,
    Port_Channel_E7,

    Port_Channel_F0,
    Port_Channel_F1,
    Port_Channel_F2,
    Port_Channel_F3,
    Port_Channel_F4,
    Port_Channel_F5,
    Port_Channel_F6,
    Port_Channel_F7
}Port_ChannelType;

typedef enum{
    Port_PortA =0,
    Port_PortB,
    Port_PortC,
    Port_PortD,
    Port_PortE,
    Port_PortF
}Port_PortType;

typedef uint8 Port_PinType;
typedef uint8 Port_PinDirectionType;
typedef uint8 Port_PinModeType;
typedef uint8 Port_PinInternalAttachType;
typedef uint8 Port_PinOutputCurrentType;
typedef const struct
{
    Port_ChannelType PortChannelId;
    Port_PinType PortPinLevelValue;
    Port_PinDirectionType PortPinDirection;
    Port_PinModeType PortPinMode;
    Port_PinInternalAttachType PortPinInternalAttach;
    Port_PinOutputCurrentType PortPinOutputCurrent;
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
