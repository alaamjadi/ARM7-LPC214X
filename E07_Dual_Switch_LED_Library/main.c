/**
 * @file main.c
 * @brief Dual switch and dual LED control using library functions
 * @version 1.0
 *
 * This example demonstrates:
 * - Usage of LED and Switch library functions for multiple I/O
 * - Independent control of two LEDs using two switches
 * - Hardware abstraction through library interface
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
    Init_Sw_Led();  // Initialize LEDs and Switches GPIO
}

/**
 * @brief Main program entry point
 */
void main(void)
{
  InitMain();

    while (1) {
        /* Check if Switch1 is pressed (active low) */
        if ((SW_PIN & Sw1) == 0)
        {
            LED_CLR |= Led1;  // Turn off LED1 when Switch1 is pressed
        }
        else
        {
            LED_SET |= Led1;  // Turn on LED1 when Switch1 is released
        }

        /* Check if Switch2 is pressed (active low) */
        if ((SW_PIN & Sw2) == 0)
        {
            LED_CLR |= Led2;  // Turn off LED2 when Switch2 is pressed
        }
        else
        {
            LED_SET |= Led2;  // Turn on LED2 when Switch2 is released
        }
  }
}
