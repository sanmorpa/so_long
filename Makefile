SRCS	=	main.c ./outils/ft_outils.c ./movement/ft_keys.c ./outils/ft_error.c \
			./window/ft_paint.c ./prep/ft_images.c ./window/ft_window.c ./movement/ft_events.c \
			./prep/ft_hero.c ./prep/ft_array.c ./prep/ft_size_map.c ./prep/ft_unite.c \
			./prep/ft_check.c ./movement/ft_enemy.c ./outils/ft_itoa.c ./movement/ft_enemy_mood.c \
			./prep/ft_strrchr.c ./prep/ft_strncmp.c 

NAME	=	so_long

DIRLIB =  ./gnl/get_next_line.a

MAKELIB = cd ./gnl/ && ${MAKE}

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror -I /usr/local/include

MINILIBX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

CC		=	gcc

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${MAKELIB}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${MINILIBX} ${DIRLIB}

clean:
			${RM} ${OBJS}
			${MAKELIB} clean

fclean:		clean
			${RM} ${NAME}
			${MAKELIB} fclean

re:			fclean ${NAME}
			${MAKELIB} re

.PHONY:		all clean fclean re
