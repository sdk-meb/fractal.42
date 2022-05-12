NAME = fractol
LIBFT= /Users/mes-sadk/Desktop/libx/fractal.42/libft.42/libft.a
prntf= /Users/mes-sadk/Desktop/libx/fractal.42/printf.42/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx

OBJ = init-apix.o help/calculs.o help/trgb.o help/check.o drew.o event.o data_save.o

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(prntf) $(LIBFT)
	make clean
clean:
	@rm -rf ${OBJ}
fclean: clean
	@rm -rf ${NAME}
re : fclean all

.PHONY: all re clean fclean
