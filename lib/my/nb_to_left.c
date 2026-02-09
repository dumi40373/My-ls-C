/*
** EPITECH PROJECT, 2025
** nb_to_left
** File description:
** handle left alignment in printf
*/

#include <stdarg.h>
#include "my.h"

int for1(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] == '-')
            break;
    }
    return i;
}

int nb_to_left(const char *str, va_list arg)
{
    int i = for1(str);
    int j = 0;
    int deca = 0;
    char nbr[20];

    j = i + 2;
    i = 0;
    for (; my_isnumeric(str[j]) == 1; j++) {
        nbr[i] = str[j];
        i++;
    }
    nbr[i + 1] = '\0';
    deca = my_getnbr(nbr);
    j += show_tag(str, arg, j - 1);
    for (int z = 0; z < deca; z++)
        my_putchar(' ');
    return j;
}
