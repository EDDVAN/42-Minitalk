
NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -Rf

SRC = 	ft_printf.c includs/ft_putchar_fd.c includs/ft_putnbr_fd.c includs/ft_putstr_fd.c \
		includs/ft_strlen.c includs/ft_putnbr_fd_u.c includs/ft_print_hexa.c

OBJ = $(SRC:.c=.o)


$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
