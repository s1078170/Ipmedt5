/*
 * pwm.c
 *
 *  Created on: 18 aug. 2015
 *      Author: Qui
 */
#include "main.h"

void initPWM (void)
{
	//Init timer0 and timer2 to create PWM on PD3,PD5,PD6

	//Timer0
    // set none-inverting mode on PWM A
    TCCR0A |= (1 << COM0A1);
    // set none-inverting mode on PWM B
    TCCR0A |= (1 << COM0B1);
    // set fast PWM Mode
    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    // set prescaler to 8 and starts PWM
    TCCR0B |= (1 << CS01);

    //Timer2
    // set none-inverting mode on PWM B
    TCCR2A |= (1 << COM2B1);
    // set fast PWM Mode
    TCCR2A |= (1 << WGM21) | (1 << WGM20);
    // set prescaler to 8 and starts PWM
    TCCR2B |= (1 << CS21);

    //Set all PWM channels off
    OCR0A = 0;	//RED OFF
    OCR0B = 0;	//GREEN OFF
    OCR2B = 0;	//BLUE OFF
}

void writePWM(char channel, char value)
{
	switch(channel)
	{
		case RED:
		{
			//TIMER0 PWMA = RED
			OCR0A = value;
			break;
		}

		case GREEN:
		{
			//TIMER0 PWMB = GREEN
			OCR0B = value;
			break;
		}

		case BLUE:
		{
			//TIMER2 PWMB = BLUE
			OCR2B = value;
			break;
		}
	}

}
