#include <stdio.h>

#include "unit_converter.h"

/*
 * Prototipos de funciones privadas de main.c.
 *
 * static significa que estas funciones solamente pueden
 * utilizarse dentro de este archivo.
 */
static void show_menu(void);
static void clear_input_buffer(void);
static int read_integer(const char *message, int *value);
static int read_double(const char *message, double *value);

int main(void)
{
    int selected_option = -1;
    double input_value = 0.0;
    double output_value = 0.0;

    ConversionType conversion_type;
    ConverterStatus conversion_status;

    do
    {
        show_menu();

        if (!read_integer(
                "Select a conversion: ",
                &selected_option
            ))
        {
            printf(
                "Invalid option. Enter an integer.\n\n"
            );

            continue;
        }

        if (selected_option == 0)
        {
            printf("Closing Engineering Unit Converter.\n");
            break;
        }

        if (
            selected_option <
                CONVERSION_CELSIUS_TO_FAHRENHEIT
            ||
            selected_option >
                CONVERSION_MILLIMETERS_TO_INCHES
        )
        {
            printf(
                "The selected conversion does not exist.\n\n"
            );

            continue;
        }

        conversion_type = (ConversionType)selected_option;

        if (!read_double(
                "Enter the value to convert: ",
                &input_value
            ))
        {
            printf(
                "Invalid value. Enter a numeric value.\n\n"
            );

            continue;
        }

        conversion_status = convert_unit(
            conversion_type,
            input_value,
            &output_value
        );

        if (conversion_status == CONVERTER_SUCCESS)
        {
            printf(
                "\n%.4f %s = %.4f %s\n\n",
                input_value,
                get_input_unit(conversion_type),
                output_value,
                get_output_unit(conversion_type)
            );
        }
        else
        {
            printf(
                "The conversion could not be completed.\n\n"
            );
        }

    } while (selected_option != 0);

    return 0;
}

static void show_menu(void)
{
    printf("========================================\n");
    printf("      ENGINEERING UNIT CONVERTER\n");
    printf("========================================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. PSI to bar\n");
    printf("4. bar to PSI\n");
    printf("5. L/min to m3/h\n");
    printf("6. m3/h to L/min\n");
    printf("7. Inches to millimeters\n");
    printf("8. Millimeters to inches\n");
    printf("0. Exit\n");
    printf("========================================\n");
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
        /*
         * El cuerpo está vacío porque solamente queremos
         * extraer y descartar los caracteres restantes.
         */
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
        clear_input_buffer();
        return 0;
    }

    clear_input_buffer();

    return 1;
}