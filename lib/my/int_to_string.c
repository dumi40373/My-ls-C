/*
** EPITECH PROJECT, 2025
** intstring
** File description:
** intstring
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *int_to_string(int nbr)
{
    int negative = (nbr < 0);
    int len = my_nbrlen(nbr);
    char *str = malloc(len + negative + 1);

    str[len + negative] = '\0';
    if (nbr < 0)
        nbr = -nbr;
    for (int i = len + negative - 1; i >= 0; i--) {
        str[i] = '0' + (nbr % 10);
        nbr /= 10;
    }
    if (negative)
        str[0] = '-';
    return str;
}
