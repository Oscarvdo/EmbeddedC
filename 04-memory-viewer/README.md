# Embedded C Lab 04 — Memory Viewer

A command-line memory inspection tool written in C.

This project is the fourth lab in the **Embedded C Labs** series. It explores how variables are stored in memory, how pointers reference addresses, how `sizeof` reports object sizes, and how byte order affects multi-byte values.

## Features

- Inspect an `int`
- Inspect a `float`
- Inspect a `double`
- Inspect a `char`
- Display memory addresses
- Display object sizes
- Display each byte in hexadecimal
- Display each byte in decimal
- Detect little-endian or big-endian byte order

## Concepts Practiced

- Memory addresses
- Pointers
- The address-of operator `&`
- Pointer casting
- Generic pointers with `void *`
- Read-only pointers with `const`
- Fixed-width integers
- Byte-level memory access
- The `sizeof` operator
- Little-endian and big-endian storage
- Modular programming
- Input validation

## Project Structure

```text
04-memory-viewer/
├── include/
│   └── memory_viewer.h
├── src/
│   ├── main.c
│   └── memory_viewer.c
└── README.md
```

## Build

Compile with GCC:

```bash
gcc src/main.c src/memory_viewer.c -Iinclude -Wall -Wextra -Wpedantic -std=c11 -o memory_viewer.exe
```

## Run

Windows PowerShell:

```powershell
.\memory_viewer.exe
```

Linux or macOS:

```bash
./memory_viewer
```

## Example

```text
========================================
             MEMORY VIEWER
========================================
1. Inspect an int
2. Inspect a float
3. Inspect a double
4. Inspect a char
5. Detect system endianness
0. Exit
========================================

Select an option: 1
Enter an integer value: 305419896

Variable: integer_value
Address : 0000008A9F3FF9C4
Size    : 4 byte(s)
----------------------------------------
Byte 0 | Value: 0x78 | Decimal: 120
Byte 1 | Value: 0x56 | Decimal:  86
Byte 2 | Value: 0x34 | Decimal:  52
Byte 3 | Value: 0x12 | Decimal:  18
```

## Endianness

The hexadecimal number:

```text
0x12345678
```

contains four bytes:

```text
12 34 56 78
```

A little-endian machine stores the least significant byte first:

```text
78 56 34 12
```

A big-endian machine stores the most significant byte first:

```text
12 34 56 78
```

## Embedded Systems Relevance

Firmware frequently interacts directly with memory-mapped registers, communication buffers, sensor data, and binary protocols.

Understanding memory layout is necessary when:

- Reading device registers
- Parsing UART or SPI messages
- Processing CAN frames
- Reading binary files
- Converting network packets
- Working with DMA buffers
- Debugging embedded software
- Sharing data between different processors

## Future Improvements

- Inspect arrays
- Inspect structures
- Display binary values
- Support hexadecimal user input
- Compare signed and unsigned values
- Demonstrate structure padding
- Add a memory dump format
- Add automated tests

## License

MIT License