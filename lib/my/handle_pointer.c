/*
** EPITECH PROJECT, 2025
** handle pointer
** File description:
** handle pointer
*/

#include <stdarg.h>
#include "my.h"

void handle_pointer(va_list ap)
{
    void *p = va_arg(ap, void *);

    my_putaddress(p);
}
