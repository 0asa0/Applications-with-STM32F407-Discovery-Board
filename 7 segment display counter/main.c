
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef PIN;

void GPIO_Config()
	{

		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);

		PIN.GPIO_Mode = GPIO_Mode_IN;
		PIN.GPIO_OType =  GPIO_OType_PP;
		PIN.GPIO_Pin = GPIO_Pin_0;
		PIN.GPIO_PuPd = GPIO_PuPd_DOWN ;
		PIN.GPIO_Speed = GPIO_Speed_100MHz;

		GPIO_Init(GPIOE, &PIN); //BUTTON

		PIN.GPIO_Mode = GPIO_Mode_OUT;
		PIN.GPIO_OType =  GPIO_OType_PP;
		PIN.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 |GPIO_Pin_6;
		PIN.GPIO_PuPd = GPIO_PuPd_NOPULL ;
		PIN.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_Init(GPIOA, &PIN); //LED

		PIN.GPIO_Mode = GPIO_Mode_OUT;
		PIN.GPIO_OType =  GPIO_OType_PP;
		PIN.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 |GPIO_Pin_6;
		PIN.GPIO_PuPd = GPIO_PuPd_NOPULL ;
		PIN.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_Init(GPIOB, &PIN); //LED
	}
void lednumbers(GPIO_TypeDef* GPIOx, int counter){

	switch(counter)
	{
		case 0:
		{
			GPIO_ResetBits(GPIOx, GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_6);
			GPIO_SetBits(GPIOx, GPIO_Pin_5);
			break;
		}
		case 1:
		{
			GPIO_ResetBits(GPIOx, GPIO_Pin_1 |GPIO_Pin_2);
			GPIO_SetBits(GPIOx,GPIO_Pin_0 |GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 |GPIO_Pin_6);
			break;
		}
		case 2:
			GPIO_ResetBits(GPIOx, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_5);
			GPIO_SetBits(GPIOx,GPIO_Pin_2 |GPIO_Pin_6);
			break;
		case 3:
			GPIO_ResetBits(GPIOx, GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_5 |GPIO_Pin_2 |GPIO_Pin_3);
			GPIO_SetBits(GPIOx, GPIO_Pin_4 |GPIO_Pin_6);
			break;
		case 4:
			GPIO_ResetBits(GPIOx, GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_5 |GPIO_Pin_6);
			GPIO_SetBits(GPIOx,GPIO_Pin_0 |GPIO_Pin_3 |GPIO_Pin_4 );
			break;
		case 5:
			GPIO_ResetBits(GPIOx, GPIO_Pin_0 |GPIO_Pin_5 |GPIO_Pin_6 |GPIO_Pin_2 |GPIO_Pin_3);
			GPIO_SetBits(GPIOx,GPIO_Pin_1  |GPIO_Pin_4);
			break;
		case 6:
			GPIO_ResetBits(GPIOx, GPIO_Pin_0 |GPIO_Pin_2 |GPIO_Pin_5 |GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_6);
			GPIO_SetBits(GPIOx,GPIO_Pin_1);
			break;
		case 7:
			GPIO_ResetBits(GPIOx, GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2);
			GPIO_SetBits(GPIOx,GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 |GPIO_Pin_6);
			break;
		case 8:
			GPIO_ResetBits(GPIOx, GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 |GPIO_Pin_6);
			break;
		case 9:
			GPIO_ResetBits(GPIOx, GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2 |GPIO_Pin_3 |GPIO_Pin_5 |GPIO_Pin_6);
			GPIO_SetBits(GPIOx,GPIO_Pin_4);
			break;

	}

}

void delay(uint32_t time)
{
	while(time--);
}
int main(void)
{
	GPIO_Config();
	int counter1 = 0;
	int counter2 = 0;

  while (1)
  {
	 if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0)) {
		while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0));
		delay(1680000);
		counter1++;
		if(counter1 % 10 == 0){
			counter2++;
		}
	}
	 lednumbers(GPIOA, counter1 % 10);
	 lednumbers(GPIOB, counter2);
  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}

