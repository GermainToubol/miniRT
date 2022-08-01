CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

NAME	= libt_random.a
SRCS	= r_rand \
		  r_randf \
		  r_srand
OBJS	= ${SRCS:%=%.o}

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
