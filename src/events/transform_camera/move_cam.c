/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:13:01 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/08/06 01:27:08 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "scene.h"
#include "t_math.h"

int	move_cam_left(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(-1, camera->ux));
	return (0);
}

int	move_cam_up(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(1, camera->uy));
	return (0);
}

int	move_cam_right(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(1, camera->ux));
	return (0);
}

int	move_cam_down(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(-1, camera->uy));
	return (0);
}

int	move_cam_forward(t_data *data)
{
	t_camera	*camera;

	camera = data->scene.camera;
	camera->pos = v_add(camera->pos, v_scalar(1, camera->dir));
	return (0);
}
