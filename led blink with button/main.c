
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef BUTTON;

void GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
	BUTTON.GPIO_Pin = GPIO_Pin_12 |GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	BUTTON.GPIO_Mode = GPIO_Mode_OUT;
	BUTTON.GPIO_OType = GPIO_OType_PP;
	BUTTON.GPIO_PuPd = GPIO_PuPd_NOPULL;
	BUTTON.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD,&BUTTON);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	BUTTON.GPIO_Pin = GPIO_Pin_0;
	BUTTON.GPIO_Mode = GPIO_Mode_IN;
	BUTTON.GPIO_OType = GPIO_OType_PP;
	BUTTON.GPIO_PuPd = GPIO_PuPd_DOWN;
	BUTTON.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOA,&BUTTON);

}

void delay(uint32_t time) {
	while(time--);
}

int main(void)
{
	GPIO_Config();
	int i = 1;
  while (1)
  {
	  if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))
	  {
		  while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0));//butondan dolayı oluşan arkı(debuence) önlemek için
		  delay(1680000);//butondan dolayı oluşan arkı önlemek için

		  if(i % 4 == 0){
			  GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
			  i++;
		  }
		  else if(i % 4 == 1){
			  GPIO_ToggleBits(GPIOD, GPIO_Pin_13);
			  i++;
		  }
		  else if(i % 4 == 2){
			  GPIO_ToggleBits(GPIOD, GPIO_Pin_14);
			  i++;
		  		  }
		  else if(i % 4 == 3){
			  GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
			  i++;
		  		  }
	  }

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
