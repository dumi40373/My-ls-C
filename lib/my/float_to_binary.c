/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** flag_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static char *decimal_binary_if0(double nb)
{
    char *binary = malloc(sizeof(char) * 52);
    double res = nb - (int)nb;

    if (nb < 0)
        res = -res;
    for (int i = 0; i < 52; i++) {
        res = res * 2;
        if ((int)res >= 1) {
            binary[i] = '1';
            res -= 1;
        } else {
            binary[i] = '0';
        }
    }
    return binary;
}

static char *decimal_binary(double nb)
{
    char *binary = malloc(sizeof(char) * 52);
    double res = nb - (int)nb;

    if (nb < 0)
        res = -res;
    for (int i = 0; res != 0 && i < 52; i++) {
        res = res * 2;
        if ((int)res >= 1) {
            binary[i] = '1';
            res -= 1;
        } else {
            binary[i] = '0';
        }
    }
    return binary;
}

char *whole_to_binary(int nb)
{
    int a = nb;
    char *res = malloc(sizeof(char) * 33);

    if (a < 0)
        a = a * -1;
    if (nb == 0) {
        res[0] = '0';
        return res;
    }
    for (int i = 0; a > 0; i++) {
        if (a % 2 >= 1) {
            res[i] = 1 + '0';
        } else {
            res[i] = 0 + '0';
        }
        a = a / 2;
    }
    my_revstr(res);
    return res;
}

char *float_binary(char *whole, char *decimal)
{
    int max = my_strlen(whole) + my_strlen(decimal);
    char *res = malloc(sizeof(char) * (max + 1));
    int i = 0;

    for (; i < my_strlen(whole); i++) {
        res[i] = whole[i];
    }
    for (int y = 0; y < my_strlen(decimal); y++) {
        res[i] = decimal[y];
        i++;
    }
    return res;
}

char *float_binary_complete(double nb)
{
    int a = (int)nb;
    char *whole = whole_to_binary(a);
    char *decimal = decimal_binary(nb);
    char *res = float_binary(whole, decimal);

    return res;
}

char *move_dot(double nb)
{
    char *str = float_binary_complete(nb);
    int l = my_strlen(str);
    char *res = malloc(sizeof(char) * (l + 2));

    res[0] = str[0];
    res[1] = '.';
    for (int i = 1; i < l; i++) {
        res[i + 1] = str[i];
    }
    return res;
}
