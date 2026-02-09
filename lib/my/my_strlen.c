/*
** EPITECH PROJECT, 2025
** task03
** File description:
** task03
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++){
        x++;
    }
    return x;
}
