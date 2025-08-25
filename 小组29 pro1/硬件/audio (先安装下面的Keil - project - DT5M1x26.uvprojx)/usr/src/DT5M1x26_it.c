#include "DT5M1x26.h"
#include "play_audio.h"

void SysTick_Handler(void)
{

}

void WDT_Int_Handler(void)
{
//    if(WDT_GetIntFlag())
//    {
//        WDT_ClearIntFlag();
//		//printf("WDT Int!\r\n");
//    }
//		*(vu8*)(0x10000101ul) = 0xff;
//		*(vu8*)(0x10000101ul) = 0x7f;
}

void Timer0_Int_Handler(void)
{
	if (Timer_GetIntFlag(TIMER0))
	{
		Timer_ClearIntFlag(TIMER0);
	}
}

void Timer1_Int_Handler(void)
{
	if(Timer_GetIntFlag(TIMER1))
	{
		Timer_ClearIntFlag(TIMER1);	
	}
}

void GPIO_Int_Handler(void)
{

}

void GPIO_WakeUp_Int_Handler(void)
{

}

void Sound_Int_Handler(void)
{
	Sound_Int_Usr_Handler();
}


void Uart_Int_Handler(void)
{

}


void SPI_Int_Handler(void)
{
//	vu32 r;
//
//	r = SPI->ICR;
//
//	printf("spi int \r\n");
}

void I2C_Int_Handler(void)
{
//	if (I2C_GetIntFlag() & I2C_TX_EMPTY_INT)
//	{
//		printf("I2C tx int \r\n");
//	}

//	if (I2C_GetIntFlag() & I2C_RX_FULL_INT)
//	{
//		printf("I2C rx int \r\n");
//	}
//	I2C_ClearInt();
}

void RTC_Int_Handler(void)
{
//    if(RTC_GetIntFlag())
//    {
//        RTC_ClearIntFlag();
//    }	
//		*(vu8*)(0x10000101ul) = 0xff;
//		*(vu8*)(0x10000101ul) = 0x7f;
}

void ADC_Int_Handler(void)
{
  
}

void ADC_Fall_Int_Handler(void)
{
   
	 
}

void ADC_Rise_Int_Handler(void)
{

}
