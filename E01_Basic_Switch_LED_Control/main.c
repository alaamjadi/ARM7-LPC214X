/**
 * @file main.c
 * @brief Basic LED control using a single switch on LPC2148
 * @version 1.0
 * 
 * This example demonstrates basic GPIO operations on LPC2148:
 * - LED1 and LED2 are configured as outputs
 * - SW1 is configured as input
 * - When SW1 is pressed, LED1 turns off and LED2 turns on
 * - When SW1 is released, LED1 turns on and LED2 turns off
 */

#include <nxp/iolpc2148.h>

/* Pin definitions for LEDs and Switch */
#define led1 (1<<20)    // LED1 connected to P1.20
#define led2 (1<<24)    // LED2 connected to P1.24
#define sw1  (1<<29)    // Switch1 connected to P1.29

void main (void)
{
  IO1DIR |=led1;  //output P1.20 as Led1
  IO1DIR |=led2;  //output P1.24 as Led2
  IO1DIR &=~sw1;  //input P1.29 as Sw1

  while(1)
  {
    if( (IO1PIN & sw1) == 0 ) //check status of switch P1.29 ? 0
    {
      IO1CLR |=led1;  //  0-> P1.20
      IO1SET |=led2;  //  1-> P1.24
    }
    else
    {
      IO1SET |=led1;  //  1-> P1.20
      IO1CLR |=led2;  //  0-> P1.24
    }
  }
}
