CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MAKE		= /bin/make


NAME		= miniRT

LIB_NAMES	= ft \
			  mlx \
			  t_math \
			  t_random

LIBEXT_NAMES= m \
			  X11 \
			  Xext

HEADER_NAMES=

SRC_NAMES	= main \
			  events/close_window \
			  events/manage_keypress \
			  events/move \
			  init/check_scene/check_scene \
			  init/check_scene/rt_error_elem_format \
			  init/check_scene/rt_error_elem_format2 \
			  init/check_scene/rt_is_type \
			  init/check_scene/rt_is_type2 \
			  init/check_scene/rt_print_error \
			  init/init \
			  init/init_mlx \
			  init/init_scene \
			  init/init_scene_derivates \
			  init/parse_scene/parse_scene \
			  init/parse_scene/rt_get_type \
			  init/parse_scene/rt_get_type2 \
			  init/parse_scene/rt_set_elem \
			  init/parse_scene/rt_set_elem2 \
			  render/render \
			  render/set_color \
			  render/set_intersection/set_intersection \
			  render/set_intersection/set_intersection_pos \
			  render/set_intersection/set_intersection_sphere \
			  render/set_intersection/set_intersection_normal \
			  render/set_intersection/set_normal_sphere \
			  terminate/terminate

LIB_DIR		= lib

LIB			= $(LIBEXT_NAMES:%=-l%) \
			  $(LIB_NAMES:%=-L$(LIB_DIR)/%) \
			  $(LIB_NAMES:%=-l%)

INCLUDE_DIRS= include \
			  include/lib
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
re:				fclean all

.INTERMEDIATE:	start_compiling
start_compiling:
	@echo "\n$(_GREEN)Start Compiling $(_NO_COLOR)"

.PHONY:			malloc_test
malloc_test: $(OBJ) $(LIB_FILES)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ $(OBJ) $(LIB) -L. -lmallocator


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
