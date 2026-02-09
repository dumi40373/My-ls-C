/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** flag aR
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include <dirent.h>
#include <sys/sysmacros.h>

static char *build_path_ar(const char *path, const char *d_name)
{
    int nlen = my_strlen(d_name);
    int plen = my_strlen(path);
    char *fullpath = malloc(sizeof(char) * ((nlen + plen) + 2));

    my_strcpy(fullpath, path);
    my_strcat(fullpath, "/");
    my_strcat(fullpath, d_name);
    return fullpath;
}

static int ar_put_dir_list(const char *path)
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (dir == NULL)
        return 0;
    my_printf("%s:\n", path);
    for (entry = readdir(dir); entry; entry = readdir(dir))
        my_printf("%s  ", entry->d_name);
    closedir(dir);
    return 0;
}

int ar_put_first_dir(const char *path, DIR *dir)
{
    dir = opendir(path);
    if (dir == NULL)
        return 84;
    ar_put_dir_list(path);
    closedir(dir);
    return 0;
}

static int str_cmp(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}

void ar_put_first_list(const char *path, DIR *dir, struct dirent *entry)
{
    char *fullpath;
    struct stat ls_info;

    if (str_cmp(entry->d_name, ".")) {
        fullpath = build_path_ar(path, entry->d_name);
        stat(fullpath, &ls_info);
        if (S_ISDIR(ls_info.st_mode))
            ar_put_first_dir(fullpath, dir);
        free(fullpath);
    }
}

void ar_put_list(const char *path, struct dirent *entry, DIR *dir)
{
    struct stat ls_info;
    char *fullpath;

    ar_put_first_dir(path, dir);
    dir = opendir(path);
    ar_put_first_list(path, dir, readdir(dir));
    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        if (str_cmp(entry->d_name, ".."))
            continue;
        fullpath = build_path_ar(path, entry->d_name);
        stat(fullpath, &ls_info);
        if (S_ISDIR(ls_info.st_mode) && !(ls_info.st_mode & S_IRUSR))
            my_printf("\nls: cannot open directory '%s': Permission denied");
        if (S_ISDIR(ls_info.st_mode) && (ls_info.st_mode & S_IRUSR)) {
            my_putstr("\n\n");
            ar_put_list(fullpath, entry, dir);
        }
        free(fullpath);
    }
    closedir(dir);
}

int ar_with_argument(int argc, const char **argv, int i)
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
    ar_put_list(argv[i], entry, dir);
    my_printf("\n");
    return 0;
}

static int ar_check_flags(const char **argv)
{
    int files_nb = 0;

    for (int i = 1; argv[i] != NULL; i++) {
        if (argv[i][0] != '-')
            files_nb++;
    }
    return files_nb;
}

int ls_ar(int argc, const char **argv, struct dirent *entry, DIR *dir)
{
    int files = ar_check_flags(argv);

    if (files == 0) {
        dir = opendir(".");
        ar_put_list(".", entry, dir);
        my_printf("\n");
        return 0;
    }
    for (int k = 1; k < argc; k++) {
        if (argv[k] == NULL)
            continue;
        if (argv[k][0] == '-')
            continue;
        ar_with_argument(argc, argv, k);
        if (k < files)
            my_printf("\n");
    }
    return 0;
}
