/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** handle flag_l
*/

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

static int check_ls_root3(int argc, const char **argv)
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

int find_total(const char *path)
{
    DIR *dir = opendir(path);
    struct dirent *entry;
    char *fullpath;
    struct stat ls_info;
    int total = 0;

    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        if (entry->d_name[0] == '.')
            continue;
        fullpath = malloc(my_strlen(path) + my_strlen(entry->d_name) + 2);
        my_strcpy(fullpath, path);
        my_strcat(fullpath, "/");
        my_strcat(fullpath, entry->d_name);
        if (stat(fullpath, &ls_info) == 0)
            total += ls_info.st_blocks;
        free(fullpath);
    }
    closedir(dir);
    return total / 2;
}

int l_put_list(struct dirent *entry,
    DIR *dir, const char **argv, const char *path)
{
    char *fullpath;

    if (!dir)
        return 84;
    my_printf("total %d\n", find_total(path));
    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        if (entry->d_name[0] == '.')
            continue;
        fullpath = malloc(my_strlen(path) + my_strlen(entry->d_name) + 2);
        my_strcpy(fullpath, path);
        my_strcat(fullpath, "/");
        my_strcat(fullpath, entry->d_name);
        my_ls_flag_l(fullpath, path);
        my_printf(" %s\n", entry->d_name);
        free(fullpath);
    }
    closedir(dir);
    return 0;
}

int l_arguments(int argc, const char **argv, int i)
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
    if (check_ls_root3(argc, argv))
        my_printf("%s:\n", argv[i]);
    l_put_list(entry, dir, argv, argv[i]);
    return 0;
}

int ls_l(int argc, const char **argv, struct dirent *entry, DIR *dir)
{
    int use_l = 0;

    if (argc == 2) {
        dir = opendir(".");
        l_put_list(entry, dir, argv, ".");
        return 0;
    }
    for (int k = 1; k < argc; k++) {
        if (argv[k] == NULL)
            continue;
        if (argv[k][0] == '-')
            continue;
        l_arguments(argc, argv, k);
        if (k < argc - 2)
            my_printf("\n");
    }
    return 0;
}
