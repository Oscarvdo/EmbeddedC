# Embedded C Lab 03 — Bitwise Register Calculator

A command-line calculator for learning bitwise operations and 8-bit register manipulation in C.

This project is the third lab in the **Embedded C Labs** series. It introduces fixed-width integer types, binary masks, bit manipulation, hexadecimal representation, shifting operations, and register-style programming.

## Features

- Bitwise AND
- Bitwise OR
- Bitwise XOR
- Bitwise NOT
- Left shift
- Right shift
- Set a specific bit
- Clear a specific bit
- Toggle a specific bit
- Read a specific bit
- Decimal display
- Hexadecimal display
- Binary display

## Concepts Practiced

- Fixed-width integers with `uint8_t`
- Binary numbers
- Hexadecimal numbers
- Bit masks
- Bitwise AND: `&`
- Bitwise OR: `|`
- Bitwise XOR: `^`
- Bitwise NOT: `~`
- Left shift: `<<`
- Right shift: `>>`
- Enumerations
- Pointer output parameters
- Input validation
- Modular programming

## Project Structure

```text
03-bitwise-register-calculator/
├── include/
│   └── bitwise.h
├── src/
│   ├── bitwise.c
│   └── main.c
└── README.md
```

## Build

Compile with GCC:

```bash
gcc src/main.c src/bitwise.c -Iinclude -Wall -Wextra -Wpedantic -std=c11 -o bitwise_calculator.exe
```

## Run

Windows PowerShell:

```powershell
.\bitwise_calculator.exe
```

Linux or macOS:

```bash
./bitwise_calculator
```

## Example

```text
========================================
     BITWISE REGISTER CALCULATOR
========================================
1. AND
2. OR
3. XOR
4. NOT
5. Shift left
6. Shift right
7. Set bit
8. Clear bit
9. Toggle bit
10. Read bit
0. Exit
========================================

Select an option: 7
Enter a value (0-255): 0
Enter bit position (0-7): 3

Original value | Decimal:   0 | Hex: 0x00 | Binary: 00000000
Set-bit result | Decimal:   8 | Hex: 0x08 | Binary: 00001000
```

## Embedded Systems Relevance

Microcontrollers use hardware registers to control peripherals.

A hypothetical register might look like this:

```text
Bit 7: Interrupt enabled
Bit 6: Error flag
Bit 5: Transmitter enabled
Bit 4: Receiver enabled
Bit 3: Device ready
Bit 2: Reserved
Bit 1: Mode selection
Bit 0: Power enabled
```

Activating bit 0 could enable the device:

```c
register_value |= (1U << 0);
```

Clearing bit 4 could disable the receiver:

```c
register_value &= ~(1U << 4);
```

Reading bit 6 could detect an error:

```c
error_flag = (register_value >> 6) & 1U;
```

## Future Improvements

- Support 16-bit registers
- Support 32-bit registers
- Add named register flags
- Add a simulated device status register
- Add binary input
- Add hexadecimal input
- Add automated unit tests
- Add register configuration files

## License

MIT License