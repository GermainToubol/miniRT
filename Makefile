CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MAKE		= /bin/make


NAME		= miniRT

INCLUDE_DIRS= include \
			  include/lib
INCLUDE		= $(INCLUDE_DIRS:%=-I%)

LIB_DIR		= lib
LIB_NAMES	= ft mlx t_math t_random
LIBEXT_NAMES= m X11 Xext
LIB_FILES	= $(foreach l,$(LIB_NAMES),$(LIB_DIR)/$l/lib$l.a)
LIB			= $(LIBEXT_NAMES:%=-l%) \
			  $(LIB_NAMES:%=-L$(LIB_DIR)/%) \
			  $(LIB_NAMES:%=-l%)

HEADER_DIR	= include
HEADER_NAMES=
HEADER		= $(HEADER_NAMES:%=$(HEADER_DIR)/%.h)

SRC_DIR		= src
SRC_NAMES	= main \
			  events/change_uistate/close_window \
			  events/change_uistate/switch_ui_mode \
			  events/manage_event/manage_buttonpress_default \
			  events/manage_event/manage_buttonrelease_default \
			  events/manage_event/manage_event \
			  events/manage_event/manage_event_default \
			  events/manage_event/manage_event_modifier \
			  events/transform_camera/buttonmove_cam \
			  events/transform_camera/buttonrotate_cam \
			  events/transform_camera/move_cam \
			  events/transform_camera/move_cam2 \
			  events/transform_camera/rollmove_cam \
			  events/transform_camera/rotate_cam \
			  events/transform_camera/rotate_cam2 \
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
			  render/light_contribution/set_light_contribution \
			  render/light_contribution/set_ambient_light_contribution \
			  render/light_contribution/set_direct_light_contribution \
			  render/set_intersection/set_intersection \
			  render/set_intersection/set_intersection_pos \
			  render/set_intersection/set_intersection_sphere \
			  render/set_intersection/set_intersection_plane \
			  render/set_intersection/set_intersection_normal \
			  render/set_intersection/set_normal_sphere \
			  render/set_intersection/set_normal_plane \
			  terminate/terminate

OBJ_DIR		= obj
OBJ			= $(SRC_NAMES:%=$(OBJ_DIR)/%.o)

_GREY		= \033[30m
_RED		= \033[31m
_GREEN		= \033[32m
_YELLOW		= \033[33m
_BLUE		= \033[34m
_PURPLE		= \033[35m
_CYAN		= \033[36m
_WHITE		= \033[37m
_NO_COLOR	= \033[0m


.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	@echo "$(_GREEN)Removing objects$(_NO_COLOR)"
	rm -f $(OBJ)
	@for obj_dir in $(dir $(OBJ)); do \
		if [ -d $${obj_dir} ] ; then \
			rmdir -p --ignore-fail-on-non-empty $${obj_dir}; \
		fi; \
	done

.PHONY: fclean
fclean: clean
	@echo ""
	@echo "$(_GREEN)Removing $(NAME)$(_NO_COLOR)"
	rm -f $(NAME)
	@for lib in $(LIB_NAMES); do \
		echo ""; \
		echo "$(_GREEN)$(LIB_DIR)/$${lib}/: make fclean$(_NO_COLOR)"; \
		$(MAKE) --no-print-directory -C $(LIB_DIR)/$${lib}/ fclean 2> /dev/null \
		|| $(MAKE) --no-print-directory -C $(LIB_DIR)/$${lib}/ clean 2> /dev/null \
		|| echo "Cannot be clean"; \
	done

.PHONY: re
re: fclean all


$(NAME): $(LIB_FILES) $(OBJ) $(HEADER)
	@echo ""
	@echo "$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) start_compiling
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.INTERMEDIATE: start_compiling
start_compiling:
	@echo "$(_GREEN)Start Compiling $(_NO_COLOR)"

%.a:
	@echo "$(_GREEN)$(dir $@): make$(_NO_COLOR)"
	@$(MAKE) --no-print-directory -C $(dir $@)
	@echo ""
