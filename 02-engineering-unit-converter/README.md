# Embedded C Lab 02 — Engineering Unit Converter

A modular command-line unit converter written in C.

This project is the second lab in the **Embedded C Labs** series. It introduces enumerations, status codes, constants, switch statements, pointer-based outputs, and modular software organization.

## Features

The program supports the following conversions:

- Celsius to Fahrenheit
- Fahrenheit to Celsius
- PSI to bar
- bar to PSI
- Liters per minute to cubic meters per hour
- Cubic meters per hour to liters per minute
- Inches to millimeters
- Millimeters to inches

## Concepts Practiced

- Enumerations with `enum`
- Type aliases with `typedef`
- Constants with `const`
- Internal module variables with `static`
- Switch statements
- Pointer output parameters
- Status return codes
- Input validation
- Header files
- Multiple source files
- Modular programming

## Project Structure

```text
02-engineering-unit-converter/
├── include/
│   └── unit_converter.h
├── src/
│   ├── main.c
│   └── unit_converter.c
└── README.md
```

## Build

Compile with GCC:

```bash
gcc src/main.c src/unit_converter.c -Iinclude -Wall -Wextra -Wpedantic -std=c11 -o unit_converter.exe
```

## Run

Windows PowerShell:

```powershell
.\unit_converter.exe
```

Linux or macOS:

```bash
./unit_converter
```

## Example

```text
========================================
      ENGINEERING UNIT CONVERTER
========================================
1. Celsius to Fahrenheit
2. Fahrenheit to Celsius
3. PSI to bar
4. bar to PSI
5. L/min to m3/h
6. m3/h to L/min
7. Inches to millimeters
8. Millimeters to inches
0. Exit
========================================

Select a conversion: 3
Enter the value to convert: 14.7

14.7000 PSI = 1.0135 bar
```

## Design

The application is separated into three components:

- `main.c` handles the user interface and input validation.
- `unit_converter.c` contains the conversion logic.
- `unit_converter.h` defines the public interface of the conversion module.

The conversion function returns a status code and writes the converted value through a pointer:

```c
ConverterStatus convert_unit(
    ConversionType type,
    double input,
    double *output
);
```

## Future Improvements

- Add mass conversions
- Add electrical engineering units
- Add flow-unit conversions
- Add configuration files
- Add automated unit tests
- Add conversion history
- Support command-line arguments

## License

MIT License