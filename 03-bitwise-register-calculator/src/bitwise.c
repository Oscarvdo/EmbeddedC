#include <stddef.h>
#include <stdio.h>

#include "bitwise.h"

/*
 * Cantidad de bits de un uint8_t.
 */
#define UINT8_BIT_COUNT 8U

/*
 * Comprueba si una posición de bit está entre 0 y 7.
 */
static int is_valid_bit_position(uint8_t position)
{
    return position < UINT8_BIT_COUNT;
}

uint8_t bitwise_and(
    uint8_t first_value,
    uint8_t second_value
)
{
    return (uint8_t)(first_value & second_value);
}

uint8_t bitwise_or(
    uint8_t first_value,
    uint8_t second_value
)
{
    return (uint8_t)(first_value | second_value);
}

uint8_t bitwise_xor(
    uint8_t first_value,
    uint8_t second_value
)
{
    return (uint8_t)(first_value ^ second_value);
}

uint8_t bitwise_not(uint8_t value)
{
    return (uint8_t)(~value);
}

uint8_t shift_left(
    uint8_t value,
    uint8_t positions
)
{
    if (positions >= UINT8_BIT_COUNT)
    {
        return 0U;
    }

    return (uint8_t)(value << positions);
}

uint8_t shift_right(
    uint8_t value,
    uint8_t positions
)
{
    if (positions >= UINT8_BIT_COUNT)
    {
        return 0U;
    }

    return (uint8_t)(value >> positions);
}

BitwiseStatus set_bit(
    uint8_t value,
    uint8_t position,
    uint8_t *result
)
{
    uint8_t mask = 0U;

    if (result == NULL)
    {
        return BITWISE_ERROR;
    }

    if (!is_valid_bit_position(position))
    {
        return BITWISE_ERROR;
    }

    mask = (uint8_t)(1U << position);

    *result = (uint8_t)(value | mask);

    return BITWISE_SUCCESS;
}

BitwiseStatus clear_bit(
    uint8_t value,
    uint8_t position,
    uint8_t *result
)
{
    uint8_t mask = 0U;

    if (result == NULL)
    {
        return BITWISE_ERROR;
    }

    if (!is_valid_bit_position(position))
    {
        return BITWISE_ERROR;
    }

    mask = (uint8_t)(1U << position);

    *result = (uint8_t)(value & (uint8_t)(~mask));

    return BITWISE_SUCCESS;
}

BitwiseStatus toggle_bit(
    uint8_t value,
    uint8_t position,
    uint8_t *result
)
{
    uint8_t mask = 0U;

    if (result == NULL)
    {
        return BITWISE_ERROR;
    }

    if (!is_valid_bit_position(position))
    {
        return BITWISE_ERROR;
    }

    mask = (uint8_t)(1U << position);

    *result = (uint8_t)(value ^ mask);

    return BITWISE_SUCCESS;
}

BitwiseStatus read_bit(
    uint8_t value,
    uint8_t position,
    uint8_t *bit_value
)
{
    if (bit_value == NULL)
    {
        return BITWISE_ERROR;
    }

    if (!is_valid_bit_position(position))
    {
        return BITWISE_ERROR;
    }

    *bit_value = (uint8_t)((value >> position) & 1U);

    return BITWISE_SUCCESS;
}

void print_binary_uint8(uint8_t value)
{
    int position = 0;

    for (position = 7; position >= 0; position--)
    {
        uint8_t bit =
            (uint8_t)((value >> position) & 1U);

        printf("%u", (unsigned int)bit);
    }
}