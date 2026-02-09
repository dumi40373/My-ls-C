/*
** EPITECH PROJECT, 2025
** task05
** File description:
** task05
*/

int my_compute_power_it(int nb, int p)
{
    int power = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    for (int i = 1; i < p; i++){
        power = power * nb;
    }
    return power;
}

int my_compute_square_root(int nb)
{
    int x = 1;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    for (int i = 1; x < nb; i++){
        x = my_compute_power_it(i, 2);
        if (x > nb){
            return (0);
            break;
        }
        if (x == nb)
            return i;
    }
    return (0);
}
