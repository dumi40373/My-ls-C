/*
** EPITECH PROJECT, 2025
** print
** File description:
** print
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>
struct arg_list1
{
    char arg;
    void (*pf)(va_list);
};

struct arg_list2
{
    char arg;
    int (*pf)(const char *, va_list);
};
static const struct arg_list1 s1[16] = {
    {'c', handle_char},
    {'s', handle_str},
    {'d', handle_int},
    {'i', handle_int},
    {'F', handle_float},
    {'f', handle_float},
    {'e', handle_scientist},
    {'E', handle_scientist_upper},
    {'%', handle_percent},
    {'x', handle_hexa},
    {'X', handle_hexa_upper},
    {'n', handle_nothing},
    {'p', handle_pointer},
    {'u', handle_unsigned},
    {'g', handle_shortest},
    {'a', handle_float_to_hexa},
};
int show_plus(const char *str, va_list args)
{
    int i = 0;
    int nb = va_arg(args, int);

    for (; str[i] != 'd' || str[i] == '\0'; i++);
    if (nb > 0 && str[i] == 'd' || nb > 0 && str[i] == 'i') {
        my_putchar('+');
        my_put_nbr(nb);
        return 3;
    }
    if (nb < 0 && str[i] == 'd' || nb < 0 && str[i] == 'i') {
        my_put_nbr(nb);
        return 3;
    }
    return 0;
}

int show_space(const char *str, va_list args)
{
    int i = 0;
    int nb = va_arg(args, int);

    for (; str[i] != ' ' || str[i] == '\0'; i++);
    if (nb > 0 && str[i + 1] == 'd' || nb > 0 && str[i + 1] == 'i') {
        my_putchar(' ');
        my_put_nbr(nb);
        return 3;
    }
    if (nb < 0 && str[i + 1] == 'd' || nb < 0 && str[i + 1] == 'i') {
        my_put_nbr(nb);
        return 3;
    }
    return 0;
}

static const struct arg_list2 s2[3] = {
    {'-', nb_to_left},
    {'+', show_plus},
    {' ', show_space},
};
int show_tag(const char *str, va_list args, int i)
{
    for (int j = 0; j < 3; j++) {
        if ((char)s2[j].arg == str[i + 1])
            return s2[j].pf(str, args);
    }
    for (int j = 0; j < 16; j++){
        if ((char)s1[j].arg == str[i + 1]){
            s1[j].pf(args);
            return i + 2;
        }
    }
    return i;
}
