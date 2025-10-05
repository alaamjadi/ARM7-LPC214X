/**
 * @file switch.h
 * @brief Switch interface definitions for seven-segment control
 * @version 1.0
 *
 * This header provides:
 * - Switch pin definitions for digit selection
 * - Switch control registers
 * - Switch initialization function prototype
 */

#ifndef _SWITCH_H
#define _SWITCH_H

#include "Config.h"

/* Switch Control Register Definitions */
#define sw_dir IO0DIR   // Direction register for switch pins
#define sw_pin IO0PIN   // Pin state register for switches

/* Switch Pin Definitions */
#define sw0 (1<<0)    // Switch for digit 0 (P0.0)
#define sw1 (1<<1)    // Switch for digit 1 (P0.1)
#define sw2 (1<<2)    // Switch for digit 2 (P0.2)
#define sw3 (1<<3)    // Switch for digit 3 (P0.3)
#define sw4 (1<<4)    // Switch for digit 4 (P0.4)
#define sw5 (1<<5)    // Switch for digit 5 (P0.5)
#define sw6 (1<<6)    // Switch for digit 6 (P0.6)
#define sw7 (1<<7)    // Switch for digit 7 (P0.7)
#define sw8 (1<<8)    // Switch for digit 8 (P0.8)
#define sw9 (1<<9)    // Switch for digit 9 (P0.9)

/* Mask for all switches */
#define mask_sw (sw0 | sw1 | sw2 | sw3 | sw4 | sw5 | sw6 | sw7 | sw8 | sw9)

/**
 * @brief Initialize switch GPIO pins
 *
 * Configures all switch pins (P0.0-P0.9) as inputs
 * for digit selection
 */
void init_sw(void);

#endif
