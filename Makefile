CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MAKE		= /bin/make


NAME		= miniRT

LIB_NAMES	= ft \
			  mlx \
			  t_math

LIBEXT_NAMES= 

HEADER_NAMES= 

SRC_NAMES	= main \

LIB_DIR		= lib

LIB			= $(LIBEXT_NAMES:%=-l%) \
			  $(LIB_NAMES:%=-L$(LIB_DIR)/%) \
			  $(LIB_NAMES:%=-l%)

INCLUDE_DIRS= include \
			  imclude/lib
HEADER_DIR	= include
SRC_DIR		= src
OBJ_DIR		= obj

INCLUDE		= $(INCLUDE_DIRS:%=-I%)

HEADER		= $(HEADER_NAMES:%=$(HEADER_DIR)/%.h)
OBJ			= $(SRC_NAMES:%=$(OBJ_DIR)/%.o)
LIB_OBJS	= 

LIB_FILES	= $(foreach l,$(LIB_NAMES),$(LIB_DIR)/$l/lib$l.a)

_GREY		= \033[30m
_RED		= \033[31m
_GREEN		= \033[32m
_YELLOW		= \033[33m
_BLUE		= \033[34m
_PURPLE		= \033[35m
_CYAN		= \033[36m
_WHITE		= \033[37m
_NO_COLOR	= \033[0m



.PHONY:			all
all:			$(NAME)

.PHONY:			clean
clean:
	@echo "$(_GREEN)Removing objects$(_NO_COLOR)"
	rm -f $(OBJ)
	@if [ -d $(OBJ_DIR) ]; then \
		find $(OBJ_DIR) -type d | xargs rmdir -p --ignore-fail-on-non-empty; \
	fi

.PHONY:			fclean
fclean:			clean
	@echo "\n$(_GREEN)Removing $(NAME)$(_NO_COLOR)"
	rm -f $(NAME)
	@for lib in $(LIB_NAMES); do \
		echo "\n$(_GREEN)$(LIB_DIR)/$${lib}/: make fclean$(_NO_COLOR)"; \
		$(MAKE) --no-print-directory -C $(LIB_DIR)/$${lib}/ fclean; \
	done

.PHONY:			re
re:				
	$(MAKE) fclean
	$(MAKE) all

.INTERMEDIATE:	start_compiling
start_compiling:
	@echo "\n$(_GREEN)Start Compiling $(_NO_COLOR)"


$(NAME): $(LIB_FILES) $(OBJ) $(HEADER)
	@echo "\n$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER) start_compiling
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
	fi
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%.a:
	@echo "\n$(_GREEN)$(dir $@): make$(_NO_COLOR)"
	@$(MAKE) --no-print-directory -C $(dir $@)
