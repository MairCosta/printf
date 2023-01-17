NAME = libftprintf.a

SRC = ft_printf.c \
		complements.c \
		complements_hex.c

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -I.

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
			ar rc $(NAME)	$(OBJ)

clean:
	$(RM)	$(OBJ)

fclean: clean
	$(RM)	$(NAME)

re: fclean $(NAME)
