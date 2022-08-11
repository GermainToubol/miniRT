NAME		= miniRT

# List of all inclusions (.h and .a)
# -------------------------------------------------------------------------
HEADER_DIR	= include
HEADER_NAMES=
HEADER		= $(HEADER_NAMES:%=$(HEADER_DIR)/%.h)

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

# List of all sources (.c)
# -------------------------------------------------------------------------
SRC_DIR		= src
SRC_NAMES	=									main							\
			$(addprefix events/,												\
				$(addprefix change_uistate/,	close_window					\
												set_control						\
												switch_ui_mode)					\
				$(addprefix manage_event/,		manage_buttonpress_default		\
												manage_buttonrelease_default	\
												manage_event					\
												manage_event_default			\
												manage_event_modifier)			\
				$(addprefix modifier/,			hand_focus						\
												hand_focus_input_box)			\
				$(addprefix transform_camera/,	buttonmove_cam					\
												buttonrotate_cam				\
												move_cam						\
												move_cam2						\
												rollmove_cam					\
												rotate_cam						\
												rotate_cam2))					\
			$(addprefix init/,													\
												init							\
												init_mlx						\
												init_scene						\
												init_scene_derivates			\
												name_scene_elems				\
				$(addprefix scene_derivates/,	init_sphere_derivates			\
												init_plane_derivates			\
												init_cylinder_derivates			\
												init_triangle_derivates)		\
				$(addprefix check_scene/,		check_scene						\
												rt_error_elem_format			\
												rt_error_elem_format2			\
												rt_is_type						\
												rt_is_type2						\
												rt_print_error)					\
				$(addprefix parse_scene/,		parse_scene						\
												rt_get_type						\
												rt_get_type2					\
												rt_set_elem						\
												rt_set_elem2))					\
			$(addprefix menu/,													\
				$(addprefix render_menu/,										\
												render_h1						\
												render_li						\
												render_menu						\
												render_ul)						\
				$(addprefix set_menu/,											\
												set_h1							\
												set_input_box					\
												set_input_type					\
												set_li							\
												set_menu						\
												set_menu_focus					\
												set_menu_obj					\
												set_menu_viewports				\
												set_ul_type))					\
			$(addprefix render/,												\
												render							\
												print_progress					\
												set_color						\
				$(addprefix light_contribution/,set_light_contribution			\
												set_ambient_light_contribution	\
												set_direct_light_contribution	\
												set_specular_contribution)		\
				$(addprefix set_intersection/,	set_intersection				\
												set_intersection_pos			\
												set_intersection_sphere			\
												set_intersection_plane			\
												set_intersection_cylinder		\
												set_intersection_triangle		\
												set_intersection_normal			\
												set_normal_sphere				\
												set_normal_plane				\
												set_normal_cylinder				\
												set_normal_triangle)			\
				$(addprefix texture/,			apply_texture					\
												cboard_sphere					\
												cboard_plane					\
												cboard_cylinder))				\
			$(addprefix terminate/,												\
												terminate)

# List of all object files (.o)
# -------------------------------------------------------------------------

OBJ_DIR		= obj
OBJ			= $(SRC_NAMES:%=$(OBJ_DIR)/%.o)

DEPS		= $(SRC_NAMES:%=$(OBJ_DIR)/%.d)

# List of all compilation options
# -------------------------------------------------------------------------
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -O2
MAKE		= /bin/make
SHELL		= /bin/zsh

_GREY		= \033[30m
_RED		= \033[31m
_GREEN		= \033[32m
_YELLOW		= \033[33m
_BLUE		= \033[34m
_PURPLE		= \033[35m
_CYAN		= \033[36m
_WHITE		= \033[37m
_NO_COLOR	= \033[0m

vpath %.c $(SRCS_DIR)
vpath %.h $(HEAD_DIR)

# General rules
# -------------------------------------------------------------------------
.PHONY:		all
all:		$(NAME)

.PHONY:		clean
clean:
			@echo "$(_GREEN)Removing objects$(_NO_COLOR)"
			rm -f $(OBJ)
			@echo ""
			@echo "$(_GREEN)Removing dependencies$(_NO_COLOR)"
			rm -f $(DEPS)
			@for obj_dir in $(dir $(OBJ)); do							\
				if [ -d $${obj_dir} ] ; then							\
					rmdir -p --ignore-fail-on-non-empty $${obj_dir}; 	\
				fi;														\
			done

.PHONY:		fclean
fclean:		clean
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

.PHONY:		re
re:			fclean all


$(NAME):	$(LIB_FILES) $(OBJ)
			@echo ""
			@echo "$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c start_compiling
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.INTERMEDIATE:start_compiling
start_compiling:
			@echo "$(_GREEN)Start Compiling $(_NO_COLOR)"

# Libraries
# -------------------------------------------------------------------------
%.a:
			@echo "$(_GREEN)$(dir $@): make$(_NO_COLOR)"
			@$(MAKE) --no-print-directory -C $(dir $@)
			@echo ""

# Dependencies
# -------------------------------------------------------------------------
.SILENT:	$(DEPS)
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) -MM -MT $(@:.d=.o) $(CFLAGS) $(INCLUDE) $< > $@

-include $(DEPS)
