/*
* main.c
* Author: Bilgehan Sakin
* number: 1801022062
* prepared for MICROPROCESSOR PROJECT 2
*/

#include "bsp.h"
#include "lc512.h"
#include <stdlib.h>

int main(void)
{
	//configurating sizes of reading and writing memory ability
	allocBuffers();
	//Set current state START as default should be 
	curr_state = START;
	//Set current state properties
	SetStateProperty(curr_state);
	//Initializing ADC
	ADCInit();
	//Initializing PWM
	INIT_PWM();
	//Initializing EEPROMs
	INIT_EEPROM_512();
	//Initializing TIMER14
	INIT_TIMER14();
	//Initializing KEYPAD & SSD
	Keypad_SSD_GPIO_Init();
	//Initializing TIMER2
	INIT_TIMER2();

	while (1)
	{

	}

	//Releasing memory
	freeBuffers();
}
