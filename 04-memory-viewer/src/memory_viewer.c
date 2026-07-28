#include <stdint.h>
#include <stdio.h>

#include "memory_viewer.h"

void print_memory_bytes(
    const void *data,
    size_t size
)
{
    const uint8_t *bytes = NULL;
    size_t index = 0U;

    if (data == NULL)
    {
        printf("Error: the memory address is NULL.\n");
        return;
    }

    bytes = (const uint8_t *)data;

    for (index = 0U; index < size; index++)
    {
        printf(
            "Byte %zu | Address: %p | Value: 0x%02X | Decimal: %3u\n",
            index,
            (const void *)&bytes[index],
            (unsigned int)bytes[index],
            (unsigned int)bytes[index]
        );
    }
}

void inspect_memory(
    const char *name,
    const void *data,
    size_t size
)
{
    if (name == NULL)
    {
        name = "unnamed";
    }

    printf("\n========================================\n");
    printf("Variable: %s\n", name);
    printf("Address : %p\n", data);
    printf("Size    : %zu byte(s)\n", size);
    printf("----------------------------------------\n");

    print_memory_bytes(data, size);

    printf("========================================\n");
}

int is_little_endian(void)
{
    uint16_t test_value = 0x0001U;
    const uint8_t *first_byte =
        (const uint8_t *)&test_value;

    return first_byte[0] == 0x01U;
}