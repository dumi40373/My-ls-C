/*
** EPITECH PROJECT, 2025
** tets
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static char *res_if_zero_exponent(double nb, char *str)
{
    char *res = malloc(sizeof(char) * 8);
    int len = my_strlen(str);
    int i = 0;
    char *exponent = find_exponent_str(nb);

    for (; i < len; i++) {
        res[i] = str[i];
    }
    res[i] = 'p';
    i++;
    res[i] = '+';
    i++;
    for (int h = 0; h < my_strlen(exponent); h++) {
        res[i] = exponent[h];
        i++;
    }
    return res;
}

static char *res_if_zero_mantissa(double nb)
{
    int d = 0;
    char *res = malloc(sizeof(char) * 8);

    if (nb < 0 || 1 / nb < 0) {
        res[d] = '-';
        d++;
    }
    res[d] = '0';
    d++;
    res[d] = 'x';
    d++;
    if (nb == 0) {
        res[d] = '0';
    } else {
        res[d] = '1';
    }
    res = res_if_zero_exponent(nb, res);
    return res;
}

char *if_zero_mantissa(double nb)
{
    char *mantissa = find_mantissa(nb);
    int len = my_strlen(mantissa);
    int j = 0;
    char *res = malloc(sizeof(char) * 8);

    for (int i = 0; i < len; i++) {
        if (mantissa[i] == '0') {
            j += 1;
        }
    }
    if (j == len) {
        res = res_if_zero_mantissa(nb);
    } else {
        res = NULL;
    }
    return res;
}

char *put_hexa(double nb, char *res, int i)
{
    char *res2 = res;

    if (nb == 0) {
        res2[i] = '0';
        i++;
    } else {
        res2[i] = '1';
        i++;
        res2[i] = '.';
        i++;
    }
    return res2;
}

char *put_mantissa(double nb, int i, char *res, char *str)
{
    char *res2 = res;
    char *exponent = find_exponent_str(nb);

    for (int a = 0; a < my_strlen(str); a++) {
        res2[i] = str[a];
        i++;
    }
    res2[i] = 'p';
    i++;
    res2[i] = '+';
    i++;
    for (int h = 0; h < my_strlen(exponent); h++) {
        res2[i] = exponent[h];
        i++;
    }
    return res2;
}

void flag_a(double nb)
{
    char *res = malloc(sizeof(char) * 32);
    char *str = float_to_hexa(find_mantissa(nb));
    int i = 0;

    if (nb < 0) {
        res[i] = '-';
        nb = nb * -1;
        i++;
    }
    res[i] = '0';
    i++;
    res[i] = 'x';
    i++;
    res = put_hexa(nb, res, i);
    i += 2;
    res = put_mantissa(nb, i, res, str);
    if (if_zero_mantissa(nb) != NULL)
        my_putstr(if_zero_mantissa(nb));
    else
        my_putstr(res);
}
