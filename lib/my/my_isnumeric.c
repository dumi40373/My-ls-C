/*
** EPITECH PROJECT, 2025
** my_isnumeric
** File description:
** check single char is numeric
*/

#include "my.h"

int my_isnumeric(char nbr)
{
    if (nbr >= '0' && nbr <= '9'){
        return 1;
    } else {
        return 0;
    }
}
