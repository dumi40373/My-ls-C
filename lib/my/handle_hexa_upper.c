/*
** EPITECH PROJECT, 2025
** handle_hexa
** File description:
** handle_hexa
*/

#include <stdarg.h>
#include "my.h"

void handle_hexa_upper(va_list ap)
{
    char *hexa = decimal_to_hexa_upper(va_arg(ap, int));

    my_putstr(hexa);
}
