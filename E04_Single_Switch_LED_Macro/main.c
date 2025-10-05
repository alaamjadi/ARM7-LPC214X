/**
 * @file main.c
 * @brief Single switch and dual LED control using macros
 * @version 1.0
 * 
 * This example demonstrates GPIO control using macro definitions:
 * - Uses preprocessor macros for pin definitions and operations
 * - Implements LED control with switch input using macro functions
 * - Shows how to create reusable GPIO macros for cleaner code
 */

#include <nxp/iolpc2148.h>

/* Pin Definitions */
#define led1 (1<<20)  // LED1 connected to P1.20
#define led2 (1<<24)  // LED2 connected to P1.24
#define sw1  (1<<29)  // Switch1 connected to P1.29

/* GPIO Direction Configuration Macros */
#define int_led1() IO1DIR |=led1;  // Configure P1.20 as output for LED1
#define int_led2() IO1DIR |=led2;  // Configure P1.24 as output for LED2
#define int_sw1()  IO1DIR &=~sw1;  // Configure P1.29 as input for Switch1

/* GPIO Operation Macros */
#define out_led1(x) ((x) ? (IO1SET |=led1) : (IO1CLR |= led1))  // Set LED1 state (1=on, 0=off)
#define out_led2(x) ((x) ? (IO1SET |=led2) : (IO1CLR |= led2))  // Set LED2 state (1=on, 0=off)

/* Input Reading Macro */
#define read_sw1() ((IO1PIN & sw1) == 0)  // Read switch state (returns 1 when pressed)

void main(void)
{
  int_led1();
  int_led2();
  int_sw1();

  while(1)
  {
    if ( read_sw1() )
    {
      out_led1(0);
      out_led2(0);
    }
    else
    {
      out_led1(1);
      out_led2(0);
    }
  }
}
