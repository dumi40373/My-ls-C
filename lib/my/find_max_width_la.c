/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** find max width la
*/

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include "my.h"

static char *find_fullpath_la(const char *path, struct dirent *entry)
{
    char *fullpath;

    fullpath = malloc(my_strlen(path) + my_strlen(entry->d_name) + 2);
    my_strcpy(fullpath, path);
    my_strcat(fullpath, "/");
    my_strcat(fullpath, entry->d_name);
    return fullpath;
}

static int find_width_la(const char *path, int (*get_len)(struct stat *))
{
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat ls_info;
    char *fullpath;
    int width = 0;
    int len;

    if (!dir)
        return 0;
    for (entry = readdir(dir); entry; entry = readdir(dir)) {
        fullpath = find_fullpath_la(path, entry);
        stat(fullpath, &ls_info);
        len = get_len(&ls_info);
        if (len > width)
            width = len;
        free(fullpath);
    }
    closedir(dir);
    return width;
}

static int size_len_la(struct stat *ls_info)
{
    return my_nbrlen(ls_info->st_size);
}

int find_size_width_la(const char *path)
{
    return find_width_la(path, size_len_la);
}
