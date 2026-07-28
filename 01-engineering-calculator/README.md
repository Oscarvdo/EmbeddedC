# Engineering Calculator

A command-line engineering calculator written in ANSI C.

This project is the first lab in the **Embedded C Labs** series. It focuses on the fundamentals of the C programming language while introducing basic software modularization and engineering unit conversions.

---

## Features

- Addition
- Subtraction
- Multiplication
- Division with error handling
- Celsius to Fahrenheit conversion
- PSI to Bar conversion
- Liters/minute to Cubic meters/hour conversion

---

## Concepts Practiced

- Variables
- Functions
- Header files
- Source files
- Modular programming
- Function prototypes
- Input validation
- Pointer parameters
- Conditional statements
- Loops
- Basic engineering calculations

---

## Project Structure

```
01-engineering-calculator/
│
├── include/
│   └── calculator.h
│
├── src/
│   ├── calculator.c
│   └── main.c
│
└── README.md
```

---

## Build

Compile using GCC:

```bash
gcc src/main.c src/calculator.c -Iinclude -Wall -Wextra -Wpedantic -std=c11 -o engineering_calculator.exe
```

Run:

```bash
./engineering_calculator.exe
```

Windows PowerShell:

```powershell
.\engineering_calculator.exe
```

---

## Example

```
====================================
      ENGINEERING CALCULATOR
====================================

1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Celsius to Fahrenheit
6. PSI to Bar
7. L/min to m³/h
0. Exit

Select an option: 6

Enter pressure in PSI:
14.7

14.70 PSI = 1.0135 bar
```

---

## Learning Objectives

After completing this project, the following topics should be understood:

- Creating and using functions
- Organizing code into multiple source files
- Header file usage
- Basic pointer usage
- Returning values through pointers
- Input validation
- Separating interface from implementation

---

## Future Improvements

- Scientific functions
- History of calculations
- Configuration file
- Unit tests
- Menu navigation with keyboard shortcuts
- Additional engineering conversions

---

## License

MIT License