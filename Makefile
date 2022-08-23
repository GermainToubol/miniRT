NAME		= miniRT
NAME_BONUS	= miniRT_bonus

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
				$(addprefix change_uistate/,									\
												close_window					\
												set_control						\
												switch_ui_mode)					\
				$(addprefix manage_event/,										\
												manage_buttonpress_default		\
												manage_buttonrelease_default	\
												manage_event					\
												manage_event_default			\
												manage_event_modifier)			\
				$(addprefix modifier/,											\
												add_char_to_input				\
												erase_input_last_char			\
												hand_focus						\
												hand_focus_input_box)			\
				$(addprefix print_frame_buffer/,								\
												print_frame_buffer)				\
				$(addprefix transform_camera/,									\
												buttonmove_cam					\
												buttonrotate_cam				\
												change_cam						\
												move_cam						\
												move_cam2						\
												rollmove_cam					\
												rotate_cam						\
												rotate_cam2))					\
			$(addprefix init/,													\
												init							\
												init_mlx						\
												init_scene						\
												name_scene_elems				\
												parse_tiff						\
				$(addprefix check_scene/,										\
												check_scene						\
												rt_error_elem_format			\
												rt_error_elem_format2			\
												rt_is_type						\
												rt_is_type2						\
												rt_is_type3						\
												rt_print_error)					\
				$(addprefix parse_scene/,										\
												alloc_scene						\
												parse_scene						\
												rt_get_type						\
												rt_get_type2					\
												rt_get_type3					\
												rt_set_elem						\
												rt_set_elem2))					\
			$(addprefix menu/,													\
				$(addprefix put_mlx/,											\
												put_mlx)						\
				$(addprefix render_menu/,										\
												mix_img							\
												render_h1						\
												render_input_box				\
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
												set_ul_type)					\
				$(addprefix update_scene/,										\
												update_input_type				\
												update_scene_menu))				\
			$(addprefix render/,												\
												render							\
												set_color						\
				$(addprefix light/,												\
												set_ambient_light_contribution	\
												set_direct_light_contribution	\
												set_light_contribution			\
												set_specular_contribution)		\
				$(addprefix mask/,												\
												set_cylinder_mask				\
												set_default_mask				\
												set_plane_mask					\
												set_sphere_mask					\
												set_triangle_mask				\
												update_mask_light				\
												update_mask_camera)				\
				$(addprefix set_intersection/,									\
												set_intersection				\
												set_intersection_cylinder		\
												set_intersection_hyperbol		\
												set_intersection_normal			\
												set_intersection_plane			\
												set_intersection_pos			\
												set_intersection_sphere			\
												set_intersection_triangle		\
												set_normal_cylinder				\
												set_normal_hyperbol				\
												set_normal_plane				\
												set_normal_sphere				\
												set_normal_triangle)			\
				$(addprefix texture/,											\
												apply_texture					\
												cboard_cylinder					\
												cboard_plane					\
												cboard_sphere					\
												ftext_sphere					\
												ftext_plane)					\
				$(addprefix ui/,												\
												print_progress)					\
				$(addprefix update_scene/,										\
												update_camera					\
												update_cylinder					\
												update_hyperbol					\
												update_light					\
												update_plane					\
												update_scene					\
												update_sphere					\
												update_triangle))				\
			$(addprefix terminate/,												\
												free_camera						\
												free_lights						\
												terminate)						

# List of all object files (.o)
# -------------------------------------------------------------------------

OBJ_DIR		= obj
OBJ			= $(SRC_NAMES:%=$(OBJ_DIR)/%.o)
OBJ_BONUS	= $(SRC_NAMES:%=$(OBJ_DIR)/%_bonus.o)

DEPS		= $(SRC_NAMES:%=$(OBJ_DIR)/%.d)

# List of all compilation options
# -------------------------------------------------------------------------
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -O3
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
			rm -f $(OBJ_BONUS)
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
	rm -f $(NAME_BONUS)
	@for lib in $(LIB_NAMES); do \
		echo ""; \
		echo "$(_GREEN)$(LIB_DIR)/$${lib}/: make fclean$(_NO_COLOR)"; \
		$(MAKE) --no-print-directory -C $(LIB_DIR)/$${lib}/ fclean 2> /dev/null \
		|| $(MAKE) --no-print-directory -C $(LIB_DIR)/$${lib}/ clean 2> /dev/null \
		|| echo "Cannot be clean"; \
	done

.PHONY:		re
re:			fclean all

.PHONY:		bonus
bonus:		$(NAME_BONUS)


$(NAME):	$(LIB_FILES) $(OBJ)
			@echo ""
			@echo "$(_BLUE)Linkage $(NAME)$(_NO_COLOR)"
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c start_compiling
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME_BONUS):	$(LIB_FILES) $(OBJ_BONUS)
			@echo ""
			@echo "$(_BLUE)Linkage $(NAME_BONUS)$(_NO_COLOR)"
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME_BONUS) $(LIB)

$(OBJ_DIR)/%_bonus.o:$(SRC_DIR)/%.c start_compiling
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -D BONUS -c $< -o $@

.INTERMEDIATE:start_compiling
start_compiling:
			@echo "$(_GREEN)Start Compiling $(_NO_COLOR)"

.PHONY:		malloc_test
malloc_test:	$(OBJ) $(LIB_FILES)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ $(OBJ) $(LIB) -lm -L. -lmallocator

# Libraries
# -------------------------------------------------------------------------
%.a:
			@echo "$(_GREEN)$(dir $@): make$(_NO_COLOR)"
			@$(MAKE) --no-print-directory -C $(dir $@)
			@echo ""

# Dependencies
# -------------------------------------------------------------------------
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) -MM -MT $(@:.d=.o) $(CFLAGS) $(INCLUDE) $< > $@

-include $(DEPS)
