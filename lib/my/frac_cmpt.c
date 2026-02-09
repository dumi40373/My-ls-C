/*
** EPITECH PROJECT, 2025
** frac_cmpt
** File description:
** count fractional digits helper
*/

#include "my.h"

int frac_cmpt(double nb)
{
    int cmpt = 0;
    long int entier_part = 0;

    while (entier_part != nb) {
        nb *= 10;
        cmpt++;
        entier_part = (long int)nb;
    }
    if (cmpt == 13)
        cmpt = 6;
    return cmpt;
}
