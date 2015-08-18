#include <avr/io.h>
#include <avr/interrupt.h>

#define RED			(0)
#define GREEN		(1)
#define BLUE		(2)

#define TRUE 		(1)
#define FALSE 		(0)

void initGPIO (void);

void initPWM();
void writePWM(char channel, char value);


int main (void);
void init (void);

void wait_ms (uint16_t ms);
void wait_us (uint16_t ms);
