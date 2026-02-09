/*
** EPITECH PROJECT, 2025
** task01
** File description:
** task01
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int n = my_strlen(src);

    for (int i = 0; i <= n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
