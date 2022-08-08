#include "Std_Types.h"
#include "SysCtr.h""
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "IntCtrl.h"
#include "Bit_Math.h"
void func1(void)
{
	Dio_FlipChannel(Dio_Channel_F1);
}

int main (void)
{
	SysCtr_Init();
	
	extern Port_ConfigType PortConfigChannels;
	Port_Init(&PortConfigChannels);
	
	
	IntCrtl_Init();
	
	extern Gpt_ConfigType GptConfigChannels;
	GptConfigChannels.Gpt_Notification = &func1;
	
	
	Dio_WriteChannel(Dio_Channel_F1,GPIO_LOW);
	
	
	
	Gpt_Init(&GptConfigChannels);
	Gpt_EnableNotification(GPT_TIMER_0);
	
	uint8 flag1 =1;
	
	while(1)
	{
		if(Dio_ReadChannel(Dio_Channel_F4) == GPIO_LOW && flag1 == 1)
		{
			Gpt_StartTimer(GPT_TIMER_0,0x00F42400); // 1 sec ON and 1 sec OFF
			flag1 =0;
		}
		if(Dio_ReadChannel(Dio_Channel_F4) != GPIO_LOW &&flag1 == 0)
		{
			Gpt_StartTimer(GPT_TIMER_0,0x007A1200); // 0.5 sec ON and 0.5 sec OFF
			flag1 =1;
		}	
	}
	return 0;
}