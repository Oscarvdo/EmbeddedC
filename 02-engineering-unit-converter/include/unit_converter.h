#ifndef UNIT_CONVERTER_H
#define UNIT_CONVERTER_H

/*
 * Este enum contiene todas las conversiones que puede
 * realizar el programa.
 *
 * Un enum permite asignar nombres descriptivos a números enteros.
 */
typedef enum
{
    CONVERSION_CELSIUS_TO_FAHRENHEIT = 1,
    CONVERSION_FAHRENHEIT_TO_CELSIUS,
    CONVERSION_PSI_TO_BAR,
    CONVERSION_BAR_TO_PSI,
    CONVERSION_LITERS_MIN_TO_CUBIC_METERS_HOUR,
    CONVERSION_CUBIC_METERS_HOUR_TO_LITERS_MIN,
    CONVERSION_INCHES_TO_MILLIMETERS,
    CONVERSION_MILLIMETERS_TO_INCHES
} ConversionType;

/*
 * Códigos que indican si una operación terminó correctamente
 * o si ocurrió algún error.
 */
typedef enum
{
    CONVERTER_ERROR = 0,
    CONVERTER_SUCCESS = 1
} ConverterStatus;

/*
 * Realiza una conversión utilizando:
 *
 * type   -> tipo de conversión
 * input  -> valor original
 * output -> dirección donde se guardará el resultado
 *
 * Devuelve CONVERTER_SUCCESS si la conversión fue válida.
 * Devuelve CONVERTER_ERROR si ocurrió un error.
 */
ConverterStatus convert_unit(
    ConversionType type,
    double input,
    double *output
);

/*
 * Devuelve el nombre de la unidad de entrada correspondiente
 * a una conversión.
 */
const char *get_input_unit(ConversionType type);

/*
 * Devuelve el nombre de la unidad de salida correspondiente
 * a una conversión.
 */
const char *get_output_unit(ConversionType type);

#endif