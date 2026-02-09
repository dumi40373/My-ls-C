/*
** EPITECH PROJECT, 2025
** my_put_unsigned_nbr
** File description:
** print unsigned number
*/

#include "my.h"

int my_put_unsigned_nbr(unsigned int nb)
{
    if (nb >= 10) {
        my_put_unsigned_nbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}
