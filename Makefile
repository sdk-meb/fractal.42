NAME = GUI
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx

OBJ = init-apix.o help/calculs.o help/trgb.o

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
