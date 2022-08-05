/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttonmove_cam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:04:31 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:34:59 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "parameters.h"
#include "scene.h"

void	buttonmove_cam(int mouse_x, int mouse_y, t_camera *camera,
	t_event_state *event_state)
{
	float			move_x;
	float			move_y;

	move_x = (float) -(mouse_x - event_state->last_buttonpress_x) * 8 / WIDTH;
	move_y = (float)(mouse_y - event_state->last_buttonpress_y) * 8 / HEIGHT;
	camera->pos = v_add(camera->pos, v_scalar(move_x, camera->ux));
	camera->pos = v_add(camera->pos, v_scalar(move_y, camera->uy));
	camera->anchor = v_add(camera->anchor, v_scalar(move_x, camera->ux));
	camera->anchor = v_add(camera->anchor, v_scalar(move_y, camera->uy));
}

void	set_buttonmove_cam(int mouse_x, int mouse_y, t_event_state *event_state)
{
	event_state->last_buttonpress_x = mouse_x;
	event_state->last_buttonpress_y = mouse_y;
}
