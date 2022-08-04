/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buttonpress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:50:29 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 03:55:27 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "t_math.h"

int	manage_left_press(int mouse_x, int mouse_y, t_data *data)
{
	t_event_state	*event_state;

	event_state = &data->ui_state.event_state;
	if (event_state->is_translation_in_progress
		&& event_state->is_rotation_in_progress)
		return (0);
	event_state->last_buttonpress_x = mouse_x;
	event_state->last_buttonpress_y = mouse_y;
	event_state->is_translation_in_progress = 1;
	return (0);
}

int	manage_middle_press(int mouse_x, int mouse_y, t_data *data)
{
	(void) mouse_x;
	(void) mouse_y;
	(void) data;
	return (0);
}

int	manage_right_press(int mouse_x, int mouse_y, t_data *data)
{
	t_event_state	*event_state;

	event_state = &data->ui_state.event_state;
	if (event_state->is_translation_in_progress
		&& event_state->is_rotation_in_progress)
		return (0);
	event_state->last_buttonpress_x = mouse_x;
	event_state->last_buttonpress_y = mouse_y;
	event_state->is_rotation_in_progress = 1;
	return (0);
}

int	manage_roll_up(int mouse_x, int mouse_y, t_data *data)
{
	t_ray		ray;
	t_camera	*camera;

	camera = data->scene.camera;
	set_ray(&ray, camera, mouse_x, mouse_y);
	camera->pos = v_add(camera->pos, ray.dir);
	camera->anchor = v_add(camera->anchor, ray.dir);
	return (0);
}

int	manage_roll_down(int mouse_x, int mouse_y, t_data *data)
{
	t_ray		ray;
	t_camera	*camera;

	camera = data->scene.camera;
	set_ray(&ray, camera, mouse_x, mouse_y);
	camera->pos = v_sub(camera->pos, ray.dir);
	camera->anchor = v_sub(camera->anchor, ray.dir);
	return (0);
}
