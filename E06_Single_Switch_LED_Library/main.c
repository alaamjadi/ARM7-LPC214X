/**
 * @file main.c
 * @brief Single switch and dual LED control using library functions
 * @version 1.0
 *
 * This example demonstrates:
 * - Usage of LED and Switch library functions
 * - Hardware abstraction through library interface
 * - Simple switch-based LED control logic
 */

#include "Config.h"
#include "LedSw.h"

/**
 * @brief Initialize all hardware peripherals
 *
 * This function calls all necessary initialization
 * routines for the application
 */
void InitMain(void)
{
    Init_Sw_Led();  // Initialize LED and Switch GPIO
}

/**
 * @brief Main program entry point
 */
void main(void)
{
  InitMain();

    while(1)
    {
        /* Check if Switch1 is pressed (active low) */
        if ((SW_PIN & Sw1) == 0)
        {
            LED_SET |= Led1;  // Turn on LED1
            LED_CLR |= Led2;  // Turn off LED2
        }
        else
        {
            LED_CLR |= Led1;  // Turn off LED1
            LED_SET |= Led2;  // Turn on LED2
        }
  }
}
