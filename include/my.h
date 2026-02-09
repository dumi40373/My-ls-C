/*
** EPITECH PROJECT, 2025
** my.h_2
** File description:
** my.h_2
*/

#include <stdarg.h>
#include <dirent.h>

#ifndef MY_H
    #define MY_H
struct arg_list {
    double nbr;
    char str[4];
    int expo;
};
struct float_list {
    char neg;
    long int entier;
    long int frac;
};
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(long int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_it(int nb, int p);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_isnumeric(char nbr);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *int_to_char(int nbr);
char *int_to_string(int nbr);
int my_nbrlen(long int nbr);
int my_pow(int nbr, int expo);
void my_putfloat(double nb);
int frac_cmpt(double nb);
void my_put_scientist(double nbr);
void my_put_scientist_upper(double nbr);
void my_printf(const char *str, ...);
char *decimal_to_hexa(int nb);
char decimal_to_hexa_char(int nb);
void handle_hexa(va_list ap);
void handle_nothing(va_list ap);
void handle_percent(va_list ap);
void handle_scientist_upper(va_list ap);
void handle_scientist(va_list ap);
void handle_float(va_list ap);
void handle_int(va_list ap);
void handle_str(va_list ap);
void handle_char(va_list ap);
void handle_pointer(va_list ap);
void my_putaddress(void *ptr);
void handle_unsigned(va_list ap);
void handle_shortest(va_list ap);
int my_put_unsigned_nbr(unsigned int nb);
struct arg_list my_return_scientist(double nbr);
struct float_list my_return_float(double nb);
long int zero_killer(int nb);
void my_shortest(double nb);
char *move_dot(double nb);
int find_exponent_int(double nb);
char *find_exponent_str(double nb);
char *find_mantissa(double nb);
char *float_to_hexa(char *binary);
void flag_a(double nb);
void handle_float_to_hexa(va_list ap);
char *decimal_to_hexa_upper(int nb);
void handle_hexa_upper(va_list ap);
int nb_to_left(const char *str, va_list arg);
int show_tag(const char *str, va_list args, int i);
char *my_find_file_name(char *str);
char **my_str_to_word_array(char *str, char *delim);
int with_argument(int argc, char **argv, int i);
int put_list(int argc, struct dirent *entry, DIR *dir, char **argv);
int ls_a(int argc, const char **argv, struct dirent *entry, DIR *dir);
int show_tag2(int argc, const char **argv, struct dirent *entry, DIR *dir);
int str_to_ascii(const char *str);
void my_ls_flag_l(const char *argv, const char *path);
int ls_l(int argc, const char **argv, struct dirent *entry, DIR *dir);
int ls_la(int argc, const char **argv, struct dirent *entry, DIR *dir);
int find_link_width(const char *path);
int find_usr_width(const char *path);
int find_grp_width(const char *path);
int find_size_width(const char *path);
void my_ls_flag_la(const char *argv, const char *path);
int find_size_width_la(const char *path);
int ls_t(int argc, const char **argv, struct dirent *entry, DIR *dir);
int ls_lt(int argc, const char **argv, struct dirent *entry, DIR *dir);
int ls_at(int argc, const char **argv, struct dirent *entry, DIR *dir);
int ls_lat(int argc, const char **argv, struct dirent *entry, DIR *dir);
int ls_r(int argc, const char **argv, struct dirent *entry, DIR *dir);
int ls_lr(int argc, const char **argv, struct dirent *entry, DIR *dir);
int ls_ar(int argc, const char **argv, struct dirent *entry, DIR *dir);

#endif
