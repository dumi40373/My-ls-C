/*
** EPITECH PROJECT, 2025
** handle_str
** File description:
** handle_str
*/

#include <stdarg.h>
#include "my.h"

void handle_str(va_list ap)
{
    char *s = va_arg(ap, char *);

    my_putstr(s);
}
