NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx

OBJ = init-apix.o help/calculs.o help/trgb.o

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	@rm -rf ${OBJ}
fclean: clean
	@rm -rf ${NAME}
re : fclean all

.PHONY: all re clean fclean
