CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MAKE		= /bin/make


NAME		= libft.a

HEADER_NAMES= libft
SRC_NAMES	= ft_error_base \
			  ft_atod \
			  ft_arraylen \
			  ft_atoi \
			  ft_bzero \
			  ft_calloc \
			  ft_free_tab \
			  ft_get_empty \
			  ft_isalpha \
			  ft_isdigit \
			  ft_isalnum \
			  ft_isascii \
			  ft_isdouble \
			  ft_isint \
			  ft_islong \
			  ft_isprint \
			  ft_itoa \
			  ft_memchr \
			  ft_memcmp \
			  ft_memcpy \
			  ft_memmove \
			  ft_memset \
			  ft_putchar_fd \
			  ft_putstr_fd \
			  ft_putendl_fd \
			  ft_putnbr_fd \
			  ft_split \
			  ft_split_quoted \
			  ft_strchr \
			  ft_strcmp \
			  ft_strdup \
			  ft_striteri \
			  ft_strjoin \
			  ft_strjoin_onplace \
			  ft_strlcat \
			  ft_strlcpy \
			  ft_strlen \
			  ft_strmapi \
			  ft_strncmp \
			  ft_strndup \
			  ft_strnstr \
			  ft_strrchr \
			  ft_strtrim \
			  ft_substr \
			  ft_toupper \
			  ft_tolower \
			  ft_ultoa_base \
			  ft_utoa_base

HEADER_DIR	= include
SRC_DIR		= src
OBJ_DIR		= obj

INCLUDE		= -I$(HEADER_DIR)

HEADER		= $(HEADER_NAMES:%=$(HEADER_DIR)/%.h)
OBJ			= $(SRC_NAMES:%=$(OBJ_DIR)/%.o)
DEP			= $(SRC_NAMES:%=$(OBJ_DIR)/%.d)


all:			$(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(DEP)
	@if [ -d $(OBJ_DIR) ]; then \
		find $(OBJ_DIR) -type d | xargs rmdir -p --ignore-fail-on-non-empty; \
	fi

fclean:			clean
	rm -f $(NAME)

re:				fclean all


$(NAME): $(LIB_FILES) $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
	fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%.a:
	$(MAKE) -C $(dir $@)


.PHONY:			all clean fclean re
