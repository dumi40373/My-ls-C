/*
** EPITECH PROJECT, 2025
** handle_scientist
** File description:
** handle_scientist
*/

#include <stdarg.h>
#include "my.h"

void handle_scientist(va_list ap)
{
    double d = va_arg(ap, double);

    my_put_scientist(d);
}
