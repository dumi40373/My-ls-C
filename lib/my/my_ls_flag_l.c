/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** flag l
*/
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include "my.h"

static void put_type(const char *argv, struct stat *ls_info)
{
    char type = '-';

    if (S_ISBLK(ls_info->st_mode))
        type = 'b';
    if (S_ISCHR(ls_info->st_mode))
        type = 'c';
    if (S_ISDIR(ls_info->st_mode))
        type = 'd';
    if (S_ISLNK(ls_info->st_mode))
        type = 'l';
    if (S_ISFIFO(ls_info->st_mode))
        type = 'p';
    if (S_ISSOCK(ls_info->st_mode))
        type = 's';
    my_printf("%c", type);
}

static void put_perm_usr(const char *argv, struct stat *ls_info)
{
    if (ls_info->st_mode & S_IRUSR)
        my_printf("%c", 'r');
    else
        my_printf("%c", '-');
    if (ls_info->st_mode & S_IWUSR)
        my_printf("%c", 'w');
    else
        my_printf("%c", '-');
    if (ls_info->st_mode & S_IXUSR)
        my_printf("%c", 'x');
    else
        my_printf("%c", '-');
}

static void put_perm_grp(const char *argv, struct stat *ls_info)
{
    if (ls_info->st_mode & S_IRGRP)
        my_printf("%c", 'r');
    else
        my_printf("%c", '-');
    if (ls_info->st_mode & S_IWGRP)
        my_printf("%c", 'w');
    else
        my_printf("%c", '-');
    if (ls_info->st_mode & S_IXGRP)
        my_printf("%c", 'x');
    else
        my_printf("%c", '-');
}

static void put_perm_oth(const char *argv, struct stat *ls_info)
{
    if (ls_info->st_mode & S_IROTH)
        my_printf("%c", 'r');
    else
        my_printf("%c", '-');
    if (ls_info->st_mode & S_IWOTH)
        my_printf("%c", 'w');
    else
        my_printf("%c", '-');
    if (ls_info->st_mode & S_IXOTH)
        my_printf("%c", 'x');
    else
        my_printf("%c", '-');
}

static void put_link(const char *argv, struct stat *ls_info)
{
    int link = ls_info->st_nlink;

    my_printf(" %d", ls_info->st_nlink);
}

static void put_usr_grp(const char *argv, struct stat *ls_info)
{
    struct passwd *pwd;
    struct group *grp;

    (pwd = getpwuid(ls_info->st_uid));
    my_printf(" %s", pwd->pw_name);
    (grp = getgrgid(ls_info->st_gid));
    my_printf(" %s", grp->gr_name);
}

static void put_size(const char *argv, struct stat *ls_info)
{
    int size = ls_info->st_size;
    int digits = my_nbrlen(size);
    int min_width = find_size_width(argv);

    while (digits < min_width) {
        my_putchar(' ');
        digits++;
    }
    my_printf(" %d ", size);
}

static void put_time(const char *argv, struct stat *ls_info)
{
    char *time = ctime(&ls_info->st_mtime);

    for (int i = 4; i <= 15; i++) {
        my_putchar(time[i]);
    }
}

void my_ls_flag_l(const char *argv, const char *path)
{
    const char *arg = argv;
    struct stat ls_info;

    stat(arg, &ls_info);
    if (ls_info.st_ino) {
        put_type(arg, &ls_info);
        put_perm_usr(arg, &ls_info);
        put_perm_grp(arg, &ls_info);
        put_perm_oth(arg, &ls_info);
        put_link(arg, &ls_info);
        put_usr_grp(arg, &ls_info);
        put_size(path, &ls_info);
        put_time(arg, &ls_info);
    }
}
