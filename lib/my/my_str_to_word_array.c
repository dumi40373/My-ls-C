/*
** EPITECH PROJECT, 2025
** my str to word array
** File description:
** my str to word array
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int is_delim(char value, char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++) {
        if (value == delim[i]) {
            return 1;
        }
    }
    return 0;
}

int number_of_words(char *str, char *delim)
{
    int lim = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_delim(str[i], delim) == 1) {
            lim++;
        }
    }
    return lim;
}

int words_size(char *str, char *delim, int i)
{
    int nb_words = number_of_words(str, delim);
    int a = 0;

    for (int index = i; is_delim(str[index], delim) == 0; index++) {
        a++;
    }
    return a;
}

char **my_str_to_word_array(char *str, char *delim)
{
    int nb_words = number_of_words(str, delim);
    char **res = malloc(sizeof(char *) * (nb_words + 1));
    int i = 0;

    for (int j = 0; j < nb_words; j++) {
        res[j] = malloc(sizeof(char) * words_size(str, delim, i) + 1);
        for (int a = 0; is_delim(str[i], delim) == 0; a++) {
            res[j][a] = str[i];
            i++;
        }
        i++;
    }
    res[nb_words] = NULL;
    return res;
}
