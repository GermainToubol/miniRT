/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buttonpress_default.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:50:29 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:45:42 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "minirt.h"

int	manage_buttonpress_left_default(int mouse_x, int mouse_y, t_data *data)
{
	t_event_state	*event_state;

	event_state = &data->ui_state.event_state;
	if (event_state->action_in_progress)
		return (0);
	set_buttonrotate_cam(mouse_x, mouse_y, event_state);
	event_state->action_in_progress = cam_rotation;
	return (0);
}

int	manage_buttonpress_middle_default(int mouse_x, int mouse_y, t_data *data)
{
	(void) mouse_x;
	(void) mouse_y;
	(void) data;
	return (0);
}

int	manage_buttonpress_right_default(int mouse_x, int mouse_y, t_data *data)
{
	t_event_state	*event_state;

	event_state = &data->ui_state.event_state;
	if (event_state->action_in_progress)
		return (0);
	set_buttonmove_cam(mouse_x, mouse_y, event_state);
	event_state->action_in_progress = cam_translation;
	return (0);
}
