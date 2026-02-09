/*
** EPITECH PROJECT, 2025
** task04
** File description:
** task04
*/

#include <unistd.h>

void my_putchar2(char c)
{
    write(1, &c, 1);
}

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar2('P');
    else
        my_putchar2('N');
    return (0);
}
