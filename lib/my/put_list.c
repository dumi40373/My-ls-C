/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** put_list
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include <dirent.h>
#include <sys/sysmacros.h>

int put_list(int argc, struct dirent *entry, DIR *dir, char **argv)
{
    struct stat ls_info;

    if (dir == NULL)
        return 84;
    entry = readdir(dir);
    while (entry != NULL) {
        if (entry->d_name[0] != '.')
            my_printf("%s  ", entry->d_name);
        entry = readdir(dir);
    }
    if (argc == 1)
        my_putchar('\n');
    closedir(dir);
    return 0;
}
