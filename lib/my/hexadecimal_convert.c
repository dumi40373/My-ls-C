/*
** EPITECH PROJECT, 2025
** decimal to hexadecimal
** File description:
** decimal to hexadecimal
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>

int add_negative_symb(int is_negative, char *res, int i)
{
    if (is_negative == 1) {
        res[i] = '-';
        i++;
    }
    return i;
}

int hexa_if_inf_zero(int nb, int is_negative)
{
    if (nb < 0) {
        nb = -nb;
        is_negative = 1;
    }
    return is_negative;
}

char *decimal_to_hexa(int nb)
{
    char *res = malloc(sizeof(char) * 9);
    int i = 0;
    unsigned int n = (unsigned int)nb;

    if (n == 0) {
        res = "0";
        return res;
    }
    for (int b = 0; n != 0; i++) {
        b = n % 16;
        if (b >= 0 && b <= 9)
            res[i] = '0' + b;
        if (b >= 10 && b <= 15)
            res[i] = 'a' + (b - 10);
        n = n / 16;
    }
    my_revstr(res);
    return res;
}
