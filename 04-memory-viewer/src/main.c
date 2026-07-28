#include <stdint.h>
#include <stdio.h>

#include "memory_viewer.h"

static void show_menu(void);
static void clear_input_buffer(void);
static int read_integer(const char *message, int *value);
static int read_float(const char *message, float *value);
static int read_double(const char *message, double *value);

typedef enum
{
    MENU_EXIT = 0,
    MENU_INSPECT_INTEGER = 1,
    MENU_INSPECT_FLOAT,
    MENU_INSPECT_DOUBLE,
    MENU_INSPECT_CHARACTER,
    MENU_SHOW_ENDIANNESS
} MenuOption;

int main(void)
{
    int selected_option = -1;

    int integer_value = 0;
    float float_value = 0.0F;
    double double_value = 0.0;
    char character_value = '\0';

    do
    {
        show_menu();

        if (!read_integer(
                "Select an option: ",
                &selected_option
            ))
        {
            printf(
                "Invalid option. Enter an integer.\n\n"
            );

            continue;
        }

        switch ((MenuOption)selected_option)
        {
            case MENU_INSPECT_INTEGER:
                if (read_integer(
                        "Enter an integer value: ",
                        &integer_value
                    ))
                {
                    inspect_memory(
                        "integer_value",
                        &integer_value,
                        sizeof(integer_value)
                    );
                }
                else
                {
                    printf("Invalid integer value.\n\n");
                }
                break;

            case MENU_INSPECT_FLOAT:
                if (read_float(
                        "Enter a float value: ",
                        &float_value
                    ))
                {
                    inspect_memory(
                        "float_value",
                        &float_value,
                        sizeof(float_value)
                    );
                }
                else
                {
                    printf("Invalid float value.\n\n");
                }
                break;

            case MENU_INSPECT_DOUBLE:
                if (read_double(
                        "Enter a double value: ",
                        &double_value
                    ))
                {
                    inspect_memory(
                        "double_value",
                        &double_value,
                        sizeof(double_value)
                    );
                }
                else
                {
                    printf("Invalid double value.\n\n");
                }
                break;

            case MENU_INSPECT_CHARACTER:
                printf("Enter a character: ");

                if (scanf(" %c", &character_value) == 1)
                {
                    clear_input_buffer();

                    inspect_memory(
                        "character_value",
                        &character_value,
                        sizeof(character_value)
                    );
                }
                else
                {
                    clear_input_buffer();

                    printf(
                        "Invalid character value.\n\n"
                    );
                }
                break;

            case MENU_SHOW_ENDIANNESS:
                if (is_little_endian())
                {
                    printf(
                        "\nSystem byte order: little-endian\n\n"
                    );
                }
                else
                {
                    printf(
                        "\nSystem byte order: big-endian\n\n"
                    );
                }
                break;

            case MENU_EXIT:
                printf("Closing Memory Viewer.\n");
                break;

            default:
                printf(
                    "The selected option does not exist.\n\n"
                );
                break;
        }

    } while (selected_option != MENU_EXIT);

    return 0;
}

static void show_menu(void)
{
    printf("========================================\n");
    printf("             MEMORY VIEWER\n");
    printf("========================================\n");
    printf("1. Inspect an int\n");
    printf("2. Inspect a float\n");
    printf("3. Inspect a double\n");
    printf("4. Inspect a char\n");
    printf("5. Detect system endianness\n");
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
         * Discard the remaining characters.
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

static int read_float(
    const char *message,
    float *value
)
{
    if (message == NULL || value == NULL)
    {
        return 0;
    }

    printf("%s", message);

    if (scanf("%f", value) != 1)
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