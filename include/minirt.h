/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:04:37 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 02:36:38 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "events.h"
# include "scene.h"

typedef struct s_ui_state
{
	int				to_render;
	t_event_state	event_state;
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
