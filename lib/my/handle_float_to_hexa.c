/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** flag_a
*/

#include <stdarg.h>
#include "my.h"

void handle_float_to_hexa(va_list ap)
{
    double nb = va_arg(ap, double);

    flag_a(nb);
}
