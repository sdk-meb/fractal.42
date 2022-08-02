
NAME = fractol
LIBFT= libft.a
prntf= libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx \
 -Ofast -march=native -fno-signed-zeros \
 -fno-trapping-math

OBJ_HLP = utils/calculs.o utils/check.o utils/move.o
OBJ_ORG = main.o init-apix.o  draw.o event.o 

all :  $(NAME)

$(NAME): $(OBJ_ORG) $(OBJ_HLP)
	$(CC) $(OBJ_HLP) $(OBJ_ORG) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(prntf) $(LIBFT)
	@echo ""
	@echo "       "IF YOU ARE NEEDE TO HELP RUN : __MAKE HELP__

help :
	@echo " You can add one name of your choice of your choice :"
	@echo "     ↳ mandelbrot  ↳ julia  ↳  BurningShip"
	@echo ""
	@echo keyboard shortcut :
	@echo   "          ⓼ ( ⇕ )"
	@echo	" ⓸ (<->)      .    ⓺ (>-<)"
	@echo   "          ⓶ (1/⇳)"
	@echo ""
	@echo   " i     = RECOnFIGUReE_SET"
	@echo	" c     = CHANGE COLORS"
	@echo	" g     = ZOOM IN  CENTER"
	@echo	" h     = ZOOM OUT CENTER"
	@echo ""
	@echo   "      △      AS USUAL "
	@echo   "   ◀  ▽  ▷   	↳ FOR MOVE"


clean:
	@rm -rf ${OBJ_ORG} $(OBJ_HLP)

fclean: clean
	@rm -rf ${NAME}

re : fclean all

.PHONY: all re clean fclean
