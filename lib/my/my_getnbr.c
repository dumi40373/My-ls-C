/*
** EPITECH PROJECT, 2025
** get nbr
** File description:
** get nbr
*/

int my_getnbr(char *str)
{
    int neg = 1;
    int nb = 0;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-') {
            neg = neg * -1;
        }
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        } else {
            return (nb * neg);
        }
    }
    return (nb * neg);
}
