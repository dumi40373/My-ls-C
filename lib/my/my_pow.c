/*
** EPITECH PROJECT, 2025
** pow
** File description:
** pow
*/

int my_pow(int nbr, int expo)
{
    int result = nbr * nbr;

    if (expo == 1)
        return nbr;
    if (expo == 0)
        return 1;
    for (int i = 2; i < expo; i++){
        result = result * nbr;
    }
    return result;
}
