/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void my_printf(const char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '%') {
            i = show_tag(str, args, i);
            i--;
            continue;
        }
        if (str[i] == '\0')
            break;
        my_putchar(str[i]);
    }
    va_end(args);
}
