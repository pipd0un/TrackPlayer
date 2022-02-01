/*
 * auth@r: Bilgehan Sakin
 * FILE  : bsp.h
 * 
*/
#include <stdbool.h>
#include "stm32g0xx.h"

#ifndef _BSP_H_
#define _BSP_H_

//FIRST EEPROM COMMUNICATION ADDRESS
#define EEPROM_ADR1 0x50 //1010(Control Byte)000(A2 A1 A0)
//SECOND EEPROM COMMUNICATION ADDRESS
#define EEPROM_ADR2 0x54 //1010(Control Byte)100(A2 A1 A0)
//Max one track size that will write to EEPROM
#define MAX_TRACK_BYTE_SIZE 32000

//Write buffer
uint8_t* buffer_write;
//Read buffer
uint8_t* buffer_read;
//Write index
uint16_t bw_index;
//Read index
uint16_t read_index;
//Current recorded size
uint16_t record_size;
//Current write memory address
uint16_t curr_memaddr;
//Current read device address
uint8_t curr_devaddr;
//Able to read operation
bool can_read;
//Able to button press
bool canButtonPress;
//Debouncing counter
uint8_t buttonPressCounter;
//Returning idle counter
uint16_t idle_counter;
//Storing state chars to display on SSD
char disp_letters[4];
//Recorded Track size
uint8_t track_size;
//Recording time duration
uint8_t record_time;
//Refers to initialized address of reading memory
uint16_t read_init_memaddr;
//Current reading device address
uint8_t curr_readdevaddr;
//Current reading memory address
uint16_t curr_readmemaddr;
//Boolean array that refers to
//whether track is recorded or not
bool playable_track[4];

//STATES
typedef enum STATE
{
	START,
	IDLE,
	RECORD,
	PLAY,
	PAUSE,
	DELETE,
	STATUS,
	FULL,
	INVALID
}STATE;

//TRACKS
typedef enum TRACK
{
	TRACK1 = 1,
	TRACK2,
	TRACK3,
	TRACK4
}TRACK;

//Selected Track
TRACK selected_track;
//Selected Current State
STATE curr_state;

//Basic common delay function
void delay(volatile unsigned int s);
//CLEAR KEYPAD ROWS
void clearRow(void);
//SET KEYPAD ROWS
void setRow(void);

/* 	Assigning proper chars to display
	array to show current state properly */

void SetStateProperty(STATE state);
//TIMER3 USED BY PWM
void INIT_PWM();
//TRACK PLAYER & RECORDER
void INIT_TIMER2();
//DEBOUNCING & DISPLAYER TIMER
void INIT_TIMER14();
//Play sound
void PlaySound(uint8_t sound);
//Track and recorder interrupt
void TIM2_IRQHandler();

void TIM14_IRQHandler(void);

void EXTI4_15_IRQHandler(void);
//ADC INITIALIZATION
void ADCInit();
/*To implementing basic numbers to leds need to assign them
  as chars. */
char IntToChar(uint8_t digit);

void allocBuffers(void);
void freeBuffers(void);

/* SSDCONFIG */

//Segments BEGIN
//To light A LED
void SetSegmentA();
//To light B LED
void SetSegmentB();
//To light C LED
void SetSegmentC();
//To light D LED
void SetSegmentD();
//To light E LED
void SetSegmentE();
//To light F LED
void SetSegmentF();
//To light G LED
void SetSegmentG();
//Segments END

//Numbers BEGIN
//To light Number 0
void SetNumberZero();
//To light Number 1
void SetNumberOne();
//To light Number 2
void SetNumberTwo();
//To light Number 3
void SetNumberThree();
//To light Number 4
void SetNumberFour();
//To light Number 5
void SetNumberFive();
//To light Number 6
void SetNumberSix();
//To light Number 7
void SetNumberSeven();
//To light Number 8
void SetNumberEight();
//To light Number 9
void SetNumberNine();
//To light Negative Sign
void SetNegativeSign();
//Numbers END

//Letters Begin
//To light Letter A
void SetLetterA();
//To light Letter B
void SetLetterB();
//To light Letter C
void SetLetterC();
//To light Letter D
void SetLetterD();
//To light Letter E
void SetLetterE();
//To light Letter I
void SetLetterI();
//To light Letter N
void SetLetterN();
//To light Letter V
void SetLetterV();
//To light Letter O
void SetLetterO();
//To light Letter U
void SetLetterU();
//To light Letter F
void SetLetterF();
//To light Letter L
void SetLetterL();
//To light Letter P
void SetLetterP();
//To light Letter R
void SetLetterR();
//Letters End

//To turn left most digit when shifter reachs to rightmost digit
void TurnBeginning();
void ShiftDigit(unsigned int currIndex);
//Initializing counter and assigning them to school id(1734)
void Init_Counter(int(*_digits)[4]);
//Initializing letters and assigning them to "-" character
void Init_Letters(char* _letters);
//Resetting digits and assigning all of them to zero
void Reset_Counter(int(*_digits)[4]);
//To display characters (mixing displayNum and displayLetter)
void DisplayChar(char ch);
//Clearing displayer
void ResetDisplay();
//KEYPAD & SSD INITIALIZER
void Keypad_SSD_GPIO_Init(void);
#endif
