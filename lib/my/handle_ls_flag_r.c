/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** ls_R
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include <dirent.h>
#include <sys/sysmacros.h>

static char *build_path(const char *path, const char *d_name)
{
    int nlen = my_strlen(d_name);
    int plen = my_strlen(path);
    char *fullpath = malloc(sizeof(char) * ((nlen + plen) + 2));

    my_strcpy(fullpath, path);
    my_strcat(fullpath, "/");
    my_strcat(fullpath, d_name);
    return fullpath;
}

static int has_files(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    int has_file = 0;

    dir = opendir(path);
    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        if (entry->d_name[0] != '.'){
            has_file++;
            break;
        }
    }
    return has_file;
}

static int r_put_dir_list(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    int has_file = has_files(path);

    dir = opendir(path);
    if (dir == NULL)
        return 0;
    if (!has_file) {
        my_printf("%s:", path);
        return 0;
    }
    my_printf("%s:\n", path);
    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        if (entry->d_name[0] != '.')
            my_printf("%s  ", entry->d_name);
    }
    closedir(dir);
    return 0;
}

int r_put_first_dir(const char *path, DIR *dir)
{
    dir = opendir(path);
    if (dir == NULL)
        return 84;
    r_put_dir_list(path);
    closedir(dir);
    return 0;
}

void r_put_first_list(const char *path, DIR *dir, struct dirent *entry)
{
    char *fullpath;
    struct stat ls_info;

    if (entry->d_name[0] != '.') {
        fullpath = build_path(path, entry->d_name);
        stat(fullpath, &ls_info);
        if (S_ISDIR(ls_info.st_mode))
            r_put_first_dir(fullpath, dir);
        free(fullpath);
    }
}

static int is_perm(char *fullpath)
{
    struct stat ls_info;

    stat(fullpath, &ls_info);
    if (S_ISDIR(ls_info.st_mode) && !(ls_info.st_mode & S_IRUSR)) {
        my_printf("\nls: cannot open directory '%s': "
            "Permission denied", fullpath);
        free(fullpath);
        return 1;
    }
    return 0;
}

void r_put_list(const char *path, struct dirent *entry, DIR *dir)
{
    struct stat ls_info;
    char *fullpath;

    r_put_first_dir(path, dir);
    dir = opendir(path);
    entry = readdir(dir);
    r_put_first_list(path, dir, entry);
    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        if (entry->d_name[0] == '.')
            continue;
        fullpath = build_path(path, entry->d_name);
        stat(fullpath, &ls_info);
        if (is_perm(fullpath))
            continue;
        if (S_ISDIR(ls_info.st_mode) && (ls_info.st_mode & S_IRUSR)) {
            my_putstr("\n\n");
            r_put_list(fullpath, entry, dir);
        }
    }
    closedir(dir);
}

static int r_check_ls_root(int argc, const char **argv)
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

int r_with_argument(int argc, const char **argv, int i)
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
    r_put_list(argv[i], entry, dir);
    my_printf("\n");
    return 0;
}

int ls_r(int argc, const char **argv, struct dirent *entry, DIR *dir)
{
    if (argc == 2) {
        dir = opendir(".");
        r_put_list(".", entry, dir);
        my_printf("\n");
        return 0;
    }
    for (int k = 1; k < argc; k++) {
        if (argv[k] == NULL)
            continue;
        if (argv[k][0] == '-')
            continue;
        r_with_argument(argc, argv, k);
        if (k < argc - 2)
            my_printf("\n");
    }
    return 0;
}
