/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buttonrelease_default.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:50:48 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:36:24 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "minirt.h"

int	manage_buttonrelease_left_default(int mouse_x, int mouse_y, t_data *data)
{
	t_event_state	*event_state;
	t_camera		*camera;
	int				displace_x;
	int				displace_y;

	event_state = &data->ui_state.event_state;
	displace_x = mouse_x - event_state->last_buttonpress_x;
	displace_y = mouse_y - event_state->last_buttonpress_y;
	if (displace_x * displace_x + displace_y * displace_y < 100)
		return (0);
	if (event_state->action_in_progress != cam_rotation)
		return (0);
	camera = data->scene.camera;
	buttonrotate_cam(mouse_x, mouse_y, camera, event_state);
	event_state->action_in_progress = none;
	data->ui_state.to_render = 1;
	return (0);
}

int	manage_buttonrelease_middle_default(int mouse_x, int mouse_y, t_data *data)
{
	(void) mouse_x;
	(void) mouse_y;
	(void) data;
	return (0);
}

int	manage_buttonrelease_right_default(int mouse_x, int mouse_y, t_data *data)
{
	t_event_state	*event_state;
	t_camera		*camera;
	int				displace_x;
	int				displace_y;

	event_state = &data->ui_state.event_state;
	displace_x = mouse_x - event_state->last_buttonpress_x;
	displace_y = mouse_y - event_state->last_buttonpress_y;
	if (displace_x * displace_x + displace_y * displace_y < 100)
		return (0);
	if (event_state->action_in_progress != cam_translation)
		return (0);
	camera = data->scene.camera;
	buttonmove_cam(mouse_x, mouse_y, camera, event_state);
	event_state->action_in_progress = none;
	data->ui_state.to_render = 1;
	return (0);
}
