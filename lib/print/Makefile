##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for lprintf
##

SRC	=	source/converters.c	\
		source/getnumbers.c	\
		source/hexaswitch.c	\
		source/longshortswitch.c	\
		source/my_evil_str.c	\
		source/my_printf_bootstrap.c	\
		source/my_printf.c	\
		source/unsignedgetnumber.c	\
		source/switch_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libprint.a

CFLAGS	=	-W -Wall -Wextra -Werror -I ../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: fclean clean all re
