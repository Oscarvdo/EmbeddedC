#include <stddef.h>

#include "calculator.h"

double add(double first_number, double second_number)
{
    return first_number + second_number;
}

double subtract(double first_number, double second_number)
{
    return first_number - second_number;
}

double multiply(double first_number, double second_number)
{
    return first_number * second_number;
}

int divide_numbers(
    double dividend,
    double divisor,
    double *result
)
{
    if (result == NULL)
    {
        return 0;
    }

    if (divisor == 0.0)
    {
        return 0;
    }

    *result = dividend / divisor;

    return 1;
}

double celsius_to_fahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

double psi_to_bar(double psi)
{
    return psi * 0.0689476;
}

double liters_per_minute_to_cubic_meters_per_hour(
    double liters_per_minute
)
{
    return liters_per_minute * 0.06;
}