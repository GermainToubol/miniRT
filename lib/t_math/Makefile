CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g

NAME	= libt_math.a
SRCS	= q_operations.c \
		  quaternion.c \
		  vector.c \
		  v_operations.c \
		  v_operations2.c \
		  v_transformation.c\
		  v_copy.c

OBJS	= ${SRCS:%.c=%.o}

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJS}
	ar rc $@ $^

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $^

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
