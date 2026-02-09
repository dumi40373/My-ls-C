/*
** EPITECH PROJECT, 2025
** zero_killer
** File description:
** Function that removes trailing zeros from a number
*/

#include "my.h"

long int zero_killer(int nb)
{
    int cmpt = 0;

    while (nb != 0) {
        if (nb % 10 == 0)
            nb /= 10;
        else
            break;
    }
    return nb;
}
