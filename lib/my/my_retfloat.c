/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdio.h>
#include "my.h"

struct float_list my_return_float(double nb)
{
    struct float_list out;
    int precision = 6;
    double frac;
    double scaled;
    long int pow10 = 1;

    if (nb < 0.0) {
        out.neg = '-';
        nb = -nb;
    }
    out.entier = (long int)nb;
    frac = nb - (double)out.entier;
    if (frac < 0.0)
        frac = -frac;
    scaled = frac * my_pow(10, precision);
    out.frac = scaled + 0.5;
    return out;
}
