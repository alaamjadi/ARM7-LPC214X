# ARM7 LPC214x Microcontroller Examples

This repository contains a collection of example projects originally developed in 2012 for an introductory ARM programming course at IAUCTB. The examples were designed to teach fundamental concepts of microcontroller programming using the ARM7 LPC214x series. These examples demonstrate various GPIO operations, from basic LED control to seven-segment display implementations, using different programming approaches that progressively increase in complexity.

## Project Structure

The repository is organized into eight progressive examples:

1. **Basic Switch & LED Control** (E01)

   - Simple GPIO operations with one switch controlling two LEDs
   - Direct port manipulation
   - Basic input/output concepts

2. **Dual Switch & LED Control** (E02)

   - Independent control of two LEDs using two switches
   - Multiple GPIO input/output handling

3. **Seven Segment Display Basic** (E03)

   - 7-segment display control using macros
   - Multiple switch inputs
   - BCD to 7-segment conversion

4. **Single Switch & LED Macro** (E04)

   - LED control using macro definitions
   - Improved code organization

5. **Dual Switch & LED Macro** (E05)

   - Extended macro usage for multiple I/O
   - More complex logic handling

6. **Single Switch & LED Library** (E06)

   - Introduction to custom libraries
   - Modular code structure
   - Hardware abstraction layer basics

7. **Dual Switch & LED Library** (E07)

   - Extended library implementation
   - Multiple device handling
   - Clean code architecture

8. **Seven Segment Display Library** (E08)
   - Complete library-based implementation
   - Advanced hardware abstraction
   - Modular and reusable code

## Development Environment

### Required Software

- IAR Embedded Workbench for ARM 8.22.1 or later
- NI Circuit Design Suite v14.0.1 or later
- Proteus Pro 8.6 SP3 or later

### Hardware Support

The examples are tested on the NXP LPC2148 microcontroller and are compatible with the LPC2130~LPC2148 family.

## Prerequisites

### Software Requirements

- IAR Embedded Workbench for ARM (recommended) or equivalent ARM toolchain
- One of the following simulation tools:
  - Proteus Design Suite (for circuit simulation)
  - NI Circuit Design Suite (for circuit simulation)

### Optional Hardware

- LPC214x development board (optional, for physical testing)

### Knowledge Requirements

- Basic understanding of C programming
- Knowledge of GPIO concepts
- Familiarity with digital circuit simulation tools

## Getting Started

### For Simulation Testing

1. Clone this repository
2. Open the desired example project in IAR Embedded Workbench
3. Build the project
4. Set up the circuit in Proteus or NI Circuit Design Suite:
   - Create new schematic
   - Add LPC2148 microcontroller
   - Connect LEDs, switches, or 7-segment display as per example
   - Import the compiled binary
   - Run simulation

### For Hardware Testing (Optional)

1. Clone this repository
2. Open the desired example project in IAR Embedded Workbench
3. Build the project
4. Flash the compiled binary to your LPC214x board
5. Connect the hardware components according to pin definitions

## Hardware Setup

### LED Projects (E01, E02, E04, E05, E06, E07)

- LEDs connected to specified GPIO pins (see individual project documentation)
- Switches connected to specified input pins
- Proper current-limiting resistors for LEDs

### Seven Segment Display Projects (E03, E08)

- Common cathode 7-segment display
- Connected to P1.17 through P1.23
- Input switches for digit selection

## Proteus Simulation Setup

1. Open Proteus Design Suite
2. Add the microprocessor: Library => Microprocessor ICs => LPC => 2148
3. Connect components according to the pin configurations in each example

## GPIO Programming Guide

### Register Operations

```c
// Set bit n to 1
R |= (1UL << n);    // UL ensures 32-bit operation

// Clear bit n to 0
R &= ~(1UL << n);
```

### Pin Direction Control

Using IOxDIR registers (x = 0 or 1 for respective ports):

```c
// Configure pin as output
IO0DIR |= (1UL << 3);    // P0.3 as output
IO1DIR |= (1UL << 8);    // P1.8 as output

// Configure pin as input
IO0DIR &= ~(1UL << 2);   // P0.2 as input
IO1DIR &= ~(1UL << 4);   // P1.4 as input
```

### Pin Value Control

```c
// Set pin to high (3.3V)
IO0SET |= (1UL << pinNumber);

// Set pin to low (0V)
IO0CLR |= (1UL << pinNumber);
```

## Contributing

Contributions are welcome! Please feel free to submit pull requests with improvements or additional examples.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Support

For questions or issues, please open an issue in the repository.
