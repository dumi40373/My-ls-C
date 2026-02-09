/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** flag_a
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include <dirent.h>
#include <sys/sysmacros.h>

int a_put_list(struct dirent *entry, DIR *dir, const char **argv)
{
    struct stat ls_info;

    if (dir == NULL)
        return 84;
    entry = readdir(dir);
    while (entry != NULL) {
        my_printf("%s  ", entry->d_name);
        entry = readdir(dir);
    }
    closedir(dir);
    return 0;
}

int check_ls_root2(int argc, const char **argv)
{
    int check = 1;

    for (int i = 1; argv[i] != NULL; i++) {
        if (argv[i][0] == '-')
            check++;
    }
    if (check == argc || check == argc - 1)
        return 0;
    else
        return 1;
}

int a_arguments(int argc, const char **argv, int i)
{
    DIR *dir;
    struct dirent *entry;
    struct stat ls_info;

    if (stat(argv[i], &ls_info) == -1) {
        my_printf("ls: cannot access '%s': "
            "No such file or directory\n", argv[i]);
        return 84;
    }
    if (!(ls_info.st_mode & S_IRUSR)) {
        my_printf("ls: cannot open directory '%s': "
            "Permission denied\n", argv[i]);
        return 84;
    }
    dir = opendir(argv[i]);
    if (check_ls_root2(argc, argv))
        my_printf("%s:\n", argv[i]);
    a_put_list(entry, dir, argv);
    my_printf("\n");
    return 0;
}

int ls_a(int argc, const char **argv, struct dirent *entry, DIR *dir)
{
    if (argc == 2) {
        dir = opendir(".");
        a_put_list(entry, dir, argv);
        my_printf("\n");
        return 0;
    }
    for (int k = 1; k < argc; k++) {
        if (argv[k] == NULL)
            continue;
        if (argv[k][0] == '-')
            continue;
        a_arguments(argc, argv, k);
        if (k < argc - 2)
            my_printf("\n");
    }
    return 0;
}
