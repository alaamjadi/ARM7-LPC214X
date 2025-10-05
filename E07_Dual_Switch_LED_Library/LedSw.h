/**
 * @file LedSw.h
 * @brief LED and Switch interface definitions for LPC2148
 * @version 1.0
 *
 * This header provides:
 * - LED pin definitions and control macros
 * - Dual switch pin definitions and control macros
 * - Initialization function prototype
 */

#ifndef _LEDSW_H
#define _LEDSW_H

#include "Config.h"

/* LED Control Register Definitions */
#define LED_DIR IO0DIR   // LED Direction Register (Port 0)
#define LED_SET IO0SET   // LED Set Register (Port 0)
#define LED_CLR IO0CLR   // LED Clear Register (Port 0)

/* LED Pin Definitions */
#define Led1 (1<<0)    // LED1 connected to P0.0
#define Led2 (1<<1)    // LED2 connected to P0.1
#define Led3 (1<<2)    // LED3 connected to P0.2
#define Led4 (1<<3)    // LED4 connected to P0.3
#define Led5 (1<<4)    // LED5 connected to P0.4
#define Led6 (1<<5)    // LED6 connected to P0.5
#define Led7 (1<<6)    // LED7 connected to P0.6
#define Led8 (1<<7)    // LED8 connected to P0.7

/* LED Mask for all LEDs */
#define Mask_Led (Led1 | Led2 | Led3 | Led4 | Led5 | Led6 | Led7 | Led8)

/* Switch Control Register Definitions */
#define SW_DIR IO0DIR   // Switch Direction Register (Port 0)
#define SW_PIN IO0PIN   // Switch Pin Register (Port 0)

/* Switch Pin Definitions */
#define Sw1 (1<<10)    // Switch1 connected to P0.10
#define Sw2 (1<<11)    // Switch2 connected to P0.11

void Init_Sw_Led (void);

#endif
