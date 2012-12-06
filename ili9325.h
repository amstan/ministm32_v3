/*
 * Copyright (C) 2012 Rikard Lindström <ornotermes@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef ILI9325_H
#define ILI9325_H

//---- Includes headers ------------------------------------------------------//

#include <libopencm3/stm32/f1/gpio.h>
#include "font_7seg.h"

//---- Definitions -----------------------------------------------------------//

#define C16_BLACK		0x0000
#define C16_WHITE		0xffff
#define C16_GRAY		0x39ee
#define C16_RED			0xf800
#define C16_DK_RED		0x3800
#define	C16_GREEN		0x07e0
#define C16_DK_GREEN	0x01e0
#define C16_BLUE		0x001f
#define C16_DK_BLUE		0x000e
#define	C16_YELLOW		0xffe0
#define	C16_DK_YELLOW	0x39e0
#define C16_CYAN		0x07ff
#define C16_DK_CYAN		0x01ee
#define C16_MAGENTA		0xf81f
#define C16_DK_MAGENTA	0x3807

#define ili9325Width	240
#define ili9325Height	320

#define ili9325CS(x)		(x)?gpio_set(GPIOC, GPIO8):gpio_clear(GPIOC, GPIO8)
#define ili9325RS(x)		(x)?gpio_set(GPIOC, GPIO9):gpio_clear(GPIOC, GPIO9)
#define ili9325WR(x)		(x)?gpio_set(GPIOC, GPIO10):gpio_clear(GPIOC, GPIO10)
#define ili9325RD(x)		(x)?gpio_set(GPIOC, GPIO11):gpio_clear(GPIOC, GPIO11)
#define ili9325Light(x) 	(x)?gpio_set(GPIOC, GPIO12):gpio_clear(GPIOC, GPIO12)

//---- Variables -------------------------------------------------------------//

uint8_t _ili9325Rotation = 0; //Don't set it by hand, use ili9325_orientation()

//---- Function prototypes ---------------------------------------------------//

void		ili9325PortDirection(bool input);
void		ili9325PortWrite(uint16_t bits);		
uint16_t	ili9325PortRead(void);
void		ili9325WriteCommand(uint16_t command);
void		ili9325WriteData(uint16_t data);
void		ili9325WriteRegister(uint16_t reg, uint16_t data);
void		ili9325Init(void);
void		ili9325GoTo(uint16_t x, uint16_t y);
void		ili9325Clear(uint16_t color);
void		ili9325Point(uint16_t color);
void		ili9325Orientation(uint8_t rot);
void		ili9325PrintDigit(uint8_t digit, uint16_t x, uint16_t y, uint16_t \
			colorFront, uint16_t colorBack, uint16_t colorShadow);
//void		ili9325Image(const uint16_t *width, const uint16_t *height, const uint16_t *colors, const uint8_t *data, uint16_t destX, uint16_t destY);

//---- Include source --------------------------------------------------------//

#include "ili9325.c"

#endif
