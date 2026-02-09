/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** show_tag
*/

#include "my.h"
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>

struct arg_list2
{
    char *arg;
    int (*pf)(int, const char **, struct dirent *, DIR *);
};

const struct arg_list2 s1[10] = {
    {"a", ls_a},
    {"l", ls_l},
    {"la", ls_la},
    {"t", ls_t},
    {"lt", ls_lt},
    {"at", ls_at},
    {"lat", ls_lat},
    {"R", ls_r},
    {"lR", ls_lr},
    {"Ra", ls_ar},
};

int same_str(const char *a, const char *b)
{
    int i = 0;

    while (a[i] == b[i] && a[i] != '\0' && b[i] != '\0') {
        i++;
    }
    if (i == my_strlen(a) && i == my_strlen(b))
        return 1;
    else
        return 0;
}

int find_option_index(const char *opt, int ascii)
{
    for (int j = 0; j < 10; j++) {
        if (str_to_ascii(s1[j].arg) == ascii)
            return j;
    }
    return -1;
}

int show_tag2(int argc, const char **argv, struct dirent *entry, DIR *dir)
{
    const char *opt;
    int j;
    int res = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-')
            res += str_to_ascii(argv[i] + 1);
    }
    j = find_option_index(opt, res);
    if (j >= 0) {
        s1[j].pf(argc, argv, entry, dir);
        return 1;
    }
    return 0;
}
