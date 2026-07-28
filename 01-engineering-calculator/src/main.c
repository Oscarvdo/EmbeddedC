#include <stdio.h>

#include "calculator.h"

static void show_menu(void);
static void clear_input_buffer(void);

static int read_integer(
    const char *message,
    int *value
);

static int read_double(
    const char *message,
    double *value
);

int main(void)
{
    int option = -1;

    double first_value = 0.0;
    double second_value = 0.0;
    double result = 0.0;

    do
    {
        show_menu();

        if (!read_integer("Select an option: ", &option))
        {
            printf("Invalid option. Enter an integer.\n\n");
            continue;
        }

        switch (option)
        {
            case 1:
                if (
                    read_double(
                        "Enter the first number: ",
                        &first_value
                    )
                    &&
                    read_double(
                        "Enter the second number: ",
                        &second_value
                    )
                )
                {
                    result = add(first_value, second_value);
                    printf("Result: %.4f\n\n", result);
                }
                break;

            case 2:
                if (
                    read_double(
                        "Enter the first number: ",
                        &first_value
                    )
                    &&
                    read_double(
                        "Enter the second number: ",
                        &second_value
                    )
                )
                {
                    result = subtract(
                        first_value,
                        second_value
                    );

                    printf("Result: %.4f\n\n", result);
                }
                break;

            case 3:
                if (
                    read_double(
                        "Enter the first number: ",
                        &first_value
                    )
                    &&
                    read_double(
                        "Enter the second number: ",
                        &second_value
                    )
                )
                {
                    result = multiply(
                        first_value,
                        second_value
                    );

                    printf("Result: %.4f\n\n", result);
                }
                break;

            case 4:
                if (
                    read_double(
                        "Enter the dividend: ",
                        &first_value
                    )
                    &&
                    read_double(
                        "Enter the divisor: ",
                        &second_value
                    )
                )
                {
                    if (
                        divide_numbers(
                            first_value,
                            second_value,
                            &result
                        )
                    )
                    {
                        printf("Result: %.4f\n\n", result);
                    }
                    else
                    {
                        printf(
                            "Error: division by zero "
                            "is not allowed.\n\n"
                        );
                    }
                }
                break;

            case 5:
                if (
                    read_double(
                        "Enter temperature in Celsius: ",
                        &first_value
                    )
                )
                {
                    result =
                        celsius_to_fahrenheit(first_value);

                    printf(
                        "%.2f C = %.2f F\n\n",
                        first_value,
                        result
                    );
                }
                break;

            case 6:
                if (
                    read_double(
                        "Enter pressure in PSI: ",
                        &first_value
                    )
                )
                {
                    result = psi_to_bar(first_value);

                    printf(
                        "%.2f PSI = %.4f bar\n\n",
                        first_value,
                        result
                    );
                }
                break;

            case 7:
                if (
                    read_double(
                        "Enter flow in L/min: ",
                        &first_value
                    )
                )
                {
                    result =
                        liters_per_minute_to_cubic_meters_per_hour(
                            first_value
                        );

                    printf(
                        "%.2f L/min = %.4f m3/h\n\n",
                        first_value,
                        result
                    );
                }
                break;

            case 0:
                printf(
                    "Closing Engineering Calculator.\n"
                );
                break;

            default:
                printf(
                    "Invalid option. Try again.\n\n"
                );
                break;
        }

    } while (option != 0);

    return 0;
}

static void show_menu(void)
{
    printf("====================================\n");
    printf("      ENGINEERING CALCULATOR\n");
    printf("====================================\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. PSI to bar\n");
    printf("7. L/min to m3/h\n");
    printf("0. Exit\n");
    printf("====================================\n");
}

static void clear_input_buffer(void)
{
    int character = 0;

    while (
        (character = getchar()) != '\n'
        &&
        character != EOF
    )
    {
        /* Discard the remaining input. */
    }
}

static int read_integer(
    const char *message,
    int *value
)
{
    if (message == NULL || value == NULL)
    {
        return 0;
    }

    printf("%s", message);

    if (scanf("%d", value) != 1)
    {
        clear_input_buffer();
        return 0;
    }

    clear_input_buffer();

    return 1;
}

static int read_double(
    const char *message,
    double *value
)
{
    if (message == NULL || value == NULL)
    {
        return 0;
    }

    printf("%s", message);

    if (scanf("%lf", value) != 1)
    {
        printf(
            "Invalid input. Enter a numeric value.\n"
        );

        clear_input_buffer();

        return 0;
    }

    clear_input_buffer();

    return 1;
}