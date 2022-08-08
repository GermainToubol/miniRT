/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_state.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:57:08 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/08 13:46:24 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_STATE_H
# define UI_STATE_H

# define NB_UI_MODES 3
# define NB_ELEM_TYPES 4

typedef struct s_event_state	t_event_state;

typedef enum e_ui_mode
{
	mode_invalid,
	mode_default,
	mode_modifier
}	t_ui_mode;

typedef enum e_var_type
{
	type_int,
	type_float,
	type_str
}	t_var_type;

typedef struct s_input_box
{
	char		input[16];
	t_var_type	type;
	void		*val;
	int			x;
	int			y;
	int			w;
	int			h;
}	t_input_box;

typedef struct s_h1
{
	t_input_box	input_box;
	int			x;
	int			y;
	int			w;
	int			h;
}	t_h1;

typedef struct s_li
{
	char		name[8];
	t_input_box	input_box;
	int			x;
	int			y;
	int			w;
	int			h;
}	t_li;

typedef struct s_ul
{
	char	name[16];
	int		nb_li;
	t_li	li[3];
	int		x;
	int		y;
	int		w;
	int		h;
}	t_ul;

typedef struct s_menu
{
	void		*img;
	t_h1		h1;
	int			nb_ul;
	t_ul		ul[8];
}	t_menu;

typedef enum e_elem_type
{
	type_obj,
	type_light,
	type_ambient_light,
	type_camera
}	t_elem_type;

typedef struct s_modifier_state
{
	void		*frame_buffer;
	t_menu		menu;
	t_elem_type	elem_type;
	int			nb_elems[NB_ELEM_TYPES];
	int			i_elem[NB_ELEM_TYPES];
}	t_modifier_state;

typedef enum e_event_action
{
	none,
	cam_translation,
	cam_rotation
}	t_event_action;

typedef struct s_event_state
{
	t_event_action	action_in_progress;
	int				control_set;
	int				last_buttonpress_x;
	int				last_buttonpress_y;
}	t_event_state;

typedef struct s_ui_state
{
	t_ui_mode			mode;
	t_modifier_state	modifier_state;
	t_event_state		event_state;
	int					to_render;
}	t_ui_state;

#endif
