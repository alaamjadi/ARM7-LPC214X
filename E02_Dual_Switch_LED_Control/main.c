/**
 * @file main.c
 * @brief Dual LED control using two switches on LPC2148
 * @version 1.0
 * 
 * This example demonstrates independent control of two LEDs:
 * - LED1 and LED2 are configured as outputs
 * - SW1 and SW2 are configured as inputs
 * - Each switch controls its corresponding LED
 * - When a switch is pressed, its LED turns off
 * - When a switch is released, its LED turns on
 */

#include <nxp/iolpc2148.h>

/* Pin definitions for LEDs and Switches */
#define led1 (1<<4)    // LED1 connected to P0.4
#define led2 (1<<7)    // LED2 connected to P0.7
#define sw1  (1<<0)    // Switch1 connected to P0.0
#define sw2  (1<<2)    // Switch2 connected to P0.2

void main (void)
{
  IO1DIR |=led1;  //output P0.4 as Led1
  IO1DIR |=led2;  //output P0.7 as Led2
  IO1DIR &=~sw1;  //input P0.0 as Sw1
  IO1DIR &=~sw2;  //input P0.2 as Sw1
  while(1)
  {
    if( (IO0PIN & sw1) == 0 ) //check status of switch P0.0 ? 0
    {
      IO0CLR |=led1;  //  0-> P0.4
    }
    else
    {
      IO0SET |=led1;  //  1-> P0.4
    }
//
    if( (IO0PIN & sw2) == 0 ) //check status of switch P0.2 ? 0
    {
      IO0CLR |=led2;  //  0-> P0.7
    }
    else
    {
      IO0SET |=led2;  //  1-> P0.7
    }
  }
}
