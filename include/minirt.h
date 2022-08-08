/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:04:37 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/08 10:29:24 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"

# define NB_UI_MODES 3
# define NB_ELEM_TYPES 4

typedef struct s_event_state	t_event_state;

typedef enum e_ui_mode
{
	mode_invalid,
	mode_default,
	mode_modifier
}	t_ui_mode;

typedef enum e_elem_type
{
	type_obj,
	type_light,
	type_ambient_light,
	type_camera
}	t_elem_type;

typedef struct s_modifier_state
{
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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*frame_buffer;
	t_scene		scene;
	t_ui_state	ui_state;
}	t_data;

#endif
