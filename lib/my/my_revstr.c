/*
** EPITECH PROJECT, 2025
** task03
** File description:
** task03
*/

#include "my.h"

char *my_revstr(char *str)
{
    char temp;
    int i = my_strlen(str);

    if (i <= 1) {
        return str;
    }
    i--;
    for (int y = 0; y < i; y++) {
        temp = str[y];
        str[y] = str[i];
        str[i] = temp;
        i--;
    }
    return str;
}
