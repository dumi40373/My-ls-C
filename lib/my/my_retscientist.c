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

static struct arg_list show_scientist_superior(double nbr, long int cmpt)
{
    struct arg_list s1;
    double temp = nbr;

    if (my_nbrlen(nbr) < 8)
        nbr -= 1e-6f;
    for (long int i = 0; i < cmpt - 1; i++){
        nbr = nbr / 10;
    }
    s1.nbr = nbr;
    s1.str[0] = 'e';
    s1.str[1] = '+';
    if (cmpt - 1 < 10){
        s1.str[2] = '0';
        s1.str[3] = '\0';
    } else
        s1.str[2] = '\0';
    s1.expo = cmpt - 1;
    return s1;
}

struct arg_list show_scientist_inferior(double nbr, long int cmpt)
{
    struct arg_list s1;
    double temp = nbr;

    for (long int i = 0; i < cmpt - 1; i++){
        temp = temp * 10;
    }
    s1.nbr = temp;
    s1.str[0] = 'e';
    if (cmpt - 1 < 10)
        s1.str[1] = '\0';
    else
        s1.str[1] = '\0';
    s1.expo = (cmpt - 1) * -1;
    return s1;
}

struct arg_list my_return_scientist(double nbr)
{
    struct arg_list s1;
    long int cmpt = my_nbrlen((long int)nbr);
    double entier_nbr = (long int)nbr;
    double temp = 0;

    if (entier_nbr >= 1){
        return show_scientist_superior(nbr, cmpt);
    }
    if (nbr < 1){
        temp = nbr;
        for (int i = 0; (long int)temp <= 0; i++){
            temp = temp * 10;
            cmpt++;
        }
        return show_scientist_inferior(nbr, cmpt);
    }
    return s1;
}
