/*
 * gpio.c
 *
 *  Created on: 18 aug. 2015
 *      Author: Qui
 */
#include "main.h"

void initGPIO (void)
{
	DDRB |= (1<<PB0);//Set Debug led as output
	DDRD |= (1<<PD3) | (1<<PD5) | (1<<PD6);//Set PWM pins as output
	DDRD &= ~(1<<PD2);//Set encoder as input
	PORTB = 0x00;//Clear PORTB
	PORTD = 0x00;//Clear PORTD
}
