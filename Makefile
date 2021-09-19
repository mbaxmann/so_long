OBJS    =       ${SRCS:.c=.o}

SRCS	=	srcs/main.c srcs/ft_init.c srcs/ft_init_2.c srcs/ft_engine.c srcs/ft_event.c

CC      =       clang

FLAGS   =       -Wall -Wextra -Werror

NAME    =       so_long

LINK	=	-lft -lmlx -lX11 -lXext

LIB     =       libft/libft.a mlx/libmlx.a

RM      =       rm -rf

LIB_PATH	=	-L ./libft/ -L ./mlx

all:    ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:        ${OBJS}
		make -C libft
		make -C mlx
		${CC} ${LIB_PATH} -o ${NAME} ${OBJS} ${LINK}

clean:
	make clean -C libft
	make clean -C mlx
	${RM} ${OBJS}

fclean:         clean
	make fclean -C libft
	make clean -C mlx
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re

