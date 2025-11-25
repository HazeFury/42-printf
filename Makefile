CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
HEADER = includes

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I$(HEADER) -o $@ -c $<

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
