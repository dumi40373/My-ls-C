##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

SRC =	my_ls.c	\

OBJ =	$(SRC:.c=.o)

NAME = my_ls

LIB_DIR = lib/my
LIB = $(LIB_DIR)/libmy.a

all: $(LIB) $(NAME)

$(LIB):
		$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ)
		epiclang $(OBJ) -o $(NAME) lib/libmy.a
clean:
		rm -f $(OBJ)
		$(MAKE) -C $(LIB_DIR) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIB_DIR) fclean
		rm -f lib/libmy.a

re: fclean all
