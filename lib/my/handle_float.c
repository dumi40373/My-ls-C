/*
** EPITECH PROJECT, 2025
** handle_float
** File description:
** handle_float
*/

#include <stdarg.h>
#include "my.h"

void handle_float(va_list ap)
{
    double d = va_arg(ap, double);

    my_putfloat(d);
}
