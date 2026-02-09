/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** find max width
*/

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include "my.h"

static char *find_fullpath(const char *path, struct dirent *entry)
{
    char *fullpath;

    if (entry->d_name[0] == '.')
        return NULL;
    fullpath = malloc(my_strlen(path) + my_strlen(entry->d_name) + 2);
    my_strcpy(fullpath, path);
    my_strcat(fullpath, "/");
    my_strcat(fullpath, entry->d_name);
    return fullpath;
}

static int find_width(const char *path, int (*get_len)(struct stat *))
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
        fullpath = find_fullpath(path, entry);
        stat(fullpath, &ls_info);
        len = get_len(&ls_info);
        if (len > width)
            width = len;
        free(fullpath);
    }
    closedir(dir);
    return width;
}

static int link_len(struct stat *ls_info)
{
    return my_nbrlen(ls_info->st_nlink);
}

static int usr_len(struct stat *ls_info)
{
    struct passwd *pwd;

    (pwd = getpwuid(ls_info->st_uid));
    return my_strlen(pwd->pw_name);
}

static int grp_len(struct stat *ls_info)
{
    struct group *grp;

    (grp = getgrgid(ls_info->st_gid));
    return my_strlen(grp->gr_name);
}

static int size_len(struct stat *ls_info)
{
    return my_nbrlen(ls_info->st_size);
}

int find_link_width(const char *path)
{
    return find_width(path, link_len);
}

int find_usr_width(const char *path)
{
    return find_width(path, usr_len);
}

int find_grp_width(const char *path)
{
    return find_width(path, grp_len);
}

int find_size_width(const char *path)
{
    return find_width(path, size_len);
}
