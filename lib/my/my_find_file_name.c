/*
** EPITECH PROJECT, 2025
** my find file name
** File description:
** my find file name
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>

char *add_res(char *str, int i, int final)
{
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);

    for (int j = i + 1; str[j] != '\0'; j++) {
        res[final] = str[j];
        final++;
    }
    return res;
}

char *my_find_file_name(char *str)
{
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);
    int rep = 0;
    int rep2 = 0;
    int final = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == '/')
            rep++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/')
            rep2++;
        if (str[i] == '/' && rep2 == rep) {
            res = add_res(str, i, final);
        }
    }
    if (rep == 0)
        res = str;
    return res;
}
