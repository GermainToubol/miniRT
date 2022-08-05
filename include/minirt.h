/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:04:37 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:49:05 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"

# define NB_UI_MODES 2

typedef struct s_event_state	t_event_state;

typedef enum e_ui_mode
{
	mode_invalid,
	mode_default,
	mode_modifier
}	t_ui_mode;

typedef enum e_event_action
{
	none,
	cam_translation,
	cam_rotation
}	t_event_action;

typedef struct s_event_state
{
	t_event_action	action_in_progress;
	int				last_buttonpress_x;
	int				last_buttonpress_y;
}	t_event_state;

typedef struct s_ui_state
{
	t_ui_mode		mode;
	t_event_state	event_state;
	int				to_render;
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
