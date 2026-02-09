/*
** EPITECH PROJECT, 2025
** handle_char
** File description:
** handle_char
*/

#include <stdarg.h>
#include "my.h"

void handle_char(va_list ap)
{
    char c = (char)va_arg(ap, int);

    my_putchar(c);
}
