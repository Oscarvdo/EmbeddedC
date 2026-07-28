#ifndef CALCULATOR_H
#define CALCULATOR_H

double add(double first_number, double second_number);
double subtract(double first_number, double second_number);
double multiply(double first_number, double second_number);

int divide_numbers(
    double dividend,
    double divisor,
    double *result
);

double celsius_to_fahrenheit(double celsius);
double psi_to_bar(double psi);

double liters_per_minute_to_cubic_meters_per_hour(
    double liters_per_minute
);

#endif