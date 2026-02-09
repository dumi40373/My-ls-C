/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static float negverif(float nb)
{
    if (nb < 0.0f){
        nb = -nb;
        my_putchar('-');
    }
    return nb;
}

static int digit_verif(int digit)
{
    if (digit < 0)
        digit = 0;
    if (digit > 9)
        digit = 9;
    my_putchar('0' + digit);
    return digit;
}

void my_putfloat(double nb)
{
    int precision = 6;
    double frac = (nb - (int)nb) + 1e-6f;
    int digit = 0;
    int cmpt = frac_cmpt(nb + 1);

    nb = negverif(nb);
    my_put_nbr((int)nb);
    my_putchar('.');
    if (frac < 0.0f)
        frac = -frac;
    for (int i = 0; i < precision; ++i) {
        if (i <= cmpt){
            frac *= 10.0f;
            digit = (int)(frac);
            digit = digit_verif(digit);
            frac -= (double)digit;
            continue;
        }
        my_putchar('0');
    }
}
