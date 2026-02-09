/*
** EPITECH PROJECT, 2025
** printf
** File description:
** printf
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static double negverif(double nb)
{
    if (nb < 0.0f){
        nb = -nb;
        my_putchar('-');
    }
    return nb;
}

static long int digit_verif(long int digit)
{
    if (digit < 0)
        digit = 0;
    if (digit > 9)
        digit = 9;
    my_putchar('0' + digit);
    return digit;
}

static void show_scientist(double nbr, long int cmpt)
{
    double temp = nbr;

    if (my_nbrlen(nbr) < 8 && my_nbrlen(nbr) > 1)
        nbr -= 1e-6f;
    for (long int i = 0; i < cmpt - 1; i++){
        nbr = nbr / 10;
    }
    my_putfloat(nbr);
    my_putstr("e+");
    if (cmpt - 1 < 10)
        my_putchar('0');
    my_put_nbr(cmpt - 1);
}

static void show_scientist_small(double nbr, long int cmpt)
{
    double temp = nbr;

    temp = nbr;
    for (int i = 0; (long int)temp <= 0; i++){
        temp = temp * 10;
        cmpt++;
    }
    my_putfloat(temp);
    my_putstr("e-");
    if (cmpt - 1 < 10)
        my_putchar('0');
    my_put_nbr(cmpt - 1);
}

void my_put_scientist(double nbr)
{
    long int cmpt = my_nbrlen((long int)nbr);
    double entier_nbr = (long int)nbr;
    double temp = 0;

    if (nbr < 0) {
        my_putfloat(nbr);
        return;
    }
    if (entier_nbr >= 1)
        show_scientist(nbr, cmpt);
    if (nbr < 1){
        show_scientist_small(nbr, cmpt);
    }
}
