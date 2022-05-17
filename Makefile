
WHITE=\033[0m
GREEN=\033[32m
YELLOW=\033[33m
GRAY=\033[2;37m
CURSIVE=\033[3m
RED =\033[0;31m
BLUE =\033[0;34m

NAME = fractol
LIBFT= libft.42/libft.a
prntf= printf.42/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx \
 -Ofast -march=native -fno-signed-zeros \
 -fno-trapping-math

OBJ_HLP = help/calculs.o help/trgb.o help/check.o help/math.o help/set_color.o help/mouve.o
OBJ_ORG = main.o init-apix.o  drew.o event.o 

all : $(NAME)

$(NAME): $(OBJ_ORG) $(OBJ_HLP)
	$(CC) $(OBJ_HLP) $(OBJ_ORG) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(prntf) $(LIBFT)
	make clean

clean:
	@rm -rf ${OBJ_ORG} $(OBJ_HLP)

fclean: clean
	@rm -rf ${NAME}

re : fclean all

.PHONY: all re clean fclean
