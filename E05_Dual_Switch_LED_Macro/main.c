/**
 * @file main.c
 * @brief Dual switch and dual LED control using macros
 * @version 1.0
 * 
 * This example demonstrates advanced GPIO control using macro definitions:
 * - Uses preprocessor macros for multiple pin definitions and operations
 * - Implements independent LED control with separate switches
 * - Shows how to handle multiple inputs and outputs using macros
 */

#include <nxp/iolpc2148.h>

/* Pin Definitions */
#define led1 (1<<4)  // LED1 connected to P0.4
#define led2 (1<<7)  // LED2 connected to P0.7
#define sw1  (1<<0)  // Switch1 connected to P0.0
#define sw2  (1<<2)  // Switch2 connected to P0.2

/* GPIO Direction Configuration Macros */
#define int_led1() IO0DIR |=led1;  // Configure P0.4 as output for LED1
#define int_led2() IO0DIR |=led2;  // Configure P0.7 as output for LED2
#define int_sw1()  IO0DIR &=~sw1;  // Configure P0.0 as input for Switch1
#define int_sw2()  IO0DIR &=~sw2;  // Configure P0.2 as input for Switch2

/* GPIO Output Control Macros */
#define out_led1(x) ((x) ? (IO0SET |=led1) : (IO0CLR |= led1))  // Set LED1 state (1=on, 0=off)
#define out_led2(x) ((x) ? (IO0SET |=led2) : (IO0CLR |= led2))  // Set LED2 state (1=on, 0=off)

/* GPIO Input Reading Macros */
#define read_sw1() ((IO0PIN & sw1) == 0)  // Read Switch1 state (returns 1 when pressed)
#define read_sw2() ((IO0PIN & sw2) == 0)  // Read Switch2 state (returns 1 when pressed)

void main(void)
{
  int_led1();
  int_led2();
  int_sw1();
  int_sw1();

  while(1)
  {
    if ( read_sw1() )
    {
      out_led1(0);
    }
    else
    {
      out_led1(1);
    }
//
    if ( read_sw2() )
    {
      out_led2(0);
    }
    else
    {
      out_led2(1);
    }
  }
}
