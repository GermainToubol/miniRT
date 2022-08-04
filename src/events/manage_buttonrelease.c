/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buttonrelease.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:50:48 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/04 16:23:32 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "parameters.h"
#include "render.h"
#include "t_math.h"

int	manage_left_release(int mouse_x, int mouse_y, t_data *data)
{
	t_event_state	*event_state;
	t_camera		*camera;
	t_ray			ray;
	t_ray			ray_last;
	t_vect			camera_anchor_relative;

	event_state = &data->ui_state.event_state;
	if (!event_state->is_rotation_in_progress
		|| (mouse_x - event_state->last_buttonpress_x) * (mouse_x - event_state->last_buttonpress_x)
			+ (mouse_y - event_state->last_buttonpress_y) * (mouse_y - event_state->last_buttonpress_y) < 100)
		return (0);
	camera = data->scene.camera;
	set_ray(&ray_last, camera, event_state->last_buttonpress_x,
		event_state->last_buttonpress_y);
	set_ray(&ray, camera, mouse_x, mouse_y);
	v_rotate(&camera->dir, v_cross_product(ray.dir, ray_last.dir),
		acosf(v_dot_product(ray.dir, ray_last.dir)));
	v_rotate(&camera->ux, v_cross_product(ray.dir, ray_last.dir),
		acosf(v_dot_product(ray.dir, ray_last.dir)));
	v_rotate(&camera->uy, v_cross_product(ray.dir, ray_last.dir),
		acosf(v_dot_product(ray.dir, ray_last.dir)));
	camera_anchor_relative = v_sub(camera->anchor, camera->pos);
	v_rotate(&camera_anchor_relative, v_cross_product(ray.dir, ray_last.dir),
		acosf(v_dot_product(ray.dir, ray_last.dir)));
	camera->anchor = v_add(camera->pos, camera_anchor_relative);
	event_state->is_rotation_in_progress = 0;
	data->ui_state.to_render = 1;
	return (0);
}

int	manage_middle_release(int mouse_x, int mouse_y, t_data *data)
{
	(void) mouse_x;
	(void) mouse_y;
	(void) data;
	return (0);
}

int	manage_right_release(int mouse_x, int mouse_y, t_data *data)
{
	t_event_state	*event_state;
	t_camera		*camera;
	float			move_x;
	float			move_y;

	event_state = &data->ui_state.event_state;
	if (!event_state->is_translation_in_progress
		|| (mouse_x - event_state->last_buttonpress_x) * (mouse_x - event_state->last_buttonpress_x)
			+ (mouse_y - event_state->last_buttonpress_y) * (mouse_y - event_state->last_buttonpress_y) < 100)
		return (0);
	camera = data->scene.camera;
	move_x = (float) -(mouse_x - event_state->last_buttonpress_x) * 8 / WIDTH;
	camera->pos = v_add(camera->pos, v_scalar(move_x, camera->ux));
	camera->anchor = v_add(camera->anchor, v_scalar(move_x, camera->ux));
	move_y = (float)(mouse_y - event_state->last_buttonpress_y) * 8 / HEIGHT;
	camera->pos = v_add(camera->pos, v_scalar(move_y, camera->uy));
	camera->anchor = v_add(camera->anchor, v_scalar(move_y, camera->uy));
	event_state->is_translation_in_progress = 0;
	data->ui_state.to_render = 1;
	return (0);
}

int	manage_roll_up_release(int mouse_x, int mouse_y, t_data *data)
{
	(void) mouse_x;
	(void) mouse_y;
	(void) data;
	return (0);
}

int	manage_roll_down_release(int mouse_x, int mouse_y, t_data *data)
{
	(void) mouse_x;
	(void) mouse_y;
	(void) data;
	return (0);
}
