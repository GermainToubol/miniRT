/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:01 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/02 16:26:03 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "minirt.h"

int	move_left(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(-(WIDTH / 4), camera->ux));
	return (0);
}

int	move_up(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(-(HEIGHT / 4), camera->uy));
	return (0);
}

int	move_right(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(WIDTH / 4, camera->ux));
	return (0);
}

int	move_down(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(HEIGHT / 4, camera->uy));
	return (0);
}
