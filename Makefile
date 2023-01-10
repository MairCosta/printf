NAME = libftprintf.a
SRC = ft_printf.c \
complement.c 

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME)	$(SRC:=.o)

clean:
	$(RM)	$(SRC:=.o)

fclean: clean
	$(RM)	$(NAME)

re: fclean $(NAME)