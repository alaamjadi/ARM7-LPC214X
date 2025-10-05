/**
 * @file switch.c
 * @brief Switch initialization implementation for seven-segment control
 * @version 1.0
 *
 * This source file provides:
 * - Implementation of switch initialization
 * - Configuration of GPIO pins for digit selection switches
 */

#include "Config.h"
#include "switch.h"

/**
 * @brief Initialize all switch GPIO pins
 *
 * Configures P0.0 through P0.9 as inputs for
 * digit selection (0-9) switches
 */
void init_sw(void)
{
    /* Configure P0.0-P0.9 as inputs using switch mask */
    sw_dir &= ~mask_sw;  // Clear direction bits for all switches
}
