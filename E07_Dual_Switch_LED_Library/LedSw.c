/**
 * @file LedSw.c
 * @brief LED and Switch initialization implementation
 * @version 1.0
 *
 * This source file provides:
 * - Implementation of LED and Switch initialization
 * - Configuration of GPIO pins for multiple LEDs and switches
 */

#include "Config.h"
#include "LedSw.h"

/**
 * @brief Initialize LED and Switch GPIO pins
 *
 * This function:
 * - Configures LED pins as outputs (P0.0 to P0.7)
 * - Sets initial LED state to OFF (active high)
 * - Configures two Switch pins as inputs (P0.10 and P0.11)
 */
void Init_Sw_Led (void)
{
    /* Configure LED pins (P0.0 to P0.7) as outputs */
    LED_DIR |= Mask_Led;

    /* Initialize all LEDs to OFF state (active high) */
    LED_SET |= Mask_Led;

    /* Configure switch pins (P0.10 and P0.11) as inputs */
    SW_DIR &= ~Sw1;  // Configure Switch1 as input
    SW_DIR &= ~Sw2;  // Configure Switch2 as input
}
