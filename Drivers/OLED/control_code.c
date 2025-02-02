/*
 * control_code.c
 *
 *  Created on: Feb 2, 2025
 *      Author: Ryzen
 */

#include <stdlib.h>
#include <string.h>
#include "control_code.h"

static uint8_t buffer[SCREEN_BUFFER_SIZE];
static Screen_t screen;

static uint8_t screenWriteCommand(I2C_HandleTypeDef *hi2c1, uint8_t byte) {
	return HAL_I2C_Mem_Write(hi2c1,(0x3C<<1), 0x00,1, &byte, 1, HAL_MAX_DELAY);
}


uint8_t screenInit(I2C_HandleTypeDef *hi2c){
	if(screen.Initialized == 1){
		return 0;
	}
	HAL_Delay(200);
	int status = 0;

	status += screenWriteCommand(hi2c, 0xAE); //turns display off
	status += screenWriteCommand(hi2c, 0x20); //Set memory addressing mode
	status += screenWriteCommand(hi2c, 0x00); //Horizontal addressing mode
	status += screenWriteCommand(hi2c, 0xB0); //Set Page Start Address to 0
	status += screenWriteCommand(hi2c, 0xC8); //Set COM Output Scan Direction
	status += screenWriteCommand(hi2c, 0x00); //set low column address
	status += screenWriteCommand(hi2c, 0x10); //set high column address
	status += screenWriteCommand(hi2c, 0x40); //set start line address
	status += screenWriteCommand(hi2c, 0x81); //set contrast control register
	status += screenWriteCommand(hi2c, 0xFF);
	status += screenWriteCommand(hi2c, 0xA1); //set segment re-map 0 to 127
	status += screenWriteCommand(hi2c, 0xA6); //set normal display

	status += screenWriteCommand(hi2c, 0xA8); //set multiplex ratio
	status += screenWriteCommand(hi2c, SCREEN_HEIGHT -1);

	status += screenWriteCommand(hi2c, 0xA4); //0xa4 output follows RAM content; 0xa5 output ignores RAM content
	status += screenWriteCommand(hi2c, 0xD3); //set display offset
	status += screenWriteCommand(hi2c, 0x00); //no offset
	status += screenWriteCommand(hi2c, 0xD5); //Set display clock divide ratio/oscillator frequency
	status += screenWriteCommand(hi2c, 0xF0); //Set divide ratio
	status += screenWriteCommand(hi2c, 0xD9); //set pre-charge period
	status += screenWriteCommand(hi2c, 0x22);

	status += screenWriteCommand(hi2c, 0xDB); //set vcomh
	status += screenWriteCommand(hi2c, 0x20); //0x20, 0.77xVcc
	status += screenWriteCommand(hi2c, 0x8D); //set DC-DC enable
	status += screenWriteCommand(hi2c, 0x14);
	status += screenWriteCommand(hi2c, 0xAF); //turns display on

	if (status != 0){
		return 1;
	}

	screenClear();
	screenUpdate(hi2c);

	screen.CurrX = 0;
	screen.CurrY = 0;
	screen.Initialized = 1;

	return 0;
}

void screenFlash(){
	uint32_t i;

	for(i=0; i<sizeof(buffer);i++){
		buffer[i] = 0xFF;
	}
}

void screenUpdate(I2C_HandleTypeDef *hi2c){
	uint8_t i;

	for(i = 0; i < (SCREEN_HEIGHT/8); i++){
		screenWriteCommand(hi2c, 0xB0 + i);
		screenWriteCommand(hi2c, 0x00);
		screenWriteCommand(hi2c, 0x10);

		HAL_I2C_Mem_Write(hi2c, (0x3C<<1), 0x40, 1, &buffer[SCREEN_WIDTH*i], SCREEN_WIDTH, 100);
	}
}

void screenDrawPixel(uint8_t x, uint8_t y, Pixel_Color color){
	if( (x < SCREEN_WIDTH) && (y < SCREEN_HEIGHT)){
		if(color == White){
			buffer[x + (y/8) * SCREEN_WIDTH] |= 1<<(y%8);
		} else {
			buffer[x + (y/8) * SCREEN_WIDTH] &= ~(1<<(y%8));
		}
	}
}

char screenWriteChar(char ch, Font_t font){
	uint32_t i, j, b;
	int x = screen.CurrX;
	int y = screen.CurrY;

	//Check if char is valid
	if(ch<32 || ch>126){
		return 0;
	}

	//Check remaining space on current line
	if (SCREEN_WIDTH <= (x + font.width) ||
		SCREEN_HEIGHT <= (y + font.height)){
		return 0;
	}

	for (i=0; i<font.height; i++){
		b = font.data[(ch-32) * font.height + i];
		for(j=0; j<font.width; j++){
			if ((b << j) & 0x8000){
				screenDrawPixel(x+j, y+i, (Pixel_Color) White);
			}else{
				screenDrawPixel(x+j, y+i, (Pixel_Color) Black);
			}
		}
	}

	screen.CurrX += font.width;

	return ch;
}

char screenWriteStr(const char* str, Font_t font){
	while(*str){
		if(screenWriteChar(*str, font) != *str){
			//char couldn't be written
			return *str;
		}

		str++;
	}
	//OK
	return *str;
}

void screenClear(){
	memset(buffer, 0x00, SCREEN_BUFFER_SIZE);
}

void screenSetCursor(uint8_t x, uint8_t y){
	screen.CurrX = x;
	screen.CurrY = y;
}
