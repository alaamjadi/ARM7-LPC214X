/**
 * @file 7Seg.c
 * @brief Seven-segment display control implementation
 * @version 1.0
 *
 * This source file provides:
 * - Seven-segment display initialization
 * - Display pattern lookup table
 * - Number display implementation
 */

#include "Config.h"
#include "7Seg.h"

/* Seven-segment display patterns for digits 0-9 and error (E) */
const U8 BCD[11] = {
    0x3f,  // 0: 0b00111111
    0x06,  // 1: 0b00000110
    0x5b,  // 2: 0b01011011
    0x4f,  // 3: 0b01001111
    0x66,  // 4: 0b01100110
    0x6d,  // 5: 0b01101101
    0x7d,  // 6: 0b01111101
    0x07,  // 7: 0b00000111
    0x7f,  // 8: 0b01111111
    0x67,  // 9: 0b01100111
    0x79   // E: 0b01111001 (Error)

/**
 * @brief Initialize seven-segment display GPIO pins
 *
 * Configures P0.17 through P0.23 as outputs for the
 * seven-segment display segments (a-g)
 */
void Init_7Seg(void)
{
    /* Configure P0.17-P0.23 as outputs */
    SEG_DIR |= (0xff << 17);
}

/**
 * @brief Write a number to the seven-segment display
 * @param Num Number to display (0-9, 10 for error)
 *
 * Clears all segments first, then sets the appropriate
 * segments based on the BCD lookup table pattern
 */
void Wr_7Seg(U8 Num)
{
    /* Clear all segments first */
    SEG_CLR |= (0xff << 17);
    
    /* Set segments according to BCD pattern */
    SEG_SET |= (BCD[Num] << 17);
}
