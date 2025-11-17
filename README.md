# LCD_Scrolling_Bar

A simple AVR microcontroller project for the ATmega328P that displays a scrolling animation on a 16x2 character LCD. The animation consists of a right-pointing arrow (`>`) followed by a solid block (`■`) that moves across the top row of the display.

## Features
- Initializes the ATmega328P clock to run at full speed (no prescaling).
- Uses the `alcd.h` library for LCD interfacing (assumes 4-bit or 8-bit mode as configured).
- Displays a moving block animation from left to right.
- Clears the line after each animation cycle.

## Hardware Requirements
- ATmega328P microcontroller (e.g., Arduino Uno without bootloader)
- 16x2 Character LCD (HD44780-compatible)
- Appropriate wiring for LCD (data lines, RS, E, and optionally RW grounded)
- 16 MHz crystal (or internal oscillator, depending on fuse settings)
- Power supply and decoupling capacitors

## Software Dependencies
- AVR-GCC toolchain
- `mega328p.h` (AVR device header)
- `alcd.h` – custom or third-party LCD library compatible with CodeVisionAVR or similar
- `delay.h` – for millisecond delays

## How It Works
1. The system clock is set to run at full speed by clearing all CLKPS bits.
2. The LCD is initialized for a 16-character width.
3. In the main loop:
   - A `>` character is printed at position (0,0).
   - A solid block (`0xFF`, typically mapped to a filled character in HD44780 CGRAM) moves from column 1 to 15.
   - Each movement step is delayed by 500 ms.
   - After reaching the end, the display pauses for 1 second.
   - The top row is cleared, and the animation repeats.

## Notes
- Ensure the `alcd.h` library is properly configured for your hardware pinout.
- The solid block (`0xFF`) appearance depends on the LCD’s built-in character map. On many HD44780 displays, `0xFF` shows as a fully filled 5x8 dot block.
- Fuse bits should be set appropriately (e.g., external crystal if used).

## Build & Flash
Compile with an AVR-compatible IDE or Makefile (e.g., CodeVisionAVR, AVR-GCC).  
Flash the resulting `.hex` file using a programmer (e.g., USBasp, AVRISP).

---

**Author:** Sarvenaz 
**Date:** November 17, 2025
