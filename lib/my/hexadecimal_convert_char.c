/*
** EPITECH PROJECT, 2025
** decimal to hexa in char
** File description:
** decimal to hexa in char
*/

#include <stdio.h>

char decimal_to_hexa_char(int nb)
{
    char res;
    int i = 0;

    if (nb == 0)
        res = '0';
    for (int b; nb != 0; i++) {
        b = nb % 16;
        if (b >= 0 && b <= 9)
            res = '0' + b;
        if (b >= 10 && b <= 15)
            res = 'a' + (b - 10);
        nb = nb / 16;
    }
    return res;
}
