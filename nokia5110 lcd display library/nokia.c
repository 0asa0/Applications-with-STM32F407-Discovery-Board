/*
 * nokia.c
 *
 *  Created on: Aug 16, 2023
 *      Author: ASA
 */

#include "nokia.h"
#include <stdbool.h>


bool nokia_init(void){
	nokia_reset();
	if(!nokia_write(0x21, 0))
		return false;
	if(!nokia_write(0xC0, 0))
		return false;
	if(!nokia_write(0x07, 0))
		return false;
	if(!nokia_write(0x13, 0))
		return false;
	if(!nokia_write(0x20, 0))
		return false;
	if(!nokia_write(0x0C, 0))
		return false;

	return true;
}

void nokia_reset(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10,GPIO_PIN_RESET);//reset pin is low
	HAL_Delay(30);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10,GPIO_PIN_SET);//reset pin is high
}


bool nokia_write(uint8_t data, uint8_t mode) {
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);//CE pin is low

	if(mode == 0)
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);//dc pin is low for data send
	}
	else if(mode == 1)
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);//for command send
	else {
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
		return false;
	}

	HAL_SPI_Transmit_DMA(&hspi2, &data, 1);

	return true;
}
uint8_t frameBuff[504];
void nokia_clear(){
	for ( int i= 0; i < 504; i++) {
		frameBuff[i] = 0x00;
	}
}
bool nokia_update(void){
	if(!nokia_write(0x80,0))
	{
		return false;
	}
	if(!nokia_write(0x40,0))
	{
		return false;
	}
	if(!nokia_bufferwrite(frameBuff,504))
	{
			return false;
	}
	return true;
}

bool nokia_bufferwrite(uint8_t* data, uint16_t len){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
	HAL_SPI_Transmit_DMA(&hspi2, data, len);
	return true;
}

void nokia_setpixel(uint8_t x, uint8_t y, bool set){
	uint8_t Bi;
	uint16_t By;

	if (x<0 || x>= 84 || y<0 || y >= 84) {
		return;
	}
	By = (y/8) * 84 + x;
	Bi = y % 8;

	if (set) {
		frameBuff[By] |= (1<< Bi);
	} else {
		frameBuff[By] &= -(1<< Bi);
	}
}




