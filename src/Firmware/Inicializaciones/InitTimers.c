#include <TPO.h>

void InicTimer0(void);

void InicTimer0(void)
{
	PCONP |= 1 << 1; 		// Habilitar Timer 0
	PCLKSEL0 |= 1 << 2; 	// Clock for timer PCLK = CCLK Selecciono clock
	T0->PR = 100000;		// Prescaler para 1ms
	T0->TCR = 2;			// Apago y reseteo el temporizador
	T0->MR1 = 0xFFFFFFFF;	// Configuro match 1 para detectar overflow
	T0->MCR_.MR1I = 1;		// Interrumpe si se produce overflow
}
