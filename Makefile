OBJS    =       ${SRCS:.c=.o}

SRCS	=	srcs/main.c srcs/ft_init.c

CC      =       clang

FLAGS   =       -Wall -Wextra -Werror

NAME    =       so_long

LINK	=	-lft

LIB     =       libft/libft.a

RM      =       rm -rf

LIB_PATH	=	-L ./libft/

all:    ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:        ${OBJS}
		make -C libft
		${CC} ${LIB_PATH} -o ${NAME} ${OBJS} ${LINK}

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean:         clean
	make fclean -C libft
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re

