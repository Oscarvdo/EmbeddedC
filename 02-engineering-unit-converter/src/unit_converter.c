#include <stddef.h>

#include "unit_converter.h"

/*
 * Constantes de conversión.
 *
 * static:
 *     Hace que estas constantes solamente sean visibles
 *     dentro de este archivo.
 *
 * const:
 *     Impide que su valor sea modificado.
 */
static const double PSI_TO_BAR_FACTOR = 0.0689476;
static const double BAR_TO_PSI_FACTOR = 14.5038;
static const double LITERS_MIN_TO_CUBIC_METERS_HOUR_FACTOR = 0.06;
static const double CUBIC_METERS_HOUR_TO_LITERS_MIN_FACTOR =
    16.6666667;
static const double INCHES_TO_MILLIMETERS_FACTOR = 25.4;
static const double MILLIMETERS_TO_INCHES_FACTOR =
    1.0 / 25.4;

ConverterStatus convert_unit(
    ConversionType type,
    double input,
    double *output
)
{
    /*
     * Antes de utilizar un puntero debemos verificar
     * que no sea NULL.
     */
    if (output == NULL)
    {
        return CONVERTER_ERROR;
    }

    /*
     * Seleccionamos la fórmula correspondiente según
     * el tipo de conversión.
     */
    switch (type)
    {
        case CONVERSION_CELSIUS_TO_FAHRENHEIT:
            *output = (input * 9.0 / 5.0) + 32.0;
            break;

        case CONVERSION_FAHRENHEIT_TO_CELSIUS:
            *output = (input - 32.0) * 5.0 / 9.0;
            break;

        case CONVERSION_PSI_TO_BAR:
            *output = input * PSI_TO_BAR_FACTOR;
            break;

        case CONVERSION_BAR_TO_PSI:
            *output = input * BAR_TO_PSI_FACTOR;
            break;

        case CONVERSION_LITERS_MIN_TO_CUBIC_METERS_HOUR:
            *output =
                input *
                LITERS_MIN_TO_CUBIC_METERS_HOUR_FACTOR;
            break;

        case CONVERSION_CUBIC_METERS_HOUR_TO_LITERS_MIN:
            *output =
                input *
                CUBIC_METERS_HOUR_TO_LITERS_MIN_FACTOR;
            break;

        case CONVERSION_INCHES_TO_MILLIMETERS:
            *output = input * INCHES_TO_MILLIMETERS_FACTOR;
            break;

        case CONVERSION_MILLIMETERS_TO_INCHES:
            *output =
                input * MILLIMETERS_TO_INCHES_FACTOR;
            break;

        default:
            return CONVERTER_ERROR;
    }

    return CONVERTER_SUCCESS;
}

const char *get_input_unit(ConversionType type)
{
    switch (type)
    {
        case CONVERSION_CELSIUS_TO_FAHRENHEIT:
            return "C";

        case CONVERSION_FAHRENHEIT_TO_CELSIUS:
            return "F";

        case CONVERSION_PSI_TO_BAR:
            return "PSI";

        case CONVERSION_BAR_TO_PSI:
            return "bar";

        case CONVERSION_LITERS_MIN_TO_CUBIC_METERS_HOUR:
            return "L/min";

        case CONVERSION_CUBIC_METERS_HOUR_TO_LITERS_MIN:
            return "m3/h";

        case CONVERSION_INCHES_TO_MILLIMETERS:
            return "in";

        case CONVERSION_MILLIMETERS_TO_INCHES:
            return "mm";

        default:
            return "unknown";
    }
}

const char *get_output_unit(ConversionType type)
{
    switch (type)
    {
        case CONVERSION_CELSIUS_TO_FAHRENHEIT:
            return "F";

        case CONVERSION_FAHRENHEIT_TO_CELSIUS:
            return "C";

        case CONVERSION_PSI_TO_BAR:
            return "bar";

        case CONVERSION_BAR_TO_PSI:
            return "PSI";

        case CONVERSION_LITERS_MIN_TO_CUBIC_METERS_HOUR:
            return "m3/h";

        case CONVERSION_CUBIC_METERS_HOUR_TO_LITERS_MIN:
            return "L/min";

        case CONVERSION_INCHES_TO_MILLIMETERS:
            return "mm";

        case CONVERSION_MILLIMETERS_TO_INCHES:
            return "in";

        default:
            return "unknown";
    }
}