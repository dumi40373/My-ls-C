##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_isnumeric.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\
		int_to_char.c	\
		int_to_string.c	\
		my_pow.c	\
		my_nbrlen.c	\
		my_put_scientist.c	\
		my_putfloat.c	\
		frac_cmpt.c	\
		my_put_scientist_upper.c	\
		my_printf.c	\
		hexadecimal_convert.c	\
		hexadecimal_convert_char.c	\
		handle_char.c	\
		handle_str.c	\
		handle_int.c	\
		handle_float.c	\
		handle_scientist.c	\
		handle_scientist_upper.c	\
		handle_percent.c	\
		handle_hexa.c	\
		handle_nothing.c	\
		handle_pointer.c	\
		handle_unsigned.c	\
		my_find_pointer_address.c	\
		my_put_unsigned_nbr.c	\
		my_retscientist.c	\
		my_retfloat.c	\
		zero_killer.c	\
		my_shortest.c	\
		handle_shortest.c	\
		float_to_binary.c	\
		float_to_hexa.c	\
		flag_a.c	\
		handle_float_to_hexa.c 	\
		hexadecimal_convert_upper.c	\
		handle_hexa_upper.c	\
		nb_to_left.c	\
		show_tag.c	\
		my_find_file_name.c	\
		my_str_to_word_array.c	\
		with_argument.c	\
		put_list.c	\
		my_ls_flag_a.c	\
		show_tag_ls.c	\
		my_str_to_ascii.c	\
		my_ls_flag_l.c	\
		handle_ls_flag_l.c	\
		handle_ls_flag_la.c	\
		find_max_width_l.c	\
		find_max_width_la.c	\
		my_ls_flag_la.c	\
		handle_ls_flag_t.c	\
		handle_ls_flag_lt.c	\
		handle_ls_flag_at.c	\
		handle_ls_flag_lat.c	\
		handle_ls_flag_r.c	\
		handle_ls_flag_lr.c	\
		handle_ls_flag_ar.c	\

OBJ	=	$(SRC:.c=.o)

all: exe

exe: $(OBJ)
	ar rc libmy.a $(OBJ)
	cp libmy.a ../
	cp my.h ../../include/

$(OBJ): $(SRC)
	epiclang -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a

re: fclean all
