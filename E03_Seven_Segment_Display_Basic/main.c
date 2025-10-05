/**
 * @file main.c
 * @brief Seven-segment display control using switches on LPC2148
 * @version 1.0
 * 
 * This example demonstrates 7-segment display control:
 * - 10 switches (SW0-SW9) are used for digit selection
 * - 7-segment display connected to P1.17 through P1.23
 * - Pressing a switch displays corresponding digit
 * - Displays 'E' when no switch is pressed or error
 */

#include <nxp/iolpc2148.h>

/* Pin definitions for switches */
#define sw0 (1<<0)     // Switch for digit 0
#define sw1 (1<<1)     // Switch for digit 1
#define sw2 (1<<2)     // Switch for digit 2
#define sw3 (1<<3)     // Switch for digit 3
#define sw4 (1<<4)     // Switch for digit 4
#define sw5 (1<<5)     // Switch for digit 5
#define sw6 (1<<6)     // Switch for digit 6
#define sw7 (1<<7)     // Switch for digit 7
#define sw8 (1<<8)     // Switch for digit 8
#define sw9 (1<<9)     // Switch for digit 9

/* Seven segment display pins (P1.17 - P1.23) */
#define dir (127UL<<17)

unsigned char BCD[11]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67, 0x79};

void main (void)
{
  IO0DIR |=dir;  //P1.17 ~ P1.23

  IO0DIR &=~sw0;  //P0.0  as  sw0
  IO0DIR &=~sw1;  //P0.1  as  sw1
  IO0DIR &=~sw2;  //P0.2  as  sw2
  IO0DIR &=~sw3;  //P0.3  as  sw3
  IO0DIR &=~sw4;  //P0.4  as  sw4
  IO0DIR &=~sw5;  //P0.5  as  sw5
  IO0DIR &=~sw6;  //P0.6  as  sw6
  IO0DIR &=~sw7;  //P0.7  as  sw7
  IO0DIR &=~sw8;  //P0.8  as  sw8
  IO0DIR &=~sw9;  //P0.9  as  sw9

  while(1)
  {
    if( (IO0PIN & sw0) == 0 ) //  sw0 ? 0
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[0]<<17;
    }
//
    else if ( (IO0PIN & sw1) == 0 ) // sw1  ? 0
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[1]<<17;
    }
//
    else if ( (IO0PIN & sw2) == 0 ) // sw2  ? 0
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[2]<<17;
    }
//
    else if ( (IO0PIN & sw3) == 0 ) // sw3  ? 0
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[3]<<17;
    }
//
    else if ( (IO0PIN & sw4) == 0 ) // sw4  ? 0
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[4]<<17;
    }
//
    else if ( (IO0PIN & sw5) == 0 ) // sw5  ? 0
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[5]<<17;
    }
//
    else if ( (IO0PIN & sw6) == 0 ) // sw6  ? 0
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[6]<<17;
    }
//
    else if ( (IO0PIN & sw7) == 0 ) // sw7  ? 0
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[7]<<17;
    }
//
    else if ( (IO0PIN & sw8) == 0 ) // sw8  ? 0
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[8]<<17;
    }
//
    else if ( (IO0PIN & sw9) == 0 ) // sw9  ? 0
    {
    }
    IO0CLR  |=dir;
    IO0SET  |=BCD[9]<<17;
//
    else  //  Error or Empty
    {
      IO0CLR  |=dir;
      IO0SET  |=BCD[10]<<17;
    }
  }
}
