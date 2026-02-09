/*
** EPITECH PROJECT, 2025
** task02
** File description:
** task02
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        my_putchar(str[i]);
    }
    return (0);
}
