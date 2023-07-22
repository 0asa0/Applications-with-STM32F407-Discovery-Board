
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void GPIO_Config()
{
	//reference manual.pdf -> GPIO registers
	RCC->AHB1ENR = 0x00000008; //D portunun clock hattı aktif edilir.
	GPIOD->MODER = 0x55000000; //GPIO mode registerının 12,13,14,15. pinlerini general output purpose mode'a almak için bu pinlere 01 atanır geri kalan pinler 00.
	GPIOD->OTYPER = 0x00000000; // Output push pull olması için 0 atanır.
	GPIOD->OSPEEDR = 0xFF000000; //very high speed çalışması için 12,13,14,15. pinlere 11 atanır.
	GPIOD->PUPDR = 0x00000000; //no pull up no pull down
}

void delay(uint32_t time) {
	while(time--);
}

int main(void)
{
	GPIO_Config();
  while (1)
  {

	  GPIOD->ODR = 0x00000000;// D portunda 12,13,14,15. pinlerde ledler bulunmaktadır. output data regsterdan ledleri yakmak için çıkış alınır.
	  delay(1680000);
	  GPIOD->ODR = 0x00001000;
	  delay(1680000);
	  GPIOD->ODR = 0x00000000;
	  delay(1680000);
	  GPIOD->ODR = 0x00002000;
	  delay(1680000);
	  GPIOD->ODR = 0x00000000;
	  delay(1680000);
	  GPIOD->ODR = 0x00004000;
	  delay(1680000);
	  GPIOD->ODR = 0x00008000;
	  delay(1680000);
	  GPIOD->ODR = 0x0000F000;
	  delay(1680000);

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
