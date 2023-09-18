/*
 * nokia.h
 *
 *  Created on: Aug 16, 2023
 *      Author: ASA
 */
#ifndef INC_NOKIA_H_
#define INC_NOKIA_H_
#include "stm32f4xx_hal.h"
#include <stdbool.h>

extern SPI_HandleTypeDef hspi2;
extern DMA_HandleTypeDef hdma_spi2_tx;



bool nokia_init(void);
bool nokia_update(void);
void nokia_reset(void);
void nokia_clear(void);
bool nokia_write(uint8_t data, uint8_t mode);
bool nokia_bufferwrite(uint8_t* data, uint16_t len);
void nokia_setpixel(uint8_t x, uint8_t y, bool set);

#endif /* INC_NOKIA_H_ */
