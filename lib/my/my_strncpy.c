/*
** EPITECH PROJECT, 2025
** task02
** File description:
** task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i <= n - 1; i++) {
        dest[i] = src[i];
    }
    return dest;
}
