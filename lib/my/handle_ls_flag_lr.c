/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** flag lR
*/


#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include <dirent.h>
#include <sys/sysmacros.h>

static char *build_path_lr(const char *path, const char *d_name)
{
    int nlen = my_strlen(d_name);
    int plen = my_strlen(path);
    char *fullpath = malloc(sizeof(char) * ((nlen + plen) + 2));

    my_strcpy(fullpath, path);
    my_strcat(fullpath, "/");
    my_strcat(fullpath, d_name);
    return fullpath;
}

int find_total_lr(const char *path)
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

static int lr_put_dir_list(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    char *fullpath;

    dir = opendir(path);
    if (dir == NULL)
        return 0;
    my_printf("%s:\ntotal %d\n", path, find_total_lr(path));
    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        if (entry->d_name[0] != '.') {
            fullpath = build_path_lr(path, entry->d_name);
            my_ls_flag_l(fullpath, path);
            my_putchar(' ');
            my_printf("%s  ", entry->d_name);
            my_printf("\n");
            free(fullpath);
        }
    }
    closedir(dir);
    return 0;
}

static int lr_put_first_dir(const char *path, DIR *dir)
{
    dir = opendir(path);
    if (dir == NULL)
        return 84;
    lr_put_dir_list(path);
    closedir(dir);
    return 0;
}

void lr_put_first_list(const char *path, DIR *dir, struct dirent *entry)
{
    char *fullpath;
    struct stat ls_info;

    if (entry->d_name[0] != '.') {
        fullpath = build_path_lr(path, entry->d_name);
        stat(fullpath, &ls_info);
        if (S_ISDIR(ls_info.st_mode))
            lr_put_first_dir(fullpath, dir);
        free(fullpath);
    }
}

static int is_perm_lr(char *fullpath)
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

void lr_put_list(const char *path, struct dirent *entry, DIR *dir)
{
    struct stat ls_info;
    char *fullpath;

    lr_put_first_dir(path, dir);
    dir = opendir(path);
    entry = readdir(dir);
    lr_put_first_list(path, dir, entry);
    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        if (entry->d_name[0] == '.')
            continue;
        fullpath = build_path_lr(path, entry->d_name);
        stat(fullpath, &ls_info);
        if (is_perm_lr(fullpath))
            continue;
        if (S_ISDIR(ls_info.st_mode) && (ls_info.st_mode & S_IRUSR)) {
            my_putstr("\n");
            lr_put_list(fullpath, entry, dir);
        }
    }
    closedir(dir);
}

int lr_with_argument(int argc, const char **argv, int i)
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
    lr_put_list(argv[i], entry, dir);
    return 0;
}

static int lr_check_flags(const char **argv)
{
    int files_nb = 0;

    for (int i = 1; argv[i] != NULL; i++) {
        if (argv[i][0] != '-')
            files_nb++;
    }
    return files_nb;
}

int ls_lr(int argc, const char **argv, struct dirent *entry, DIR *dir)
{
    int files = lr_check_flags(argv);

    if (files == 0) {
        dir = opendir(".");
        lr_put_list(".", entry, dir);
        return 0;
    }
    for (int k = 1; k < argc; k++) {
        if (argv[k] == NULL)
            continue;
        if (argv[k][0] == '-')
            continue;
        lr_with_argument(argc, argv, k);
        if (k < files)
            my_printf("\n");
    }
    return 0;
}
