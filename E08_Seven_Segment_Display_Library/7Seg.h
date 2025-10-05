/**
 * @file 7Seg.h
 * @brief Seven-segment display control interface
 * @version 1.0
 *
 * This header provides:
 * - Seven-segment display control registers
 * - Display initialization function
 * - Display write function for numeric output
 */

#ifndef _7SEG_H
#define _7SEG_H

#include "config.h"

/* Seven Segment Display Control Registers */
#define SEG_DIR IO0DIR   // Direction register for segment pins
#define SEG_SET IO0SET   // Set register for segment pins
#define SEG_CLR IO0CLR   // Clear register for segment pins

/* Function Declarations */

/**
 * @brief Initialize seven-segment display GPIO pins
 * 
 * Configures the GPIO pins (P0.17-P0.23) as outputs for
 * controlling the seven-segment display segments
 */
void Init_7Seg(void);

/**
 * @brief Write a number to the seven-segment display
 * @param num Number to display (0-9, 10 for error)
 * 
 * Converts the input number to its corresponding
 * seven-segment display pattern and outputs it
 */
void Wr_7Seg(U8 num);

#endif
