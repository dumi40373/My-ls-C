/*
** EPITECH PROJECT, 2025
** handle_scientist_upper
** File description:
** handle_scientist_upper
*/

#include <stdarg.h>
#include "my.h"

void handle_scientist_upper(va_list ap)
{
    double d = va_arg(ap, double);

    my_put_scientist_upper(d);
}
