/*
** EPITECH PROJECT, 2025
** str cat
** File description:
** str cat
*/

#include <unistd.h>
#include "my.h"
#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    int l = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[l + i] = src[i];
    }
    dest[l + i] = '\0';
    return dest;
}
