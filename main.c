#include "main.h"

#define DEBUG_ON			(PORTB |= (1<<PB0))//Debug ON
#define DEBUG_OFF			(PORTB &= ~(1<<PB0))//Debug OFF

#define INTERVALTIME		(5)

int cnt = 0; 
char col = 0; 

void init (void)
{
char i = 0;

	initGPIO();
	initPWM();

	//Enable encoder interrupt
	EIMSK = (1 << INT0);
	EICRA = 0;
	EICRA |= ((1 << ISC01));// set INT0 to trigger on falling edge change

	//Show init ok
	for(i=0;i<10;i++)
	{
		PORTB |= (1<<PB0);
		wait_ms(100);
		PORTB &= ~(1<<PB0);
		wait_ms(100);
	}

	//test rgb leds
	//RED ON
	for(i=0;i<255;i++)
	{
		writePWM(RED,i);
		wait_ms(INTERVALTIME);
	}

	//RED OFF
	for(i=255;i>0;i--)
	{
		writePWM(RED,i);
		wait_ms(INTERVALTIME);
	}

	//GREEN ON
	for(i=0;i<255;i++)
	{
		writePWM(GREEN,i);
		wait_ms(INTERVALTIME);
	}

	//GREEN OFF
	for(i=255;i>0;i--)
	{
		writePWM(GREEN,i);
		wait_ms(INTERVALTIME);
	}

	//BLUE ON
	for(i=0;i<255;i++)
	{
		writePWM(BLUE,i);
		wait_ms(INTERVALTIME);
	}

	//BLUE OFF
	for(i=255;i>0;i--)
	{
		writePWM(BLUE,i);
		wait_ms(INTERVALTIME);
	}

	//Blink green 3 times
	for(i=0;i<7;i++)
	{
		writePWM(GREEN,255);
		wait_ms(200);
		writePWM(GREEN,0);
		wait_ms(200);
	}
	wait_ms(1000);//Wait 1000ms (1sec)
	//Enable interrupt
	sei();

}

int main (void)
{
char i = 0;
	init();

	//Begin hier met code
	while(1)
	{

	}

	return 0;
}

ISR(INT0_vect) //is geworden extia_irq
{
	if(cnt<255)
		cnt+=20;
	else
	{
		if(col<5)
			col++;
		else
			col = 0;
			
		cnt = 0;
	}
		
	switch(col)
	{
		case 0:
		{
			writePWM(RED,cnt);
			writePWM(GREEN,0);
			writePWM(BLUE,0);
			break;
		}
		
		case 1:
		{
			writePWM(RED,0);
			writePWM(GREEN,cnt);
			writePWM(BLUE,0);
			break;
		}
		
		case 2:
		{
			writePWM(RED,0);
			writePWM(GREEN,0);
			writePWM(BLUE,cnt);
			break;
		}

		case 3:
		{
			writePWM(RED,cnt);
			writePWM(GREEN,cnt);
			writePWM(BLUE,0);
			break;
		}
		
		case 4:
		{
			writePWM(RED,0);
			writePWM(GREEN,cnt);
			writePWM(BLUE,cnt);
			break;
		}
		
		case 5:
		{
			writePWM(RED,cnt);
			writePWM(GREEN,0);
			writePWM(BLUE,cnt);
			break;
		}

	}
}

void wait_ms (uint16_t ms)
{
	int i = 0;
	for (; ms>0; ms--)
	{
		for (i=0;i<500;i++);
	}
}

void wait_us (uint16_t ms)
{
	for (; ms>0; ms--);
}
