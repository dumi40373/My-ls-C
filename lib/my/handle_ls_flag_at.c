/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** handle flag_at
*/

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

static int at_check_ls_root(int argc, const char **argv)
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

static int at_find_files_nbr(const char *argv)
{
    DIR *dir = opendir(argv);
    int files_nb = 0;
    struct dirent *entry;

    for (entry = readdir(dir); entry; entry = readdir(dir))
        files_nb++;
    closedir(dir);
    return files_nb;
}

static char **at_find_files_tab(const char *argv)
{
    DIR *dir = opendir(argv);
    struct dirent *entry;
    int files_nb = at_find_files_nbr(argv);
    char **files_names = malloc(sizeof(char *) * (files_nb + 1));
    int i = 0;

    if (!dir)
        return NULL;
    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        files_names[i] = malloc(my_strlen(entry->d_name) + 1);
        my_strcpy(files_names[i], entry->d_name);
        i++;
    }
    files_names[i] = NULL;
    closedir(dir);
    return files_names;
}

static int at_find_index(char **list, const char *path)
{
    struct stat ls_info;
    struct stat best_info;
    char fullpath[4096];
    int best_i = 0;

    my_strcpy(fullpath, path);
    my_strcat(fullpath, "/");
    my_strcat(fullpath, list[0]);
    stat(fullpath, &best_info);
    for (int i = 1; list[i] != NULL; i++) {
        my_strcpy(fullpath, path);
        my_strcat(fullpath, "/");
        my_strcat(fullpath, list[i]);
        stat(fullpath, &ls_info);
        if (ls_info.st_mtime >= best_info.st_mtime) {
            best_info = ls_info;
            best_i = i;
        }
    }
    return best_i;
}

void at_remove_index(char **list, int index)
{
    free(list[index]);
    for (int i = index; list[i] != NULL; i++)
        list[i] = list[i + 1];
}

void sort_list_at(const char *path)
{
    char **list = at_find_files_tab(path);
    int index;

    while (list[0] != NULL) {
        index = at_find_index(list, path);
        my_printf("%s  ", list[index]);
        at_remove_index(list, index);
    }
    my_printf("\n");
}

int at_arguments(int argc, const char **argv, int i)
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
    if (at_check_ls_root(argc, argv))
        my_printf("%s:\n", argv[i]);
    sort_list_at(argv[i]);
    return 0;
}

int at_check_flags(const char **argv)
{
    int files_nb = 0;

    for (int i = 1; argv[i] != NULL; i++) {
        if (argv[i][0] != '-')
            files_nb++;
    }
    return files_nb;
}

int ls_at(int argc, const char **argv, struct dirent *entry, DIR *dir)
{
    int files = at_check_flags(argv);

    if (files == 0) {
        dir = opendir(".");
        sort_list_at(".");
        return 0;
    }
    for (int k = 1; k < argc; k++) {
        if (argv[k] == NULL)
            continue;
        if (argv[k][0] == '-')
            continue;
        at_arguments(argc, argv, k);
        if (k < files)
            my_printf("\n");
    }
    return 0;
}
