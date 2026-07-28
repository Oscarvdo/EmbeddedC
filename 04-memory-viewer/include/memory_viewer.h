#ifndef MEMORY_VIEWER_H
#define MEMORY_VIEWER_H

#include <stddef.h>

/*
 * Muestra una región de memoria byte por byte.
 *
 * data:
 *     Dirección inicial de la información.
 *
 * size:
 *     Cantidad de bytes que deben mostrarse.
 */
void print_memory_bytes(
    const void *data,
    size_t size
);

/*
 * Muestra información general de una variable:
 *
 * - Nombre
 * - Dirección
 * - Tamaño
 * - Bytes en hexadecimal
 */
void inspect_memory(
    const char *name,
    const void *data,
    size_t size
);

/*
 * Detecta el orden de bytes utilizado por el sistema.
 *
 * Devuelve:
 *
 * 1 si el sistema es little-endian.
 * 0 si el sistema es big-endian.
 */
int is_little_endian(void);

#endif