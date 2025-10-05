/**
 * @file Config.h
 * @brief Global configuration and type definitions for LPC2148
 * @version 1.0
 *
 * This header provides:
 * - System clock configuration
 * - Common type definitions
 * - Boolean constants
 * - Standard integer type definitions for 7-segment display
 */

#ifndef _CONFIG_H
#define _CONFIG_H

#include <nxp/iolpc2148.h>

/* Clock Configuration */
#define CCLK 12000000   // CPU Clock frequency in Hz
#define PCLK (CCLK/4)   // Peripheral Clock frequency (CPU Clock / 4)

/* Boolean Constants */
#define True  1
#define False 0

/* Standard Integer Types */
typedef char               S8;    // Signed 8-bit integer (for BCD values)
typedef unsigned char      U8;    // Unsigned 8-bit integer (for segment patterns)
typedef short             S16;    // Signed 16-bit integer
typedef unsigned short    U16;    // Unsigned 16-bit integer
typedef int               S32;    // Signed 32-bit integer
typedef unsigned int      U32;    // Unsigned 32-bit integer
typedef long long         S64;    // Signed 64-bit integer
typedef unsigned long long U64;   // Unsigned 64-bit integer

/* Special Types */
typedef unsigned char     BIT;    // Single bit type
typedef unsigned int      BOOL;   // Boolean type

/* Floating Point Types */
typedef float            Fp32;    // 32-bit floating point
typedef double           Fp64;    // 64-bit floating point
