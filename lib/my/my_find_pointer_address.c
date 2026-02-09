/*
** EPITECH PROJECT, 2025
** flag a
** File description:
** flag a
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void pointer_to_string(void *ptr, char *buffer)
{
    unsigned long address = (unsigned long)ptr;
    int index = 0;
    char temp[17];
    int temp_i = 0;

    if (address == 0) {
        buffer[index] = '0';
        index++;
    } else {
        for (int i = 0; address > 0; i++) {
            temp[temp_i] = decimal_to_hexa_char(address % 16);
            temp_i++;
            address = address / 16;
        }
        for (int i = temp_i - 1; i >= 0; i--) {
            buffer[index] = temp[i];
            index++;
        }
    }
    buffer[index] = '\0';
}

void my_putaddress(void *ptr)
{
    char *res = malloc(sizeof(char) * 19);
    int i = 0;
    char buffer[17];

    res[i] = '0';
    i++;
    res[i] = 'x';
    i++;
    pointer_to_string(ptr, buffer);
    for (int j = 0; buffer[j] != '\0'; j++) {
        res[i] = buffer[j];
        i++;
    }
    res[i] = '\0';
    my_putstr(res);
}
