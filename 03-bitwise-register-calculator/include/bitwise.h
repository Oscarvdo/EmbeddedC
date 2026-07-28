#ifndef BITWISE_H
#define BITWISE_H

/*
 * stdint.h contiene tipos enteros de tamaño definido.
 *
 * uint8_t significa:
 *
 * unsigned integer de 8 bits.
 *
 * Puede almacenar valores entre 0 y 255.
 */
#include <stdint.h>

/*
 * Resultado de una operación del módulo.
 */
typedef enum
{
    BITWISE_ERROR = 0,
    BITWISE_SUCCESS = 1
} BitwiseStatus;

/*
 * Aplica la operación AND entre dos valores de 8 bits.
 */
uint8_t bitwise_and(uint8_t first_value, uint8_t second_value);

/*
 * Aplica la operación OR entre dos valores de 8 bits.
 */
uint8_t bitwise_or(uint8_t first_value, uint8_t second_value);

/*
 * Aplica la operación XOR entre dos valores de 8 bits.
 */
uint8_t bitwise_xor(uint8_t first_value, uint8_t second_value);

/*
 * Invierte todos los bits del valor.
 */
uint8_t bitwise_not(uint8_t value);

/*
 * Desplaza los bits hacia la izquierda.
 */
uint8_t shift_left(uint8_t value, uint8_t positions);

/*
 * Desplaza los bits hacia la derecha.
 */
uint8_t shift_right(uint8_t value, uint8_t positions);

/*
 * Coloca en 1 un bit específico.
 *
 * position debe estar entre 0 y 7.
 */
BitwiseStatus set_bit(
    uint8_t value,
    uint8_t position,
    uint8_t *result
);

/*
 * Coloca en 0 un bit específico.
 */
BitwiseStatus clear_bit(
    uint8_t value,
    uint8_t position,
    uint8_t *result
);

/*
 * Cambia el estado de un bit:
 *
 * 0 se convierte en 1.
 * 1 se convierte en 0.
 */
BitwiseStatus toggle_bit(
    uint8_t value,
    uint8_t position,
    uint8_t *result
);

/*
 * Lee el estado de un bit.
 *
 * bit_value recibirá 0 o 1.
 */
BitwiseStatus read_bit(
    uint8_t value,
    uint8_t position,
    uint8_t *bit_value
);

/*
 * Imprime un valor de 8 bits en formato binario.
 */
void print_binary_uint8(uint8_t value);

#endif