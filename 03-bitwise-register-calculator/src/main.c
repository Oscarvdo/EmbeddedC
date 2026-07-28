#include <stdint.h>
#include <stdio.h>

#include "bitwise.h"

/*
 * Opciones disponibles en el menú.
 */
typedef enum
{
    MENU_EXIT = 0,
    MENU_AND = 1,
    MENU_OR,
    MENU_XOR,
    MENU_NOT,
    MENU_SHIFT_LEFT,
    MENU_SHIFT_RIGHT,
    MENU_SET_BIT,
    MENU_CLEAR_BIT,
    MENU_TOGGLE_BIT,
    MENU_READ_BIT
} MenuOption;

/*
 * Funciones privadas de main.c.
 */
static void show_menu(void);
static void clear_input_buffer(void);

static int read_integer(
    const char *message,
    int *value
);

static int read_uint8(
    const char *message,
    uint8_t *value
);

static void print_value(
    const char *label,
    uint8_t value
);

int main(void)
{
    int selected_option = -1;

    uint8_t first_value = 0U;
    uint8_t second_value = 0U;
    uint8_t result = 0U;
    uint8_t position = 0U;
    uint8_t bit_value = 0U;

    BitwiseStatus status = BITWISE_ERROR;

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
            case MENU_AND:
                if (
                    read_uint8(
                        "Enter the first value (0-255): ",
                        &first_value
                    )
                    &&
                    read_uint8(
                        "Enter the second value (0-255): ",
                        &second_value
                    )
                )
                {
                    result = bitwise_and(
                        first_value,
                        second_value
                    );

                    print_value("First value ", first_value);
                    print_value("Second value", second_value);
                    print_value("AND result  ", result);
                }
                break;

            case MENU_OR:
                if (
                    read_uint8(
                        "Enter the first value (0-255): ",
                        &first_value
                    )
                    &&
                    read_uint8(
                        "Enter the second value (0-255): ",
                        &second_value
                    )
                )
                {
                    result = bitwise_or(
                        first_value,
                        second_value
                    );

                    print_value("First value ", first_value);
                    print_value("Second value", second_value);
                    print_value("OR result   ", result);
                }
                break;

            case MENU_XOR:
                if (
                    read_uint8(
                        "Enter the first value (0-255): ",
                        &first_value
                    )
                    &&
                    read_uint8(
                        "Enter the second value (0-255): ",
                        &second_value
                    )
                )
                {
                    result = bitwise_xor(
                        first_value,
                        second_value
                    );

                    print_value("First value ", first_value);
                    print_value("Second value", second_value);
                    print_value("XOR result  ", result);
                }
                break;

            case MENU_NOT:
                if (
                    read_uint8(
                        "Enter a value (0-255): ",
                        &first_value
                    )
                )
                {
                    result = bitwise_not(first_value);

                    print_value("Original value", first_value);
                    print_value("NOT result    ", result);
                }
                break;

            case MENU_SHIFT_LEFT:
                if (
                    read_uint8(
                        "Enter a value (0-255): ",
                        &first_value
                    )
                    &&
                    read_uint8(
                        "Enter shift positions (0-7): ",
                        &position
                    )
                )
                {
                    if (position > 7U)
                    {
                        printf(
                            "Position must be between 0 and 7.\n\n"
                        );

                        break;
                    }

                    result = shift_left(
                        first_value,
                        position
                    );

                    print_value("Original value", first_value);
                    print_value("Shift result  ", result);
                }
                break;

            case MENU_SHIFT_RIGHT:
                if (
                    read_uint8(
                        "Enter a value (0-255): ",
                        &first_value
                    )
                    &&
                    read_uint8(
                        "Enter shift positions (0-7): ",
                        &position
                    )
                )
                {
                    if (position > 7U)
                    {
                        printf(
                            "Position must be between 0 and 7.\n\n"
                        );

                        break;
                    }

                    result = shift_right(
                        first_value,
                        position
                    );

                    print_value("Original value", first_value);
                    print_value("Shift result  ", result);
                }
                break;

            case MENU_SET_BIT:
                if (
                    read_uint8(
                        "Enter a value (0-255): ",
                        &first_value
                    )
                    &&
                    read_uint8(
                        "Enter bit position (0-7): ",
                        &position
                    )
                )
                {
                    status = set_bit(
                        first_value,
                        position,
                        &result
                    );

                    if (status == BITWISE_SUCCESS)
                    {
                        print_value(
                            "Original value",
                            first_value
                        );

                        print_value(
                            "Set-bit result",
                            result
                        );
                    }
                    else
                    {
                        printf(
                            "Invalid bit position.\n\n"
                        );
                    }
                }
                break;

            case MENU_CLEAR_BIT:
                if (
                    read_uint8(
                        "Enter a value (0-255): ",
                        &first_value
                    )
                    &&
                    read_uint8(
                        "Enter bit position (0-7): ",
                        &position
                    )
                )
                {
                    status = clear_bit(
                        first_value,
                        position,
                        &result
                    );

                    if (status == BITWISE_SUCCESS)
                    {
                        print_value(
                            "Original value  ",
                            first_value
                        );

                        print_value(
                            "Clear-bit result",
                            result
                        );
                    }
                    else
                    {
                        printf(
                            "Invalid bit position.\n\n"
                        );
                    }
                }
                break;

            case MENU_TOGGLE_BIT:
                if (
                    read_uint8(
                        "Enter a value (0-255): ",
                        &first_value
                    )
                    &&
                    read_uint8(
                        "Enter bit position (0-7): ",
                        &position
                    )
                )
                {
                    status = toggle_bit(
                        first_value,
                        position,
                        &result
                    );

                    if (status == BITWISE_SUCCESS)
                    {
                        print_value(
                            "Original value   ",
                            first_value
                        );

                        print_value(
                            "Toggle-bit result",
                            result
                        );
                    }
                    else
                    {
                        printf(
                            "Invalid bit position.\n\n"
                        );
                    }
                }
                break;

            case MENU_READ_BIT:
                if (
                    read_uint8(
                        "Enter a value (0-255): ",
                        &first_value
                    )
                    &&
                    read_uint8(
                        "Enter bit position (0-7): ",
                        &position
                    )
                )
                {
                    status = read_bit(
                        first_value,
                        position,
                        &bit_value
                    );

                    if (status == BITWISE_SUCCESS)
                    {
                        print_value(
                            "Value",
                            first_value
                        );

                        printf(
                            "Bit %u contains: %u\n\n",
                            (unsigned int)position,
                            (unsigned int)bit_value
                        );
                    }
                    else
                    {
                        printf(
                            "Invalid bit position.\n\n"
                        );
                    }
                }
                break;

            case MENU_EXIT:
                printf(
                    "Closing Bitwise Register Calculator.\n"
                );
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
    printf("     BITWISE REGISTER CALCULATOR\n");
    printf("========================================\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. NOT\n");
    printf("5. Shift left\n");
    printf("6. Shift right\n");
    printf("7. Set bit\n");
    printf("8. Clear bit\n");
    printf("9. Toggle bit\n");
    printf("10. Read bit\n");
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
         * Discard remaining input.
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

static int read_uint8(
    const char *message,
    uint8_t *value
)
{
    unsigned int temporary_value = 0U;

    if (message == NULL || value == NULL)
    {
        return 0;
    }

    printf("%s", message);

    if (scanf("%u", &temporary_value) != 1)
    {
        clear_input_buffer();
        return 0;
    }

    clear_input_buffer();

    if (temporary_value > 255U)
    {
        printf(
            "The value must be between 0 and 255.\n"
        );

        return 0;
    }

    *value = (uint8_t)temporary_value;

    return 1;
}

static void print_value(
    const char *label,
    uint8_t value
)
{
    printf(
        "%s | Decimal: %3u | Hex: 0x%02X | Binary: ",
        label,
        (unsigned int)value,
        (unsigned int)value
    );

    print_binary_uint8(value);

    printf("\n");
}