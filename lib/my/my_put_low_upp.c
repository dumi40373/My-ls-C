/*
** EPITECH PROJECT, 2025
** lower upper
** File description:
** lower upper
*/

#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lowcase(char *str)
{
    char *new_str = malloc(sizeof(char) * (strlen(str) + 1));

    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            new_str[i] = str[i] + 32;
        else
            new_str[i] = str[i];
    }
    return new_str;
    free(new_str);
}

char *upcase(char *str)
{
    char *new_str = malloc(sizeof(char) * (strlen(str) + 1));

    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            new_str[i] = str[i] - 32;
        else
            new_str[i] = str[i];
    }
    return new_str;
    free(new_str);
}
