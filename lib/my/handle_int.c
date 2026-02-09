/*
** EPITECH PROJECT, 2025
** handle_int
** File description:
** handle_int
*/

#include <stdarg.h>
#include "my.h"

void handle_int(va_list ap)
{
    int n = va_arg(ap, int);

    my_put_nbr(n);
}
