/*
** EPITECH PROJECT, 2025
** handle_unsigned
** File description:
** handler for unsigned integer format
*/

#include <stdarg.h>
#include "my.h"

void handle_unsigned(va_list ap)
{
    unsigned int n = va_arg(ap, unsigned int);

    my_put_unsigned_nbr(n);
}
