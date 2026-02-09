/*
** EPITECH PROJECT, 2025
** nbrlen
** File description:
** nbrlen
*/

int my_nbrlen(long int nbr)
{
    long int cmpt = 0;

    if (nbr == 0)
        return 1;
    if (nbr < 0)
        nbr = -nbr;
    while (nbr != 0) {
        nbr = nbr / 10;
        cmpt++;
    }
    return cmpt;
}
