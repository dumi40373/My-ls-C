/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** my_ls
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"
#include <dirent.h>
#include <sys/sysmacros.h>

int detect_flag(int argc, char **argv)
{
    for (int i = 1; argv[i] != NULL; i++) {
        if (argv[i][0] == '-')
            return 1;
    }
    return 0;
}

int my_ls(int argc, char **argv)
{
    DIR *dir;
    struct dirent *entry;
    int a = 0;

    if (argc == 1) {
        dir = opendir(".");
        put_list(argc, entry, dir, argv);
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        if (argv[i] != NULL && detect_flag(argc, argv)) {
            a = show_tag2(argc, (const char **)argv, entry, dir);
            return 0;
        }
        if (argv[i] != NULL && a == 0)
            with_argument(argc, argv, i);
        if (i < argc - 1 && a == 0)
            my_printf("\n");
    }
    return 0;
}

int main(int argc, char **argv)
{
    return my_ls(argc, argv);
}
