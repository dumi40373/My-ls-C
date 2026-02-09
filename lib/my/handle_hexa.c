/*
** EPITECH PROJECT, 2025
** handle_hexa
** File description:
** handle_hexa
*/

#include <stdarg.h>
#include "my.h"

void handle_hexa(va_list ap)
{
    char *hexa = decimal_to_hexa(va_arg(ap, int));

    my_putstr(hexa);
}
