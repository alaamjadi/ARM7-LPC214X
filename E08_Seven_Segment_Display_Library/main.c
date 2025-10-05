/**
 * @file main.c
 * @brief Seven-segment display control with multiple switches
 * @version 1.0
 *
 * This example demonstrates:
 * - Seven-segment display control using library functions
 * - Multiple switch input handling for digit selection
 * - Error handling for invalid states
 */

#include "Config.h"
#include "7Seg.h"
#include "switch.h"

/**
 * @brief Initialize all hardware peripherals
 *
 * Initializes:
 * - Seven-segment display GPIO pins
 * - Switch GPIO pins for digit selection
 */
void InitMain(void)
{
    Init_7Seg();  // Initialize seven-segment display
    init_sw();    // Initialize digit selection switches
}

/**
 * @brief Main program entry point
 */
void main(void)
{
    InitMain();

    while (1) {
        /* Check each switch and display corresponding digit */
        if ((sw_pin & sw0) == 0)         // Switch 0 pressed
        {
            Wr_7Seg(0);
        }
        else if ((sw_pin & sw1) == 0)    // Switch 1 pressed
        {
            Wr_7Seg(1);
        }
        else if ((sw_pin & sw2) == 0)    // Switch 2 pressed
        {
            Wr_7Seg(2);
        }
        else if ((sw_pin & sw3) == 0)    // Switch 3 pressed
        {
            Wr_7Seg(3);
        }
        else if ((sw_pin & sw4) == 0)    // Switch 4 pressed
        {
            Wr_7Seg(4);
        }
        else if ((sw_pin & sw5) == 0)    // Switch 5 pressed
        {
            Wr_7Seg(5);
        }
        else if ((sw_pin & sw6) == 0)    // Switch 6 pressed
        {
            Wr_7Seg(6);
        }
        else if ((sw_pin & sw7) == 0)    // Switch 7 pressed
        {
            Wr_7Seg(7);
        }
        else if ((sw_pin & sw8) == 0)    // Switch 8 pressed
        {
            Wr_7Seg(8);
        }
        else if ((sw_pin & sw9) == 0)    // Switch 9 pressed
        {
            Wr_7Seg(9);
        }
        else                            // No switch pressed or error
        {
            Wr_7Seg(10);  // Display 'E' for error/empty state
        }
  }
}
