/*
** EPITECH PROJECT, 2025
** my_shortest
** File description:
** flag g
*/

#include "my.h"
#include <stdlib.h>


#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int zero_cmpt(double nb)
{
    int cmpt = 0;

    while ((long int)nb == 0) {
        nb = nb * 10;
        cmpt++;
    }
    return cmpt;
}

void shortest_scientist_branch(double nb, struct arg_list *argp, double frac1)
{
    if (nb < 1) {
        my_put_nbr((long int)argp->nbr);
        my_putchar('.');
        my_put_nbr(zero_killer((long int)frac1));
        my_putstr(argp->str);
        my_putchar('-');
        if (argp->expo < 10)
            my_putchar('0');
        my_put_nbr((argp->expo) * -1);
    }
}

void shortest_decimal_branch(double nb, struct float_list *flp, char *str)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    my_put_nbr(flp->entier);
    if (zero_killer(flp->frac) != 0) {
        my_putchar('.');
        my_putstr(str);
        my_put_nbr(zero_killer(flp->frac));
    }
}

void my_shortest(double nb)
{
    struct float_list fl = my_return_float(nb);
    struct arg_list arg = my_return_scientist(nb);
    double frac = (arg.nbr - (long int)arg.nbr) * my_pow(10, 6);
    char str[20];

    for (int i = 0; i < zero_cmpt(nb) - 1; i++) {
        str[i] = '0';
    }
    str[zero_cmpt(nb)] = '\0';
    if (arg.expo < -4 || arg.expo >= 6) {
        shortest_scientist_branch(nb, &arg, frac);
    } else {
        shortest_decimal_branch(nb, &fl, str);
    }
}
