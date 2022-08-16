/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:59:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/16 22:51:25 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "mlx_int.h"
# include "scene.h"
# include "t_math.h"

# define MENU_NAME_POS "Position"
# define MENU_NAME_DIR "Direction"
# define MENU_NAME_NORMAL "Normal"
# define MENU_NAME_RATIO "Ratio"
# define MENU_NAME_COLOR "Color"
# define MENU_NAME_FOV "Fov"
# define MENU_NAME_R "Radius"
# define MENU_NAME_H "Height"
# define MENU_NAME_EDGE0 "Edge 1"
# define MENU_NAME_EDGE1 "Edge 2"
# define MENU_NAME_EDGE2 "Edge 3"

# define MENU_X 550
# define MENU_Y 20
# define MENU_WIDTH 150
# define MENU_HEIGHT 300
# define H1_X 0
# define H1_Y 0
# define H1_WIDTH MENU_WIDTH
# define H1_HEIGHT 30
# define H1_INPUT_BOX_X 0
# define H1_INPUT_BOX_Y 0
# define LI_X 0
# define LI_Y 0
# define LI_WIDTH MENU_WIDTH
# define LI_HEIGHT 50
# define LI_INPUT_BOX_X 0
# define LI_INPUT_BOX_Y 0
# define UL_X 0
# define UL_Y 0
# define UL_WIDTH MENU_WIDTH
# define UL_HEIGHT 70

typedef enum e_var_type
{
	type_int,
	type_float,
	type_ratio,
	type_fov,
	type_str
}	t_var_type;

typedef struct s_viewport
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_viewport;

typedef struct s_input_box
{
	char				input[16];
	t_var_type			type;
	void				*ptr;
	t_viewport			viewport;
	int					has_focus;
	struct s_input_box	*next;
	struct s_input_box	*prev;
}	t_input_box;

typedef struct s_h1
{
	t_input_box	input_box;
	t_viewport	viewport;
}	t_h1;

typedef struct s_li
{
	char		name[8];
	t_input_box	input_box;
	t_viewport	viewport;
}	t_li;

typedef struct s_ul
{
	char		name[16];
	int			nb_li;
	t_li		li[3];
	t_viewport	viewport;
}	t_ul;

typedef struct s_menu
{
	void		*img;
	t_h1		h1;
	int			nb_ul;
	t_ul		ul[8];
	t_viewport	viewport;
	t_input_box	*input_box_focus;
}	t_menu;

typedef struct s_data			t_data;
typedef struct s_modifier_state	t_modifier_state;

//	SET_MENU
//	set_h1
void	set_h1(t_h1 *h1, char *name);
//	set_input_box
void	set_input_box(t_input_box *input_box, t_var_type var_type, void *ptr);
//	set_input_type
void	set_input_float(char *input, void *ptr);
void	set_input_int(char *input, void *ptr);
void	set_input_str(char *str, void *ptr);
//	set_li
void	set_li(t_li *li, t_var_type var_type, void *ptr, char *name);
//	set_menu
void	set_menu(t_data *data, t_modifier_state *modifier_state);
//	set_menu_focus
void	set_menu_focus(t_menu *menu);
//	set_menu_obj
void	set_menu_sphere(t_menu *menu, t_obj *obj);
void	set_menu_plane(t_menu *menu, t_obj *obj);
void	set_menu_cylinder(t_menu *menu, t_obj *obj);
void	set_menu_triangle(t_menu *menu, t_obj *obj);
//	set_menu_viewports
void	set_menu_viewports(t_menu *menu);
//	set_menu_ul_type
void	set_ul_color(t_ul *ul, t_color *color, char *name);
void	set_ul_float(t_ul *ul, float *f, char *name);
void	set_ul_fov(t_ul *ul, float *fov, char *name);
void	set_ul_ratio(t_ul *ul, float *ratio, char *name);
void	set_ul_vect(t_ul *ul, t_vect *v, char *name);

//	RENDER_MENU
//	render_h1
void	render_h1_background(t_h1 *h1, t_img *img, t_viewport *offset);
void	render_h1_text(t_h1 *h1, t_img *img, t_viewport *offset);
//	render_li
void	render_li_background(t_li *li, t_img *img, t_viewport *offset);
void	render_li_text(t_li *li, t_img *img, t_viewport *offset);
//	render_menu
void	render_menu(t_data *data, t_menu *menu);
//	render_ul
void	render_ul_background(t_ul *ul, t_img *img, t_viewport *offset);
void	render_ul_text(t_ul *ul, t_img *img, t_viewport *offset);

//	UPDATE_SCENE
//	update_input_type
int		update_input_float(char *input, void *ptr);
int		update_input_fov(char *input, void *ptr);
int		update_input_int(char *input, void *ptr);
int		update_input_ratio(char *input, void *ptr);
int		update_input_str(char *input, void *ptr);
//	update_scene
int		update_scene(t_data *data);

#endif
