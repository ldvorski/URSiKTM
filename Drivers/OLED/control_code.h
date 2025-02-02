/*
 * control_code.h
 *
 *  Created on: Feb 2, 2025
 *      Author: Ryzen
 */

#ifndef OLED_CONTROL_CODE_H_
#define OLED_CONTROL_CODE_H_

//INCLUDES
#include "stm32f4xx_hal.h"
#include <stdint.h>

//MACROS
#define SCREEN_WIDTH 			128
#define SCREEN_HEIGHT 			64
#define SCREEN_BUFFER_SIZE 	SCREEN_WIDTH*SCREEN_HEIGHT/8

//ENUMS
typedef enum {
	SCREEN_OK 	= 0x00,
	SCREEN_ERR 	= 0x01
} Screen_Error_t;

typedef enum {
	Black = 0x00,
	White = 0x01
}Pixel_Color;

//TYPES
typedef struct {
	uint16_t CurrX;
	uint16_t CurrY;
	uint8_t Initialized;
} Screen_t;

typedef struct {
	const uint8_t width;
	const uint8_t height;
	const uint16_t *const data;
} Font_t;

//FUNCTIONS
uint8_t screenInit(I2C_HandleTypeDef *hi2c);
void screenFlash();
void screenUpdate(I2C_HandleTypeDef *hi2c);
char screenWriteChar(char ch, Font_t font);
char screenWriteStr(const char* str, Font_t font);
void screenSetCursor(uint8_t x, uint8_t y);
void screenClear();


#endif /* OLED_CONTROL_CODE_H_ */
