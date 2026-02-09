/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** flag_a_2
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int find_exponent_int(double nb)
{
    int exponent = 0;
    double value = nb;

    if (value < 0)
        value = value * -1;
    if (value == 0.0)
        return 0;
    if (value < 1.0) {
        while (value < 1.0) {
            value *= 2.0;
            exponent--;
        }
    } else {
        while (value >= 2.0) {
            value /= 2.0;
            exponent++;
        }
    }
    return exponent;
}

char *find_exponent_str(double nb)
{
    int exponent = find_exponent_int(nb);
    char *res = malloc(sizeof(char) * (my_nbrlen(exponent) + 1));
    int i = 0;

    if (exponent == 0)
        res[i] = '0';
    while (exponent != 0) {
        res[i] = (exponent % 10) + '0';
        i++;
        exponent /= 10;
    }
    my_revstr(res);
    return res;
}

char *find_mantissa(double nb)
{
    char *str = move_dot(nb);
    int len = my_strlen(str) - 2;
    char *res = malloc(sizeof(char) * len + 1);
    int i = 0;

    if (nb < 0)
        nb = nb * -1;
    for (; i < len; i++) {
        res[i] = str[i + 2];
    }
    return res;
}

static char temp_float_to_hexa(char *binary, int i, int len)
{
    char res;
    int temp_res = 0;
    int a = 0;

    if (binary[i + a] == '1')
        temp_res += 8;
    a++;
    if (binary[i + a] == '1')
        temp_res += 4;
    a++;
    if (binary[i + a] == '1')
        temp_res += 2;
    a++;
    if (binary[i + a] == '1')
        temp_res += 1;
    res = decimal_to_hexa_char(temp_res);
    return res;
}

char *float_to_hexa(char *binary)
{
    int len = my_strlen(binary);
    int hexa_len = len / 4 + (len % 4 != 0);
    char *res = malloc(sizeof(char) * (hexa_len + 1));
    int b = 0;

    for (int i = 0; i < len; i += 4) {
        res[b] = temp_float_to_hexa(binary, i, len);
        b++;
    }
    return res;
}
